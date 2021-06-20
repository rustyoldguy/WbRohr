#include <iostream>

using namespace std;

#include <string.h>
#include "festi.h"

int main(void)
{
int wouhi = 21;
Rohr homa;

do
switch(wouhi)
{
  default:
    Hauptmenue();
    wouhi = MenueFrage();
   break;
  
 case 0:
     std::cout << "Programm beendet" << std::endl;
     return 0;
   break;

 case 1:
   RohrDauswbundws();
   wouhi = 21;
   break;

 case 2:
   homa.RohrWBbausD();
   wouhi = 21;
   break;

 case 3: homa.RUND();
   wouhi = 21;
   break;

 case 4:
   homa.BelarundD();
   wouhi = 21;
   break;
 
 case 5:
   Traeger();
   wouhi = 21;
   break;
 
 case 6:
   homa.Traegerf();
   wouhi = 21;
   break;
 
 case 7:
   homa.Materialwahl();
   wouhi = 21;
   break;
 
 case 8:
  homa.DiaofTraeger();
  wouhi = 21;
  break;

 case 9:
  homa.calcGewicht();
  wouhi = 21;
  break;
 
 case 10:
     std::cout << "Innendurchmesser aus D und wb" << std::endl;
     std::cout << "Aussendurchmesser in mm : ";
     std::cin >> homa.gd;
     std::cout << "Widerstandsbiegemoment Wb : ";
     std::cin >> homa.wb;
  
     homa.gdh4 = homa.gd * homa.gd * homa.gd * homa.gd;
     //homa.wb * 32 * homa.gd = M_PI *(homa.gdh4 - d^4)
     //(homa.wb * 32 * homa.gd) / M_PI = (homa.gdh4 - d^4)
     //((homa.wb * 32 * homa.gd) / M_PI) + kdh4 = homa.gdh4
     homa.kdh4 = homa.gdh4 - ((homa.wb * 32 * homa.gd) / M_PI);
     homa.kd = pow(homa.kdh4, 0.25);
     std::cout << "Innendurchmesser in mm : " << homa.kd << std::endl; 
     wouhi = 21;
  break;
}
while ( wouhi != 0);

std::cout << "Programm beendet" << std::endl;
return 0;
}
// Wb = (D^4) -(d^4)/ (10 * D)
// 10 * Wb = (D^4) -(d^4)/  D
// D * 10Wb = (D^4) - (d^4)
// 10Wb = (D^3) - ((d^4) / D)
// (d^4) =  (D^4) + 10Wb  
// (d =  pow( ((D^4) + 10Wb), 0.25);  
