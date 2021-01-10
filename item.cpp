#include "item.h"

//konstrukor
item::item(int riadok, int stlpec) 
	:pozicia(riadok, stlpec)
{
	this->status = true;
}
//getter na status
bool item::Status() 
{
	return this->status;
}

//setter na status
void item::nastavStatus(bool p_status) 
{
	this->status = p_status;

}
//getter na poziciu
Pozicia item::dajPoziciu() 
{
	return this->pozicia;
}
//setter na poziciu
void item::nastavPoziciu(Pozicia poz)
{
	this->pozicia = poz;
}

//nastavuje suradnice 
void item::nastavPolohuSuradnic(int riadok, int stlpec) 
{
	this->pozicia.setRiadok(riadok);
	this->pozicia.setStlpec(stlpec);
}
//destruktor
item::~item()
{
}