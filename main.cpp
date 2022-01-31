#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const int COGNOME_MAX = 15;
const int N_CANDIDATI = 7;
const int N_COLLEGI = 5;
char candidati[N_CANDIDATI][COGNOME_MAX];
int grigliaVoti[N_COLLEGI][N_CANDIDATI];
/* Questa procedura legge il file il cui nome è passato come argomento e
popola i vettori “candidati” e “grigliaVoti” */
void leggi_voti(const char nomeFile[])
{
// PUNTI 4
}
/* Questa funzione restituisce la somma della colonna con indice
“indiceColonna” del vettore “voti” */
int somma_colonna(int voti[][N_CANDIDATI], int righe, int indiceColonna)
{
// PUNTI 2
}
/* Questa funzione restituisce la somma di tutti gli elementi del vettore
“voti” */
int somma_vettore(int voti[][N_CANDIDATI], int righe)
{
// PUNTI 2
}
/* Questa funzione restituisce true se le stringhe passate come argomento
sono uguali, false altrimenti */
bool confronta(char* str1, char* str2)
{
// PUNTI 1
}
/* Questa procedura prende il nome di un candidato e, se il candidato
esiste, ne stampa i risultati, altrimenti ne comunica l'inesistenza
all'utente */
void stampa_candidato(char candidato[])
{
// PUNTI 4
}
int main()
{
// PUNTI 3
}
