#include <iostream>
#include <sstream>
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <ctime>
//#include "Libreria_Casa_Colegio.h"
//#include "Libreria_Habilidades.h"
//#include "Libreria_Objetos.h"
#include "LibreriaEstudiantes.h"
using namespace std;



void gotoxy(int x, int y){
  HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X=x;
  dwPos.Y=y;
  SetConsoleCursorPosition(hcon,dwPos);
}

int volverStringInt (string palabra){
  char buffer[300];
  for(int j=0; j<palabra.length();j++){
    buffer[j]=palabra[j];
  }
  return(atoi(buffer));
}

void fechaDia(int dia, int mes, int anio) {
  string palabra;
  time_t tiempoActual = std::time(nullptr);
  tm* fecha = std::localtime(&tiempoActual);
  dia = fecha->tm_mday;
  cout<<"dia"<<dia<<endl;
  mes = fecha->tm_mon + 1;
  cout<<"mes"<<mes<<endl;
  anio = fecha->tm_year + 1900; 
  cout<<"anio"<<anio<<endl;
}

//IMPRIMIR RONDA

void titulo() {
    SetConsoleOutputCP(CP_UTF8); // Establecer el código de página de la consola en UTF-8
    cout << " "<<endl;
    cout << "                    ███████╗████████╗███████╗██████╗░███╗░░██╗░█████╗░██╗░░░░░░██████╗" << std::endl;
    cout << "                    ██╔════╝╚══██╔══╝██╔════╝██╔══██╗████╗░██║██╔══██╗██║░░░░░██╔════╝" << std::endl;
    cout << "                    █████╗░░░░░██║░░░█████╗░░██████╔╝██╔██╗██║███████║██║░░░░░╚█████╗░" << std::endl;
    cout << "                    ██╔══╝░░░░░██║░░░██╔══╝░░██╔══██╗██║╚████║██╔══██║██║░░░░░░╚═══██╗" << std::endl;
    cout << "                    ███████╗░░░██║░░░███████╗██║░░██║██║░╚███║██║░░██║███████╗██████╔╝" << std::endl;
    cout << "                    ╚══════╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝╚═╝░░╚══╝╚═╝░░╚═╝╚══════╝╚═════╝░" << std::endl;

}

void ImprimirRonda(){
    //R
  gotoxy(95,2); cout << char(95); gotoxy(96,2); cout << char(95);
  gotoxy(94,3); cout << char(124); gotoxy(95,3); cout << char(95); gotoxy(96,3); cout << char(95); gotoxy(97,3); cout << char(124);
  gotoxy(94,4); cout << char(124); gotoxy(96,4); cout << char(92);
    //O
	gotoxy(99,2); cout << char(95); gotoxy(100,2); cout << char(95);
	gotoxy(98,3); cout << char(124); gotoxy(101,3); cout << char(124);
	gotoxy(98,4); cout << char(124); gotoxy(99,4); cout << char(95); gotoxy(100,4); cout << char(95); gotoxy(101,4); cout << char(124); 
	//N
	gotoxy(102,3); cout << char(124); gotoxy(103,3); cout << char(92); gotoxy(105,3); cout << char(124);
	gotoxy(102,4); cout << char(124); gotoxy(104,4); cout << char(92); gotoxy(105,4); cout << char(124);
	//D
  gotoxy(107,2); cout << char(95); gotoxy(108,2); cout << char(95);
  gotoxy(106,3); cout << char(124); gotoxy(109,3); cout << char(92);
  gotoxy(106,4); cout << char(124); gotoxy(107,4); cout << char(95); gotoxy(108,4); cout << char(95); gotoxy(109,4); cout << char(47);
    //A
  gotoxy(111,2); cout << char(95); gotoxy(112,2); cout << char(95);
  gotoxy(110,3); cout << char(124); gotoxy(111,3); cout << char(95); gotoxy(112,3); cout << char(95); gotoxy(113,3); cout << char(124);
  gotoxy(110,4); cout << char(124); gotoxy(113,4); cout << char(124);
}

void Imprimir1(){
  //1
  gotoxy(116,3); cout << char(47); gotoxy(117,3); cout << char(124);
  gotoxy(116,4); cout << char(95); gotoxy(117,4); cout << char(124); gotoxy(118,4); cout << char(95);  
}
void Imprimir2(){
  //2
  gotoxy(116,2); cout << char(95); gotoxy(117,2); cout << char(95);
  gotoxy(116,3); cout << char(95); gotoxy(117,3); cout << char(95); gotoxy(118,3); cout << char(124);
  gotoxy(115,4); cout << char(124); gotoxy(116,4); cout << char(95); gotoxy(117,4); cout << char(95);
}
void Imprimir3(){
  //3
  gotoxy(116,2); cout << char(95); gotoxy(117,2); cout << char(95);
  gotoxy(116,3); cout << char(95); gotoxy(117,3); cout << char(95); gotoxy(118,3); cout << char(124);
  gotoxy(116,4); cout << char(95); gotoxy(117,4); cout << char(95); gotoxy(118,4); cout << char(124);
}

void ImprimirEstudiante(int col){
    //E
    gotoxy(col,6); cout << char(95); gotoxy(col+1,6); cout << char(95);
    gotoxy(col-1,7); cout << char(124); gotoxy(col,7); cout << char(95); gotoxy(col+1,7); cout << char(95);
    gotoxy(col-1,8); cout << char(124); gotoxy(col,8); cout << char(95); gotoxy(col+1,8); cout << char(95);
    //S
    gotoxy(col+4,6); cout << char(95); gotoxy(col+5,6); cout << char(95);
    gotoxy(col+3,7); cout << char(124); gotoxy(col+4,7); cout << char(95); gotoxy(col+5,7); cout << char(95);
    gotoxy(col+4,8); cout << char(95); gotoxy(col+5,8); cout << char(95); gotoxy(col+6,8); cout << char(124);
    //T
    gotoxy(col+7,6); cout << char(95); gotoxy(col+8,6); cout << char(95); gotoxy(col+9,6); cout << char(95);
    gotoxy(col+8,7); cout << char(124); gotoxy(col+8,8); cout << char(124);
    //U
    gotoxy(col+10,7); cout << char(124); gotoxy(col+13,7); cout << char(124);
	gotoxy(col+10,8); cout << char(124); gotoxy(col+11,8); cout << char(95); gotoxy(col+12,8); cout << char(95); gotoxy(col+13,8); cout << char(124); 
	//D
    gotoxy(col+15,6); cout << char(95); gotoxy(col+16,6); cout << char(95);
    gotoxy(col+14,7); cout << char(124); gotoxy(col+17,7); cout << char(92);
    gotoxy(col+14,8); cout << char(124); gotoxy(col+15,8); cout << char(95); gotoxy(col+16,8); cout << char(95); gotoxy(col+17,8); cout << char(47);
    //I
    gotoxy(col+18,6); cout << char(95); gotoxy(col+19,6); cout << char(95); gotoxy(col+20,6); cout << char(95); gotoxy(col+19,7); cout << char(124);
    gotoxy(col+18,8); cout << char(95); gotoxy(col+19,8); cout << char(124); gotoxy(col+20,8); cout << char(95);
    //A
    gotoxy(col+22,6); cout << char(95); gotoxy(col+23,6); cout << char(95);
    gotoxy(col+21,7); cout << char(124); gotoxy(col+22,7); cout << char(95); gotoxy(col+23,7); cout << char(95); gotoxy(col+24,7); cout << char(124);
    gotoxy(col+21,8); cout << char(124); gotoxy(col+24,8); cout << char(124);
    //N
	gotoxy(col+25,7); cout << char(124); gotoxy(col+26,7); cout << char(92); gotoxy(col+28,7); cout << char(124);
	gotoxy(col+25,8); cout << char(124); gotoxy(col+27,8); cout << char(92); gotoxy(col+28,8); cout << char(124);
	//T
    gotoxy(col+29,6); cout << char(95); gotoxy(col+30,6); cout << char(95); gotoxy(col+31,6); cout << char(95);
    gotoxy(col+30,7); cout << char(124); gotoxy(col+30,8); cout << char(124);
    //E
    gotoxy(col+33,6); cout << char(95); gotoxy(col+34,6); cout << char(95);
    gotoxy(col+32,7); cout << char(124); gotoxy(col+33,7); cout << char(95); gotoxy(col+34,7); cout << char(95);
    gotoxy(col+32,8); cout << char(124); gotoxy(col+33,8); cout << char(95); gotoxy(col+34,8); cout << char(95);   
	//1
    gotoxy(70,7); cout << char(47); gotoxy(71,7); cout << char(124);
    gotoxy(70,8); cout << char(95); gotoxy(71,8); cout << char(124); gotoxy(72,8); cout << char(95);
    //2
    gotoxy(169,6); cout << char(95); gotoxy(170,6); cout << char(95);
    gotoxy(169,7); cout << char(95); gotoxy(170,7); cout << char(95); gotoxy(171,7); cout << char(124);
    gotoxy(168,8); cout << char(124); gotoxy(169,8); cout << char(95); gotoxy(170,8); cout << char(95);   
}

void ImprimirMuneco(int col){
	gotoxy(col,9); cout << char(95); gotoxy(col+1,9); cout << char(95); gotoxy(col+2,9); cout << char(95);
	gotoxy(col-1,10); cout << char(47); gotoxy(col+3,10); cout << char(92);
	gotoxy(col-1,11); cout << char(92); gotoxy(col,11); cout << char(95); gotoxy(col+1,11); cout << char(95); gotoxy(col+2,11); cout << char(95); gotoxy(col+3,11); cout << char(47);
	gotoxy(col+1,12); cout << char(124); gotoxy(col+1,13); cout << char(124); gotoxy(col+1,14); cout << char(124); gotoxy(col+1,15); cout << char(124);
	gotoxy(col-1,13); cout << char(47); gotoxy(col+3,13); cout << char(92); gotoxy(col-2,14); cout << char(47); gotoxy(col+4,14); cout << char(92);
	gotoxy(col-1,16); cout << char(47); gotoxy(col+3,16); cout << char(92); gotoxy(col-2,17); cout << char(47); gotoxy(col+4,17); cout << char(92);
}

void ImprimirDatosEst(int col, int fil, Testudiante &est){
	gotoxy(col,fil); cout << "Nombre: " << est->nombre_estudiante;
	gotoxy(col,fil+1); cout << "Codigo: " << est->codigo_estudiante;
	gotoxy(col,fil+2); cout << "Casa: " << est->nombre_casa;
	gotoxy(col,fil+3); cout << "Energia: " << est->energia;
	gotoxy(col,fil+4); cout << "Salud: " << est->salud;
	habilidad hab = est->proxhabilidades;
	int conth=1; col=col+23;
	while (hab != NULL){
		gotoxy(col,fil); cout << "Habilidad " << conth << ": " << hab->nombre_habilidad;
		gotoxy(col,fil+1); cout << " Valor de Ataque: " << hab->valor_ataque;
		gotoxy(col,fil+2); cout << " Valor de Defensa: " << hab->valor_defensa;
    	hab = hab->proxhabilidades;
		fil=fil+4; conth++;
	}
	Tobjeto obj = est->proxObjeto;
	int conto=1; col=col+28; fil=11;
	while (obj != NULL){
		gotoxy(col,fil); cout << "Objeto " << conto << ": " << obj->nombre_objeto;
    	fil=fil+4; conto++;
    	obj = obj->proxObjeto;
	}
}

///////////////////


//DIFERENTES TIPOS DE IMPRIMIR 
void ImprimirObjetosHabCasa(Tcasa &l, int respCasaConsultar, int habConsultar){
  Tcasa aux = l;
  int contaux = 0;
  Tobjeto auxobjetos = NULL;
  while (aux != NULL) {
    contaux++;
    if (contaux == respCasaConsultar) {
      habilidad auxhab = aux->proxhabilidades;
      int conthabs = 1;
      if (auxhab == NULL){
        cout << "LA HABILIDAD NO TIENE OBJETOS" << endl;
        delay(3);
        break;
      } 
      while (auxhab != NULL) {
        if (conthabs == habConsultar){
          auxobjetos = auxhab->proxObjeto;
          int contobj = 1;
          while (auxobjetos != NULL){
            cout << contobj << ".-Objeto: " << auxobjetos->nombre_objeto << endl;
            auxobjetos = auxobjetos->proxObjeto;
            contobj++;
          }
        } 
        auxhab = auxhab->proxhabilidades;
        conthabs++; 
      }  
    }
    aux = aux->proxCasa;
  }
}

void ImprimirEstudiantesCasa(Tcasa &l, int respCasaConsultar){
  Tcasa aux = l;
  int contaux = 0;
  while (aux != NULL) {
    contaux++;
    if (contaux == respCasaConsultar) {
      Testudiante auxest = aux->proxEstudiante;
      int contest = 1;
      if (auxest == NULL){
        cout << "LA CASA NO TIENE ESTUDIANTES" << endl;
        delay(3);
        break;
      } 
      while (auxest != NULL) {
        cout << contest << ".-Estudiante: " << auxest->nombre_estudiante << endl;
        auxest = auxest->proxEstudiante;
        contest++;
      }
    }
    aux = aux->proxCasa;
  }
}

void imprimirCasa(Tcasa &l){
  Tcasa aux=NULL;
  int cont=1;
  aux=l;
  if (aux==NULL){//En caso de que el colegio se quede sin casas
    cout<<"¡EL COLEGIO ESTA VACIO!"<<endl;
  }
  while(aux!=NULL){
    cout<<cont++<<".-"<<" Nombre: "<<aux->Nombre_casa<<endl<<endl;
    cout<<"  "<<" Numero de estudiantes: "<<aux->cont_estudiante<<endl<<endl;
    cout<<"  "<<" Numero de habilidades: "<<aux->cont_habilidades<<endl<<endl;
    aux= aux->proxCasa;  
  }  
}

