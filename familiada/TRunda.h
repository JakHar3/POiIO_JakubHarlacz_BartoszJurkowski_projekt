#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TPytanie.h"

using namespace std;

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
    std::vector<bool> odkryte;
    int liczba_bledow = 0;

    

public:
   TRunda(Pytanie& p);

    bool zgadnij(std::string& odp);
    bool czy_koniec();
    int suma_punktow();

    

    void wyswietl_stan();
};

void sczytaj_pytanie(vector<Pytanie>& baza);
Pytanie losuj_pytanie(vector<Pytanie>& baza);
void wyswietl_pytanie(Pytanie& p);