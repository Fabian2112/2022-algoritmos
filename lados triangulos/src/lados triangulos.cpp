

#include <iostream>
using namespace std;

struct tlados{
	float L1;
	float L2;
	float L3;
};

void comparacion(float Lado1, float Lado2, float Lado3){
	if(Lado1 == Lado2 && Lado2 == Lado3) {
		cout << "triangulo equilatero" << endl;
	}
	else {
		cout << "Triangulo no equilatero" << endl;
	}
};



int main() {

	tlados rlados;


	cout << "Ingrese el primer lado del triangulo (cero para cortar)" << endl;
	cin >>  rlados.L1;


	while(rlados.L1 != 0) {
	cout << "Ingrese los lados restantes del triangulo" << endl;
	cin >>  rlados.L2;
	cin >>  rlados.L3;
	comparacion(rlados.L1,rlados.L2,rlados.L3);

	cout << "Ingrese el primer lado del triangulo (cero para cortar)" << endl;
	cin >>  rlados.L1;
	};


	return 0;
}
