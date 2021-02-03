//DECLARACIÓN DE LIBRERIAS
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
using namespace std;

//ESTRUCTURAS
struct tPrecioagua{
	string marcap;
	string manantialp;
	string hipercor;
	string carrefour;
	string esclat;
	string alcampo;
	string eroski;
	string consum;
	string mineralizacionp;
};

struct tComposicion{
	string marcac;
	string residuo_seco;
	string calcio;
	string sodio;
	string bicarbonato;
	string magnesio;
	string provinciac;
};

struct tConsumoProvincia{
	string comunidad;
	string anyo;
	string litros;
	string variacion_anual;
	string porcentaje;
};

//SUBPROGRAMAS
void lectura_datos1(string marcass);
void lectura_datos2(string comunidadess);
void lectura_datos3(string provinciass);
void lectura_datos4(string manantialess);
void lectura_entidad1(vector<tPrecioagua> &pantalla);
void lectura_entidad2(vector<tComposicion> &pantalla2);
void lectura_entidad3(vector<tConsumoProvincia> &pantalla3);
void buscarPreciosMercado(const vector<tPrecioagua> &fila, string id);
void mostrarPreciosMercado(const tPrecioagua& tpa);
void buscarComposionAgua(const vector<tComposicion> &fila2, string id);
void mostrarComposicionAgua(const tComposicion &tca);
void buscarProvinciaAgua(const vector<tComposicion> &resultado, string prov);
void mostrarConsumoComunidad (const vector<tConsumoProvincia> &tcp);
void buscarConsumoComunidad(const vector<tConsumoProvincia> &resultado2, string comunidad_consumo, string anyo_consumo);
void buscarManantialAgua(const vector<tPrecioagua> &fila3, string manantialdp);
void mostrarManantialAgua(const tPrecioagua &tma);
void compararConsumoAgua(const vector<tConsumoProvincia> &compar_compo, string com1, string com2);
void Agregar_entidad1(tPrecioagua &tpa, vector <tPrecioagua> &vtpa);
void Agregar_entidad2(tComposicion &tca, vector <tComposicion> &vtcp);
void Agregar_entidad3 (tConsumoProvincia &tcpa, vector <tConsumoProvincia> &vtcpa);
///void Modificar_entidad1 (string buscar, vector <tPrecioagua> fila, int &pos);
///void eliminarEntidad1(tPrecioagua &tpa, vector<tPrecioagua> &tpane);
///void mostrarComunidadAgua(const tConsumoProvincia &tcpa);
///void compararConsumoAgua(const vector<tConsumoProvincia> &compar_compo, string com1, string com2);

