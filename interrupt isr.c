
#include "config.h"
#include "arrays.h"
#include "sendSPIbyte.h"
#include "sendNoSPIbyte.h"
#include "writeMatrix.h"
#include "splitScore.h"
#include "selectDigit.h"
static volatile char icol = 1;
static volatile char irow = 5;
static volatile char xSpeed = 1;
static volatile char ySpeed = 1;
static volatile bool ballInt = HI;
static volatile bool eraseInt = LO;
__interrupt() void MY_ISR(void)
{
     if(INTCONbits.TMR0IF == HI && drawFlg == HI)
     {
        icol = icol + xSpeed;
        irow = irow + ySpeed;
        
        gameArray[irow][icol]= 1;
       /* if(icol <2 || icol>=14)
        {
            xSpeed = -xSpeed;
        }*/
        if((gameArray[irow][0] && gameArray[irow][1] == 1) || (gameArray[irow][14] && gameArray[irow][15] == 1))
        {
          xSpeed = -xSpeed;
        }
        
        else if (icol == 1 || icol == 14)
        {
            INTCONbits.TMR0IE = LO;
            xSpeed = 0;
            ySpeed = 0;
            if(icol == 1)
            {
                rightScore++;
                splitScore(rightScore);  
                selectDigit(units,6,8);
                selectDigit(tens,2,4);
                __delay_ms(2000);
            }
            else if(icol == 14)
            {
                leftScore++;
                splitScore(leftScore);
                selectDigit(units,6,8);
                selectDigit(tens,2,4);
                 __delay_ms(2000);
            }
            mainState = 9;
        }
        if(irow <1 || irow>=7)
        {
            ySpeed = -ySpeed;   
        }

        
        drawFlg = LO;
        DIAGNOSTIC_BLUE_LED = ~DIAGNOSTIC_BLUE_LED;
     }
      else if(INTCONbits.TMR0IF == HI && drawFlg == LO)
        {
          if(gameArray[irow][icol]==1)
                    { 
                        gameArray[irow][icol] = 0x00;// clear row 0 of previous paddle position data
                        
                    }
        DIAGNOSTIC_GREEN_LED = ~DIAGNOSTIC_GREEN_LED;
        drawFlg = HI;
        }
     
      writeMatrix(0,7,0,15);
      TMR0 = 0;
      INTCONbits.TMR0IF = LO; 
}    
 