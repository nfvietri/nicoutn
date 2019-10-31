#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cliente.h"
#include "parser.h"


int parseData(char* fileName,Cliente* arrayClientes[], int len)
{
 FILE *pFile;
 int r,i=0;
 char var1[50],var3[50],var2[50],var4[50],var5[40];
 pFile = fopen(fileName,"r");

 if(pFile == NULL)
  {
  return -1;
  }
  do
  {
	  r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
	  if(r==5)
	  {
		  Cliente* cliAux = new_Cliente();
		  cli_setId(cliAux,atoi(var1));
		  cli_setNombre(cliAux,var2);
		  cli_setDireccion(cliAux,var3);
		  cli_setCuit(cliAux,var4);
		  cli_setLocalidad(cliAux,var5);
		  arrayClientes[i] = cliAux;
		  i++;
	  } else
		  break;
  	  }while(!feof(pFile) && i<len);
  	  fclose(pFile);

 return i;

}
