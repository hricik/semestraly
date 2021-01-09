#pragma once
#include "Subjekt.h"
#include "stvorec.h"
#include <random>
#include "lietadlovaLod.h"
#include "Ponorka.h"
#include "Enterprise.h"
#include "Kriznik.h"
#include "Hydroplan.h" 

class HraciePole
{
public:
	HraciePole();
	void vytvorPrazdneHraciePole();
	void dajSubjektDoPola(Subjekt*);
	void resetujHraciePole();
	void premiesajSubjekty();
	void nastavHodnotuStvorca(int, int, bool);
	void nastavSymbolStvorca(int, int, char);
	void nastavStatusItemuSubjektu(int, int, bool);
	void potopitItem(int, int, bool);
	bool overPotopeneItemy();
	bool dajHodnotuStvorca(int ,int);
	bool overPodporuSubjektovOblasti(Subjekt*, int ,int);
	bool overOblastSubjektu(Subjekt*, int, int);
	bool overZnicenieSubjektu(Subjekt*);
	Subjekt* dajSubjekt(int riadok, int stlpec);

	std::vector<std::vector<Stvorec*>> hracove_hracie_pole;
	~HraciePole();

private:
	std::vector<Subjekt*> subjekty;
	std::vector<std::vector<bool>> oblast;

};

