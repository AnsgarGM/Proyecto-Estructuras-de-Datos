#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main(){
  char cadena_leida[100];
  char *aux;
  int pasaporte, presupuesto, clima, *idiomas, cont_indices=0, bandera=1, hacer=0, vez=1;
  idiomas=(int*)calloc(6, sizeof(int));
  //--------------------------------------------------------------------Lee pasaporte--------------------------------------------------------------------
  do{
    bandera=1;
    system("clear");
    printf("\nTiene usted pasaporte:\t");
    cin.getline(cadena_leida, 100);
    for(int i=0;cadena_leida[i];i++){
      cadena_leida[i]=tolower(cadena_leida[i]);
    }
    aux=strtok(cadena_leida, " ,.-\n");
    while(aux!=NULL){
      if(strcmp(aux, "si")==0){
        pasaporte=1;
        bandera=0;
        hacer=0;
        break;
      }else if(strcmp(aux, "no")==0){
        pasaporte=0;
        bandera=0;
        hacer=0;
        break;
      }else{
        hacer=1;
        goto s;
      }
      aux=strtok(NULL, " ,.-\n");
    }
    s:
    if(hacer)
      printf("\nNo entiendo");
  }while(bandera);

  //--------------------------------------------------------------------Lee presupuesto--------------------------------------------------------------------
  do{
    bandera=1;
    system("clear");
    printf("\nCual es su presupuesto:\t");
    cin >> presupuesto;
    if(presupuesto<8000){
      system("clear");
      printf("\nNo te alcanza para un buen viaje, intenta de nuevo");
    }else{
      bandera=0;
    }
  }while(bandera);

  //-----------------------------------------------------------------------Lee clima-----------------------------------------------------------------------
  do{
    system("clear");
    bandera=1;
    printf("\nQue clima le agrada:\t");
    if(vez){
      cin.ignore();
      vez=0;
    }
    cin.getline(cadena_leida, 100);
    for(int i=0;cadena_leida[i];i++){
      cadena_leida[i]=tolower(cadena_leida[i]);
    }
    aux=strtok(cadena_leida, " ,.-\n");
    while(aux!=NULL){
      if(strcmp(aux, "frio")==0){
        clima=1;
        bandera=0;
        hacer=0;
        break;
      }else if(strcmp(aux, "calido")==0){
        clima=0;
        bandera=0;
        hacer=0;
        break;
      }else{
        hacer=1;
        goto salir;
      }
      aux=strtok(NULL, " ,.-\n");
    }
    salir:
    if(hacer)
      printf("\nNo entiendo");
  }while(bandera);

  //---------------------------------------------------------------------Lee idiomas---------------------------------------------------------------------
  system("clear");
  printf("\nQue idiomas habla:\t");
  cin.getline(cadena_leida, 100);
  for(int i=0;cadena_leida[i];i++){
    cadena_leida[i]=tolower(cadena_leida[i]);
  }
  aux=strtok(cadena_leida, " ,.-\n");
  while(aux!=NULL){
    if(strcmp(aux, "español")==0){
      idiomas[cont_indices]=1;
      cont_indices++;
    }
    if(strcmp(aux, "ingles")==0){
      idiomas[cont_indices]=2;
      cont_indices++;
    }
    if(strcmp(aux, "aleman")==0){
      idiomas[cont_indices]=3;
      cont_indices++;
    }
    if(strcmp(aux, "ruso")==0){
      idiomas[cont_indices]=4;
      cont_indices++;
    }
    if(strcmp(aux, "frances")==0){
      idiomas[cont_indices]=5;
      cont_indices++;
    }
    if(strcmp(aux, "chino")==0){
      idiomas[cont_indices]=6;
      cont_indices++;
    }
    aux=strtok(NULL, " ,.-\n");
  }

    system("clear");
    printf("\nPasaporte: %d", pasaporte);
    printf("\nPresupuesto: %d", presupuesto);
    printf("\nClima: %d", clima);
    for(int i=0;i<6;i++){
      if(idiomas[i]!=0){
        printf("\nIdiomas: %d", idiomas[i]);
      }
    }
    printf("\n");
  return 0;
}
