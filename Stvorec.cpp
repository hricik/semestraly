#include "Stvorec.h"

Stvorec::Stvorec(int riadok, int stlpec, char symbol, bool vyplnene, bool zobrazene) 
{
	this->riadok = riadok;
	this->stlpec = stlpec;
	this->symbol = stlpec;
	this->vyplnene = vyplnene;
	this->zobraz = zobrazene;
}

int Stvorec::getRiadok()
{
	return this->riadok;
}
void Stvorec::setRiadok(int riadok)
{
	this->riadok = riadok;
}
int Stvorec::getStlpec() 
{
	return this->stlpec;
}
void Stvorec::setStlpec(int stlpec) 
{
	this->stlpec = stlpec;
}

bool Stvorec::jeVyplnene() 
{
	return vyplnene;
}
void Stvorec::NastavVypln(bool vyplnene)
{
	this->vyplnene = vyplnene;
}

char Stvorec::getSymbolStvorca() 
{
	return symbol;
}
void Stvorec::nastavSybmolStvorca(char symbol) 
{
	this->symbol = symbol;
}

bool Stvorec::jeZobrazene() 
{
	return zobraz;
}
void Stvorec::nastavZobrazenie(bool zobraz) 
{
	this->zobraz = zobraz;
}


Stvorec::~Stvorec()
{

}
