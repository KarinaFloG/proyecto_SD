#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAESTRO 0
#define COL 2
#define REN 2
#define TAG_DAT 1


int main(int argc, char** argv) {
  int rank, size, ascii;
  int cont = 0;
  //char rbuf[size][10];

  /*Máximo 6 para evitar letras raras*/

  MPI_Init(&argc, &argv);
  MPI_Status info;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  int nodo_id, i, j;
  int orden = (int)sqrt(size);
  double tInicio, tFinal;
  char *rbuf;

  nodo_id = rank;
  j = nodo_id % orden;
  i = (int)floor(nodo_id /orden);


  if (nodo_id == MAESTRO) {
    rbuf = (char *)malloc(size*10*sizeof(char));
    tInicio = MPI_Wtime();
  }
  MPI_Barrier(MPI_COMM_WORLD);

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

    //printf("Soy el proceso con id: %d mi etiqueta es: %c\n",rank,matriz[i][j]);
    int vecinosSI, vecinosAR, vecinosSD, vecinosDER, vecinosID, vecinosAB, vecinosII, vecinosIZQ, nodoDest, nodoRemi;
    char rec;
    char palabra[10];
    palabra[0] = matriz[i][j];
    int eti_sig = 1;
    MPI_Barrier(MPI_COMM_WORLD);

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


    if(vecinosSI == 1){
      nodoRemi = rank - orden - 1;
      MPI_Recv(&rec,1, MPI_CHAR, nodoRemi, TAG_DAT, MPI_COMM_WORLD, &info);
      palabra[eti_sig] = rec;
      eti_sig ++;
    }if(vecinosID == 1){
        nodoDest = rank + orden + 1;
        char *ma = matriz[i][j];
        MPI_Send(&ma,1,MPI_CHAR,nodoDest,TAG_DAT,MPI_COMM_WORLD);
      }

    if(vecinosAR == 1){
      nodoRemi = rank - orden;
      MPI_Recv(&rec,1, MPI_CHAR, nodoRemi, TAG_DAT, MPI_COMM_WORLD, &info);
      palabra[eti_sig] = rec;
      eti_sig ++;
    }if(vecinosAB == 1){
        nodoDest = rank + orden;
        char *ma = matriz[i][j];
        MPI_Send(&ma,1,MPI_CHAR,nodoDest,TAG_DAT,MPI_COMM_WORLD);
      }


    if(vecinosSD == 1){
      nodoRemi = rank - orden + 1;
      MPI_Recv(&rec,1, MPI_CHAR, nodoRemi, TAG_DAT, MPI_COMM_WORLD, &info);
      palabra[eti_sig] = rec;
eti_sig ++;
    }if(vecinosII == 1){
        nodoDest = rank + orden - 1;
        char *ma = matriz[i][j];
        MPI_Send(&ma,1,MPI_CHAR,nodoDest,TAG_DAT,MPI_COMM_WORLD);
      }

    if(vecinosDER == 1){
      nodoRemi = rank + 1;
      MPI_Recv(&rec,1, MPI_CHAR, nodoRemi, TAG_DAT, MPI_COMM_WORLD, &info);
      palabra[eti_sig] = rec;
eti_sig ++;
    }if(vecinosIZQ == 1){
        nodoDest = rank - 1;
        char *ma = matriz[i][j];
        MPI_Send(&ma,1,MPI_CHAR,nodoDest,TAG_DAT,MPI_COMM_WORLD);
      }

    if(vecinosID == 1){
      nodoRemi = rank + orden + 1;
      MPI_Recv(&rec,1, MPI_CHAR, nodoRemi, TAG_DAT, MPI_COMM_WORLD, &info);
      palabra[eti_sig] = rec;
eti_sig ++;
    }if(vecinosSI == 1){
        nodoDest = rank - orden - 1;
        char *ma = matriz[i][j];
        MPI_Send(&ma,1,MPI_CHAR,nodoDest,TAG_DAT,MPI_COMM_WORLD);
      }


    if(vecinosAB == 1){
      nodoRemi = rank + orden;
      MPI_Recv(&rec,1, MPI_CHAR, nodoRemi, TAG_DAT, MPI_COMM_WORLD, &info);
      palabra[eti_sig] = rec;
eti_sig ++;
    }if(vecinosAR == 1){
        nodoDest = rank - orden;
        char *ma = matriz[i][j];
        MPI_Send(&ma,1,MPI_CHAR,nodoDest,TAG_DAT,MPI_COMM_WORLD);
      }


    if(vecinosII == 1){
      nodoRemi = rank + orden - 1;
      MPI_Recv(&rec,1, MPI_CHAR, nodoRemi, TAG_DAT, MPI_COMM_WORLD, &info);
      palabra[eti_sig] = rec;
eti_sig ++;
    }if(vecinosSD == 1){
        nodoDest = rank - orden + 1;
        char *ma = matriz[i][j];
        MPI_Send(&ma,1,MPI_CHAR,nodoDest,TAG_DAT,MPI_COMM_WORLD);
      }

    if(vecinosIZQ == 1){
      nodoRemi = rank - 1;
      MPI_Recv(&rec,1, MPI_CHAR, nodoRemi, TAG_DAT, MPI_COMM_WORLD, &info);
      palabra[eti_sig] = rec;
      eti_sig ++;
    }if(vecinosDER == 1){
        nodoDest = rank + 1;
        char *ma = matriz[i][j];
        MPI_Send(&ma,1,MPI_CHAR,nodoDest,TAG_DAT,MPI_COMM_WORLD);
      }

    palabra[eti_sig] = '*';
    printf("Soy el proceso con id: %d mi palabra es: %s\n",rank, &palabra);
    MPI_Gather(palabra, 10, MPI_CHAR, rbuf, 10, MPI_CHAR, MAESTRO, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);

    if (nodo_id == MAESTRO) {
      FILE *fp = fopen("resultado_malla.txt","w");
      if(fp == NULL){
        printf("error al crear archivo\n");}
      int apunt = 0;
      fprintf(fp, "La matriz inicial: \n\n");
      for (size_t i = 0; i < orden; i++) {
        for (size_t j = 0; j < orden; j++) {
          fprintf(fp, "%c ", matriz[i][j]);
        }
        fprintf(fp, "\n");
      }
      fprintf(fp, "\n");
      for (size_t i = 0; i < size; i++) {
        apunt = 10*i;
        while (rbuf[apunt] != '*') {
          fprintf(fp, "%c", rbuf[apunt]);
          apunt++;
        }
        fprintf(fp, "\n");
      }
      fclose(fp);
      tFinal = MPI_Wtime();
      printf("Tiempo de ejecución: %.10lf\n",tFinal - tInicio);
    }
  MPI_Finalize();

  return 0;
  }
