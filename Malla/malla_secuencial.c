#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define COL 2
#define REN 2

void get_walltime(double * wcTime){
  struct timeval tp;
  gettimeofday(&tp, NULL);
  *wcTime=(tp.tv_sec + tp.tv_usec /1000000.0);
}

void vecinos(char **matriz[REN][COL], int i, int j, char palabra[10]){
  int vecinosSI, vecinosAR, vecinosSD, vecinosDER, vecinosID, vecinosAB, vecinosII, vecinosIZQ;
  strcat(palabra,&matriz[i][j]);
  vecinosSI = 1;
  vecinosAR = 1;
  vecinosSD = 1;
  vecinosDER = 1;
  vecinosID = 1;
  vecinosAB = 1;
  vecinosII = 1;
  vecinosIZQ = 1;

  if(i == 0){
    vecinosSI = 0;
    vecinosAR = 0;
    vecinosSD = 0;
  }

  if(i == REN-1){
    vecinosID = 0;
    vecinosAB = 0;
    vecinosII = 0;
  }
  if(j == 0){
      vecinosSI = 0;
      vecinosII = 0;
      vecinosIZQ = 0;
  }
  if(j == COL-1){
      vecinosSD = 0;
      vecinosDER = 0;
      vecinosID = 0;
  }
  //matriz[i][j] = etiqueta;
  if(vecinosSI == 1){
    strcat(palabra,&matriz[i-1][j-1]);

  }
  if(vecinosAR == 1){
    strcat(palabra,&matriz[i-1][j]);
  }
  if(vecinosSD == 1){
    strcat(palabra,&matriz[i-1][j+1]);
  }
  if(vecinosDER == 1){
    strcat(palabra,&matriz[i][j+1]);
  }
  if(vecinosID == 1){
    strcat(palabra,&matriz[i+1][j+1]);
  }
  if(vecinosAB == 1){
    strcat(palabra,&matriz[i+1][j]);
  }
  if(vecinosII == 1){
    strcat(palabra,&matriz[i+1][j-1]);
  }
  if(vecinosIZQ == 1){
    strcat(palabra,&matriz[i][j-1]);
  }

}
int main(int argc, char const *argv[])
{
  int i,j;
  char palabra[10];
  FILE *fp;
  double T_inicio, T_fin;
  char **matriz[REN][COL] = {{'a','M'},
                             {'G','e'}};

  /*char **matriz[REN][COL] = {{'i','d','S'},
                             {'A','f','E'},
                             {'R','D','J'}};*/

  /*char **matriz[REN][COL] = {{'H','j','s','p'},
                             {'A','R','z','U'},
                             {'m','T','P','j'},
                             {'z','X','k','N'}};*/

  /*char **matriz[REN][COL] = {{'O','w','I','B','p'},
                             {'k','k','g','K','h'},
                             {'Y','e','k','Y','D'},
                             {'O','E','u','W','k'},
                             {'m','j','W','e','V'}};*/

  /*char **matriz[REN][COL] = {{'d','D','W','m','D','I'},
                             {'Q','p','B','m','f','P'},
                             {'E','F','q','w','T','A'},
                             {'N','A','d','D','n','c'},
                             {'I','Q','d','R','j','L'},
                             {'W','c','r','U','B','i'}};*/

  fp=fopen("resultado_malla_sec.txt","w");
  if(fp == NULL){
    printf("error al crear archivo\n");
  }else{
    get_walltime(&T_inicio);
    fprintf(fp, "La matriz inicial: \n\n");
    for (size_t i = 0; i < REN; i++) {
      for (size_t j = 0; j < COL; j++) {
        fprintf(fp, "%c ", matriz[i][j]);
      }
      fprintf(fp, "\n");
    }
    fprintf(fp, "\n");

    for(i = 0 ; i< REN; i++){
      for(j = 0 ; j< COL ; j++){

          vecinos(matriz,i,j,palabra);
          printf("%s\n", &palabra);
          fprintf(fp, "%s\n", palabra);
          strcpy(palabra,"");
          printf("%s\n", &palabra);

      }
    }

  }

  get_walltime(&T_fin);
  printf("Tiempo de ejecucion = %f\n", (T_fin-T_inicio));
  fclose(fp);


  return 0;
}
