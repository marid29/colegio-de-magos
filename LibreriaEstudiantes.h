
#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include "Libreria_Casa_Colegio.h"

using namespace std::chrono;
using namespace std;

struct estudiante{
  int codigo_estudiante;
  string nombre_estudiante;
  string nombre_casa;
  string status = "despierto";
  struct estudiante *proxEstudiante;
  struct habilidades *proxhabilidades;
  struct objeto *proxObjeto;
  struct habilidadEspecial *proxHabEsp=NULL;
  int cont_hab_est=0;
  int cont_obj_est=0;
	int energia=20;
  int salud=20;
  int knuts=0;     //60 knuts equivale a 1 galeón
  int galeones=0;
};

typedef struct estudiante *Testudiante;
Testudiante listaEstudiante = NULL;

Testudiante CrearNodoEstudiante(int codigo_estudiante, string nombre_estudiante, string nombre_casa,int energia,int salud,int knuts,int galeones){
	Testudiante nuevonodo_estudiante;
	nuevonodo_estudiante = new(struct estudiante);
  nuevonodo_estudiante->codigo_estudiante = codigo_estudiante;
	nuevonodo_estudiante->nombre_estudiante = nombre_estudiante;
  nuevonodo_estudiante->nombre_casa = nombre_casa;
  nuevonodo_estudiante->energia=energia;
  nuevonodo_estudiante->salud=salud;
  nuevonodo_estudiante->knuts=knuts;
  nuevonodo_estudiante->galeones=galeones;
	nuevonodo_estudiante->proxEstudiante = NULL;
  nuevonodo_estudiante->proxhabilidades = NULL;
  nuevonodo_estudiante->proxObjeto = NULL;
	return nuevonodo_estudiante;
}





Testudiante AgregarFinalEstudiante(Testudiante &listaEstudiante, int codigo_estudiante, string nombre_estudiante, string Nombre_casa, int energia,int salud, int knuts, int galeones){
	if (listaEstudiante == NULL){
		listaEstudiante = CrearNodoEstudiante(codigo_estudiante, nombre_estudiante, Nombre_casa, energia,salud,knuts,galeones);
		return listaEstudiante;
	}
	else{
		Testudiante aux_estudiante = listaEstudiante;
		while (aux_estudiante->proxEstudiante != NULL){
			aux_estudiante = aux_estudiante->proxEstudiante;
		}
		aux_estudiante->proxEstudiante = CrearNodoEstudiante(codigo_estudiante, nombre_estudiante, Nombre_casa, energia,salud,knuts,galeones);
		return aux_estudiante->proxEstudiante;
	}
}





//CREAR UN ESTUDIANTE CON SUS RESPECTIVAS HABILIDADES Y OBJETOS 
int random(int num){
  int valor;
  valor = 1 + rand() % (num+1-1);
  return valor;
}

Tcasa nomcasa(Tcasa &casa,int poscasa){
  Tcasa aux=NULL;
  Tcasa aux2=NULL;
  aux=casa;
  int cont=1;
  while(aux!=NULL){
    if(cont==poscasa){
      aux2=aux;
      break;
    }
    aux=aux->proxCasa;
    cont++;
  }
  return aux2;
}

Tobjeto CopiaObjeto(Tobjeto &listaOriginal){
  string nomO, desO;
  nomO=listaOriginal->nombre_objeto;
  desO=listaOriginal->descripcion_objeto;
  return (CrearObjeto(nomO,desO));
}

void agregarFinalCopiaObjeto(Tobjeto &listaOriginal, Tobjeto &listaCopia){
  if (listaCopia==NULL){
    listaCopia= CopiaObjeto(listaOriginal);
  }else{
    Tobjeto aux = listaCopia;
    while (aux->proxObjeto != NULL){
      aux = aux->proxObjeto ;    
    }
    aux->proxObjeto=CopiaObjeto(listaOriginal);
  }
}

habilidad CopiaHabilidad(habilidad &listaOriginal){
int valD, valA, valV,objeto;
string nomH, tipoH;
  nomH=listaOriginal->nombre_habilidad;
  tipoH=listaOriginal->tipo_habilidad;
  valD=listaOriginal->valor_defensa;
  valA=listaOriginal->valor_ataque;
  valV=listaOriginal->valor_velocidad;
  objeto=0;
  return (crearNodoHabilidad(nomH,tipoH,valA,valD,valV,objeto));
}