void imprimirtodo (Tcasa &l, Tcolegio &l2){
Tcasa auxl=NULL;
Tobjeto auxobjetos=NULL;
auxl=l;
habilidad aux=NULL;
int contc=1;
imprimirColegio(l2);
  while(auxl!=NULL){
    aux=NULL;
    auxobjetos=NULL;
    cout<<contc<<".-"<<" Nombre: "<<auxl->Nombre_casa<<endl<<endl;
    cout<<"  "<<" Descripcion casa: "<<auxl->descripcion_casa<<endl<<endl;
    cout<<"  "<<" Ano de fundada: "<<auxl->ano_fundada<<endl<<endl;
    cout<<"  "<<" Nombre del Director: "<<auxl->nombre_director<<endl<<endl;
    cout<<"  "<<" Numero de estudiantes: "<<auxl->cont_estudiante<<endl<<endl;
    cout<<"  "<<" Numero de habilidades: "<<auxl->cont_habilidades<<endl<<endl;
    aux=auxl->proxhabilidades;
    int conth=1;
    while (aux != NULL) {
      cout<<conth<<".-"<<" Habilidad de "<<auxl->Nombre_casa<<":"<< aux-> nombre_habilidad <<endl;
      cout<<"     "<<" Tipo de Habilidad: "<< aux-> tipo_habilidad <<endl;
      cout<<"     "<<" Valor de Ataque: "<< aux-> valor_ataque <<endl;
      cout<<"     "<<" Valor de Defensa: "<< aux-> valor_defensa <<endl;
      cout<<"     "<<" Valor de Velocidad: "<< aux-> valor_velocidad <<endl;
      cout<<"     "<<" Cantidad de Objetos: "<< aux->Cont_objetos <<endl;
      auxobjetos=aux->proxObjeto;
      int cont=1;
      while(auxobjetos != NULL){
      cout<<cont<<".-"<< "Objeto " << endl;
			cout << "          Nombre: " << auxobjetos->nombre_objeto << endl;
			cout << "          Descripcion: " << auxobjetos->descripcion_objeto << endl << endl;
			auxobjetos =auxobjetos->proxObjeto;
			cont++;
		  }
      aux = aux->proxhabilidades;
      conth++;
    }
    auxl= auxl->proxCasa; 
    contc++;
  } 
  auxl=l;
  habilidad aux_est_habilidad=NULL;
  Tobjeto   aux_est_objeto=NULL;
    while(auxl!=NULL){
      listaEstudiante=auxl->proxEstudiante;
      while(listaEstudiante!= NULL){
			cout << "       Estudiante "  << endl;
			cout << "                 Codigo: " << listaEstudiante->codigo_estudiante << endl;
			cout << "                 Nombre: " << listaEstudiante->nombre_estudiante << endl;
      cout << "                 Casa: " << listaEstudiante->nombre_casa << endl << endl;
			cout << "                 Habilidad: " << listaEstudiante->cont_hab_est << endl;
      cout << "                 objeto: " << listaEstudiante->cont_obj_est << endl;
      cout << "                 Salud: " << listaEstudiante->salud << endl;
      cout << "                 Energia: " << listaEstudiante->energia<< endl;
      cout << "                 Estatus: " << listaEstudiante->status<< endl;
	
     aux_est_habilidad=listaEstudiante->proxhabilidades;
			int conthe=1;
			while (aux_est_habilidad!=NULL){
			    cout<<conthe<<".-"<<" Habilidad nombre: "<< aux_est_habilidad-> nombre_habilidad <<endl;
      		cout<<"     "<<" Tipo de Habilidad: "<< aux_est_habilidad-> tipo_habilidad <<endl;
     			cout<<"     "<<" Valor de Ataque: "<<aux_est_habilidad-> valor_ataque <<endl;
      		cout<<"     "<<" Valor de Defensa: "<< aux_est_habilidad-> valor_defensa <<endl;
      		cout<<"     "<<" Valor de Velocidad: "<< aux_est_habilidad-> valor_velocidad <<endl;
				conthe++;
				aux_est_habilidad=aux_est_habilidad->proxhabilidades;
      }
      aux_est_objeto=listaEstudiante->proxObjeto;
	
			while (aux_est_objeto!=NULL){
			  cout<<".-"<< "Objeto " << endl;
			  cout << "          Nombre: " <<  aux_est_objeto->nombre_objeto << endl;
			  cout << "          Descripcion: " <<  aux_est_objeto->descripcion_objeto << endl << endl;
				aux_est_objeto=aux_est_objeto->proxObjeto;
      }
      listaEstudiante = listaEstudiante->proxEstudiante;
      }
      auxl= auxl->proxCasa;
    }

}

void imprimirCuadrodeTodo(Tcasa &l, Tcolegio &l2, int &fil, int &col){ 
  Tcasa auxl=NULL;
  Tobjeto aux_objeto=NULL;
  fil=1;
  auxl=l;
  habilidad aux=NULL;
  Testudiante auxest = NULL;
  gotoxy(8, fil); cout << "---------------------------------------------ESCUELA " << l2->Nombre_colegio << "-------------------------------------------" << endl;
  fil = fil+3;
  gotoxy(8, fil); cout << "------------------------------------------------------------------------------------------" << endl;
  fil = fil+1;
  gotoxy(8, fil); cout << "Casa     Habilidad     Tipo Hab. V.ataque V.defensa V.velocidad  Nomb.Obj.   Descrip.Obj. " << endl;  
  fil = fil+1;
  gotoxy(8, fil); cout << "------------------------------------------------------------------------------------------" << endl;
  while(auxl != NULL){
    fil = fil+2;
    gotoxy(8,fil); cout << auxl->Nombre_casa;
    aux=auxl->proxhabilidades;
    while (aux != NULL) {
	    gotoxy(17, fil); cout << aux->nombre_habilidad;
	    gotoxy(31, fil); cout << aux->tipo_habilidad;
	    gotoxy(41, fil); cout << aux->valor_ataque;
	    gotoxy(50, fil); cout << aux->valor_defensa;
	    gotoxy(60, fil); cout<<aux->valor_velocidad;
      aux_objeto=aux->proxObjeto;
      while(aux_objeto != NULL){
	      gotoxy(73, fil); cout << aux_objeto->nombre_objeto;
	      gotoxy(85, fil); cout << aux_objeto->descripcion_objeto;
		    aux_objeto = aux_objeto->proxObjeto;
		    fil = fil+2;
	    }
      aux = aux->proxhabilidades;
    }
    gotoxy(8, fil); cout << "------------------------------------------------------------------------------------------" << endl;
    auxl= auxl->proxCasa;
  }  
  fil = fil+4;
  gotoxy(8, fil); cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
  fil = fil+1;
  gotoxy(8, fil); cout << "Casa     Codigo Est. Estudiante    Energia Est.  Habilidad     Tipo Hab. V.ataque V.defensa V.velocidad  Nomb.Obj.   Descrip.Obj." << endl;
  fil = fil+1;
  gotoxy(8, fil); cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
  auxl=l;
  habilidad aux_est_habilidad = NULL;
  Tobjeto aux_est_objeto = NULL;
  fil = fil+2;
  while (auxl != NULL){
    auxest = auxl->proxEstudiante;
    while (auxest != NULL){
      gotoxy(8, fil); cout << auxest->nombre_casa;
      gotoxy(17, fil); cout << auxest->codigo_estudiante;
      gotoxy(29, fil); cout << auxest->nombre_estudiante;
      gotoxy(43, fil); cout << auxest->energia;
      aux_est_habilidad = auxest->proxhabilidades;
      while (aux_est_habilidad != NULL){
        gotoxy(57, fil); cout << aux_est_habilidad->nombre_habilidad;
        gotoxy(71, fil); cout << aux_est_habilidad->tipo_habilidad;
        gotoxy(81, fil); cout << aux_est_habilidad->valor_ataque;
        gotoxy(90, fil); cout << aux_est_habilidad->valor_defensa;
        gotoxy(100, fil); cout << aux_est_habilidad->valor_velocidad;
        aux_est_objeto = auxest->proxObjeto;
        while (aux_est_objeto != NULL){
          gotoxy(113, fil); cout << aux_est_objeto->nombre_objeto;
          gotoxy(125, fil); cout << aux_est_objeto->descripcion_objeto;
          aux_est_objeto=aux_est_objeto->proxObjeto;
          fil = fil+2;
        }   
        aux_est_habilidad=aux_est_habilidad->proxhabilidades;       
      }  
      gotoxy(8, fil); cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;    
      fil = fil+2;
      auxest = auxest->proxEstudiante;  
    }
    auxest = auxl->proxEstudiante;
    auxl = auxl->proxCasa;
  }   
}
/////////////////////////////////////////////////


//FUNCIONES PARA LA GESTION DEL PROGRAMA 
void BuscarCasa(Tcasa &l, int respCasaConsultar){
  Tcasa auxl=NULL;
  Tobjeto auxobjetos=NULL;
  auxl=l;
  habilidad aux=NULL;
  int pos_estudiante=1;
  Testudiante auxe = NULL; 
  int contpos = 1;
  while(auxl != NULL){
    if (contpos == respCasaConsultar){
      cout<<contpos<<".-"<<" Nombre: "<<auxl->Nombre_casa<<endl<<endl;
      cout<<"  "<<" Descripcion casa: "<<auxl->descripcion_casa<<endl<<endl;
      cout<<"  "<<" Ano de fundada: "<<auxl->ano_fundada<<endl<<endl;
      cout<<"  "<<" Nombre del Director: "<<auxl->nombre_director<<endl<<endl;
      cout<<"  "<<" Numero de estudiantes: "<<auxl->cont_estudiante<<endl<<endl;
      cout<<"  "<<" Numero de habilidades: "<<auxl->cont_habilidades<<endl<<endl;
      aux=auxl->proxhabilidades;
      int conth=1;
      while (aux != NULL) {
        cout<<conth<<".-"<<" Habilidad de "<<auxl->Nombre_casa<<":"<< aux-> nombre_habilidad <<endl;
        cout<<"     "<<" Tipo de Habilidad: "<< aux-> tipo_habilidad <<endl;
        cout<<"     "<<" Valor de Ataque: "<< aux-> valor_ataque <<endl;
        cout<<"     "<<" Valor de Defensa: "<< aux-> valor_defensa <<endl;
        cout<<"     "<<" Valor de Velocidad: "<< aux-> valor_velocidad <<endl;
        cout<<"     "<<" Cantidad de Objetos: "<< aux->Cont_objetos <<endl << endl;
        auxobjetos=aux->proxObjeto;
        ImprimirObjetos(auxobjetos);
        aux = aux->proxhabilidades;
        conth++;
      }
      auxe = auxl->proxEstudiante;
      cout << "\nLa Lista de Estudiantes es: " << endl;
      while(auxe != NULL){
        cout << "    Estudiante " << pos_estudiante << endl;
        cout << "              Codigo: " << auxe->codigo_estudiante << endl;
        cout << "              Nombre: " << auxe->nombre_estudiante << endl;
        cout << "              Casa: " << auxe->nombre_casa << endl << endl;    
        auxe = auxe->proxEstudiante;
        pos_estudiante++;
      }
    }
    contpos++;
    auxl= auxl->proxCasa; 
  }  
} 

void BuscarEstudiante(Tcasa &l, int respCasaConsultar, int estConsultar){
  Tcasa aux = l;
  int contaux = 0;
  while (aux != NULL) {
      contaux++;
      if (contaux == respCasaConsultar){
          Testudiante auxest = aux->proxEstudiante;
          int contest = 1;
          if (aux->cont_estudiante == 0){
            cout << "LA CASA NO TIENE ESTUDIANTES" << endl;
            delay(3);
            break;
          }
          else{
            while (auxest != NULL){
              if (contest == estConsultar){
                cout << "Estudiante " << contest << ":" << endl;
                cout << "        Codigo: " << auxest->codigo_estudiante << endl;
                cout << "        Nombre: " << auxest->nombre_estudiante << endl;
                cout << "        Casa: " << auxest->nombre_casa << endl;
                cout << "        Cantidad Objetos: " << auxest->cont_obj_est << endl;
                cout << "        Cantidad Habilidades: " << auxest->cont_hab_est << endl;
                habilidad auxhab=NULL;
                auxhab=auxest->proxhabilidades;
                while(auxhab!=NULL){
                  cout<<"     "<<"Nombre: "<<auxhab->nombre_habilidad<<endl;
                  cout<<"     "<<" Tipo de Habilidad: "<<auxhab-> tipo_habilidad <<endl;
                  cout<<"     "<<" Valor de Ataque: "<< auxhab-> valor_ataque <<endl;
                  cout<<"     "<<" Valor de Defensa: "<<auxhab-> valor_defensa <<endl;
                  cout<<"     "<<" Valor de Velocidad: "<< auxhab-> valor_velocidad <<endl;
                   auxhab=auxhab->proxhabilidades;
                }
                Tobjeto auxobj=NULL;
                auxobj=auxest->proxObjeto;
                while (auxobj!=NULL){
			            cout<<".-"<< "Objeto " << endl;
			            cout << "          Nombre: " <<  auxobj->nombre_objeto << endl;
			            cout << "          Descripcion: " << auxobj->descripcion_objeto << endl << endl;
				          auxobj=auxobj->proxObjeto;
                }
                break;
              }
              auxest = auxest->proxEstudiante;
              contest++;
            }
        }  
      }
      aux = aux->proxCasa;
    }
}

