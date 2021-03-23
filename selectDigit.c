#include "config.h"
#include "printDigit.h"
#include "arrays.h"
void selectDigit (uchar num, uchar rowL, uchar rowH)
{
    switch(num)
    {
            case 0:
            printDigit(rowL, rowH, cero);    
            break;
            
            case 1:
            printDigit(rowL, rowH, uno);    
            break;
            
            case 2:
            printDigit(rowL, rowH, dos);    
            break;
            
            case 3:
            printDigit(rowL, rowH, tres);    
            break;
            
            case 4:
            printDigit(rowL, rowH, cuatro);    
            break;
            
            case 5:
            printDigit(rowL, rowH, cinco);    
            break;
            
            case 6:
            printDigit(rowL, rowH, seis);    
            break;
            
            case 7:
            printDigit(rowL, rowH, siete);    
            break;
            
            case 8:
            printDigit(rowL, rowH, ocho);    
            break;
            
            case 9:
            printDigit(rowL, rowH, nueve);    
            break;
    }              
}