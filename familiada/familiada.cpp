/*#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "TPytanie.h"
#include "TRunda.h"
#include <Windows.h>
#include "TGra.h"

using namespace std; */

// do wczytywania plików dźwiękowych

#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;

/*int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);  //ustawia język pol, plik txt jest UTF8
    srand(time(0)); //losowanie innego pytania


    TGra gra;
    gra.start();

} */
[STAThreadAttribute]

int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    familiada::MyForm form;
    Application::Run(% form);
    return 0;
}

