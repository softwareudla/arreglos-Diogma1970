#include <stdio.h>


int main() {
    int i, j, a, b;
    int aprobados = 0;
    int reprobados = 0;
    float calificaciones[5][3];
    float suma_estudiantes = 0;
    float suma_materias = 0;
    float promedio_estudiante;
    float promedio_materias;
    float mayor, menor;

    // Ingreso de calificaciones
    printf(" Ingreso de Calificaciones: \n");
    for (i = 0; i < 5; i++) {
        a=i+1;
        printf("\nEstudiante %d:\n", a);
        for (j = 0; j < 3; j++) {
            b=j+1;
            do {
                printf("  Ingrese calificacion para asignatura %d (0-10): ", b);
                scanf("%f", &calificaciones[i][j]);
                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10) {
                    printf("  Calificacion invalida. Intente de nuevo.\n");
                }
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
    }
    a=0;
    b=0;

    // Promedio por estudiante
    printf("\n Promedio por estudiante: \n");
    for (i = 0; i < 5; i++) {
        suma_estudiantes = 0;
        for (j = 0; j < 3; j++) {
            suma_estudiantes += calificaciones[i][j];
        }
        promedio_estudiante = suma_estudiantes/3;
        a=i+1;
        printf("Estudiante %d: %.2f\n", a, promedio_estudiante);
    }
    a=0;

    // Promedio por asignatura
    printf("\n Promedio por asignatura: \n");
    for (j = 0; j < 3; j++) {
        suma_materias = 0;
        for (i = 0; i < 5; i++) {
            suma_materias += calificaciones[i][j];
        }
        promedio_materias = suma_materias/5;
        b=j+1;
        printf("Asignatura %d: %.2f\n", b, promedio_materias);
    }
    b=0;

    // Nota mas alta y mas baja por asignatura
    printf("\n Nota mas alta y mas baja por asignatura: \n");
    for (j = 0; j < 3; j++) {
        mayor = calificaciones[0][j];
        menor = calificaciones[0][j];
        for (i = 0; i < 5; i++) {
            if (calificaciones[i][j] > mayor) {
                mayor = calificaciones[i][j];
            }
            if (calificaciones[i][j] < menor) {
                menor = calificaciones[i][j];
            }
        }
        b=j+1;
        printf("Asignatura %d - Mayor nota: %.2f, Menor nota: %.2f\n", b, mayor, menor);
    }
    b=0;

    // Aprobados y reprobados por asignatura
    printf("\n Aprobados y reprobados por asignatura: \n");
    for (j = 0; j < 3; j++) {
        aprobados = 0;
        reprobados = 0;
        for (i = 0; i < 5; i++) {
            if (calificaciones[i][j] >= 6) {
                aprobados++;
            } else {
                reprobados++;
            }
        }
        b=j+1;
        printf("Asignatura %d - Aprobados: %d, Reprobados: %d\n", b, aprobados, reprobados);
    }

    return 0;
}
