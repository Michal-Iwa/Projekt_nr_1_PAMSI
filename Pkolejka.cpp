#include "Pkolejka.h"
#include <iostream>


Pkolejka::Pkolejka(Uint _pojemnosc){
	pojemnosc = _pojemnosc;
	rozmiar = 0;
	stos = new int[pojemnosc];
	for (Uint i = 0; i < pojemnosc; i++) {
		stos[i] = NULL;
	}
}
std::ostream& operator <<(std::ostream& strm, const Pkolejka& arg) {
	for (unsigned int i = 0; i < arg.get_pojemnosc(); i++) {
		strm << arg.get_kolejka(i) <<" ";
	}
	return strm;
}
bool Pkolejka::mniejszy(Uint roz,Uint rodzic) {
	return (stos[roz] <= stos[rodzic]);

} 
void Pkolejka::zamien(Uint roz,Uint rodzic){
	int zamiennik;
	zamiennik = stos[roz];
	stos[roz] = stos[rodzic];
	stos[rodzic] = zamiennik;
}
void Pkolejka::do_gory()
{
	Uint rodzic;
	rodzic = (rozmiar - 1) / 2;
	while (nie_pusty() && mniejszy(rozmiar,rodzic)) {
		zamien(rozmiar,rodzic);
		rozmiar = rodzic;
		rodzic = (rozmiar - 1) / 2;
	}
}
void Pkolejka::wstaw_do_kolejki(int* arg) {
	stos[0] = arg[0];
	for (Uint i = 1; i < pojemnosc; i++){
		rozmiar = i;
		stos[i] = arg[i];
		do_gory();
	}
	rozmiar = pojemnosc;
}
void Pkolejka::w_dol() {
	Uint rodzic;
	rodzic= 0;
	Uint dziecko[2] = { rodzic * 2 + 1,rodzic * 2 + 2 };
	while (dziecko[1] < rozmiar && (mniejszy(dziecko[0], rodzic) || mniejszy(dziecko[1], rodzic))) {
		if (mniejszy(dziecko[0], dziecko[1])) {
			zamien(dziecko[0], rodzic);
			rodzic = dziecko[0];

		}
		else {
			zamien(dziecko[1], rodzic);
			rodzic = dziecko[1];
		}
		dziecko[0] = rodzic * 2 + 1;
		dziecko[1] = rodzic * 2 + 2;
	}

}
void Pkolejka::wyrzuc_z_kolejki(){
	while (rozmiar) {
		rozmiar--;
		zamien(0,rozmiar);
		w_dol();
		if (rozmiar == 0 && mniejszy(0, 1)) {
			zamien(0, 1);
		}
	}
	rozmiar = pojemnosc;
}
void Pkolejka::zamien_kolejnosc() {
	for (Uint i = 0; (i != rozmiar-1 && i!= rozmiar-2); i++) {
		zamien(i, rozmiar-1);
		rozmiar--;
	}
}
