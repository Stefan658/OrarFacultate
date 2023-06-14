#include "Sala.h"

Sala::Sala(const string& nume, const vector<string>& fisiere)
    : nume(nume), numeFisiere(fisiere)
{
}

void Sala::afisareNumeFisiere()
{
    cout << "Numele salii: " << nume << endl;
    cout << "Fisierele disponibile:" << endl;
    for (const string& numeFisier : numeFisiere)
    {
        cout << numeFisier << endl;
    }
}

void Sala::cautaNume(const string& textCautat)
{
    vector<vector<string>> data(14, vector<string>(6, ""));
    Tabel tabel(data);
    tabel.completeazaTitluri();
    regex regexText("\\((.*?)\\)");
    for (const string& numeFisier : numeFisiere)
    {
        ifstream fisier(numeFisier);
        if (fisier.is_open())
        {
            string linie;
            int numarLinie = 1;
            while (getline(fisier, linie))
            {
                stringstream ss(linie);
                string element;
                int numarElement = 1;
                while (getline(ss, element, ';'))
                {
                    smatch match;
                    if (regex_search(element, match, regexText))
                    {
                        string textParanteze = match[1].str();
                        if (textParanteze == textCautat)
                        {
                            tabel.completeazaTabelCuInfoSala(numarLinie, numarElement, element);}
                    }
                    numarElement++;}
                numarLinie++;}
            fisier.close();}
    }
    tabel.Ident();
    tabel.bracket();
    tabel.afiseazaTabel();
    cout << endl;
}
