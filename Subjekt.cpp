#include "Subjekt.h"

//standardny konstruktor
Subjekt::Subjekt() :pozicia(0, 0) {}
//konstruktor 
Subjekt::Subjekt(int riadok, int stlpec)
	:pozicia(riadok, stlpec) {}

//getter na itemy
std::vector<item*>& Subjekt::DajItem()
{
	return itemy;
}
//getter na sirku
int Subjekt::getSirka() 
{
	int sirka = 1;
	int sirka_max = 0;
	for (item* item : itemy) {
		if (item->dajPoziciu().getStlpec() > sirka_max) {
			sirka_max = item->dajPoziciu().getStlpec();
			sirka++;
		}
	}
	return sirka;
}
//getter na vysku
int Subjekt::getVyska() 
{
	int vyska = 1;
	int vyska_max = 0;
	for (item* item : itemy) {
		if (item->dajPoziciu().getRiadok() > vyska_max) {
			vyska_max = item->dajPoziciu().getRiadok();
			vyska++;
		}
	}
	return vyska;
}
//getter na poziciu
Pozicia Subjekt::getPozicia() 
{
	return pozicia;
}
//destruktor
Subjekt::~Subjekt() 
{
}