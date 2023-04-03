#include <iostream>
#include <conio.h>
#include <string.h>
//#include "coordenadas.h"
using namespace std;

struct producto{
	string nombre;
	float precio;
	int cantidad;
	string marca;
	char disponible;
};

void entrada(int lim,producto lacteos[]);
void consulta1(int lim,producto lacteos[]);
void consulta2(string valor, int lim,producto lacteos[]);
void inventario(int lim,producto lacteos[]);
void eliminar(string valor, int lim,producto lacteos[]);
void modificarNombre(string valor, string valor2,int lim,producto lacteos[]);
void modificarPrecio(string valor, float pre,  int lim,producto lacteos[]);


main(){
	producto lacteos[' '];
	int op1,op2,op3,num;
	string nom,nom2;
	float prec;
	char ov;
	do{
		do{
			system("color 30");
			system("cls");
			cout<<"****** TIENDA DE LACTEOS ******"<<endl;
			cout<<"************* MENU *************"<<endl;
			cout<<"*  1) Alta                     *"<<endl;
	 		cout<<"*  2) Consulta                 *"<<endl;
	 		cout<<"*  3) Almacen (inventario)     *"<<endl;
	 		cout<<"*  4) Bajas                    *"<<endl;
	 		cout<<"*  5) Cambios                  *"<<endl;
	 		cout<<"*  6) Salir                    *"<<endl;
 			cout<<"********************************"<<endl;
	 		cout<<"Elija una opcion: ";
	 		cin>>op1;
	 		system("cls");
	 		switch(op1){
	 			case 1:
	 				cout<<"---------- ALTA DE DATOS ----------"<<endl;
	 				cout<<"Cantidad de productos: ";
					cin>>num;
					cout<<endl;
					entrada(num,lacteos);										
	 				break;
	 			case 2:
	 				do{
						system("cls");
						cout<<"---------- CONSULTA ----------"<<endl;
						cout<<"*******************************"<<endl;
	 					cout<<"*  1) Todos los productos     *"<<endl;
		 				cout<<"*  2) Por producto            *"<<endl;
		 				cout<<"*  3) Salir                   *"<<endl;
		 				cout<<"******************************"<<endl;
		 				cout<<"Elija una opcion: "<<endl;
		 				cin>>op2;
		 				system("cls");
							switch(op2){
								case 1:
									cout<<"---------- TODOS LOS PRODUCTOS ----------";
									cout<<endl;
									consulta1(num,lacteos);
									getch();
								break;
								case 2:
									cout<<"---------- POR PRODUCTO ----------"<<endl;
									cout<<"Nombre del producto: ";
									cin>>nom;
									cout<<endl;
				 					consulta2(nom,num,lacteos);
									getch();
								break;
								case 3:
								break;
						}
					}while(op2!=3);	
	 				break;
	 			case 3:
	 				cout<<"---------- ALMACEN ----------";
	 				cout<<endl;
	 				inventario(num,lacteos);
	 				cout<<endl;
	 				getch();
	 				break;
	 			case 4:
	 				cout<<"---------- BAJAS ----------"<<endl;
	 				cout<<"Nombre del producto a eliminar: ";
					cin>>nom;
			 		cout<<endl;
				 	eliminar(nom,num,lacteos);
					getch();
	 				break;
	 			case 5:
	 				do{
						system("cls");
						cout<<"---- CAMBIOS ----"<<endl;
						cout<<"******************"<<endl;
	 					cout<<"*  1) Nombre     *"<<endl;
		 				cout<<"*  2) Precio     *"<<endl;
		 				cout<<"*  3) Salir      *"<<endl;
		 				cout<<"******************"<<endl;
		 				cout<<"Elija una opcion: ";
		 				cin>>op3;
		 				system("cls");
							switch(op3){
								case 1:
									cout<<"---------- NOMBRE ----------"<<endl;
									cout<<"Nombre del producto: ";
									cin>>nom;									
									cout<<"Nombre del producto a cambiar: ";
									cin>>nom2;
									cout<<endl;
				 					modificarNombre(nom,nom2, num,lacteos);
									getch();
								break;
								case 2:
									cout<<"---------- PRECIO ----------"<<endl;
									cout<<"Nombre del producto: ";
									cin>>nom;									
									cout<<"Precio del producto a cambiar: ";
									cin>>prec;
									cout<<endl;
				 					modificarPrecio(nom,prec,num,lacteos);
									getch();
								break;
								case 3:
								break;
							}
					}while(op3!=3);	
	 				break;
	 		case 6:
	 			break;
	 				}
	 				
	}while(op1!=6);
		cout<<"Desea ejecutar otra vez? s/n: ";
		cin>>ov;
}while(ov=='s'||ov=='S');
}

