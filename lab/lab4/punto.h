typedef struct punto *Punto;

Punto creaPunto(float, float);

void sequenza_punti(Punto*, int);
void stampa_sequenza(Punto *seq, int size);

float ascissa(Punto);
float ordinata(Punto);
float distanza(Punto, Punto);
void sposta(Punto, float,float);
Punto centroide(Punto*, int);

int punti_vicino_tot(Punto*, int, float); // restituisce numero di coppie < di distanza d
float distanza_max(Punto *sequenza, int size); //ritorna la distanza max tra punti presi a coppie