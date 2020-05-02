#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>
#include<iomanip>
using namespace std;
void datos();
void reporte();
void menu();
struct poblacion{
	
	float peso;
	float altura;
	int edad;
	char genero;
	
};
int main (){
	menu();
}


void menu(){
	char tecla;
	bool bandera=false;
	
	do{
	    system ("CLS");
	    cout<<"Censo de la poblacion"<<endl;
        cout << "--------------------------" << endl;
        cout << "\t1 Ingresar datos de la persona" << endl;
        cout << "\t2 Reporte" << endl;
        cout << "\t3 Salir" << endl << endl;
 
        cout << "Elije una opcion: ";
 
        cin >> tecla;
 
		switch(tecla)
		{
 
			case '1':
				system("cls");
				datos();
				break;
 
			case '2':
				system("cls");
				reporte();
				break;
				
			case '3':
				bandera=true;

 
				break;
				default:
				system("cls");
				cout << "Opcion no valida.\a\n";
				break;
		}
 
    }while(bandera!=true);
 
    exit (1);
}
	
void datos(){
	
	float pesod, alturad;
	int edadd;
	char generod;
	
    cout<<"ingrese peso de la persona: "<<endl;
    cin>>pesod;
    cout<<"ingrese altura de la persona: "<<endl;
    cin>>alturad;
    cout<<"ingrese edad de la persona: "<<endl;
    cin>>edadd;
    cout<<"ingrese genero de la persona: F/M "<<endl;
    cin>>generod;
  
  generod=toupper(generod);
  
  
  
  ofstream archivo;
  fflush (stdin);
  archivo.open("censo.txt",ios::app);
  archivo<<pesod<<"\t"<<alturad<<"\t"<<edadd<<"\t"<<generod<<endl;
  archivo.close();
  
}

void reporte (){
	ifstream archivo;
	float pesoa, alturaa;
	int edada,i;
	char generoa;
	string linea;
	float sumap=0, sumaa=0, sumae=0;
	
	try {
		archivo.open("censo.txt",ios::in);
		cout<<"Datos del censo:"<<endl;
		cout<<" Peso|"<<"      Altura      |"<<"Edad|"<<"	Genero	|"<<endl;
		while(archivo>>pesoa>>alturaa>>edada>>generoa){
			cout<<setw(3)<<pesoa<<"|"<<setw(5)<<alturaa<<"|"<<setw(4)<<edada<<"|"<<setw(4)<<generoa<<"|"<<endl;
			i++;
			sumap+=pesoa;
			sumaa+=alturaa;
			sumae+=edada;
			system("PAUSE");
			
		}
		archivo.close();
		
		cout<<"media respecto a peso: "<<sumap/i<<endl;
		cout<<"media respecto a altura: "<<sumaa/i<<endl;
		cout<<"media respecto a edad: "<<sumae/i<<endl;
		system("Pause");
		
	}
	catch(exception& X){
		cout<<"Error al abrir el archivo"<<endl;
		system("Pause");
	}	
}