void agregarFinalCopiaHabilidad(habilidad &listaOriginal, habilidad &listaCopia){
  if (listaCopia==NULL){
    listaCopia= CopiaHabilidad(listaOriginal);
  }else{
    habilidad aux = listaCopia;
    while (aux->proxhabilidades != NULL){
      aux = aux->proxhabilidades;    
    }
    aux->proxhabilidades=CopiaHabilidad(listaOriginal);
  }
}

habilidad crearlistahabilidad(Tcasa &casaEst,Testudiante &auxest){ 
  int numR;
  bool existe;
  habilidad listaCopia=NULL;
  habilidad listaOriginal=NULL;
  listaOriginal=casaEst->proxhabilidades;
  auxest->cont_hab_est=0;
  int cont=1;
  int contR=1;
  numR=random(casaEst->cont_habilidades);
	while (contR!=numR){
    listaOriginal=listaOriginal->proxhabilidades;
    contR++;
	}
  auxest->cont_hab_est++;
  agregarFinalCopiaHabilidad(listaOriginal,listaCopia);
  while(cont<3){
    existe=false;
    while(existe==false){
      listaOriginal=casaEst->proxhabilidades;
      int contR=1;
      numR=random(casaEst->cont_habilidades);
      while (contR!=numR){
        listaOriginal=listaOriginal->proxhabilidades;
        contR++;
		  }
      if(existeMismaHabilidad(listaCopia,listaOriginal->nombre_habilidad)==false){
        existe=true; 
      } 
    }
    agregarFinalCopiaHabilidad(listaOriginal,listaCopia);
    auxest->cont_hab_est++;
		cont++;
	}
return listaCopia;
}

Tobjeto crearlistaobjeto(Tcasa casaEst,Testudiante &auxest){ 
  int numR;
  Tobjeto listaCopia=NULL;
  Tobjeto listaOriginal=NULL;
  habilidad listahabilidades=NULL;
  habilidad listahabilidadesCasa=NULL;
  listahabilidadesCasa=casaEst->proxhabilidades;
  listahabilidades=auxest->proxhabilidades;
  while (listahabilidades!=NULL){
    listahabilidadesCasa=casaEst->proxhabilidades;
    while(listahabilidadesCasa!=NULL){
      if(listahabilidadesCasa->nombre_habilidad==listahabilidades->nombre_habilidad){
        break;
      }
      listahabilidadesCasa=listahabilidadesCasa->proxhabilidades;
    }
    numR=random(listahabilidadesCasa->Cont_objetos);
    int contR=1;
    listaOriginal=NULL;
    listaOriginal=listahabilidadesCasa->proxObjeto;
    while (contR!=numR){
      listaOriginal=listaOriginal->proxObjeto;
      contR++;
	  }
    auxest->cont_obj_est++;
    agregarFinalCopiaObjeto(listaOriginal,listaCopia); 
    listahabilidades=listahabilidades->proxhabilidades;
  }
  return listaCopia;
}

