do {
    nomina = nomina + sal;
    i++;
    printf("Ingrese el salario del profesor, 0 para terminar: ");
    scanf("%f", &sal);
} while (sal != 0);

prom = nomina / i;
printf("\nNomina: %.2f \t Promedio de salarios: %.2f\n", nomina, prom);