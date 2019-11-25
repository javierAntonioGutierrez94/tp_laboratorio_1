#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"
#include "inputs.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int r=-1;
    FILE* pFile;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile= fopen(path,"r");

        if(pFile!=NULL)
        {
            r=parser_EmployeeFromText(pFile,pArrayListEmployee);
            fclose(pFile);
        }
        else
        {
            r=0;
        }
    }
    return r;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int r=-1;
    FILE* pFile;

    if (path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"rb");

        if(pFile!=NULL)
        {
            r=parser_EmployeeFromBinary(pFile,pArrayListEmployee);
            fclose(pFile);
        }
        else
        {
            r=0;
        }
    }
    return r;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int r=-1;
    int auxId;
    char idAux[50];
    char auxHoras[50];
    char auxSalario[50];
    char auxNombre[130];
    char confirm;

    system("cls");

    getChoiceForm("Alta de Empleado",1,78);

    auxId=nextIdLinkedList(pArrayListEmployee);

    printf("\nSiguiente ID: %d",auxId);

    sprintf(idAux, "%d", auxId);

    do
    {
        getString("\nIngrese Nombre: ",auxNombre,130);
        r=esSoloLetras(auxNombre);
        if (r!=1)
        {
            takeBreak("Error, debe ingresar solo letras");
        }
     }while (r!=1);

    do
    {
        getString("\nIngrese Horas Trabajadas: ",auxHoras,50);
        r=esNumerico(auxHoras);
        if (!(r==1 && atoi(auxHoras)>0 && atoi(auxHoras)<=550))
        {
            takeBreak("\nError, Horas Trab solo numeros entre (0-550");
        }
    }while (r!=1);

    do
    {
        getString("\nIngrese salario: ",auxSalario,50);
        r=esNumerico(auxSalario);
        if (!(r==1 && atoi(auxSalario)>0 && atoi(auxSalario)<15000000))
        {
            takeBreak("\nError, Salario solo numeros entre (0-15,000,000");
        }
    }while (r!=1);

    confirm=getChar2("\nUna tecla para Grabar / <Esc> Salir sin Grabar: ");

    if(confirm!=27)
    {
        Employee* empNew=employee_newParametros(idAux,auxNombre,auxHoras,auxSalario);
        ll_add(pArrayListEmployee,empNew);
        r=1;
    }
    else
    {
        r=0;
    }
    return r;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int r=-1;
    int auxId;
    //char idAux[50];
    char auxHoras[50];
    char auxSalario[50];
    char auxNombre[130];
    int auxIntHoras=0;
    int auxIntSalario=0;
    char confirm;
    int index=-1;
    char opcion;
    char opcion2;

    Employee* emp;

    do
    {
        system("cls");
        getChoiceForm("Modifica Empleado",1,78);

        opcion2=getChar2("<s> Listar Empleados / una tecla para continuar");
        opcion2=tolower(opcion2);
        if (opcion2=='s')
        {
            printf("\nOrdenando...\n");
            //ll_sort2(pArrayListEmployee,ordenaPorId,0);
            ll_sort(pArrayListEmployee,ordenaPorId,1);
            muestraEmpleados(pArrayListEmployee);
        }


        r=getInt(&auxId,"\nIngrese Id: ","Error, ingrese Id entre (1-2,000): ",1,2000);
        if (!r)
        {
            takeBreak("\nError, debe ingresar Id (1-2000");
        }
        index=indexLinkedList(pArrayListEmployee,auxId);

        emp=((Employee* ) ll_get(pArrayListEmployee,index));

        if (emp!=NULL && emp->id==auxId)
        {
             strcpy(auxNombre,emp->nombre);
             sprintf(auxHoras,"%d",emp->horasTrabajadas);
             sprintf(auxSalario,"%d",emp->sueldo);

             printf("\nNombre: %s\nHoras Trabajadas: %s\nSueldo: %s",auxNombre,auxHoras,auxSalario);
             r=1;
        }
        else
        {
            takeBreak("Registro no Encontrado, Reintente...");
            r=-1;
        }


    }while (r!=1);

    do
    {
        printf("\nIngrese la opcion a modificar... ");
        opcion=getChar2("\na- Nombre / b- Horas Trabajadas / c- Sueldo / s-Termina -> ");
        opcion=tolower(opcion);
        if (opcion!='a' && opcion!='b' && opcion!='c' && opcion!='s')
        {
            continue;
        }
        switch (opcion)
        {
            case 'a':
               do
               {
                   getString("\nIngrese Nombre: ",auxNombre,130);
                   r=esSoloLetras(auxNombre);
                   if (!r)
                   {
                       takeBreak("\nError, debe ingresar solo letras");
                   }
                }while (r!=1);
                break;

            case 'b':
                do
                {
                    getString("\nIngrese Horas Trabajadas: ",auxHoras,50);
                    r=esNumerico(auxHoras);
                    if (!(r==1 && atoi(auxHoras)>0 && atoi(auxHoras)<=550))
                    {
                        takeBreak("\nError, Horas Trab solo numeros entre (0-550");
                    }
                }while (r!=1);
                break;

            case 'c':
                do
                {
                    getString("\nIngrese salario: ",auxSalario,50);
                    r=esNumerico(auxSalario);
                    if (!(r==1 && atoi(auxSalario)>0 && atoi(auxSalario)<15000000))
                    {
                        takeBreak("\nError, Salario solo numeros entre (0-15,000,000");
                    }
                }while (r!=1);
                break;

            case 's':
                break;

            default:
                break;
          }

    }while (opcion!='s');

    confirm=getChar2("\nUna tecla para Grabar / <Esc> Salir sin Grabar: ");

    if(confirm!=27)
    {
        //r=employee_setId(emp,idAux);
        r=employee_setNombre(emp,auxNombre);
        auxIntHoras=atoi(auxHoras);
        auxIntSalario=atoi(auxSalario);
        r=employee_setHorasTrabajadas(emp,auxIntHoras);
        r=employee_setSueldo(emp,auxIntSalario);
        r=1;
    }
    else
    {
        r=0;
    }
    return r;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int r=-1;
    int auxId;
    char auxHoras[50];
    char auxSalario[50];
    char auxNombre[130];
    char confirm;
    int index=-1;
    char opcion;
    char opcion2;

    Employee* emp;

    do
    {
        system("cls");
        getChoiceForm("Baja de Empleado",1,78);

        opcion2=getChar2("<s> Listar Empleados / una tecla para continuar");
        opcion2=tolower(opcion2);
        if (opcion2=='s')
        {
            printf("\nOrdenando...\n");
            ll_sort(pArrayListEmployee,ordenaPorId,1);
            //ll_sort2(pArrayListEmployee,ordenaPorId,0);
            muestraEmpleados(pArrayListEmployee);
        }

        r=getInt(&auxId,"\nIngrese Id: ","Error, ingrese Id entre (1-2,000): ",1,2000);
        if (!r)
        {
            takeBreak("\nError, debe ingresar Id (1-2000");
        }

        index=indexLinkedList(pArrayListEmployee,auxId);
        emp=((Employee* ) ll_get(pArrayListEmployee,index));

        if (emp!=NULL)
        {
             strcpy(auxNombre,emp->nombre);
             sprintf(auxHoras,"%d",emp->horasTrabajadas);
             sprintf(auxSalario,"%d",emp->sueldo);

             printf("\nNombre: %s\nHoras Trabajadas: %s\nSueldo: %s",auxNombre,auxHoras,auxSalario);
             r=1;
        }
        else
        {
            takeBreak("Registro no Encontrado, Reintente...");
            r=-1;
        }

    }while (r!=1);

    confirm=getChar2("\nEsta seguro de Borrar al Empleado? <s/n> ");
    confirm=tolower(confirm);
    if (confirm=='s')
    {
        opcion=getChar2("\n<b> Para Borrar...");

        if(opcion=='b')
        {
            r=ll_remove(pArrayListEmployee,index);

            if (r==0)
            {
                r=1;
            }
        }
        else
        {
            r=0;
        }
    }
    else
    {
        r=0;
    }


    return r;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int r=-1;
    if(pArrayListEmployee!=NULL)
    {
        encabezadoListados(" ID  | Nombre                         | Horas | Salario ",1,78);
        muestraEmpleados(pArrayListEmployee);
        printf("\n");
        takeBreak("Presione una tecla para continuar...");
        r=1;
    }

    return r;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int orden;
    int r=-1;

    if(pArrayListEmployee!=NULL)
    {

        switch(menuOrdenamiento())
        {
        case 'a':

            orden=opcionOrden();

            if(orden==1)
            {
                ll_sort(pArrayListEmployee,ordenaPorId,0);
                //controller_ListEmployee(pArrayListEmployee);
                r=1;
            }

            else if(orden==2)
            {
                ll_sort(pArrayListEmployee,ordenaPorId,1);
                //controller_ListEmployee(pArrayListEmployee);
                r=1;
            }

            break;


        case 'b':

            orden=opcionOrden();

            if(orden==1)
            {
                ll_sort(pArrayListEmployee,ordenaPorNombre,0);
                //controller_ListEmployee(pArrayListEmployee);
                r=1;
            }
            else if (orden==2)
            {
                ll_sort(pArrayListEmployee,ordenaPorNombre,1);
                //controller_ListEmployee(pArrayListEmployee);
                r=1;
            }
            break;

        case 'c':

            orden=opcionOrden();
            if(orden==1)
            {
                ll_sort(pArrayListEmployee,ordenaPorHorasTrabajadas,0);
                //controller_ListEmployee(pArrayListEmployee);
                r=1;
            }
            else if (orden==2)
            {
                ll_sort(pArrayListEmployee,ordenaPorHorasTrabajadas,1);
                //controller_ListEmployee(pArrayListEmployee);
                r=1;
            }
            break;

        case 'd':

            orden=opcionOrden();
            if(orden==1)
            {
                ll_sort(pArrayListEmployee,ordenaPorSalario,0);
                controller_ListEmployee(pArrayListEmployee);
                r=1;
            }
            else if (orden==2)
            {
                ll_sort(pArrayListEmployee,ordenaPorSalario,1);
                controller_ListEmployee(pArrayListEmployee);
                r=1;
            }

            break;

        default:

            r=-1;
            break;
        }
    }
    return r;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* auxEmp;
    int r=-1;
    int id;
    int hours;
    int salary;
    char name[130];

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        if(ll_len(pArrayListEmployee)>0)
        {
            pFile=fopen(path,"w");
            if(pFile!=NULL)
            {
                for(int i=0; i<ll_len(pArrayListEmployee); i++)
                {
                    auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
                    employee_getId(auxEmp,&id);
                    employee_getNombre(auxEmp,name);
                    employee_getHorasTrabajadas(auxEmp,&hours);
                    employee_getSueldo(auxEmp,&salary);
                    fprintf(pFile,"%d,%s,%d,%d\n",id,name,hours,salary);
                }
                fclose(pFile);
                r=1;
            }
            else
            {
                 r=0;
            }
        }
    }
    return r;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* auxEmp;
    int r=-1;

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        if(ll_len(pArrayListEmployee)>0)
        {
            pFile=fopen(path,"wb");
            if(pFile!=NULL)
            {
                for(int i=0; i<ll_len(pArrayListEmployee); i++)
                {
                    auxEmp=ll_get(pArrayListEmployee,i);
                    if(auxEmp!=NULL)
                    {
                        fwrite(auxEmp,sizeof(Employee),1,pFile);
                        r=1;
                    }
                }
                fclose(pFile);
            }
            else
            {
                r=0;
            }
        }
    }
    return r;
}

