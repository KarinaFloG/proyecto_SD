#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv[]){
  //Variables para MPI
	int pid, size, origen, destino, tag;
	MPI_Status info;
	MPI_Datatype stype;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	//Variables para el problema
	int total_nomb = 20000;
	char id[10],numero1[10], numero2[10], numero3[10], numero4[10];
	int ids, cal1, cal2,cal3;
	//Tablas de conversión para los puntajes
	int contador = 0; // Para controlar el csv
	int datos[4]; //Para guardar los datos del csv y hacer las conversiones
	int arrPuntaje[5];
	int calificacion  = 0;
	int identificador = 0;
	double tiempo_inicio, tiempo_fin, tiempo_total;
	FILE * archivo = fopen("datos.csv","r");
	double dato = 0;
	double potencia = 0;
	int iterador = 0;
	int num_elementos = 0;
	double bd[100000];
	int i = 0;
	if(archivo == NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}else{
		char linea[1024];
		while(i<2){
			if(pid == 0){
				num_elementos = 0;
				while(num_elementos<100000){
					fgets(linea,1024,archivo);
					tag = 0;
					dato = strtod(linea,NULL);
					bd[num_elementos] = dato;
					if(num_elementos==0){
						printf("Dato[%d] %f\n",num_elementos,dato);
					}

					num_elementos++;
				}
				MPI_Send(&bd,100000,MPI_DOUBLE, 1, tag, MPI_COMM_WORLD);

			}


			if(pid==1){
				tag = 0;
				MPI_Recv(&bd,100000,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
				//printf("Dato en 0: %f\n",bd[0] );
			}
			i++;
		}


	}
	fclose(archivo);
	MPI_Finalize();

	return 0;
}