//PROGRAMMA PRINCIPAL
int main(){
    system("color F2");
    system("Mode CON cols=150 lines=100");

//DECLARACION VARIABLES
	vector<tPrecioagua> ent1;
	vector<tComposicion> ent2;
	vector<tConsumoProvincia> ent3;
	tPrecioagua tpa;
	tComposicion tca;
	tConsumoProvincia tcpa;
    int opcion, op, op2, pos;
	string bus,agua, caso7, caso31, caso32, manantial,manantialess, provinciass, comunidadess, marcass;
//Se recomienda mirar la funcionalidad "zero" para conocer los listados disponibles.
	do{
//Llamada de los subprogramas de lectura de las entidades.
        lectura_entidad1(ent1);
		lectura_entidad2(ent2);
		lectura_entidad3(ent3);
		cout<<"Propiedades, Composicion y Consumo de agua envasada en Espanya.\n";
		cout<<">>Seleccione una de las opciones: \n0- Mostrar las marcas, coumidades, provincias, manantiales disponibles para seleccionar.\n1- Mostar precio en diferentes supermercados del agua seleccionada.\n2- Mostrar composicion del agua seleccionada.\n3- Mostar consumo de agua embotellada por comunidad y anyo."<<endl;
		cout<<"4- Buscar marca de agua por provincia. \n5- Mostrar marca de agua a partir de su manantial.\n6- Agregar nueva informacion en cualquier de las entidades."<<endl;
		cout<<"7- Salir del programa.\n\nSeleccion: ";
		cin>>opcion;
		system("cls");
        //MENU de Opciones principal
		switch(opcion){
            case 0:
                cout <<"Propiedades, Composicion y Consumo de agua envasada en Espanya.\n";
                cout <<">>Seleccione una de las opciones:\n";
                cout << "\n1-Marcas \n2-Comunidades \n3-Provincias  \n4-Manantiales: " << endl;
                cin >> op;
                switch(op){
                case 1:
                lectura_datos1(marcass);
                break;
                case 2:
                lectura_datos2(comunidadess);
                break;
                case 3:
                lectura_datos3(provinciass);
                break;
                case 4:
                lectura_datos4(manantialess);
                break;
                }
                break;
            case 1:
				cout<<">>Introduzca una marca de agua embotellada: ";
				cin.ignore();
				getline(cin, agua);
				buscarPreciosMercado(ent1, agua);
				break;
			case 2:
				cout<<">>Introduzca una marca de agua embotellada: ";
				cin.ignore();
				getline(cin, agua);
				buscarComposionAgua(ent2, agua);
				break;
			case 3:
				cout<<"Introduzca un anyo a buscar: ";
				cin>>caso32;
				cout<<"Introduzca una comunidad autonoma: ";
				cin.ignore();
				getline(cin, caso31);
				buscarConsumoComunidad(ent3, caso31, caso32);
				break;
			case 4:
				cout<<"Introduzca la provincia: ";
				cin.ignore();
				getline(cin, caso7);
				buscarProvinciaAgua(ent2, caso7);
				break;
			case 5:
				cout<<"Introdueix un manantial: ";
				cin.ignore();
				getline(cin, manantial);
				buscarManantialAgua(ent1, manantial);
				break;
            case 6:
                cout <<"Propiedades, Composicion y Consumo de agua envasada en Espanya.\n";
                cout <<">>Seleccione una de las opciones:\n";
                cout << "\n1-Agregar informacion entidad 1 \n2-Agregar informacion entidad 2 \n3-Agregar informacion entidad 3: " << endl;
                cin >> op2;
                switch(op2){
                case 1:
                Agregar_entidad1 (tpa, ent1);
                break;
                case 2:
                Agregar_entidad2 (tca, ent2);
                break;
                case 3:
                Agregar_entidad3 (tcpa, ent3);
                break;
                }
                break;
            case 7:
                cout << "...FIN DE PROGRAMMA..." << endl;
                system("pause");
                break;
            default:
                cout<< "...ERROR..."<< endl;
                system("pause");
                break;
        }
	}while(opcion != 7);
	return 0;
}

