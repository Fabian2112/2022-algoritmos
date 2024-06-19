//============================================================================
// Name        : Genera.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
string Nom, Ape, linea;

ofstream archout;
archout.open ("APersonas.txt");

cout << "Ing Nom (punto para cortar): ";
cin >> Nom;
while (Nom != "."){
  cout << "Ing Ape: ";
  cin >> Ape;
  archout << Nom << " " << Ape << endl;
  cout << "Ing Nom (punto para cortar): ";
  cin >> Nom;
}
archout.close();

cout << endl << "Listado del archivo" << endl;

ifstream archin;
archin.open ("APersonas.txt");

while (!archin.eof()){
   getline(archin, linea);
   cout << linea <<endl;
}
archin.close();

cout << "Programa finalizado" <<endl;
return 0;
}
