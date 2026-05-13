#pragma once
#include <string>
#include <vector>

using namespace std;

struct TOdpowiedz
{
	string tekst;
	int punkty;
};

class TPytanie {
private:
	string tresc;
	vector<TOdpowiedz> odpowiedzi;


public:
	TPytanie(string tresc, vector<TOdpowiedz> odpowiedzi);
	TPytanie();

	void wyswietl();

	string get_tresc();
	void set_tresc(string t);
	void dodaj_odpowiedz(TOdpowiedz o);

	std::vector<TOdpowiedz> get_odpowiedzi();
};