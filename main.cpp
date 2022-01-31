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
    fstream file;
    file.open(nomeFile,ios::in);
    if(!file){
        cout<<nomeFile<<" NON TROVATO!"<<endl;
        exit(1);
    }
    for(int i=0;i<N_CANDIDATI;i++){
        file>>candidati[i];
        //cout<<candidati[i]<<" ";
    }

    //cout<<endl;

    for(int i=0;i<N_COLLEGI;i++){
        for(int j=0;j<N_CANDIDATI;j++){
            file>>grigliaVoti[i][j];
            //cout<<grigliaVoti[i][j]<<"\t";
        }
        //cout<<endl;
    }

    //cout<<endl;

}

/* Questa funzione restituisce la somma della colonna con indice
“indiceColonna” del vettore “voti” */
int somma_colonna(int voti[][N_CANDIDATI], int righe, int indiceColonna)
{
    int somma=0;
for(int i=0;i<righe;i++){
    /*cout<<voti[i][indiceColonna];
    if(i!=righe-1) cout<<" + ";
    else cout<<" = "<<endl;*/
    somma+=voti[i][indiceColonna];
}
    //cout<<somma<<endl;
    return somma;
}

/* Questa funzione restituisce la somma di tutti gli elementi del vettore
“voti” */
int somma_vettore(int voti[][N_CANDIDATI], int righe)
{
    int somma=0;
    for(int i=0;i<N_CANDIDATI;i++)
        somma+=somma_colonna(voti,righe,i);
    return somma;
}

/* Questa funzione restituisce true se le stringhe passate come argomento
sono uguali, false altrimenti */
bool confronta(char* str1, char* str2)
{
    while(*str1==*str2){
        if(*str1=='\0')
            return true;
        str1++;
        str2++;
    }
    return false;
}

/* Questa procedura prende il nome di un candidato e, se il candidato
esiste, ne stampa i risultati, altrimenti ne comunica l'inesistenza
all'utente */
void stampa_candidato(char candidato[])
{
    //Mette in minuscolo il candidato da cercare
    for(int i=0;i<COGNOME_MAX;i++)
        candidato[i]=tolower(candidato[i]);

    char candConf[COGNOME_MAX];

    bool found=false;
    int c=0;
for(int i=0;i<N_CANDIDATI;i++){

    //Memorizza in un vettore di appoggio i candidati del file in minuscolo
    for(int j=0;j<COGNOME_MAX;j++)
        candConf[j]=tolower(candidati[i][j]);

    if(confronta(candidato,candConf)){
        found=true;
        c=i;
        break;
    }
}

    if(found){

        int votiC=somma_colonna(grigliaVoti,N_COLLEGI,c);
        int votiTot=somma_vettore(grigliaVoti,N_COLLEGI);
        double perc=(double)(votiC*100)/votiTot;


        cout<<"Il candidato "<<candidati[c]<<" ha ottenuto "<<votiC<<" voti";
        //Stampa solo due cifre decimali
        cout<<setprecision(2)<<fixed;
        cout<<" pari al "<<perc<<" %."<<endl;
    }
    else {
        //Mette la maiuscola iniziale al candidato non trovato
        candidato[0]=toupper(candidato[0]);
        cout<<"Nessun candidato si chiama "<<candidato<<"."<<endl;
    }
}

int main()
{
    //TODO cambia path
    char nomeFile[]="C:\\Users\\Thinkpad User\\CLionProjects\\elezioni\\elezioni.txt";
    leggi_voti(nomeFile);
    char scelta;
    bool cont=false;
    char candidato[COGNOME_MAX];
    cout<<"Voti espressi: "<<somma_vettore(grigliaVoti,N_COLLEGI)<<endl;
    do {
        cout <<endl<<"Inserisci il nome del candidato:"<<endl;
        cin >> candidato;
        stampa_candidato(candidato);
        cout<<"Vuoi continuare? [s/n]:";
        cin>>scelta;
        switch(scelta){
            case 's': case 'S':
                cont=true;
                break;

            case 'n':  case 'N':
                cont=false;
                break;

            default:
                cout<<"Usa solo caratteri consentiti!"<<endl;
                cont= true;
                break;
        }
    }while(cont);
// PUNTI 3
}
