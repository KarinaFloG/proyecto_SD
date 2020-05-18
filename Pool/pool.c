#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv[]){
  //Variables para MPI
	int pid, size, origen, destino, data_tag,terminator_tag,source_tag, result_tag;
	MPI_Status info;
	MPI_Datatype stype;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	MPI_Status status;
	FILE * archivo = fopen("datos.csv","r");
	FILE * archivo_final = fopen("granjaPollos.csv","a+");
	int num_elementos = 0;
	int count_datos = 0;
	int count_proc = 0;
	int i = 0;
	double dato = 0, valor = 0;
	double bd[100000];
	int iterador = 0;
	double potencia = 0;
	if(archivo == NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}else{
		char linea[1024];
		while(i<100){
			if(pid == 0){
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
					valor = bd[iterador];
					count_proc++;
					MPI_Ssend(&valor,1,MPI_DOUBLE, j, data_tag, MPI_COMM_WORLD);
					count_datos++;
					iterador++;

				}
	
			}

			if(pid == 1){
				source_tag = 0;
				result_tag = 3;
				
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				//printf("DATO en 1: %f\n",valor );
				
				do{
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Ssend(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
					//printf("DATO en 1: %f\n",valor );
				}while(source_tag == data_tag);
				//{

				//}
			}else if(pid == 2){
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				do{
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Ssend(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
					//printf("DATO en 1: %f\n",valor );
				}while(source_tag == data_tag);	
			}else if(pid == 3){
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				//printf("DATO en 3: %f\n",valor );
				do{
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Ssend(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
					//printf("DATO en 1: %f\n",valor );
				}while(source_tag == data_tag);
			}else if(pid == 4){
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				do{
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Ssend(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
					//printf("DATO en 1: %f\n",valor );
				}while(source_tag == data_tag);
			}else if(pid == 5){
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				do{
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Ssend(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
					//printf("DATO en 1: %f\n",valor );
				}while(source_tag == data_tag);
			}else if(pid == 6){
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				do{
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Ssend(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
					//printf("DATO en 1: %f\n",valor );
				}while(source_tag == data_tag);
			}else if(pid == 7){
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				do{
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Ssend(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
					//printf("DATO en 1: %f\n",valor );
				}while(source_tag == data_tag);
			}else if(pid == 8){
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				do{
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Ssend(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
					//printf("DATO en 1: %f\n",valor );
				}while(source_tag == data_tag);
			}else if(pid == 9){
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				do{
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					
					MPI_Ssend(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
					//printf("DATO en 1: %f\n",valor );
				}while(source_tag == data_tag);
			}else if(pid == 10){
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				do{
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					MPI_Ssend(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
					//printf("DATO en 1: %f\n",valor );
				}while(source_tag == data_tag);
			}else if(pid == 11){
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				do{
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					MPI_Ssend(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
					//printf("DATO en 1: %f\n",valor );
				}while(source_tag == data_tag);
			}else if(pid == 12){
				source_tag = 0;
				result_tag = 3;

				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				do{
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					MPI_Ssend(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
					//printf("DATO en 1: %f\n",valor );
				}while(source_tag == data_tag);
			}else if(pid == 13){
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				do{
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					MPI_Ssend(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
					//printf("DATO en 1: %f\n",valor );
				}while(source_tag == data_tag);
			}else if(pid == 14){
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				do{
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					MPI_Ssend(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
					//printf("DATO en 1: %f\n",valor );
				}while(source_tag == data_tag);
			}else if(pid == 15){
				source_tag = 0;
				result_tag = 3;
				MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
				do{
					potencia = 0;
					for(int k = 0; k < 10; k++){
						potencia = potencia + pow(valor,k);
					}
					MPI_Ssend(&potencia,1,MPI_DOUBLE,0,result_tag, MPI_COMM_WORLD);
					MPI_Recv(&valor,1,MPI_DOUBLE,0,source_tag, MPI_COMM_WORLD, &info);
					//printf("DATO en 1: %f\n",valor );
				}while(source_tag == data_tag);
			}

			if(pid==0){
				do{
					result_tag = 3;
					data_tag = 0;
					MPI_Recv(&potencia,1,MPI_DOUBLE, MPI_ANY_SOURCE,result_tag, MPI_COMM_WORLD, &info);
					int ps = info.MPI_SOURCE;
					printf("SOY id[%d] y la potencia es: %f\n",ps,potencia );
					//printf("STATUS: %d\n",ps);
					//if(archivo_final == NULL){
						//perror("Error en la apertura del archivo");
						//return 1;
					//}else{
							fprintf(archivo_final,"%.1f\n", potencia); 
					//}
					//f("Potencia final: %f\n",potencia);
					count_proc--;
					if(count_datos < 100000){
						//printf("COUNT: %d\n",count_datos );
						valor = bd[count_datos];
						//printf("VALOOOOOOR: %f a %d\n",valor,ps );

						MPI_Send(&valor,1,MPI_DOUBLE,ps, data_tag, MPI_COMM_WORLD);	
						count_datos++;
						count_proc++;
					}else{
						terminator_tag = 1;
						MPI_Send(NULL,1,MPI_DOUBLE,ps, terminator_tag, MPI_COMM_WORLD);	
					}
				}while(count_proc>0);				
			}

			i++;
		}
	}
	MPI_Finalize();
	return 0;
}