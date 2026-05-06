#pragma once
#include "TPytanie.h"

class TRunda {
private:
    TPytanie pytanie;
    std::vector<bool> odkryte;
    int liczba_bledow = 0;

public:
    TRunda(TPytanie& p);

    bool zgadnij(std::string& odp);
    bool czy_koniec();
    int suma_punktow();

    void sczytaj_pytanie();

    void wyswietl_stan();
};