#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


void get_walltime(double * wcTime){
  struct timeval tp;
  gettimeofday(&tp, NULL);
  *wcTime=(tp.tv_sec + tp.tv_usec /1000000.0);
}


int main(int argc, char const *argv[])
{
  int i,j;
  char dato_leido[100];
  int datos_leidos[1000000];
  FILE *fp, *fp1, *fp2, *fp3,*fp4,*fp5,*fp6,*fp7,*fp8,*fp9,*fp10,*fp11,*fp12,*fp13,*fp14,*fp15, *fp16;
  double T_inicio, T_fin;

  fp=fopen("datos8ceros.csv","r");
  fp1=fopen("datos_1.csv","w");
  fp2=fopen("datos_2.csv","w");
  fp3=fopen("datos_3.csv","w");
  fp4=fopen("datos_4.csv","w");
  fp5=fopen("datos_5.csv","w");
  fp6=fopen("datos_6.csv","w");
  fp7=fopen("datos_7.csv","w");
  fp8=fopen("datos_8.csv","w");
  fp9=fopen("datos_9.csv","w");
  fp10=fopen("datos_10.csv","w");
  fp11=fopen("datos_11.csv","w");
  fp12=fopen("datos_12.csv","w");
  fp13=fopen("datos_13.csv","w");
  fp14=fopen("datos_14.csv","w");
  fp15=fopen("datos_15.csv","w");
  fp16=fopen("datos_16.csv","w");
  if(fp == NULL){
    printf("error al crear archivo\n");
  }else{
    get_walltime(&T_inicio);
    for(j = 0; j<100000; j++){//numero de lotes
      for(i = 0 ; i< 10000; i++){
        fgets(dato_leido,100,fp);
        datos_leidos[i] = atoi(dato_leido);
        //printf("%d\n",datos_leidos[i]);
      }
      for(i = 0; i <10000; i++){
        if(datos_leidos[i] <= 8){//nodo 1
          if(datos_leidos[i] <= 4){//nodo 3
            if(datos_leidos[i] <= 2){//nodo 7
              if(datos_leidos[i] == 1){//nodo 15
                //printf("es un 1\n");
                fprintf(fp1, "%d\n",datos_leidos[i]);
              }
              if(datos_leidos[i] == 2){//nodo 16
                //printf("es un 2\n");
                fprintf(fp2, "%d\n",datos_leidos[i]);
              }
            }
            if(datos_leidos[i] > 2){//nodo 8
              if(datos_leidos[i] == 3){//nodo 17
                //printf("es un 3\n");
                fprintf(fp3, "%d\n",datos_leidos[i]);
              }
              if(datos_leidos[i] == 4){//nodo 18
                //printf("es un 4\n");
                fprintf(fp4, "%d\n",datos_leidos[i]);
              }
            }
          }
          if (datos_leidos[i] > 4){//nodo 4
            if(datos_leidos[i] <= 6){//nodo 9
              if(datos_leidos[i] == 5){//nodo 19
                //printf("es un 5\n");
                fprintf(fp5, "%d\n",datos_leidos[i]);
              }
              if(datos_leidos[i] == 6){//nodo 20
                //printf("es un 6\n");
                fprintf(fp6, "%d\n",datos_leidos[i]);
              }
            }
            if(datos_leidos[i] > 6){//nodo 10
              if(datos_leidos[i] == 7){//nodo 21
                //printf("es un 7\n");
                fprintf(fp7, "%d\n",datos_leidos[i]);
              }
              if(datos_leidos[i] == 8){//nodo 22
                //printf("es un 8\n");
                fprintf(fp8, "%d\n",datos_leidos[i]);
              }
            }
          }
        }
        if(datos_leidos[i] > 8){//nodo 2
          if(datos_leidos[i] <= 12){//nodo 5
            if(datos_leidos[i] <= 10){//nodo 11
              if(datos_leidos[i] == 9){//nodo 23
                //printf("es un 9\n");
                fprintf(fp9, "%d\n",datos_leidos[i]);
              }
              if(datos_leidos[i] == 10){//nodo 24
                //printf("es un 10\n");
                fprintf(fp10, "%d\n",datos_leidos[i]);
              }
            }
            if(datos_leidos[i] > 10){//nodo 12
              if(datos_leidos[i] == 11){//nodo 25
                //printf("es un 11\n");
                fprintf(fp11, "%d\n",datos_leidos[i]);
              }
              if(datos_leidos[i] == 12){//nodo 26
                //printf("es un 12\n");
                fprintf(fp12, "%d\n",datos_leidos[i]);
              }
            }
          }
          if(datos_leidos[i] > 12){//nodo 6
            if(datos_leidos[i] <= 14){//nodo 13
              if(datos_leidos[i] == 13){//nodo 27
                //printf("es un 13\n");
                fprintf(fp13, "%d\n",datos_leidos[i]);
              }
              if(datos_leidos[i] == 14){//nodo 28
                //printf("es un 14\n");
                fprintf(fp14, "%d\n",datos_leidos[i]);
              }
            }
            if(datos_leidos[i] > 14){//nodo 14
              if(datos_leidos[i] == 15){//nodo 29
                //printf("es un 15\n");
                fprintf(fp15, "%d\n",datos_leidos[i]);
              }
              if(datos_leidos[i] == 16){//nodo 30
                //printf("es un 16\n");
                fprintf(fp16, "%d\n",datos_leidos[i]);
              }
            }

          }
        }
      }
      //printf("****************\n");
    }

  }

  get_walltime(&T_fin);
  printf("Tiempo de ejecucion = %f\n", (T_fin-T_inicio));
  fclose(fp);
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  fclose(fp4);
  fclose(fp5);
  fclose(fp6);
  fclose(fp7);
  fclose(fp8);
  fclose(fp9);
  fclose(fp10);
  fclose(fp11);
  fclose(fp12);
  fclose(fp13);
  fclose(fp14);
  fclose(fp15);
  fclose(fp16);
  return 0;
}
