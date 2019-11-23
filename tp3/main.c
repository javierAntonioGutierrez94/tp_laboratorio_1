#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"

/*******************************************************************
*Programa:Trabajo Practico N4
*
*El objetivo del siguiente trabajo es que el alumno sea capaz de demostrar que puede integrar
*los conocimientos aprendidos durante la cursada en un caso real.
* Manejo de punteros.
* Manejo de linkedList.
* Manejo de estructuras.
* Manejo de memoria dinámica.
*
*Version:0.1 del 21 de Noviembre de el 2019
*Autor:Javier Gutierrez
*
********************************************************************/



int main()
{
    int option = 0;
    int r;
    int flagLoadLinkedList=0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        switch(menuPrincipal())
        {
        case 1:

            if(!flagLoadLinkedList)
            {
                r=controller_loadFromText("./data.csv",listaEmpleados);
                validaciones(r,1);
                if (r==1){
                    flagLoadLinkedList=1;
                }
            }
            else
            {
                takeBreak("\nExiste un archivo cargado\n");

            }

            break;

        case 2:

            if(!flagLoadLinkedList)
            {
                r=controller_loadFromBinary("./data.bin",listaEmpleados);
                validaciones(r,2);
                if (r==1){
                    flagLoadLinkedList=1;
                }
            }
            else
            {
                takeBreak("\nExiste un archivo cargado\n");

            }
            break;

        case 3:

            r=controller_addEmployee(listaEmpleados);
            //addOk=statusAddEmployee(result);
            //if(addOk==1)
            //    flagAdd=1;
            break;

        case 4:

            r=controller_editEmployee(listaEmpleados);
            validaciones(r,4);

            break;

        case 5:

            r=controller_removeEmployee(listaEmpleados);
            validaciones(r,5);
            break;

        case 6:
            r=controller_ListEmployee(listaEmpleados);
            validaciones(r,6);
            break;

        case 7:
            //ll_sort2(listaEmpleados,ordenaPorSalario,1);
            //r=controller_ListEmployee(listaEmpleados);
            r=controller_sortEmployee(listaEmpleados);
            validaciones(r,7);
            break;

        case 8:
            r=controller_saveAsText("./data.csv",listaEmpleados);
            validaciones(r,8);
            if (r==1){
                //ll_deleteLinkedList(listaEmpleados);
                //listaEmpleados=ll_newLinkedList();
            }
            break;

        case 9:
            r=controller_saveAsBinary("./data.bin",listaEmpleados);
            validaciones(r,9);
            if(r==1)
            {
                //ll_deleteLinkedList(listaEmpleados);
                //listaEmpleados=ll_newLinkedList();
            }
            break;

        case 10:
            option=10;
            break;
        }
    }while(option != 10);
    return 0;
}
