#pragma once
#include "Subjekt.h"
class Enterprise : public Subjekt
{
public:
	Enterprise();
	Enterprise(int, int);
	~Enterprise();
	std::string DajMeno()override;
	void inicializujItem()override;
	void aktualizujPoziciuItemu()override;

private:
	const int velkostLode = 2;
};

