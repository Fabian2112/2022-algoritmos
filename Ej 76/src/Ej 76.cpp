#include <iostream>
#include <stdio.h>
using namespace std;

struct t_almn {

   int legajo;
   //int materia;
   int Par1, Par2, RecP1, RecP2;

   //bool aprobado;
   //notas = [Par1, Par2, RecP1, RecP2]
};

bool aprobo(t_almn r_alumno){

   //En base a las notas de los parciales y los recuperatorios analiza si el alumno aprobo o no.
   //Devuelve "true" si esta aprobado. "false" si esta desaprobado.
   bool aprobado = false;

   if ((r_alumno.Par1 >= 6) || (r_alumno.RecP1 >= 6)){

      if ((r_alumno.Par2 >= 6) || (r_alumno.RecP2 >= 6)){
         aprobado = true;
         //cout << "El alumno Aprobo" << r_alumno.legajo << endl;
      }
   }

   return aprobado;
}

int analizar_promocion(int Par1, int Par2, int RecP1, int RecP2){
   //Devuelve 1 si el alumno promociona
   // Devuelve 0 si no lo hace

   int result;

   if((Par1 >= 8 || RecP1 >= 8) && (Par2 >=8)){
      result = 1;
   }
   else if ((Par2 >= 8 || RecP2 >= 8) && (Par1 >= 8)) {
      result = 1;
   }
   else {
      result = 0;
   }

   return result;
}

void generar_archivo() {

   t_almn r_alumno;
   //string asignatura;

   FILE* falu = fopen("Alumnos.dat", "w+b");
   /*
   cout << endl << "Ingrese el NOMBRE de la MATERIA: ";
   cin >> asignatura;
   */
   cout << "_________________________________________" << endl;

   cout << endl << "Ingrese el LEGAJO del alumno (0 para cortar): ";
   cin >> r_alumno.legajo;

   while (r_alumno.legajo != 0) {

      //inicializo
      r_alumno.RecP2 = 0;
      r_alumno.RecP1 = 0;


      //r_alumno.materia = asignatura; // la pregunto una sola vez y la repito en cada registro

      /*PARCIALES*/
      cout << endl << "Ingrese la NOTA del PRIMER PARCIAL: ";
      cin >> r_alumno.Par1;

      cout << endl << "Ingrese la NOTA del SEGUNDO PARCIAL: ";
      cin >> r_alumno.Par2;

      /*RECUPERATORIOS*/
      if (r_alumno.Par1 < 6) { // no tiene nota de promocion
         cout <<endl << "Ingrese la NOTA del RECUPERATORIO del PRIMER PARCIAL: ";
         cin >> r_alumno.RecP1;
      }

      if (r_alumno.Par2 < 6) {
         cout <<endl << "Ingrese la NOTA del RECUPERATORIO del SEGUNDO PARCIAL: ";
         cin >> r_alumno.RecP2;
      }

      //if(aprobo(r_alumno))
      fwrite (&r_alumno, sizeof(r_alumno), 1, falu);  //fwrite (puntero al registro, tamaño del registro, 1, nombre del archivo)


      //Nuevo alumno
      cout << "_________________________________________" << endl;
      cout << endl << "Ingrese el LEGAJO del alumno (0 para cortar): ";
      cin >> r_alumno.legajo;
   }

   fclose(falu);
}

void leer_archivo () {
   t_almn r_alumno;

   FILE* falu = fopen("Alumnos.dat", "r+b");

   //Validacion, no es necesaria
   if (falu == NULL) {
      cout << "ERROR! no existe el archivo" << endl;
   }
   else {
      cout << endl << "           ..:ALUMNOS CARGADOS:..";
      cout << endl << "Legajo  |  1 Par  |  2 Par  |  Rec 1P  |  Rec 2P  "<< endl;
      fread(&r_alumno, sizeof(r_alumno), 1, falu); //intento leer una primera vez
      while(!feof(falu)){
            cout << "   " << r_alumno.legajo << "         " << r_alumno.Par1 << "         " << r_alumno.Par2 << "         " << r_alumno.RecP1 << "         " << r_alumno.RecP2 << endl;
         fread(&r_alumno, sizeof(r_alumno), 1, falu); //intento leer
      }
      cout << endl;

      //vuelvo el puntero del archivo al comienzo para leerlo nuevamente de otra manera
      fseek(falu, 0, SEEK_SET);
      cout << "Repetimos el archivo" << endl;
      cout << endl;

      // Otra forma más sencilla de leer un archivo y sin usar feof
      while(fread(&r_alumno, sizeof(r_alumno), 1, falu)){
            cout << "   " << r_alumno.legajo << "         " << r_alumno.Par1 << "         " << r_alumno.Par2 << "         " << r_alumno.RecP1 << "         " << r_alumno.RecP2 << endl;
      }
      cout << endl;
   }

   fclose(falu);
}



void procesar_archivo () {
   int cant_promocionados = 0;
   t_almn r_alumno;

   FILE* f = fopen("Alumnos.dat", "r+b");

   //Validacion, no es necesaria
   if (f == NULL) {
      cout << "ERROR! no existe el archivo" << endl;
   }
   else {

     cout << endl << "           ..:ALUMNOS APROBADOS:..";
     cout << endl << "Legajo  |  1 Par  |  2 Par  |  Rec 1P  |  Rec 2P  "<< endl;
     fread(&r_alumno, sizeof(r_alumno), 1, f); //intento leer una primera vez
     while(!feof(f)){

         if(aprobo(r_alumno)) {
            cout << "   " << r_alumno.legajo << "         " << r_alumno.Par1 << "         " << r_alumno.Par2 << "         " << r_alumno.RecP1 << "         " << r_alumno.RecP2 << endl;

            cant_promocionados =  cant_promocionados + analizar_promocion(r_alumno.Par1, r_alumno.Par2, r_alumno.RecP1, r_alumno.RecP2); //devuelve 1 si promociono, 0 sino.
         }

         fread(&r_alumno, sizeof(r_alumno), 1, f); //intento leer
      }
   }

   cout << endl << "PROMOCIONARON " << cant_promocionados << " EN TOTAL" << endl;
   cout << endl;
   fclose(f);
}

int main () {

   int opcion = -1;

    do {

      cout << "---------MENU---------" << endl;
      cout << "| 1) Generar archivo |"<<endl;
      cout << "| 2) Leer archivo    |"<<endl;
      cout << "| 3) Procesar archivo    |"<<endl;
      cout << "| 0) Salir           |"<<endl;
      cout << "----------------------" << endl;

      cout <<"Ingrese la opcion deseada: ";
      cin >> opcion;
      cout << "____________________________" << endl;
      switch (opcion) {
         case 0:
            cout<<"Muchas gracias por utilizar el programa"<<endl;
            break;

         case 1:
            generar_archivo();
            break;

         case 2:
               leer_archivo();
               break;
         case 3:
               procesar_archivo();
               break;

         default:
            cout <<"ERROR! La opcion seleccionada es invalida"<<endl;
               break;
         }
   }

   while (opcion != 0);


    return 0;
}
























