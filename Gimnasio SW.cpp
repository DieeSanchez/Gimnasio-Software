#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdio.h>

using namespace std;


void Crear();
void Leer();
void Insertar();
void Modificar();
void Eliminar();


struct Personas{
	
	string nom;
	string ape;
	int DNI = 0;
	int id= 0;
	string cuota;
	
}Personas;



int main() {
	
	int opc;

	do {
		cout<<endl;
		cout<<"------------------BIENVENIDOS------------------"<<endl;
		cout<<endl;
		cout<<"---------------GIMNASIO SOFTWARE---------------"<<endl;
		cout<<endl;
		
		cout<<"[1]- Crear lista de personas"<<endl;
		cout<<"[2]- Lista de personas ingresadas al gimnasio"<<endl;
		cout<<"[3]- Ingresar Personas"<<endl;
		cout<<"[4]- Modificar"<<endl;
		cout<<"[5]- Eliminar lista"<<endl;
		cout<<"[6]- Finalizar programa"<<endl;
		
		cout<<"Ingrese su opcion: ";
		cin>>opc;
		switch (opc) {
		case 1:Crear();
		
		break;
		case 2:Leer();
		
		break;
		case 3:Insertar();
			
		break;
		case 4:Modificar();
		
		break;
		case 5:Eliminar();
		
		break;
		case 6: 
		system("cls");
		cout<<"----------------------------------"<<endl;
		cout<<"EL PROGRAMA SE CERRO EXITOSAMENTE."<<endl;
		cout<<"             --------             "<<endl;
		cout<<"PRESIONE ENTER PARA SALIR..."<<endl;
		cout<<"----------------------------------"<<endl;
		
		}
	} while (opc!=6);
	return 0;
	
	
	
	getch();
	return 0;
}


void Crear(){
	
	ofstream archivo; 
	
	archivo.open("Gimnasio_Personas.txt");

	
	archivo.close();
	system("cls");
	cout<<"------------------------------"<<endl;
	cout<<"SE CREO LA LISTA EXITOSAMENTE"<<endl;
	cout<<"------------------------------"<<endl;
	
}
void Leer(){
	
	ifstream archivo("Gimnasio_Personas.txt");
	char linea[1000];
	system("cls");
	cout<<"------------------------------------------------------------------"<<endl;
	cout<<"CLAVE ID  APELLIDO Y NOMBRE       DNI       ESTADO DE CUOTA"<<endl;
	while(!archivo.eof())
	{
		archivo.getline(linea, sizeof(linea));
		cout << linea << endl;

	}
	cout<<"------------------------------------------------------------------"<<endl;
	archivo.close();
	
}
void Insertar(){

	ofstream archivo; 
	
	archivo.open("Gimnasio_Personas.txt",ios::out|ios::app);
	cout<<"Ingrese un ID a otorgar: "; cin>>Personas.id;
	cout<<"Ingrese el nombre de la persona: ";cin>>Personas.nom;
	cout<<"Ingrese el apellido de la persona: ";cin>>Personas.ape;
	cout<<"Ingrese el DNI de la persona: ";cin>>Personas.DNI;
	cout<<"Ingrese PAGADO si la persona abono la cuota, de lo contrario ingrese ADEUDA: ";cin>>Personas.cuota;

	archivo<<Personas.id<<"         "<<Personas.ape<<", "<<Personas.nom<<"         "<<Personas.DNI<<"         "<<Personas.cuota<<endl;

	
	archivo.close();
	system("cls");
	cout<<"------------------------------"<<endl;
	cout<<"SE AGREGO A LA LISTA EXITOSAMENTE"<<endl;
	cout<<"------------------------------"<<endl;
}
	
void Eliminar(){

	ofstream archivo; 
	
	archivo.open("Gimnasio_Personas.txt");
	
	archivo.close();
	remove("Gimnasio_Personas.txt");
	system("cls");
	cout<<"-----------------------------------"<<endl;
	cout<<"SE ELIMINO LA LISTA COMPLETAMENTE"<<endl;
	cout<<"-----------------------------------"<<endl;
}
	
void Modificar(){
	
	bool encontrado=false;
	string auxcuota;
	int auxClave;
	ifstream lectura;
	lectura.open("Gimnasio_Personas.txt",ios::in);
	ofstream aux("auxiliar.txt",ios::out);
	if(lectura.is_open()){
	
	cout<<"Digite la ID de la persona: ";cin>>auxClave;
	lectura>>Personas.id;
	while(!lectura.eof()){
		lectura>>Personas.ape;
		lectura>>Personas.nom;
		lectura>>Personas.DNI;
		lectura>>Personas.cuota;
		if(Personas.id==auxClave){
		encontrado=true;
		cout<<"NUEVO ESTADO DE LA CUOTA DEL GIMNASIO DE "<<Personas.ape<<Personas.nom<<":";
		cin>>auxcuota;
		aux<<Personas.id<<"         "<<Personas.ape<<" "<<Personas.nom<<"         "<<Personas.DNI<<"         "<<auxcuota<<endl;
		system("cls");
		cout<<"----------------------"<<endl;
		cout<<"REGISTRO MODIFICADO"<<endl;
		cout<<"----------------------"<<endl;
	}else{
		aux<<Personas.id<<"         "<<Personas.ape<<" "<<Personas.nom<<"         "<<Personas.DNI<<"         "<<Personas.cuota<<endl;
	}
	lectura>>Personas.id;
}
	lectura.close();
	aux.close();
	
	}if(encontrado==false){
		system("cls");
		cout<<"---------------------------------------"<<endl;
		cout<<"NO SE ENCONTRO UNA PERSONA CON ESE ID"<<endl;
		cout<<"---------------------------------------"<<endl;
	}
	remove("Gimnasio_Personas.txt");
	rename("auxiliar.txt","Gimnasio_Personas.txt");
	
}

