#pragma once
#include "HraciePole.h"
#include "Stvorec.h"
#include <vector>
#include <string>
#include <iostream>


class biznisLogika
{
public:

	biznisLogika();
	std::string nastavPolohuSuradnic(int, int);
	void print();
	void navysPocetTahu();

	~biznisLogika();
private:
	HraciePole h_pole;
	std:: string ManazerPrikazov(int, Stvorec*);
	int Odos_tahy;
	int podavac_odpovedi = 0;
	int Pocet_Tahov;
	int Pocet_Odpovedi = 0;

	int const START = 10;
	int const ODPOVED_XY = 30;
	int const XY_STVOREC = 20;
	int const VYHRA = 40;
	int const PREHRA = 50;
};

