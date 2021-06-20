#include "menuefrage.h"

void clpuf(void)
{
 while (getc(stdin) != '\n')
    ;
}


int MenueFrage(void)
{
 int i, rewer = 21;
 std::string frage[32] = {"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15",
                          "16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"}; 
 std::string wahl = "";
 std::cout << std::endl << "Ihre Wahl: ";
 std::cin >> wahl;
 clpuf();
 
 for (i = 0; i < 32; i++)
  {
   if (wahl.compare(frage[i]) == 0)
    {
     rewer = i;
     break;   
    }   
  }   

 return rewer; 
}