#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

string read_sequence(const string& filename);
int** read_matrix(const string& filename, int size);
void free_matrix(int** matrix, int size);
void write_report(const string& seq1, const string& seq2, const string& seqAlignment, int totalScore, double similarity );

#endif 
