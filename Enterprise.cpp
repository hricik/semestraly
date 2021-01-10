#include "Enterprise.h"



Enterprise::Enterprise()
	:Subjekt()
{
	inicializujItem();
}

Enterprise::Enterprise(int riadok, int stlpec)
	: Subjekt(riadok, stlpec)
{

	inicializujItem();
}


Enterprise::~Enterprise()
{
}


std::string Enterprise::getMeno() {
	return "Enterprise";
}
void Enterprise::inicializujItem() {

	itemy =
	{
		new item(pozicia.getRiadok(), pozicia.getStlpec()),
		new item(pozicia.getRiadok(), pozicia.getStlpec() + 1),
	};

}

void Enterprise::aktualizujPoziciuItemu() {
	for (unsigned i = 0; i < velkostLode; i++) {
		itemy[i]->nastavPolohuSuradnic(pozicia.getRiadok(), pozicia.getStlpec() + i);
	}

}