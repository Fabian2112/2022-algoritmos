


#include <iostream>
#include <fstream>
using namespace std;


struct talu {
	int Leg;
	char NomyAp[30];
	int Antig;
};


struct tmat {
	int CodM;
	char Nommat[30];
	int Capac;
};


struct tins {
	int Leg;
	int CodM;
};


struct Nodo {
	talu info;
	Nodo* sig;
};


void generaralumno() {

   talu ralu;

   FILE *falu = fopen("ALUMNOS.dat", "w+b");

   cout << "_________________________________________" << endl;

   cout << "Ingrese LEGAJO del alumno (0 para cortar): " << endl;
   cin >> ralu.Leg;

   while (ralu.Leg != 0) {

	  cout << "Ingrese Nombre y Apellido del alumno: " << endl;
      cin >> ralu.NomyAp;

      cout << "Ingrese Antiguedad del alumno: " << endl;
      cin >> ralu.Antig;

      fwrite (&ralu, sizeof(ralu), 1, falu);  //fwrite (puntero al registro, tamaño del registro, 1, nombre del archivo)

      cout << "_________________________________________" << endl;
      cout << endl << "Ingrese LEGAJO del alumno (0 para cortar): ";
      cin >> ralu.Leg;
   }

   fclose(falu);
}


void generarmateria() {

   tmat rmat;

   FILE *fmat = fopen("MATERIAS.dat", "w+b");

   cout << "_________________________________________" << endl;

   cout << "Ingrese Codigo de la Materia (0 para cortar): " << endl;
   cin >> rmat.CodM;

   while (rmat.CodM != 0) {

	  cout << "Ingrese Nombre de la Materia: " << endl;
      cin >> rmat.Nommat;
      cout << "Ingrese Capacidad de la Materia: " << endl;
      cin >> rmat.Capac;

      fwrite (&rmat, sizeof(rmat), 1, fmat);  //fwrite (puntero al registro, tamaño del registro, 1, nombre del archivo)

      cout << "_________________________________________" << endl;
      cout << "Ingrese Codigo de la Materia (0 para cortar): " << endl;
      cin >> rmat.CodM;
   }

   fclose(fmat);
}


void generarinscripcion() {

   tins rins;

   FILE *fins = fopen("INSCRIPCIONES.dat", "w+b");

   cout << "_________________________________________" << endl;

   cout << "Ingrese el Legajo del Alumno (0 para cortar): " << endl;
   cin >> rins.Leg;

   while (rins.Leg != 0) {

	  cout << "Ingrese Codigo de la Materia: " << endl;
      cin >> rins.CodM;

      fwrite (&rins, sizeof(rins), 1, fins);  //fwrite (puntero al registro, tamaño del registro, 1, nombre del archivo)

      cout << "_________________________________________" << endl;
      cout << "Ingrese el Legajo del Alumno (0 para cortar): " << endl;
      cin >> rins.Leg;
   }

   fclose(fins);
}



void leerarchivos() {

   talu ralu;

   FILE* falu = fopen("ALUMNOS.dat", "rb");

      cout << endl << "     ..:ALUMNOS CARGADOS:..";
      cout << endl << "Legajo  |  NomyAp  |  Antiguedad  "<< endl;

      fread(&ralu, sizeof(ralu), 1, falu); //intento leer una primera vez
      while(!feof(falu)){
            cout << "   " << ralu.Leg << "         " << ralu.NomyAp << "           " << ralu.Antig << endl;
         fread(&ralu, sizeof(ralu), 1, falu); //intento leer
      }
      cout << endl;

      //vuelvo el puntero del archivo al comienzo para leerlo nuevamente de otra manera
      fseek(falu, 0, SEEK_SET);
      cout << "Repetimos el archivo" << endl;
      cout << endl;

   fclose(falu);



   tmat rmat;

   FILE* fmat = fopen("MATERIAS.dat", "rb");

      cout << endl << "   ..:MATERIAS REGISTRADAS:..";
      cout << endl << "Codigo  |  Nombre  |  Capacidad  "<< endl;

      fread(&rmat, sizeof(rmat), 1, fmat);
      while(!feof(fmat)){
            cout << "   " << rmat.CodM << "         " << rmat.Nommat << "            " << rmat.Capac << endl;
         fread(&rmat, sizeof(rmat), 1, fmat);
      }
      cout << endl;

      //vuelvo el puntero del archivo al comienzo para leerlo nuevamente de otra manera
      fseek(fmat, 0, SEEK_SET);
      cout << "Repetimos el archivo" << endl;
      cout << endl;

   fclose(fmat);


   tins rins;

    FILE* fins = fopen("INSCRIPCIONES.dat", "rb");

       cout << endl << "..:INSCRIPCIONES A MATERIAS:..";
       cout << endl << "   Legajo  |  Codigo Materia "<< endl;

       fread(&rins, sizeof(rins), 1, fins); //intento leer una primera vez
       while(!feof(fins)){
             cout << "      " << rins.Leg << "              " << rins.CodM << endl;
          fread(&rins, sizeof(rins), 1, fins); //intento leer
       }
       cout << endl;

       //vuelvo el puntero del archivo al comienzo para leerlo nuevamente de otra manera
       fseek(fins, 0, SEEK_SET);
       cout << "Repetimos el archivo" << endl;
       cout << endl;

    fclose(fins);

}


