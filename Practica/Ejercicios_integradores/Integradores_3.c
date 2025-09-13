/*Desarrolle un programa que permita gestionar los datos de pacientes en un hospital. 
Para ello, defina una estructura llamada PacienteHospital que almacene la siguiente información: 
número de paciente (entero), nombre (cadena de caracteres), diagnóstico (cadena de caracteres) 
y fecha de consulta(cadena de caracteres). 
Luego, implemente las siguientes funciones: 
-Que permita registrar un nuevo paciente (debe agregar un paciente nuevo a la lista)
-Que permita leer un archivo "paciente.txt".
-Que permita buscar todas las consultas que realizó un paciente.
Genere un menú de opciones con las distintas opciones que puede realizar el usuario. 
Recuerde presentar la información de manera ordenada y entendible.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct pacienteHospital{
    int numero;
    char nombre[20];
    char diagnostico[30];
    char turno[30];
};
int registrar(struct pacienteHospital *p, int);
void buscar(struct pacienteHospital *p, int);
int leer(struct pacienteHospital *p);
int main(){
    int op = 0;
    char fin = ' ';
    int n = 0;
    struct pacienteHospital *p = NULL;
    struct pacienteHospital *aux = NULL;
    
    do{
         printf("\n=====================MENU====================="
            "\n1)Registrar"
            "\n2)Leer archivo"
            "\n3)Buscar consultas"
            "\n=====================MENU====================="
            "\nOpcion: ");
    scanf(" %d", &op);

    switch(op){
        case 1: if(n == 0){
            p = malloc(sizeof(struct pacienteHospital));
            if(p == NULL){ printf("Error al asignar memoria!"); return 1;
            }else {registrar(p, n);}

        }else{
            aux = realloc(p, (n+1) * sizeof(struct pacienteHospital));
             if(aux == NULL){ printf("Error al asignar memoria!"); free(p); return 1;
            }else {p = aux; registrar(p, n);}
        }
        break;
        case 2: n = leer(p); 
        break;
        case 3: buscar(p, n); break;
    }


    printf("\nDesea continuar? (s/n)");
    scanf(" %c", &fin);
    }while(fin == 'S'||fin == 's');
   
    free(p);
    return 0;
}

int registrar(struct pacienteHospital *p, int n){
    FILE *f;
    f = fopen("paciente.txt", "w");

    if(f == NULL){
        printf("\nError al abrir archivo ''paciente.txt''");
    }
    printf("\n---------------------------------------------------");
    printf("\nCarga n°%d", n+1);
    (p+n)->numero = n+1;
    getchar();
    printf("\nNombre: ");
    fgets((p+n)->nombre, sizeof((p+n)->nombre), stdin);
    (p+n)->nombre[strcspn((p+n)->nombre, "\n")] = 0;
    printf("\nDiagnostico: ");
    fgets((p+n)->diagnostico, sizeof((p+n)->diagnostico), stdin);
    (p+n)->diagnostico[strcspn((p+n)->diagnostico, "\n")] = '\0';
    printf("\nTurno: ");
    fgets((p+n)->turno, sizeof((p+n)->turno), stdin);
    (p+n)->turno[strcspn((p+n)->turno, "\n")] = 0;

    fprintf(f,"%d|%s|%s|%s\n", (p+n)->numero,(p+n)->nombre,(p+n)->diagnostico,(p+n)->turno);
    fclose(f);
    return n;
}


int leer(struct pacienteHospital *p){
int n = 0;
char linea[200];
FILE *f;
f = fopen("paciente.txt", "r");
while(fgets(linea, sizeof(linea), f) != NULL){
    
    if(sscanf(linea, "%d|%[^|]|%[^|]|%[^\n]", 
        &(p+n)->numero,
        (p+n)->nombre,
        (p+n)->diagnostico,
        (p+n)->turno) == 4){
         n++;
        }else{
            printf("\nError en la linea: %s", linea);
        }
}
fclose(f);

for(int i = 0; i < n; i++){
        printf("\n------------------------------");
        printf("\nNombre: %s",(p+i)->nombre);
        printf("\nId: %d", (p+i)->numero);
        printf("\nDiagnostico: %s", (p+i)->diagnostico);
        printf("\nTurno: %s", (p+i)->turno);
        }
return n;
}

void buscar(struct pacienteHospital *p, int n){
    int id;
    int flag = 0;

    printf("\nIngrese ID del paciente que quiere buscar: ");
    scanf(" %d", &id);
    for(int i = 0; i < n; i++){
        if((p+i)->numero == id){
        printf("\n------------------------------");
        printf("\nNombre: %s",(p+i)->nombre);
        printf("\nId: %d", (p+i)->numero);
        printf("\nDiagnostico: %s", (p+i)->diagnostico);
        printf("\nTurno: %s", (p+i)->turno);

        flag = 1;
        }
    }
    if(flag == 0){
        printf("\n\aPaciente no encontrado!");
    }
}