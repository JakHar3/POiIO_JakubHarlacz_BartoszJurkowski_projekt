#pragma once
#include <string>

class TDruzyna {
private:
    std::string nazwa;
    int punkty = 0;

public:
    TDruzyna(std::string nazwa);

    void dodaj_punkty(int p);
    int get_punkty();
    std::string get_nazwa();
};