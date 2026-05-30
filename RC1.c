#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones
void leerCalificaciones(float *calificaciones, int estudiantes, int asignaturastat);
void calcularPromedioEstudiantes(float *calificaciones, int estudiantes, int asignaturastat);
void calcularEstadisticasAsignaturas(float *calificaciones, int estudiantes, int asignaturastat);
void obtenerMaxMinEstudiante(float *calificaciones, int estudianteIdx, float *max, float *min, int asignaturastat);

int main() {
    int estudiantes;
    int asignaturas = 3; 

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

void leerCalificaciones(float *calificaciones, int estudiantes, int asignaturastat) {
    printf("\n--- INGRESO DE CALIFICACIONES (Rango: 0 a 10) ---\n");
    for (int i = 0; i < estudiantes; i++) {
        printf("\nEstudiante %d:\n", i + 1);
        for (int j = 0; j < asignaturastat; j++) {
            float nota;
            do {
                printf("  Asignatura %d: ", j + 1);
                if (scanf("%f", &nota) != 1) {
                    printf("    Por favor, ingrese un numero valido.\n");
                    while (getchar() != '\n');
                    nota = -1;
                    continue;
                }
                if (nota < 0 || nota > 10) {
                    printf("    Error: La calificacion debe estar entre 0 y 10.\n");
                }
            } while (nota < 0 || nota > 10);
            
            *(calificaciones + (i * asignaturastat + j)) = nota;
        }
    }
}

void calcularPromedioEstudiantes(float *calificaciones, int estudiantes, int asignaturastat) {
    printf("\n======================================================\n");
    printf("   REPORTE DE RENDIMIENTO POR ESTUDIANTE\n");
    printf("======================================================\n");
    
    for (int i = 0; i < estudiantes; i++) {
        float suma = 0;
        float max, min;
        
        for (int j = 0; j < asignaturastat; j++) {
            suma += *(calificaciones + (i * asignaturastat + j));
        }
        
        float promedio = suma / asignaturastat;
        obtenerMaxMinEstudiante(calificaciones, i, &max, &min, asignaturastat);
        
        printf("Estudiante %d -> Promedio: %.2f | Maxima: %.2f | Minima: %.2f\n", 
               i + 1, promedio, max, min);
    }
}

void obtenerMaxMinEstudiante(float *calificaciones, int estudianteIdx, float *max, float *min, int asignaturastat) {
    *max = *(calificaciones + (estudianteIdx * asignaturastat + 0));
    *min = *(calificaciones + (estudianteIdx * asignaturastat + 0));
    
    for (int j = 1; j < asignaturastat; j++) {
        float notaActual = *(calificaciones + (estudianteIdx * asignaturastat + j));
        if (notaActual > *max) *max = notaActual;
        if (notaActual < *min) *min = notaActual;
    }
}

void calcularEstadisticasAsignaturas(float *calificaciones, int estudiantes, int asignaturastat) {
    printf("\n======================================================\n");
    printf("   REPORTE DE ESTADISTICAS POR ASIGNATURA\n");
    printf("======================================================\n");
    
    for (int j = 0; j < asignaturastat; j++) {
        float suma = 0;
        float max = *(calificaciones + (0 * asignaturastat + j));
        float min = *(calificaciones + (0 * asignaturastat + j));
        int aprobados = 0;
        int reprobados = 0;
        
        for (int i = 0; i < estudiantes; i++) {
            float nota = *(calificaciones + (i * asignaturastat + j));
            suma += nota;
            
            if (nota > max) max = nota;
            if (nota < min) min = nota;
            
            if (nota >= 6.0) {
                aprobados++;
            } else {
                reprobados++;
            }
        }
        
        float promedio = suma / estudiantes;
        
        printf("Asignatura %d:\n", j + 1);
        printf("  > Promedio General: %.2f\n", promedio);
        printf("  > Calificacion Mas Alta: %.2f | Mas Baja: %.2f\n", max, min);
        printf("  > Aprobados: %d | Reprobados: %d\n\n", aprobados, reprobados);
    }
}