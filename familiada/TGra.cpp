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

    // TEST FINAŁU:
    //start_final(&druzyna1);
    //return;

    TDruzyna* aktualna_druzyna = &druzyna1;
    TDruzyna* przeciwna_druzyna = &druzyna2;

    cout << "Witamy w familiadzie!" << endl;
    cout << "Pierwsza drużyna, która zdobędzie 200 punktów, przechodzi do finału." << endl;
    PlaySound(TEXT("przerywnik.wav"),
        NULL,
        SND_SYNC);
    system("cls");

    // przed finalem
    for (int nr = 1; nr <= 10; nr++)
    {
        cout << endl;
        system("cls");

        TPytanie p = runda.losuj_pytanie(baza);
        runda.ustaw_pytanie(p);

        // kod pojedynku
        pojedynek(aktualna_druzyna, przeciwna_druzyna, nr);
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

                if(runda.czy_koniec())
                    aktualna_druzyna->dodaj_punkty(runda.get_suma_punktow());
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
                        runda.wyswietl_stan(nr);
                        przeciwna_druzyna->dodaj_punkty(
                            runda.get_suma_punktow()
                        );

                        cout << "\nKRADZIEZ UDANA!" << endl;
                        PlaySound(TEXT("poprawna_odp.wav"), NULL, SND_SYNC);
                    }
                    else
                    {
                        runda.wyswietl_stan(nr);
                        aktualna_druzyna->dodaj_punkty(
                            runda.get_suma_punktow()
                        );

                        cout << "\nKRADZIEZ NIEUDANA!" << endl;
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

        if ((druzyna1.get_punkty() >= 200) && (druzyna1.get_punkty() >= druzyna2.get_punkty()))
        {
            start_final(&druzyna1);
            cout << endl;
            cout << "=== KONIEC GRY ===" << endl;
            PlaySound(TEXT("przed_finalem.wav"), NULL, SND_SYNC);
            return;
        }
        else if ((druzyna2.get_punkty() >= 200) && (druzyna1.get_punkty() <= druzyna2.get_punkty()))
        {
            start_final(&druzyna2);
            cout << endl;
            cout << "=== KONIEC GRY ===" << endl;
            PlaySound(TEXT("przed_finalem.wav"), NULL, SND_SYNC);
            return;
        }
    }

}

void TGra::pojedynek(TDruzyna*& aktualna_druzyna, TDruzyna*& przeciwna_druzyna, int nr) // nr jest numerem rundy
{
    while (true)
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
            PlaySound(TEXT("poprawna_odp.wav"), NULL, SND_SYNC);
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
}

