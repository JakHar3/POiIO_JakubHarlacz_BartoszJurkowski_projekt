#include <iostream>
#include "TPytanie.h"

int main()
{
    std::cout << "Hello World!\n";

    std::vector<std::string> odp = { "Warszawa", "Kraków", "Gniezno" };
    std::vector<int> pkt = { 10, 5, 1 };
    TPytanie pytanie("Jaka jest stolica Polski?", odp, pkt);

    pytanie.wyswietl();


}

