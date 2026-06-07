#pragma once
#include <string>
#include <vector>
#include "TGra.h"
#include "TRunda.h"
#include "TPytanie.h"
#include "TDruzyna.h"
#include "windows.h"
#include <mmsystem.h>
#include <ctime>
#pragma comment(lib, "winmm.lib")


namespace familiada {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			//usuwamy obiekty z pamieci przy zamknieciu okna
			if (baza_pytan) delete baza_pytan;
			if (runda_aktualna) delete runda_aktualna;
			if (pytanie_aktualne) delete pytanie_aktualne;
			if (odpowiedzi_gracz1) delete odpowiedzi_gracz1;
			if (odpowiedzi_gracz2) delete odpowiedzi_gracz2;
			if (punkty_finalowe) delete punkty_finalowe;
			if (pytania_finalu) delete pytania_finalu;

			if (components)
			{
				delete components;
			}
		}
	private:
		std::vector<TPytanie>* baza_pytan;
		TRunda* runda_aktualna;
		TPytanie* pytanie_aktualne;
		int punkty_czerwoni;
		int punkty_niebiescy;
		int numer_rundy;
		bool tura_czerownych; // true = czerowni, false = niebiescy
		// Do wielkiego fina³u zmienne:
		bool czy_tryb_finalowy;
		int aktualny_gracz_finalu;
		int numer_pytania_finalu;

		std::vector<std::string>* odpowiedzi_gracz1;
		std::vector<std::string>* odpowiedzi_gracz2;
		std::vector<int> * punkty_finalowe;
		std::vector<TPytanie>* punkty_finalu;

	private: System::String^ stdToSystemStr(std::string stdStr)
	{
		// wyœwietlanie polskich znaków UTF-8
		return gcnew System::String(stdStr.c_str(),0,stdStr.length(),System::Text::Encoding::UTF8);
	}
	private: System::Windows::Forms::Label^ labelPytanie;
	private: System::Windows::Forms::Label^ labelOdp1;
	private: System::Windows::Forms::Label^ labelOdp2;
	private: System::Windows::Forms::Label^ labelOdp3;
	private: System::Windows::Forms::Label^ labelOdp4;
	private: System::Windows::Forms::Label^ labelOdp5;
	private: System::Windows::Forms::Label^ labelPunktyDruzyna1;
	private: System::Windows::Forms::Label^ labelPunktyDruzyna2;
	private: System::Windows::Forms::TextBox^ textBoxOdpowiedz;
	private: System::Windows::Forms::Button^ buttonZatwierdz;
	private: System::Windows::Forms::Label^ labelBledy;





	protected:

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelPytanie = (gcnew System::Windows::Forms::Label());
			this->labelOdp1 = (gcnew System::Windows::Forms::Label());
			this->labelOdp2 = (gcnew System::Windows::Forms::Label());
			this->labelOdp3 = (gcnew System::Windows::Forms::Label());
			this->labelOdp4 = (gcnew System::Windows::Forms::Label());
			this->labelOdp5 = (gcnew System::Windows::Forms::Label());
			this->labelPunktyDruzyna1 = (gcnew System::Windows::Forms::Label());
			this->labelPunktyDruzyna2 = (gcnew System::Windows::Forms::Label());
			this->textBoxOdpowiedz = (gcnew System::Windows::Forms::TextBox());
			this->buttonZatwierdz = (gcnew System::Windows::Forms::Button());
			this->labelBledy = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelPytanie
			// 
			this->labelPytanie->AutoSize = true;
			this->labelPytanie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelPytanie->Location = System::Drawing::Point(123, 36);
			this->labelPytanie->Name = L"labelPytanie";
			this->labelPytanie->Size = System::Drawing::Size(389, 29);
			this->labelPytanie->TabIndex = 0;
			this->labelPytanie->Text = L"Tutaj pojawi siê pytanie z bazy...";
			this->labelPytanie->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// labelOdp1
			// 
			this->labelOdp1->AutoSize = true;
			this->labelOdp1->Location = System::Drawing::Point(321, 93);
			this->labelOdp1->Name = L"labelOdp1";
			this->labelOdp1->Size = System::Drawing::Size(93, 16);
			this->labelOdp1->TabIndex = 1;
			this->labelOdp1->Text = L"1.-------------------";
			// 
			// labelOdp2
			// 
			this->labelOdp2->AutoSize = true;
			this->labelOdp2->Location = System::Drawing::Point(321, 132);
			this->labelOdp2->Name = L"labelOdp2";
			this->labelOdp2->Size = System::Drawing::Size(93, 16);
			this->labelOdp2->TabIndex = 2;
			this->labelOdp2->Text = L"2.-------------------";
			this->labelOdp2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// labelOdp3
			// 
			this->labelOdp3->AutoSize = true;
			this->labelOdp3->Location = System::Drawing::Point(321, 170);
			this->labelOdp3->Name = L"labelOdp3";
			this->labelOdp3->Size = System::Drawing::Size(93, 16);
			this->labelOdp3->TabIndex = 3;
			this->labelOdp3->Text = L"3.-------------------";
			// 
			// labelOdp4
			// 
			this->labelOdp4->AutoSize = true;
			this->labelOdp4->Location = System::Drawing::Point(321, 215);
			this->labelOdp4->Name = L"labelOdp4";
			this->labelOdp4->Size = System::Drawing::Size(93, 16);
			this->labelOdp4->TabIndex = 4;
			this->labelOdp4->Text = L"4.-------------------";
			this->labelOdp4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// labelOdp5
			// 
			this->labelOdp5->AutoSize = true;
			this->labelOdp5->Location = System::Drawing::Point(321, 253);
			this->labelOdp5->Name = L"labelOdp5";
			this->labelOdp5->Size = System::Drawing::Size(93, 16);
			this->labelOdp5->TabIndex = 5;
			this->labelOdp5->Text = L"5.-------------------";
			this->labelOdp5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// labelPunktyDruzyna1
			// 
			this->labelPunktyDruzyna1->AutoSize = true;
			this->labelPunktyDruzyna1->Location = System::Drawing::Point(39, 141);
			this->labelPunktyDruzyna1->Name = L"labelPunktyDruzyna1";
			this->labelPunktyDruzyna1->Size = System::Drawing::Size(74, 16);
			this->labelPunktyDruzyna1->TabIndex = 6;
			this->labelPunktyDruzyna1->Text = L"Czerowni: 0";
			this->labelPunktyDruzyna1->Click += gcnew System::EventHandler(this, &MyForm::labelPunktyDruzyna1_Click);
			// 
			// labelPunktyDruzyna2
			// 
			this->labelPunktyDruzyna2->AutoSize = true;
			this->labelPunktyDruzyna2->Location = System::Drawing::Point(641, 122);
			this->labelPunktyDruzyna2->Name = L"labelPunktyDruzyna2";
			this->labelPunktyDruzyna2->Size = System::Drawing::Size(81, 16);
			this->labelPunktyDruzyna2->TabIndex = 7;
			this->labelPunktyDruzyna2->Text = L"Niebiescy: 0";
			// 
			// textBoxOdpowiedz
			// 
			this->textBoxOdpowiedz->Location = System::Drawing::Point(517, 212);
			this->textBoxOdpowiedz->Name = L"textBoxOdpowiedz";
			this->textBoxOdpowiedz->Size = System::Drawing::Size(147, 22);
			this->textBoxOdpowiedz->TabIndex = 8;
			// 
			// buttonZatwierdz
			// 
			this->buttonZatwierdz->Location = System::Drawing::Point(517, 253);
			this->buttonZatwierdz->Name = L"buttonZatwierdz";
			this->buttonZatwierdz->Size = System::Drawing::Size(147, 23);
			this->buttonZatwierdz->TabIndex = 9;
			this->buttonZatwierdz->Text = L"ZatwierdŸ odpowiedŸ";
			this->buttonZatwierdz->UseVisualStyleBackColor = true;
			this->buttonZatwierdz->Click += gcnew System::EventHandler(this, &MyForm::buttonZatwierdz_Click);
			// 
			// labelBledy
			// 
			this->labelBledy->AutoSize = true;
			this->labelBledy->ForeColor = System::Drawing::Color::Red;
			this->labelBledy->Location = System::Drawing::Point(54, 221);
			this->labelBledy->Name = L"labelBledy";
			this->labelBledy->Size = System::Drawing::Size(48, 16);
			this->labelBledy->TabIndex = 10;
			this->labelBledy->Text = L"B³êdy:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(755, 309);
			this->Controls->Add(this->labelBledy);
			this->Controls->Add(this->buttonZatwierdz);
			this->Controls->Add(this->textBoxOdpowiedz);
			this->Controls->Add(this->labelPunktyDruzyna2);
			this->Controls->Add(this->labelPunktyDruzyna1);
			this->Controls->Add(this->labelOdp5);
			this->Controls->Add(this->labelOdp4);
			this->Controls->Add(this->labelOdp3);
			this->Controls->Add(this->labelOdp2);
			this->Controls->Add(this->labelOdp1);
			this->Controls->Add(this->labelPytanie);
			this->Name = L"MyForm";
			this->Text = L"Familiada - gra";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void labelPunktyDruzyna1_Click(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void UruchomNowaRunde() {
		if (baza_pytan->empty()) return;
		
		delete runda_aktualna;
		runda_aktualna = new TRunda();
		*pytanie_aktualne = runda_aktualna->losuj_pytanie(*baza_pytan);
		runda_aktualna->ustaw_pytanie(*pytanie_aktualne);

		labelPytanie->Text = "Runda " + numer_rundy + ": " + stdToSystemStr(pytanie_aktualne->get_tresc());

		labelOdp1->Text = "1. -------------------";
		labelOdp2->Text = "2. -------------------";
		labelOdp3->Text = "3. -------------------";
		labelOdp4->Text = "4. -------------------";
		labelOdp5->Text = "5. -------------------";

		labelPunktyDruzyna1->Text = "Czerwoni: " + punkty_czerwoni;
		labelPunktyDruzyna2->Text = "Niebiescy: " + punkty_niebiescy;
		labelBledy->Text = "B³êdy w rundzie: 0";
		textBoxOdpowiedz->Text = "";
	}
private: System::Void UruchomWielkiFinal() {
	czy_tryb_finalowy = true;
	aktualny_gracz_finalu = 1;
	numer_pytania_finalu = 0;

	odpowiedzi_gracz1->clear();
	odpowiedzi_gracz2->clear();
	punkty_finalowe->clear();
	pytania_finalu->clear();

	std::vector<TPytanie> kopia_bazy = *baza_pytan;
	for (int i = 0;i < 5;i++) {
		if(!kopia_bazy.empty()) {
			TPytanie p = runda_aktualna->losuj_pytanie(kopia_bazy);
			pytania_finalu->push_back(p);

			for (auto it = kopia_bazy.begin(); it != kopia_bazy.end();++it) {
				kopia_bazy.erase(it);
				break;
			}
		}
	}
	MessageBox::Show("Rozpoczynamy WIELKI FINA£!\nZapraszamy Gracza 1!" "Fina³", MessageBoxButtons::OK, MessageBoxIcon::Information);

	labelOdp1->Text = "Pytanie 1: -------";
	labelOdp2->Text = "Pytanie 2: -------";
	labelOdp3->Text = "Pytanie 3: -------";
	labelOdp4->Text = "Pytanie 4: -------";
	labelOdp5->Text = "Pytanie 5: -------";

	labelPunktyDruzyna1->Text = "Suma punktów: 0";
	labelPunktyDruzyna2->Text = "";
	labelBledy->Text = "Gracz 1";

	labelPytanie->Text = "Fina³ - Pytanie 1/5: " + stdToSystemStr((*pytania_finalu)[0].get_tresc());
	textBoxOdpowiedz->Text = "";
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		//losowe pytanie
		srand(static_cast<unsigned int>(time(0)));
		
		// Tworzymy nowe obiekty w pamieci:
		baza_pytan = new std::vector<TPytanie>();
		runda_aktualna = new TRunda();
		pytanie_aktualne = new TPytanie();

		// Zerujemy stan pocz¹tkowy
		punkty_czerwoni = 0;
		punkty_niebiescy = 0;
		numer_rundy = 1;
		tura_czerownych = true; // zaczna czerowni

		// Inicjalizacja trybu finalowego
		czy_tryb_finalowy = false;
		aktualny_gracz_finalu = 1;
		numer_pytania_finalu = 0;
		odpowiedzi_gracz1 = new std::vector<std::string>();
		odpowiedzi_gracz2 = new std::vector<std::string>();
		punkty_finalowe = new std::vector<int>();
		pytanie_finalu = new std::vector<TPytanie>();
		// Szczytanie bazy pytan
		runda_aktualna->sczytaj_pytanie(*baza_pytan);
		if (!baza_pytan->empty()) {
			UruchomNowaRunde();
		}
		else {
			labelPytanie->Text = "B³¹d: Nie uda³o siê wczytaæ bazy pytañ!";
		}
	}
private: System::Void buttonZatwierdz_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ sysOdp = textBoxOdpowiedz->Text;

		//Konwersja System::String na std::string
		using namespace System::Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(sysOdp)).ToPointer();
		std::string odpGracza(chars);
		Marshal::FreeHGlobal(IntPtr((void*)chars));

		if (odpGracza.empty()) return;

		// LOGIKA WIELKIEGO FINA£U
		(czy_tryb_finalowy)
		{
			if (aktualny_gracz_finalu == 1) {
				odpowiedzi_gracz1->push_back(odpGracza);

				switch (numer_pytania_finalu) {
				case 0: labelOdp1->Text = "1. " + sysOdp; break;
				case 1: labelOdp2->Text = "2. " + sysOdp; break;
				case 2: labelOdp3->Text = "3. " + sysOdp; break;
				case 3: labelOdp4->Text = "4. " + sysOdp; break;
				case 4: labelOdp5->Text = "5. " + sysOdp; break;
				}
			}
			else {
				//gracz musi podac inna odp w finale niz 1 zaweodnik
				if (!odpowiedzi_gracz1->empty() && numer_pytania_finalu < odpowiedzi_gracz1->size()) {
					if (runda_aktualna->normalizuj(odpGracza) == runda_aktualna->normalizuj((*odpowiedzi_gracz1)[numer_pytania_finalu])) {
						PLaySound(TEXT("blad.wav"), NULL, SND_ASYNC);
						MessageBox::Show("Taka odpowiedŸ ju¿ pad³a! Podaj inn¹!", "Powtórka", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						textBoxOdpowiedz->Text = "";
						return;
					}
				}
				odpowiedzi_gracz2->push_back(odpGracza);
			}
				numer_pytania_finalu++;

				if(numer_pytania_finalu<5){
					labelPytanie->Text = "Fina³ - Pytanie " + (numer_pytania_finalu + 1) + "/5: " + stdToSystemStr((*pytania_finalu)[numer_pytania_finalu].get_tresc());
					textBoxOdpowiedz->Text = "";
			}
				else {
					if (aktualny_gracz_finalu == 1)
					{
						MessageBox::Show("Dziêkujemy Graczowi 1!\nCzas na Gracza 2. Gracz 2 nie wiedzi odpowiedzi poprzednika!", "Fina³", MessageBoxButtons::OK, MessageBoxIcon::Information);
						labelOdp1->Text = "Pytanie 1: -------";
						labelOdp2->Text = "Pytanie 2: -------";
						labelOdp3->Text = "Pytanie 3: -------";
						labelOdp4->Text = "Pytanie 4: -------";
						labelOdp5->Text = "Pytanie 5: -------";

						aktualny_gracz_finalu = 2;
						numer_pytania_finalu = 0;
						labelBledy->Text = "GRACZ 2";
						labelPyatnie->Text = "Fina³ - Pytanie 1/5: " + stdToSystemStr((*pytania_finalu)[0].get_tresc());
						textBoxOdpowiedz->Text = "";
					}
					else
					{
						czy_tryb_finalowy = false;
						int suma_finalowa = 0;

						System::String^ podsumowanie_tekst = "--- WYNIKI WIELKIEGO FINA£U ---\n\n";
						
						for (int i = 0;i < 5;i++)
						{
							TPytanie p = (*pytania_finalu)[i];
							runda_aktualna->ustaw_pytanie(p);
							int pkt1 = runda_aktualna->wartosc_odpowiedzi((*odpowiedzi_gracz1)[i]);
							int pkt2 = runda_aktualna->wartosc_odpowiedzi((*odpowiedzi_gracz2)[i]);
							suma_finalowa += pkt1 + pkt2;
							podsumowanie_tekst += "Pytanie " + (i + 1) + ": " + stdToSystemStr(p.get_tresc()) + "\n";
							podsumowanie_tekst += "G1: " + stdToSystemStr((*odpowiedzi_gracz1)[i]) + " (" + pkt1 + " pkt)\n";
							podsumowanie_tekst += "G2: " + stdToSystemStr((*odpowiedzi_gracz2)[i]) + " (" + pkt2 + " pkt)\n";
						}
						
						//Wyœwietlanie wyników na planszy gry
						labelOdp1->Text = "G1: " + stdToSystemStr((*odpowiedzi_gracz1)[0]) + " | G2: " + stdToSystemStr((*odpowiedzi_gracz2)[0]);
						labelOdp2->Text = "G1: " + stdToSystemStr((*odpowiedzi_gracz1)[1]) + " | G2: " + stdToSystemStr((*odpowiedzi_gracz2)[1]);
						labelOdp3->Text = "G1: " + stdToSystemStr((*odpowiedzi_gracz1)[2]) + " | G2: " + stdToSystemStr((*odpowiedzi_gracz2)[2]);
						labelOdp4->Text = "G1: " + stdToSystemStr((*odpowiedzi_gracz1)[3]) + " | G2: " + stdToSystemStr((*odpowiedzi_gracz2)[3]);
						labelOdp5->Text = "G1: " + stdToSystemStr((*odpowiedzi_gracz1)[4]) + " | G2: " + stdToSystemStr((*odpowiedzi_gracz2)[4]);

						labelPunktyDruzyna1->Text = "SUMA PUNKTÓW FINA£U: " + suma_finalowa;

						if (suma_finalowa >= 200)
						{
							PlaySound(TEXT("odsloniecie.wav"), NULL, SND_ASYNC);
							MessageBox::Show(podsumowanie_tekst + "\nWYGRANA! Zdobyliœcie " + suma_finalowa + " punktów! Nagroda g³ówna jest wasza!", "FINA£ WYGRANY", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
						}
						else {
							PlaySound(TEXT("blad.wav"), NULL, SND_ASYNC);
							MessageBox::Show(podsumowanie_tekst + "\nPRZEGRANA! Zdobyliœcie tylko " + suma_finalowa + " punktów. Do 200 zabrak³o " + (200 - suma_finalowa) + ".", "FINA£ PRZEGRANY", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						}
						//reset i powrót do normalnej gry
						numer_rundy = 1;
						punkty_czerwoni = 0;
						punkty_niebiescy = 0;
						UruchomNowaRunde();
					}
				}
				return;
		}

		// LOGIKA ZWYK£EJ RUNDY
		int indeksOdpowiedzi = runda_aktualna->zgadnij(odpGracza, true);

		if (indeksOdpowiedzi != -1) {
			PlaySound(TEXT("odsloniecie.wav"), NULL, SND_ASYNC);
			std::vector<TOdpowiedz> listaOdp = pytanie_aktualne->get_odpowiedzi();
			std::string tekstOdp = listaOdp[indeksOdpowiedzi].tekst + " (" + std::to_string(listaOdp[indeksOdpowiedzi].punkty) + " pkt";
			System::String^ wyswietl_odp = stdToSystemStr(tekstOdp);

			switch (indeksOdpowiedzi) {
			case 0: labelOdp1->Text = "1. " + wyswietl_odp; break;
			case 1: labelOdp2->Text = "2. " + wyswietl_odp; break;
			case 2: labelOdp3->Text = "3. " + wyswietl_odp; break;
			case 3: labelOdp4->Text = "4. " + wyswietl_odp; break;
			case 4: labelOdp5->Text = "5. " + wyswietl_odp; break;
			}

			if (tura_czerownych) {
				punkty_czerwoni += listaOdp[indeksOdpowiedzi].punkty;
				labelPunktyDruzyna1->Text = "Czerowni: " + punkty_czerwoni;
			}
			else {
				punkty_niebiescy += listaOdp[indeksOdpowiedzi].punkty;
				labelPunktyDruzyna2->Text = "Niebiescy: " + punkty_niebiescy;
			}
		}
		else 
		{
			PlaySound(TEXT("blad.wav"), NULL, SND_ASYNC);
			int bledy = runda_aktualna->get_liczba_bledow();
			labelBledy->Text = "B³êdy w rundzie: " + bledy;
			tura_czerownych = !tura_czerownych; // zmiana tury po b³êdzue
		}
		textBoxOdpowiedz->Text = "";

		if (runda_aktualna->czy_koniec() || runda_aktualna->get_liczba_bledow() >= 3) {
			MessageBox::Show("Koniec rundy " + numer_rundy + "!", "Podsumowanie", MessageBoxButtons::OK, MessageBoxIcon::Information);

			if (numer_rundy >= 3)
			{
				UruchomWielkiFinal();
			}
			else
			{
				numer_rundy++;
				UruchomNowaRunde();
			}
		};
	}
};
}
