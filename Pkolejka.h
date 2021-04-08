#pragma once

#include <iostream>

class Pkolejka
{
public:
	typedef int* Wsk;
	typedef unsigned int Uint;
private:
	Uint rozmiar;
	Uint pojemnosc;
	Wsk stos;
public:
	Pkolejka(Uint _pojemnosc);
	~Pkolejka() { delete[]stos; };
	const int& get_pojemnosc() const { return pojemnosc; };
	bool nie_pusty() const { return rozmiar; };
	const bool& pelny() const { return (rozmiar==pojemnosc); };
	const Uint get_kolejka(Uint index)const { return stos[index]; };
	bool mniejszy(Uint roz,Uint rodzic);
	void do_gory();
	void wstaw_do_kolejki(int* arg);
	void zamien(Uint roz,Uint rodzic);
	void wyrzuc_z_kolejki();
	void w_dol();
	void zamien_kolejnosc();
};

std::ostream& operator << (std::ostream& strm, const Pkolejka& arg);

