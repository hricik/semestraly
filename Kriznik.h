#pragma once
#include "Subjekt.h"
class Kriznik : public Subjekt
{
public:
	Kriznik();
	Kriznik(int, int);
	~Kriznik();
	std::string DajMeno()override;
	void inicializujItem()override;
	void aktualizujPoziciuItemu()override;

private:
	const int velkostLode = 4;
};

