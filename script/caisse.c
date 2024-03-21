#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double RandDouble() {
	srand(time(NULL));
	double r = rand() % 10001 + ((double) rand() / RAND_MAX);
	

	return r;
}

int main() {
	double Paye;
	double Montant = RandDouble();
	
	printf("Le montant a payé est %.2lf.\n", Montant);
	printf("Veuillez indiquez le montant que vous allez donner : ");
	scanf("%lf", &Paye);
	
	while (Paye < Montant) {
		printf("Veuillez donner un montant supérieur ou égal : ");
		scanf("%lf", &Paye);
	}
		
	printf("Votre monnaie est de %.2lf", Paye - Montant);
	
	
}
