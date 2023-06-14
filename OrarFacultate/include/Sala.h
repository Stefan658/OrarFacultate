#ifndef SALA_H
#define SALA_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include "Tabel.h"

using namespace std;

class Sala {
private:
    string nume;
    vector<string> numeFisiere;

public:
    Sala(const string& nume, const vector<string>& fisiere);

    void afisareNumeFisiere();
    void cautaNume(const string& textCautat);
};

#endif // SALA_H
