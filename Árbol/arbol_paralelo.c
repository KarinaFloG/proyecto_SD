#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ROOT 0
#define TAG_DAT 1
#define NUM_LOTES 5000
#define NUM_DATOSxLOTE 10000


int main(int argc, char** argv) {
  int rank, size;
  double tInicio, tFinal;

  MPI_Init(&argc, &argv);
  MPI_Status info;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  /*Los niveles y id comoenzan en 1*/
  int elemento_profundidad,nivel, nodo_id, val_recv, nodo_dest, nodo_remi;
  if(rank != 0){
    nodo_id = rank;
    nivel = floor(log(rank)/log(2) + 1);
    elemento_profundidad = rank + 1 - pow(2,nivel-1);
  }


  if (rank == ROOT) {
    tInicio = MPI_Wtime();
    nodo_id = rank;
    nivel = 0;
    elemento_profundidad = 0;
    char dato[100];
    FILE *datos = fopen("datos8ceros.csv","r");
    int i,j;
    int datos_leidos[NUM_DATOSxLOTE];

    if(datos == NULL){
      return -1;
    }else{
      for(j = 0; j< NUM_LOTES; j++){
        for(i = 0; i< NUM_DATOSxLOTE; i++){
          fgets(dato,100,datos);
          datos_leidos[i] = atoi(dato);
          //printf("Soy el MAESTRO con id: %d lei el dato: %d de la base de datos\n",rank,datos_leidos[i]);
        }
        //printf("Soy el MAESTRO termine de leer el lote de datos numero %d\n",j+1);
        MPI_Send(datos_leidos,NUM_DATOSxLOTE,MPI_INT,1,TAG_DAT,MPI_COMM_WORLD);
      }
    }

  }

  switch(nivel){
    case 1:
    ;
      //printf("Soy el nodo raiz con id:%d, profundidad: %d y elemento en profundidad: %d\n",rank,nivel,elemento_profundidad);
      int datos_leidos[NUM_DATOSxLOTE];
      for (int j = 0; j < NUM_LOTES; j++){
          MPI_Recv(datos_leidos, NUM_DATOSxLOTE, MPI_INT, 0, TAG_DAT, MPI_COMM_WORLD, &info);
          //printf("nodo 1 recibi del MAESTRO un lote de datos:\n");
          for (int i = 0; i < NUM_DATOSxLOTE; i++){
          //printf("dato: %d\n", datos_leidos[i]);
            nodo_dest = datos_leidos[i] <= 8 ? 2 : 3;
            MPI_Send(&datos_leidos[i], 1, MPI_INT, nodo_dest , TAG_DAT, MPI_COMM_WORLD);
          }
      }
      val_recv = 0;
      MPI_Send(&val_recv, 1, MPI_INT, 2 , TAG_DAT, MPI_COMM_WORLD);
      MPI_Send(&val_recv, 1, MPI_INT, 3 , TAG_DAT, MPI_COMM_WORLD);
      break;
    case 2:
      //printf("Soy un nodo rama con id:%d, profundidad: %d y elemento en profundidad: %d\n",rank,nivel,elemento_profundidad);
      nodo_remi = floor(nodo_id/2); //Puede afuera
      MPI_Recv(&val_recv, 1, MPI_INT, nodo_remi, TAG_DAT, MPI_COMM_WORLD, &info);
      while(val_recv > 0 && val_recv <= 16){
        if (nodo_id == 2) {
          nodo_dest = val_recv <= 4 ? 4 : 5;
        }else {
          nodo_dest = val_recv <= 12 ? 6 : 7;
        }
        MPI_Send(&val_recv, 1, MPI_INT, nodo_dest , TAG_DAT, MPI_COMM_WORLD);
        MPI_Recv(&val_recv, 1, MPI_INT, nodo_remi, TAG_DAT, MPI_COMM_WORLD, &info);
      }

      //printf("Valor obtenido de: %d, para el rank: %d; \n",nodo_remi-1,rank);

      /*Envío de mensajes de finalización*/
      val_recv = 0;
      MPI_Send(&val_recv, 1, MPI_INT, rank*2, TAG_DAT, MPI_COMM_WORLD);
      MPI_Send(&val_recv, 1, MPI_INT, rank*2+1, TAG_DAT, MPI_COMM_WORLD);
      //printf("Todos los nodos notificados %d rank\n", rank );

      break;
    case 3:
      //printf("Soy un nodo hoja con id:%d, profundidad: %d y elemento en profundidad: %d\n",rank,nivel,elemento_profundidad);
      nodo_remi = floor(nodo_id/2);
      MPI_Recv(&val_recv, 1, MPI_INT, nodo_remi, TAG_DAT, MPI_COMM_WORLD, &info);
      while (val_recv > 0 && val_recv <= 16) {
        if (nodo_id == 4) {
          nodo_dest = val_recv <= 2 ? 8 : 9;
        }else if(nodo_id == 5){
          nodo_dest = val_recv <= 6 ? 10 : 11;
        }else if (nodo_id == 6) {
          nodo_dest = val_recv <= 10 ? 12 : 13;
        }else if (nodo_id == 7) {
          nodo_dest = val_recv <= 14 ? 14 : 15;
        }
        MPI_Send(&val_recv, 1, MPI_INT, nodo_dest , TAG_DAT, MPI_COMM_WORLD);
        MPI_Recv(&val_recv, 1, MPI_INT, nodo_remi, TAG_DAT, MPI_COMM_WORLD, &info);
      }
      //printf("Valor obtenido de: %d, para el rank: %d; \n",nodo_remi-1,rank);

      /*Envío de mensajes de finalización*/
      val_recv = 0;
      MPI_Send(&val_recv, 1, MPI_INT, rank*2, TAG_DAT, MPI_COMM_WORLD);
      MPI_Send(&val_recv, 1, MPI_INT, rank*2 +1 , TAG_DAT, MPI_COMM_WORLD);
      //printf("Todos los nodos notificados %d rank\n", rank );
      break;

    case 4:
      nodo_remi = floor(nodo_id/2);
      MPI_Recv(&val_recv, 1, MPI_INT, nodo_remi, TAG_DAT, MPI_COMM_WORLD, &info);
      while(val_recv > 0 && val_recv <= 16) {
        MPI_Send(&val_recv, 1, MPI_INT, 15 + val_recv, TAG_DAT, MPI_COMM_WORLD);
        MPI_Recv(&val_recv, 1, MPI_INT, nodo_remi, TAG_DAT, MPI_COMM_WORLD, &info);
      }
      //printf("Valor obtenido de: %d, para el rank: %d; \n",nodo_remi-1,rank);

      /*Envío de mensajes de finalización*/
      val_recv = 0;
      MPI_Send(&val_recv, 1, MPI_INT, rank*2 , TAG_DAT, MPI_COMM_WORLD);
      MPI_Send(&val_recv, 1, MPI_INT, rank*2 +1, TAG_DAT, MPI_COMM_WORLD);
      //printf("Todos los nodos notificados %d rank\n", rank );
    break;

    case 5:
      nodo_remi = floor(nodo_id/2);
      char nomFile[12];
      char bufer[3];
      strcpy(nomFile,"");
      strcat(nomFile,"arbol_");//6
      sprintf(bufer, "%d", rank - 15);
      strcat(nomFile,bufer);
      strcat(nomFile,".txt");//4
      FILE *fp = fopen(nomFile,"w");
      if(fp == NULL)
        printf("error al crear archivo\n");

      MPI_Recv(&val_recv, 1, MPI_INT, nodo_remi, TAG_DAT, MPI_COMM_WORLD, &info);
      //printf("\nSoy el nodo ID = %d, el valor llegado es: %d \n", nodo_id, val_recv);
      while(val_recv > 0 && val_recv <= 16) {
        fprintf(fp, "%d \n", val_recv);
        MPI_Recv(&val_recv, 1, MPI_INT, nodo_remi, TAG_DAT, MPI_COMM_WORLD, &info);
        //printf("\nSoy el nodo ID = %d, el valor llegado es: %d \n", nodo_id, val_recv);
      }
      fclose(fp);
  }

  if (rank == ROOT) {
    tFinal = MPI_Wtime();
    printf("Tiempo de ejecución: %.10lf\n",tFinal - tInicio);
  }
  MPI_Finalize();
  return 0;
}
