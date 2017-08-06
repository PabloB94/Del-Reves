#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sysexits.h>
#include <stdarg.h>


void invertir( char cadena[2048]){
	int k;
    	for(k=2048; cadena[k]!='\0' && cadena[k]!='\n'; k--){

	        while(k>=0){
        		printf("%c",cadena[k]);
        	        k--;
        	}
        	printf("\n");
	}
}

int main(int argc, char* argv[]){
        char texto[2048];

        if(argc==2 && (strcmp("--help",argv[1])==1 || strcmp("-h",argv[1])==1)){
                printf("delreves: Uso: delreves [ fichero... ]\n");
        	printf("delreves: Invierte el contenido de las lineas de los ficheros (o de la entrada).\n");
		exit(EX_OK);
	}
        if (argc>=2){
        	FILE* fichero;
                int i;

                for(i=1; i<argc; i++){
	                if((fichero=fopen(argv[i],"r"))){
				while(fgets(texto,2048,fichero)){
                                          invertir(texto);
                                }

                                        fclose(fichero);
                        }

			else{
                                fprintf(stderr,"delreves: Error(EX_NOINPUT), uso incorrecto del mandato. \"Success\"\n");
                                fprintf(stderr,"delreves+ El fichero \"%s\" no puede ser leido\n",argv[i]);
                                exit(EX_NOINPUT);
                        }
                }
	}

	else{
 		int k;
                while(fgets(texto,2048,stdin)){

                        for(k=2048;texto[k]!='\0' && texto[k]!='\n';k--);
                        	if(strcmp(texto,"")==0){

                                	while(k>=0){
                                        	printf("%c",texto[k]);
						k--;
                                	}
                                	printf("\n");
                        	}
			
                }
        }

	exit(EX_OK);
}


