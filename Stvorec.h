#pragma once
class Stvorec
{
public:
	Stvorec(int, int, char, bool, bool);
	~Stvorec();
	int getRiadok();
	void setRiadok(int);
	int getStlpec();
	void setStlpec(int);

	bool jeVyplnene();
	void NastavVypln(bool);

	char getSymbolStvorca();
	void nastavSybmolStvorca(char symbol);

	bool jeZobrazene();
	void nastavZobrazenie(bool);

 private:
	 char symbol;
	 int stlpec;
	 bool vyplnene;
	 bool zobraz;
	 int riadok;

};

