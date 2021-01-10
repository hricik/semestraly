#pragma once
#include "Pozicia.h"
#include "item.h"
#include <string>
#include <vector>
#include <list>

class Subjekt
{
public:
	Subjekt();
	Subjekt(int, int);
	
	std::vector<item*>&DajItem();

	int getSirka();
	int getVyska();

	Pozicia getPozicia();

	virtual ~Subjekt();
	virtual std::string DajMeno() = 0;
	virtual void aktualizujPoziciuItemu() = 0;
	virtual void inicializujItem() = 0;

protected:
	std::vector<item*>itemy;
	Pozicia pozicia;


};

