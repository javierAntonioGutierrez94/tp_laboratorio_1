#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int num;
    num=*input;
    printf(message);
    fflush(stdin);
    scanf("\n%d",&num);
    if(num>hiLimit||num<lowLimit){
        printf("\n%s",eMessage);
        return -1;
    }else{
        *input=num;
        return 0;
    }
}

int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    float num;
    num=*input;
    printf(message);
    fflush(stdin);
    scanf("\n%f",&num);
    if(num>hiLimit||num<lowLimit){
        printf("\n%s",eMessage);
        return -1;
    }else{
        *input=num;
        return 0;
    }
}

int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    char word;
    printf(message);
    scanf("%c",&word);
    if(word<lowLimit||word>hiLimit){
        printf(eMessage);
        return -1;
    }else{
        *input = word;
        return 0;
    }
}

int getString(char* input[],char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int cantidad;
    char buffer[hiLimit];
    printf(message);
    fflush(stdin);
    fgets(buffer,sizeof(buffer)-2,stdin);
    cantidad=strlen(buffer);
    buffer[cantidad-1] = '\0';
    if(cantidad<lowLimit||cantidad>hiLimit){
        printf(eMessage);
        return -1;
    }else{
        strcpy(*input,buffer);
        return 0;
    }
}

int getAnswer(char* input,char message[],char eMessage[], char positive, char negative){
    char word;
    printf(message);
    fflush(stdin);
    scanf("%c",&word);
    word=tolower(word);
    positive=tolower(positive);
    negative=tolower(negative);
    while(word!=positive&&word!=negative){
        printf(eMessage);
        fflush(stdin);
        scanf("%c",&word);
        word=tolower(word);
    }
    if(word==positive){
        return 0;
    }else if(word==negative){
        return -1;
    }
}
