#include <iostream>
#include <string.h>
using namespace std;

struct tAlumno
{
    int legajo;
    int materia;
	char nombre[26];
};

void cargarArray (tAlumno alumnos[], int &tope) {
	int i = 0;
    cout << endl;
    cout << "Siguiente alumno:" << endl;
    cout << "Legajo: (corta con 0)";
    cin >> alumnos[i].legajo;
    while (alumnos[i].legajo != 0)
    {
        cout << "Codigo materia:";
        cin >> alumnos[i].materia;
		cout << "Codigo nombre:";
        cin >> alumnos[i].nombre;
        cout << endl;
        i++;
        cout << "Siguiente alumno:" << endl;
        cout << "Legajo: (corta con 0)";
        cin >> alumnos[i].legajo;
    };

	tope = i-1;

	cout << endl;
};

void ordenoFinalesxMateria(tAlumno VecF[],int tope)
{
    int pas=1;
    bool ordenado=false;
    tAlumno RAlumno;
    while(!ordenado)
    {
        ordenado = true;

        for(int i=0; i<=tope-pas;i++)
        {
            if(VecF[i].materia > VecF[i+1].materia)
            {
                RAlumno=VecF[i];
                VecF[i] = VecF[i+1];
                VecF[i+1]= RAlumno;
                ordenado = false;
            }
        }
        pas++;
    }
}


void Apareo(tAlumno vectorA[], int &tope1, tAlumno vectorB[], int &tope2, tAlumno vectorFinal[], int &tope3) {

	int j = 0;
	int k = 0;
	int i = 0;

	while( j <= tope1 && k <= tope2)
	{
	    if (vectorA[j].materia <= vectorB[k].materia) {
	    	vectorFinal[i] = vectorA[j];
	    	j++;
		} else {
			vectorFinal[i] = vectorB[k];
			k++;
		};

		i++;
	};

	if (j > tope1) {
		while(k <= tope2) {
			vectorFinal[i] = vectorB[k];
			k++;
			i++;
		};
	} else {
		while(j <= tope1) {
			vectorFinal[i] = vectorA[j];
			j++;
			i++;
		};
	};

	tope3 = i - 1;


};

void MostrarVector(tAlumno VecF[],int tope)
{
    for(int cont = 0; cont <= tope ; cont++)
    {
        cout << VecF[cont].materia << "                        " << VecF[cont].legajo << "                               " << VecF[cont].nombre << endl;
    }
    cout << endl;
}


int main()
{
    tAlumno VecFINALES[100];
    int tope1 = 0;
    tAlumno VecDIAFINALES[100];
    int tope2 = 0;
    tAlumno VecFINALESACT[200];
    int tope3 = 0;

	cout << "Ingreso de alumnos anotados hasta ayer:" <<endl;
	cargarArray(VecFINALES, tope1);
	cout << "Ingreso de alumnos anotados hoy:" <<endl;
	cargarArray(VecDIAFINALES, tope2);
    cout << "VECTORES SIN ORDEN " << endl;
    cout << "Finales hasta ayer  " << endl;
    MostrarVector(VecFINALES, tope1);
    cout << endl;
    cout << "Finales de hoy  " << endl;
    MostrarVector(VecDIAFINALES,tope2);

    ordenoFinalesxMateria(VecFINALES,tope1);
    ordenoFinalesxMateria(VecDIAFINALES,tope2);
    cout << "VECTORES ORDENADOS " << endl;
    cout << "Finales hasta ayer  " << endl;
    MostrarVector(VecFINALES, tope1);
    cout << endl;
    cout << "Finales de hoy  " << endl;
    MostrarVector(VecDIAFINALES,tope2);
    cout << endl;
	Apareo(VecFINALES, tope1, VecDIAFINALES, tope2, VecFINALESACT, tope3);

//	FILE *fFINALESACT;
//	fFINALESACT = fopen("finales.dat", "wb");
//	tAlumno auxAlumno;

	for (int i = 0; i <= tope3; i++) {
	   cout << VecFINALESACT[i].legajo << "  ";
      cout << VecFINALESACT[i].materia << "  ";
      cout << VecFINALESACT[i].nombre << "  " << endl;
//		fwrite(&VecFINALESACT[i], sizeof(VecFINALESACT[i]), 1, fFINALESACT);
	};

//	fclose(fFINALESACT);

//	fFINALESACT = fopen("finales.dat", "rb+");

//	fread(&auxAlumno, sizeof(auxAlumno), 1, fFINALESACT);

//	while (!feof(fFINALESACT))
//	{
//		cout << auxAlumno.materia << " " << auxAlumno.legajo << " " << auxAlumno.nombre << endl;
//		fread(&auxAlumno, sizeof(auxAlumno), 1, fFINALESACT);
//	};


	return 0;

};