void BuscarHabilidad(Tcasa &l, int respCasaConsultar, int habConsultar){
    Tcasa aux = l;
    int contaux = 0;
    Tobjeto auxobjetos = NULL;
    while (aux != NULL) {
        contaux++;
        if (contaux == respCasaConsultar) {
            habilidad auxhab = aux->proxhabilidades;
            int conthabs = 1;
            if (aux->cont_habilidades == 0){
              cout << "LA CASA NO TIENE HABILIDADES" << endl;
              delay(3);
              break;
            }
            else{
              while (habConsultar > aux->cont_habilidades || habConsultar < 1) {
                cout << "El numero de habilidad ingresado no es valido." << endl;
                cout << "Indica que habilidad desea consultar: " << endl;
                cin >> habConsultar;
                validarDatos(habConsultar);
              }
              while (auxhab != NULL) {
                if (conthabs == habConsultar){
                  cout << "Habilidad " << conthabs << ":" << endl;
                  cout << "Nombre: " << auxhab->nombre_habilidad << endl;
                  cout << "Tipo: " << auxhab->tipo_habilidad << endl;
                  cout << "Valor de defensa: " << auxhab->valor_defensa << endl;
                  cout << "Valor de ataque: " << auxhab->valor_ataque << endl;
                  cout << "Valor de velocidad: " << auxhab->valor_velocidad << endl << endl;
                  auxobjetos = auxhab->proxObjeto;
                  ImprimirObjetos(auxobjetos);
                  break;
                } 
                auxhab = auxhab->proxhabilidades;
                conthabs++; 
              }
            }        
        }
        aux = aux->proxCasa;
    }
}

void BuscarObjeto(Tcasa &l, int respCasaConsultar, int habConsultar, int objConsultar){
    Tcasa aux = l;
    int contaux = 0;
    Tobjeto auxobjetos = NULL;
    while (aux != NULL) {
        contaux++;
        if (contaux == respCasaConsultar) {
            habilidad auxhab = aux->proxhabilidades;
            int conthabs = 1;
            while (habConsultar > aux->cont_habilidades || habConsultar < 1) {
              cout << "El numero de habilidad ingresado no es valido." << endl;
              cout << "Indica que habilidad desea consultar un objeto: " << endl;
              cin >> habConsultar;
              validarDatos(habConsultar);
            }
            while (auxhab != NULL) {
              if (conthabs == habConsultar){
                auxobjetos = auxhab->proxObjeto;
                int contobj = 1;
                if (auxhab->Cont_objetos == 0){
                  cout << "LA HABILIDAD NO TIENE OBJETOS" << endl;
                  delay(3);
                  break;
                }
                else{
                  while (objConsultar > auxhab->Cont_objetos || objConsultar < 1) {
                    cout << "El numero de objeto ingresado no es valido." << endl;
                    cout << "Indica que objeto desea consultar: " << endl;
                    cin >> objConsultar;
                    validarDatos(objConsultar);
                  }
                  while (auxobjetos != NULL){
                    if (contobj == objConsultar){
                      cout << "Objeto " << contobj << endl;
                      cout << "          Nombre: " << auxobjetos->nombre_objeto << endl;
                      cout << "          Descripcion: " << auxobjetos->descripcion_objeto << endl;
                      break;
                    }  
                    auxobjetos = auxobjetos->proxObjeto;
                    contobj++;
                  }
                }  
              } 
              auxhab = auxhab->proxhabilidades;
              conthabs++; 
            }

        }
        aux = aux->proxCasa;
    }
}

void ConsultarCasa(Tcasa &l){
  Tcasa aux=NULL;
  int cont=1;
  aux=l;
  if (aux==NULL){
    cout<<"EL COLEGIO ESTA VACIO"<<endl;
  }
  while(aux != NULL){
    cout << cont << ".-" << " Nombre: " << aux->Nombre_casa <<endl <<endl;
    aux= aux->proxCasa;  
    cont++;
  }  
}

void agregarHabilidades(Tcasa &l,int opcasaA){
int conthabA=1;
Tcasa auxl=NULL;
auxl=l;
  while(conthabA!=opcasaA){
    auxl=auxl->proxCasa;
    conthabA++;
  }
 preguntasHabilidades(auxl->proxhabilidades,auxl);
}

void agregarObjeto(Tcasa &l,int opcasaA, int habEl){
  int conthabA=1;
  int contobjA=1;
  int objeto;
  Tcasa auxl=NULL;
  habilidad auxhabilidad=NULL;
  auxl=l;
  while(conthabA!=opcasaA){
    auxl=auxl->proxCasa;
    conthabA++;
  }
  while (habEl > auxl->cont_habilidades || habEl < 1) {
    cout << "El numero de habilidad ingresado no es valido." << endl;
    cout << "Indica que habilidad desea agregarle un objeto: " << endl;
    cin >> habEl;
    validarDatos(habEl);
  }
  auxhabilidad=auxl->proxhabilidades;
  while(contobjA!=habEl){
    auxhabilidad=auxhabilidad->proxhabilidades;
    contobjA++;
  }
  cout<<"Cuantos objetos desea agregar a esta habilidad: "<< endl;
  cin>> objeto;
  validarDatos(objeto);
  preguntasObjetos(auxhabilidad->proxObjeto,auxhabilidad,objeto);

}

void gestionCasa(Tcolegio &escuela, Tcasa &puntcasa){
  Tcolegio auxescuela=NULL;
  auxescuela=escuela;
  Tcasa auxpuntcasa=NULL;
  auxpuntcasa=puntcasa;
  int opCasa = 0;
  int agregarop2 = 0;
  while (agregarop2<6){
    cout<<"      GESTION CASA      "<<endl;
    cout<<"1.-Agregar informacion"<<endl;
    cout<<"2.-Modificar informacion"<<endl;
    cout<<"3.-Eliminar casa"<<endl;
    cout<<"4.-Buscar informacion"<<endl;
    cout<<"5.-Regresar"<<endl;
    cout<<"Ingrese una opcion."<<endl;
    cin>>opCasa;
    validarDatos(opCasa);
    switch(opCasa){
      case(1):{
          system("cls");
          preguntasCasa(puntcasa,escuela);
          system("cls");
      }
      break;
      case(2):{
          system("cls");
          int respCasaModificar;
          cout << "Indica el numero de la casa a modificar." << endl;
          imprimirCasa(puntcasa);
          cin >> respCasaModificar;
          validarDatos(respCasaModificar);
          if (auxescuela->cont_Casa == 0){
            cout << "EL COLEGIO NO TIENE CASAS" << endl;
            delay(3);
            break;
          }
          else{
            
            while(respCasaModificar > auxescuela->cont_Casa || respCasaModificar < 1){
              cout<<"La opcion indicada no existe."<<endl;
              cout<<"Indique nuevamente el numero de la casa a modificar."<<endl;
              cin >> respCasaModificar;
              validarDatos(respCasaModificar);
            }
            modificarCasa(puntcasa, escuela, respCasaModificar);
          }
          system("cls");
      }
      break;
      case(3):{
          system("cls");
          int respCasaEliminar;
          cout << "Indica el numero de la casa a eliminar." << endl;
          imprimirCasa(puntcasa);
          cin >> respCasaEliminar;
          validarDatos(respCasaEliminar);
          if (auxescuela->cont_Casa == 0){
            cout << "EL COLEGIO NO TIENE CASAS" << endl;
            delay(3);
            break;
          }
          else{
            while(respCasaEliminar>auxescuela->cont_Casa || respCasaEliminar < 1){
              cout<<"La opcion indicada no existe."<<endl;
              cout<<"Indique nuevamente el numero de la casa a eliminar."<<endl;
              cin >> respCasaEliminar;
              validarDatos(respCasaEliminar);
            }
            eliminarNodoCasa(puntcasa,escuela,respCasaEliminar);
            //imprimirCasa(puntcasa);
          }         
          system("cls");
      }
      break;
      case(4):{
          system("cls");
          int respCasaConsultar;
          cout << "CONSULTAR CASA" << endl << endl;                                       
          ConsultarCasa(puntcasa);
          cout << "\nIndique el numero de la casa a consultar" << endl;
          cin >> respCasaConsultar;
          validarDatos(respCasaConsultar);
          if (auxescuela->cont_Casa == 0){
            cout << "EL COLEGIO NO TIENE CASAS" << endl;
            delay(3);
            break;
          }
          else{
            while(respCasaConsultar > auxescuela->cont_Casa || respCasaConsultar < 1){
              cout<<"La opcion indicada no existe."<<endl;
              cout<<"Indique nuevamente el numero de la casa a consultar."<<endl;
              cin >> respCasaConsultar;
              validarDatos(respCasaConsultar);
            }
            BuscarCasa(puntcasa, respCasaConsultar);
            cout<< "    "<<endl;
          }         
      }
      break;
      case(5):{
          agregarop2 = 6;
      }
      break;
      default:
        cout<<"INDIQUE NUEVAMENTE LA OPCION ";
      break;
    }
  }
}

void gestionHabilidades(Tcolegio &escuela, Tcasa &puntcasa){
  int opModifHabs = 0;
  int respModifCasa;
  while (opModifHabs < 6){
    cout<<"      GESTION HABILIDADES    "<<endl;
    cout<<"1.-Ingresar nueva habilidad"<<endl;
    cout<<"2.-Modificar habilidad"<<endl;
    cout<<"3.-Eliminar habilidad"<<endl;
    cout<<"4.-Buscar habilidad"<<endl;
    cout<<"5.-Regresar"<<endl;
    cout<<"Ingrese una opcion."<<endl;
    cin>>opModifHabs;
    validarDatos(opModifHabs);
    switch(opModifHabs){
      case(1):{
        ConsultarCasa(puntcasa);
        cout<<"En que casa desea hacer la gestion"<<endl;
        cin>>respModifCasa;
        validarDatos(respModifCasa);
        if (escuela->cont_Casa == 0){
          cout << "EL COLEGIO NO TIENE CASAS" << endl;
          delay(3);
          break;
        }
        else{
          while (respModifCasa>escuela->cont_Casa || respModifCasa < 1){
            cout<<"La casa indicada no existe."<<endl;
            cout<<"Indique nuevamente la casa a la que desea agregarle una habilidad."<<endl;
            cin>>respModifCasa;
            validarDatos(respModifCasa);
          }
          imprimirHabilidadesCasa(puntcasa, respModifCasa);
          agregarHabilidades(puntcasa,respModifCasa);
        }
          
        system("cls");   
      }break;
      case(2):{
        ConsultarCasa(puntcasa);
        cout<<"En que casa desea hacer la gestion"<<endl;
        cin>>respModifCasa;
        validarDatos(respModifCasa);
        if (escuela->cont_Casa == 0){
          cout << "EL COLEGIO NO TIENE CASAS" << endl;
          delay(3);
          break;
        }
        else{
          while (respModifCasa>escuela->cont_Casa || respModifCasa < 1){
            cout<<"La casa indicada no existe."<<endl;
            cout<<"Indique nuevamente la casa a la que desea modificarle una habilidad."<<endl;
            cin>>respModifCasa;
            validarDatos(respModifCasa);
          }
          int habModif;
          cout << " HABILIDADES" << endl;
          cout << "Indica el numero de la habilidad a modificar" << endl;
          imprimirHabilidadesCasa(puntcasa, respModifCasa);
          cin >> habModif;
          validarDatos(habModif);
          BuscarHabilidad(puntcasa, respModifCasa, habModif); 
          modificarCasaHabilidad(puntcasa,respModifCasa, habModif);
        }     
        system("cls");
      }break;
      case(3):{
        ConsultarCasa(puntcasa);
        if (escuela->cont_Casa == 0){
          cout << "EL COLEGIO NO TIENE CASAS" << endl;
          delay(3);
          break;
        }
        else{
          cout<<"Indique la casa a la que desea modificarle una habilidad."<<endl;
          cin>>respModifCasa;
          while (respModifCasa>escuela->cont_Casa || respModifCasa < 1){
            cout<<"La casa indicada no existe."<<endl;
            cout<<"Indique nuevamente la casa a la que desea modificarle una habilidad."<<endl;
            cin>>respModifCasa;
            validarDatos(respModifCasa);
          }
          eliminarCamposHab(puntcasa, respModifCasa);
        }  
      }break;
      case(4):{
        ConsultarCasa(puntcasa);
        cout<<"En que casa desea hacer la gestion"<<endl;
        cin>>respModifCasa;
        validarDatos(respModifCasa);
        if (escuela->cont_Casa == 0){
          cout << "EL COLEGIO NO TIENE CASAS" << endl;
          delay(3);
          break;
        }
        else{
          while (respModifCasa > escuela->cont_Casa){
            cout<<"La casa indicada no existe."<<endl;
            cout<<"Indique nuevamente la casa a la que desea consultar una habilidad."<<endl;
            cin>>respModifCasa;
            validarDatos(respModifCasa);
          }
          int habConsultar;
          cout << " HABILIDADES" << endl << endl;              
          imprimirHabilidadesCasa(puntcasa, respModifCasa);
          cout << "\nIndique el numero de la habilidad a consultar" << endl;
          cin >> habConsultar;
          validarDatos(habConsultar);
          BuscarHabilidad(puntcasa, respModifCasa, habConsultar);
          cout<< "    "<<endl;
        }        
      }break;
      case(5):{ 
        opModifHabs = 6;  
      }break;
      default:
        cout<<"INDIQUE NUEVAMENTE LA OPCION ";
      break;
    }
  }
}

