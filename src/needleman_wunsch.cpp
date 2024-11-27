#include "needleman_wunsch.h"
#include <iostream>
#include <fstream>

using namespace std;

// obtiene el indice del caracter, es para darle un número al caracter de adn
int get_index(char c) {
    switch (c) {
        case 'A': return 0;
        case 'T': return 1;
        case 'C': return 2;
        case 'G': return 3;
        // no tiene los 4 indicados
        default:
            cerr << "Error: Caracter no válido en la secuencia: " << c << endl;
            exit(1);
    }
}

// función principal de Needle
void needleman_wunsch(
    const string& S,
    const string& T,
    int** U,
    int V,
    string& alignedS,
    string& alignedT,
    int& totalScore,
    double& similarity
) {
    // cout << "Test 2 n" <<endl;

    int n = S.size();
    //cout << n << endl;
    // cout << "Test 2 m" <<endl;
    int m = T.size();
    //cout << m << endl;

    // Crear matriz de puntaje dinámicamente
    
    int** f = new int*[n + 1];
    
    for (int i = 0; i <= n; ++i) {
        f[i] = new int[m + 1];
        if (!f[i]) {
            cerr << "Error: No se pudo asignar memoria para la matriz f." << endl;
            exit(1);
        }
    }

    // Inicialización en un for que tiene pocas cosas que hacer así que lo hace rápido
    for (int i = 0; i <= n; ++i) f[i][0] = i * V;
    for (int j = 0; j <= m; ++j) f[0][j] = j * V;

    cout << "Test 3" <<endl;

    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // Validar caracteres y calcular índices
            int indexS = get_index(S[i - 1]);
            int indexT = get_index(T[j - 1]);

            // Calcular los puntajes
            int match = f[i - 1][j - 1] + U[indexS][indexT];
            int deleteS = f[i - 1][j] + V;
            int deleteT = f[i][j - 1] + V;

            // Asignar el valor máximo manualmente
            if (match >= deleteS && match >= deleteT) {
                f[i][j] = match;
            } else if (deleteS >= match && deleteS >= deleteT) {
                f[i][j] = deleteS;
            } else {
                f[i][j] = deleteT;
            }
        }
    }

    totalScore = f[n][m];


    // Reconstrucción
    alignedS = "";
    alignedT = "";
    int i = n, j = m;
    int matches = 0; // contador de emparejamientos
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0) {
            int indexS = get_index(S[i - 1]);
            int indexT = get_index(T[j - 1]);
            if (f[i][j] == f[i - 1][j - 1] + U[indexS][indexT]) {
                alignedS = S[i - 1] + alignedS;
                alignedT = T[j - 1] + alignedT;
                // si son iguales se hace el match en tinder -> secuencia
                if (S[i - 1] == T[j - 1]) matches++;
                --i; --j;
                continue;
            }
        }
        if (i > 0 && f[i][j] == f[i - 1][j] + V) {
            alignedS = S[i - 1] + alignedS;
            alignedT = '-' + alignedT;
            --i;
        } else if (j > 0) {
            alignedS = '-' + alignedS;
            alignedT = T[j - 1] + alignedT;
            --j;
        }
    }

    int alignmentLength = alignedS.size();
    similarity = (static_cast<double>(matches) / alignmentLength) * 100.0;

    // Liberar memoria
    for (int i = 0; i <= n; ++i) delete[] f[i];
    delete[] f;
}

void generate_graphviz(const string& alignedS, const string& alignedT, const string& output_file) {
    int cont = 0;
    ofstream file(output_file);
    file << "digraph Alignment {\n";
    for (size_t i = 0; i < alignedS.size(); ++i) {
        file << "    \"" << alignedS[i] << cont << "\" -> \"" << alignedT[i] << cont+1 << "\";\n";
        cont ++;
    }
    file << "}\n";
    file.close();
    system("dot -Tpng alignment.dot -o alignment.png");
}
