#include <stdio.h>
#include <stdlib.h>

int op1,op2,res;

int suma(int op1, int op2);
int resta(int op1, int op2);
int multiplicacion(int op1, int op2);
int division(int op1, int op2);
int factorial(int n);

int main() {
    printf("Ingresar 1er operando A=");
    scanf("%d",&op1);
    printf("\nIngresar 2do operando B=");
    scanf("%d",&op2);
    res=suma(op1,op2);
    printf("\nEl resultado de A+B es: %d",res);
    res=resta(op1,op2);
    printf("\nEl resultado de A-B es: %d",res);
    res=division(op1,op2);
    printf("\nEl resultado de A/B es: %d",res);
    res=multiplicacion(op1,op2);
    printf("\nEl resultado de A*B es: %d",res);
    res=factorial(op1);
    printf("\nEl factorial de A es: %d",res);
    res=factorial(op2);
    printf(" y El factorial de B es: %d",res);

return 0;
}
int suma(int op1, int op2){
    int resultado;
    resultado=op1+op2;
    return resultado;
}
int resta(int op1, int op2){
  int resultado;
  resultado=op1-op2;
  return resultado;
}
int multiplicacion(int op1, int op2){
  int resultado;
  /*char e[30];
  if(op1==0||op2==0){
    e="No se puede dividir por 0";
    return e;
    break;
  }*/
  resultado=op1*op2;
  return resultado;
}
int division(int op1, int op2){
  int resultado;
  resultado=op1/op2;
  return resultado;
}
int factorial(int n){
  int resp;
  if(n==1)
  return 1;
  resp=n*factorial(n-1);
  return (resp);
}
