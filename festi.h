#ifndef FESTI_H_INCLUDED
#define FESTI_H_INCLUDED

#include <iostream>
#include <math.h>
#include "menuefrage.h"

void Hauptmenue(void);
long double Traeger(long double sbzul = 0);
long double SucheInkrementwert(long double m, long double x);
long double IstWbausRohr(long double (*kd1), long double ws, long double gd);
void RohrDauswbundws(long double m = 0, long double ws = 0);
long double Materialwahl(void);



class Rohr
{
 public:
   Rohr();
   ~Rohr(){};
   long double gd, kd, ws, wb, gdh4, kdh4, agd, akd, PI, Wp;
   // Wp=polares Widerstandsmoment
   long double FM2GI; // FM2GI=Flaechenmoment 2ten Grades I

    struct Materialdaten
     {
      std::string Belastungsart[3];
      std::string Material[7];
      int Untergrenze[3][7];
      int Obergrenze[3][7];
     } matdat;


  //Für Rohre
  void getDundws(void);
  void calcRohrwb(void);
  void calcGewicht(void);
  void ShowRohrwb(void);
  void ZeigeErklaerung(void);
  void getLaengeundF(void);
  void calcKraefte(void);
  void ShowKraefte(void);
  void RohrWBbausD(void);
  void Traegerf(void);
  void InitRohr(void);
  long double Materialwahl(void);
  void DiaofTraeger(void);
  //Für Vollmaterialien
  void getD(void);
  void calcwb(void);
  void Showwb(void);
  void getwb(void);
  void calcD(void);
  void ShowD(void);
  void BelarundD(void);
  void RUND(void);
  
  private:
    long double l,f,mbzul,sbzul, ARohr, VRohr, agw;
    long double d, potenz, dma, dmb;

};


#endif // FESTI_H_INCLUDED
