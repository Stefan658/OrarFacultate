#ifndef SEMIGRUPA_H
#define SEMIGRUPA_H

#include <iostream>
#include <string>

using namespace std;

class Semigrupa {
public:
    string nume;
    string specializare;
    int nrAnului;

   Semigrupa();
    Semigrupa(string specializare, int nrAnului, string nume);
    bool validareNume();
    string transmitereNumeFisier();
};

#endif // SEMIGRUPA_H
