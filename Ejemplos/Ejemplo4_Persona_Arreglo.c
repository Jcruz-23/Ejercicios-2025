/* Crear un programa que pida los siguientes datos de una persona: 
nombre, apellido, celular.
Crear una estructura que almacene datos de persona y luego los 
muestre por pantalla.

Ampliar el programa del ejercicio anterior, para que almacene datos 
de hasta 3 personas en un vector de estructura.
Luego crear un menu que permita las opciones: 
a. agregar una nueva persona
b. mostrar todas las personas
c. buscar una persona por apellido

*/

#include <stdio.h>
#include <string.h>

struct persona
{
	char nombre[20];
	char apellido[20];
	long celular;
};

int main() {
	
	struct persona contactos[3];
	char op = ' ';
	char buscar_apellido[20];
	int bandera_encontrado = 0;
	
	do {
		printf("MENU DE OPCIONES\n");
		printf("a. Agregar.\nb. Mostrar.\nc. Buscar.\n");
		scanf(" %c", &op);
		getchar();  // Limpiar el buffer de entrada
		
		switch (op) {
		case 'a':
			for (int i = 0; i < 3; i++) {
				printf("\nINGRESE LOS DATOS DE PERSONA Nº%d:\n", i + 1);
				printf("Nombre: ");
				fgets(contactos[i].nombre, sizeof(contactos[i].nombre), stdin); //Permite ingresar una cadena incluyendo espacios
				contactos[i].nombre[strcspn(contactos[i].nombre, "\n")] = '\0'; // Elimina el salto de linea
				printf("Apellido: ");
				fgets(contactos[i].apellido, sizeof(contactos[i].apellido), stdin);
				contactos[i].apellido[strcspn(contactos[i].apellido, "\n")] = '\0'; 
				printf("Celular: ");
				scanf("%ld", &contactos[i].celular);
				getchar();
				printf("---------------------------------------------------\n");
			}
			break;
		case 'b':
			for (int i = 0; i < 3; i++) {
				printf("\nDATOS DE PERSONA N%d:\n", i + 1);
				printf("\nNombre: %s\n", contactos[i].nombre);
				printf("\nApellido: %s\n", contactos[i].apellido);
				printf("\nCelular: %ld\n", contactos[i].celular);
				printf("---------------------------------------------------\n");
			}
			break;
		case 'c':
			printf("INGRESE APELLIDO A BUSCAR:\n");
			fgets(buscar_apellido, sizeof(buscar_apellido), stdin);
			buscar_apellido[strcspn(buscar_apellido, "\n")] = '\0'; 
			bandera_encontrado = 0;
			for (int i = 0; i < 3; i++) {
				if (strcmp(buscar_apellido, contactos[i].apellido) == 0) {
					printf("Persona encontrada: %s %s\n", contactos[i].nombre, contactos[i].apellido);
					printf("Celular: %ld\n", contactos[i].celular);
					bandera_encontrado = 1;
				}
			}
			if (bandera_encontrado == 0) {
				printf("No se encontro la persona buscada.\n");
			}
			break;
		}
		
		printf("\n¿Desea seguir (S/N)? ");
		scanf(" %c", &op);
		getchar();
		
	} while (op == 's' || op == 'S');
	
	return 0;
}


