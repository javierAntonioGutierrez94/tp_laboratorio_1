#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "firstLib.h"
#define CANTEMPLOYES 1000
/*******************************************************************
*Programa:Trabajo Practico Nº2
*
*Objetivo:El objetivo del siguiente trabajo es que el alumno sea capaz de demostrar que puede integrar
los conocimientos aprendidos hasta la clase 12.
* Manejo de arrays.
* Manejo de pasaje por referencia.
* Manejo de estructuras
*
*Version:0.1 del 04 octubre de2019
*Autor:Javier Gutierrez
*
********************************************************************/

int main()
{
    int mainMenu,answerMain=-1,mainVal=-1,functionReturn,flag=0;
    char yesNo;
    Employee empleados[CANTEMPLOYES];
    initEmployees(empleados,CANTEMPLOYES);
    do{
        printf("==========MENU PRINCIPAL=========\n");
        printf("\n1)ALTAS\n2)MODIFICAR\n3)BAJA\n4)INFORMAR\n");
        while(mainVal==-1){
            mainVal=getInt(&mainMenu,"\nIngrese Accion:","Opcion no valida intente de nuevo",1,4);
            }
                switch(mainMenu){
                    case 1:{
                        functionReturn=addEmployee(empleados,CANTEMPLOYES);
                        if(functionReturn==-1){
                            printf("\nLimite maximo de empleados alcanzado");
                        }
                        flag=1;
                        break;
                    }
                    case 2:{
                        if(flag==1){
                            functionReturn=findEmployeeById(empleados,CANTEMPLOYES);
                            if(functionReturn==-1){
                                printf("\nEl id no existe, No se modifico datos");
                            }
                        }else{
                            printf("\nPrimero cargue al menos un empleado");
                        }
                        break;
                    }
                    case 3:{
                        if(flag==1){
                        functionReturn=removeEmployee(empleados,CANTEMPLOYES);
                        if(functionReturn==-1){
                            printf("\nNo se realizo ninguna accion");
                            }
                        }else{
                            printf("\nPrimero cargue al menos un empleado");
                        }
                        break;
                    }
                    case 4:{
                        if(flag==1){
                        functionReturn=printEmployees(empleados,CANTEMPLOYES);
                        }else{
                            printf("\nPrimero cargue al menos un empleado");
                        }
                        break;
                    }
                }
        fflush(stdin);
        answerMain=getAnswer(&yesNo,"\nRealizara otra accion?: ","Solo S / N: ",'S','N');
        mainVal=-1;
        system("cls");
    }while(answerMain==0);
}
