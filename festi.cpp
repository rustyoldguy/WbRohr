#include "festi.h"



// gibt bei Trägerlänge und angreifender Kraft den Widerstandsbiegemoment zurück
long double Traeger(long double sbzul)
{
 long double l,f,mbzul, wb;
  
  std::cout << "\nTrägerlaenge in mm................l: ";
  std::cin >> l;
  std::cout << "\nmax. zulaessige Belastung Fzul in N: ";
  std::cin >> f;

  if (sbzul == 0)
   {
    std::cout << "\nzul.Biegespannung in N/qmm...sb zul= ";
    std::cin >> sbzul;
   }

  mbzul = f * l;
  wb = mbzul / sbzul;

  std::cout << "\nzul. Biegespannung sigma_b_zul.....= " << std::fixed << sbzul << " N/cmm";
  std::cout << "\nzulaessiges Biegemoment Mb_zul.....= " << mbzul << " cmm";
  std::cout << "\nBiegewiderstandsmoment. Wb.........= " << wb << " cmm";
  std::cout << "\nmbzul = Fzul * l";
  std::cout << "\nwb = Mb_zul / sigma_b_zul";
  std::cout << "\nzulässiges Biegemoment Mb_zul......= " <<  std::fixed << wb << " cmm" << std::endl << std::endl;

return(wb);
}
/*
Rohr::Rohr()
  : gd{}, kd{}, ws{}, gdh4{}, kdh4{}, wb{}, agd{}, akd{}, PI{3.141592653589793},
    l{}, f{}, mbzul{}, sbzul{}, ARohr{}, VRohr{}, agw{}, d{}, potenz{}, dma{}, dmb{},
    matdat{
      {"BiegungI", "BiegungII", "BiegungIII"},
      {"ST-37", "ST-50", "ST-70", "GS-45", "G-AlSi", "AlCuMg2", "AlMg3"},
      {
        {110, 150, 230, 110, 35, 120, 90},
        {70, 100, 150, 70, 20, 50, 58},
        {50, 70, 105, 50, 14, 35, 45}
      },
      {
        {165, 220, 245, 165, 50, 175, 135},
        {105, 150, 220, 105, 28, 70, 88},
        {75, 105, 125, 75, 21, 55, 68}
      }
    }
{
}
*/
Rohr::Rohr()
{
int slei, sleib;
PI = M_PI;

matdat.Belastungsart[0] = "BiegungI";
matdat.Belastungsart[1] = "BiegungII";
matdat.Belastungsart[2] = "BiegungIII";

matdat.Material[0] = "ST-37";
matdat.Material[1] = "ST-50";
matdat.Material[2] = "ST-70";
matdat.Material[3] = "GS-45";
matdat.Material[4] = "G-AlSi";
matdat.Material[5] = "AlCuMg2";
matdat.Material[6] = "AlMg3";


int Ug[3][7] = { 110,150,230,110,35,120,90,   //ug1
                 70, 100,150, 70,20, 50,58,   //ug2
                 50, 70, 105, 50,14, 35,45
               };   //ug3

int Og[3][7] = { 165,220,245,165,50,175,135,  //og1
                 105,150,220,105,28, 70, 88,  //og2
                 75, 105, 125,75,21, 55, 68}; //og3

for (slei = 0; slei < 3; slei++)
 for (sleib = 0; sleib < 7; sleib++)
  {
   matdat.Untergrenze[slei][sleib] = Ug[slei][sleib];
   matdat.Obergrenze[slei][sleib] = Og[slei][sleib];
  }

}

// berechnet den axialen Widerstandsmoment(Biegewiderstandsmoment) eines Rohres
void Rohr::calcRohrwb(void)
 {
  kd = gd - (ws * 2);
  gdh4 = gd * gd * gd * gd;
  kdh4 = kd * kd * kd * kd;
  wb = (M_PI * (gdh4 - kdh4)) / (gd * 32);
  Wp = wb * 2; // Polares Widerstandsmoment
  FM2GI = (M_PI * (gdh4 - kdh4)) / 64; // FM2GI=Flaechenmoment 2ten Grades I
 }