//DESARROLLO DE LOS SUBPROGRAMAS
//Lectura de las marcas
void lectura_datos1(string marcass){
   ifstream file01 ("Datos1.csv");
    marcass;
    string line = "";
    getline(file01, line);
     cout << "\n>>Marcas disopnibles: "<<endl;
    while(getline(file01, line)){
        string marcass;
        stringstream ss (line);
		char delim = ';';
        getline(ss, marcass, delim);
        cout<< marcass << endl;
    }
    cout <<endl;
}
//Lectura de las comunidades
void lectura_datos2(string comunidadess){
    ifstream file02 ("Datos2.csv");
    comunidadess;
    string line = "";
    getline(file02, line);
    cout << "\n>>Comunidades disponibles: "<<endl;
    while(getline(file02, line)){
        string comunidaddess;
        stringstream ss (line);
		char delim = ';';
        getline(ss, comunidadess, delim);
        cout<< comunidadess << endl;
    }
    cout <<endl;
}
//Lectura de las provincias
void lectura_datos3(string provinciass){
    ifstream file03 ("Datos3.csv");
    provinciass;
    string line = "";
    getline(file03, line);
    cout << "\n>>Provincias disponibles: "<<endl;
    while(getline(file03, line)){
        string provinciass;
        stringstream ss (line);
		char delim = ';';
        getline(ss, provinciass, delim);
        cout << provinciass << endl;
    }
    cout <<endl;
}
//Lectura de los manantiales
void lectura_datos4(string manantialess){
    ifstream file04 ("Datos4.csv");
    manantialess;
    string line = "";
    getline(file04, line);
    cout << "\n>>Manantiales disponibles: "<<endl;
    while(getline(file04, line)){
        string manantialess;
        stringstream ss (line);
		char delim = ',';
        getline(ss,manantialess, delim);
        cout << manantialess << endl;
    }
    cout <<endl;
}
//Lectura entidad 1
void lectura_entidad1(vector<tPrecioagua> &pantalla){
	ifstream file1("ENTIDAD1.csv");
    tPrecioagua precio_agua;
	string line = "";
	getline(file1, line);
	while(getline(file1, line)){
		tPrecioagua precio_agua;
		stringstream ss (line);
		char delim = ';';
		getline(ss, precio_agua.marcap, delim);
        getline(ss, precio_agua.manantialp, delim);
		getline(ss, precio_agua.hipercor, delim);
		getline(ss, precio_agua.carrefour, delim);
		getline(ss, precio_agua.esclat, delim);
		getline(ss, precio_agua.alcampo, delim);
		getline(ss, precio_agua.eroski, delim);
		getline(ss, precio_agua.consum, delim);
		getline(ss, precio_agua.mineralizacionp, delim);
		pantalla.push_back(precio_agua);
		//cout<<line<<endl;

	}
}
//Lectura entidad 2
void lectura_entidad2(vector<tComposicion> &pantalla2){
	ifstream file2("ENTIDAD2.csv");
	tComposicion composicion_agua;
	string line = "";
	getline(file2, line);
	while(getline(file2, line)){
		tComposicion composicion_agua;
		stringstream ss (line);
		char delim = ';';
		getline(ss, composicion_agua.marcac, delim);
		getline(ss, composicion_agua.residuo_seco, delim);
		getline(ss, composicion_agua.calcio, delim);
		getline(ss, composicion_agua.sodio, delim);
		getline(ss, composicion_agua.bicarbonato, delim);
		getline(ss, composicion_agua.magnesio, delim);
		getline(ss, composicion_agua.provinciac, delim);
		pantalla2.push_back(composicion_agua);
		//cout<<line<<endl;
	}
}
//Lectura entidad 3
void lectura_entidad3(vector<tConsumoProvincia> &pantalla3){
	ifstream file3("ENTIDAD3.csv");
	tConsumoProvincia consumo;
	string line = "";
	getline(file3, line);
	while(getline(file3, line)){
		tConsumoProvincia consumo;
		stringstream ss (line);
		char delim = ';';
		getline(ss, consumo.comunidad, delim);
		getline(ss, consumo.anyo, delim);
		getline(ss, consumo.litros, delim);
		getline(ss, consumo.variacion_anual, delim);
		getline(ss, consumo.porcentaje, delim);
		pantalla3.push_back(consumo);
		//cout<<line<<endl;
	}
}
//Impresion de datos por pantalla y fichero "funcion 1"
void mostrarPreciosMercado(const tPrecioagua& tpa){
	cout<<"\n\n>Manantial: "<<tpa.manantialp<<endl;
	cout<<"\nPRECIOS EN DIFERENTES SUPERMERCADOS"<<endl;
	cout<<"\n>>>Precio Hipercor: "<<tpa.hipercor<<endl;
	cout<<"\n>>>Precio Carrefour: "<<tpa.carrefour<<endl;
	cout<<"\n>>>Precio Esclat: "<<tpa.esclat<<endl;
	cout<<"\n>>>Precio Alcampo: "<<tpa.alcampo<<endl;
	cout<<"\n>>>Precio Eroski: "<<tpa.eroski<<endl;
	cout<<"\n>>>Precio Consum: "<<tpa.consum<<endl;
	cout<<"\n>Este agua esta considerada como: "<<tpa.mineralizacionp<<"\n\n"<<endl;

	ofstream fout;
	fout.open("Informe.txt", ios::app);
	fout<<"\n\n>Manantial: "<<tpa.manantialp<<endl;
	fout<<"\nPRECIOS EN DIFERENTES SUPERMERCADOS"<<endl;
	fout<<"\n>>>Precio Hipercor: "<<tpa.hipercor<<endl;
	fout<<"\n>>>Precio Carrefour: "<<tpa.carrefour<<endl;
	fout<<"\n>>>Precio Esclat: "<<tpa.esclat<<endl;
	fout<<"\n>>>Precio Alcampo: "<<tpa.alcampo<<endl;
	fout<<"\n>>>Precio Eroski: "<<tpa.eroski<<endl;
	fout<<"\n>>>Precio Consum: "<<tpa.consum<<endl;
	fout<<"\n>Este agua esta considerada como: "<<tpa.mineralizacionp<<"\n\n"<<endl;
	fout.close();		//ENTIDAD 1
}
//Busqueda "case1"
void buscarPreciosMercado(const vector<tPrecioagua> &fila, string id){
	bool encontrado = false;
	int elem = fila.size();
	int cont = 0;
	while(cont < elem && !encontrado){
		tPrecioagua precio = fila[cont];
		if(precio.marcap == id){
			mostrarPreciosMercado(precio);
			encontrado = true;
		}
		cont++;
	}	//ENTIDAD 1
}
//Impresion de datos por pantalla y fichero "funcion 2"
void mostrarComposicionAgua(const tComposicion &tca){
	cout<<"\n\nMarca selecionada: "<<tca.marcac<<endl;
	cout<<"COMPOSICION DEL AGUA"<<endl;
	cout<<"\n>>>Residuo Seco: "<<tca.residuo_seco<<endl;
	cout<<"\n>>>Calcio: "<<tca.calcio<<endl;
	cout<<"\n>>>Sodio: "<<tca.sodio<<endl;
	cout<<"\n>>>Bicarbonato: "<<tca.bicarbonato<<endl;
	cout<<"\n>>>Magnesio: "<<tca.magnesio<<endl;
	cout<<"\n>>>PROCEDENCIA DEL AGUA: "<<tca.provinciac<<"\n\n"<<endl;

    ofstream fout;
    fout.open("Informe.txt", ios::app);
    fout<<"\n\nMarca selecionada: "<<tca.marcac<<endl;
	fout<<"COMPOSICION DEL AGUA"<<endl;
	fout<<"\n>>>Residuo Seco: "<<tca.residuo_seco<<endl;
	fout<<"\n>>>Calcio: "<<tca.calcio<<endl;
	fout<<"\n>>>Sodio: "<<tca.sodio<<endl;
	fout<<"\n>>>Bicarbonato: "<<tca.bicarbonato<<endl;
	fout<<"\n>>>Magnesio: "<<tca.magnesio<<endl;
	fout<<"\n>>>PROCEDENCIA DEL AGUA: "<<tca.provinciac<<"\n\n"<<endl;
	fout.close();		//ENTIDAD 2
}
//Busqueda "case 2"
void buscarComposionAgua(const vector<tComposicion> &fila2, string id){
	bool encontrado = false;
	int elem = fila2.size();
	int cont = 0;
	while(cont < elem && !encontrado){
		tComposicion residuo = fila2[cont];
		if(residuo.marcac == id){
			mostrarComposicionAgua(residuo);
			encontrado = true;
        }
		cont++;
	}	//ENTIDAD 2
}
//Impresion de datos por pantalla y fichero "case 4"
void mostrarProvinciaAgua(const tComposicion &fuente){
	cout<<"\n>"<<fuente.marcac<<endl;
	ofstream fout;
	fout.open("Informe.txt", ios::app);
	fout<<"\n>"<<fuente.marcac<<"\n\n"<<endl;	//ENTIDAD 2
}
//Busqueda "case 4"
void buscarProvinciaAgua(const vector<tComposicion> &resultado, string prov){
	int elem = resultado.size();
    bool encontrado = false;
    int cont = 0;
    while(cont < elem){
        tComposicion localizacion = resultado[cont];
        if(localizacion.provinciac == prov){
            encontrado = true;
            mostrarProvinciaAgua(localizacion);
            }
        cont++;
        }
    cout<<endl;//ENTIDAD 2
    }