int validaciones(int signed codigo,int devolucion)
{
    switch (devolucion){

       case 0:
           break;

       case 1:
            if (codigo==-1)
            {
                takeBreak("Archivo .txt esta vacio...");
            }
            else if (codigo==1)
            {
               takeBreak("Archivo .txt Leido Correctamente...");
            }
            else if (codigo==0)
            {
                takeBreak("El archivo .txt no existe...");
            }
            break;

        case 2:
            if (codigo==-1)
            {
                takeBreak("Archivo .bin esta vacio...");
            }
            else if (codigo==1)
            {
               takeBreak("Archivo .bin Leido Correctamente...");
            }
            else if (codigo==0)
            {
                takeBreak("El archivo .bin no existe...");
            }
            break;

        case 3:
           if (codigo==-1){
            getChar2("\nError...Registro lleno o Inconsistencia en los datos\n");
           }
           break;

        case 4:
           if (codigo==-1)
           {
               takeBreak("Error en la funcion Registro no Modificado...\n");
           }
           else if (codigo==1)
           {
               takeBreak("El Registro fue modificado exitosamente...");
           }
           else if (codigo==0)
           {
               takeBreak("El registro no ha sido modificado...");
           }
           break;

        case 5:
           if (codigo==-1)
           {
               takeBreak("Error en la funcion Registro no borrado...\n");
           }
           else if (codigo==1)
           {
               takeBreak("El Registro fue borrado exitosamente...");
           }
           else if (codigo==0)
           {
               takeBreak("El registro no ha sido borrado...");
           }
           break;

        case 6:
           if (codigo==-1){

           getChar2("\nOpcion Incorrecta / Verifique y reintente...\n");
           }
           break;

        case 7:
           if (codigo==1010 || codigo==-1){

           getChar2("\nRegistros esta Vacio...Realice un alta para continuar\n");
           }
           break;

        case 8:
           if(codigo==1)
           {
                takeBreak("Archivo .txt se guardo correctamente\n");
           }
           else if(codigo==-1)
           {
                takeBreak("LinkedList o path vacio, No fue posible guardar el Archivo .txt\n");
           }
           else if(codigo==0)
           {
                takeBreak("No fue posible Abrir el archivo .txt ...\n");
           }
           break;

        case 9:
           if(codigo==1)
           {
                takeBreak("El archivo .bin se creo correctamente\n");
           }
           else if(codigo==-1)
           {
                takeBreak("LinkedList o path vacio, No fue posible guardar el Archivo .bin\n");
           }
           else if(codigo==0)
           {
                takeBreak("No fue posible Abrir el archivo .bin ...\n");
           }

           break;

        default:

           getChar2("Error Validacion inexistente");

           break;
    }

    return codigo;
}