void preguntasEstudiantes(Tcasa &l,Tcolegio &l2){
  string nomEst, nomCasaEst;
  int cdEst;
  Tcasa condicionCasa=NULL;
  Testudiante auxEst=NULL;
  Tcasa casaEst=NULL;
  bool buscarNodoCondicion=false;
  bool cumpleCondicionHab=false;
  bool cumpleCondicionObj=false;
  habilidad condicionHab=NULL;
  int op=1;
  while (op!=2){
    auxEst=NULL;
    casaEst=NULL;
    condicionCasa=l;
    buscarNodoCondicion=false;
    cumpleCondicionHab=false;
    cumpleCondicionObj=false;
    while (condicionCasa!=NULL){
      if(condicionCasa->cont_habilidades>=3){
        cumpleCondicionHab=true;
        condicionHab=NULL;
        condicionHab=condicionCasa->proxhabilidades;
        while(condicionHab!=NULL){
          if(condicionHab->Cont_objetos<1){
            cumpleCondicionObj=false;
            break;
          }
          cumpleCondicionObj=true;
          condicionHab=condicionHab->proxhabilidades;
        }
        break;
      }
      condicionCasa=condicionCasa->proxCasa;
    }
    if((cumpleCondicionHab==true)&&(cumpleCondicionObj==true)){
      while(buscarNodoCondicion==false){
        casaEst=nomcasa(l,random(l2->cont_Casa)); 
        if(casaEst->cont_habilidades>=3){
          habilidad auxhab=NULL;
          auxhab=casaEst->proxhabilidades;
          while(auxhab!=NULL){
            if(auxhab->Cont_objetos<1){
              buscarNodoCondicion=false;
              break;
            }
            auxhab=auxhab->proxhabilidades;
            buscarNodoCondicion=true;
          }
        }
      }
      l2->cont_Estudiante++;
      cout<<"SEPARAR CON PUNTOS."<<endl;
      cout << "Ingrese el nombre del estudiante: "<<endl;
      cin>>nomEst;
      nomCasaEst=casaEst->Nombre_casa;
      cdEst=l2->cont_Estudiante;
      auxEst=AgregarFinalEstudiante(casaEst->proxEstudiante,cdEst,nomEst,nomCasaEst,20,20,0,0);
      auxEst->proxhabilidades=crearlistahabilidad(casaEst,auxEst);
      auxEst->proxObjeto=crearlistaobjeto(casaEst,auxEst);
      casaEst->cont_estudiante++; 
      cout<<"LA INFORMACION DE "<<nomEst<<" YA FUE ASIGNADA POR EL ESPEJO CLARIVIDENTE."<<endl;
      cout<<"Desea ingresar otro estudiante a tu escuela de magos. Indique 1 o 2:"<<endl;
      cout<<"1.-Si."<<endl;
      cout<<"2.-No."<<endl;
      cin>>op;
      validarDatos(op);
    }else{
      if (cumpleCondicionHab==false){
        cout<<"NO HAY NINGUNA CASA QUE CUENTE CON LAS HABILIDADES NECESARIA PARA BRINDARSELAS A LOS ESTUDIANTES."<<endl;
        cout<<"POR FAVOR AGREGUE MAS HABILIDADES A SUS CASAS."<<endl;
        cout<<"DE MANERA QUE TENGAN COMO MINIMO 3 HABILIDADES."<<endl;
      }
      if (cumpleCondicionObj==false){
        cout<<"HAY CASAS QUE TIENEN HABILIDADES QUE NO CUENTAN CON LA CANTIDAD DE OBJETOS NECESARIAS."<<endl;
        cout<<"POR FAVOR AGREGUE MAS OBJETOS A SUS HABILIDADES."<<endl;
        cout<<"DE MANERA QUE TENGAN COMO MINIMO 1 OBJETO POR HABILIDAD."<<endl;
      }
      op=2;
    }
  }
}
/////////////////////////////////////////////////////////////////////


//FUNCION MODIFICAR ESTUDIANTE 
void ModificarCasaEstudiante(Tcasa &l, int respCasaConsultar, int estModif){
  Tcasa aux = l;
  int contaux = 0;
  string nuevoNombreEst;
  while (aux != NULL) {
    contaux++;
    if (contaux == respCasaConsultar) {
      Testudiante auxest = aux->proxEstudiante;
      int contest = 1;
      if (aux->cont_estudiante == 0){
        cout << "LA CASA NO TIENE ESTUDIANTES" << endl;
        delay(3);
        break;
      }
      else{
        while (auxest != NULL) {
          if (contest == estModif){
            cout<<"Ingresa el nuevo nombre del estudiante: "<<endl;
            cin>>nuevoNombreEst;
            auxest->nombre_estudiante = nuevoNombreEst;
          }
          auxest = auxest->proxEstudiante;
          contest++;
        }
      }     
    }
    aux = aux->proxCasa;
  }
}
//////////////////////////////////////////////////////////////////////////



