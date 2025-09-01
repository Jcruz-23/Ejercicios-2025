/*Crear una estructura Actividad, las mismas corresponden a las actividades de un gym.
Atributos: nombre, cupo, dias de la semana, horario, cant_inscriptos.
Funciones: mostrar, buscar, mostrar actividades que aun no tienen el cupo lleno.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

struct gym
{
    char nombre[20];
    int cupo;
    int dias[2];
    float horario;
    int inscriptos;
};

int agregar(struct gym *p, int n);
void mostrar(struct gym *p, int n);
void buscar(struct gym *p, int n);
void mostrarSinCupo(struct gym *p, int n);
void menu();
void dias(int);
void mayus(struct gym *p);

int main()
{
    srand(time(NULL));
    menu();
}

void menu()
{
    int n = 0;
    int op = 0;
    char fin = ' ';
    struct gym *p;
    struct gym *p2;
    int flag = 0;

    do
    {
        printf("--------------MENU--------------"
               "\n1)Agregar actividad"
               "\n2)Mostrar actividades"
               "\n3)Buscar actividad"
               "\n4)Mostrar actividades sin cupo"
               "\n--------------------------------"
               "\nOpcion: ");
        scanf(" %d", &op);

        switch (op)
        {
        case 1:
            if (flag == 0)
            {
                p = malloc(1 * (sizeof(struct gym)));
                if (p == NULL)
                {
                    printf("\nError asignndo memoria");
                }
                else
                {
                    n = agregar(p, n);
                }
                flag = 1;
                break;
            }
            else
            {
                p2 = realloc(p, (n + 1) * sizeof(struct gym));
                p = p2;
                if (p2 == NULL)
                {
                    printf("\nError asignndo memoria");
                    free(p);
                }
                else
                {
                    n = agregar(p, n);
                }
                break;
            }
        case 2:
            mostrar(p, n);
            break;
        case 3:
            buscar(p, n);
            break;
        case 4:
            mostrarSinCupo(p, n);
            break;
        default:
            printf("\n\aERROR!!");
            break;
        }
        printf("\nDesea continuar? (s/n): ");
        scanf(" %c", &fin);
    } while (fin == 's' || fin == 'S');

    free(p);
    p = NULL;
}

int agregar(struct gym *p, int n)
{
    printf("\nNombre: ");
    scanf(" %s", p[n].nombre);
    printf("\nCant de cupo : ");
    scanf(" %d", &p[n].cupo);
    p[n].dias[0] = rand() % 5 + 1;
    p[n].dias[1] = rand() % 5 + 1;
    while (p[n].dias[0] == p[n].dias[1])
        p[n].dias[1] = rand() % 5 + 1;
    printf("\nHorario(hora.minutos): ");
    scanf(" %f", &p[n].horario);
    printf("\nCant. de inscriptos: ");
    scanf(" %d", &p[n].inscriptos);
    while (p[n].cupo < p[n].inscriptos)
    {
        printf("\n\aERROR!!");
        printf("\nIngrese una cantidad igual o menor a %d: ", p[n].cupo);
        scanf(" %d", &p[n].inscriptos);
    }
    n++;

    return n;
}

void mostrar(struct gym *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n--------------Actividad(%d)--------------", i + 1);
        printf("\nNombre: %s", p[i].nombre);
        printf("\nCant. cupos: %d", p[i].cupo);
        printf("\nDias:");
        dias(p[i].dias[0]);
        dias(p[i].dias[1]);
        printf("\nHorario: %.2f", p[i].horario);
        printf("\nCant. inscriptios: %d", p[i].inscriptos);
    }
}
void buscar(struct gym *p, int n)
{
    char aux[20];
    printf("\nIngrese nombre de la actividad a buscar: ");
    scanf(" %s", aux);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(aux, p[i].nombre) == 0)
        {
            printf("\n--------------Actividad(%d)--------------", i + 1);
            printf("\nNombre: %s", p[i].nombre);
            printf("\nCant. cupos: %d", p[i].cupo);
            printf("\nDias:");
            dias(p[i].dias[0]);
            dias(p[i].dias[1]);
            printf("\nHorario: %.2f", p[i].horario);
            printf("\nCant. inscriptios: %d", p[i].inscriptos);
        }
    }
}
void mostrarSinCupo(struct gym *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i].cupo > p[i].inscriptos)
        {
            printf("\n--------------Actividad(%d)--------------", i + 1);
            printf("\nNombre: %s", p[i].nombre);
            printf("\nCant. cupos: %d", p[i].cupo);
            printf("\nDias:");
            dias(p[i].dias[0]);
            dias(p[i].dias[1]);
            printf("\nHorario: %.2f", p[i].horario);
            printf("\nCant. inscriptios: %d", p[i].inscriptos);
        }
    }
}

void dias(int dia)
{
    if (dia == 1)
    {
        printf(" lunes");
    }
    else if (dia == 2)
    {
        printf(" martes");
    }
    else if (dia == 3)
    {
        printf(" miercoles");
    }
    else if (dia == 4)
    {
        printf(" jueves");
    }
    else if (dia == 5)
    {
        printf(" viernes");
    }
}