void Rohr::calcGewicht(void)
 {
  std::cout << "\nRohr-Aussendurchmesser in mm: "; std::cin >> gd;
  std::cout << "\nWandstärke in mm............: "; std::cin >> ws;
  std::cout << "\nRohrlaenge in mm............: "; std::cin >> l;
  std::cout << "\nMaterialgewicht in kg/cdm...: "; std::cin >> agw;

  agd = gd * gd * PI * 0.25;
  kd  = gd - (2 * ws);
  akd = kd * kd * PI * 0.25;
  ARohr = (agd - akd) / 10000;
  VRohr = (ARohr * l * agw) / 100;
  std::cout << "Kleiner Dmr in mm....: " << kd << std::endl;
  std::cout << "Rohrgewicht: in kg...: " << VRohr << std::endl;
 }

void Rohr::calcKraefte(void)
 {
  mbzul = sbzul * wb;
  f    = mbzul / l;
 }

void Rohr::calcwb(void)
 {
  wb = ((d *d *d) * PI) / 32;
  Wp = (M_PI * d * d * d) / 16;
  FM2GI = (M_PI * d * d * d * d) / 64;
 }
void Rohr::Showwb(void)
 {
  std::cout << std::endl << "Rundmaterial, Vollmaterial:" << std::endl;
  std::cout << "axialer Widerstandsmoment(= Biegewiderstandsmoment): " << wb << " ccm" << std::endl;
  std::cout << "Polarer(Torsion) Widerstandsmoment.................: " << Wp << " ccm" << std::endl;
  std::cout << "Flaechenmoment 2ten Grades I.......................: " << FM2GI << " mm^4" << std::endl;
 }

void Rohr::calcD(void)
 {
  potenz = 1.00 / 3.00;
  dma = (wb * 32) / PI;
  dmb = powl( dma,  potenz );
 }

long double SucheInkrementwert(long double m, long double x)
{
long double b, schrittfaktor;
        schrittfaktor = 1 - (x / m);
        b = schrittfaktor * 2;
        if (( x > (.9 * m))          && (x < (1.1 * m)) )        b = schrittfaktor * 1.5;
        if (( x > (.99 * m))         && (x < (1.01 * m)) )       b = schrittfaktor * 0.75;
        if (( x > (.999 * m))        && (x < (1.001 * m)) )      b = schrittfaktor * 0.5;
        if (( x > (.9999 * m))       && (x < (1.0001 * m)) )     b = schrittfaktor * 0.25;
        if (( x > (.99999 * m))      && (x < (1.00001 * m)) )    b = schrittfaktor * 0.125;
        if (( x > (.999999 * m))     && (x < (1.000001 * m)) )   b = schrittfaktor * 0.075;
        if (( x > (.9999999 * m))    && (x < (1.0000001 * m)) )  b = schrittfaktor * 0.001;
        //if (( x > (.999999999 * m))  && (x < (1.000000001 * m)) ) b = (1 - (x / m)) * 0.0001;
        if (( x > (.99999999999 * m)) && (x < (1.00000000001 * m)) ) b = 0;
        //LOCATE(11,1);
        //printf("istwb=%Lf  urwb=%Lf  b=%Lf    slei: %Lf", x, m, b, slei);
        //slei++;
return(b);
}

/* Eingangswert ist gd und ws(zunaechst Startwert). Daraus wird wb errechnet
 * der Innendurchmesser wird an Parameter 1 zurueckgegeben
 */
