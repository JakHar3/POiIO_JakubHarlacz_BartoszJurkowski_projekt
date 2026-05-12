#include "TGra.h"
#include <iostream>

using namespace std;

TGra::TGra()
    : druzyna1("Czerwoni"),
    druzyna2("Niebiescy")
{
}

void TGra::start()
{
    runda.sczytaj_pytanie(baza);

    for (int nr = 1; nr <= 5; nr++)
    {
        cout << endl;
        cout << "=== RUNDA " << nr << " ===" << endl;

        TPytanie p = runda.losuj_pytanie(baza);

        runda.ustaw_pytanie(p);

        while (!runda.czy_koniec())
        {
            runda.wyswietl_stan();

            string odp;

            cout << "Podaj odpowiedz: ";
            getline(cin, odp);

            if (runda.zgadnij(odp))
            {
                cout << "Dobra odpowiedz!" << endl;
            }
            else
            {
                cout << "Zla odpowiedz!" << endl;
            }
        }

        int pkt = runda.get_suma_punktow();

        druzyna1.dodaj_punkty(pkt);

        cout << endl;
        cout << "Koniec rundy!" << endl;
        cout << "Zdobyte punkty: " << pkt << endl;
    }

    cout << endl;
    cout << "=== KONIEC GRY ===" << endl;

    cout << druzyna1.get_nazwa()
        << ": "
        << druzyna1.get_punkty()
        << " pkt" << endl;

}