//Impresion de datos por pantalla y fichero "funcion 3"
void mostrarConsumoComunidad(const tConsumoProvincia &tcp){
    cout<<"\n\nComunidad selecionada: "<<tcp.comunidad <<endl;
	cout<<"CONSUMO AGUA DEL ESTADO O COMUNIDAD"<<endl;
	cout<<"\n>>>Anyo: "<<tcp.anyo<<endl;
	cout<<"\n>>>Litros: "<<tcp.litros<<endl;
	cout<<"\n>>>Variacion anual: "<<tcp.variacion_anual<<endl;
	cout<<"\n>>>Porcentaje: "<<tcp.porcentaje<<"%"<<"\n\n"<<endl;

    ofstream fout;
    fout.open("Informe.txt", ios::app);
    fout<<"\n\nComunidad selecionada: "<<tcp.comunidad <<endl;
	fout<<"CONSUMO AGUA DEL ESTADO O COMUNIDAD"<<endl;
	fout<<"\n>>>Anyo: "<<tcp.anyo<<endl;
	fout<<"\n>>>Litros: "<<tcp.litros<<endl;
	fout<<"\n>>>Variacion anual: "<<tcp.variacion_anual<<endl;
	fout<<"\n>>>Porcentaje: "<<tcp.porcentaje<<"%"<<"\n\n"<<endl;
	fout.close();	//ENTIDAD 3
}
//Busqueda "case 3"
void buscarConsumoComunidad(const vector<tConsumoProvincia> &resultado2, string comunidad_consumo, string anyo_consumo){
	bool encontrado = false;
	int elem = resultado2.size();
	int cont = 0;
	while(cont < elem and !encontrado){
		tConsumoProvincia consumos = resultado2[cont];
		if(consumos.comunidad == comunidad_consumo and consumos.anyo == anyo_consumo){
			mostrarConsumoComunidad(consumos);
			encontrado = true;
		}
		cont++;
	}
}//ENTIDAD 3

