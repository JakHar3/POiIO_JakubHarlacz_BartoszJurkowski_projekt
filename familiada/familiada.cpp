#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "TPytanie.h"
#include "TRunda.h"
#include <Windows.h>
#include "TGra.h"

// do wczytywania plików dźwiękowych
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);  //ustawia język pol, plik txt jest UTF8
    srand(time(0)); //losowanie innego pytania

    /*
    vector<Pytanie> baza;
    TRunda runda1;
    runda1.sczytaj_pytanie(baza);
    
    if (!baza.empty())
    {
        Pytanie aktualne = runda1.losuj_pytanie(baza);
        runda1.wyswietl_pytanie(aktualne);
    }
    */

    TGra gra;
    gra.start();

}

