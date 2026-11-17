#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Libreria_Objetos.h"
using namespace std;

//ESTRUCTURA HABILIDADES
struct habilidades{
  string nombre_habilidad;
  string tipo_habilidad;
  int conth; //esto es para la tienda y la ruleta
  int Cont_objetos=0;
  int valor_ataque;
  int valor_defensa;
  int valor_velocidad;
  struct objeto *proxObjeto;
  struct habilidades* proxhabilidades;
};

typedef struct habilidades* habilidad;
int contador_objetos = 0;
int contador_habilidades = 0; 


habilidad crearNodoHabilidad(string n, string t , int val_at, int val_def,int val_velo, int obj){ //int cont_obj
  habilidad hab = new habilidades();
  hab->nombre_habilidad = n;
  hab->tipo_habilidad = t;
  hab->valor_ataque = val_at;
  hab->valor_defensa = val_def;
  hab->valor_velocidad = val_velo;
  hab->Cont_objetos = obj;
  hab->proxObjeto = NULL;
  hab->proxhabilidades = NULL;
return hab;
}

habilidad agregarFinalHabilidad(habilidad &H, string n, string t , int val_at,int val_def,int val_velo, int obj ){
  if (H == NULL){
    H = crearNodoHabilidad(n, t , val_at, val_def,val_velo, obj);
    return H;
  }else{
    habilidad aux = H;
    while (aux->proxhabilidades != NULL){
      aux = aux->proxhabilidades;    
    }
    aux->proxhabilidades = crearNodoHabilidad(n, t , val_at, val_def,val_velo, obj);
    return aux->proxhabilidades;
  }
}

//FUNCIONES MODIFICAR PARA EL MODIFICAR PRINCIPAL QUE ESTA EN LA LIBRERIA DE CASA

void modificarNombreHabilidad(habilidad& hab, const string& nuevoNombre) {
  hab->nombre_habilidad = nuevoNombre;
}

void modificarTipoHabilidad(habilidad& hab, const string& nuevoTipo) {
  hab->tipo_habilidad = nuevoTipo;
}

void modificarValAtaque(habilidad& hab, int nuevoValA){
  hab->valor_ataque = nuevoValA;
}

void modificarValDefensa(habilidad& hab, int nuevoValD){
  hab->valor_defensa = nuevoValD;
}

void modificarValVelocidad(habilidad& hab, int nuevoValV){
  hab->valor_velocidad = nuevoValV;
}
//////////////////////////////////////////////////////////////////////////////////


//FUNCIONES PARA VALIDAR SI EXISTE EL MISMA HABILIDAD

string minuscula2(string &palabra){//esto es para transformar las palabra ingresadas a minusculas y ver si son iguales
   for(int i=0; i<palabra.length();i++){
      palabra[i]= tolower(palabra[i]);
   }
   return palabra;
}

bool existeMismaHabilidad(habilidad &H,string &nomHabilidad){
habilidad aux=NULL;
aux=H;
bool existe=false;
string palabraCampo;
  while(aux!=NULL){
    palabraCampo=aux->nombre_habilidad;
    if(minuscula2(palabraCampo)==minuscula2(nomHabilidad)){
      existe=true;
    }
    aux=aux->proxhabilidades;
  }
  return existe;
}
////////////////////////////////////////////////////////////

