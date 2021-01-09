#pragma once
#include "Subjekt.h"
class lietadlovaLod : public Subjekt
{
public:
	lietadlovaLod();
	lietadlovaLod(int, int);
	~lietadlovaLod();
	std::string DajMeno()override;
	void inicializujItem()override;
	void aktualizujPoziciuItemu()override;

private:
	const int velkostLode = 5;
};

