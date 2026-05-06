#pragma once
#include <vector>
#include "TDruzyna.h"
#include "TPytanie.h"
#include "TRunda.h"

class TGra {
private:
    std::vector<TDruzyna> druzyny;
    std::vector<TPytanie> pytania;

    int aktualne_pytanie = 0;

public:
    TGra(std::vector<TPytanie> pytania, std::vector<TDruzyna> druzyny);

    void start();

private:
    void nastepna_runda();
};