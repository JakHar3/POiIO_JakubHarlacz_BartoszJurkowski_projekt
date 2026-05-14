#pragma once
#include <vector>
#include "TDruzyna.h"
#include "TPytanie.h"
#include "TRunda.h"

#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

class TGra {
private:
    vector<TPytanie> baza;

    TDruzyna druzyna1;
    TDruzyna druzyna2;

    TRunda runda;

public:
    TGra();

    void start();

private:
    // pomocnicze:
};