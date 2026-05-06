#include "TDruzyna.h"
#include <string>

TDruzyna::TDruzyna(std::string nazwa) : nazwa(nazwa) {}

void TDruzyna::dodaj_punkty(int p)
{
	punkty += p;
}
int TDruzyna::get_punkty()
{
	return punkty;
}
std::string TDruzyna::get_nazwa()
{
	return nazwa;
}