void gestionObjetos(Tcolegio &escuela, Tcasa &puntcasa){
  int habEl;
  int respModifCasa;
  int opModifObjs = 0;
  while (opModifObjs!=5){
    cout<<"      GESTION OBJETOS     "<<endl;
    cout<<"1.-Ingresar nuevo objeto"<<endl;
    cout<<"2.-Modificar objeto"<<endl;
    cout<<"3.-Eliminar objeto"<<endl;
    cout<<"4.-Buscar objeto"<<endl;
    cout<<"5.-Regresar"<<endl;
    cout<<"Ingrese una opcion."<<endl;
    cin>>opModifObjs;
    validarDatos(opModifObjs);
    if (opModifObjs<5){
      imprimirCasa(puntcasa);
      cout<<"En que casa desea hacer la gestion"<<endl;
      cin>>respModifCasa;
      validarDatos(respModifCasa);
      if (escuela->cont_Casa == 0){
        cout << "EL COLEGIO NO TIENE CASAS" << endl;
        delay(3);
        break;
      }else{
        while (respModifCasa>escuela->cont_Casa || respModifCasa < 1){
          cout<<"La casa indicada no existe."<<endl;
          cout<<"Indique nuevamente la casa a la que desea agregarle a una habilidad un objeto."<<endl;
          cin>>respModifCasa;
          validarDatos(respModifCasa);
        }
        cout<<"Indique en que habilidad quiere hacer la gestion de objetos"<<endl;
        imprimirHabilidadesCasa(puntcasa,respModifCasa);
        cin>>habEl;
        validarDatos(habEl);
      }     
    }
    switch(opModifObjs){
      case(1):{
          agregarObjeto(puntcasa, respModifCasa, habEl);
      }
      break;
      case(2):{
          modificarObjeto(puntcasa, respModifCasa, habEl);
          system("cls");
      }
      break;
      case(3):{
        imprimirObjetoUnaCasa(puntcasa, habEl,respModifCasa);
        eliminarCamposObj(puntcasa, habEl, respModifCasa);
        system("cls");
          
      }
      break;
      case(4):{
          int objConsultar;
          cout << "OBJETOS" << endl << endl;
          ImprimirObjetosHabCasa(puntcasa, respModifCasa, habEl);
          cout << "\nIndique el numero del objeto a consultar" << endl;
          cin >> objConsultar;
          validarDatos(objConsultar);
          BuscarObjeto(puntcasa, respModifCasa, habEl, objConsultar);
          cout<< "    "<<endl;
      }
      break;
      case(5):{
      }
      break;
      default:
        cout<<"INDIQUE NUEVAMENTE LA OPCION ";
      break;
    }
  }       
}

void gestionEstudiantes(Tcolegio &escuela, Tcasa &puntcasa){
   int opEst = 0;
   int respModifCasa;
   while (opEst<5){
    cout<<"      GESTION ESTUDIANTES      "<<endl;
    cout<<"1.-Agregar estudiante"<<endl;
    cout<<"2.-Modificar estudiante"<<endl;
    cout<<"3.-Eliminar estudiante"<<endl;
    cout<<"4.-Buscar estudiante"<<endl;
    cout<<"5.-Regresar"<<endl;
    cout<<"Ingrese una opcion."<<endl;
    cin>>opEst;
    validarDatos(opEst);
    if (opEst!=1 && opEst<5){
      imprimirCasa(puntcasa);
      cout<<"Selecciona la casa en la que se encuentra el estudiante"<<endl;
      cin>>respModifCasa;
      validarDatos(respModifCasa);
      if (escuela->cont_Casa == 0){
        cout << "EL COLEGIO NO TIENE CASAS" << endl;
        delay(3);
        break;
      }
      else{
        while(respModifCasa > escuela->cont_Casa){
          cout<<"La opcion indicada no existe."<<endl;
          cout<<"Indique nuevamente el numero de la casa que se encuentra el estudiante."<<endl;
          cin >> respModifCasa;
          validarDatos(respModifCasa);
        }
      }   
    }
    
    switch(opEst){
        case(1):{
             preguntasEstudiantes(puntcasa,escuela);
            //preguntasEstudiantes1(puntcasa,escuela);
            //system("cls");
        }
        break;
        case(2):{
            string nuevoNombreEst;
            int numModifEst;
            cout<<"Indica el estudiante a modificar: "<<endl;
            ImprimirEstudiantesCasa(puntcasa, respModifCasa);
            cin>>numModifEst;
            validarDatos(numModifEst);
            ModificarCasaEstudiante(puntcasa, respModifCasa, numModifEst);
            system("cls");
        }
        break;
        case(3):{
            int estEliminar;
            cout<<"Indica que estudiante desea eliminar de la casa: "<<endl;
            ImprimirEstudiantesCasa(puntcasa, respModifCasa);
            cin>>estEliminar;
            validarDatos(estEliminar);
            eliminarEstudiante(puntcasa, respModifCasa, estEliminar);
            system("cls");
        }
        break;
        case(4):{
            int estConsultar;
            cout << "ESTUDIANTES" << endl << endl;
            ImprimirEstudiantesCasa(puntcasa, respModifCasa);
            cout << "Indique el numero del estudiante a consultar" << endl;
            cin >> estConsultar;  
            validarDatos(estConsultar);                   
            BuscarEstudiante(puntcasa, respModifCasa, estConsultar);
            cout<< "    "<<endl;
        }
        break;
        case(5):{
        }
        break;
        default:
          cout<<"INDIQUE NUEVAMENTE LA OPCION ";
        break;
    }
    }
}
///////////////////////////////////////////////////////////////////


//FALTA LECTURA DE ARCHIVOS ESTUDIANTES

// LECTURA DE ARCHIVOS

bool archivo_existe(string nombre){
	ifstream archivo(nombre.c_str());
	return archivo.good();
}

void LecturaArchivoEstudiante(Tcasa &l, Tcolegio &l2,string nomArchEstudiante ){
  Tcasa auxcasa=NULL;
  auxcasa=l;
  Testudiante auxEst=NULL;
  string nomEst, nomCasaEst;
  int valD, valA, valV,knuts,galeones;
  string nomH, tipoH;
  string palabraHab,palabraObj,palabraEst;
  string nombre_objeto,descripcion_objeto;
  int contObj=0;
  int codigo,energia,salud;
  int contEst=0;
  int conthab=0;
  string palabra="";
  int cont,cont2,cont3;
  string textoArchivo;
  ifstream archivoEstudiante(nomArchEstudiante);
   
  while(getline(archivoEstudiante,textoArchivo)){
    for(int i=0; i<textoArchivo.length();i++){
      if(textoArchivo[i] ==','){
        if(palabra=="est"){
          palabraEst="est";
          cont=0;
        }
        if((palabraEst=="est")&&(cont!=0)){
          contEst++;
          if(contEst==1){
            nomEst=palabra;
          }
          if(contEst==2){
            codigo=volverStringInt(palabra);
          }
          if(contEst==3){
            knuts=volverStringInt(palabra);
          }
          if(contEst==4){
            galeones=volverStringInt(palabra);
          }
          if(contEst==5){
            energia=volverStringInt(palabra);
          }
          if(contEst==6){
            salud=volverStringInt(palabra);
          }
          if(contEst==7){
            nomCasaEst=palabra;
            auxcasa=l;
            contEst=0;
            palabraEst="";
            while(auxcasa->Nombre_casa!=nomCasaEst){
              auxcasa=auxcasa->proxCasa;
            }
            auxcasa->cont_estudiante++;
            l2->cont_Estudiante++;
            auxEst=AgregarFinalEstudiante(auxcasa->proxEstudiante,codigo,nomEst,nomCasaEst,energia,salud,knuts,galeones);
          }
        } 
       
        if(palabra=="hab"){
          palabraHab="hab";
          cont2=0;
        }
        if((palabraHab=="hab")&&(cont2!=0)){
          conthab++;
          if (conthab==1){
            nomH=palabra;
          }
          if(conthab==2){
            tipoH=palabra;
          }
          if(conthab==3){
            valA=volverStringInt(palabra);
          }
          if(conthab==4){
            valD=volverStringInt(palabra);
          }
          if(conthab==5){
            conthab=0;
            palabraHab="";
            auxEst->cont_hab_est++;
            valV=volverStringInt(palabra);
            agregarFinalHabilidad(auxEst->proxhabilidades,nomH,tipoH,valA,valD,valV,0);
          }
        }
          
        if(palabra=="obj"){
          palabraObj="obj";
          cont3=0;
        }
        if((palabraObj=="obj")&&(cont3!=0)){
          contObj++;
          if(contObj==1){
            nombre_objeto=palabra;
          }
          if(contObj==2){
            contObj=0;
            palabraObj="";
            descripcion_objeto=palabra;
            auxEst->cont_obj_est++;
            AgregarFinalObjeto(auxEst->proxObjeto,nombre_objeto,descripcion_objeto);
          }
        }
        if(palabra=="habesp"){
          agregarFinalHabilidadEspecial(auxEst->proxHabEsp);
        }
        cont++;
        cont2++;
        cont3++;
        palabra="";  
      }else{
        palabra=palabra+textoArchivo[i];
      }   
    }
  }
}

void LecturaArchivobjetos(Tcasa &l, string nomArchObjetos){
  Tcasa auxcasa=NULL;
  auxcasa=l;
  habilidad auxhab=NULL;
  auxhab=auxcasa->proxhabilidades;
  string nombre_objeto,descripcion_objeto;
  bool buenHab=false;
  bool buenCasa=false;
  int contObj=0;
  string textoArchivo,nomCasa,nomHab;
  string palabraObj="";
  ifstream archivoObjetos(nomArchObjetos);
  
  while(getline(archivoObjetos,textoArchivo)){
    for(int i=0; i<textoArchivo.length();i++){
      if(textoArchivo[i]==','){
        contObj++;
        if(contObj==1){
          nomCasa=palabraObj;
        }
        if(contObj==2){
          nomHab=palabraObj;
        }
        if(contObj==3){
          nombre_objeto=palabraObj;
        }
        if(contObj==4){
          contObj=0;
          buenHab=false;
          buenCasa=false;
          descripcion_objeto=palabraObj;
          while((buenCasa==false)||(buenHab==false)){
            if(nomCasa==auxcasa->Nombre_casa){
              buenCasa=true;
              if(nomHab==auxhab->nombre_habilidad){
                buenHab=true;
                auxhab->Cont_objetos++;
                AgregarFinalObjeto(auxhab->proxObjeto,nombre_objeto,descripcion_objeto);
              }else{
                auxhab=auxhab->proxhabilidades;
              }
            }else{
              auxcasa=auxcasa->proxCasa;
              auxhab=auxcasa->proxhabilidades;
            }
          }
        }
        palabraObj="";
      }else{
        palabraObj=palabraObj+textoArchivo[i];
      }
    }
  }
}

void LecturaArchivoHabilidades(Tcasa &l, string nomArchHabilidades){
  Tcasa auxcasa=NULL;
  auxcasa=l;
  int valD, valA, valV;
  int cont_hab=0;
  string nomH, tipoH,nomCasa;
  string textoArchivo;
  string palabraHab="";
  ifstream archivoHabilidades(nomArchHabilidades);
 
  while(getline(archivoHabilidades,textoArchivo)){
    for(int i=0; i<textoArchivo.length();i++){
      if(textoArchivo[i] ==','){
        cont_hab++;
        if(cont_hab==1){
          nomCasa=palabraHab;
        }
        if(nomCasa==auxcasa->Nombre_casa){
          if (cont_hab==2){
            nomH=palabraHab;
          }
          if(cont_hab==3){
            tipoH=palabraHab;
          }
          if(cont_hab==4){
            valA=volverStringInt(palabraHab);
          }
          if(cont_hab==5){
            valD=volverStringInt(palabraHab);
          }
          if(cont_hab==6){
            cont_hab=0;
            auxcasa->cont_habilidades++;
            valV=volverStringInt(palabraHab);
            agregarFinalHabilidad(auxcasa->proxhabilidades,nomH,tipoH,valA,valD,valV,0);
          }
        }else{
          auxcasa=auxcasa->proxCasa;
        }
        palabraHab="";
      }else{
        palabraHab=palabraHab+textoArchivo[i];
      }
    }
  } 
}

void LecturaArchivoCasa(Tcasa &l, Tcolegio &l2, string nomArchCasa){//PARA QUE LAS PALABRAS SE SEPAREN CORRECTAMENTE LOS ARCHIVOS TIENEN
  string casa,desCasa,nomDir;                   //QUE TERMINAR EN COMA ASI(casa1,casa.rosada,1993,los.corales,)
  int anoCasa;
  int cont=0;
  string palabra="";
  string textoArchivo;
  ifstream archivoCasa(nomArchCasa);
  while(getline(archivoCasa,textoArchivo)){
    for(int i=0; i<textoArchivo.length();i++){
      if(textoArchivo[i] ==','){//Esto es para separar las palabras del sting
        cont++;
        if(cont==1){
          casa=palabra;
        }
        if (cont==2){
          desCasa=palabra;
        }
        if(cont==3){
          anoCasa=volverStringInt(palabra);
        }
        if(cont==4){
          nomDir=palabra;
          cont=0;
          agregarFinalcasa(l,l2,casa,desCasa,anoCasa,nomDir);
        }
        palabra="";  
      }else{
        palabra=palabra+textoArchivo[i];
      }   
    }
  }
}

void LecturaArchivoEscuela(Tcolegio &l2, string nomArchEscuela){
  int antEscuela,cpEscuela;
  string nomEscuela,dirEscuela;
  string textoArchivo;
  int cont=0;
  string palabra="";
  ifstream archivoColegio(nomArchEscuela);
  while(getline(archivoColegio,textoArchivo)){
    for(int i=0; i<textoArchivo.length();i++){
      if(textoArchivo[i] ==','){//Esto es para separar las palabras del sting
        cont++;
        if(cont==1){
          nomEscuela=palabra;
          
        }
        if (cont==2){
          dirEscuela=palabra;
          
        }
        if(cont==3){
          antEscuela=volverStringInt(palabra);
        }
        if(cont==4){
          cpEscuela=volverStringInt(palabra);
          l2=crearcolegio(nomEscuela, dirEscuela,antEscuela,cpEscuela);
        }
        palabra="";  
      }else{
        palabra=palabra+textoArchivo[i];
      }   
    }
  }
}
////////////////////////////////////////////

//GUARDAR INFORMARCION ESTRUCTURA

void GuardarInformacionEscuela(Tcolegio colegio, string nomArchEscuela){
  ofstream archivo(nomArchEscuela);
	archivo<<colegio->Nombre_colegio<<","<<endl;
  archivo<<colegio->Direccion<<","<<endl;
  archivo<<colegio->Antiguedad<<","<<endl;
  archivo<<colegio->Codigo_Postal<<","<<endl;
	archivo.close();
}

