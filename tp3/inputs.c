#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "inputs.h"

void encabezadoListados(char titulo[],int canFila, int canCol)
{
        system("cls");
        getChoiceForm(titulo,canFila,canCol);
        crearEspacio('*',canFila,canCol);
        printf("\n");
}
void validateString(const char arrayIn[], char arrayOut[])
{
    int i,j=0,inicioCadena=0;
    int tamano=strlen(arrayIn);
    char aux[tamano];

    //Empieza Ltrim
    for (i=tamano; i>=0 ; i--)
    {
        if (arrayIn[i]!=' ' && arrayIn[i]!='\0' )
            {
                arrayOut[i+1] = '\0';
                break;
            }
    }
    //Empieza Rtrim

    aux[0]='\0';

    for (i=0; arrayIn[i]!='\0' ; i++)
    {
        if (arrayIn[i]!=' ' || inicioCadena !=0)
            {
                aux[j] = arrayIn[i];
                j++;
                inicioCadena = 1;
            }
    }
    aux[j++]='\0';
    strcpy(arrayOut,aux);

    //Empieza quitar los espacio en medio

    aux[0]='\0';
    inicioCadena=0;
    j=0;

    for (i=0; arrayIn[i]!='\0' ; i++)
    {
        if (inicioCadena==0)
        {
            aux[j] = arrayIn[i];
            j++;
            inicioCadena = 1;

        } else if (arrayIn[i]!=' ' || arrayIn[i-1]!= ' ')
            {
                aux[j] = arrayIn[i];
                j++;
            }
    }
    aux[j++]='\0';
    strcpy(arrayOut,aux);
}

int esSoloLetras(char str[])
{
   int i=0;
   int r=1;

   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
       {
           if (str[i]=='-')
           {
               str[i]=' ';
           }
           else
           {
                r=-1;
                return r;
           }
       }
       i++;
   }
   return r;
}

int menuPrincipal(void)
{
    int opcion;
    system("cls");
    getChoiceForm(" Menu Principal ",1,78);

    printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
    printf("\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
    printf("\n3. Alta de empleado");
    printf("\n4. Modificar datos de empleado");
    printf("\n5. Baja de empleado");
    printf("\n6. Listar empleados");
    printf("\n7. Ordenar empleados");
    printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)");
    printf("\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)");
    printf("\n10. Salir");


    printf("\n\n ");
    do{
        getInt(&opcion,"Ingrese una Opcion: ","Error, la opcion no es correcta",1,10);

    }while (!(opcion>0 || opcion<=10));

    printf("\n ");
    return opcion;

}

void getChoiceForm(char titulo[],int CANT,int LENMENU)
{

    int margen;

    margen=((LENMENU-2)-(strlen(titulo)))/2;

    crearEspacio('*',LENMENU,1);
    printf("\n");

    crearEspacio('*',margen,1);
    printf(" %s ",titulo);
    crearEspacio('*',margen,1);

    printf("\n");
    crearEspacio('*',LENMENU,1);
    printf("\n");
}

int getInt(int *numero,char mensaje1[],char mensajeError1[],int minimo,int maximo)
{
    int num;
    //int cant;
    int flagSalida=0;
    int resultado=-1;

    printf("%s",mensaje1);
    while(flagSalida==0)
    {

        fflush(stdin);
        if (scanf("%d",&num)==1)
        {
            if (num >= minimo && num <= maximo)
            {
                    resultado=1;
                    break;
            }
        }
        printf("%s",mensajeError1);
    }

    *numero=num;
    return resultado;
}

void crearEspacio(char caracter,int can_col,int can_fila)
{
    int i=0;
    int j;
    for (i=0; i<can_fila; i++)
    {
        for (j=0; j<can_col; j++)
        {
            printf("%c",caracter);
        }
    }
}

char getChar2(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    auxiliar=getch();
    return auxiliar;
}

void getString(char mensaje[],char input[],int tamano)
{
    printf("%s",mensaje);
    fflush(stdin);
    myFgets(input,tamano);

    //scanf ("%[^\n]s", input);
}

int esNumerico(char str[])
{
    int i=0;
    int resultado=1;
    int cant = strlen(str);

    for(i=0; i<cant; i++)
        {
            if(!isdigit(str[i]))
            {
                resultado=-1;
                break;
            }
        }

return resultado;
}

int esNumericoFlotante(char str[])
{
    int i=0;
    int resultado=1;
    int cant = strlen(str);
    int cantPunto=0;

    for(i=0; i<cant; i++)
        {
            if (str[i]!='.')
            {
                if(!isdigit(str[i]))
                {
                    resultado=0;
                    break;
                }
             }
             else
             {
                 cantPunto++;
                 if (cantPunto>1)
                 {
                    resultado=0;
                    break;
                 }
             }
        }

return resultado;
}

int esAlfaNumerico(char str[])
{
   int i=0;
   int r=1;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
       {
           r=-1;
           break;
       }

       i++;
   }
   return r;
}

void takeBreak(char mensaje[])
{
    printf("\n");
    getChar2(mensaje);
    printf("\n");
}


void myFgets(char array[], int cantidad)
{

    int cant=0;
    fflush(stdin);

    fgets(array, cantidad, stdin);

    cant = strlen(array);
    array[cant-1] = '\0';

}

int nextIdLinkedList(LinkedList* pArrayListEmployee)
{
    int nId;
    int i;
    int maxId=0;
    Employee* emp;

    for (i=0; i<ll_len(pArrayListEmployee); i++)
        {
            emp=((Employee*) ll_get(pArrayListEmployee,i));
            if (maxId<emp->id)
            {
                maxId=emp->id;
            }
        }
        nId=maxId+1;

    return nId;
}

int indexLinkedList(LinkedList* pArrayListEmployee,int idLinkedlist)
{
    int index;
    int i;

    Employee* emp;

    for (i=0; i<ll_len(pArrayListEmployee); i++)
        {
            emp=((Employee*) ll_get(pArrayListEmployee,i));
            if (idLinkedlist==emp->id)
            {
                index=i;
            }
        }

    return index;
}

char menuOrdenamiento(void)
{
    char opcion;
    system("cls");
    getChoiceForm("MENU DE ORDENAMIENTO",1,78);
    crearEspacio('*',78,1);
    printf("\n");
    printf("a. Ordenar por ID\n");
    printf("b. Ordenar por Nombre\n");
    printf("c. Ordenar por Horas Trabajadas\n");
    printf("d. Ordenar por Sueldo\n");

    do
    {
        opcion=getChar2("Ingrese una opcion: ");
        opcion=tolower(opcion);

    }while (!(opcion>='a' && opcion<='d') && opcion!=27);

    return opcion;
}



int opcionOrden(void)
{
    int opcion;

    printf("\n");
    printf("1-Descendente\n");
    printf("2-Ascendente\n");

    do
    {
        getInt(&opcion,"Ingrese una opcion: ","Error, 1- Descendente / 2- Ascendente",1,2);

    }while (!(opcion>=1 && opcion<=2));
    printf("\nOdenando... Espere un momento...");

    return opcion;
}
