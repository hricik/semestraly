#include "Ponorka.h"

Ponorka::Ponorka()
	:Subjekt()
{
	inicializujItem();
}

Ponorka::Ponorka(int riadok, int stlpec)
	: Subjekt(riadok, stlpec)
{

	inicializujItem();
}

Ponorka::~Ponorka()
{

}

std::string Ponorka::getMeno() {
	return "Ponorka";
}
void Ponorka::inicializujItem() {

	itemy = { new Item(pozicia.getRiadok(), pozicia.getStlpec()) };

}

void Ponorka::aktualizujPoziciuItemu() {
	itemy[0]- nastavPolohuSuradnic(pozicia.getRiadok(), pozicia.getStlpec());
}