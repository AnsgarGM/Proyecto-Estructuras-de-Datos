#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class nodo_consulta{

};

class nodo{

};

class arbol{

};

int main(){
  FILE * reglas;
  char **cadena, *aux_cadena;
  int cont_saltos=1, c;
  reglas=fopen("reglas.csv", "r+");
  if(reglas==NULL){
    printf("\nNo se pudo abrir archivo");
  }else{
    //aqui se empieza a construir arbol
    do{
      c=fgetc(reglas);
      if(c==10){
        cont_saltos++;
      }
    }while(c!=EOF);
    cadena=(char**)calloc(cont_saltos, sizeof(char*));
    printf("\nTermina do while y crea arreglo");
    rewind(reglas);
    for(int i=0;i=3;i++){
      fgets(aux_cadena, 100, reglas);
      printf("%s", aux_cadena);
      cadena[i]=aux_cadena;
    }

    fclose(reglas);
  }
  return 0;
}
