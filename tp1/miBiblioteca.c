
int suma(int op1,int op2){
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
    resultado=op1*op2;
    return resultado;

}
int division(int op1, int op2){
    int resultado;
    resultado=(float)op1/op2;
    return resultado;
}
int factorial(int valor){
    int i,res=1;
    for(i=valor;i>0;i--){
        res=res*i;
    }
    return res;
}
