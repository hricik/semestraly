#include "Hydroplan.h"


Hydroplan::Hydroplan()
	:Subjekt()
{
	inicializujItem();
}

Hydroplan::Hydroplan(int riadok, int stlpec)
	: Subjekt(riadok, stlpec)
{

	inicializujItem();
}

Hydroplan::~Hydroplan()
{

}

std::string Hydroplan::DajMeno() {
	return "Hydroplan";
}
void Hydroplan::inicializujItem() {

	itemy = { new item(pozicia.getRiadok(), pozicia.getStlpec() + 1),
		new item(pozicia.getRiadok() + 1, pozicia.getStlpec()),
		new item(pozicia.getRiadok() + 1, pozicia.getStlpec() + 2) };

}

void Hydroplan::aktualizujPoziciuItemu() {
	for (unsigned i = 0; i < velkostLode; i++) {
		itemy[i]->nastavPolohuSuradnic(pozicia.getRiadok(), pozicia.getStlpec() + i);
	}

}