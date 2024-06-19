

#include <iostream>
using namespace std;


struct tprod{
	int Codp;
	float PUP;
	int CantV;
};


void CargaProds(tprod Vprod[], int & N){
	int i;
	cout << "Ingrese cantidad de productos del comercio"<<endl;
	cin >> N;
	for(i=0;i<=N-1;i++){
		cout << "Ingrese el codigo del producto "<<i+1<<endl;
		cin >> Vprod[i].Codp;
		cout << "Ingrese el precio del producto "<<i+1<<endl;
		cin >> Vprod[i].PUP;
		Vprod[i].CantV=0;
	};
}

int buscarenvec(tvec vect[], int n, int dato){
	int pos=0
	while((vect[pos].Campob != dato) && pos<n){
		pos++
	};
	if(pos==n){
		pos=-1 //como resultado de no encontrado
	};
	return pos;
};



int main() {
	tprod Vprod[100];
	int N;

	CargaProds(Vprod,N);


	return 0;
}

