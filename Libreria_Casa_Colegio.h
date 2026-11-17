#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "Libreria_Habilidades.h"

using namespace std;


//ESTRUCTURA HABILIDADES ESPECIALES
struct habilidadEspecial{
  int energia=20;
  int salud=20;
  struct habilidadEspecial *proxHabEsp;
};

//ESTRUCTURA CASA 
struct casa{
  string Nombre_casa;
  int cont_estudiante=0;
  int cont_habilidades=0;
  int ano_fundada;
  string descripcion_casa;
  string nombre_director;
  struct casa*proxCasa; 
  struct estudiante*proxEstudiante;  
  struct habilidades* proxhabilidades; 
};

//ESTRUCTURA COLEGIO
struct colegio{
  string Nombre_colegio;
  string Direccion;
  int Antiguedad;
  int Codigo_Postal;
  int cont_Casa=0;
  struct casa*proxCole;
  int cont_Estudiante=0;
};

typedef casa*Tcasa;
typedef colegio*Tcolegio;
typedef habilidadEspecial *THabEsp;
Tcasa puntcasa=NULL;
Tcolegio puntcole=NULL;


//COLEGIO
  Tcolegio crearcolegio(string nom, string dir, int ant,int cp){
  Tcolegio p=new(colegio);
  p->Nombre_colegio=nom;
  p->Direccion=dir;
  p->Antiguedad=ant;
  p->Codigo_Postal=cp;
  p->proxCole=NULL;
  return p;
}

//MODIFICAR COLEGIO
void modificarEscuelaNombre(Tcolegio &l2,  string nombreEscuelaNuevo){
  Tcolegio aux = l2;
  cout << "Ingrese el nuevo nombre: \n";
  cin >> nombreEscuelaNuevo;
  aux -> Nombre_colegio = nombreEscuelaNuevo;
}

void modificarEscuelaDireccion(Tcolegio &l2,  string DirEscuelaNuevo){
  Tcolegio aux = l2;
  cout << "Ingrese la nueva direccion: \n";
  cin >> DirEscuelaNuevo;
  aux -> Direccion = DirEscuelaNuevo;
}

void modificarEscuelaAntiguedad(Tcolegio &l2,  int AntEscuelaNuevo){
  Tcolegio aux = l2;
  cout << "Ingrese antiguedad: \n";
  cin >> AntEscuelaNuevo;
  aux -> Antiguedad = AntEscuelaNuevo;
}

void modificarEscuelaCodigoP(Tcolegio &l2,  int CodEscuelaNuevo){
  Tcolegio aux = l2;
  cout << "Ingrese Codigo Postal nuevo: \n";
  cin >> CodEscuelaNuevo;
  aux -> Codigo_Postal = CodEscuelaNuevo;
}

void imprimirColegio(Tcolegio &l2){
  cout<<"Nombre:"<<l2->Nombre_colegio<<endl<<endl;
  cout<<"Direccion:"<<l2->Direccion<<endl<<endl; 
  cout<<"Ano de anteguedad:"<<l2->Antiguedad<<endl<<endl;  
  cout<<"Codigo Postal:"<<l2->Codigo_Postal<<endl<<endl; 
  cout<<"Numero de casas:"<<l2->cont_Casa<<endl<<endl;
  cout<<"Numero de estudiantes:"<<l2->cont_Estudiante<<endl<<endl;     
}

void modificarColegio(Tcolegio &l2){
   int modifCampoEscuela;
   string n;
   string dir;
   int ant;
   int cod; 
   cout<<"Que campo desea modificar?"<<endl;
   cout<<"1. nombre"<<endl;
   cout<<"2. direccion"<<endl;
   cout<<"3. antiguedad"<<endl;
   cout<<"4. Codigo postal"<<endl;
   cin>>modifCampoEscuela;
   switch(modifCampoEscuela){
      case(1):{
         modificarEscuelaNombre(l2, n);
         imprimirColegio(l2);
      }
      break;
      case(2):{
         modificarEscuelaDireccion(l2, dir);
         imprimirColegio(l2);
      }
      break;
      case(3):{
         modificarEscuelaAntiguedad(l2, ant);
         imprimirColegio(l2);
      }
      break;
      case(4):{
         modificarEscuelaCodigoP(l2, cod);
         imprimirColegio(l2);
      }
      break;
   }
}

