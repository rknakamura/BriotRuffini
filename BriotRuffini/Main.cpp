#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
	int n = 0, z = 0;
	int *coeficientes, *aux, *resultado;

	while (n <= 0) {
		printf("Digite um numero n maior que 0: ");
		scanf("%d", &n);
	}

	coeficientes = (int *)malloc(n * sizeof(int));
	aux = (int *)malloc(n * sizeof(int));
	resultado = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("Digite o valor para o coeficiente %d: ", i);
		scanf("%d", &coeficientes[i]);
	}

	printf("Digite o valor para z: ");
	scanf("%d", &z);	

	for (int i = n - 1; i >= 0; i--) {
		if (i == (n - 1))
			resultado[i] = coeficientes[i];
		else {
			aux[i] = resultado[i + 1] * z;
			resultado[i] = aux[i] + coeficientes[i];
		}
	}

	printf("Polinomio Q(x) = %dx^%d ", resultado[n - 1], n - 2);

	for (int i = n - 2; i > 0; i--) {
		if (resultado[i] >= 0)
			printf("+");

		if (i == 1)
			printf(" %d \n", resultado[i]);
		else
			printf(" %dx^%d", resultado[i], i - 1);
			
	}

	printf("Resto = %d", resultado[0]);

	getch();
	return 0;
}