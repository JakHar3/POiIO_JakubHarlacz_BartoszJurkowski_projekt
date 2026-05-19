#include "TPytanie.h"
#include <iostream>

using namespace std;

TPytanie::TPytanie(string tresc,vector<TOdpowiedz> odpowiedzi)
{
    this->tresc = tresc;
    this->odpowiedzi = odpowiedzi;
}

TPytanie::TPytanie()
{
}

void TPytanie::wyswietl() {
    std::cout << tresc << std::endl;
}

string TPytanie::get_tresc() {
    return tresc;
}

void TPytanie::set_tresc(string t) {
    tresc = t;
}

void TPytanie::dodaj_odpowiedz(TOdpowiedz o)
{
    odpowiedzi.push_back(o);
}

std::vector<TOdpowiedz> TPytanie::get_odpowiedzi() {
    return odpowiedzi;
}