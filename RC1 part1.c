#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones
void leerCalificaciones(float *calificaciones, int estudiantes, int asignaturastat);
void calcularPromedioEstudiantes(float *calificaciones, int estudiantes, int asignaturastat);
void calcularEstadisticasAsignaturas(float *calificaciones, int estudiantes, int asignaturastat);
void obtenerMaxMinEstudiante(float *calificaciones, int estudianteIdx, float *max, float *min, int asignaturastat);

int main() {
    int estudiantes;
    int asignaturas = 3; // Reemplazo de la constante definida

    printf("=== SISTEMA DE GESTION DE CALIFICACIONES ===\n");
    printf("Ingrese el numero de estudiantes: ");
    while (scanf("%d", &estudiantes) != 1 || estudiantes <= 0) {
        printf("Entrada invalida. Ingrese un numero entero mayor a 0: ");
        while (getchar() != '\n');
    }

    // Reserva de memoria dinamica para la matriz aplanada
    float *calificaciones = (float *)malloc(estudiantes * asignaturas * sizeof(float));
    
    if (calificaciones == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    leerCalificaciones(calificaciones, estudiantes, asignaturas);
    calcularPromedioEstudiantes(calificaciones, estudiantes, asignaturas);
    calcularEstadisticasAsignaturas(calificaciones, estudiantes, asignaturas);

    free(calificaciones);
    return 0;
}