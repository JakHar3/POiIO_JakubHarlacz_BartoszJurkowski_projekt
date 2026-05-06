#include "TPytanie.h"
#include <iostream>

TPytanie::TPytanie(std::string tresc,
    std::vector<std::string> odpowiedzi,
    std::vector<int> punkty)
    : tresc(tresc), odpowiedzi(odpowiedzi), punkty(punkty) {
}

void TPytanie::wyswietl() {
    std::cout << tresc << std::endl;
    for (size_t i = 0; i < odpowiedzi.size(); i++) {
        std::cout << i + 1 << ". " << odpowiedzi[i]
            << " (" << punkty[i] << " pkt)" << std::endl;
    }
}

std::string TPytanie::get_tresc() {
    return tresc;
}

std::vector<std::string> TPytanie::get_odpowiedzi() {
    return odpowiedzi;
}

std::vector<int> TPytanie::get_punkty() {
    return punkty;
}