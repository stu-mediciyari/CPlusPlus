#include <iostream>

void push(const int valore, int *&numeri, int &dim) {

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

void stampa_array(const int *numeri, const int dim) {
    std::cout << "Gli elementi dell'array sono: ";
    for (int i = 0; i < dim; i++) {
        std::cout << numeri[i] << " ";
    }
    std::cout << std::endl;
}

void funzione_inserisci(int dim = 0) {}