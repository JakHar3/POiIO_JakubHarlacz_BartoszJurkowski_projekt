#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TPytanie.h"

using namespace std;


class TRunda {
private:
    TPytanie pytanie;
    vector<bool> odkryte;

    int liczba_bledow;
    int punkty_rundy;
    

public:
    TRunda();

    int zgadnij(string odp_gracza, bool licz_bledy = true);
    bool czy_koniec();

    int get_suma_punktow();
    int get_liczba_bledow();

    void wyswietl_stan(int number_rundy, bool wyswietl_ilosc_bledow = true);

    void sczytaj_pytanie(vector<TPytanie>& baza);
    TPytanie losuj_pytanie(vector<TPytanie>& baza);
    void ustaw_pytanie(TPytanie p);

    int wartosc_odpowiedzi(string odp);

    void wyswietl_stan_final(vector<string> odp_gracza1,
        vector<string> odp_gracza2, vector<vector<TOdpowiedz>> popr_odp_final,
        vector<int> pkt);
private:
    string normalizuj(string tekst);
};
