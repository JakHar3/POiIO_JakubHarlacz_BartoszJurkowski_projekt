#include "TRunda.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TPytanie.h"

using namespace std;

TRunda::TRunda()
{
    liczba_bledow = 0;
    punkty_rundy = 0;
}

int TRunda::zgadnij(string odp_gracza, bool licz_bledy)
{
    vector<TOdpowiedz> odp = pytanie.get_odpowiedzi();

    for (int i = 0; i < odp.size(); i++)
    {
        if (odp[i].tekst == odp_gracza && !odkryte[i])
        {
            odkryte[i] = true;

            punkty_rundy += odp[i].punkty;

            system("cls");

            return i;
        }
    }

    if (licz_bledy)
        liczba_bledow++;


    return -1;
}
bool TRunda::czy_koniec()
{
    if (liczba_bledow >= 3)
    {
        return true;
    }

    for (bool x : odkryte)
    {
        if (!x)
        {
            return false;
        }
    }

    return true;
}
int TRunda::get_suma_punktow()
{
    return punkty_rundy;
}

int TRunda::get_liczba_bledow()
{
    return liczba_bledow;
}

//void TRunda::wyswietl_stan();
void TRunda::sczytaj_pytanie(vector<TPytanie>& baza) {
    //Powyższa linijka pozwala na zapisanie pytań
    //Otwieramy plik
    ifstream plik("baza_pytan.txt");
    string linia;
    if (!plik.is_open())
    {
        cout << "Nie znaleziono pliku baza_pytan.txt!\n" << endl;
        return;
    }
    TPytanie aktualne;
    bool czyNowePytanie = true;

    while (getline(plik, linia))
    {
        if (linia == "---" || linia.empty()) //ignorujemy separatory i puste linie
        {
            if (!aktualne.get_tresc().empty())
            {
                baza.push_back(aktualne);
                aktualne = TPytanie(); // czyścimy miejsce na nowe pytanie
            }
            czyNowePytanie = true;
            continue;
        }
        size_t pozycjaDwukropka = linia.find(":");
        if (pozycjaDwukropka != string::npos) //jeśli znaleziono dwukropek to odp
        {
            TOdpowiedz o;
            o.tekst = linia.substr(0, pozycjaDwukropka);
            o.punkty = stoi(linia.substr(pozycjaDwukropka + 1)); //stoi zamienia wycięty tekst na prawdziwą liczbę int
            aktualne.dodaj_odpowiedz(o);
        }
        else
        {
            if (czyNowePytanie) //logika jeśli nie ma dwukropka w linii
            {
                aktualne.set_tresc(linia);
                czyNowePytanie = false;
            }
        }
    }
    if (!aktualne.get_tresc().empty())
    {
        baza.push_back(aktualne);
    }
    plik.close();
}
TPytanie TRunda::losuj_pytanie(vector<TPytanie>& baza) 
{
    int losowy_idx = rand() % baza.size();
    return baza[losowy_idx];
    if (baza.empty()) 
    {
        return TPytanie();
    }
    
};

void TRunda::ustaw_pytanie(TPytanie p)
{
    pytanie = p;

    odkryte.clear();

    for (int i = 0; i < pytanie.get_odpowiedzi().size(); i++)
    {
        odkryte.push_back(false);
    }

    liczba_bledow = 0;
    punkty_rundy = 0;
}

void TRunda::wyswietl_stan(int numer_rundy, bool wyswietl_ilosc_bledow)
{
    system("cls");
    cout << endl;
    cout << "=== RUNDA " << numer_rundy << " ===" << endl;
    cout << pytanie.get_tresc() << endl;
    cout << endl;

    vector<TOdpowiedz> odp = pytanie.get_odpowiedzi();

    for (int i = 0; i < odp.size(); i++)
    {
        if (odkryte[i])
        {
            cout << i + 1 << ". "
                << odp[i].tekst
                << " - "
                << odp[i].punkty
                << " pkt" << endl;
        }
        else
        {
            cout << i + 1 << ". ??????" << endl;
        }
    }
    if (wyswietl_ilosc_bledow) // dla pojedynku nie wyświetlamy błędów
    {
        cout << endl;
        cout << "Bledy: ";

        for (int i = 0; i < liczba_bledow; i++)
        {
            cout << "X ";
        }
    }
    else
    {
        cout << endl;
        cout << "Kto pierwszy ten lepszy (c/n): ";
    }

    cout << endl;
}

int TRunda::wartosc_odpowiedzi(string odp)
{
    vector<TOdpowiedz> odp_tab = pytanie.get_odpowiedzi();

    for (int i = 0; i < odp_tab.size(); i++)
    {
        if (odp_tab[i].tekst == odp)
        {
            return odp_tab[i].punkty;
        }
    }

    return 0;
}
