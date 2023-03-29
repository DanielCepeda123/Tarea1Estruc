#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "list_answer.c"

typedef struct
{
    char nombre[30];
    char apellido[30];
    int edad;
    int telefono;
    char direccion[30];
    char numeroSocial[30];
    char listaMedicos[30];
}Datos;

void registrarPaciente(List* lista)
{
    Datos* paciente = (Datos*)malloc(sizeof(Datos));
    printf("Ingrese el nombre del paciente: ");
    scanf("%s", paciente->nombre);
    printf("Ingrese el apellido del paciente: ");
    scanf("%s", paciente->apellido);
    printf("Ingrese la edad del paciente: ");
    scanf("%d", &paciente->edad);
    printf("Ingrese el telefono del paciente: ");
    scanf("%d", &paciente->telefono);
    printf("Ingrese la direccion del paciente: ");
    scanf("%*c%[^\n]", paciente->direccion);
    printf("Ingrese el numero de seguro social del paciente: ");
    scanf("%s", paciente->numeroSocial);
    printf("Ingrese el nombre del medico asignado al paciente: ");
    scanf("%*c%[^\n]", paciente->listaMedicos);

    pushBack(lista, paciente);
}

void mostrarPaciente(List* lista)
{
    char nombre[30];
    char apellido[30];
    printf("Ingrese el nombre del paciente: ");
    scanf("%s", nombre);
    printf("Ingrese el apellido del paciente: ");
    scanf("%s", apellido);

    Datos* aux = firstList(lista);
    bool encontrado = false;
    
    while (aux != NULL)
    {
        encontrado = false;
        if (strcmp(aux->nombre, nombre) == 0 && strcmp(aux->apellido, apellido) == 0)
        {
            encontrado = true;
            printf("Nombre: %s\n", aux->nombre);
            printf("Apellido: %s\n", aux->apellido);
            printf("Edad: %d\n", aux->edad);
            printf("Telefono: %d\n", aux->telefono);
            printf("Direccion: %s\n", aux->direccion);
            printf("Numero de seguro social: %s\n", aux->numeroSocial);
            printf("Medico asignado: %s\n", aux->listaMedicos);
            sleep(1);
            break;
        }

        else if (aux != lista->tail)
        {
            aux = nextList(lista);
        }
        
        
        
    }

    if (!encontrado)
    {
        printf("No se encontro el paciente\n");
        sleep(1);
    }


}

void eliminarPaciente(List *lista)
{
    char nombre[30];
    char apellido[30];
    printf("Ingrese el nombre del paciente: ");
    scanf("%s", nombre);
    printf("Ingrese el apellido del paciente: ");
    scanf("%s", apellido);

    Datos* aux = firstList(lista);
    bool eliminado = false;
    
    while (aux != NULL)
    {
        if (strcmp(aux->nombre, nombre) == 0 && strcmp(aux->apellido, apellido) == 0)
        {
            eliminado = true;
            popCurrent(lista);
            printf("Paciente eliminado\n");
            sleep(1);
            break;
        }

        else if (aux != lista->tail)
        {
            aux = nextList(lista);
        }
    }

    if (!eliminado)
    {
        printf("No se encontro el paciente\n");
        sleep(1);
    }
}

void mostrarTodosPacientes(List *lista)
{
    Datos* aux = firstList(lista);
    while (aux != NULL)
    {
        printf("Nombre: %s\n", aux->nombre);
        printf("Apellido: %s\n", aux->apellido);
        printf("Edad: %d\n", aux->edad);
        printf("Telefono: %d\n", aux->telefono);
        printf("Direccion: %s\n", aux->direccion);
        printf("Numero de seguro social: %s\n", aux->numeroSocial);
        printf("Medico asignado: %s\n", aux->listaMedicos);
        printf("\n");
        sleep(1);
        if (aux != lista->tail)
        {
            aux = nextList(lista);
        }
        else
        {
            break;
        }
    }
}

