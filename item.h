#pragma once
#include "Pozicia.h"
class item

{
public: 
	item(int, int);
	bool Status();
	void nastavStatus(bool);
	Pozicia dajPoziciu();
	void nastavPoziciu(Pozicia);
	void nastavPolohuSuradnic(int, int);
	~item();

private:
	bool status;
	Pozicia pozicia;
};