////////////////////////////////////////////////

//HABILIDADES ESPECIALES
THabEsp crearNodoHabEsp(int e, int s){
   THabEsp HabEsp = new habilidadEspecial();
   HabEsp->energia = e;
   HabEsp->salud = s;
   HabEsp->proxHabEsp = NULL;
   return HabEsp;
}

THabEsp agregarFinalHabilidadEspecial(THabEsp &HabEspecial ){
  if (HabEspecial== NULL){
    HabEspecial= crearNodoHabEsp(20,20);
    return HabEspecial;
  }else{
    THabEsp aux = HabEspecial;
    while (aux->proxHabEsp != NULL){
      aux = aux->proxHabEsp;    
    }
    aux->proxHabEsp =crearNodoHabEsp(20,20);
    return aux->proxHabEsp;
  }
}

THabEsp CopiaHabEsp(THabEsp &listaOriginal){
int e, s;
  e = listaOriginal->energia;
  s = listaOriginal->salud;
  return (crearNodoHabEsp(e,s));
}

void agregarFinalCopiaHabEsp(THabEsp &listaOriginal, THabEsp &listaCopia){
    if (listaCopia == NULL){
        listaCopia = CopiaHabEsp(listaOriginal);
    }else{
        THabEsp aux = listaCopia;
        while (aux->proxHabEsp != NULL){
            aux = aux->proxHabEsp;    
        }
        aux->proxHabEsp = CopiaHabEsp(listaOriginal);
    }
}
/////////////////////////////////////////////////////////////////////////


//CASAS
Tcasa crearcasa(string nomCasa, string desCasa, int anoCasa, string nomDir){
  Tcasa p=new(casa);
  p->Nombre_casa=nomCasa;
  p->descripcion_casa=desCasa;
  p->ano_fundada=anoCasa;
  p->nombre_director=nomDir;
  p->proxEstudiante=NULL;
  p->proxhabilidades=NULL;
  p->proxCasa=NULL;
  return p;
}

Tcasa agregarFinalcasa(Tcasa &l,Tcolegio &l2,string nomCasa, string desCasa, int anoCasa, string nomDir){
  Tcasa aux=l;
  if(l==NULL){ 
    l=crearcasa(nomCasa,desCasa,anoCasa,nomDir); 
    l2->cont_Casa++; 
    l2->proxCole=l;
    return l;
  }else{
    while(aux->proxCasa!=NULL){
      aux= aux->proxCasa;
    }
    aux->proxCasa=crearcasa(nomCasa,desCasa,anoCasa,nomDir); 
    l2->cont_Casa++; 
    return aux->proxCasa;
  }
}


//FUNCIONES GENERALES DEL PROGRAMA
void delay(int secs){
  for (int i = (time(NULL) + secs); time(NULL) != i; time(NULL)){}
}

void validarDatos( int &n ){
    while (cin.fail() == true){
    cin.clear();
    cin.ignore(1000000000, '\n');
    cout<<"Ingresa un valor valido."<<endl; 
    cout<<"Ingresa el valor:"<<endl;
    cin>>n;
    system("cls");
    }
}

void validarDatos2(int &n){
  while (n>100){
    cout<<"Ingresa un valor valido entre 0 y 90:"<<endl;
    cin>>n;
  }
}
////////////////////////////////////////////////



//FUNCIONES PARA VALIDAR SI EXISTE EL MISMA CASA 
string minuscula(string &palabra){//esto es para transformar las palabra ingresadas a minusculas y ver si son iguales
  for(int i=0; i<palabra.length();i++){
    palabra[i]= tolower(palabra[i]);
  }
  return palabra;
}

bool existeMismaCasa(Tcasa &l,string &casa){
Tcasa aux=NULL;
aux=l;
bool existe=false;
string palabraCampo;
  while(aux!=NULL){
    palabraCampo=aux->Nombre_casa;
    if(minuscula(palabraCampo)==minuscula(casa)){
      existe=true;
    }
    aux=aux->proxCasa;
  }
  return existe;
}
///////////////////////////////////////////////////


