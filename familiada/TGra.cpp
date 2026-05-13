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

    TDruzyna* aktualna_druzyna;
    TDruzyna* przeciwna_druzyna;

    for (int nr = 1; nr <= 4; nr++)
    {
        cout << endl;
        cout << "=== RUNDA " << nr << " ===" << endl;

        if (nr % 2 == 1)
        {
            aktualna_druzyna = &druzyna1;
            przeciwna_druzyna = &druzyna2;
        }
        else
        {
            aktualna_druzyna = &druzyna2;
            przeciwna_druzyna = &druzyna1;
        }

        TPytanie p = runda.losuj_pytanie(baza);
        runda.ustaw_pytanie(p);

        while (!runda.czy_koniec())
        {
            runda.wyswietl_stan();

            cout << endl;
            cout << "Tura druzyny: " << aktualna_druzyna->get_nazwa() << endl;

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


                if (runda.get_liczba_bledow() >= 3)
                {
                    runda.wyswietl_stan();

                    cout << endl;
                    cout << "SZANSA KRADZIEZY dla "
                        << przeciwna_druzyna->get_nazwa()
                        << endl;

                    string kradziez;

                    getline(cin, kradziez);

                    if (runda.zgadnij(kradziez))
                    {
                        przeciwna_druzyna->dodaj_punkty(
                            runda.get_suma_punktow()
                        );

                        cout << "KRADZIEZ UDANA!" << endl;
                    }
                    else
                    {
                        aktualna_druzyna->dodaj_punkty(
                            runda.get_suma_punktow()
                        );

                        cout << "KRADZIEZ NIEUDANA!" << endl;
                    }
                }
            }
        }

        cout << endl;
        cout << "Koniec rundy!" << endl;
        cout << endl;

        cout << druzyna1.get_nazwa()
            << ": "
            << druzyna1.get_punkty()
            << " pkt" << endl;

        cout << druzyna2.get_nazwa()
            << ": "
            << druzyna2.get_punkty()
            << " pkt" << endl;
    }

    cout << endl;
    cout << "=== KONIEC GRY ===" << endl;

}