#include<iostream>
using namespace std;

// Declaraciones adelantadas de las funciones o prototipos
bool lado1nulo(int l);
bool equilatero(int l1, int l2, int l3);
void sumareq(int &ceq);
void sumarperimetros(int perim, int &sumperim);
void inicializar(int &c, int &sum);
void informes(int contador, int sumap);


//Programa o modulo principal

int main() {
	int ceq;
	int l1;
	int l2;
	int l3;
	int perim;
	int sumperim;
	// Ingresar valores correspondientes a los lados de un triángulo
	// hasta que se ingresa un primer valor de lado (L1) cero.
	// Informar la cantidad de triángulos equiláteros ingresados
	// y la sumatoria de los perímetros de todos los triángulos
	inicializar(ceq,sumperim);
	cout << "Ing Lado 1 (0 para cortar)" << endl;
	cin >> l1;
	// Mientras L1<>0 Hacer
	// Mientras (LadoNulo(L1)=falso) Hacer
	while (!lado1nulo(l1)) {
		cout << "Ingrese 2 lados restantes" << endl;
		cin >> l2 >> l3;
		// Si (L1=L2) Y (L2=L3) Entonces      en vez de evaluar así, lo hago a través de una función no void
		if (equilatero(l1,l2,l3)) {
			// CEq=CEq+1   en vez de sumar 1 así, lo hago a través de una función void
			sumareq(ceq);
		}
		perim = l1+l2+l3;
		// SumPerim <- SumPerim+Perim    en vez de sumar así, lo hago a través de una función void
		sumarperimetros(perim,sumperim);
		cout << "Ing Lado 1 (0 para cortar)" << endl;
		cin >> l1;
	}
	informes(ceq,sumperim);
	return 0;
}



bool lado1nulo(int l) {
	bool l1nulo;
	if (l==0) {
		l1nulo = true;
	} else {
		l1nulo = false;
	}
	return l1nulo;
}

bool equilatero(int l1, int l2, int l3) {
	bool equilat;
	if ((l1==l2) && (l2==l3)) {
		equilat = true;
	} else {
		equilat = false;
	}
	return equilat;
}

void sumareq(int &ceq) {
	ceq = ceq+1;
}

void sumarperimetros(int perim, int &sumperim) {
	sumperim = sumperim+perim;
}

void inicializar(int &c, int &sum) {
	c = 0;
	sum = 0;
}

void informes(int contador, int sumap) {
	cout << "Cant equil " << contador << endl;
	cout << "Suma total de perim " << sumap << endl;
}