void GuardarInformacionCasa(Tcasa casa, string nomArchCasa){
  Tcasa aux=NULL;
  aux=casa;
  ofstream archivo(nomArchCasa);
	  while(aux!=NULL){
      archivo<<aux->Nombre_casa<<","<<endl;
      archivo<<aux->descripcion_casa<<","<<endl;
      archivo<<aux->ano_fundada<<","<<endl;
      archivo<<aux->nombre_director<<","<<endl;
      aux=aux->proxCasa;
    }
  archivo.close();
}

void GuardarInformacionHabilidades(Tcasa casa, string nomArchHabilidades){
  Tcasa aux=NULL;
  aux=casa;
  habilidad auxHab=NULL;
  ofstream archivo(nomArchHabilidades);
	  while(aux!=NULL){
      auxHab=aux->proxhabilidades;
      while(auxHab!=NULL){
        archivo<<aux->Nombre_casa<<","<<endl;
        archivo<<auxHab->nombre_habilidad<<","<<endl;
        archivo<<auxHab->tipo_habilidad<<","<<endl;
        archivo<<auxHab->valor_ataque<<","<<endl;
        archivo<<auxHab->valor_defensa<<","<<endl;
        archivo<<auxHab->valor_velocidad<<","<<endl;
        auxHab=auxHab->proxhabilidades;
      }
      aux=aux->proxCasa;
    }
  archivo.close();
}

void GuardarInformacionObjetos(Tcasa casa, string nomArchObjetos){
  Tcasa aux=NULL;
  aux=casa;
  habilidad auxHab=NULL;
  Tobjeto auxObj=NULL;
  ofstream archivo(nomArchObjetos);
	  while(aux!=NULL){
      auxHab=aux->proxhabilidades;
      while(auxHab!=NULL){
        auxObj=auxHab->proxObjeto;
        while(auxObj!=NULL){
          archivo<<aux->Nombre_casa<<","<<endl;
          archivo<<auxHab->nombre_habilidad<<","<<endl;
          archivo<<auxObj->nombre_objeto<<","<<endl;
          archivo<<auxObj->descripcion_objeto<<","<<endl;
          auxObj=auxObj->proxObjeto;
        }
        auxHab=auxHab->proxhabilidades;
      }
      aux=aux->proxCasa;
    }
  archivo.close();
}

void GuardarInformacionEstudiante(Tcasa casa, string nomArchEstudiante){
  Tcasa aux=NULL;
  aux=casa;
  Testudiante auxEst=NULL;
  habilidad auxHab=NULL;
  Tobjeto auxObj=NULL;
  THabEsp auxHabEsp=NULL;
  ofstream archivo(nomArchEstudiante);
	  while(aux!=NULL){
      auxEst=aux->proxEstudiante;
      while(auxEst!=NULL){
        archivo<<"est,"<<endl;
        archivo<<auxEst->nombre_estudiante<<","<<endl;
        archivo<<auxEst->codigo_estudiante<<","<<endl;
        archivo<<auxEst->knuts<<","<<endl;
        archivo<<auxEst->galeones<<","<<endl;
        archivo<<auxEst->energia<<","<<endl;
        archivo<<auxEst->salud<<","<<endl;
        archivo<<aux->Nombre_casa<<","<<endl;
        auxHab=auxEst->proxhabilidades;
        auxObj=auxEst->proxObjeto;
        while(auxHab!=NULL){
          archivo<<"hab"<<","<<endl;
          archivo<<auxHab->nombre_habilidad<<","<<endl;
          archivo<<auxHab->tipo_habilidad<<","<<endl;
          archivo<<auxHab->valor_ataque<<","<<endl;
          archivo<<auxHab->valor_defensa<<","<<endl;
          archivo<<auxHab->valor_velocidad<<","<<endl;
          auxHab=auxHab->proxhabilidades; 
        }
        while(auxObj!=NULL){
          archivo<<"obj"<<","<<endl;
          archivo<<auxObj->nombre_objeto<<","<<endl;
          archivo<<auxObj->descripcion_objeto<<","<<endl;
          auxObj=auxObj->proxObjeto;
        }
      
        auxHabEsp=auxEst->proxHabEsp;
        while(auxHabEsp!=NULL){
          archivo<<"habesp"<<","<<endl;
          auxHabEsp=auxHabEsp->proxHabEsp;
        }
        auxEst=auxEst->proxEstudiante;
      }
      aux=aux->proxCasa;
    }
  archivo.close();
}

////////////////////////////////////////////


//TIENDA Y RULETA 

int CalculoDeKnuts(int valorGaleones){
  int valorKnuts;
  valorKnuts = (60*valorGaleones);
  return valorKnuts;
}

void Tienda(Tcasa &l){
  int pos_estudiante=0; int contpos=0; int compra;
  int respCasa; int respEst; int op=0;
  while (op != 2){
    cout << "\n----------------------TIENDA----------------------" << endl;
    cout << "       1. Hacer una compra" << endl;
    cout << "       2. Salir" << endl;
    cout << "       Indique la accion a realizar: ";
    cin >> op;
    switch(op){
      case(1):{
        Tcasa auxl=NULL; auxl=l; 
        cout << "\nIndique la casa del estudiante que desea hacer una compra: " << endl;
        ConsultarCasa(auxl);
        cin >> respCasa;
        cout << "\nIndique al estudiante que desea hacer una compra: " << endl;
        ImprimirEstudiantesCasa(auxl, respCasa);
        cin >> respEst;
        system("cls");
        while(auxl != NULL){
          contpos++;
          if (contpos == respCasa){
            Testudiante auxe = NULL; 
            auxe = auxl->proxEstudiante;
            while(auxe != NULL){
              pos_estudiante++;
              if (pos_estudiante == respEst){
                int col=10; int fil=5;
                gotoxy(col,fil); cout << "Nombre del Estudiante: " << auxe->nombre_estudiante;
                col=90;
                gotoxy(col,fil); cout << "Monedas:"; 
                fil=6;
                gotoxy(col,fil); cout << "     Galeones: " << auxe->galeones;
                fil=7;
                gotoxy(col,fil); cout << "     Knuts: " << auxe->knuts; 
                fil=9; col=63;
                gotoxy(col,fil); cout << "TIENDA";
                habilidad auxh=NULL; 
                auxh=auxe->proxhabilidades;
                fil=11; int cont=0;
                while (auxh != NULL){
                  cont++;
                  if ((cont % 2) == 0){ //si cont es par imprime a la derecha
                    col=70; 
                    gotoxy(col,fil); cout << cont << ". Habilidad: " << auxh->nombre_habilidad;
                    fil=fil+1; 
                    gotoxy(col,fil); cout << "   Precio: 10 Galeones";
                    fil=fil+2;
                  }
                  else{ //sino imprime a la izquierda
                    col=40;
                    gotoxy(col,fil); cout << cont << ". Habilidad: " << auxh->nombre_habilidad;
                    fil=fil+1; 
                    gotoxy(col,fil); cout << "   Precio: 10 Galeones";
                    fil=fil-1;
                  }
                  auxh->conth = cont;
                  auxh = auxh->proxhabilidades;
                }
                Tobjeto auxo=NULL;
                auxo=auxe->proxObjeto; 
                while (auxo != NULL){
                  cont++; 
                  if ((cont % 2) == 0){ //par imprime derecha
                    col=70; 
                    gotoxy(col,fil); cout << cont << ". Objeto: " << auxo->nombre_objeto;
                    fil=fil+1;
                    gotoxy(col,fil); cout << "   Precio: 2 Galeones";
                    fil=fil+2;
                  }
                  else{ //impar imprime izquierda
                    col=40; 
                    gotoxy(col,fil); cout << cont << ". Objeto: " << auxo->nombre_objeto;
                    fil=fil+1;
                    gotoxy(col,fil); cout << "   Precio: 2 Galeones";  
                    fil=fil-1;                   
                  }
                  auxo->conto = cont;
                  auxo=auxo->proxObjeto;
                }
                fil=fil+2; col=10;
                gotoxy(col,fil); cout << "Indique lo que desea comprar: ";
                cin >> compra;
                habilidad aux2h=NULL;
                aux2h=auxe->proxhabilidades;
                while (aux2h != NULL){ //se consigue la hab y se le resta los 10G
                  if (compra == aux2h->conth){
                    if (auxe->galeones >= 10){
                      auxe->galeones = auxe->galeones - 10; 
                      auxe->knuts = CalculoDeKnuts(auxe->galeones);
                      agregarFinalCopiaHabilidad(aux2h, auxe->proxhabilidades);
                      auxe->cont_hab_est++;
                      fil=fil+1; 
                      gotoxy(col,fil); cout << "Compra exitosa";
                      delay(3);
                    }
                    else{
                      fil=fil+1;
                      gotoxy(col,fil); cout << "Usted no tiene la cantidad necesaria para hacer la compra";
                      delay(3);
                    }
                    break; 
                  }
                  aux2h = aux2h->proxhabilidades;
                }
                Tobjeto aux2o=NULL;
                aux2o=auxe->proxObjeto;
                while (aux2o != NULL){//se consigue el obj y se le resta los 2G
                  if (compra == aux2o->conto){
                    if (auxe->galeones >= 2){
                      auxe->galeones = auxe->galeones - 2; 
                      auxe->knuts = CalculoDeKnuts(auxe->galeones);
                      agregarFinalCopiaObjeto(aux2o, auxe->proxObjeto);
                      auxe->cont_obj_est++;
                      fil=fil+1; 
                      gotoxy(col,fil); cout << "Compra exitosa";
                      delay(3);
                    }
                    else{
                      fil=fil+1;
                      gotoxy(col,fil); cout << "Usted no tiene la cantidad necesaria para hacer la compra";
                      delay(3);
                    }
                    break;
                  }
                  aux2o = aux2o->proxObjeto;
                }
                system("cls");
              }   
              auxe = auxe->proxEstudiante;
            }
          }
          auxl= auxl->proxCasa; 
        }
      }
      break;
      case(2):{
        op=2;
      }
      break;
    }
  }  
}

void Ruleta(Tcasa &l, int casaEstG, Testudiante &EstGanador){
  int numRandom; int nuevoValorDeEnergia; int nuevoValorDeSalud; 
  int contGiro=6; int contposC=0; int contposE=0; int op=3;
  Tcasa auxl = l; 
  while(auxl != NULL){
    contposC++;
    if (contposC == casaEstG){
      while (op == 3){
        int col=40; int fil=3;
        gotoxy(col,fil); cout << "----------------------RULETA----------------------" << endl;
        col=10; fil=5;
        gotoxy(col,fil); cout << "Nombre del Estudiante: " <<EstGanador->nombre_estudiante;
        col=90;
        gotoxy(col,fil); cout << "Valores:"; 
        fil=6;
        gotoxy(col,fil); cout << "     Energia: " <<EstGanador->energia;
        fil=7;
        gotoxy(col,fil); cout << "     Salud: " << EstGanador->salud; 
        fil=9; col=63;
        gotoxy(col,fil); cout << "RULETA";
        fil=11; col=40;
        gotoxy(col,fil); cout << "1. 10% Energia";
        col=70;
        gotoxy(col,fil); cout << "2. 10% Salud";
        fil=13; col=40;
        gotoxy(col, fil); cout << "3. Repite Ruleta";
        col=70;
        gotoxy(col, fil); cout << "4. Habilidad Especial";
        habilidad auxh=NULL; 
        auxh=EstGanador->proxhabilidades;
        fil=15; int cont=4;
          while (auxh != NULL){
            cont++;
            if ((cont % 2) == 0){ //si cont es par imprime a la derecha
              col=70; 
              gotoxy(col,fil); cout << cont << ". Habilidad: " << auxh->nombre_habilidad;
              fil=fil+2;
            }else{ //sino imprime a la izquierda
              col=40;
              gotoxy(col,fil); cout << cont << ". Habilidad: " << auxh->nombre_habilidad;
            }
            auxh->conth = cont;
            auxh = auxh->proxhabilidades;
          }
        Tobjeto auxo=NULL;
        auxo=EstGanador->proxObjeto; 
          while (auxo != NULL){
            cont++; 
            if ((cont % 2) == 0){ //par imprime derecha
              col=70; 
              gotoxy(col,fil); cout << cont << ". Objeto: " << auxo->nombre_objeto;
              fil=fil+2;
            }else{ //impar imprime izquierda
              col=40; 
              gotoxy(col,fil); cout << cont << ". Objeto: " << auxo->nombre_objeto;                  
            }
            auxo->conto = cont;
            auxo=auxo->proxObjeto;
          }
        col=50; fil=fil+2;
        gotoxy(col, fil); cout << "LA RULETA ESTA GIRANDO...";
        col=53; fil=fil+1;
        gotoxy(col, fil); cout << "Quedan "; 
        col=60;                
          while (contGiro != 0){
            gotoxy(col, fil); cout << contGiro-- << " segundos";
            delay(1);
          }   
        numRandom = random(10);
        col=52; fil=fil+3;
        gotoxy(col, fil); cout << "Ha salido el numero " << numRandom;
        col=54; fil=fil+3;
          if (numRandom == 1){
            gotoxy(col, fil); cout << "FELICIDADES " <<EstGanador->nombre_estudiante;
            col=48; fil=fil+1;
            gotoxy(col, fil); cout << "Has ganado un 10% mas de energia";
            nuevoValorDeEnergia = (EstGanador->energia + ((EstGanador->energia*10)/100));
            EstGanador->energia = nuevoValorDeEnergia;
            delay(5);
            op=1;
            break;
          }
          if (numRandom == 2){
            gotoxy(col, fil); cout << "FELICIDADES " << EstGanador->nombre_estudiante;
            col=48; fil=fil+1;
            gotoxy(col, fil); cout << "Has ganado un 10% mas de salud";
            nuevoValorDeSalud = (EstGanador->salud + ((EstGanador->salud*10)/100));
            EstGanador->salud = nuevoValorDeSalud;
            delay(5);
            op=2;
            break;
          }
          if (numRandom == 3){
            col=40;
            gotoxy(col, fil); cout << EstGanador->nombre_estudiante << ", debes girar nuevamente la ruleta";
            delay(5);
            op=3;
            break;
          }
          if (numRandom == 4){
            THabEsp habEsp=NULL;
            habEsp = crearNodoHabEsp(20,100);
            gotoxy(col, fil); cout << "FELICIDADES " << EstGanador->nombre_estudiante;
            col=40; fil=fil+1;
            gotoxy(col, fil); cout << "Has ganado la Habilidad Especial, que consiste en";
            fil=fil+1;
            gotoxy(col, fil); cout << "restaurar tus valores de Energia (a 20) y Salud (a 100)";
            EstGanador->energia = habEsp->energia; 
            EstGanador->salud = habEsp->salud;
            agregarFinalCopiaHabEsp(habEsp, EstGanador->proxHabEsp);
            EstGanador->cont_hab_est++;
            delay(7);
            op=4;
            break;
          }
          if (numRandom > 4){
            habilidad auxh=NULL;
            auxh=EstGanador->proxhabilidades;
            while (auxh != NULL){ 
              if (numRandom == auxh->conth){//se consiguio la hab
                gotoxy(col, fil); cout << "FELICIDADES " << EstGanador->nombre_estudiante;
                col=48; fil=fil+1;
                gotoxy(col, fil); cout << "Has ganado la Habilidad " << auxh->nombre_habilidad;
                agregarFinalCopiaHabilidad(auxh, EstGanador->proxhabilidades);
                EstGanador->cont_hab_est++;
                delay(5);
                break; 
              }
              auxh = auxh->proxhabilidades;
            }
            Tobjeto auxo=NULL;
            auxo=EstGanador->proxObjeto;
            while (auxo != NULL){
              if (numRandom == auxo->conto){ //se consiguio el obj
                gotoxy(col, fil); cout << "FELICIDADES " << EstGanador->nombre_estudiante;
                col=48; fil=fil+1;
                gotoxy(col, fil); cout << "Has ganado el Objeto " << auxo->nombre_objeto;
                agregarFinalCopiaObjeto(auxo, EstGanador->proxObjeto);
                EstGanador->cont_obj_est++;
                delay(5);
                break;
              }
              auxo = auxo->proxObjeto;
            }
            op=5;
            break;
          }
      } 
      break;
    }  
    auxl = auxl->proxCasa;
  } 
}