//INGRESAR INFORMACION POR TECLADO Y SE GUARDA EN UN ARCHIVO

void PreguntasEscuela(Tcolegio &l2){
  int antEscuela,cpEscuela;
  string nomEscuela,dirEscuela;
  
  cout<<"SEPARAR CON PUNTOS."<<endl;
  cout<<"Indique el nombre de su escuela."<<endl;
  cin>>nomEscuela;
  cout<<"Indique la direccion de su escuela."<<endl;
  cin>>dirEscuela;
  cout<<"Indique el ano de antiguedad de su escuela."<<endl;
  cin>>antEscuela;
  validarDatos(antEscuela); 
  cout<<"Indique codigo postal de su escuela."<<endl;
  cin>>cpEscuela;
  validarDatos(cpEscuela);
  l2 = crearcolegio(nomEscuela, dirEscuela,antEscuela,cpEscuela);
}

Tobjeto preguntasObjetos(Tobjeto &listaObjeto,habilidad auxhabilidad,int objeto){
  string nombre_objeto;
  bool existe=false;
  string descripcion_objeto;
  int contauxhabilidad=0;
  while(contauxhabilidad<objeto){
    existe=false;
    if(listaObjeto==NULL){
      cout<<"SEPARAR CON PUNTOS."<<endl;
      cout << "Indique el nombre del objeto a agregar: "<<endl;
      cin>>nombre_objeto;
      cout << "Indique la descripcion del objeto a agregar: "<<endl;
      cin>>descripcion_objeto; 
    }else{
      cout<<"SEPARAR CON PUNTOS."<<endl;
      cout << "Indique el nombre del objeto a agregar: "<<endl;
      cin>>nombre_objeto;
      while(existe==false){
        if( existeMismoObjeto(listaObjeto,nombre_objeto)==true){
          cout<<"EL NOMBRE "<<nombre_objeto<< " YA FUE USADO"<<endl;
          cout << "Indique el nombre del objeto a agregar: "<<endl;
          cin>>nombre_objeto;
        }else{
          existe=true;   
        }
      }
      cout << "Indique la descripcion del objeto a agregar: "<<endl;
      cin>>descripcion_objeto;
    }
    AgregarFinalObjeto(listaObjeto,nombre_objeto,descripcion_objeto);
    auxhabilidad->Cont_objetos++;
    contauxhabilidad++;
  }
  return listaObjeto;
}

