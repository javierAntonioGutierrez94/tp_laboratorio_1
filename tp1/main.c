#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"



int main() {
    int op1=0,op2=0,res=0,flag=0,opcion=0;
    printf("======== Bienvenidos a su Calculadora=========\n");
  do{
    printf("\nPor Favor Ingrese el 1er operando A=");
    scanf("%d",&op1);
    printf("\nPor Favor Ingresar el 2do operando B=");
    scanf("%d",&op2);
    printf("\nQue operacion Desea realizar?\n\n1)Calcular la suma (A+B)\n2)Calcular la resta (A-B)\n3)Calcular la division (A/B)\n4)Calcular la multiplicacion (A*B)\n5)Calcular el factorial (A!) y (B!)\n");
    scanf("%d",&opcion);
    while(opcion>5||opcion<1){
        printf("\nError por favor ingrese una operacion valida\n");
        scanf("%d",&opcion);
    }
    switch(opcion){
        case 1:{
            res=suma(op1,op2);
            printf("\nEl resultado de A+B es: %d\n",res);
            break;
        }
        case 2:{
            res=resta(op1,op2);
            printf("\nEl resultado de A-B es: %d\n",res);
            break;
        }
        case 3:{
            if(op1==0||op2==0){
                printf("\nNo es posible dividir por 0\n");
                break;
            }else{
                res=division(op1,op2);
                printf("\nEl resultado de A/B es: %d\n",res);
                break;
            }
        }
        case 4:{
            res=multiplicacion(op1,op2);
            printf("\nEl resultado de A*B es: %d\n",res);
            break;
        }
        case 5:{
            res=factorial(op1);
            printf("\nEl factorial de A es: %d",res);
            res=factorial(op2);
            printf(" y El factorial de B es: %d\n",res);
            break;
        }
    }
    printf("\nSi Desea volver a operar, presione 1\n");
    scanf("%d",&flag);
  }while(flag==1);
return 0;
}
