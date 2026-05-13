#pragma once
#include <vector>
#include "TDruzyna.h"
#include "TPytanie.h"
#include "TRunda.h"

class TGra {
private:
    vector<TPytanie> baza;

    TDruzyna druzyna1;
    TDruzyna druzyna2;

    TRunda runda;

public:
    TGra();

    void start();
};