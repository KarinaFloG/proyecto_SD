#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]){
  //Variables para MPI
	int pid, size, origen, destino, data_tag,terminator_tag,source_tag, result_tag;
	MPI_Status info;
	MPI_Datatype stype;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	MPI_Status status;
	double tiempo_inicio, tiempo_fin, tiempo_total;
	FILE * archivo = fopen("datos.csv","r");
	FILE * archivo_final = fopen("granja.csv","a+");
	int num_elementos = 0;
	int count_datos = 0;
	int count_proc = 0;
	int i = 0;
	int escritos = 0;
	double dato = 0, valor = 0;
	double bd[20];
	int iterador = 0;
	double potencia = 0;
	int *ptr = NULL;
	if(archivo == NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}else{
		char linea[1024];
		while(i<1){
			printf("EL valor de i es: %d\n",i );
			if(pid == 0){
				printf("Soy el maestro con pid[%d] y estoy leyendo datos\n",pid );
				while(num_elementos<20){
					fgets(linea,1024,archivo);
					//tag = 0;
					dato = strtod(linea,NULL);
					bd[num_elementos] = dato;
					num_elementos++;
				}
				MPI_Send(&bd,20,MPI_DOUBLE,ps, data_tag, MPI_COMM_WORLD);
	
			}


			if(pid == 1){
				MPI_Recv(&bd,20,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				for(int ḱ=0;k<20;k++){
					printf("Base en [%d] : %f\n",k,bd[k] );
				}
			}


			i++;
		}

	}

	fclose(archivo);
	fclose(archivo_final);
	MPI_Finalize();
	return 0;
}