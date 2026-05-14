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

    TDruzyna* aktualna_druzyna = &druzyna1;
    TDruzyna* przeciwna_druzyna = &druzyna2;

    cout << "Witamy w familiadzie!" << endl;
    PlaySound(TEXT("przerywnik.wav"),
        NULL,
        SND_SYNC);
    system("cls");

    for (int nr = 1; nr <= 4; nr++)
    {
        cout << endl;
        system("cls");

        TPytanie p = runda.losuj_pytanie(baza);
        runda.ustaw_pytanie(p);

        // kod pojedynku
        while(true)
        {
            string odpowiadajacy;
            system("cls");

            while (odpowiadajacy != "c" && odpowiadajacy != "n")
            {
                runda.wyswietl_stan(nr, false);
                getline(cin, odpowiadajacy);
                if (odpowiadajacy == "c") // czerwoni
                {
                    aktualna_druzyna = &druzyna1;
                    przeciwna_druzyna = &druzyna2;
                }

                else if (odpowiadajacy == "n") // niebiescy
                {
                    aktualna_druzyna = &druzyna2;
                    przeciwna_druzyna = &druzyna1;
                }
            }

            cout << "Tura druzyny: " << aktualna_druzyna->get_nazwa() << endl;

            string odp_pojedynek;
            int punkty_pojedynku_1 = 0;
            int punkty_pojedynku_2 = 0;

            cout << "Podaj odpowiedz: ";
            getline(cin, odp_pojedynek);

            /*
            if (runda.zgadnij(odp_pojedynek, false) != -1)
            {
                runda.wyswietl_stan(nr, false);
                punkty_pojedynku_1 = runda.wartosc_odpowiedzi(odp_pojedynek);
            }
            */
            bool czy_najlepsza_odp = false;
            switch (runda.zgadnij(odp_pojedynek, false))
            {
                case -1:
                    PlaySound(TEXT("bledna_odp.wav"), NULL, SND_SYNC);
                    break;
                case 0:
                    czy_najlepsza_odp = true;
                    runda.wyswietl_stan(nr, false);
                    punkty_pojedynku_1 = runda.wartosc_odpowiedzi(odp_pojedynek);

                    PlaySound(TEXT("poprawna_odp.wav"), NULL, SND_SYNC);
                    cout << aktualna_druzyna->get_nazwa() << " rozpoczynają rundę!" << endl;
                    PlaySound(TEXT("nowa_runda.wav"),
                        NULL,
                        SND_SYNC);
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                    runda.wyswietl_stan(nr, false);
                    punkty_pojedynku_1 = runda.wartosc_odpowiedzi(odp_pojedynek);
                    PlaySound(TEXT("poprawna_odp.wav"),NULL,SND_SYNC);
                    break;
                default:

                    break;

            }

            if (czy_najlepsza_odp)
                break;

            cout << "Tura druzyny: " << przeciwna_druzyna->get_nazwa() << endl;
            cout << "Podaj odpowiedz: ";
            getline(cin, odp_pojedynek);

            if (runda.zgadnij(odp_pojedynek, false) != -1)
            {
                runda.wyswietl_stan(nr, false);
                PlaySound(TEXT("poprawna_odp.wav"), NULL, SND_SYNC);
                punkty_pojedynku_2 = runda.wartosc_odpowiedzi(odp_pojedynek);
            }
            else PlaySound(TEXT("bledna_odp.wav"), NULL, SND_SYNC);

            if (punkty_pojedynku_1 > punkty_pojedynku_2)
            {
                cout << aktualna_druzyna->get_nazwa() << " rozpoczynają rundę!" << endl;
                PlaySound(TEXT("nowa_runda.wav"),
                    NULL,
                    SND_SYNC);
                break;
            }
            else if (punkty_pojedynku_2 > punkty_pojedynku_1)
            {
                cout << przeciwna_druzyna->get_nazwa() << " rozpoczynają rundę!" << endl;
                TDruzyna* temp = aktualna_druzyna;
                aktualna_druzyna = przeciwna_druzyna;
                przeciwna_druzyna = temp;
                PlaySound(TEXT("nowa_runda.wav"),
                    NULL,
                    SND_SYNC);
                break;
            }
        }
        // koniec pojedynku

        while (!runda.czy_koniec())
        {
            system("cls");
            runda.wyswietl_stan(nr);

            cout << endl;
            cout << "Tura druzyny: " << aktualna_druzyna->get_nazwa() << endl;

            string odp;

            cout << "Podaj odpowiedz: ";
            getline(cin, odp);

            if (runda.zgadnij(odp) != -1)
            {
                runda.wyswietl_stan(nr);
                cout << "\nDobra odpowiedz!" << endl;
                PlaySound(TEXT("poprawna_odp.wav"), NULL, SND_SYNC);
            }
            else
            {
                runda.wyswietl_stan(nr);
                cout << "\nZla odpowiedz!" << endl;
                PlaySound(TEXT("bledna_odp.wav"), NULL, SND_SYNC);


                if (runda.get_liczba_bledow() >= 3)
                {
                    runda.wyswietl_stan(nr);

                    cout << endl;
                    cout << "SZANSA KRADZIEZY dla "
                        << przeciwna_druzyna->get_nazwa()
                        << endl;

                    string kradziez;

                    getline(cin, kradziez);

                    if (runda.zgadnij(kradziez) != -1)
                    {
                        przeciwna_druzyna->dodaj_punkty(
                            runda.get_suma_punktow()
                        );

                        cout << "KRADZIEZ UDANA!" << endl;
                        PlaySound(TEXT("poprawna_odp.wav"), NULL, SND_SYNC);
                    }
                    else
                    {
                        aktualna_druzyna->dodaj_punkty(
                            runda.get_suma_punktow()
                        );

                        cout << "KRADZIEZ NIEUDANA!" << endl;
                        PlaySound(TEXT("bledna_odp.wav"), NULL, SND_SYNC);
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

        PlaySound(TEXT("nowa_runda.wav"),NULL,SND_SYNC);
    }

    cout << endl;
    cout << "=== KONIEC GRY ===" << endl;
    PlaySound(TEXT("przed_finalem.wav"), NULL, SND_SYNC);

}
