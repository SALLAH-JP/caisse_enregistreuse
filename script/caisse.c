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
	int Stock[14];
	int SommeStock;
	int Choix;
	
	for (int i = 0; i < 14; i++) {
		Stock[i] = 40;
		SommeStock += Stock[i] * Billets[i];
	}
	
	printf("Le montant a payé est %.2lf.\n", Montant);
	printf("Veuillez indiquez le montant que vous allez donner : ");
	scanf("%lf", &Paye);
	
	if (SommeStock < Paye) {
		printf("Désolé, vous ne pouvez pas faire cette transaction.\n");
		printf("Que voulez-vous faire maintenant?\nEntrez 0 pour fermer la caisse et 1 pour remplir la caisse : ");
		scanf("%i", &Choix);
		if (Choix == 1) {
			SommeStock = 0;
			for (int i = 0; i < 14; i++) {
				Stock[i] = 40;
				SommeStock += Stock[i] * Billets[i];
			}
		}
		else { return 1 ; }
	}
	
	while (Paye < Montant) {
		printf("Veuillez donner un montant supérieur ou égal : ");
		scanf("%lf", &Paye);
	}
	
	int Rendre[14] = {0};
	double aRendre = Paye - Montant;
	printf("Votre monnaie est de %.2lf.\n", aRendre);
	
	int i = 0;
	while (aRendre >= 0.05) {
		if ((aRendre >= Billets[i]) && (Stock[i] > 0)) {
			aRendre -= Billets[i];
			Stock[i] -= 1;
			Rendre[i] += 1;
		}
		else 
			i++;
	}
	
	printf("\n");
	printf("On vous rendra : \n");
	for (int i = 0; i < 14; i++) {
		if (Rendre[i] != 0) {
			if (i < 7) printf("%i Billet de %.2lf.\n", Rendre[i], Billets[i]);
			else printf("%i Pièce de %.2lf.\n", Rendre[i], Billets[i]);
		}
	}
	
	printf("\n");
	printf("Il reste dans le stock :\n");
	for (int i = 0; i < 14; i++) {
		if (i < 7) printf("%i Billet de %.2lf.\n", Stock[i], Billets[i]);
		else printf("%i Pièce de %.2lf.\n", Stock[i], Billets[i]);
	}
		

}
