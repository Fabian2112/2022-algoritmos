
#include<iostream>
using namespace std;

int main() {
	int c;
	int i;
	int maxcand;
	int maxvotos;
	int n;
	int vc[10];
	// 51) Finalizada una votaciï¿½n se desean contar los votos obtenidos por cada uno de 10 candidatos existentes
	// Se cuenta con N sobres, y de c/u que se abre se ingresa el nro de candidato elegido (1 a 10)
	// Informar los votos obtenidos por cada candidato y el ganador de la elecciï¿½n
	// completar con variables del problema
	// en C++ una sola lï¿½nea int VC[10]
	// Inicializo el vector de candidatos VC para que cada candidato comience en 0 votos
	for (c=0;c<=9;c++) {
		vc[c] = 0;
	}
	cout << "Ingrese cantidad de votantes" << endl;
	cin >> n;
	// se ingresan los datos de los sobres abiertos
	for (i=1;i<=n;i++) {
		cout << "Ing candidato elegido (1 a 10)" << endl;
		cin >> c;
		vc[c-1] = vc[c-1]+1;
	}
	// Informar votos por candidato
	cout << "Candidato   Votos" << endl;
	for (c=0;c<=9;c++) {
		cout << "       " << c+1 << "       " << vc[c] << endl;
		if ((c==0) || (vc[c]>maxvotos)) {
			maxvotos = vc[c];
			maxcand = c+1;
		}
	}
	cout << "El candidato ganador de la elecciï¿½n es " << maxcand << " con " << maxvotos << " votos" << endl;
	return 0;
}

