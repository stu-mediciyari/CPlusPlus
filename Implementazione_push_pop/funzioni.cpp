#include <iostream>

// Permettiamo alla funzione di modificare dove punta il puntatore originale.
// *&numeri è un riferimento ad un puntatore.
// La variabile "numeri" dentro questa funzione non è una nuova variabile che contiene una copia dell'indirizzo.
// "numeri" è la variabile "v" del main, solo con un nome diverso.
// *&numeri è un riferimento ad un puntatore --> si riferisce al puntatore *v nel main.
void push(const int valore, int *&numeri, int &dim) {

    // L'operatore new richiede un blocco di memoria contiguo che sia sufficientemente grande da ospitare
    // esattamente dim+1 numeri interi. Il compilatore utilizza "int" dopo l'istruzione new per calcolare
    // i byte necessari. Se un int occupa 4 byte e dim è 4 (quindi vogliamo 5 elementi), il sistema calcola
    // 5x4=20 byte totali contigui. A questo punto new restituisce l'indirizzo di memoria del primo byte del
    // primo elemento che viene salvato all'interno della variabile puntatore array_temp.
    int *array_temp = new int[dim+1];

    for (int i = 0; i < dim; i++) {
        // numeri[i] esegue in automatico un'operazione di dereferenziazione: numeri[i] = *(numeri+i).
        // Essendo "numeri" un alias per *v (dichiarata nel main) noi abbiamo a che fare con indirizzi di memoria.
        // La notazione numeri[i] estrae automaticamente il valore contenuto in posizione i (dereferenziazione) ed
        // esegue l'operazione inversa su array_temp[i].
        // L'istruzione seguente è equivalente a *(array_temp+i)=*(numeri+i).
        array_temp[i] = numeri[i];
    }

    array_temp[dim] = valore;

    // A differenza delle variabili nello Stack che svaniscono automaticamente quando la funzione termina,
    // un blocco nello Heap sopravvive indefinitamente finché non viene distrutto esplicitamente. Il punatore numeri
    // sta puntando al vecchio array (quello piccolo). Eseguendo delete[] numeri, stiamo dicendo al sistema di considerare
    // quel blocco di memoria come libero.
    delete[] numeri;
    dim++;

    // Dopo aver liberato lo spazio di memoria copiamo l'indirizzo del nuovo blocco dentro la variabile puntatore del
    // main.
    numeri = array_temp;

}

int pop(int *&numeri, int &dim) {

    // Controlliamo la dimensione del vettore.
    if (dim <= 0) {
        std::cout << "Dimensioni incorrette" << std::endl;
        return -1; // DA MODIFICARE
    }

    // Salviamo l'ultimo valore dell'array
    const int valore_finale = numeri[dim - 1];

    int *array_temp = new int[dim-1];

    for (int i = 0; i < dim-1; i++) {
        array_temp[i] = numeri[i];
    }

    delete[] numeri;
    dim--;

    numeri = array_temp;

    return valore_finale;
}

void inserisci_mezzo(const int valore, const int pos, int *&numeri, int &dim) {

    // controlliamo che la posizione inserita dall'utente esista nell'array
    if (pos < 0 || pos > dim) {
        std::cout << "Posizione non valida." << std::endl;
        return;
    }

    // creiamo un array di dimensione dim+1
    int *array_temp = new int[dim+1];

    for (int i = 0; i < pos; i++) {
        array_temp[i] = numeri[i];
    }

    // inseriamo il nuovo elemento nella posizione fornita dall'utente
    array_temp[pos] = valore;

    for (int i = pos; i < dim; i++) {
        array_temp[i+1] = numeri[i];
    }

    delete[] numeri;
    dim++;

    numeri = array_temp;
}

void stampa_array(const int *numeri, const int dim) {
    std::cout << "Gli elementi dell'array sono: ";
    for (int i = 0; i < dim; i++) {
        std::cout << numeri[i] << " ";
    }
    std::cout << std::endl;
}

void menu(int *&v, int &dim) {
    int scelta;

    do {
        std::cout << "\n-----------------------------------" << std::endl;
        std::cout << "      GESTIONE ARRAY DINAMICO      " << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "1. Inserisci un elemento (Push)" << std::endl;
        std::cout << "2. Rimuovi l'ultimo elemento (Pop)" << std::endl;
        std::cout << "3. Inserisci un elemento in una posizione specifica" << std::endl;
        std::cout << "4. Visualizza array corrente" << std::endl;
        std::cout << "0. Esci" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Scelta: ";

        std::cin >> scelta;

        switch (scelta) {
            case 1: {
                int valore;
                std::cout << "Inserisci il numero da aggiungere: ";
                std::cin >> valore;
                push(valore, v, dim);
                std::cout << "-> Elemento " << valore << " aggiunto con successo." << std::endl;
                break;
            }
            case 2: {
                if (dim > 0) {
                    int rimosso = pop(v, dim);
                    std::cout << "-> Elemento rimosso: " << rimosso << std::endl;
                } else {
                    std::cout << "-> Errore: L'array e' gia' vuoto." << std::endl;
                }
                break;
            }
            case 3: {
                int valore;
                int posizione;
                std::cout << "Inserisci il numero da aggiungere: ";
                std::cin >> valore;

                std::cout << "Inserisci la posizione in cui aggiungere l'elemento: ";
                std::cin >> posizione;

                inserisci_mezzo(valore, posizione, v, dim);
                std::cout << "-> Elemento " << valore << " in posizione " << posizione << " aggiunto con successo." << std::endl;
                break;
            }
            case 4: {
                stampa_array(v, dim);
                break;
            }
            case 0:
                std::cout << "Uscita dal programma..." << std::endl;
                break;
            default:
                std::cout << "Scelta non valida, riprova." << std::endl;
                break;
        }

    } while (scelta != 0);
}