void asignarMedico(List *lista)
{
    char nombre[30];
    char apellido[30];
    printf("Ingrese el nombre del paciente: ");
    scanf("%s", nombre);
    printf("Ingrese el apellido del paciente: ");
    scanf("%s", apellido);

    Datos* aux = firstList(lista);
    bool encontrado = false;
    
    while (aux != NULL)
    {
        encontrado = false;
        if (strcmp(aux->nombre, nombre) == 0 && strcmp(aux->apellido, apellido) == 0)
        {
            encontrado = true;
            printf("Ingrese el nombre del medico: ");
            scanf("%*c%[^\n]", aux->listaMedicos);
            printf("Medico asignado\n");
            sleep(1);
            break;
        }

        else if (aux != lista->tail)
        {
            aux = nextList(lista);
        }
        
        
        
    }

    if (!encontrado)
    {
        printf("No se encontro el paciente\n");
        sleep(1);
    }
}

void pacientesSinMedicos(List *lista)
{
    Datos* aux = firstList(lista);
    while (aux != NULL)
    {
        if (strcmp(aux->listaMedicos, "") == 0)
        {
            printf("Nombre: %s\n", aux->nombre);
            printf("Apellido: %s\n", aux->apellido);
            printf("Edad: %d\n", aux->edad);
            printf("Telefono: %d\n", aux->telefono);
            printf("Direccion: %s\n", aux->direccion);
            printf("Numero de seguro social: %s\n", aux->numeroSocial);
            printf("Medico asignado: %s\n", aux->listaMedicos);
            printf("\n");
            sleep(1);
        }
        if (aux != lista->tail)
        {
            aux = nextList(lista);
        }
        else
        {
            break;
        }
    }
}

void desasignarMedico(List *lista)
{
    char nombre[30];
    char apellido[30];
    printf("Ingrese el nombre del paciente: ");
    scanf("%s", nombre);
    printf("Ingrese el apellido del paciente: ");
    scanf("%s", apellido);

    Datos* aux = firstList(lista);
    bool encontrado = false;
    
    while (aux != NULL)
    {
        encontrado = false;
        if (strcmp(aux->nombre, nombre) == 0 && strcmp(aux->apellido, apellido) == 0)
        {
            encontrado = true;
            strcpy(aux->listaMedicos, "");
            printf("Medico desasignado\n");
            sleep(1);
            break;
        }

        else if (aux != lista->tail)
        {
            aux = nextList(lista);
        }
    }

    if (!encontrado)
    {
        printf("No se encontro el paciente\n");
        sleep(1);
    }
}


int main()
{
    List* lista = createList();
    Datos *p = (Datos*)malloc(sizeof(Datos));

    int opcion = 1;

    while (opcion != 0)
    {  
        opcion = 0;
        printf("Que desea hacer?\n");
        printf("1. Registrar un paciente\n");
        printf("2. Mostrar datos de un paciente\n");
        printf("3. Eliminar paciente\n");
        printf("4. Mostrar todos los pacientes\n");
        printf("5. Mostrar todos los pacientes sin un medico asignado\n");
        printf("6. Asignar medico a paciente\n");
        printf("7. Desasignar medico de paciente\n");
        printf("9. Importar pacientes desde un archivo CSV\n");
        printf("10. Exportar pacientes a un archivo CSV\n");
        printf("0. Salir\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 0:
            {
                printf("Saliendo...\n");
                exit(0);
            }
            case 1:
            {
                registrarPaciente(lista);
                break;
            }
            case 2:
            {
                mostrarPaciente(lista);
                break;
            }
            case 3:
            {
                eliminarPaciente(lista);
                break;
            }
            case 4: 
            {
                mostrarTodosPacientes(lista);
                break;
            }
            case 5: 
            {
                pacientesSinMedico(lista);
            }
            case 6: 
            {
                asignarMedico(lista);
                break;
            }
            case 7: 
            {
                desasignarMedico(lista);
                break;
            }
        }
    }
}
