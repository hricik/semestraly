#pragma once
#include "Subjekt.h"
class Ponorka : public Subjekt
{
public:
	Ponorka();
	Ponorka(int, int);
	~Ponorka();
	std::string getMeno()override;
	void inicializujItem()override;
	void aktualizujPoziciuItemu()override;


};