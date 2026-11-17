#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//ESTRUCTURA OBJETO
struct objeto{
  int conto; //esto es para la tienda y la ruleta
  string nombre_objeto;
  string descripcion_objeto;
  struct objeto *proxObjeto;
};

typedef struct objeto *Tobjeto;
Tobjeto listaObjeto = NULL;

Tobjeto CrearObjeto(string nombre_objeto, string descripcion_objeto){
	Tobjeto nuevonodo_objeto;
	nuevonodo_objeto = new(struct objeto);
	nuevonodo_objeto->nombre_objeto = nombre_objeto;
  nuevonodo_objeto->descripcion_objeto = descripcion_objeto;
	nuevonodo_objeto->proxObjeto = NULL;
	return nuevonodo_objeto;
}

bool buscarObjeto(Tobjeto &listaObjeto, string nombre_objeto){
  Tobjeto aux=listaObjeto;
  while(aux!=NULL){
    if(aux->nombre_objeto==nombre_objeto){
      return true;
    }
    aux=aux->proxObjeto;
  }
  return false;
}

void AgregarFinalObjeto(Tobjeto &listaObjeto, string nombre_objeto, string descripcion_objeto){
Tobjeto aux=listaObjeto;

    if(listaObjeto==NULL){ 
      listaObjeto=CrearObjeto(nombre_objeto, descripcion_objeto);
    }else{
      while(aux->proxObjeto!=NULL){
        aux= aux->proxObjeto;
      }
      aux->proxObjeto=CrearObjeto(nombre_objeto, descripcion_objeto);
    } 

}

void ImprimirObjetos(Tobjeto &listaObjeto){
	int pos_objeto=1;
	int cont=1;
	Tobjeto aux_objeto = listaObjeto;
	if (aux_objeto == NULL){
		cout << "\nLA LISTA ESTA VACIA" << endl << endl;
	}
	else{
		cout << "\nLa Lista de Objetos es: " << endl << endl;
		while(aux_objeto != NULL){
			cout<<cont<<".-"<< "Objeto " << pos_objeto << endl;
			cout << "          Nombre: " << aux_objeto->nombre_objeto << endl;
			cout << "          Descripcion: " << aux_objeto->descripcion_objeto << endl << endl;
			aux_objeto = aux_objeto->proxObjeto;
			pos_objeto++;
			cont++;
		}
	}
}

//FUNCIONES PARA VALIDAR SI EXISTE EL MISMOS OBJETO 

string minuscula3(string &palabra){//esto es para transformar las palabra ingresadas a minusculas y ver si son iguales
  for(int i=0; i<palabra.length();i++){
    palabra[i]= tolower(palabra[i]);
  }
  return palabra;
}

bool existeMismoObjeto(Tobjeto &listaObjeto,string &nomObjeto){
Tobjeto aux=NULL;
aux=listaObjeto;
bool existe=false;
string palabraCampo;
  while(aux!=NULL){
    palabraCampo=aux->nombre_objeto;
    if(minuscula3(palabraCampo)==minuscula3(nomObjeto)){
      existe=true;
    }
    aux=aux->proxObjeto;
  }
return existe;
}
//////////////////////////////////////////////////////////