//FUNCION PARA ELIMINAR  
void eliminarEstudiante(Tcasa &l, int respCasaModificar, int estEl) {
  Tcasa aux=l;
  int contaux = 0;

  while (aux != NULL) {
    contaux++;
    if (contaux == respCasaModificar) {
      Testudiante auxest = aux->proxEstudiante;
      int contest = 1;
      if (aux->cont_estudiante == 0){
        cout << "LA CASA NO TIENE ESTUDIANTES" << endl;
        delay(3);
        break;
      }
      else{
        while (auxest != NULL) {
          if (contest == estEl) {
            habilidad nodohabilidad = auxest->proxhabilidades;
            while (nodohabilidad != NULL) {
              habilidad siguiente = nodohabilidad->proxhabilidades;
              delete nodohabilidad;
              nodohabilidad = siguiente;
            }
            auxest->proxhabilidades = NULL;
            Tobjeto nodoobjeto = auxest->proxObjeto;
            while (nodoobjeto != NULL) {
              Tobjeto sigObj = nodoobjeto->proxObjeto;
              delete nodoobjeto;
              nodoobjeto = sigObj;
            }
            auxest->proxObjeto = NULL;
            if (auxest == aux->proxEstudiante) {
              aux->proxEstudiante = auxest->proxEstudiante;
              delete auxest;
              auxest = aux->proxEstudiante;
            } else {
              Testudiante anteriorEst = aux->proxEstudiante;
              while (anteriorEst->proxEstudiante != auxest) {
                anteriorEst = anteriorEst->proxEstudiante;
              }
              anteriorEst->proxEstudiante = auxest->proxEstudiante;
              delete auxest;
              aux->cont_estudiante--;
              auxest = anteriorEst->proxEstudiante;
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

void eliminarCamposObj(Tcasa &l, int habE, int casaE) {
  Tcasa aux = l;
  int contpos = 0;
  int numObjModif;
    
  while (aux != NULL) {
    contpos++;
    if (casaE == contpos) {
      habilidad auxhab = aux->proxhabilidades;
      int conthabs = 1;
      while (habE > aux->cont_habilidades || habE < 1) {
        cout << "El numero de habilidad ingresado no es valido." << endl;
        cout << "Indica que habilidad desea eliminar un objeto: " << endl;
        cin >> habE;
        validarDatos(habE);
      }
      while (auxhab != NULL && conthabs < habE) {
        auxhab = auxhab->proxhabilidades;
        conthabs++;
      }            
      int contobjetos = 1;
      cout << "Indica el objeto que quieres eliminar: " << endl;
      cin >> numObjModif;
      validarDatos(numObjModif);
      if (auxhab->Cont_objetos == 0){
        cout << "LA HABILIDAD NO TIENE OBJETOS" << endl;
        delay(3);
        break;
      }
      else{
        while (numObjModif > auxhab->Cont_objetos || numObjModif < 1) {
          cout << "El numero de objeto ingresado no es valido." << endl;
          cout << "Indica que objeto desea eliminar: " << endl;
          cin >> numObjModif;
          validarDatos(numObjModif);
        }
        Tobjeto aux1 = auxhab->proxObjeto;
        Tobjeto aux2 = NULL;
        while (aux1 != NULL && contobjetos < numObjModif) {
          aux2 = aux1;
          aux1 = aux1->proxObjeto;
          contobjetos++;
        }
        if (aux1 != NULL){
          if (aux2 != NULL){
            aux2->proxObjeto = aux1->proxObjeto;
          }
          else{
            auxhab->proxObjeto = aux1->proxObjeto;
          } 
          auxhab->Cont_objetos--;               
          delete aux1;
        }
        else{
          cout << "El objeto seleccionado no existe." << endl;
        }
      }  
    }        
    aux = aux->proxCasa;
  }
}

void imprimirHabilidadesCasa(Tcasa l, int respCasaModificar) {
  Tcasa aux = l;
  int contaux = 0;
  while (aux != NULL) {
    contaux++;
    if (contaux == respCasaModificar) {
      habilidad auxhab = aux->proxhabilidades;
      int conthab = 1;
      if (auxhab == NULL){
        cout << "LA CASA NO TIENE HABILIDADES" << endl;
        delay(3);
        break;
      } 
      while (auxhab != NULL) {
        cout << conthab << ".-Habilidad: " << auxhab->nombre_habilidad << endl;
        auxhab = auxhab->proxhabilidades;
        conthab++;
      }   
    }
    aux = aux->proxCasa;
  }
}

void eliminarCamposHab(Tcasa &l, int casaE){
    Tcasa aux = l;
    int contpos = 0;
    int habE;
    while (aux != NULL) {
        contpos++;
        if (casaE == contpos) {
            habilidad auxhab = aux->proxhabilidades;
            int conthabs = 1;
            cout << "Indica que habilidad desea eliminar: " << endl;
            imprimirHabilidadesCasa(l, casaE);
            cin >> habE;
            validarDatos(habE);
            if (aux->cont_habilidades == 0){
              cout << "LA CASA NO TIENE HABILIDADES" << endl;
              delay(3);
              break;
            }
            else{
              while (habE > aux->cont_habilidades || habE < 1) {
                cout << "El numero de habilidad ingresado no es valido." << endl;
                cout << "Indica que habilidad desea eliminar: " << endl;
                cin >> habE;
                validarDatos(habE);
              }
              while (auxhab != NULL && conthabs < habE) {
                auxhab = auxhab->proxhabilidades;
                conthabs++;
              }
              if (auxhab != NULL) {
                Tobjeto auxO = auxhab->proxObjeto;
                while (auxO != NULL) {
                    Tobjeto siguiente = auxO->proxObjeto;
                    delete auxO;
                    auxO = siguiente;
                }
                auxhab->proxObjeto = NULL;

                habilidad auxHabS = aux->proxhabilidades;
                int conthabs2 = 1;
                while (auxHabS != NULL && conthabs2 < habE - 1) {
                    auxHabS = auxHabS->proxhabilidades;
                    conthabs2++;
                }
                if (auxHabS != NULL && auxHabS->proxhabilidades != NULL) {
                    auxHabS->proxhabilidades = auxHabS->proxhabilidades->proxhabilidades;
                }
                delete auxhab;
                l->cont_habilidades--;
              }
            }           
        }
        aux = aux->proxCasa;
    }
}

void eliminarNodoCasa(Tcasa &l,Tcolegio &l2, int casaE) {
  Tcasa aux = l;
  Tcasa anterior = NULL;
  int contpos = 0;

  while (aux != NULL){
    contpos++;
    if (casaE == contpos){
      Testudiante auxest = aux->proxEstudiante;
      while (auxest != NULL) {
        eliminarEstudiante(l, casaE, 1); // se eliminan a los estudiantes de la casa
        auxest = aux->proxEstudiante;
      }
      habilidad auxhab = aux->proxhabilidades;
      while (auxhab != NULL){
        Tobjeto auxO = auxhab->proxObjeto;
        while (auxO != NULL){
          Tobjeto siguiente = auxO->proxObjeto;
          delete auxO;     //se eliminan los objetos de la casa
          auxO = siguiente;
        }
        auxhab->proxObjeto = NULL;
        habilidad siguienteHab = auxhab->proxhabilidades;
        delete auxhab;     //se eliminan las habilidades de la casa
        auxhab = siguienteHab;
      }
      aux->proxhabilidades = NULL;
      if (anterior == NULL){
        l = aux->proxCasa;
      }else{
        anterior->proxCasa = aux->proxCasa;
      }
      l2->cont_Casa--;
      delete aux; //se elimina la casa
      break;
    }
    anterior = aux;
    aux = aux->proxCasa;
  }
}
/////////////////////////////////////////////

//FUNCION PARA DORMIR ESTUDIANTE
steady_clock::time_point tiempoInicioSueno;

int CalculoDeGaleones(int valorKnuts){
  int valorGaleones;
  valorGaleones = (valorKnuts/60);
  return valorGaleones;
}

void dormir(Tcasa &l, int numCasa, int numEstudiante) {
  Tcasa aux = l;
  int contCasa = 0;
  tiempoInicioSueno = steady_clock::now();
  while (aux != NULL) {
    contCasa++;
    if (contCasa == numCasa) {
      Testudiante auxest = aux->proxEstudiante;
      int contEstudiante = 0;
      while (auxest != NULL) {
        contEstudiante++;
        if (contEstudiante == numEstudiante) {
          if(auxest->status!="dormido"){
            auxest->status="dormido";
            cout << auxest->nombre_estudiante << " está durmiendo..." << endl;
            return;  // Salir de la función después de dormir al estudiante
          }else{
            cout<<"EL ESTUDIANTE YA ESTA DORMIDO"<<endl;
          }
          delay(3);
          system("cls");
        }
        auxest = auxest->proxEstudiante;
      }
    }
    aux = aux->proxCasa;
  }
  // Si la función llega a este punto, no se encontró al estudiante deseado
  cout << "Estudiante no encontrado." << endl;
}

void despertar(Tcasa &l, int numCasa, int numEstudiante) {
  Tcasa aux = l;
  int contCasa = 0;
  while (aux != NULL) {
    contCasa++;
    if (contCasa == numCasa) {
      Testudiante auxest = aux->proxEstudiante;
      int contEstudiante = 0;
      
      while (auxest != NULL) {

        contEstudiante++;
        if (contEstudiante == numEstudiante) {
          if(auxest->status=="dormido"){
          steady_clock::time_point tiempoDespertar = steady_clock::now();
          steady_clock::duration duracionSueno = tiempoDespertar - tiempoInicioSueno;
          int monedas = duration_cast<seconds>(duracionSueno).count();
          auxest->knuts = auxest->knuts+monedas; 
          auxest->galeones = auxest->galeones+CalculoDeGaleones(auxest->knuts);
          auxest->knuts= auxest-> knuts % 60;
          cout << auxest->nombre_estudiante << " ha dormido durante " << duration_cast<seconds>(duracionSueno).count() << " segundos." << endl;
          return;  // Salir de la función después de despertar al estudiante
          }else{
            cout<<"El ya esta despierto"<<endl;        
          }
          delay(3);
          system("cls");
        }

        auxest = auxest->proxEstudiante;
      }
    }
    aux = aux->proxCasa;
 }
}
///////////////////////////////////////////////////////