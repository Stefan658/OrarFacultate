#include "Semigrupa.h"


Semigrupa::Semigrupa() : nume(""), specializare(""), nrAnului(0) {}

Semigrupa::Semigrupa(string specializare, int nrAnului, string nume)
    : specializare(specializare), nrAnului(nrAnului), nume(nume) {

}

/*string Semigrupa::setSpecializare(const string& specializare)
{
    this->specializare = specializare;
    return this->specializare;
}

int Semigrupa::setNrAnului(int nrAnului)
{
    this->nrAnului = nrAnului;
    return this->nrAnului;
}*/

bool Semigrupa::validareNume() {
    if (nume == "1a" || nume == "1b")
        return true;
    else if (nume == "2a" || nume == "2b" || nume == "3a" || nume == "3b")
        return true;
    else if (nume == "1a" || nume == "1b")
        return true;
    else if (nume == "2a" || nume == "2b" || nume == "3a" || nume == "3b")
        return true;
    else
        return true;
}

string Semigrupa::transmitereNumeFisier() {
    string numeFisier;

    if (specializare == "C" || specializare == "c" ) {
        if (nume == "1a")
            numeFisier = "Calc_1_g1.txt";
        else if (nume == "1b")
            numeFisier = "Calc_1_g2.txt";
        else if (nume == "2a")
            numeFisier = "Calc_2_g1.txt";
        else if (nume == "2b")
            numeFisier = "Calc_2_g2.txt";
        else if (nume == "3a")
            numeFisier = "Calc_3_g1.txt";
        else if (nume == "3b")
            numeFisier = "Calc_3_g2.txt";

    }
     if (specializare == "SE" || specializare == "se") {
             if (nume == "1a")
            numeFisier = "SE_1_gr1.txt";
        else if (nume == "1b")
            numeFisier = "SE_1_gr2.txt";
        else if (nume == "2a")
            numeFisier = "SE_2_gr1.txt";
        else if (nume == "2b")
            numeFisier = "SE_2_gr2.txt";
        else if (nume == "3a")
            numeFisier = "SE_3_gr1.txt";
        else if (nume == "3b")
            numeFisier = "SE_3_gr2.txt";
    }

    return numeFisier;
}
