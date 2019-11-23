#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"
#include "inputs.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int r=-1;

    int cant;
    char buffer[4][150];

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        Employee* employeeNew;


            //cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n] \n",buffer[0],buffer[1],buffer[2],buffer[3]);

            while(!feof(pFile))
            {
                cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n] \n",buffer[0],buffer[1],buffer[2],buffer[3]);

                if (!atoi(buffer[0]))
                {
                    continue;
                }

                    if(cant==4)
                    {
                        employeeNew=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                        if(employeeNew!=NULL)
                        {
                            ll_add(pArrayListEmployee,employeeNew);
                            //printf("%d %s",employeeNew->id,employeeNew->nombre);
                            //miPausa("");
                            r=1;
                        }
                    }
            }
    }
    return r;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r=-1;
    int cant;
    if(pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {
            Employee* empleadoNew=employee_new();
            if(empleadoNew!=NULL)
            {
                cant=fread(empleadoNew,sizeof(Employee),1,pFile);
                if(cant!=1)
                {
                    if(feof(pFile))
                        break;
                    else
                    {
                        printf("No leyo el ultimo registro");
                        system("pause");
                    }
                }
                else
                {
                    r=ll_add(pArrayListEmployee,empleadoNew);
                    r=1;
                }
            }
        }
    }
    return r;
}
