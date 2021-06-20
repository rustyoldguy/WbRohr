// Wb = (D^4) -(d^4)/ (10 * D)

#include "festi.h"

void Hauptmenue(void)
{
 std::cout << std::endl << "\n Festimath V1.36" << std::endl;
 std::cout << " Ende............................................= 0" << std::endl;
 std::cout << " Rohraussendurchmesser aus wb & Wandstaerke......= 1" << std::endl;
 std::cout << " Maximale Belastung(Biegewiderstandsmoment) aus..= 2" << std::endl;
 std::cout << " Rohraussendurchmesser & Wandstaerke" << std::endl;
 std::cout << " Durchmesser eines Rundmaterials aus wb..........= 3" << std::endl;
 std::cout << " Biegewiderstandsmoment wb eines Rundmaterials...= 4" << std::endl;
 std::cout << " Biegewiderstandsmoment wb in cmm aus............= 5" << std::endl;
 std::cout << " Rohrlaenge, angreifender Kraft in N und" << std::endl;
 std::cout << " zulaessige Biegespannung in N/cmm" << std::endl;
 std::cout << " max. zul angreifende Kraft an einem Rohr........= 6" << std::endl;
 std::cout << " Materialwahl fuer Simga_b_zul...................= 7" << std::endl;
 std::cout << " D aus angreifende Kraft, Laenge, Material.......= 8" << std::endl;
 std::cout << " Belastungsart" << std::endl;
 std::cout << " Rohrgewicht.....................................= 9" << std::endl;
 std::cout << " d aus D und wb..................................= 10" << std::endl;
}

void Rohr::getDundws(void)
 {
  std::cout << "Rohr-Aussendurchmesser in mm: ";
  std::cin >>  gd;
  std::cout << "Wandstärke in mm............: ";
  std::cin >> ws;
 }
 
void Rohr::ShowRohrwb(void)
 {
  std::cout << std::endl;
  std::cout << "Aussendurchmesser....: " << gd << " mm" << std::endl;
  std::cout << "Innendurchmesser.....: " << kd << " mm" << std::endl;
  std::cout << "Biegewiderstandmoment: " << wb << " cmm" << std::endl;
  std::cout << "Polarer(Torsion) Widerstandsmoment: " << Wp << " cmm" << std::endl;
  std::cout << "Flaechenmoment 2ten Grades I......: " << FM2GI << " mm^4" << std::endl;
 }

void Rohr::ZeigeErklaerung(void)
 {
  std::cout  << "zul. Biegespannung in N/cmm..= sigma_b_zul" << std::endl;
  std::cout  << "zul. Biegemoment in cmm......= Mb_zul" << std::endl;
  std::cout  << "Biegewiderstandsmoment...... = Wb" << std::endl;
  std::cout  << "max. zul. Belastung in N     = Fzul" << std::endl;
  std::cout <<  "mbzul = Fzul * l          wb = mb_zul / sigma_b_zul" << std::endl;
 }

void Rohr::getLaengeundF(void)
 {
 std::cout << std::endl << "Trägerlaenge in mm      l= "; std::cin >> l;
 std::cout << std::endl << "Biegewiderstandsmoment wb= "; std::cin >> wb;
 std::cout << std::endl << "zul.Biegespannung in N/qmm...sb zul= "; std::cin >> sbzul;
 } 
 
void Rohr::getD(void)
 {
  std::cout << std::endl << "Durchmesser des Rundmaterials in mm: ";
  std::cin >> d;
 }

void Rohr::getwb(void)
 {
  std::cout << std::endl << "Biegewiderstandsmoment in cmm: ";
  std::cin >> wb;
 }

void Rohr::ShowD(void)
 {
  std::cout << std::endl << "Potenz " << potenz << " dma " << dma << " wb" << wb<< std::endl;
  std::cout << "Durchmesser in mm" << dmb << std::endl;
 }

void Rohr::ShowKraefte(void)
 {
  std::cout << std::endl << "zulässiges Biegemoment in cmm.....Mb_zul= " << mbzul << std::endl;
  std::cout << "max. zul. Angreifende Kraft in N/ cmm : " << f << std::endl;
 }

void Rohr::RohrWBbausD(void)
{
 getDundws();
 calcRohrwb();
 ShowRohrwb();
}

void Rohr::Traegerf(void)
{
ZeigeErklaerung();
getLaengeundF();
calcKraefte();
ShowKraefte();
}

void Rohr::BelarundD(void)
{
getD();
calcwb();
Showwb();
}

void Rohr::RUND(void)
{
getwb();
calcD();
ShowD();
}
 
