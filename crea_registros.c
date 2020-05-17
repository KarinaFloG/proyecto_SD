#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
  srand(time(NULL));
  int dato, i;
  FILE *fp;
  fp=fopen("datos.csv","w");
  if(fp==NULL){
    printf("error al crear el archivo\n");
  }else{
    for(i=1 ; i<=200000; i++){
      
      dato = 1 + rand() % (17 - 1);   
      fprintf(fp,"%d\n", dato);
    }
  
    fclose(fp);
  }
  return 0;
}