void entrada(int lim,producto lacteos[]){
	int x;
	if(lim>0){
		for(x=0;x<lim;x++){
			cout<<endl;
			cout<<"Nombre del producto: ";
			cin>>lacteos[x].nombre;
			cout<<"Precio del producto : ";
			cin>>lacteos[x].precio;
			cout<<"Cantidad: ";
			cin>>lacteos[x].cantidad;
			cout<<"Marca: ";
			cin>>lacteos[x].marca;
			cout<<"Disponible (s/n): ";
			lacteos[x].disponible='s';
			cout<<lacteos[x].disponible;
			cout<<endl;
		}
	}else{
		cout<<"NO INGRESO CANTIDAD DE PRODUCTOS A REGISTRAR "<<endl;
	}
}

void inventario(int lim,producto lacteos[]){
	int x;
	for(x=0;x<lim;x++){
		cout<<"Nombre del producto: "<<lacteos[x].nombre<<endl;
		cout<<"Precio del producto : "<<lacteos[x].precio<<endl;
		cout<<"Cantidad: "<<lacteos[x].cantidad<<endl;
		cout<<"Marca: "<<lacteos[x].marca<<endl;
		cout<<"Disponible (s/n): "<<lacteos[x].disponible<<endl;
		cout<<endl;
	}
}

void consulta1(int lim,producto lacteos[]){
	int x;
	int c=0;
	for(x=0;x<lim;x++){
		if(lacteos[x].disponible=='s'){
			cout<<"Nombre del producto: "<<lacteos[x].nombre<<endl;
			cout<<"Precio del producto : "<<lacteos[x].precio<<endl;
			cout<<"Cantidad: "<<lacteos[x].cantidad<<endl;
			cout<<"Marca: "<<lacteos[x].marca<<endl;
			cout<<"Disponible (s/n): "<<lacteos[x].disponible<<endl;
			cout<<endl;
			c++;
		}
	}
	
	if(c==0){
		cout<<"NO EXISTEN PRODUCTOS O FUERON ELIMINADOS "<<endl;
	}	
}

void eliminar(string valor,int lim,producto lacteos[]){
	int x;
	int c=0;
	for(x=0;x<lim;x++){
		if(lacteos[x].nombre== valor){
			lacteos[x].disponible='n';
			cout<<"PRODUCTO ELIMINADO : "<<valor<<endl;
			c++;
		}
	}
	if(c==0){
		cout<<"NO SE ENCONTRO PRODUCTO A ELIMINAR:"<<valor<<endl;
	}
}

void consulta2(string valor,int lim,producto lacteos[]){
	int x;
	int c=0;
	for(x=0;x<lim;x++){
		if(lacteos[x].disponible=='s'){
			if(lacteos[x].nombre==valor){				
				cout<<"Nombre del producto: "<<lacteos[x].nombre<<endl;
				cout<<"Precio del producto : "<<lacteos[x].precio<<endl;
				cout<<"Cantidad: "<<lacteos[x].cantidad<<endl;
				cout<<"Marca: "<<lacteos[x].marca<<endl;
				cout<<"Disponible (s/n): "<<lacteos[x].disponible<<endl;
				cout<<endl;
				c++;
			}
		}
	}
	
	if(c==0){
		cout<<"NO EXISTE EL PRODUCTO O FUE ELIMINADO:"<<valor<<endl;
	}
}

void modificarNombre(string valor, string valor2,int lim,producto lacteos[]){
	int x;
	int c=0;
	for(x=0;x<lim;x++){
		if(lacteos[x].nombre == valor){
			cout<<"NOMBRE ACTUAL : "<<lacteos[x].nombre<<endl;
			cout<<"NOMBRE MODIFICADO : "<<valor2<<endl;
			lacteos[x].nombre=valor2;
			cout<<endl;
			c++;
		}
	}	
	if(c==0){
		cout<<"NO SE ENCONTRO PRODUCTO A MODIFICAR : "<<valor<<endl;
	}	
}

void modificarPrecio(string valor, float pre,  int lim,producto lacteos[]){
	int x;
	int c=0;
	for(x=0;x<lim;x++){
		if(lacteos[x].nombre == valor){
			cout<<"PRECIO ACTUAL : "<<lacteos[x].precio<<endl;
			cout<<"PRECIO MODIFICADO : "<<pre<<endl;
			lacteos[x].precio = pre;
			cout<<endl;
			c++;
		}
	}
	if(c==0){
		cout<<"NO SE ENCONTRO PRODUCTO A MODIFICAR : "<<valor<<endl;
	}
}
