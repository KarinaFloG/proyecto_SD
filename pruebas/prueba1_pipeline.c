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
	tiempo_inicio = MPI_Wtime();

	if(archivo == NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}else{
		char linea[1024];
		while(fgets(linea,1024,archivo)){
			if(pid==0){
				tag = 0;
				dato = strtod(linea,NULL);
				//printf("DATO: %f\n", dato );

				for(int i=1;i<size;i++){
					MPI_Send(&dato,1,MPI_DOUBLE, i, tag, MPI_COMM_WORLD);
				}
			}

			if(pid==1){
				tag = 0;
				MPI_Recv(&dato,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
				//printf("ID 0: %f\n",dato );
				potencia = pow(dato,0);
				MPI_Send(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);
			}else if(pid==2){
				tag = 0;
				MPI_Recv(&dato,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
				MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 
				//printf("ID 1: %f\n",dato);
				//printf("potencia en 1: %f\n",potencia );
				potencia = pow(dato,1) + potencia;
				MPI_Send(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);		
			}else if(pid==3){
				tag = 0;
				MPI_Recv(&dato,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
				MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 
				//printf("ID 2: %f\n",dato);
				//printf("potencia en 2: %f\n",potencia );			
				potencia = pow(dato,2) + potencia;
				MPI_Send(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);
			}else if(pid==4){
				tag = 0;
				MPI_Recv(&dato,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
				MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 
				//printf("ID 3: %f\n",dato);
				//printf("potencia en 3: %f\n",potencia );			
				potencia = pow(dato,3) + potencia;
				MPI_Send(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);
			}else if(pid==5){
				tag = 0;
				MPI_Recv(&dato,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
				MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 
				//printf("ID 4: %f\n",dato);
				//printf("potencia en 4: %f\n",potencia );			
				potencia = pow(dato,4) + potencia;
				MPI_Send(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);		
			}else if(pid==6){
				tag = 0;
				MPI_Recv(&dato,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
				MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 
				//printf("ID 5: %f\n",dato);
				//printf("potencia en 5: %f\n",potencia );			
				potencia = pow(dato,5) + potencia;
				MPI_Send(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);		
			}else if(pid==7){
				tag = 0;
				MPI_Recv(&dato,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
				MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 
				//printf("ID 6: %f\n",dato);
				//printf("potencia en 6: %f\n",potencia );			
				potencia = pow(dato,6) + potencia;
				MPI_Send(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);
			}else if(pid==8){
				tag = 0;
				MPI_Recv(&dato,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
				MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 
				//printf("ID 7: %f\n",dato);
				//printf("potencia en 7: %f\n",potencia );			
				potencia = pow(dato, 7)+ potencia;
				MPI_Send(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);		
			}else if(pid==9){
				tag = 0;
				MPI_Recv(&dato,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
				MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 
				//printf("ID 8: %f\n",dato);
				//printf("potencia en 8: %f\n",potencia );			
				potencia = pow(dato,8) + potencia;
				MPI_Send(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);
			}else if(pid==10){
				tag  = 0;
				MPI_Recv(&dato,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
				MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 
				//printf("ID 9: %f\n",dato);
				//printf("potencia en 9: %f\n",potencia );			
				potencia = pow(dato,9) + potencia;
				MPI_Send(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);
			}else if(pid==11){
				tag = 0;
				MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 
				//printf("POTENCIA FINAL %f\n",potencia );
				printf("Elemento: %d\n",iterador );
				iterador++;
			}
		}
		//tiempo_fin = MPI_Wtime();
		//tiempo_total = tiempo_fin - tiempo_inicio;
		//printf("El tiempo de ejecución es: %f\n", tiempo_total);
		//printf("Total de elementos: %d\n",iterador );
	}

	fclose(archivo);
	MPI_Finalize();

	return 0;
}
