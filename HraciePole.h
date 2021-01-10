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
	void premiesajSubjekty();
	void dajSubjektDoPola(Subjekt*);
	void resetujHraciePole();
	void nastavHodnotuStvorca(int, int, bool);
	void nastavSymbolStvorca(int, int, char);
	void nastavStatusItemuSubjektu(int, int, bool);
	void potopitItem(int, int, bool);
	bool overPotopeneItemy();
	bool dajHodnotuStvorca(int, int);
	bool overPodporuSubjektuVOblasti(Subjekt*, int, int);
	bool overOblastSubjektu(Subjekt*, int, int);
	bool overZnicenieSubjektu(Subjekt*);
	Subjekt* dajSubjekt(int row, int column);

	std::vector<std::vector<Stvorec*>> HracovStvorec;
	~HraciePole();

private:
	std::vector<Subjekt*> Subjekty;
	std::vector<std::vector<bool>> oblast;

};

