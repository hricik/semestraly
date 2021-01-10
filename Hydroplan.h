#pragma once
#include "Subjekt.h"
class Hydroplan : public Subjekt
{
public:
	Hydroplan();
	Hydroplan(int, int);
	~Hydroplan();
	std::string getMeno()override;
	void inicializujItem()override;
	void aktualizujPoziciuItemu()override;

private:
	const int velkostLode = 3;
};


