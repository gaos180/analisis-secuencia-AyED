#ifndef NEEDLEMAN_WUNSCH_H
#define NEEDLEMAN_WUNSCH_H

#include <string>

using namespace std;

void needleman_wunsch(
    const string& S,
    const string& T,
    int** U,
    int V,
    string& alignedS,
    string& alignedT,
    int& totalScore,
    double& similarity
);

void generate_graphviz(
    const string& alignedS,
    const string& alignedT,
    const string& output_file
);

#endif
