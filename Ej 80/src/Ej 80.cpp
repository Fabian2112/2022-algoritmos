#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct tAlumno{
    char nombre[20];
    int edad;
};
void generarArchivo()
{
    tAlumno ralumno;
    FILE *f= fopen("Alumnos.dat", "w+b");

    cout << "Ingrese la edad (0 para cortar)" << endl;
    cin >> ralumno.edad;
    while (ralumno.edad!= 0)
    {
        cout << "Ingrese el nombre: " << endl;
        cin >> ralumno.nombre;
         fwrite (&ralumno, sizeof (ralumno), 1, f);   // write(RDest,aDest)
        cout << "Ingrese la edad (0 para cortar)" << endl;
        cin >> ralumno.edad;
    }
    fclose (f);
}

void leerArchivo()
{
     FILE *f = fopen ("Alumnos.dat", "r+b");
    tAlumno ralumno;
    if (f == NULL) {
        cout << "ERROR! No existe el archivo" << endl;
        return;
    }
    fread (&ralumno, sizeof (ralumno), 1, f);
    while (!feof (f))
    {
        cout << "Nombre: " << ralumno.nombre<<endl;
        cout << "Edad: " << ralumno.edad << endl;
        fread (&ralumno, sizeof (ralumno), 1, f);
    }
   fclose (f);
}

int cargarAlumnos(tAlumno (&valumnos)[70])
{
    FILE *f = fopen ("Alumnos.dat", "r+b");

    tAlumno ralumno;

    int i =0;
    if (f == NULL) {
        cout << "ERROR! No existe el archivo" << endl;
        return 1;
    }
    fread (&ralumno, sizeof (ralumno), 1, f);
    //    Podría leer directamente el registro del archivo y colocarlo ya dentro del vector
    //    porque COINCIDEN EN ESTRUCTURA
    //    fread (&valumnos[i], sizeof (valumnos[i]), 1, f);
    while (!feof (f))
    {
        strcpy(valumnos[i].nombre,ralumno.nombre);
        // valumnos[i].nombre = ralumno.nombre   // no va pq no se puede asignar directo entre cadenas de caracteres
        valumnos[i].edad = ralumno.edad;

        fread (&ralumno, sizeof (ralumno), 1, f);
        //    fread (&valumnos[i], sizeof (valumnos[i]), 1, f);
        i++;
    }
   fclose (f);
   return i;
}
void calcularPromedio(tAlumno valumnos[70], int n)
{
    float promedio=0;
    int suma=0;

    for(int i =0;i<=n-1;i++) //Calculo el promedio
        suma += valumnos[i].edad;

    promedio = suma / n * 1.0;

    cout << "Promedio de edad es: " << promedio << endl;
    cout << "Alumnos que superaron el promedio: " << endl;
    cout << "Nombre          " << "Edad          " << endl;

    for(int i =0; i<= n-1;i++)//Los que superaron el promedio los mostramos
    {
        if(valumnos[i].edad>promedio)
        {
            cout << valumnos[i].nombre << "          " << valumnos[i].edad << endl;
        }
    }

}

int main()
{
    tAlumno valumnos[70];
    int opcion;
    int n=0;

    do {
      cout<<"Ingrese la opcion deseada"<<endl;
      cout<<"1) Generar y mostrar archivo alumnos"<<endl;
      cout<<"2) Calcular promedio e imprimir mayores"<<endl;
      cout<<"0) Salir"<<endl;
      cin >> opcion;

      switch (opcion) {
         case 0:
            cout<<"Muchas gracias por utilizar el programa"<<endl;
            break;
         case 1:
            generarArchivo();
            leerArchivo();
            break;
         case 2:
            n = cargarAlumnos(valumnos);
            calcularPromedio(valumnos,n);
            break;

         default:
            cout <<"ERROR! La opcion seleccionada es invalida"<<endl;
            break;
      }
   }
   while (opcion != 0);
   return 0;
}
