#include "utils.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Lee el archivo

string read_sequence(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        exit(1);
    }

    string sequence;
    string line;

    // lee el archivo línea por línea
    while (getline(file, line)) {
        // ignorar líneas que empiezan con '>' permitiendo leer archivos fasta
        if (!line.empty() && line[0] == '>') {
            continue;
        }

        // Agregar la línea a la secuencia, eliminando '\n' automáticamente
        sequence += line;
    }

    file.close(); // Cerrar el archivo
    return sequence;
}


// Lee la matriz
int** read_matrix(const string& filename, int size) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        exit(1);
    }

    int** matrix = new int*[size];
    for (int i = 0; i < size; ++i) matrix[i] = new int[size];

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix[i][j];
        }
    }
    return matrix;
}
void write_report(const string& seq1, const string& seq2, const string& seqAlignment, int totalScore, double similarity ){
    
    // Abrimos el archivo en modo escritura
    ofstream file("temp/report.txt");
    string content = "Reporte de la secuencia";
    if (file.is_open()) {
        file << content << endl;
        file << content << endl;
        file << "Puntaje total (Score): " << totalScore << endl;
        file << "Porcentaje de Similitud: " << similarity << "%" << endl;
        file << "------------------------------------"<< endl;
        file << "Secuencia número 1:\n" << seq1 << endl;
        file << "------------------------------------"<< endl;
        file << "Secuencia número 2:\n" << seq2 << endl;

        file << "------------------------------------"<< endl;
        file << "Secuencia alineada:\n" << seqAlignment << endl;
        
        file.close();
        cout << "Reporte creado exitosamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }


}

// libera espacio eliminando la matriz
void free_matrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) delete[] matrix[i];
    delete[] matrix;
}
