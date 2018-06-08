#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

class nodo_listad{ //Nodo de lista de paises
  public:
    /*
    Datos que se imprimiran de cada pais
    */
    nodo_listad *sig, *ant;
};

class nodo_listas{ //Nodo de lista de hijos de los nodos del arbol
  public:
    int indice;
    //nodo_arbol *hijo;
    nodo_listas *sig;
};

class nodo_arbol{ //Nodo de arboles
  public:
    nodo_listas *hijos;
};

class arbol{ //Clase arbol para el recorrimiento
  public:
    nodo_arbol *raiz;

    void corrimiento(){

    }
};

class lista_simple{ //Clase lista de hijos
  public:

};

class lista_doble{ ///Clase lista doble de paises
  public:

};

int validarPasaporte(char *cad){
  char *ptr;
  int ban;
  ptr=strtok(cad, " ,.-");
  while(ptr!=NULL){
    if(strcmp(ptr, "si")==0){
      ban=0;
    }else if(strcmp(ptr, "no")==0){
      ban=0;
    }else{
      ban=1;
    }
    ptr=strtok(NULL, " ,.-");
  }
  cout << "\nNo entiendo, se mas especifico" << endl;
  return ban;
}

int validarClima(char *cade){
  char *pch;
  int b;
  pch=strtok(cade, " ,.-");
  while(pch!=NULL){
    if(strcmp(pch, "calido")==0||strcmp(pch, "frio")==0){
      b=0;
    }else{
      b=1;
    }
    pch=strtok(NULL, " ,.-");
  }
  cout << "\nNo entiendo, se mas especifico" << endl;
  return b;
}

int main(){
  int opc, presupuesto, bandera=1;
  char pasaporte[50], clima[50], idioma[50];
  do{
    system("clear");
    printf("\n1.-Nueva entrada\n2.-Modificar\n7.-Salir\nSeleccion:\t");
    scanf("%d", &opc);
    switch(opc){
      case 1:
        do{
          cout << "\nTiene usted pasaporte:\t";
          fflush(stdin);
          cin.getline(pasaporte, 50);
          for(int i=0;pasaporte[i];i++){
            pasaporte[i]=tolower(pasaporte[i]);
          }
          bandera=validarPasaporte(pasaporte);
        }while(bandera);
        do{
          cout << "\nCual es su presupuesto:\t";
          cin >> presupuesto;
          if(presupuesto<7999){
            cout << "No te alcanza, prro";
          }
        }while(presupuesto<8000);
        do{
          cout << "\nQue clima le agrada:\t";
          fflush(stdin);
          cin.getline(clima, 50);
          for(int i=0;clima[i];i++){
            clima[i]=tolower(clima[i]);
          }
          bandera=validarClima(clima);
        }while(bandera);
        cout << "\nQue idiomas habla:\t";
        fflush(stdin);
        cin.getline(idioma, 50);

        cout << "Pasaporte: " << pasaporte << endl;
        cout << "Presupuesto: " << presupuesto << endl;
        cout << "Clima: " << clima << endl;
        cout << "Idiomas: " << idioma << endl;
        getchar();
      break;
      case 2:

      break;
      case 7:

      break;
      default:
        printf("\nOpcion invalida");
    }
  }while(opc!=7);
  return 0;
}