habilidad preguntasHabilidades(habilidad &listahabilidad,Tcasa &auxcasa){
  int valD, valA, valV, objeto;
  string nomH, tipoH;
  int numeroH;
  bool valido=false;
  habilidad auxhabilidad=NULL;
  int cont_habilidades=0;
  bool existe=false; 
  //Aqui tiene que haber una pregunta en donde se pregunta si ya cuenta con un archivo de habilidades o no, esto 
  //tambien es para objetos
  cout<<"Cuantas habilidades desea ingresar: ";
  cin>> numeroH;
  validarDatos(numeroH);
  while(cont_habilidades<numeroH){
    Tobjeto listaObjeto=NULL;
    existe=false;
    valido=false;
    if (listahabilidad==NULL){
      cout<<"SEPARAR CON PUNTOS."<<endl;
      cout<<"Ingrese el nombre de la habilidad:"<<endl;
      cin>>nomH;
      cout<<"Ingrese el tipo de habilidad: a (ataque) o d (defensa)"<<endl;
      cin>>tipoH;
      while (valido!=true){
        if ((tipoH !="a") && (tipoH!="d")){
          cout<<"Ingrese un tipo de habilidad valido"<<endl;
          cin>>tipoH;
        }else{
          valido=true;
        }
      }
      if (tipoH == "a"){
        cout<<"El valor de ataque: "<< endl; 
        cin>> valA; 
        validarDatos(valA); 
        valD = ((valA*30)/100);
        cout<<"El valor de defensa: "<<valD<<endl;
      }
      if (tipoH == "d"){
        cout<<"El valor de defensa: "<< endl;
        cin>> valD;
        validarDatos(valD);
        valA = ((valD*30)/100); 
        cout<<"El valor de ataque: "<<valA<<endl;  
      }
      cout<<"La velocidad:"<<endl;
      cin>>valV;
      validarDatos(valV); 
      cout<<"Cuantos objetos desea que tenga esta habilidad: "<< endl;
      cin>> objeto;
      validarDatos(objeto); 
      agregarFinalHabilidad(listahabilidad,nomH,tipoH,valA,valD,valV,0);
      listahabilidad->proxObjeto=preguntasObjetos(listaObjeto,listahabilidad,objeto);
    }else{
      cout<<"SEPARAR CON PUNTOS."<<endl;
      cout<<"Ingrese el nombre de la habilidad:"<<endl;
      cin>>nomH;
      while(existe==false){
        if( existeMismaHabilidad(listahabilidad,nomH)==true){
          cout<<"EL NOMBRE "<<nomH<<" YA FUE USADO"<<endl;
          cout<<"Ingrese nuevamente el nombre de la habilidad:"<<endl;
          cin>> nomH;
        }else{
          existe=true;   
        }
      }
      cout<<"Ingrese el tipo de habilidad: a (ataque) o d (defensa)"<<endl;
      cin>>tipoH;
      while (valido!=true){
        if ((tipoH !="a") && (tipoH!="d")){
          cout<<"Ingrese un tipo de habilidad valido"<<endl;
          cin>>tipoH;
        }else{
          valido=true;
        }
      }
      if (tipoH == "a"){
        cout<<"El valor de ataque: "<< endl; 
        cin>> valA; 
        validarDatos(valA); 
        valD = ((valA*30)/100);
        cout<<"El valor de defensa: "<<valD<<endl;
      }
      if (tipoH == "d"){
        cout<<"El valor de defensa: "<< endl;
        cin>> valD;
        validarDatos(valD);
        valA = ((valD*30)/100); 
        cout<<"El valor de ataque: "<<valA<<endl;  
      }
      cout<<"La velocidad:"<<endl;
      cin>>valV;
      validarDatos(valV); 
      cout<<"Cuantos objetos desea que tenga esta habilidad: "<< endl;
      cin>> objeto;
      validarDatos(objeto);
      auxhabilidad=agregarFinalHabilidad(listahabilidad,nomH,tipoH,valA,valD,valV,0);
      auxhabilidad->proxObjeto=preguntasObjetos(listaObjeto,auxhabilidad,objeto);
    }
    auxcasa->cont_habilidades++;
    cont_habilidades++;
  }
  return listahabilidad;
}

void preguntasCasa(Tcasa &l, Tcolegio &l2){
Tcasa auxcasa=NULL;
bool existe;
int anoCasa;
string casa,desCasa,nomDir;
int op=1;
  while (op!=2){
    habilidad listahabilidad=NULL;
    if(l==NULL){
      cout<<"SEPARAR CON PUNTOS."<<endl;
      cout<<"Indique el nombre de la casa."<<endl;
      cin>>casa;
      cout<<"Indique la descripcion de la casa."<<endl;
      cin>>desCasa;
      cout<<"Indique el ano en que fue fundada la casa."<<endl;
      cin>>anoCasa;
      validarDatos(anoCasa);
      cout<<"Indique el nombre del director."<<endl;
      cin>>nomDir;
      agregarFinalcasa(l,l2,casa,desCasa,anoCasa,nomDir);
      l->proxhabilidades=preguntasHabilidades(listahabilidad,l);
    }else{
      cout<<"Desea ingresar otra casa a tu escuela de magos. Indique 1 o 2:"<<endl;
      cout<<"1.-Si."<<endl;
      cout<<"2.-No."<<endl;
      cin>>op;
      validarDatos(op);
      while(op==1){
        existe=false;
        listahabilidad=NULL;
        cout<<"SEPARAR CON PUNTOS."<<endl;
        cout<<"Indique el nombre de la casa."<<endl;
        cin>>casa;
        while(existe==false){
          if(existeMismaCasa(l,casa)==true){
            cout<<"EL NOMBRE "<<casa<<" YA FUE USADO"<<endl;
            cout<<"Ingrese nuevamente el nombre de la casa:"<<endl;
            cin>> casa;
          }else{
            existe=true;   
          }
        }
        cout<<"Indique la descripcion de la casa."<<endl;
        cin>>desCasa;
        cout<<"Indique el ano en que fue fundada la casa."<<endl;
        cin>>anoCasa;
        validarDatos(anoCasa);
        cout<<"Indique el nombre del director."<<endl;
        cin>>nomDir;
        auxcasa=agregarFinalcasa(l,l2,casa,desCasa,anoCasa,nomDir);
        auxcasa->proxhabilidades=preguntasHabilidades(listahabilidad,auxcasa);
        cout<<"Desea ingresar otra casa a tu escuela de magos. Indique 1 o 2:"<<endl;
        cout<<"1.-Si."<<endl;
        cout<<"2.-No."<<endl;
        cin>>op;
        validarDatos(op);
      }
    }
  }   
}
//////////////////////////////////////////////////////////////////////////


