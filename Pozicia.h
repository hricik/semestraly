#pragma once
class Pozicia
{
public:

	Pozicia(int , int);
	int getRiadok();
	void setRiadok(int riadok);
	int getStlpec();
	void setStlpec(int stlpec);
	void nastavPolohuSuradnic(int, int);

	~Pozicia();

private:
	int riadok;
	int stlpec;
};

