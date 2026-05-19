#pragma once
#include <string>
#include <vector>

//using namespace std;

struct TOdpowiedz
{
	std::string tekst;
	int punkty;
};

class TPytanie {
private:
	std::string tresc;
	std::vector<TOdpowiedz> odpowiedzi;


public:
	TPytanie(std::string tresc, std::vector<TOdpowiedz> odpowiedzi);
	TPytanie();

	void wyswietl();

	std::string get_tresc();
	void set_tresc(std::string t);
	void dodaj_odpowiedz(TOdpowiedz o);

	std::vector<TOdpowiedz> get_odpowiedzi();
};