//Impresion de datos por pantalla y fichero "case 5"
void mostrarManantialAgua(const tPrecioagua &tma){
	cout<<"Manantial: "<<tma.marcap<<"\n\n"<<endl;
	ofstream fout;
	fout.open("Informe.txt", ios::app);
	fout<<"\n>"<<tma.marcap<<"\n\n"<<endl;
}
//Busqueda "case 5"
void buscarManantialAgua(const vector<tPrecioagua> &fila3, string manantialdp){
	int elem = fila3.size();
	int cont = 0;
	while(cont < elem){
		tPrecioagua manantial_encontrado = fila3[cont];
		if(manantial_encontrado.manantialp == manantialdp){
			mostrarManantialAgua(manantial_encontrado);
		}
		cont++;
	}
}
// Añadir datos entidad 1 "case6"
void Agregar_entidad1 (tPrecioagua &tpa, vector <tPrecioagua> &vtpa){
ofstream f;
f.open("ENTIDAD1.csv", ios::out | ios::app);
cout << "Marca: "<<endl;
cin >> tpa.marcap;
f << tpa.marcap <<';';
cout << "Manantial: " << endl;
cin >> tpa.manantialp;
f <<tpa.manantialp<<';';
cout << "Hipercor: " << endl;
cin >> tpa.hipercor;
f <<tpa.hipercor<<';';
cout << "Carrefour: " << endl;
cin >> tpa.carrefour;
f <<tpa.carrefour<<';';
cout << "Esclat " << endl;
cin >> tpa.esclat;
f<<tpa.esclat<<';';
cout << "Alcampo: " << endl;
cin >> tpa.alcampo;
f<<tpa.alcampo<<';';
cout << "Eroski: " << endl;
cin >> tpa.eroski;
f<<tpa.eroski<<';';
cout << "Consum: " << endl;
cin >> tpa.consum;
f<<tpa.consum<<';';
cout << "Mineralizacion: " << endl;
cin >> tpa.mineralizacionp;
f << tpa.mineralizacionp << ';' <<endl;
vtpa.push_back(tpa);
f.close();
}
// Añadir datos entidad 2 "case6"
void Agregar_entidad2 (tComposicion &tca, vector <tComposicion> &vtcp){
ofstream f;
f.open("ENTIDAD2.csv", ios::out | ios::app);
cout << "Marca: "<<endl;
cin >> tca.marcac;
f << tca.marcac <<';';
cout << "Residuo seco: " << endl;
cin >> tca.residuo_seco;
f <<tca.residuo_seco<<';';
cout << "Calcio: " << endl;
cin >> tca.calcio;
f <<tca.calcio<<';';
cout << "Sodio: " << endl;
cin >> tca.sodio;
f <<tca.sodio<<';';
cout << "Bicarbonato: " << endl;
cin >> tca.bicarbonato;
f<<tca.bicarbonato<<';';
cout << "Magnesio: " << endl;
cin >> tca.magnesio;
f<<tca.magnesio<<';';
cout << "Provincia: " << endl;
cin >> tca.provinciac;
f<<tca.provinciac<<';';
vtcp.push_back(tca);
f.close();
}
// Añadir datos entidad 3 "case6"
void Agregar_entidad3 (tConsumoProvincia &tcpa, vector <tConsumoProvincia> &vtcpa){
ofstream f;
f.open("ENTIDAD3.csv", ios::out | ios::app);
cout << "Comunidad: "<<endl;
cin >> tcpa.comunidad;
f << tcpa.comunidad <<';';
cout << "Anyo: " << endl;
cin >> tcpa.anyo;
f <<tcpa.anyo<<';';
cout << "Litros: " << endl;
cin >> tcpa.litros;
f <<tcpa.litros<<';';
cout << "Variacion anual: " << endl;
cin >> tcpa.variacion_anual;
f <<tcpa.variacion_anual<<';';
cout << "Porcentage: " << endl;
cin >> tcpa.porcentaje;
f<<tcpa.porcentaje<<';';
vtcpa.push_back(tcpa);
f.close();

}

