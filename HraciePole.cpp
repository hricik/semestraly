#include "HraciePole.h"


HraciePole::HraciePole() 
{
	for (int x = 0; x < 15; x++) {
		std::vector<bool> temp;
		for (int y = 0; y < 15; y++) {
			temp.push_back(false);
		}
		oblast.push_back(temp);
	}
	vytvorPrazdneHraciePole();
	premiesajSubjekty();
}
void HraciePole::vytvorPrazdneHraciePole() 
{
	for (int x = 0; x < 15; x++) {
		std::vector<Stvorec*> temp;
		for (int y = 0; y < 15; y++) {
			temp.push_back(new Stvorec(x,y,'#',false,true));
		}
		hracove_hracie_pole.push_back(temp);
	}
}

void premiesajSubjekty()
{
	std::vector<Subjekt*> subjektVector = { new Ponorka(), new Ponorka(), new Ponorka(), new Ponorka(),
		new Hydroplan(), new Hydroplan() ,new Hydroplan() , new Kriznik(), new Kriznik(),
		new Kriznik(), new Enterprise(), new Enterprise(), new lietadlovaLod()
	};

	std::vector<Subjekt*> subjekty;

	while (subjektVector.size() > 0) {
		int radnomIndexVektoru = (rand() % subjektVector.size());
		int radnomRiadok = (rand() % 15);
		int radnomStlpec = (rand() % 15);

		if (overPodporuSubjektovOblasti(subjektVector.at(radnomIndexVektoru), radnomRiadok, radnomStlpec) && !overOblastSubjektu(subjektVector.at(radnomIndexVektoru), radnomRiadok, randomStlpec)) {
			Subjekt* subjekt = subjektVector.at(radnomIndexVektoru);
			subjekt->getPozicia().nastavPolohuSuradnic(randomRiadok, randomStlpec);
			subjekt->aktualizujPoziciuItemu();



			subjekty.push_back(subjekt);
			dajSubjektDoPola(subjekt);

			subjektVector.erase(subjektVector.begin() + radnomIndexVektoru)
		}

	}
}

void HraciePole::dajSubjektDoPola(Subjekt* subjekt) 
{
	for (item* item : subjekt->DajItem()) {
		oblast[item->dajPoziciu().getRiadok()][item->dajPoziciu().getStlpec()] = true;
	}

}
void HraciePole::resetujHraciePole() 
{
	for (int riadok = 0; riadok < oblast.size(); riadok++) {
		for (int stlpec = 0; stlpec < oblast[riadok].size(); stlpec++) {
			oblast[riadok][stlpec] = false;
		}
	}
}
void HraciePole::nastavHodnotuStvorca(int riadok, int stlpec, bool hodnota) 
{
	if (riadok <= oblast.size() && stlpec <= oblast.size()) {
		oblast[riadok][stlpec] = hodnota;
	}
}
void HraciePole::nastavSymbolStvorca(int riadok, int stlpec,char symbol) 
{
	if (riadok <= oblast.size() && stlpec <= oblast.size()) {
		hracove_hracie_pole[riadok][stlpec]->NastavVypln(true);
		hracove_hracie_pole[riadok][stlpec]->nastavSybmolStvorca(symbol);
	}
}

void HraciePole::nastavStatusItemuSubjektu(int riadok, int stlpec, bool hodnota)
{
	for (auto subjekt : subjekty) {
		for (auto item : subjekt->DajItem()) {
			//Because position was initialized with (0,0).
			if (item->dajPoziciu().getRiadok() == riadok && item->dajPoziciu().getStlpec() == stlpec) {
				item->nastavStatus(hodnota);
			}
		}
	}
}

void HraciePole::potopitItem(int riadok, int stlpec, bool hodnota) 
{
	nastavHodnotuStvorca(riadok, stlpec, hodnota);
	nastavStatusItemuSubjektu(riadok, stlpec, hodnota);
}

bool HraciePole::overPotopeneItemy() 
{
	for (Subjekt *subjekt : subjekty) {
		for (item *item : subjekt->DajItem()) {
			if (item->Status()) {
				return true;
			}
		}
	}
	return false;
}

bool HraciePole::dajHodnotuStvorca(int x, int y) 
{
	if (x <= oblast.size() && y <= oblast.size()) {
		return oblast[x][y];
	}
	else {
		return false;
	}
}




bool HraciePole::overOblastSubjektu(Subjekt *subjekt, int riadok, int stlpec) 
{
	for (item* item : subjekt->DajItem()) {
		if (oblast[item->dajPoziciu().getRiadok() + riadok][item->dajPoziciu().getStlpec() + stlpec]) {
			return true;
		}
	}
	return false;
}

bool HraciePole::overZnicenieSubjektu(Subjekt* subjekt) 
{
	for (item* item : subjekt->DajItem()) {
		if (item->Status()) {
			return false;
		}
	}
	return true;

}


Subjekt* HraciePole::dajSubjekt(int riadok, int stlpec)
{
	for (auto subjekt : subjekty) {
		for (auto item : subjekt->DajItem()) {
			if (item->dajPoziciu().getRiadok() == riadok && item->dajPoziciu().getStlpec() == stlpec) {
				return subjekt;
			}
		}
	}
	return nullptr;
}

HraciePole::~HraciePole() 
{

}