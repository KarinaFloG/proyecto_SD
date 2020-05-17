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
	FILE * archivo_final = fopen("potenciasPipeline.csv","a+");
	double dato = 0;
	double potencia = 0;
	int num_elementos = 0;
	double bd[100000];
	int bd_final[100000];
	int i = 0, it = 0;
	double elemento = 0;
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
				for(int k = 0;k<100000;k++){
					for(int j = 1;j<12;j++){
						elemento = bd[k];
						MPI_Ssend(&elemento,1,MPI_DOUBLE, j, tag, MPI_COMM_WORLD);
					}
					
				}
				
			}

			for(int k=0; k<100000;k++){
				if(pid==1){
					tag = 0;
					MPI_Recv(&elemento,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					potencia = pow(elemento,0);
					MPI_Ssend(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);
				}else if(pid==2){
					tag = 0;
					MPI_Recv(&elemento,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 
					potencia = pow(elemento,1) + potencia;
					MPI_Ssend(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);		
				}else if(pid==3){
					tag = 0;
					MPI_Recv(&elemento,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 		
					potencia = pow(elemento,2) + potencia;
					MPI_Ssend(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);
				}else if(pid==4){
					tag = 0;
					MPI_Recv(&elemento,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 			
					potencia = pow(elemento,3) + potencia;
					MPI_Ssend(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);
				}else if(pid==5){
					tag = 0;
					MPI_Recv(&elemento,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 			
					potencia = pow(elemento,4) + potencia;
					MPI_Ssend(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);		
				}else if(pid==6){
					tag = 0;
					MPI_Recv(&elemento,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 		
					potencia = pow(elemento,5) + potencia;
					MPI_Ssend(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);		
				}else if(pid==7){
					tag = 0;
					MPI_Recv(&elemento,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 			
					potencia = pow(elemento,6) + potencia;
					MPI_Ssend(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);
				}else if(pid==8){
					tag = 0;
					MPI_Recv(&elemento,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 	
					potencia = pow(elemento, 7)+ potencia;
					MPI_Ssend(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);		
				}else if(pid==9){
					tag = 0;
					MPI_Recv(&elemento,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 			
					potencia = pow(elemento,8) + potencia;
					MPI_Ssend(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);
				}else if(pid==10){
					tag  = 0;
					MPI_Recv(&elemento,1,MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &info); 
					MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 			
					potencia = pow(elemento,9) + potencia;
					MPI_Ssend(&potencia,1,MPI_DOUBLE, pid+1, tag, MPI_COMM_WORLD);
				}else if(pid==11){
					tag = 0;
					MPI_Recv(&elemento,1,MPI_DOUBLE,0, tag, MPI_COMM_WORLD, &info); 
					MPI_Recv(&potencia,1,MPI_DOUBLE, pid-1, tag, MPI_COMM_WORLD, &info); 
					bd_final[k] = (int)potencia;
					if(k==99999){
						MPI_Ssend(&bd_final,100000,MPI_DOUBLE,0, tag, MPI_COMM_WORLD);
					}

				}		
			}

			if(pid==0){
				MPI_Recv(&bd_final,100000,MPI_DOUBLE, 11, tag, MPI_COMM_WORLD, &info);
				if(archivo_final == NULL){
					printf("Error en la apertura del archivo potencias\n");
				}else{
    				for(int j=0 ; j<100000; j++){ 
    					dato = bd_final[j];
      					fprintf(archivo_final,"%f\n", dato);
    				}
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
