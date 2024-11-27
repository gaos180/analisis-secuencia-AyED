#include <iostream>
#include <cstdlib>
// .h para añadir modulación con los otros archivos cpp

#include "needleman_wunsch.h"
#include "utils.h"

using namespace std;

/*
Compilación:

g++ -o main.exe main.cpp needleman_wunsch.cpp utils.cpp

Ya que se deben de compilar todos juntos, le puse .exe al ejecutable para ver si se puede usar como tal
Uso:

./main.exe -C1 <cadena1.txt> -C2 <cadena2.txt> -FunU <matriz.txt> -V <penalidad>

la cadena de texto puede ser otro tipo de texto. -FunU es la matriz que se utiliza para hacer el alineamiento
Penalidad es lo que penan los gaps

Cosas que faltan: 
que sirva para archivos .fasta/fna
que muestre el puntaje de la secuencia más alta del alineamiento (score)
se ve horrible el dot, cambiarlo para poder hacer la secuencia como se ve adecuadamente
interfaz
extra de alineamiento

Nota general, tengo algunos test para comprobar donde es que me fallaba

*/


void show_usage() {
    cout << "Uso: ./main.exe -C1 <cadena1.txt> -C2 <cadena2.txt> -FunU <matriz.txt> -V <penalidad>" << endl;
    cout << "La penalidad de needleman usualmente es de 0.5, con ese número generará un reporte similar" << endl;
}

int main(int argc, char* argv[]) {
    // si no es la cantidad adecuada, pide que se muestre el como se usa
    if (argc != 9) {
        show_usage();
        return 1;
    }

    // Se hacen las variables de secuencia
    string seq1_file, seq2_file, matrix_file;
    int penalty = 0;

    for (int i = 1; i < argc; i += 2) {
        string arg = argv[i];
        if (arg == "-C1") seq1_file = argv[i + 1];
        else if (arg == "-C2") seq2_file = argv[i + 1];
        else if (arg == "-FunU") matrix_file = argv[i + 1];
        else if (arg == "-V") penalty = stoi(argv[i + 1]);
        else {
            show_usage();
            return 1;
        }
    }

    // leen los archivos según la ubicación
    string seq1 = read_sequence(seq1_file);
    string seq2 = read_sequence(seq2_file);

    int** matrix = read_matrix(matrix_file, 4); // ADN asumido: A, G, C, T, de ahi está hecha la matriz

    // para la similitud
    int totalScore = 0;
    double similarity = 0.0;

    string alignedS, alignedT;

    // Antes se veia directamente, ahora no, puse que se vea si quiere según del reporte desde terminal con bash

    // cout << "Test 1 seq1" <<endl;
    //cout << "Secuencia 1:\n" << seq1 << endl;
    // cout << "Test 1 seq2" <<endl;
    //cout << "Secuencia 2:\n" << seq2 << endl;
    needleman_wunsch(seq1, seq2, matrix, penalty, alignedS, alignedT, totalScore, similarity);

    //cout << "Secuencia 1 que será alineada con la secuencia 2:" << endl;
    //cout << seq1 << endl;
    //cout << "Secuencia del alineamiento óptimo:" << endl;
    //cout << alignedT << endl;
    //cout << "Secuencia 2 (con la que se alinea):" << endl;
    //cout << seq2 << endl;

    // Mostrar puntaje y similitud
    //cout << "Puntaje total (Score): " << totalScore << endl;
    //cout << "Porcentaje de Similitud: " << similarity << "%" << endl;
    write_report(seq1, seq2, alignedT, totalScore, similarity);


    // Crea archivo Graphviz
    generate_graphviz(alignedS, alignedT, "alignment.dot");

    // si mostrarlo o no
    int opc;
    cout << "¿Desea ver el reporte del alineamiento? \n[0] No\n[1] Si" << endl;
    cin >> opc;

    if(opc == 0);
    else if(opc == 1) system("cat temp/report.txt"); 

    cout << "En caso de que haya mensaje de \"dot: graph is too large for cairo-renderer bitmaps\" no se recomienda hacer grafico" << endl;
    cout << "¿Desea ver la imagen de graphviz? \n[0] No\n[1] Si" << endl;
    cin >> opc;
    
    if(opc == 0);
    else if(opc == 1) system("eog alignment.png"); 

    // Liberar a Pales... memoria
    free_matrix(matrix, 4);


    return 0;
}
