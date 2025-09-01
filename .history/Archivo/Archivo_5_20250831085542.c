#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct persona
{
    char nombre[20];
    char apellido[20];
    int dni;
    char nacionalidad[20];
    int edad;
};
void menu();
int cargar(struct persona *p, int);
int agregar(struct persona *p, int);

int main()
{
    menu();
    return 0;
}

void menu()
{
    struct persona *p;
    struct persona *p2;
    char fin = ' ';
    int n = 0;
    int flag = 0;
    do
    {
        if (flag == 0)
        {
            p = malloc(1 * sizeof(struct persona));
            if (p == NULL)
            {
                printf("\nError al asignar memoria");
                free(p);
                fin = 'n';
            };
            n = cargar(p, n);
            flag = 1;
        }
        else
        {
             p2 = realloc(p, (n+1) * sizeof(struct persona));
            if (p2 == NULL)
            {
                printf("\nError al asignar memoria");
                free(p);
                fin = 'n';
            }
            p = p2;
            n = agregar(p, n);
           
        }

        printf("\nDesea agregar otra persona? (s/n)");
        scanf(" %c", &fin);
    } while (fin == 's' || fin == 'S');

    free(p2);
    free(p);
}
int cargar(struct persona *p, int n)
{
    FILE *a;
    a = fopen("datos_personales.txt", "w");

    printf("\n---------------Persona [%d]---------------", n + 1);
    printf("\nNombre: ");
    scanf(" %s", p[n].nombre);
    printf("\nApellido: ");
    scanf(" %s", p[n].apellido);
    printf("\nDNI: ");
    scanf(" %d", &p[n].dni);
    printf("\nNacionalidad: ");
    scanf(" %s", p[n].nacionalidad);
    printf("\nEdad: ");
    scanf(" %d", &p[n].edad);
    fprintf(a, "\n---------------Persona [%d]---------------", n + 1);
    fprintf(a, "\nNombre: %s", p[n].nombre);
    fprintf(a, "\nApellido: %s", p[n].apellido);
    fprintf(a, "\nDNI: %d", p[n].dni);
    fprintf(a, "\nNacionalidad: %s", p[n].nacionalidad);
    fprintf(a, "\nEdad: %d", p[n].edad);

    fclose(a);
    n++;
    return n;
}

int agregar(struct persona *p, int n)
{
    FILE *a;

    a = fopen("datos_personales.txt", "a");

    printf("\n\n---------------Persona [%d]---------------\n\n", n + 1);
    printf("\nNombre: ");
    scanf(" %s", p[n].nombre);
    printf("\nApellido: ");
    scanf(" %s", p[n].apellido);
    printf("\nDNI: ");
    scanf(" %d", &p[n].dni);
    printf("\nNacionalidad: ");
    scanf(" %s", p[n].nacionalidad);
    printf("\nEdad: ");
    scanf(" %d", &p[n].edad);
    fprintf(a, "\n---------------Persona [%d]---------------", n + 1);
    fprintf(a, "\nNombre: %s", p[n].nombre);
    fprintf(a, "\nApellido: %s", p[n].apellido);
    fprintf(a, "\nDNI: %d", p[n].dni);
    fprintf(a, "\nNacionalidad: %s", p[n].nacionalidad);
    fprintf(a, "\nEdad: %d", p[n].edad);

    fclose(a);
    n++;

    return n;
}
