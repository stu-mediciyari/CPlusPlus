#pragma once

void push(int valore, int *&numeri, int &dim);
int pop(int *&numeri, int &dim);

void inserisci_mezzo(int valore, int pos, int *&numeri, int &dim);

void stampa_array(const int *numeri, int dim);
void menu(int *&v, int &dim);