///////////////////////////////////////////






//BATALLA 
 
void  imprimirHabObjEst(Testudiante Est){
  habilidad auxHab=Est->proxhabilidades;
  Tobjeto auxObj=Est->proxObjeto;
  THabEsp auxHabEsp=Est->proxHabEsp;
  int contHab=1;
  int contObj=1;
  int contHabEsp=1;
  
  cout<<"     "<<" NOMBRE: "<< Est->nombre_estudiante <<endl;
  cout<<"     "<<" energia: "<< Est->salud<<endl;
  cout<<"     "<<" salud: "<< Est->energia<<endl;
 


  cout<<"                     HABILIDADES Y OBJETOS DEL ESTUDIANTE PARA LA BATALLA                     "<<endl;
  while(auxHab!=NULL){
    cout<<"     "<<contHab++<<"-."<< "Habilidad de "<<auxHab->nombre_habilidad<<endl;
    cout<<"     "<<" Tipo de Habilidad: "<< auxHab-> tipo_habilidad <<endl;
    cout<<"     "<<" Valor de Ataque: "<< auxHab-> valor_ataque <<endl;
    cout<<"     "<<" Valor de Defensa: "<< auxHab-> valor_defensa <<endl;
    cout<<"     "<<" Valor de Velocidad: "<< auxHab-> valor_velocidad <<endl;
    auxHab=auxHab->proxhabilidades;
  }
  while (auxObj!=NULL){
		cout<<"     "<<contObj++<<"-."<<"Objeto " << endl;
		cout<<"     "<<"Nombre: " << auxObj->nombre_objeto << endl;
		cout<<"     "<<"Descripcion: " <<  auxObj->descripcion_objeto << endl << endl;
		auxObj=auxObj->proxObjeto;
  }
  while(auxHabEsp!=NULL){
    cout<<"     "<<contHabEsp++<<"-."<<"HABILIDAD ESPECIAL"<< endl;
    auxHabEsp=auxHabEsp->proxHabEsp;
  }

}

void EliminarHabilidadEspecial(Testudiante &Est){
  THabEsp habEliminar1=Est->proxHabEsp;
  THabEsp habEliminar2=Est->proxHabEsp;
  while(habEliminar1->proxHabEsp!=NULL){
    habEliminar1=habEliminar1->proxHabEsp;
  }
  while(habEliminar2->proxHabEsp->proxHabEsp!=NULL){
    habEliminar2=habEliminar2->proxHabEsp;
  }
  habEliminar2->proxHabEsp=NULL;
  delete(habEliminar1);
}

bool HabilidadBatalla(Tcasa casa,Testudiante EstComienza, habilidad HabEst){
  Tcasa auxcasa=casa;
  habilidad habcasa=NULL;
  Tobjeto objcasa=NULL;
  int contObj=0;
  Tobjeto auxObjEst=NULL;
  while(auxcasa->Nombre_casa!=EstComienza->nombre_casa){
    auxcasa=auxcasa->proxCasa;
  }
  habcasa=auxcasa->proxhabilidades;
  while(habcasa->nombre_habilidad!=HabEst->nombre_habilidad){
    habcasa=habcasa->proxhabilidades;
  }
  objcasa=habcasa->proxObjeto;
  if(habcasa->Cont_objetos>EstComienza->cont_obj_est){
    return false;
  }else{
    while(objcasa!=NULL){
      auxObjEst=EstComienza->proxObjeto;
      while(auxObjEst!=NULL){
        if(auxObjEst->nombre_objeto==objcasa->nombre_objeto){
          contObj++;
        }
        auxObjEst=auxObjEst->proxObjeto;
      }
      objcasa=objcasa->proxObjeto;
    }
    if(contObj>=habcasa->Cont_objetos){
      return true;
    }else{
      return false;
    }
  }
}

bool CantidadDeHabilidadesBuenas(Tcasa casa, Testudiante Est){
  int HabNOCorrectas=0;
  habilidad auxHab=Est->proxhabilidades;
  while(auxHab!=NULL){
    if(HabilidadBatalla(casa,Est,auxHab)==false){
      HabNOCorrectas++;
    }
    auxHab=auxHab->proxhabilidades;
  }
  if(HabNOCorrectas==Est->cont_hab_est){
    return false;
  }else{
    return true;
  }
}

void PreguntaHabilidadesEspeciales(Testudiante &Est,int energia, int salud){
  int opHabEsp;
  if(Est->proxHabEsp!=NULL){
    cout<<Est->nombre_estudiante<<" cuentas con habilidades especiales, las cueles aumentarian tu energia y salud a su valor original."<<endl;
    cout<<"Deseas utilizarlas. Indique 1 o 2."<<endl;
    cout<<"1.-Si."<<endl;
    cout<<"2.-No. "<<endl;
    cin>>opHabEsp;
    validarDatos(opHabEsp);
    if(opHabEsp==1){
      EliminarHabilidadEspecial(Est);
      Est->salud=salud;
      Est->energia=energia;
    }
  }
}

void Partida(Tcasa casa,Testudiante &EstComienza, Testudiante &EstContinua,int Energia,int Salud, int col, int fil){
  habilidad auxHabEstComienza=NULL;
  habilidad auxHabEstContinua=NULL;
  int HabEst;
  int contHab=1;
  bool HabBuena=false;
  int valRestar;

  ImprimirRonda();
	ImprimirEstudiante(31);
	ImprimirEstudiante(130);
	ImprimirMuneco(24);
	ImprimirMuneco(123);
  ImprimirDatosEst(33,11, EstComienza); 
  ImprimirDatosEst(132,11, EstContinua);
  fil=40; col=1;

  while(HabBuena==false){
    gotoxy(col,fil); cout<<"Indique el numero de la habilidad que desea usar esta ronda el estudiante " << EstComienza->nombre_estudiante << ": ";
    cin>>HabEst;
    validarDatos(HabEst);
    while((HabEst>EstComienza->cont_hab_est)||(HabEst==0)){
      fil=fil+2;
      gotoxy(col,fil); cout<<"El numero indicado no existe ";
      fil=fil+1;
      gotoxy(col,fil); cout<<"Indique el numero de la habilidad que desea usar esta ronda el estudiante " << EstComienza->nombre_estudiante << ": ";
      cin>>HabEst;
      validarDatos(HabEst);
    }
    auxHabEstComienza=EstComienza->proxhabilidades;
    contHab=1;
    while(contHab!=HabEst){
      auxHabEstComienza=auxHabEstComienza->proxhabilidades;
      contHab++;
    }
    if(HabilidadBatalla(casa,EstComienza,auxHabEstComienza)==true){
      HabBuena=true;
    }
  }

  if((auxHabEstComienza->tipo_habilidad=="a")||(auxHabEstComienza->tipo_habilidad=="d")){
    valRestar=((auxHabEstComienza->valor_ataque*20)/100);
    EstContinua->salud=((EstContinua->salud)-valRestar);
  }
  system("cls");
  ImprimirRonda();
	ImprimirEstudiante(31);
	ImprimirEstudiante(130);
	ImprimirMuneco(24);
	ImprimirMuneco(123);
  ImprimirDatosEst(33,11, EstComienza); 
  ImprimirDatosEst(132,11, EstContinua);
  fil=40; col=1;

  if((EstContinua->salud<=0)||(EstContinua->energia<=0)){
    gotoxy(col,fil); cout<<"El estudiante "<<EstContinua->nombre_estudiante<<" no puede defenderse, ya que no tiene energia o salud. ";
    PreguntaHabilidadesEspeciales(EstContinua,Energia,Salud);
  } 
  
  if((EstContinua->salud>0)&&(EstContinua->energia>0)){
    HabBuena=false;
    while(HabBuena==false){ 
      gotoxy(col,fil); cout<<"Indique el numero de la habilidad que desea usar esta ronda el estudiante "<<EstContinua->nombre_estudiante << ": ";
      cin>>HabEst;
      validarDatos(HabEst);
      while((HabEst>EstContinua->cont_hab_est)||(HabEst==0)){
        fil=fil+2;
        gotoxy(col,fil); cout<<"El numero indicado no existe ";
        fil=fil+1;
        gotoxy(col,fil); cout<<"Indique el numero de la habilidad que desea usar esta ronda el estudiante "<<EstContinua->nombre_estudiante << ": ";
        cin>>HabEst;
        validarDatos(HabEst);
      }
      auxHabEstContinua=EstContinua->proxhabilidades;
      contHab=1;
      while(contHab!=HabEst){
        auxHabEstContinua=auxHabEstContinua->proxhabilidades;
        contHab++;
      }
      if(HabilidadBatalla(casa,EstContinua,auxHabEstContinua)==true){
        HabBuena=true;
      }
    }
    if((auxHabEstContinua->tipo_habilidad=="a")||(auxHabEstContinua->tipo_habilidad=="d")){
      valRestar=((auxHabEstContinua->valor_defensa*20)/100);
      EstComienza->energia=((EstComienza->energia)-valRestar);
    }
  }
 
}

void LanzarMoneda(Testudiante &Est1, Testudiante &Est2,Testudiante &EstComienza, Testudiante &EstContinua){
  int Moneda;
  cout<<"EN ESTA PRIMERA RONDA SE LANZARA UNA MODENADA PARA VER QUIEN COMIENZA LA PARTIDA"<<endl;
  cout<<"Cara :"<<Est1->nombre_estudiante<<endl;
  cout<<"Sello:"<<Est2->nombre_estudiante<<endl;
  Moneda=random(2);
  if(Moneda==1){
    cout<<"La partida la comienza cara. "<<Est1->nombre_estudiante<<endl;
    EstComienza=Est1;
    EstContinua=Est2;
  }
  if(Moneda==2){
    cout<<"La partida la comienza sello. "<<Est2->nombre_estudiante<<endl;
    EstComienza=Est2;
    EstContinua=Est1;
  }
  
}

int ValidarEstudianteDespierto(Testudiante &puntEst,Tcasa &auxcasa,Tcasa &l, int NumCasaEst,int NumEst ){
  int op;
  int contEst=1;
  while(puntEst->status!="despierto"){
    contEst=1;
    cout<<"EL ESTUDIANTE "<<puntEst->nombre_estudiante<<" ESTA DURMIENDO"<<endl;
    cout<<"Indique 1 o 2."<<endl;
    cout<<"1.-Despertar estudiante."<<endl;
    cout<<"2.-Usar otro estudiante."<<endl;
    cin>>op;
    validarDatos(op);
    if(op==1){
      despertar(l,NumCasaEst,NumEst);
      cout<<"YA SE DESPERTO"<<endl;
    }
    if(op==2){
      ImprimirEstudiantesCasa(l,NumCasaEst);
      cout<<"Indique nuevamente el numero del primer estudiante que participara en la batalla."<<endl;
      cin>>NumEst;
      puntEst=auxcasa->proxEstudiante;
      while (NumEst!=contEst){
        puntEst=puntEst->proxEstudiante;
        contEst++;
      }
    }
  }
  return NumEst;
}

