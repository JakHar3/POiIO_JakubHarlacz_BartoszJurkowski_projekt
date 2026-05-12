#include "TRunda.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TPytanie.h"

using namespace std;
//TRunda::TRunda(TPytanie& p)

//bool TRunda::zgadnij(std::string& odp);
//bool TRunda::czy_koniec();
//int TRunda::suma_punktow();

//void TRunda::wyswietl_stan();
void sczytaj_pytanie(vector<Pytanie>& baza) {
    //Powyższa linijka pozwala na zapisanie pytań
    //Otwieramy plik
    ifstream plik("baza_pytan.txt");
    string linia;
    if (!plik.is_open())
    {
        cout << "Nie znaleziono pliku baza_pytan.txt!\n" << endl;
        return;
    }
    Pytanie aktualne;
    bool czyNowePytanie = true;

    while (getline(plik, linia))
    {
        if (linia == "---" || linia.empty()) //ignorujemy separatory i puste linie
        {
            if (!aktualne.tresc.empty())
            {
                baza.push_back(aktualne);
                aktualne = Pytanie(); // czyścimy miejsce na nowe pytanie
            }
            czyNowePytanie = true;
            continue;
        }
        size_t pozycjaDwukropka = linia.find(":");
        if (pozycjaDwukropka != string::npos) //jeśli znaleziono dwukropek to odp
        {
            Odpowiedz o;
            o.tekst = linia.substr(0, pozycjaDwukropka);
            o.punkty = stoi(linia.substr(pozycjaDwukropka + 1)); //stoi zamienia wycięty tekst na prawdziwą liczbę int
            aktualne.odpowiedzi.push_back(o);
        }
        else
        {
            if (czyNowePytanie) //logika jeśli nie ma dwukropka w linii
            {
                aktualne.tresc = linia;
                czyNowePytanie = false;
            }
        }
    }
    if (!aktualne.tresc.empty())
    {
        baza.push_back(aktualne);
    }
    plik.close();
}
Pytanie losuj_pytanie(vector<Pytanie>& baza) 
{
    int losowy_idx = rand() % baza.size();
    return baza[losowy_idx];
    if (baza.empty()) 
    {
        return Pytanie();
    }
    
};
void wyswietl_pytanie(Pytanie& p)
{
    cout << "\n===================" << endl;
    cout << "       Pytanie     " << endl;
    cout << "===================" << endl;
    cout << "\n" << p.tresc << "\n" << endl;
    cout << "Na tablicy jest " << p.odpowiedzi.size() << " odpowiedzi." << endl;
    cout << "===================" << endl;
}