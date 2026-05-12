#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "TPytanie.h"
#include "TRunda.h"
#include <Windows.h>


using namespace std;

int main()
{
    /*std::cout << "Hello World!\n";

    std::vector<std::string> odp = { "Warszawa", "Krakow", "Gniezno" };
    std::vector<int> pkt = { 10, 5, 1 };
    TPytanie pytanie("Jaka jest stolica Polski?", odp, pkt);

    pytanie.wyswietl(); */
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);  //ustawia język pol, plik txt jest UTF8
    srand(time(0)); //losowanie innego pytania
    vector<Pytanie> baza;
    sczytaj_pytanie(baza);
    
    if (!baza.empty())
    {
        Pytanie aktualne = losuj_pytanie(baza);
        wyswietl_pytanie(aktualne);
    }




}

