#include "Pozicia.h"
//zakladna dedicnost - z tejto triedy dedia ostatne triedy

//konstruktor triedy
Pozicia::Pozicia(int riadok, int stlpec){
	this->riadok = riadok;
	this->stlpec = stlpec;

}
//getter na riadok
int Pozicia::getRiadok() 
{
	return this->riadok;
}

//setter na riadok
void Pozicia::setRiadok(int riadok) 
{
	this->riadok = riadok;
}
//getter na stlpec
int Pozicia::getStlpec() 
{
	return this->stlpec;
}
//setter na stlpec
void Pozicia::setStlpec(int stlpec) 
{
	this->stlpec = stlpec;

}
//metoda na nastanevie polohy suradnic
void Pozicia::nastavPolohuSuradnic(int, int) 
{

}
//destruktor
Pozicia::~Pozicia() 
{

}