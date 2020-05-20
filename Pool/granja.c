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
	int l = 0;
	double dato = 0, valor = 0;
	double bd[100000];
	int iterador = 0;
	double potencia = 0;
	int *ptr = NULL;
	if(archivo == NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}else{
		char linea[1024];
		while(i<100){
			printf("Llegueeee: %d\n", pid);
			count_datos = 0;
			count_proc = 0;

			if(pid == 0){
				printf("Soy el maestro con pid[%d] y estoy leyendo datos\n",pid );
				num_elementos = 0;
				while(num_elementos<100000){
					fgets(linea,1024,archivo);
					//tag = 0;
					dato = strtod(linea,NULL);
					bd[num_elementos] = dato;
					num_elementos++;
				}	
				iterador = 0;
				for(int j = 1;j < size; j++){
					data_tag = 0;
					source_tag=0;
					valor = bd[iterador];
					
					MPI_Ssend(&valor,1,MPI_DOUBLE, j, data_tag, MPI_COMM_WORLD);
					count_proc++;
					count_datos++;
					printf("Ya lo mande: %d\n", count_proc);
					iterador++;

				}
	
			}

			
				

				if(pid == 1){
				data_tag = 0;
				source_tag = 0;
				result_tag = 3;
				l++;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				printf("Me llego %d\n", l);
				while(source_tag == data_tag){
					//printf("Si estoy trabajando eh \n");
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Send(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
					//printf("Soy el esclavo con pid[%d] y recibo datos del pid[0]\n",pid );
				}

			}else if(pid == 2){
				//printf("Soy el esclavo con pid[%d] y recibo datos del pid[0]\n", pid);
				data_tag = 0;
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				while(source_tag == data_tag){
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Send(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				}	
			}else if(pid == 3){
				printf("Soy el esclavo con pid[%d] y recibo datos del pid[0]\n", pid);
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				while(source_tag == data_tag){
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Send(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				}
			}else if(pid == 4){
				printf("Soy el esclavo con pid[%d] y recibo datos del pid[0]\n", pid);
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				while(source_tag == data_tag){
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Send(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				}
			}else if(pid == 5){
				printf("Soy el esclavo con pid[%d] y recibo datos del pid[0]\n", pid);
				data_tag = 0;
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				while(source_tag == data_tag){
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Send(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				}
			}else if(pid == 6){
				printf("Soy el esclavo con pid[%d] y recibo datos del pid[0]\n", pid);
				data_tag = 0;
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				while(source_tag == data_tag){
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Send(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				}
			}else if(pid == 7){
				printf("Soy el esclavo con pid[%d] y recibo datos del pid[0]\n", pid);
				source_tag = 0;
				data_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				while(source_tag == data_tag){
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Send(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				}
			}else if(pid == 8){
				printf("Soy el esclavo con pid[%d] y recibo datos del pid[0]\n", pid);
				data_tag = 0;
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				while(source_tag == data_tag){
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Send(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				}
			}else if(pid == 9){
				printf("Soy el esclavo con pid[%d] y recibo datos del pid[0]\n",pid );
				source_tag = 0;
				data_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				while(source_tag == data_tag){
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Send(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				}
			}else if(pid == 10){
				printf("Soy el esclavo con pid[%d] y recibo datos del pid[0]\n", pid);
				source_tag = 0;
				data_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				while(source_tag == data_tag){
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					MPI_Send(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				}
			}else if(pid == 11){
				printf("Soy el esclavo con pid[%d] y recibo datos del pid[0]\n", pid);
				source_tag = 0;
				data_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				while(source_tag == data_tag){
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					MPI_Send(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				}
			}else if(pid == 12){
				printf("Soy el esclavo con pid[%d] y recibo datos del pid[0]\n", pid);
				source_tag = 0;
				result_tag = 3;
				data_tag = 0;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				while(source_tag == data_tag){
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					MPI_Send(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				}
			}else if(pid == 13){
				printf("Soy el esclavo con pid[%d] y recibo datos del pid[0]\n", pid);
				source_tag = 0;
				data_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				while(source_tag == data_tag){
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					MPI_Send(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				}
			}else if(pid == 14){
				printf("Soy el esclavo con pid[%d] y recibo datos del pid[0]\n", pid);
				source_tag = 0;
				result_tag = 3;
				data_tag = 0;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				while(source_tag == data_tag){
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					MPI_Send(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
					if(count_datos==99999){
						printf("Aquime quedeeee\n");
					}
				}
			}else if(pid == 15){
				//printf("Soy el esclavo con pid[%d] y recibo datos del pid[0]\n", pid);
				source_tag = 0;
				data_tag = 0;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				while(source_tag == data_tag){
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					MPI_Send(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				}
			}

				if(pid==0){
				while(count_proc>1){
					result_tag = 3;
					data_tag = 0;
					MPI_Recv(&potencia,1,MPI_DOUBLE, MPI_ANY_SOURCE,result_tag, MPI_COMM_WORLD, &info);
					//printf("COUNT DATOS: %d\n", count_datos);
					int ps = info.MPI_SOURCE;
							//sleep(0.09);
					fprintf(archivo_final,"%.1f\n", potencia); 
					count_proc--;
					//printf("Contador de procesadores: %d\n",count_proc );
					//printf("Contador de datos: %d\n",count_datos );
					if(count_datos < 100000){
						valor = bd[count_datos];
						//sleep(0.08);
						printf("Soy el maestro con pid[%d] y llevo %d\n datos\n",pid,count_datos );
						//printf("Count datos %d\n",count_datos );
						MPI_Send(&valor,1,MPI_DOUBLE,ps, data_tag, MPI_COMM_WORLD);	
						count_datos++;
						count_proc++;
						//printf("Count: %d\n", count_proc);
					}else{
						valor = 0;
						source_tag = 1;
						//printf("Entra aqui\n");
						MPI_Send(&valor,1,MPI_DOUBLE,ps, source_tag, MPI_COMM_WORLD);	
						//printf("Despues del entra aqui xD\n");
						//count_proc--;
						//printf("Count: %d\n", count_proc);
					}
			}
			//printf("Contador de procesadores: %d\n",count_proc );
			//printf("Contador de datos: %d\n",count_datos );
				i++;
				//printf("Pinto %d\n",i );				
			}

		}
		
	}
	
	if(pid==0){
		tiempo_fin = MPI_Wtime();
		tiempo_total = tiempo_fin - tiempo_inicio;
		printf("\nEl tiempo de ejecución es: %f", tiempo_total);
	}
	
	fclose(archivo);
	fclose(archivo_final);
	
	return 0;
}