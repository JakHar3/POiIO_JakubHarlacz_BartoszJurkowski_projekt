#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TPytanie.h"

//using namespace std;


class TRunda {
private:
    TPytanie pytanie;
    std::vector<bool> odkryte;

    int liczba_bledow;
    int punkty_rundy;
    

public:
    TRunda();

    int zgadnij(std::string odp_gracza, bool licz_bledy = true);
    bool czy_koniec();

    int get_suma_punktow();
    int get_liczba_bledow();

    void wyswietl_stan(int number_rundy, bool wyswietl_ilosc_bledow = true);

    void sczytaj_pytanie(std::vector<TPytanie>& baza);
    TPytanie losuj_pytanie(std::vector<TPytanie>& baza);
    void ustaw_pytanie(TPytanie p);

    int wartosc_odpowiedzi(std::string odp);

    static std::string normalizuj(std::string tekst);

    void wyswietl_stan_final(std::vector<std::string> odp_gracza1,
        std::vector<std::string> odp_gracza2, std::vector<std::vector<TOdpowiedz>> popr_odp_final,
        std::vector<int> pkt);
};
