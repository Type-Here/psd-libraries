#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "punto.h"

struct punto{
    float x;
    float y;
};

Punto creaPunto(float a, float b){
    
    Punto p;

	p = malloc(sizeof(struct punto));

    p->x = a;
    p->y = b;

    return p;
}

void sequenza_punti(Punto* seq, int size){
	int i;
	float x,y;
	for(i=0; i<size; i++){
		printf("Creazione punto num %d\n", i+1);
		printf("Inserisci ascissa: ");
		scanf("%f", &x);
		printf("Inserisci ordinata: ");
		scanf("%f", &y);
		seq[i] = creaPunto(x,y);
		printf("Creato punto %.2f,%.2f \n\n", x, y);
	}
}


float ascissa(Punto p){
    return p->x;
}

float ordinata(Punto p){
    return p->y;
}


void stampa_sequenza(Punto *seq, int size){
	int i;
	for(i=0; i<size; i++){
		printf("%.2f,%.2f; ",ascissa(seq[i]), ordinata(seq[i]));
	}
	printf("\n");
}


float distanza(Punto p1, Punto p2)
{   
    float dx = (p1->x - p2->x) * (p1->x - p2->x);
    float dy = (p1->y - p2->y) * (p1->y - p2->y);

    return sqrt(dx+dy);
}

void sposta(Punto p, float dx, float dy){
	p->x += dx;
	p->y += dy;
}

Punto centroide(Punto *seq, int size){
	int i;
	Punto centroide;
	float somma_x, somma_y;
	for(i=0;i<size;i++){
		somma_x += seq[i]->x;
		somma_y += seq[i]->y;
	}
	
	return creaPunto(somma_x/size, somma_y/size );
	
}


/* Calcola il numero di m coppie di punti che hanno distanza minore di un numero d */
int punti_vicino_tot(Punto *sequenza, int size, float dist){
	int i;
	int k = size;
	if(size % 2 != 0){
		k = size -1; //se sequenza dispari l'ultimo punto non può essere accoppiato.
	}
	int coppie = 0;
	for(i=0; i<k; i+=2){
		if(distanza(sequenza[i], sequenza[i+1]) < dist){
			coppie++;
		}
	return coppie;
	}
}


float distanza_max(Punto *sequenza, int size){
	int i;
	int k = size;
	if(size % 2 != 0){
		k = size -1; //se sequenza dispari l'ultimo punto non può essere accoppiato.
	}
	float dist_max = 0;
	for(i=0; i<k; i+=2){
		float d = distanza(sequenza[i], sequenza[i+1]);
		if(d > dist_max){
			dist_max = d;
		}
	return dist_max;
	}
}