void materiassininscriptos() {

tmat rmat;
tins rins;

FILE* fmat = fopen("MATERIAS.dat", "rb");
FILE* fins = fopen("INSCRIPCIONES.dat", "rb");

	cout << endl;

	cout << " ..:MATERIAS SIN INSCRIPTOS:.." << endl;
	cout << "    Codigo   |   Nombre    "<< endl;

	fread(&rmat, sizeof(rmat),1,fmat);
	while(!feof(fmat)){
		fread(&rins, sizeof(rins),1,fins);
	    while (!feof(fins) && rmat.CodM != rins.CodM){
        fread (&rins, sizeof(rins),1,fins);
        };
	    if (rmat.CodM != rins.CodM){
        cout << "      " << rmat.CodM << "            " << rmat.Nommat << endl;
        };

   fseek(fins, 0, SEEK_SET);
   fread (&rmat, sizeof(rmat),1,fmat);
   };

fclose(fmat);
fclose(fins);

cout << endl;

cout << "Repetimos el archivo" << endl;
cout << endl;
}



void promedioantiguedad() {

	int n=0;
	int suma=0;
	float prom=0;

	talu ralu;
	tins rins;
	tmat rmat;

	FILE* fmat = fopen("MATERIAS.dat", "rb");
	FILE* falu = fopen("ALUMNOS.dat", "rb");
	FILE* fins = fopen("INSCRIPCIONES.dat", "rb");

	cout << endl;

	cout << " ..:ANTIGUEDAD PROMEDIO POR MATERIA:.." << endl;
	cout << "      Materia   |   Antigüedad Prom. "<< endl;

	fread (&rmat, sizeof(rmat),1,fmat);
	while (!feof(fmat)){
		fread (&rins, sizeof(rins),1,fins);
		while (!feof(fmat) && !feof(fins) && rmat.CodM != rins.CodM){
			fread (&rins, sizeof(rins),1,fins);
		};
		while  (!feof(fins) && !feof(fmat)){
			while  (!feof(fins) && rins.CodM != rmat.CodM){
			fread (&rins, sizeof(rins),1,fins);
			};
			if (rmat.CodM == rins.CodM){
			fread (&ralu, sizeof(ralu),1,falu);
				while (!feof(falu) && ralu.Leg != rins.Leg){
				fread (&ralu, sizeof(ralu),1,falu);
				};
				if (ralu.Leg == rins.Leg){
				suma = suma + ralu.Antig;
				n=n+1;
				prom = suma / n;
				};
			};
		fseek(falu, 0, SEEK_SET);
		fread (&rins, sizeof(rins),1,fins);
		};
		if (!feof(fmat) && n!=0){
		cout << "         " << rmat.CodM   <<"                "<< prom << endl;
		};
	fseek(fins, 0, SEEK_SET);
	n=0;
	suma=0;
	fread (&rmat, sizeof(rmat),1,fmat);
	};

fseek(fmat, 0, SEEK_SET);

fclose(fmat);
fclose(fins);
fclose(falu);

cout << endl;

cout << "Repetimos el archivo" << endl;
cout << endl;
};



