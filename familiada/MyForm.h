#pragma once
#include <string>
#include <vector>
#include "TGra.h"
#include "TRunda.h"
#include "TPytanie.h"
#include "TDruzyna.h"
#include "windows.h"
#include <mmsystem.h>
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
			if (components)
			{
				delete components;
			}
		}
	private:
		std::vector<TPytanie> baza_pytan;
		TRunda runda_aktualna;
		TPytanie pytanie_aktualne;
		int punkty_czerwoni;
		int punkty_niebiescy;
		int numer_rundy;
		bool tura_czerownych; // true = czerowni, false = niebiescy
	private: System::String^ stdToSystem(std::string stdStr)
	{
		return gcnew System::String(stdStr.c_str());
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
			this->labelPytanie->Location = System::Drawing::Point(183, 33);
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
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void labelPunktyDruzyna1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void UruchomNowaRunde() {
		if (baza_pytan.empty()) return;

		runda_aktualna = TRunda();
		pytanie_aktualne = runda_aktualna.losuj_pytanie(baza_pytan);
		runda_aktualna.ustaw_pytanie(pytanie_aktualne);

		labelPytanie->Text = "Runda " + numer_rundy + ": " + stdToSystemStr(pytanie_aktualne.get_tresc());

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
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		// Zerujemy stan pocz¹tkowy
		punkty_czerwoni = 0;
		punkty_niebiescy = 0;
		numer_rundy = 1;
		tura_czerownych = true; // zaczna czerowni

		// Szczytanie bazy pytan
		runda_aktualna.sczytaj_pytanie(baza_pytan);
		if (!baza_pytan.empty()) {
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
		int indeksOdpowiedzi = runda_aktualna.zgadnij(odpGracza, true);

		if (indeksOdpowiedzi != -1) {
			PlaySound(TEXT("odsloniecie.wav"), NULL, SND_ASYNC);
			std::vector<TOdpowiedz> listaOdp = pytanie_aktualne.get_odpowiedzi();
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
		else {
			PlaySound(TEXT("blad.vaw"), NULL, SND_ASYNC);
			int bledy = runda_aktualna.get_liczba_bledow();
			labelBledy->Text = "B³êdy w rundzie: " + bledy;
			tura_czerownych = !tura_czerownych; // zmiana tury po b³êdzue
		}
		textBoxOdpowiedz->Text = "";

		if (runda_aktualna.czy_koniec) || runda_aktualna.get_liczba_bledow() >= 3 {
			MessageBox::Show("Koniec rundy " + numer_rundy + "!", "Podsumowanie", MessageBoxButtons::OK, MessageBoxIcon::Information);

			numer_rundy++;
			UruchomNowaRunde();
		};
	}
};
}
