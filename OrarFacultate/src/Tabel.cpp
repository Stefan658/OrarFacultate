#include "Tabel.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;



//Tabel::Tabel(const vector<vector<string>>& data) : tabel(data) {}

void Tabel::afiseazaTabel() {
    for (size_t i = 0; i < tabel.size(); ++i) {
        for (size_t j = 0; j < tabel[i].size(); ++j) {
            cout << tabel[i][j] << "\t";
        }
        cout << endl;
    }
}

void Tabel::completeazaTitluri() {
    tabel[0][0] = "Interval orar      |";
    tabel[0][1] = "Luni               |";
    tabel[0][2] = "Marti              |";
    tabel[0][3] = "Miercuri           |";
    tabel[0][4] = "Joi                |";
    tabel[0][5] = "Vineri             |";

    tabel[1][0] = "-----------------";
    tabel[1][1] = "-----------------";
    tabel[1][2] = "-----------------";
    tabel[1][3] = "-----------------";
    tabel[1][4] = "-----------------";
    tabel[1][5] = "-----------------";

    tabel[2][0] = " 08:00 - 09:00    ";
    tabel[3][0] = " 09:00 - 10:00    ";
    tabel[4][0] = " 10:00 - 11:00    ";
    tabel[5][0] = " 11:00 - 12:00    ";
    tabel[6][0] = " 12:00 - 13:00    ";
    tabel[7][0] = " 13:00 - 14:00    ";
    tabel[8][0] = " 14:00 - 15:00    ";
    tabel[9][0] = " 15:00 - 16:00    ";
    tabel[10][0] = " 16:00 - 17:00    ";
    tabel[11][0] = " 17:00 - 18:00    ";
    tabel[12][0] = " 18:00 - 19:00    ";
    tabel[13][0] = " 19:00 - 20:00    ";
}



void Tabel::completeazaTabelCuInfo(const string& fileName) {
    ifstream file(fileName);
    string line;
    size_t row = 2;
    while (getline(file, line)) {
        size_t startPos = 0;
        size_t endPos = line.find(';');
        size_t col = 1;
        while (endPos != string::npos) {
            string element = line.substr(startPos, endPos - startPos);
            tabel[row][col] = element;
            startPos = endPos + 1;
            endPos = line.find(';', startPos);
            col++;
        }
        row++;
    }
    file.close();
}


void Tabel::completeazaTabelCuInfoSala(size_t numarLinie, size_t numarElement, const std::string& element) {
    tabel[numarLinie+1][numarElement] = element;
}


void Tabel::bracket() {
    for (size_t i = 2; i < tabel.size(); ++i) {
        for (size_t j = 1; j < tabel[i].size(); ++j) {
            string& element = tabel[i][j];
            if (element.find('(') == string::npos) {
                element = "          -         ";
            }
        }
    }
}

void Tabel::Ident() {
    size_t maxDimensiune = tabel[0][5].length();
    for (size_t i = 1; i < tabel.size(); ++i) {
        for (size_t j = 1; j < tabel[i].size(); ++j) {
            string& element = tabel[i][j];
            if (element.find("AT") != string::npos) {
                size_t pozitieUltimCaracter = element.find_last_of(')');
                if (pozitieUltimCaracter == string::npos) {
                    pozitieUltimCaracter = element.length() - 1;
                }
                size_t dimensiuneCurenta = pozitieUltimCaracter + 1;
                size_t spatiiNecesare = maxDimensiune - dimensiuneCurenta;
                element.append(spatiiNecesare, ' ');
            } else {
                size_t dimensiuneCurenta = element.length();
                size_t spatiiNecesare = maxDimensiune - dimensiuneCurenta;
                element.append(spatiiNecesare, ' ');
            }
        }
    }
}

const vector<vector<string>>& Tabel::getTabel() const {
    return tabel;
}