void seleccionarEstudiantesMenu(Tcasa auxcasa,Tcasa casa, int NumCasa, Testudiante &auxEst1, Testudiante &auxEst2){
  int NumEst1;
  int NumEst2;
  int contEst=1;
  bool MismoJugador=true;
  auxEst1=auxcasa->proxEstudiante;
  auxEst2=auxcasa->proxEstudiante;

  ImprimirEstudiantesCasa(casa,NumCasa);
  cout<<"Indique el numero del primer estudiante que participara en la batalla."<<endl;
  cin>>NumEst1;
  validarDatos(NumEst1);
  while (NumEst1!=contEst){
    auxEst1=auxEst1->proxEstudiante;
    contEst++;
  }
  NumEst1=ValidarEstudianteDespierto(auxEst1,auxcasa,casa,NumCasa,NumEst1);
  
  while(MismoJugador==true){
    auxEst2=auxcasa->proxEstudiante;
    contEst=1;
    cout<<"Indique el numero del segudo estudiante que participara en la batalla."<<endl;
    cin>>NumEst2;
    validarDatos(NumEst2);
    if(NumEst1!=NumEst2){
      MismoJugador=false;
      while (NumEst2!=contEst){
        auxEst2=auxEst2->proxEstudiante;
        contEst++;
      }
      NumEst2=ValidarEstudianteDespierto(auxEst2,auxcasa,casa,NumCasa,NumEst2);
    }else{
      cout<<"ES EL MISMO ESTUDIANTE."<<endl;
    }
  }
}

void seleccionarEstudiantesRandom(Tcasa auxcasa,Tcasa casa, int NumCasa,Testudiante &auxEst1,Testudiante &auxEst2){
  
  bool existeEst2=false;
  int NumEst1;
  int NumEst2;
  int contEst=1;
  auxEst1=auxcasa->proxEstudiante;
  auxEst2=auxcasa->proxEstudiante;


  NumEst1=random(auxcasa->cont_estudiante);
  while (NumEst1!=contEst){
    auxEst1=auxEst1->proxEstudiante;
    contEst++;
  }
  if(auxEst1->status!="despierto"){
    despertar(casa,NumCasa,NumEst1);
  }

 
  while(existeEst2!=true){
    contEst=1;
    auxEst2=auxcasa->proxEstudiante;
    NumEst2=random(auxcasa->cont_estudiante);
    if(NumEst2!=NumEst1){
      while (NumEst2!=contEst){
        auxEst2=auxEst2->proxEstudiante;
        contEst++;
      }
      if(auxEst2->status=="despierto"){
        
        existeEst2=true;
      }else{
        despertar(casa,NumCasa,NumEst2);
        existeEst2=true;
      }
    }
  }
}

int seleccionarCasaParaBatalla(Tcasa &casa, Tcolegio &cole, Tcasa &auxcasa){
  int opIngeEst;
  bool cantEst=false;
  int contCasa=1;
  int NumCasa;
  while(cantEst!=true){
    contCasa=1;
    auxcasa=casa;
    system("cls");
    imprimirCasa(casa);
    cout<<"Indique el numero de la casa en la que desea realizar la batalla."<<endl;
    cin>>NumCasa;
    while(contCasa!=NumCasa){
      auxcasa=auxcasa->proxCasa;
      contCasa++;
    }
    if(auxcasa->cont_estudiante>=2){
      cantEst=true;
      cout<<"La casa cuenta con los estudiantes adecuados para la batalla"<<endl;
    }else{
      cout<<"LA CASA NO TIENE SUFICIENTES ESTUDIANTES. MINIMO TIENE QUE TENER 2. "<<endl<<endl;
      //GUARDAR AL ESTUDIANTE QUE SE INGRESE
      cout<<"RECUERDE QUE EL ESPEJO CLARIVIDENTE ELIGE LA CASA DEL ESTUDIANTE SEGUN LO CREA MAS CONVENIENTE."<<endl;
      cout<<"POR LO QUE CABE LA POSIBILIDAD DE QUE EL ESTUDIANTE NO ENTRE EN LA CASA SELECCIONADA."<<endl<<endl;
      cout<<"Desea ingresar mas estudiantes a la escuela de magos. Indique 1 o 2:"<<endl;
      cout<<"1.-Si."<<endl;
      cout<<"2.-No."<<endl;
      cin>>opIngeEst;
      validarDatos(opIngeEst);
      if(opIngeEst==1){
        preguntasEstudiantes(casa,cole);
      }
    }
  }
  return NumCasa;
}

void GuardarInformacionBatalla(Testudiante EstComienza, Testudiante EstContinua, int puntGanador){
  int dia,mes,anio;
  ofstream archivo("archivoBatalla.txt");
	archivo<<"Identificación Estudiante 1: "<<EstComienza->codigo_estudiante<<","<<endl;
  archivo<<"Valor de energía E1: "<<EstComienza->energia<<","<<endl;
  archivo<<"Valor de salud E1: "<<EstComienza->salud<<","<<endl;
  archivo<<"Identificación Estudiante 2: "<<EstContinua->codigo_estudiante<<","<<endl;
  archivo<<"Valor de energía E2: "<<EstContinua->energia<<","<<endl;
  archivo<<"Valor de salud E2: "<<EstContinua->salud<<","<<endl;
  archivo<<"Puntaje obtenido por el ganador"<<puntGanador<<","<<endl;
  archivo<<"Identificación del ganador"<<EstComienza->codigo_estudiante<<","<<endl;
  time_t tiempoActual = std::time(nullptr);
  tm* fecha = std::localtime(&tiempoActual);
  dia = fecha->tm_mday;
  mes = fecha->tm_mon + 1;
  anio = fecha->tm_year + 1900; 
  archivo<<"Fecha de realización de la batalla: "<<endl;
  archivo<<"Dia: "<<dia<<endl;
  archivo<<"Mes: "<<mes<<endl;
  archivo<<"Anio: "<<anio<<endl;
  archivo.close();
}

void VerGanador(Tcasa &casa,int NumCasa,Testudiante &EstComienza,Testudiante &EstContinua,int puntGanador,int Energia1,int Energia2,int Salud1, int Salud2){
  habilidad habEstComienza=EstComienza->proxhabilidades;
  habilidad habEstContinua=EstContinua->proxhabilidades;

  int Est1=(EstComienza->salud+EstComienza->energia)/2;
  int Est2=(EstContinua->salud+EstContinua->energia)/2;
  int contHabEst1=0;
  int contHabEst2=0;
  int empate1=0;
  int empate2=0;
 
  if(Est1>Est2){
    cout<<"GANO "<<EstComienza->nombre_estudiante<<" FELICIDADES "<<endl;
    puntGanador=(EstComienza->energia+EstComienza->salud)-(EstContinua->energia+EstContinua->salud);
    EstContinua->energia=20;
    EstContinua->salud=20;
    EstComienza->energia=Energia1+((Energia1*10)/100);
    EstComienza->salud=Salud1+((Salud1*10)/100);
    GuardarInformacionBatalla(EstComienza,EstContinua,puntGanador);
    system("cls");
    Ruleta(casa,NumCasa,EstComienza);
  }
  if(Est1<Est2){
    cout<<"GANO "<<EstContinua->nombre_estudiante<<" FELICIDADES "<<endl;
    puntGanador=(EstContinua->energia+EstContinua->salud)-(EstComienza->energia+EstComienza->salud);
    EstContinua->energia=Energia2+((Energia2*10)/100);
    EstContinua->salud=Salud2+((Salud2*10)/100);
    EstComienza->energia=20;
    EstComienza->salud=20;
    GuardarInformacionBatalla(EstContinua,EstComienza,puntGanador);
    system("cls");
    Ruleta(casa,NumCasa,EstContinua);
  }
  if(Est1==Est2){
    while(habEstComienza!=NULL){
      empate1=empate1 + habEstComienza->valor_ataque + habEstComienza->valor_defensa + habEstComienza->valor_velocidad;
      contHabEst1++;
      habEstComienza=habEstComienza->proxhabilidades;
    }
    while(habEstContinua!=NULL){
      empate2=empate2 + habEstContinua->valor_ataque + habEstContinua->valor_defensa + habEstContinua->valor_velocidad;
      contHabEst2++;
      habEstContinua=habEstContinua->proxhabilidades;
    }
    empate1=(empate1/(contHabEst1*3));
    empate2=(empate2/(contHabEst2*3));
    if(empate1>empate2){
      cout<<"GANO "<<EstComienza->nombre_estudiante<<" FELICIDADES "<<endl;
      EstContinua->energia=20;
      EstContinua->salud=20;
      EstComienza->energia=Energia1+((Energia1*10)/100);
      EstComienza->salud=Salud1+((Salud1*10)/100);
      GuardarInformacionBatalla(EstComienza,EstContinua,puntGanador);
      system("cls");
      Ruleta(casa,NumCasa,EstComienza);
    }
    if(empate1<empate2){
      cout<<"GANO "<<EstContinua->nombre_estudiante<<" FELICIDADES "<<endl;
      EstContinua->energia=Energia2+((Energia2*10)/100);
      EstContinua->salud=Salud2+((Salud2*10)/100);
      EstComienza->energia=20;
      EstComienza->salud=20;
      GuardarInformacionBatalla(EstContinua,EstComienza,puntGanador);
      system("cls");
      Ruleta(casa,NumCasa,EstContinua);
    }
  }
}



void BatallaEstudiantes(Tcasa &casa, Tcolegio &cole){
  int col; int fil;
  Tcasa auxcasa=NULL;
  Testudiante auxEst1=NULL;
  Testudiante auxEst2=NULL;
  Testudiante EstComienza=NULL;
  Testudiante EstContinua=NULL;
  int NumCasa;
  int opEst;
  int puntGanador;

  NumCasa=seleccionarCasaParaBatalla(casa,cole,auxcasa);

  cout<<"ADVERTENCIA"<<endl;
  cout<<"Al usar la opcion random cualquier estudiante que sea elegido por el sistema y este dormido"<<endl;
  cout<<"sera despertado y dejara de generar dinero."<<endl<<endl;
  cout<<"Como desea seleccionar a los estudiantes. Indique 1 o 2."<<endl;
  cout<<"1.-Manual."<<endl;
  cout<<"2.-Random. "<<endl;
  cin>>opEst;
  validarDatos(opEst);
  if(opEst==1){
    seleccionarEstudiantesMenu(auxcasa,casa,NumCasa,auxEst1,auxEst2);
    cout<<"LOS ESTUDIANTES SELECCIONADOS SON:"<<endl;
    cout<<auxEst1->nombre_estudiante<<endl;
    cout<<auxEst2->nombre_estudiante<<endl;
  }else{
    seleccionarEstudiantesRandom(auxcasa,casa, NumCasa,auxEst1,auxEst2);
    cout<<"LOS ESTUDIANTES SELECCIONADOS SON:"<<endl;
    cout<<auxEst1->nombre_estudiante<<endl;
    cout<<auxEst2->nombre_estudiante<<endl;
  }
  
  if(CantidadDeHabilidadesBuenas(casa,auxEst1)==false){
    cout<<"El jugador "<<auxEst1->nombre_estudiante<<" elegido no cuenta con las habilidades correctas para las partida."<<endl;
    cout<<"Por ello la batalla no puede comenzar."<<endl;
    imprimirHabObjEst(auxEst1);
    imprimirHabObjEst(auxEst2);
  }
  
  if(CantidadDeHabilidadesBuenas(casa,auxEst2)==false){
    cout<<"El jugador "<<auxEst2->nombre_estudiante<<" elegido no cuenta con las habilidades correctas para las partida."<<endl;
    cout<<"Por ello la batalla no puede comenzar."<<endl;
     imprimirHabObjEst(auxEst1);
    imprimirHabObjEst(auxEst2);
  }
  system("cls");
  if((CantidadDeHabilidadesBuenas(casa,auxEst2)==true)&&(CantidadDeHabilidadesBuenas(casa,auxEst1)==true)){
    gotoxy(col, fil); LanzarMoneda(auxEst1,auxEst2,EstComienza,EstContinua);
    fil=fil+2;
    int Energia1=EstComienza->energia;
    int Energia2=EstContinua->energia;
    int Salud1=EstComienza->salud;
    int Salud2=EstContinua->salud;
    Imprimir1();
    Partida(casa,EstComienza,EstContinua,Energia2,Salud2, col, fil);
    system("cls");
    PreguntaHabilidadesEspeciales(EstComienza,Energia1,Salud1);//ESTOY HAY QUE PROBARLO CON LA TEINDA
    system("cls");
    PreguntaHabilidadesEspeciales(EstContinua,Energia2,Salud2);
     system("cls");
    if((EstComienza->energia<=0)||(EstComienza->salud<=0)||(EstContinua->salud<=0)||(EstContinua->energia<=0)){
      cout<<"LA BATALLA SE TERMINO."<<endl;
      VerGanador(casa,NumCasa,EstComienza,EstContinua,puntGanador,Energia1,Energia2,Salud1,Salud2);
    }else{
      cout<<"EN ESTA PARTIDA COMIENZA "<<EstContinua->nombre_estudiante<<endl;
      Imprimir2();
      Partida(casa,EstContinua,EstComienza,Energia1,Salud1, col, fil);
      system("cls");
      PreguntaHabilidadesEspeciales(EstContinua,Energia2,Salud2);
      system("cls");
      PreguntaHabilidadesEspeciales(EstComienza,Energia1,Salud1);
      system("cls");
      if((EstComienza->energia<=0)||(EstComienza->salud<=0)||(EstContinua->salud<=0)||(EstContinua->energia<=0)){
        cout<<"LA BATALLA SE TERMINO."<<endl;
        VerGanador(casa,NumCasa,EstComienza,EstContinua,puntGanador,Energia1,Energia2,Salud1,Salud2);
      }else{
        cout<<"EN ESTA PARTIDA COMIENZA "<<EstComienza->nombre_estudiante<<endl;
        Imprimir3();
        Partida(casa,EstComienza,EstContinua,Energia2,Salud2, col, fil);
        VerGanador(casa,NumCasa,EstComienza,EstContinua,puntGanador,Energia1,Energia2,Salud1,Salud2);
      }
    }
    
  }
  

}

