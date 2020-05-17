#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv[]){
	FILE * archivo = fopen("datos.csv","r");
	FILE * archivo_final = fopen("pipelineSec.csv","a+");
	int i = 0;
	int num_elementos = 0;
	double bd[100000];
	double bd_final[100000];
	double dato = 0;
	double potencia = 0;
	double numero = 0;
	double valor = 0;

	if(archivo == NULL){
		printf("Error en la apertura del archivo");
	}else{
		char linea[1024];
		while(i<100){
			num_elementos = 0;
			while(num_elementos<100000){
				fgets(linea,1024,archivo);
				dato = strtod(linea,NULL);
				bd[num_elementos] = dato;
				num_elementos++;	
			}

			for(int k=0; k<100000;k++){
				potencia = 0;
				numero = bd[k];
				for(int j=0; j<10;j++){
					potencia = pow(numero,j) + potencia;
				}
				bd_final[k] = potencia;
			}

			if(archivo_final == NULL){
				printf("Error abriendo el archivo para las potencias\n");
			}else{
    			for(int j=0 ; j<100000; j++){ 
    				valor = bd_final[j];
      				fprintf(archivo_final,"%.1f\n", valor);
    			}
			}
			i++;
		}
		
	}
	fclose(archivo);
	fclose(archivo_final);
	return 0 ;
}