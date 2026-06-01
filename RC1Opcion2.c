#include <stdio.h>

//Llamado de la Funcion Calcular Promedio por estudiante
//Integración de punteros en la Funcion Funpromedio
void Funpromedio(float (*notas)[3],int *n);

int main ()
{
    //Determinar el numero de estudiantes
    int n;
    printf ("Ingrese el numero de estudiantes: ");
    scanf("%d",&n);

    //Declaracion de variables
    float notas[n][3];
    float promedio;
    int cont = 1;
    float nbaja = 10,nalta;
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

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++)
        {
            printf("|%.2f",notas[i][j]);
        } 
        printf("|\n");
    }
    

    //Funcion Calcular Promedio X Estudiante
    printf("|||||||| PROMEDIOS ||||||||\n");
    float matriznotas[n][3];
    Funpromedio(notas,&n);

    cont = 1;

    //Calculo de Promedio X Asignatura
    for(int j=0; j<3;j++){
    printf("Promedio Asignatura %d:",cont);
        for (int i=0;i<n;i++){ 
            
            promedio = promedio + notas[i][j];
        }
    promedio = promedio/n;
    printf("%.2f\n",promedio);
    promedio = 0;
    cont++;
    }

    cont = 1;

    //Identificación de la nota mas alta y baja
    for (int j = 0 ; j < 3; j++){
        printf("\n    **Asignatura %d**",cont);
      for (int i = 0 ; i < n; i++){
          
        if (notas[i][j] < nbaja) {
            nbaja = notas[i][j];
        }else if (notas[i][j] > nalta) {
            nalta = notas[i][j];
        }  
        }
        
        printf("\nLa nota mas baja es: %.2f",nbaja);
        printf("\nLa nota mas alta es: %.2f",nalta);
        cont++;
        nalta = 0;
        nbaja = 10;
    }
    
    cont = 1;

    //Identificación del numero de aprobados y reprobados X asignatura
    for(int j=0; j<3;j++){
    printf("\n   **Asignatura %d**",cont);
        for (int i=0;i<n;i++){
            if(notas[i][j] >= 6){
                aprobados++;
            }
        }
    printf("\nNro. Aprobados:  %d",aprobados);  
    reprobados=n-aprobados;
    printf("\nNro. Reprobados: %d",reprobados);    
    reprobados=0;
    aprobados=0;
    cont++;
    }


}

//Calculo de Promedio X Estudiante
void Funpromedio(float (*notas)[3],int *n){
    float promedio;
    int cont = 1;
    for(int i=0; i<*n;i++){
    printf("Promedio Estudiante %d:",cont);
        for (int j=0; j<3;j++){ 
            promedio = promedio + *( *(notas + i) + j);
        }
    promedio = promedio/3;
    printf("%.2f\n",promedio);
    promedio = 0;
    cont++;
    }
}