/////////////////////////////////////////
void GenerarDinero(Tcasa &casa){
  Tcasa auxcasa=casa;
  int NumCasa,NumEst,op,op2;
  int contCasa=1;
  bool volverIngresar=true;
  while(volverIngresar!=false){
    imprimirCasa(casa);
    auxcasa=casa;
    contCasa=1;
    cout<<"Indique la casa del estudiantes que quiere que se despierte o se duerma."<<endl;
    cin>>NumCasa;
    while(contCasa!=NumCasa){
      auxcasa=auxcasa->proxCasa;
      contCasa++;
    }
    if(auxcasa->proxEstudiante!=NULL){
      ImprimirEstudiantesCasa(casa,NumCasa);
      cout<<"Indique el numero del estudiantes que quiere que se despierte o se duerma."<<endl;
      cin>>NumEst;
      cout<<"Indique 1 o 2"<<endl;
      cout<<"1.-Despertar"<<endl;
      cout<<"2.-Dormir"<<endl;
      cin>>op;
      validarDatos(op);
      if(op==1){
        volverIngresar=false;
        despertar(casa,NumCasa,NumEst);
      }
      if(op==2){
        volverIngresar=false;
        dormir(casa,NumCasa,NumEst);
      }
    }else{
      cout<<"LA CASA NO TIENE ESTUDIANTES"<<endl;
      cout<<"Indique 1 o 2"<<endl;
      cout<<"1.-Continuar en generar dinero."<<endl;
      cout<<"2.-Salir."<<endl;
      cin>>op2;
      validarDatos(op2);
      system("cls");
      if(op2==2){
        volverIngresar=false;
      }
    }
  }

}











int main(){
  int inicio;
  int pantalla2=0;
  int partida=0;
  int fil=1; int col=1;
  int pantalla3=0;
  string objetosop="no";
  string nomEscuela,dirEscuela;
  string Casa;
  Tcasa  puntcasa=NULL;
  Tcolegio escuela=NULL;
  string nomArchEscuela,nomArchEstudiante,nomArchCasa,nomArchObjetos,nomArchHabilidades ;

  titulo();
  cout<<endl;
  cout<<endl;
  cout<<endl;
  cout<<"                     1.-Gestion escuela de manera manual.  "<<endl;//esta tiene la funcion de lectura de archivo
  cout<<"                     2.-Gestion escuela a traves de archivos.  "<<endl;
  cout<<"                     3.-Salir de la partida."<<endl;
  cout<<"Ingrese una opcion."<<endl;
  cin>>inicio;
  validarDatos(inicio);
  system("cls");
  switch (inicio){
    case (1):{
      titulo();
      cout<<endl;
      cout<<endl;
      cout<<endl;
      //cout<<"--------------------------------------------ESCUELA--------------------------------------------"<<endl;
      PreguntasEscuela(escuela);
      system("cls");
      cout<<"Indique el nombre del archivo en donde se guandara la informacion de la escuela."<<endl;
      cout<<"El nombre no debe incluir ''.txt'' al final."<<endl;
      cin>>nomArchEscuela;
      nomArchEscuela=nomArchEscuela+".txt";
      GuardarInformacionEscuela(escuela,nomArchEscuela);
      cout<<"Indique el nombre del archivo en donde se guandara la informacion de las casas."<<endl;
      cout<<"El nombre no debe incluir ''.txt'' al final."<<endl;
      cin>>nomArchCasa;
      nomArchCasa=nomArchCasa+".txt";
      cout<<"Indique el nombre del archivo en donde se guandara la informacion de las habilidades."<<endl;
      cout<<"El nombre no debe incluir ''.txt'' al final."<<endl;
      cin>>nomArchHabilidades;
      nomArchHabilidades=nomArchHabilidades+".txt";
      cout<<"Indique el nombre del archivo en donde se guandara la informacion de las objetos."<<endl;
      cout<<"El nombre no debe incluir ''.txt'' al final."<<endl;
      cin>>nomArchObjetos;
      nomArchObjetos=nomArchObjetos+".txt";
      cout<<"Indique el nombre del archivo en donde se guandara la informacion de las estudiantes."<<endl;
      cout<<"El nombre no debe incluir ''.txt'' al final. "<<endl;
      cin>>nomArchEstudiante;
      nomArchEstudiante=nomArchEstudiante+".txt";

    }
    break;
    case (2):{
      cout<<"--------------------------------------------LECTURA DE ARCHIVOS--------------------------------------------"<<endl;
      cout<<"Indique el nombre del archivo de la escuela, sin el ''.txt'' al final."<<endl;
      cin>>nomArchEscuela;
      nomArchEscuela=nomArchEscuela+".txt";
      while(archivo_existe(nomArchEscuela)!=true){
        cout<<"EL NOMBRE DEL ARCHIVO NO SE A ENCONTRADO"<<endl;
        cout<<"Indique el nombre del archivo de la escuela, sin el ''.txt'' al final."<<endl;
        cin>>nomArchEscuela;
        nomArchEscuela=nomArchEscuela+".txt";
      }
      LecturaArchivoEscuela(escuela,nomArchEscuela);

      cout<<"Indique el nombre del archivo de las casas, sin el ''.txt'' al final."<<endl;
      cin>>nomArchCasa;
      nomArchCasa=nomArchCasa+".txt";
      while(archivo_existe(nomArchCasa)!=true){
        cout<<"EL NOMBRE DEL ARCHIVO NO SE A ENCONTRADO"<<endl;
        cout<<"Indique el nombre del archivo de las casas, sin el ''.txt'' al final."<<endl;
        cin>>nomArchCasa;
        nomArchCasa=nomArchCasa+".txt";
      }
      LecturaArchivoCasa(puntcasa, escuela,nomArchCasa);
      cout<<"Indique el nombre del archivo de las habilidades, sin el ''.txt'' al final."<<endl;
      cin>>nomArchHabilidades;
      nomArchHabilidades=nomArchHabilidades+".txt";
      while(archivo_existe(nomArchHabilidades)!=true){
        cout<<"EL NOMBRE DEL ARCHIVO NO SE A ENCONTRADO"<<endl;
        cout<<"Indique el nombre del archivo de las habilidades, sin el ''.txt'' al final."<<endl;
        cin>>nomArchHabilidades;
        nomArchHabilidades=nomArchHabilidades+".txt";
      }
      LecturaArchivoHabilidades(puntcasa,nomArchHabilidades);
      cout<<"Indique el nombre del archivo de los objetos, sin el ''.txt'' al final."<<endl;
      cin>>nomArchObjetos;
      nomArchObjetos=nomArchObjetos+".txt";
      while(archivo_existe(nomArchObjetos)!=true){
        cout<<"EL NOMBRE DEL ARCHIVO NO SE A ENCONTRADO"<<endl;
        cout<<"Indique el nombre del archivo de los objetos, sin el ''.txt'' al final."<<endl;
        cin>>nomArchObjetos;
        nomArchObjetos=nomArchObjetos+".txt";
      }
      LecturaArchivobjetos(puntcasa,nomArchObjetos);
      cout<<"Indique el nombre del archivo de los estudiantes, sin el ''.txt'' al final."<<endl;
      cin>>nomArchEstudiante;
      nomArchEstudiante=nomArchEstudiante+".txt";
      while(archivo_existe(nomArchEstudiante)!=true){
        cout<<"EL NOMBRE DEL ARCHIVO NO SE A ENCONTRADO"<<endl;
        cout<<"Indique el nombre del archivo de los estudiantes, sin el ''.txt'' al final."<<endl;
        cin>>nomArchEstudiante;
        nomArchEstudiante=nomArchEstudiante+".txt";
      }
      LecturaArchivoEstudiante(puntcasa,escuela,nomArchEstudiante);
    }
    break;
    case (3):{
      exit(0);
    }
    break;
    default:{
      cout<<"INDIQUE NUEVAMENTE LA OPCION ";
    }
    break;
  }

  while ((partida!=4)){
    system("cls");
    //NO OLVIDAR DE ACTIVAR CUADROTE
    imprimirCuadrodeTodo(puntcasa, escuela, fil, col);
    //imprimirtodo(puntcasa, escuela);
    //titulo();
    //fil=10; 
    gotoxy(col, fil); cout<<"----------------------------------"<<escuela->Nombre_colegio<<"---------------------------------------";
    fil=fil+2;
    gotoxy(1, fil); cout<<"                     1.-Gestion de campos.  ";
    fil=fil+1;
    gotoxy(1, fil); cout<<"                     2.-Modificar informacion de la escuela.  ";
    fil=fil+1;
    gotoxy(1, fil); cout<<"                     3.-Ver informacion detallada de la escuela.  ";
    fil=fil+1;
    gotoxy(1, fil); cout<<"                     4.-Comenzar Juego.";
    fil=fil+1;
    gotoxy(1, fil); cout<<"Ingrese una opcion.";
    cin>>pantalla2;
    validarDatos(pantalla2);
    while(pantalla2>4){
      gotoxy(1, fil); cout<<"Ingrese una opcion.";
      cin>>pantalla2;
      validarDatos(pantalla2);
    }
    system("cls");
    switch (pantalla2){
      case (1):{
        int infop = 0;
        while (infop<5){
          cout<<"----------------------------------AGREGAR INFORMACION---------------------------------------"<<endl;
          cout<<endl;
          cout<<"                     1.-Gestion casa.  "<<endl;
          cout<<"                     2.-Gestion habilidad.  "<<endl;
          cout<<"                     3.-Gestion objeto.  "<<endl;
          cout<<"                     4.-Gestion estudiante.  "<<endl;
          cout<<"                     5.-Salir de agregar informacion."<<endl;  
          cout<<endl<<endl;
          cout<<endl<<endl;
          cout<<"Ingrese una opcion."<<endl;
          cin>>infop;
          validarDatos(infop);
          string habilidadesop = "no";
          switch(infop){
            case (1):{//CASA
              system("cls");
              gestionCasa(escuela, puntcasa);
              GuardarInformacionCasa(puntcasa,nomArchCasa);
              GuardarInformacionHabilidades(puntcasa,nomArchHabilidades);
              GuardarInformacionObjetos(puntcasa,nomArchObjetos);
              GuardarInformacionEstudiante(puntcasa,nomArchEstudiante);
            }  
            break;
            case (2):{//HABILIDADES
              system("cls");
              gestionHabilidades(escuela, puntcasa);
              GuardarInformacionHabilidades(puntcasa,nomArchHabilidades);
              GuardarInformacionObjetos(puntcasa,nomArchObjetos);
            }
            break;
            case(3):{//OBJETOS
              system("cls");
              gestionObjetos(escuela, puntcasa);
              GuardarInformacionObjetos(puntcasa,nomArchObjetos);
            }
            break;
            case(4):{//ESTUDIANTES
              system("cls");
              gestionEstudiantes(escuela, puntcasa);
              GuardarInformacionEstudiante(puntcasa,nomArchEstudiante);
            }  
            break;
            default:
              cout<<"INDIQUE NUEVAMENTE LA OPCION ";
            break;
          }
        }
      }  
      break;
      case(2):{
        modificarColegio(escuela);
        GuardarInformacionEscuela(escuela,nomArchEscuela);
      }
      break;
      case(3):{
        imprimirCuadrodeTodo(puntcasa, escuela, fil, col);
        //imprimirtodo(puntcasa, escuela);
      }
      break;
      case (4):{
        partida=4;
      }  
      break;
      default:
        cout<<"INDIQUE NUEVAMENTE LA OPCION ";
      break;
    } 
    while(pantalla3!=5){
    gotoxy(col, fil); cout<<"----------------------------------"<<escuela->Nombre_colegio<<"---------------------------------------";
    fil=fil+2;
    gotoxy(1, fil); cout<<"                     1.-Agregar estudiantes.  ";
    fil=fil+1;
    gotoxy(1, fil); cout<<"                     2.-Generar Dinero.  ";
    fil=fil+1;
    gotoxy(1, fil); cout<<"                     3.-Batalla.  ";
    fil=fil+1;
    gotoxy(1, fil); cout<<"                     4.-Tienda.";
    fil=fil+1;
    gotoxy(1, fil); cout<<"                     5.-Salir del juego.";
    fil=fil+1;
    gotoxy(1, fil); cout<<"Ingrese una opcion.";
    cin>>pantalla3;
    validarDatos(pantalla3);
    while(pantalla3>6){
      gotoxy(1, fil); cout<<"Ingrese una opcion.";
      cin>>pantalla3;
      validarDatos(pantalla3);
    }
    switch (pantalla3){
      case(1):{
        system("cls");
        gestionEstudiantes(escuela, puntcasa);
        GuardarInformacionCasa(puntcasa,nomArchCasa);
        GuardarInformacionHabilidades(puntcasa,nomArchHabilidades);
        GuardarInformacionObjetos(puntcasa,nomArchObjetos);
        GuardarInformacionEstudiante(puntcasa,nomArchEstudiante);
      }break;
      case(2):{
        system("cls");
        GenerarDinero(puntcasa);
        GuardarInformacionCasa(puntcasa,nomArchCasa);
        GuardarInformacionHabilidades(puntcasa,nomArchHabilidades);
        GuardarInformacionObjetos(puntcasa,nomArchObjetos);
        GuardarInformacionEstudiante(puntcasa,nomArchEstudiante);
      }break;
      case(3):{
        system("cls");
        BatallaEstudiantes( puntcasa,escuela);
        GuardarInformacionCasa(puntcasa,nomArchCasa);
        GuardarInformacionHabilidades(puntcasa,nomArchHabilidades);
        GuardarInformacionObjetos(puntcasa,nomArchObjetos);
        GuardarInformacionEstudiante(puntcasa,nomArchEstudiante);
      }break;
      case(4):{
        system("cls");
        Tienda(puntcasa);
        GuardarInformacionCasa(puntcasa,nomArchCasa);
        GuardarInformacionHabilidades(puntcasa,nomArchHabilidades);
        GuardarInformacionObjetos(puntcasa,nomArchObjetos);
        GuardarInformacionEstudiante(puntcasa,nomArchEstudiante);
      }break;
      case(5):{
        pantalla3=5;
      }break;
      default:
        break;
      }
    }





    }
  
  return 0;  
}