#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TPytanie.h"

using namespace std;

// te 2 struktury do wywalenia
struct Odpowiedz
{
    string tekst;
    int punkty;
};
struct Pytanie
{
    string tresc;
    vector<Odpowiedz> odpowiedzi;
};

class TRunda {
private:
    TPytanie pytanie;
    vector<bool> odkryte;

    int liczba_bledow;
    int punkty_rundy;
    

public:
    TRunda();

    bool zgadnij(string odp_gracza);
    bool czy_koniec();

    int get_suma_punktow();
    int get_liczba_bledow();

    void wyswietl_stan();

    void sczytaj_pytanie(vector<TPytanie>& baza);
    TPytanie losuj_pytanie(vector<TPytanie>& baza);
    void wyswietl_pytanie(Pytanie& p);

    void ustaw_pytanie(TPytanie p);
};