//MODIFICACION DE LA INFORMACION DE OBJETOS,HABILIDADES,CASAS 
void modificarCasa(Tcasa &l,Tcolegio &l2, int respCasaModificar){
  Tcasa aux = l;
  string casaNueva; 
  int contpos=0;
  while (contpos!=l2->cont_Casa){
    contpos++;
    if (respCasaModificar==contpos){
      cout<<"Indique el nuevo nombre de la casa:"<<endl;
      cin>>casaNueva;
      aux->Nombre_casa=casaNueva;
      break;
    }
    aux=aux->proxCasa;
  }
}

void modificarCasaHabilidad(Tcasa& l, int respCasaModificar, int habModif){
  Tcasa aux = l;
  int contpos = 0;
  int opcionModificar = 0;
  while (aux != NULL) {
    contpos++;
    if (respCasaModificar == contpos){
      habilidad auxhab = aux->proxhabilidades;
      int conthabs = 1;
      if (aux->cont_habilidades == 0){
        cout << "LA CASA NO TIENE HABILIDADES" << endl;
        delay(3);
        break;
      }else{
        while (habModif > aux->cont_habilidades || habModif < 1) {
          cout << "El numero de habilidad ingresado no es valido." << endl;
          cout << "Indica que habilidad desea modificar: " << endl;
          cin >> habModif;
        }
        while (auxhab != NULL && conthabs < habModif) {
          auxhab = auxhab->proxhabilidades;
          conthabs++;
        }
        if (auxhab != NULL) {
          while (opcionModificar != 6){
            cout<<"MODIFICAR HABILIDADES"<<endl; 
            cout<<"Elige una de las siguientes opciones"<<endl;
            cout<<" 1. Modificar el nombre de la habilidad."<<endl; 
            cout<<" 2. Modificar tipo de habilidad:"<<endl; 
            cout<<" 3. Modificar valor de ataque:"<<endl; 
            cout<<" 4. Modificar valor de defensa:"<<endl;
            cout<<" 5. Modificar valor de velocidad:"<<endl; 
            cout<<" 6. Volver a opciones modificar."<<endl; 
            cin>>opcionModificar;
            switch(opcionModificar){
              case(1):{
                string habNueva;
                cout << "Indique el nuevo nombre de la habilidad:" << endl;
                cin >> habNueva;
                modificarNombreHabilidad(auxhab, habNueva);
              }
              break;
              case(2):{
                string nuevoTipo;
                cout<<"Idique nuevo tipo de habilidad:"<<endl,
                cin>> nuevoTipo;
                modificarTipoHabilidad(auxhab, nuevoTipo);   
              }
              break;
              case(3):{
                int nuevoValA;
                cout<<"Indique el nuevo valor de ataque: "<<endl;
                cin>>nuevoValA;
                validarDatos(nuevoValA);
                modificarValAtaque(auxhab, nuevoValA);
              }
              break;
              case(4):{
                int nuevoValD;
                cout<<"Indique el nuevo valor de defensa: "<<endl;
                cin>>nuevoValD;
                validarDatos(nuevoValD);
                modificarValDefensa(auxhab, nuevoValD);    
              }
              break;
              case(5):{
                int nuevoValV;
                cout<<"Indique el nuevo valor de velocidad: "<<endl;
                cin>>nuevoValV;
                validarDatos(nuevoValV);
                modificarValVelocidad(auxhab, nuevoValV);   
              }
              break;
              case(6):{
                opcionModificar = 6;
              }
              break;
              default:{
                cout<<"INDIQUE NUEVAMENTE LA OPCION ";
              }
              break;
            }
          }  
        }
        break;
      }    
    }
    aux = aux->proxCasa;
  }
}


