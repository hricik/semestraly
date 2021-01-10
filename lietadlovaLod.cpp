#include "lietadlovaLod.h"

//trieda dedi z triedy item

//konstruktor
lietadlovaLod::lietadlovaLod()
	:Subjekt()
{
	inicializujItem();
}
//konstruktor
lietadlovaLod::lietadlovaLod(int riadok, int stlpec)
	: Subjekt(riadok, stlpec)
{
	inicializujItem();
}
//destruktor
lietadlovaLod::~lietadlovaLod() 
{

}
//getter na meno objectu
std::string lietadlovaLod::DajMeno() 
{
	return "Lietadlova lod";
}
//metoda na inicializaciu a pripravu itemu
void lietadlovaLod::inicializujItem() {
	itemy =
	{
		new item(pozicia.getRiadok(),pozicia.getStlpec()),
		new item(pozicia.getRiadok(),pozicia.getStlpec() + 1),
		new item(pozicia.getRiadok(),pozicia.getStlpec() + 2),
		new item(pozicia.getRiadok(),pozicia.getStlpec() + 3),
		new item(pozicia.getRiadok(),pozicia.getStlpec() + 4)
	};
}
// metoda na aktualizovanie pozicie itemu na hracej ploche
void lietadlovaLod::aktualizujPoziciuItemu() {
	for (unsigned i = 0; i < velkostLode; i++) {
		itemy[i]->nastavPolohuSuradnic(pozicia.getRiadok(), pozicia.getStlpec() + i);
	}
}