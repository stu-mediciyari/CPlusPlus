#include <iostream>

void push(const int valore, int *&numeri, int &dim) {

    // creiamo un nuovo array di dimensione dim+1
    int *array_temp = new int[dim+1];

    for (int i = 0; i < dim; i++) {
        array_temp[i] = numeri[i];
    }

    array_temp[dim] = valore;

    delete[] numeri;
    dim++;

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