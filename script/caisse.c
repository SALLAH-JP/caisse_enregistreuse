#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


double RandDouble() {
	srand(time(NULL));
	double r = rand() % 10001 + ((double) rand() / RAND_MAX);
	r = (r * 100) / 100;
	

	return r;
}

int main() {
	double Paye;
	double Montant = RandDouble();
	double Billets[] = {2000.0, 1000.0, 500.0, 200.0, 100.0, 50.0, 25.0, 20.0, 10.0, 5.0, 1.0, 0.5, 0.2, 0.05}; 
	
	printf("Le montant a payé est %.2lf.\n", Montant);
	printf("Veuillez indiquez le montant que vous allez donner : ");
	scanf("%lf", &Paye);
	
	while (Paye < Montant) {
		printf("Veuillez donner un montant supérieur ou égal : ");
		scanf("%lf", &Paye);
	}
	
	int Rendre[14] = {0};
	double aRendre = Paye - Montant;
	printf("Votre monnaie est de %.2lf.\n", aRendre);
	
	int i = 0;
	while (aRendre > 1) {
		if (aRendre >= Billets[i]) {
			aRendre -= Billets[i];
			Rendre[i] += 1;
		}
		else 
			i++;
	}
	
	printf("On vous rendra : \n");
	for (int i = 0; i < 14; i++) {
		if (Rendre[i] != 0) {
			printf("%i Billet de %.0lf.\n", Rendre[i], Billets[i]);
		}
	}

}
