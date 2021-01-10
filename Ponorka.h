#pragma once
#include "Subjekt.h"
class Ponorka : public Subjekt
{
public:
	Ponorka();
	Ponorka(int, int);
	~Ponorka();
	std::string DajMeno()override;
	void inicializujItem()override;
	void aktualizujPoziciuItemu()override;


};