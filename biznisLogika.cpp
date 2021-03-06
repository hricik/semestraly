#include "biznisLogika.h"

using namespace std;

biznisLogika::biznisLogika() {
	Odos_tahy = 0;
	Pocet_Tahov = 1;
}

std::string biznisLogika::nastavPolohuSuradnic(int riadok, int stlpec) {

	string odpoved = "CHYBA #(nastavPolohuSuradnic)";
	if (!(riadok > 15 || riadok < 0) && !(stlpec > 15 || stlpec < 0)) {
		if (!h_pole.HracovStvorec[riadok][stlpec]->jeVyplnene()) {
			return ManazerPrikazov(XY_STVOREC, h_pole.HracovStvorec[riadok][stlpec]);
		}
		else
		{
			odpoved = "Premrhal si tah :(";
			ManazerPrikazov(PREHRA, nullptr);
		}
		Odos_tahy++;
	}
	else
	{
		odpoved = "Mimo rozsah";
	}
	return odpoved;
}
void biznisLogika::print() {
	for (int i = 0; i < h_pole.HracovStvorec.size(); i++) 
	{
		std::cout << "---";
	}
	std::cout << " " << std::endl;

	for (int i = 0; i < h_pole.HracovStvorec.size(); i++)
	{
		for (int j = 0; j < h_pole.HracovStvorec[i].size(); j++)
		{
			std::cout << "| " << h_pole.HracovStvorec[i][j]->getSymbolStvorca();
		}
		std::cout << "| " << i  << std::endl;
	}
	for (int i = 0; i < h_pole.HracovStvorec.size(); i++) {
		std::cout << "---";
	}
	std::cout << " ";
	std::cout << "" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << " " << i  << " ";
	}

	for (int i = 10; i < h_pole.HracovStvorec.size(); i++) {
		std::cout << " " << i ;
	}

	std::cout << " " << std::endl;

}
void biznisLogika::navysPocetTahu() {
	
	podavac_odpovedi++;
	if (podavac_odpovedi == Pocet_Tahov) {
		cout << "Si na rade !" << endl;
		Odos_tahy = 0;
		podavac_odpovedi = 0;
	}
}
biznisLogika::~biznisLogika() {

}
std::string biznisLogika::ManazerPrikazov(int cislo_prikazu, Stvorec* stvorec) {
	string odpoved = "CHYBA #(ManazerPrikazov)";
	navysPocetTahu();
	if (cislo_prikazu == XY_STVOREC) {
		if (h_pole.dajHodnotuStvorca(stvorec->getRiadok(), stvorec->getStlpec())) {
			Subjekt* subjekt = h_pole.dajSubjekt(stvorec->getRiadok(), stvorec->getStlpec());
			h_pole.potopitItem(stvorec->getRiadok(), stvorec->getStlpec(), false);
			h_pole.nastavSymbolStvorca(stvorec->getRiadok(), stvorec->getStlpec(), 'X');
			if (h_pole.overPotopeneItemy()) 
			{
				if (h_pole.overZnicenieSubjektu(subjekt)) 
				{
					odpoved = "Potopil si : " + subjekt->DajMeno();
				}
				else {
					odpoved = "trafil si : " + subjekt->DajMeno();
				}
			}
			else {
				odpoved = "PREHRAL SI HRU!";
			}
		}
		else {
			h_pole.nastavSymbolStvorca(stvorec->getRiadok(), stvorec->getStlpec(), ' ');
			odpoved = "trafil si do VODY";
		}

	}
	print();
	return odpoved;

}