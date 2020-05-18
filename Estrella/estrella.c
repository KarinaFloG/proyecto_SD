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
	double tiempo_inicio, tiempo_fin, tiempo_total;
	FILE * archivo = fopen("datos.csv","r");
	FILE * archivo_final = fopen("potenciasLingo.csv","a+");
	double valor = 0;
	double dato = 0;
	double suma = 0;
	double potencia = 0;
	int num_elementos = 0;
	int inicio = 0, frontera = 0;	
	double bd[100000];
	double potencias[6667];
	int i = 0;
	int it =0;

	if(archivo == NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}else{
		char linea[1024];
		while(i<100){
			suma = 0;
			if(pid == 0){
				num_elementos = 0;
				while(num_elementos<100000){
					fgets(linea,1024,archivo);
					tag = 0;
					dato = strtod(linea,NULL);
					bd[num_elementos] = dato;
					num_elementos++;
				}

				for(int j = 1;j<16;j++){
					
					MPI_Ssend(&bd,sizeof(bd)/sizeof(bd[0]),MPI_DOUBLE, j, tag, MPI_COMM_WORLD);
				}
					
				
			}
			
				if(pid==1){
					tag = 0;
					int inicio = (pid-1)*6667; //1*6667 = 6667       
					int frontera = inicio + 6667; //6667+6667=13334 
					MPI_Recv(&bd,sizeof(bd)/sizeof(bd[0]),MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					it = 0;
					for(int k = inicio; k<frontera; k++){
						double aux = 0;
						for(int p=0; p<10; p++){
							aux = aux + pow(bd[k], p);
						}
						potencias[it]=aux;
						it++;
					}
					MPI_Send(&potencias,6667,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);

				}else if(pid==2){
					tag = 0;
					int inicio = (pid-1)*6667; //1*6667 = 6667       
					int frontera = inicio + 6667; //6667+6667=13334 
					MPI_Recv(&bd,sizeof(bd)/sizeof(bd[0]),MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					it = 0;
					for(int k = inicio; k<frontera; k++){
						double aux = 0;
						for(int p=0; p<10; p++){
							aux = aux + pow(bd[k], p);
						}
						potencias[it]=aux;
						it++;
					}
					MPI_Send(&potencias,6667,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);

					
				}else if(pid==3){
					tag = 0;
					int inicio = (pid-1)*6667; //1*6667 = 6667       
					int frontera = inicio + 6667; //6667+6667=13334 
					MPI_Recv(&bd,sizeof(bd)/sizeof(bd[0]),MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					it = 0;
					for(int k = inicio; k<frontera; k++){
						double aux = 0;
						for(int p=0; p<10; p++){
							aux = aux + pow(bd[k], p);
						}
						potencias[it]=aux;
						it++;
					}
					MPI_Send(potencias,6667,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);

				}else if(pid==4){
					tag = 0;
					int inicio = (pid-1)*6667; //1*6667 = 6667       
					int frontera = inicio + 6667; //6667+6667=13334 
					MPI_Recv(&bd,sizeof(bd)/sizeof(bd[0]),MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					it = 0;
					for(int k = inicio; k<frontera; k++){
						double aux = 0;
						for(int p=0; p<10; p++){
							aux = aux + pow(bd[k], p);
						}
						potencias[it]=aux;
						it++;
					}
					MPI_Send(&potencias,6667,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);

				}else if(pid==5){
					tag = 0;
					int inicio = (pid-1)*6667; //1*6667 = 6667       
					int frontera = inicio + 6667; //6667+6667=13334 
					MPI_Recv(&bd,sizeof(bd)/sizeof(bd[0]),MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					it = 0;
					for(int k = inicio; k<frontera; k++){
						double aux = 0;
						for(int p=0; p<10; p++){
							aux = aux + pow(bd[k], p);
						}
						potencias[it]=aux;
						it++;
					}
					MPI_Send(&potencias,6667,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);

				}else if(pid==6){
					tag = 0;
					int inicio = (pid-1)*6667; //1*6667 = 6667       
					int frontera = inicio + 6667; //6667+6667=13334 
					MPI_Recv(&bd,sizeof(bd)/sizeof(bd[0]),MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					it = 0;
					for(int k = inicio; k<frontera; k++){
						double aux = 0;
						for(int p=0; p<10; p++){
							aux = aux + pow(bd[k], p);
						}
						potencias[it]=aux;
						it++;
					}
					MPI_Send(&potencias,6667,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);

				}else if(pid==7){
					tag = 0;
					int inicio = (pid-1)*6667; //1*6667 = 6667       
					int frontera = inicio + 6667; //6667+6667=13334
					MPI_Recv(&bd,sizeof(bd)/sizeof(bd[0]),MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					////printf("Potencia de [%d]: %f\n",pid, bd[inicio+5]); 
					it = 0;
					for(int k = inicio; k<frontera; k++){
						double aux = 0;
						for(int p=0; p<10; p++){
							aux = aux + pow(bd[k], p);
						}
						potencias[it]=aux;
						it++;
					}
					MPI_Send(&potencias,6667,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);

				}else if(pid==8){
					tag = 0;
					int inicio = (pid-1)*6667; //1*6667 = 6667       
					int frontera = inicio + 6667; //6667+6667=13334 
					MPI_Recv(&bd,sizeof(bd)/sizeof(bd[0]),MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					it = 0;
					for(int k = inicio; k<frontera; k++){
						double aux = 0;
						for(int p=0; p<10; p++){
							aux = aux + pow(bd[k], p);
						}
						potencias[it]=aux;
						it++;
					}
					MPI_Send(&potencias,6667,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);

				}else if(pid==9){
					tag = 0;
					int inicio = (pid-1)*6667; //1*6667 = 6667       
					int frontera = inicio + 6667; //6667+6667=13334 
					MPI_Recv(&bd,sizeof(bd)/sizeof(bd[0]),MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					it = 0;
					for(int k = inicio; k<frontera; k++){
						double aux = 0;
						for(int p=0; p<10; p++){
							aux = aux + pow(bd[k], p);
						}
						potencias[it]=aux;
						it++;
					}
					MPI_Send(&potencias,6667,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);

				}else if(pid==10){
					tag  = 0;
					int inicio = (pid-1)*6667; //1*6667 = 6667       
					int frontera = inicio + 6667; //6667+6667=13334 
					MPI_Recv(&bd,sizeof(bd)/sizeof(bd[0]),MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					it = 0;
					for(int k = inicio; k<frontera; k++){
						double aux = 0;
						for(int p=0; p<10; p++){
							aux = aux + pow(bd[k], p);
						}
						potencias[it]=aux;
						it++;
					}
					MPI_Send(&potencias,6667,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);

				}else if(pid==11){
					tag = 0;
					int inicio = (pid-1)*6667; //1*6667 = 6667       
					int frontera = inicio + 6667; //6667+6667=13334 
					MPI_Recv(&bd,sizeof(bd)/sizeof(bd[0]),MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					it = 0;
					for(int k = inicio; k<frontera; k++){
						double aux = 0;
						for(int p=0; p<10; p++){
							aux = aux + pow(bd[k], p);
						}
						potencias[it]=aux;
						it++;
					}
					MPI_Send(&potencias,6667,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);


				}else if(pid==12){
					tag = 0;
					int inicio = (pid-1)*6667; //1*6667 = 6667       
					int frontera = inicio + 6667; //6667+6667=13334 
					MPI_Recv(&bd,sizeof(bd)/sizeof(bd[0]),MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					it = 0;
					for(int k = inicio; k<frontera; k++){
						double aux = 0;
						for(int p=0; p<10; p++){
							aux = aux + pow(bd[k], p);
						}
						potencias[it]=aux;
						it++;
					}
					MPI_Send(&potencias,6667,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);


				}else if(pid==13){
					tag = 0;
					int inicio = (pid-1)*6667; //1*6667 = 6667       
					int frontera = inicio + 6667; //6667+6667=13334 
					MPI_Recv(&bd,sizeof(bd)/sizeof(bd[0]),MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					it = 0;
					for(int k = inicio; k<frontera; k++){
						double aux = 0;
						for(int p=0; p<10; p++){
							aux = aux + pow(bd[k], p);
						}
						potencias[it]=aux;
						it++;
					}
					MPI_Send(&potencias,6667,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);


				}else if(pid==14){
					tag = 0;
					int inicio = (pid-1)*6667; //1*6667 = 6667       
					int frontera = inicio + 6667; //6667+6667=13334 
					MPI_Recv(&bd,sizeof(bd)/sizeof(bd[0]),MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					it = 0;
					for(int k = inicio; k<frontera; k++){
						double aux = 0;
						for(int p=0; p<10; p++){
							aux = aux + pow(bd[k], p);
						}
						potencias[it] = aux;
						//aux1[it]=aux;
						it++;
					}
					MPI_Send(&potencias,6667,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);


				}else if(pid==15){
					tag = 0;
					int inicio = (pid-1)*6667; //1*6667 = 6667       
					int frontera = inicio + 6667-5; //6667+6667=13334 
					MPI_Recv(&bd,sizeof(bd)/sizeof(bd[0]),MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					it = 0;
					for(int k = inicio; k<frontera; k++){
						double aux = 0;
						for(int p=0; p<10; p++){
							aux = aux + pow(bd[k], p);
						}
						potencias[it]=aux;
						it++;
						//if(k==frontera-1){
						printf("Potencia ->%d[%d]: %f\n",it,pid, bd[k]);
						//}
					}
					MPI_Send(&potencias,6662,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);


				}
			
			
			if(pid==0){
				int lim=0;
				for(int i =1; i<size;i++){
				  if(i==15){
				  	lim=6662;
				  	MPI_Recv(&potencias,6662,MPI_DOUBLE, i, tag, MPI_COMM_WORLD, &info);
				  }else{
				  	lim=6667;
			      	MPI_Recv(&potencias,6667,MPI_DOUBLE, i, tag, MPI_COMM_WORLD, &info);
			      }	
			        if(archivo_final == NULL){
						perror("Error en la apertura del archivo");
						return 1;
					}else{
						for(int c=0; c<lim;c++){
							valor = potencias[c];
							//printf("Valor: %f\n",valor );
							fprintf(archivo_final,"%f\n", valor); 
						}
					}
			    } 
			}
			
			i++;

		}


	}
	if(pid==0){
		tiempo_fin = MPI_Wtime();
		tiempo_total = tiempo_fin - tiempo_inicio;
		printf("\nEl tiempo de ejecución es: %f", tiempo_total);
	}
	fclose(archivo);
	fclose(archivo_final);
	MPI_Finalize();

	return 0;
}




