#pragma once
#include <string>
#include <vector>

using namespace std;

class TPytanie {
private:
	std::string tresc;
	std::vector<std::string> odpowiedzi;
	std::vector<int> punkty;


public:
	TPytanie(std::string tresc, std::vector<std::string> odpowiedzi,
		std::vector<int> punkty);

	void wyswietl();

	std::string get_tresc();
	std::vector<std::string> get_odpowiedzi();
	std::vector<int> get_punkty();
};