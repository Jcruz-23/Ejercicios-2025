#include <stdio.h>

int main (){
	int votos1 = 0;
	int votos2 = 0;
	int votos3 = 0;
	int votoBlanco = 0;
	int candidato = 0;
	int opcion = 0;
	char continuar = 'N';
	
	while (continuar == 'N') {
		printf("Elija un tipo de voto: \n");
		printf("1- Voto normal \n2-Voto en blanco\n");
		scanf(" %d",&opcion);
		switch (opcion){
		case 1: 
			printf("1- Candidato uno \n2- Candidato dos \n3- Candidato tres \n");
			scanf(" %d", &candidato);
			switch (candidato){
			case 1:
				votos1++;
				break;
			case 2:
				votos2++;
					break;
			case 3:
				votos3++;
				break;
			}
			break;
		case 2:
			votoBlanco++;
			break;
		}
		
		printf("Finalizo la votacion? S/N: ");
		scanf(" %c",&continuar);
	}
	
	
	if(votos1>votos2>votos3){
		printf("Gano el candidato uno con %d",votos1);
	}else if(votos2>votos1>votos3){
		printf("Gano el candidato dos con %d",votos2);
	}else if(votos3>votos1>votos2){
		printf("Gano el candidato tres con %d",votos3);
	}

	return 0;
}
