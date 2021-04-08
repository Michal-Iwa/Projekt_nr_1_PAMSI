#include <iostream>
#include "Pkolejka.h"
#include <stdlib.h>    
#include <time.h> 

int main()
{
    int* ptr;
    int rozmiarwsk=1;
    std::cout << "Algorytm kolejki priorytetowej "<<std::endl;
    std::cout << "Wprowadz rozmiar wiadomosci(musi byc dodatni): ";
    std::cin >> rozmiarwsk;
    while (rozmiarwsk <= 0){
        std::cout << "Sprobuj jeszcze raz podac rozmiar widomosci (dodatnia liczba )";
        std::cin >> rozmiarwsk;
    }
    std::cout <<std::endl;
    ptr = new int[rozmiarwsk];
    srand(time(NULL));
    for (int i = 0; i < rozmiarwsk; i++) {
        ptr[i] = rand() % rozmiarwsk;
    }
    Pkolejka a(rozmiarwsk);
    a.wstaw_do_kolejki(ptr);
    std::cout << "Ulozenie liczb tak, ze im wyzej priorytetowane czesci wiadomosci(mniejsza liczba) tym wyzej w kopcu: "<<std::endl;
    std::cout << a << std::endl;
    a.wyrzuc_z_kolejki();
    a.zamien_kolejnosc();
    std::cout << "Odpowiedznio poukladana kolejka priorytetowa z najmniejsza(o najwyzszym priorytecie) liczba na gorze ";
    std::cout << a << std::endl;

}

