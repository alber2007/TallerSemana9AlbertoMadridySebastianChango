#include <stdio.h>

//Prototipo de la Funcion Calcular Promedio por estudiante
//Integración de punteros en la Funcion Funpromedio
//Prototipo de la Funcion Calcular Promedio por asignatura
//Integración de punteros en la Funcion FunpromedioA
void Funpromedio(float (*notas)[3],int *n);
void FunpromedioA(float (*notas)[3],int *n);
void FunnotaAB(float (*notas)[3],int *n);
void funApRp(float(*notas)[3],int *n);

int main ()
{
    //Determinar el numero de estudiantes
    int n;
    printf ("Ingrese el numero de estudiantes: ");
    scanf("%d",&n);
    while (n<1)
    {
        printf("ERROR Ingrese un numero mayor que 0\n");
        scanf("%d",&n);
    }

    //Declaracion de variables
    float notas[n][3];
    float promedio;
    int cont = 1;
    float nbaja = 10,nalta=0;
    int aprobados = 0, reprobados = n;

    //Bucle para el ingreso de notas(datos para la matriz)
    for(int i=0; i<n;i++){
    printf("**Estudiante:%d**",cont);
        for (int j=0; j<3;j++){
        printf("\nIngrese la nota: ");
        scanf("%f",&notas[i][j]);
    while(notas[i][j] > 10 || notas[i][j] < 0)
        {
            printf("ERROR Ingrese Datos en rango (0-10)\n");
            scanf("%f",&notas[i][j]);
        }

        }
        cont++;
    }

    cont = 1;

    //Impresion de la Matriz notas
    printf("\n\n------------- MATRIZ NOTAS -------------\n\n");
    for (int i = 0; i < n; i++){
        printf("Estudiante %d",cont);
        for (int j = 0; j < 3; j++)
        {
            printf("  | %.2f",notas[i][j]);
        } 
        printf("|\n");
        cont++;
    }
    

    //Funcion Calcular Promedio X Estudiante
    printf("\n\n---------- PROMEDIOS x ESTUDIANTE ----------\n\n");
    float matriznotas[n][3];
    Funpromedio(notas,&n);
    cont = 1;

    //Calculo de Promedio X Asignatura
    printf("\n\n---------- PROMEDIOS x ASIGNATURA ----------\n\n");
    FunpromedioA(notas,&n);
    cont = 1;

    //Identificación de la nota mas alta y baja
    printf("\n\n---------- NOTAS ALTA Y BAJA ----------\n");
    FunnotaAB(notas,&n);
    cont = 1;

    //Identificación del numero de aprobados y reprobados X asignatura
    printf("\n\n---------- APROBADOS Y REPROBADOS ----------\n");
    funApRp(notas,&n);
}

//Calculo de Promedio X Estudiante
//Integracion de punteros en el calculo de Promedio X Estudiante
void Funpromedio(float (*notas)[3],int *n){
    float promedio;
    int cont = 1;
    for(int i=0; i<*n;i++){
    printf("        Promedio Estudiante %d: ",cont);
        for (int j=0; j<3;j++){ 
            promedio = promedio + *( *(notas + i) + j);
        }
    promedio = promedio/3;
    printf("%.2f\n",promedio);
    promedio = 0;
    cont++;
    }
}

//Calculo de Promedio X Asignatura
//Integracion de punteros en el calculo de Promedio X Asignatura
void FunpromedioA(float (*notas)[3],int *n){
    float promedio;
    int cont = 1;
    for(int j=0; j<3;j++){
    printf("        Promedio Asignatura %d:",cont);
        for (int i=0;i<*n;i++){ 
            
            promedio = promedio + *( *(notas + i) + j);
        }
    promedio = promedio / *n;
    printf("%.2f\n",promedio);
    promedio = 0;
    cont++;
    }
} 

void FunnotaAB(float (*notas)[3],int *n){
    float nbaja = 10,nalta=0;
    int cont = 1;
    for (int j = 0 ; j < 3; j++){
        printf("\n            **Asignatura %d**",cont);
      for (int i = 0 ; i < *n; i++){
        
        if (i == 0) {
        nalta = notas[i][j];
        nbaja = notas[i][j];
        }else if (notas[i][j] < nbaja) {
            nbaja = notas[i][j];
        }else if (notas[i][j] > nalta) {
            nalta = notas[i][j];
        }  
        }
        
        printf("\n       La nota mas baja es: %.2f",nbaja);
        printf("\n       La nota mas alta es: %.2f",nalta);
        cont++;
        nalta = 0;
        nbaja = 10;
    }
}

void funApRp(float(*notas)[3],int *n){
    int aprobados = 0, reprobados = *n;
    int cont = 1;
    for(int j=0; j<3;j++){
    printf("\n             **Asignatura %d**",cont);
        for (int i=0;i<*n;i++){
            if(notas[i][j] >= 6){
                aprobados++;
            }
        }
    printf("\n          Nro. Aprobados:  %d",aprobados);  
    reprobados=*n-aprobados;
    printf("\n          Nro. Reprobados: %d",reprobados);    
    reprobados=0;
    aprobados=0;
    cont++;
    }
}