void imprimirObjetoUnaCasa(Tcasa &l, int habModif, int NumCasa) {
  Tcasa auxl = NULL;
  auxl = l;
  habilidad aux = NULL;
  int contc = 1;
  while (contc!=NumCasa) {
    auxl=auxl->proxCasa;
    contc++;
  }
    aux = auxl->proxhabilidades;

    int conth = 1;
    while (aux != NULL) {
      if (conth == habModif) {
        Tobjeto auxobjetos = aux->proxObjeto;
        ImprimirObjetos(auxobjetos);
      }
      aux = aux->proxhabilidades;
      conth++;
    }
  
  
}


void imprimirObjeto(Tcasa &l, int habModif) {
  Tcasa auxl = NULL;
  auxl = l;
  habilidad aux = NULL;
  int contc = 1;
  while (auxl != NULL) {
    aux = auxl->proxhabilidades;
    int conth = 1;
    while (aux != NULL) {
      if (conth == habModif) {
        Tobjeto auxobjetos = aux->proxObjeto;
        ImprimirObjetos(auxobjetos);
      }
      aux = aux->proxhabilidades;
      conth++;
    }
    contc++;
    auxl = auxl->proxCasa;
  }
}

void modificarObjeto(Tcasa& l, int respCasaModificar, int habModif){
  Tcasa aux = l;
  int contpos = 0;
  while (aux != NULL) {
    contpos++;
    if (respCasaModificar == contpos) {
      habilidad auxhab = aux->proxhabilidades;
      int conthabs = 1;
      if (aux->cont_habilidades == 0){
        cout << "LA CASA NO TIENE HABILIDADES" << endl;
        delay(3);
        break;
      }
      else{
        while (habModif > aux->cont_habilidades || habModif < 1) {
          cout << "El numero de habilidad ingresado no es valido." << endl;
          cout << "Indica que habilidad desea modifcarle un objeto: " << endl;
          cin >> habModif;
          validarDatos(habModif);
        }
        while (auxhab != NULL && conthabs < habModif) {
          auxhab = auxhab->proxhabilidades;
          conthabs++;
        }
        if (auxhab != NULL) {
          int numObjModif;       
          if (auxhab->Cont_objetos == 0){
            cout << "LA HABILIDAD NO TIENE OBJETOS" << endl;
            delay(3);
            break;
          }
          else{
            cout << "Indique el objeto a modificar: " << endl;
            imprimirObjeto(l, habModif);
            cin >> numObjModif;
            validarDatos(numObjModif);
            while (numObjModif > auxhab->Cont_objetos || numObjModif < 1) {
              cout << "El numero de objeto ingresado no es valido." << endl;
              cout << "Indica que objeto desea modificar: " << endl;
              cin >> numObjModif;
              validarDatos(numObjModif);
            }
            int contobjetos = 1;
            Tobjeto aux = auxhab->proxObjeto; 
            while (contobjetos < numObjModif && aux != NULL){
              aux = aux->proxObjeto;
              contobjetos++;
            }
            int respModifObj;
            cout<<"Indica el campo a modificar:"<<endl;
            cout<<"1. nombre"<<endl;
            cout<<"2. descripcion"<<endl;
            cin>>respModifObj;
            validarDatos(respModifObj);
            switch(respModifObj){
              case(1):{
                string nuevoNombreO;
                cout<<"ingresa el nuevo nombre:"<<endl;
                cin>>nuevoNombreO;
                aux->nombre_objeto= nuevoNombreO;
              }
              break;
              case(2):{
                string nuevaDesc;
                cout<<"ingresa la nueva descripcion:"<<endl;
                cin>> nuevaDesc;
                aux->descripcion_objeto= nuevaDesc;
              }
              break;
              default:{
                cout<<"INDIQUE NUEVAMENTE LA OPCION ";
              }
              break;
            }
          }  
          //imprimirObjeto(l, habModif);
        }
      }
    }
    aux = aux->proxCasa;
  }
}
//////////////////////////////////////////////////////////////





