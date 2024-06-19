
#include<iostream>
using namespace std;


int main() {
	int i;
	int p;
	int v;
	float pu;
	// 52) Se ingresa inicialmente el precio unitario de 10 productos, numerados de 1 a 10, sin orden.
	// Luego se conocen datos de diferentes ventas de productos sin orden, donde por cada venta se conoce:
	// Nro producto vendido    Cantidad vendida
	// Se pide luego de cada ingreso de venta informar el importe total de dicha venta (cantidad vendida por precio unitario de dicho producto).
	// completar con variables del problema
	// Cargo el VP con los ingresos sin orden del usuario
	cout << "INGRESE LA INFO DE LOS 10 PRODUCTOS NO NECESARIAMENTE EN ORDEN" << endl;
	for (i=1;i<=4;i++) {
		cout << "Ing. producto (1 a 10 sin orden)" << endl;
		cin >> p;
		cout << "Ing. el Precio Unitario de dicho producto" << endl;
		cin >> pu;
		// Cargar a Vector VP en la posic. del producto (ojo recordar vector arranca en 0!)
	}
	cout << "AHORA INGRESE LAS VENTAS SIN ORDEN" << endl;
	// ARMAR CICLO DE INGRESO DE VENTAS E IMPRESION DE IMPORTE DE CADA UNA
		cin >> v;


	return 0;
}