void TGra::start_final(TDruzyna* druzyna)
{
    vector<TOdpowiedz> popr_odp{}; // poprawne odpowiedzi na jedno pytanie w finale
    vector<vector<TOdpowiedz>> popr_odp_final{}; // zbiór wszystkich poprawnych odpowiedzi w finale
    bool odsloniete_odp[5][5] = {}; // domyślnie ustawia wszystko na false
    vector<string> odp_gracza1{};
    vector<string> odp_gracza2{};
    vector<TPytanie> pytania_final{};
    vector<int> pkt_do_wyswietlenia = {};
    int wynik = 0;

    cout << druzyna->get_nazwa() << " przechodzą do finału!\n";
    cout << "Aby wygrać, obaj gracze muszą zdobyć łącznie 150 punktów.\n";

    cout << "Pierwsza tura finału... ";
    PlaySound(TEXT("przed_finalem"), NULL, SND_SYNC);

    for (int i = 0; i < 5; i++)
    {
        TPytanie p = runda.losuj_pytanie(baza);
        // wczytanie pytania
        pytania_final.push_back(p);
        runda.ustaw_pytanie(p); // to ma być tylko raz bo resetuje odkryte

        string odp;
        runda.wyswietl_stan_final(odp_gracza1, odp_gracza2, popr_odp_final, pkt_do_wyswietlenia);
        getline(cin, odp);

        // wczytanie odpowiedzi gracza 1
        odp_gracza1.push_back(odp);
        // wczytanie poprawnych odpowiedzi na pytanie
        popr_odp = p.get_odpowiedzi();
        // wczytanie wszystkich poprawnych odpowiedzi
        popr_odp_final.push_back(popr_odp);
    }

    for (int i = 0; i < 5; i++)
    {
        runda.ustaw_pytanie(pytania_final[i]);
        int liczba = runda.zgadnij(odp_gracza1[i], false);
        odsloniete_odp[i][liczba] = true;
        switch (liczba)
        {
        case -1:
            pkt_do_wyswietlenia.push_back(0);
            break;
        default:
            pkt_do_wyswietlenia.push_back(popr_odp_final[i][liczba].punkty);
            break;
        }
        runda.wyswietl_stan_final(odp_gracza1, odp_gracza2, popr_odp_final, pkt_do_wyswietlenia);
        PlaySound(TEXT("odsloniecie.wav"), NULL, SND_SYNC);
    }

    for (int i = 0; i < pkt_do_wyswietlenia.size(); i++)
    {
        wynik += pkt_do_wyswietlenia[i];
    }
    cout << "\nWynik: " << wynik << endl;

    // 2 tura finału
    cout << "\nDruga tura finału... ";
    PlaySound(TEXT("przerywnik"), NULL, SND_SYNC);

    for (int i = 5; i < 10; i++)
    {
        TPytanie p = pytania_final[i - 5];
        // wczytanie pytania
        runda.ustaw_pytanie(p); // to ma być tylko raz bo resetuje odkryte

        string odp;
        int j = 0;
        int liczba;
        do // pobieranie odpowiedzi
        {
            runda.wyswietl_stan_final(odp_gracza1, odp_gracza2, popr_odp_final, pkt_do_wyswietlenia);
            if (j > 0)
                PlaySound(TEXT("powtorzenie_final.wav"), NULL, SND_SYNC);
            getline(cin, odp);
            j++;
            liczba = runda.zgadnij(odp, false);
            if (liczba == -1)
                break;
        } while (odsloniete_odp[i-5][liczba] == true);

        // wczytanie odpowiedzi gracza 2
        odp_gracza2.push_back(odp);
        // wczytanie poprawnych odpowiedzi na pytanie
        //popr_odp = p.get_odpowiedzi();
        // wczytanie wszystkich poprawnych odpowiedzi
        //popr_odp_final.push_back(popr_odp);
    }

    for (int i = 5; i < 10; i++)
    {
        runda.ustaw_pytanie(pytania_final[i-5]);
        int liczba = runda.zgadnij(odp_gracza2[i-5], false);
        // odsloniete_odp[i][liczba] = true;
        switch (liczba)
        {
        case -1:
            pkt_do_wyswietlenia.push_back(0);
            break;
        default:
            pkt_do_wyswietlenia.push_back(popr_odp_final[i-5][liczba].punkty);
            break;
        }
        runda.wyswietl_stan_final(odp_gracza1, odp_gracza2, popr_odp_final, pkt_do_wyswietlenia);
        PlaySound(TEXT("odsloniecie.wav"), NULL, SND_SYNC);
    }
    

    for (int i = 5; i < pkt_do_wyswietlenia.size(); i++)
    {
        wynik += pkt_do_wyswietlenia[i];
    }
    cout << "\nWynik: " << wynik << endl;

    if (wynik >= 200)
        cout << druzyna->get_nazwa() << " wygrywają finał!\n";
    else
        cout << druzyna->get_nazwa() << " przegrywają finał!\n";

    PlaySound(TEXT("przerywnik.wav"), NULL, SND_SYNC);



    /*

    for (int i = 0; i < 5; i++)
    {
        cout << popr_odp_final[0][i].tekst << '\n';
    }
    for (int i = 0; i < 5; i++)
    {
        cout << pytania_final[i].get_tresc() << '\n';
    }
    for (int i = 0; i < 5; i++)
    {
        cout << odsloniete_odp[0][i] << '\n';
    }
    */
}