///Intentos de implementar funcionalidades extras al programma (Mejoras).

/// Funcionalidad modificar
/*void Modificar_entidad1 (string buscar, vector <tPrecioagua> fila, int &pos){
int i =0;
bool trobat = false;
cout << "Busqueda: ";
cin >> buscar;
while(i<fila.size() && !trobat){
    if(fila[i].marcap == buscar){
        trobat=true;
}
else{i++;}
}
if(trobat){
        pos=i;
ofstream f;
f.open("ENTIDAD1.csv", ios::app);
for(int i=0;i<fila.size();i++){
    if (fila[i].marcap == buscar){

cout << "Marca: "<<endl;
cin >> fila[i].marcap;
f << fila[i].marcap << ';';
cout << "Manantial: " << endl;
cin >> fila[i].manantialp;
f << fila[i].manantialp << ';';
cout << "Hipercor: " << endl;
cin >> fila[i].hipercor;
f <<fila[i].hipercor<< ';';
cout << "Carrefour: " << endl;
cin >> fila[i].carrefour;
f <<fila[i].carrefour<< ';';
cout << "Esclat " << endl;
cin >> fila[i].esclat;
f <<fila[i].esclat<< ';';
cout << "Alcampo: " << endl;
cin >> fila[i].alcampo;
f <<fila[i].alcampo<< ';';
cout << "Eroski: " << endl;
cin >> fila[i].eroski;
f <<fila[i].eroski<< ';';
cout << "Consum: " << endl;
cin >> fila[i].consum;
f <<fila[i].consum<< ';';
cout << "Mineralizacion: " << endl;
cin >> fila[i].mineralizacionp;
f << fila[i].mineralizacionp << ';';
f.close();
}
}
}
else {i++;}
}
*/
/// Funcionalidad eliminar
/*void eliminarEntidad1(tPrecioagua &tpa, vector<tPrecioagua> &tpane){
	string marca;
	ifstream file1;
	file1.open("ENTIDAD1.csv");
	ofstream f;
	f.open("Auxiliar1.csv", ios::in);
	cout<<"Introduzca una marca a eliminar los datos: ";
	cin.ignore();
	getline(cin, marca);
	while(file1 and !file1.eof()){
		tPrecioagua tpa;
		if(marca == tpa.marcap){

		}
		else{
			f<<tpa.marcap<<',';
			f<<tpa.manantialp<<',';
			f<<tpa.hipercor<<',';
			f<<tpa.carrefour<<',';
			f<<tpa.esclat<<',';
			f<<tpa.alcampo<<',';
			f<<tpa.eroski<<',';
			f<<tpa.consum<<',';
			f<<tpa.mineralizacionp<<','<<endl;
			tpane.push_back(tpa);
		}
	}
	f.close();
}
*/
///Funcionalidad comparacion entidad 3
/*void mostrarComunidadAgua(const tConsumoProvincia &tcpa){
}

void compararConsumoAgua(const vector<tConsumoProvincia> &compar_compo, string com1, string com2){
	int elem = compar_compo.size();
	int cont = 0;
	while(cont < elem){
		tConsumoProvincia autonomia = compar_compo[cont];
		if(autonomia.comunidad == com1 and autonomia.comunidad == com2){
			mostrarComunidadAgua(autonomia);
		}
		cont++;
	}
}*/
///Funcionalidad comparacion precios entidad 1
/*void compararPrecioAgua(const vector<tPrecioagua> &comparativa1, vector<tComparativaPrecio> &definitiva, string marca1, string marca2){
    int elem = comparativa1.size();
    int cont = 0;
    float precio_medio, precio_medio1, precio_medio2;
    tComparativaPrecio datos_marca1;
    tComparativaPrecio datos_marca2;
    while(cont < elem){
        tPrecioagua precio_comparado = comparativa1[cont];    //tPrecioagua es una tupla
        if(marca1 == precio_comparado.marcap){
            precio_medio = (precio_comparado.hipercor + precio_comparado.carrefour + precio_comparado.esclat + precio_comparado.alcampo + precio_comparado.eroski + precio_comparado.consum)/6;
            datos_marca1.marca = marca1;
            datos_marca1.precio_medio = precio_medio;
        }
        if(marca2 == precio_comparado.marcap){
            precio_medio = (precio_comparado.hipercor + precio_comparado.carrefour + precio_comparado.esclat + precio_comparado.alcampo + precio_comparado.eroski + precio_comparado.consum)/6;
            datos_marca2.marca = marca2;
            datos_marca2.precio_medio = precio_medio;
        }
    }
    if(datos_marca1.precio_medio > datos_marca2.precio_medio){
        cout<<datos_marca1.marca<<endl;
        cout<<datos_marca1.precio_medio<<endl;
    }
}*/

