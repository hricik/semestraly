#include "Kriznik.h"


Kriznik::Kriznik()
	:Subjekt()
{
	inicializujItem();
}

Kriznik::Kriznik(int riadok, int stlpec)
	: Subjekt(riadok, stlpec)
{
	inicializujItem();
}


Kriznik::~Kriznik()
{
}

std::string Kriznik::DajMeno()
{
	return "Kriznik";
}

void Kriznik::inicializujItem()
{
	itemy = { new item(pozicia.getRiadok(), pozicia.getStlpec()),
		new item(pozicia.getRiadok(), pozicia.getStlpec() + 1),
		new item(pozicia.getRiadok(), pozicia.getStlpec() + 2),
		new item(pozicia.getRiadok(), pozicia.getStlpec() + 3) };

}

void Kriznik::aktualizujPoziciuItemu()
{
	for (unsigned i = 0; i < velkostLode; i++) {
		itemy[i]->nastavPolohuSuradnic(pozicia.getRiadok(), pozicia.getStlpec() + i);
	}
}