void alumnossinmateria(){

	Nodo* lista = NULL;
	int n=0;

	tins rins;
	tmat rmat;
	talu ralu, rinfo;

	FILE *fins = fopen ("INSCRIPCIONES.dat","rb");
	FILE *fmat = fopen ("MATERIAS.dat","rb");
	FILE *falu = fopen ("ALUMNOS.dat","rb");

	cout << endl;

    cout << " ..:ALUMNOS S/MATERIA x CAP.:.."<< endl;
    cout << "     NomyAp  |   Legajo   "<< endl;


	fread(&rmat,sizeof(rmat),1,fmat);
	while (!feof(fmat)) {

		//cout << "     " << rmat.CodM << endl;

		fread(&rins,sizeof(rins),1,fins);
		while (!feof(fins) && n<rmat.Capac) { //leyendo la primer materia comparo capacidad con cada inscripcion de alumno sumando "n+1"
			if (rins.CodM == rmat.CodM){
			n=n+1;
			};
	    fread(&rins,sizeof(rins),1,fins);
		};

		//cout << "     " << rins.Leg << endl;

		if (n>=rmat.Capac){ //si el conteo "n" supera la capacidad de la materia empieza a buscar el alumno siguiente

			//fread(&rins,sizeof(rins),1,fins);

			while (!feof(fins)){ //hasta fin de listado de inscriptos muestro los que se quedan afuera
				if (rins.CodM == rmat.CodM){
					fread(&ralu,sizeof(ralu),1,falu);
					while (!feof(falu) && ralu.Leg != rins.Leg){ //busca el alumno que quedó sin capacidad para ordenarlo en memoria dinamica
					fread(&ralu,sizeof(ralu),1,falu);
					};

					//cout << "     " << ralu.Leg << endl;

					Nodo* pnue=new Nodo();
					pnue->info=ralu;
					if ((lista==NULL) || (pnue->info.Leg < lista->info.Leg)){
					pnue->sig=lista;
					lista=pnue;
					}
					else{
					Nodo* ptr = lista;
					Nodo* antp;
						while((ptr != NULL) && (pnue->info.Leg > ptr->info.Leg)){
						antp = ptr;
						ptr = ptr-> sig;
						};
					pnue->sig = ptr;
					antp->sig = pnue;
					};
				};

				//cout << "     " << rins.Leg << endl;

			fread(&rins,sizeof(rins),1,fins);
			fseek(falu, 0, SEEK_SET);

			};

		};

	fseek(fins, 0, SEEK_SET);
	n=0;

	fread(&rmat,sizeof(rmat),1,fmat);
	};

fseek(fmat, 0, SEEK_SET);

while (lista!=NULL){
Nodo* pt2 = lista;
rinfo = pt2 -> info;
lista = lista -> sig;
delete pt2;
cout << "       " << rinfo.NomyAp << "          " << rinfo.Leg << endl;

};

cout << endl;
cout << "Repetimos el archivo" << endl;

fclose(fmat);
fclose(fins);
fclose(falu);

cout << endl;

};




int main () {

	   int opcion = -1;

	    do {

	      cout << "---------MENU---------" << endl;
	      cout << "| 1) Generar alumnos |"<<endl;
	      cout << "| 2) Generar materias |"<<endl;
	      cout << "| 3) Generar inscripcion |"<<endl;
	      cout << "| 4) Leer Archivos |"<<endl;
	      cout << "| 5) Materias s/inscriptos |"<<endl;
	      cout << "| 6) Promedio Antiguedad alumnos p/Materia |"<<endl;
	      cout << "| 7) Alumnos sin Materia por capac. Completa |"<<endl;
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
	            generaralumno();
	            break;

	         case 2:
		        generarmateria();
		        break;
	         case 3:
		        generarinscripcion();
		        break;

	         case 4:
		        leerarchivos();
		        break;

	         case 5:
		        materiassininscriptos();
		        break;

	         case 6:
	        	promedioantiguedad();
		        break;

	         case 7:
	        	alumnossinmateria();
		        break;

	         default:
	            cout <<"ERROR! La opcion seleccionada es invalida"<<endl;
	            break;
	         }
	   }

	   while (opcion != 0);

	return 0;
}
