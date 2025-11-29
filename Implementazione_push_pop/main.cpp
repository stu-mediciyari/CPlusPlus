#include <iostream>
#include <cstdio>

#include "funzioni.hpp"

int main() {

    int *v = NULL;
    int scelta;

    std::cout << "Premi 1 per inserire un elemento nel vettore." << std::endl;
    std::cout << "Premi 2 per rimuovere l'ultimo elemento del vettore." << std::endl;
    std::cout << std::endl;
    std::cout << "Scelta: ";

    std::cin >> scelta;

    if (scelta == 1) {
        int dim = 0;
        int temp_val;

        std::cout << "Inserisci un elemento oppure premi CTRL+D per terminare: ";

        while (std::cin >> temp_val) {
            push(temp_val, v, dim);

            std::cout << "Inserisci un altro elemento oppure premi CTRL+D per terminare: ";
        }

        std::cout << std::endl;
        std::cout << std::endl;
        stampa_array(v, dim);
    }


    return 0;
}