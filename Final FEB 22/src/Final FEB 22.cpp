

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
struct tpac {
	int dni;
	char Nomap[30];
	int nac;
	char dir[30];
	char centro[30];
	char test[8];
	char obsoc[30];
	int dosis;
	int fechcont;
	char result[25];
};
*/
/*
struct Nodo{
	int info;
	Nodo* sig;
};
*/


/*void buscahisopados (){

	tpac rpac;

	FILE* fhiso = fopen("hisopados.dat","rb");


	while (rpac.result != "positivo"){
		while (rpac.test != "antigeno"){

		}
	};

};

*/



string Encolarencajarapida(int cant){

	string A;

	//Nodo* pnue = new Nodo();
	//pnue->info = CA;

	if (cant <= 10){
	A="VERDADERO";
	};
	if (cant > 10){
	A="FALSO";
	};

return A;
};



int main(){

	int CA;

	cout << "Ingrese cantidad de unidades > o < a 10 unidades" << endl;
	cin >> CA;

	cout << Encolarencajarapida(CA) << endl;

	return 0;
}

