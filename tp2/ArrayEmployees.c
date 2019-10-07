#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "firstLib.h"

int initEmployees(Employee* list, int len){
    int i;
    for(i=0;i<len;i++){
    list[i].isEmpty=1;
    }
    return 0;
}

int addEmployee(Employee* list, int len){
    int i,end,flag=1;
    char endChar;
    for(i=0;i<len;i++){
        if(list[i].isEmpty==1){
            printf("\nSe contro lugar");
            flag=0;
            list[i].id=i;
            fflush(stdin);
            printf("\ningrese el Nombre: ");
            fflush(stdin);
            scanf("%s",list[i].name);
            printf("\ningrese el Apellido: ");
            fflush(stdin);
            scanf("%s",list[i].lastName);
            printf("\ningrese el Salario: ");
            fflush(stdin);
            scanf("%f",&list[i].salary);
            printf("\ningrese el Sector:\n1-SectorUno\n2-SectorDos\n3-SectorTres\n4-SectorCuatro\nIngrese Sector: ");
            fflush(stdin);
            scanf("%d",&list[i].sector);
            list[i].isEmpty=0;
            end=getAnswer(&endChar,"Desea seguir cargando otro Empleado?","Solo s/n",'s','n');
            if(end==-1){
                break;
            }else{
                flag=1;
            }
        }
    }
    if(flag==1){
    return -1;
    }
    return 0;
}

int findEmployeeById(Employee* list, int len){
    int auxId,flag=-1,flag2=0,i,menuMod,end,optionMenuMod=-1,r;
    Employee aux;
    char keepGoing;
    printf("ingrese el ID de la persona: ");
    fflush(stdin);
    scanf("%d",&auxId);
    for(i=0;i<len;i++){
        if(auxId==list[i].id){
            flag=0;
            do{
                printf("Esta es la persona con ese ID:");
                printf("\nId:%d\tNombre:%s\tApellido:%s\tSalario:%.2f\nSector:%d",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
                printf("\n\n======MENU Modificacion=======");
                printf("\n1) Modificar Nombre");
                printf("\n2) Modificar Apellido");
                printf("\n3) Modificar Salario");
                printf("\n4) Modificar Sector");
                printf("\n5) Salir");
                while(optionMenuMod!=0){
                    fflush(stdin);
                    optionMenuMod=getInt(&menuMod,"\nQue desea modificar?:\n","opcion no valida",1,5);
                }
                optionMenuMod=-1;
                switch(menuMod){
                    case 1:{
                        printf("\ningrese el Nombre: ");
                        fflush(stdin);
                        scanf("%s",aux.name);
                        strcpy(list[i].name,aux.name);
                        flag2=1;
                        break;
                    }
                    case 2:{
                        printf("\ningrese el apellido: ");
                        fflush(stdin);
                        scanf("%s",aux.lastName);
                        strcpy(list[i].lastName,aux.lastName);
                        flag2=1;
                        break;
                    }
                    case 3:{
                        printf("\ningrese el Salario: ");
                        fflush(stdin);
                        scanf("%f",&aux.salary);
                        list[i].salary=aux.salary;
                        flag2=1;
                        break;
                    }
                    case 4:{
                        while(r!=0){
                        r=getInt(&aux.sector,"\ningrese el Sector:\n1-SectorUno\n2-SectorDos\n3-SectorTres\n4-SectorCuatro","Sector incorrecto",1,4);
                        }
                        list[i].sector=aux.sector;
                        flag2=1;
                        break;
                    }
                    case 5:{
                        flag2=0;
                        break;
                    }
                }
                if(flag2==0){
                    printf("\nNo se modifico ningun dato");
                }else{
                    printf("\nLos Datos se modificaron correctamente");
                }
                fflush(stdin);
                end=getAnswer(&keepGoing,"\nDesea seguir modificando datos?","Solo s/n",'s','n');
            }while(end!=-1);
        }else{
            flag=-1;
        }
    }
    if(flag==0){
        return 0;
    }else{
        return -1;
    }
}

int removeEmployee(Employee* list, int len){
    int auxId,flag1=0,i,response=-1;
    char keepGoing;
    printf("ingrese el id de la persona: ");
    fflush(stdin);
    scanf("%d",&auxId);
    for(i=0;i<len;i++){
        if(auxId==list[i].id){
            response=getAnswer(&keepGoing,"Desea dar de baja? s/n","Solo s/n",'s','n');
            if(response==0){
                list[i].isEmpty=1;
                flag1=1;
                break;
            }else{
                printf("No se modificaron los datos");
            }
        }
        response=-1;
    }
    if(flag1==0){
        printf("No se encontro el registro");
        return -1;
    }
    return 0;
}

int printEmployees(Employee* list, int length){
    int i,j;
    Employee auxPer;
    for(i=0;i<length;i++){
        for(j=i+1;i<length;i++){
            if(list[i].sector>list[j].sector){
                    auxPer=list[i];
                    list[i]=list[j];
                    list[j]=auxPer;
                }
            }
        }
    for(i=0;i<length;i++){
        if(list[i].isEmpty==0){
            printf("\nSector: %d\tID: %d\tApellido: %s\tNombre: %s\tSalario: %.2f",list[i].sector,list[i].id,list[i].lastName,list[i].name,list[i].salary);
        }
    }
  return 0;
}

