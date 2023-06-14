#ifndef TABEL_H
#define TABEL_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Tabel {
public:
    Tabel(const vector<vector<string>>& data) : tabel(data){}
    void afiseazaTabel();
    void completeazaTitluri() ;
    void completeazaTabelCuInfo(const string& fileName) ;
    void completeazaTabelCuInfoSala(size_t numarLinie, size_t numarElement, const std::string& element);
    const vector<vector<string>>& getTabel() const;

    void bracket();
    void Ident() ;


private:
    vector<vector<string>> tabel;
};

#endif // TABEL_H