long double IstWbausRohr(long double (*kd1), long double ws, long double gd)
{
long double x, t, gdh4, kdh4, N, kd;

  kd   = gd - (2 * ws);      // Errechne Innendurchmesser
  gdh4 = gd * gd * gd * gd;  // D hoch 4
  kdh4 = kd * kd * kd * kd;  // d hoch 4
  N    = gdh4 - kdh4;        // N = (d^4) - (d^4)
  t    = 10 * gd;            // t = 10 * D
  x    = N / t;              // (d^4) - (d^4) / (10 * D)
  (*kd1) = kd;               // Rueckgabe des Innendurchmesser an Parameter 1

return(x);
}
// m ist der gegebene Biegewiderstandsmoment, ws ist Wandstärke
void RohrDauswbundws(long double m, long double ws)
{
long double gd,kd, x, a,b;
 /* Hole Werte von wb und ws */
            if (m == 0)
            {
            std::cout << std::endl << "Biegewiderstandsmoment in mm³.........Wb = ";
            std::cin >> m; // m=gegebener Biegewiderstandsmoment
            }
            else
             std::cout << std::endl << "Biegewiderstandsmoment in mm³.........Wb = " << m; // m=gegebener Biegewiderstandsmoment

            if (ws == 0)
            {
            std::cout << std::endl << "Wandstärke in mm.........................= ";
            std::cin >> ws;
            }
            else
             std::cout << std::endl << "Wandstärke in mm......................ws = " << ws;

      a = 2 * ws;
      b = 1;        // Startwert der Berechnung D ist (2 * wb) + 1 (b ist Innendurchmesser)
      //printf("\nm: %Lf\n", m);
      if ( m > 950)   b = m / 95; // Bei Werten von m > 950 Begrenzung auf 95N (alt: b = 10;)
      //if ( m > 9500)  b = 100;
      //if ( m > 95000) b = 1000;

do{
//suchen:
       gd   = a + b; // errechne D (Startwert)
        /* Eingangswert ist gd und ws(zunaechst Startwert). Daraus wird wb errechnet
         * der Innendurchmesser wird an Parameter 1 zurueckgegeben
         */
        x = IstWbausRohr(&kd, ws, gd); // x = errechneter wb aus den Vorgabewerten
        //long double SucheInkrementwert(long double sollwert, long double istwert)
        b = SucheInkrementwert(m, x);
        if (b == 0) break;//goto ergebnis;
        a = gd;
}
while(b != 0);
 //goto suchen;

//ergebnis:
std::cout << std::endl << "D=" << gd << " d=" << kd << " Wb=" << x << " bei " << ((x / m) * 100) << "% Genauigkeit";
}

void Rohr::DiaofTraeger(void)
{
long double sbzul, wb;
sbzul = Materialwahl();
// gibt bei Trägerlänge und angreifender Kraft den Widerstandsbiegemoment zurück
wb = Traeger(sbzul);
RohrDauswbundws(wb, 0);
}

/* Rückgabewert ist die Biegeuntergrenze als sbzul */
long double Rohr::Materialwahl(void)
{

int belart, material, slei, biegunter, biegober;

std::cout << "PI: " << PI << std::endl;
std::cout << "Belastungsart: " << std::endl;
for (slei = 0; slei < 3; slei++)
 std::cout << "Nr." << (slei + 1) <<  "     " << matdat.Belastungsart[slei] << std::endl;

std::cout << "Material: " << std::endl;
for (slei = 0; slei <= 6; slei++)
 std::cout << "Nr." << (slei + 1) <<  "     " << matdat.Material[slei] << std::endl;


std::cout << "Belastungsart: 1=statisch  2=schwellend  3=schwingend" << std::endl;
std::cout << "Eingabe Belastunsart[1-3]: " << std::endl;
std::cin >> belart;
std::cout << "Eingabe Material[1-7]: " << std::endl;
std::cin >> material;
belart--;
material--;


biegunter = matdat.Untergrenze[belart][material];
biegober  = matdat.Obergrenze[belart][material];

std::cout << "Belastungsart: " << matdat.Belastungsart[belart] << "   Material: " << matdat.Material[material] << std::endl;
sbzul = (long double)biegunter;
std::cout << "sigmab_zul: " << biegunter << "..." << biegober << " N/mm²" << std::endl;

return(sbzul);
}



