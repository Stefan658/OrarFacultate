#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>
#include <algorithm>
#include <cctype>


#include "Tabel.h"
#include "Semigrupa.h"
#include "Sala.h"

using namespace std;


int GetZiua(string ziua)
{
    if (ziua == "Luni")
        return 1;
    if (ziua == "Marti")
        return 2;
    if (ziua == "Miercuri")
        return 3;
    if (ziua == "Joi")
        return 4;
    if (ziua == "Vineri")
        return 5;

}
int GetOra(int ora)
{
    if (ora == 8)
        return 2;
    if (ora == 9)
        return 3;
    if (ora == 10)
        return 4;
    if (ora == 11)
        return 5;
    if (ora == 12)
        return 6;
    if (ora == 13)
        return 7;
    if (ora == 14)
        return 8;
    if (ora == 15)
        return 9;
    if (ora == 16)
        return 10;
    if (ora == 17)
        return 11;
    if (ora == 18)
        return 12;
    if (ora == 19)
        return 13;

}

string seteazaFText(string specializare, int anStudiu, string numeSemigrupa)
{
    string numeFisier;
    for (char& c : specializare)
    {
        c = toupper(c);
    }

    if (specializare == "C" && anStudiu == 1)
    {
        if (numeSemigrupa == "1a")
            numeFisier = "Calc_1_g1.txt";
        else if (numeSemigrupa == "1b")
            numeFisier = "Calc_1_g2.txt";
    }
    else if (specializare == "C" && anStudiu == 2)
    {
        if (numeSemigrupa == "2a")
            numeFisier = "Calc_2_g1.txt";
        else if (numeSemigrupa == "2b")
            numeFisier = "Calc_2_g2.txt";
    }
    else if (specializare == "C" && anStudiu == 3)
    {
        if (numeSemigrupa == "3a")
            numeFisier = "Calc_3_g1.txt";
        else if (numeSemigrupa == "3b")
            numeFisier = "Calc_3_g2.txt";
    }
    else if (specializare == "SE" && anStudiu == 1)
    {
        if (numeSemigrupa == "1a")
            numeFisier = "SE_1_gr1.txt";
        else if (numeSemigrupa == "1b")
            numeFisier = "SE_1_gr2.txt";
    }
    else if (specializare == "SE" && anStudiu == 2)
    {
        if (numeSemigrupa == "2a")
            numeFisier = "SE_2_gr1.txt";
        else if (numeSemigrupa == "2b")
            numeFisier = "SE_2_gr2.txt";
    }
    else if (specializare == "SE" && anStudiu == 3)
    {
        if (numeSemigrupa == "3a")
            numeFisier = "SE_3_gr1.txt";
        else if (numeSemigrupa == "3b")
            numeFisier = "SE_3_gr2s.txt";
    }
   return numeFisier;
}

string completeazaInfo(const string& disciplina, const string& sala, char tipActivitate)
{

    string disciplinaMare = disciplina;
    transform(disciplinaMare.begin(), disciplinaMare.end(), disciplinaMare.begin(), ::toupper);
    string tipActivitateMare(1, toupper(tipActivitate));

    stringstream ss;
    ss << "(" << sala << ")";
    string salaInParanteze = ss.str();

    string result = disciplinaMare + " " + salaInParanteze + " " + tipActivitateMare;
    return result;
}

void completeazaTabelCuCuvant(const string& numeFisier, int i, int j, Tabel& tabel, const string& info)
{
    ifstream file(numeFisier);
    if (!file.is_open())
    {
        cout << "Eroare la deschiderea fisierului!" << endl;
        return;
    }
    vector<vector<string>> data;
    string line;
    while (getline(file, line))
    {
        vector<string> row;
        size_t startPos = 0;
        size_t endPos = line.find(';');
        while (endPos != string::npos)
        {
            string element = line.substr(startPos, endPos - startPos);
            row.push_back(element);
            startPos = endPos + 1;
            endPos = line.find(';', startPos);
        }
        data.push_back(row);
    }
    file.close();
    vector<vector<string>> tabelData = tabel.getTabel();  // Copie a tabelului
    for (size_t row = 0; row < tabelData.size(); ++row)
    {
        for (size_t col = 0; col < tabelData[row].size(); ++col)
        {
            if (row == static_cast<size_t>(i) && col == static_cast<size_t>(j))
            {
                if (tabelData[row][col].find('(') == string::npos)
                {
                    tabelData[row][col] = info;
                }
            }
        }
    }

    ofstream outFile(numeFisier);
    if (!outFile.is_open())
    {
        cout << "Eroare la deschiderea fisierului de iesire!" << endl;
        return;
    }

    for (const auto& row : tabelData)
    {
        for (size_t col = 0; col < row.size(); ++col)
        {
            outFile << row[col];
            if (col != row.size() - 1)
            {
                outFile << ";";
            }
        }
        outFile << endl;
    }

    outFile.close();
}




int main()
{

    vector<vector<string>> data(14, vector<string>(6, ""));
    vector<vector<string>> dataa(12, vector<string>(5, ""));



    vector<string> numeFisiere =
    {
        "Calc_1_g1.txt",
        "Calc_1_g2.txt",
        "Calc_2_g1.txt",
        "Calc_2_g2.txt",
        "Calc_3_g1.txt",
        "Calc_3_g2.txt",
        "SE_1_gr1.txt",
        "SE_1_gr2.txt",
        "SE_2_gr1.txt",
        "SE_2_gr2.txt",
        "SE_3_gr1.txt",
        "SE_3_gr2.txt"
    };


    Tabel tabel(data);
    tabel.completeazaTitluri();

    Sala sala("Nume sala", numeFisiere);


    Semigrupa semigrupa;
    string numeSemigrupa;
    string specializare;
    string textCautat;

    string pass;
    char ch;
    string spc;
    int anDeStudiu;
    string numeSemig;
    string discip;
    string salaa;
    char tipAct;
    string ziua;
    int IndexOra;
    int oreAct;
    int IndexZiua;
    int ora;
    int anStudiu;
    string numeFisier;
    string infos;
    Tabel tabell(dataa);
    Tabel table_one(data);



    int optiune;
    while (true)
    {
        cout << "\nMeniu:" << endl;
        cout << "1. Alege specializarea, anul si semigrupa" << endl;
        cout << "2. Alege sala" << endl;
        cout << "3. Modifica orar (Admin Only)" << endl;
        cout << "4. Exit" << endl;
        cout << "Introduceti optiunea dorita: ";
        cin >> optiune;

        switch (optiune)
        {
        case 1:
            cout << "Alege specializarea (Calculatoare - C sau Sisteme Electrice - SE): ";
            cin >> specializare;
            cout << "Alege anul de studiu(1,2,3): ";
            cin >> anStudiu;
            cout << "Alege semigrupa(ex: pt. anul 1 - 1a, 1b): ";
            cin.ignore();
            getline(cin, numeSemigrupa);

            if(anStudiu == 1)
                while   (numeSemigrupa != "1a" && numeSemigrupa != "1b")
                {
                    cout<<"Semigrupa ("<<numeSemigrupa<<") nu este alesa corect. Introdu din nou numele semigrupei: ";
                    getline(cin, numeSemigrupa);
                }
            if(anStudiu == 2)
                while   (numeSemigrupa != "2a" && numeSemigrupa != "2b")
                {
                    cout<<"Semigrupa ("<<numeSemigrupa<<") nu este alesa corect. Introdu din nou numele semigrupei: ";
                    getline(cin, numeSemigrupa);
                }
            if(anStudiu == 3)
                while   (numeSemigrupa != "3a" && numeSemigrupa != "3b")
                {
                    cout<<"Semigrupa ("<<numeSemigrupa<<") nu este alesa corect. Introdu din nou numele semigrupei: ";
                    getline(cin, numeSemigrupa);
                }
            semigrupa = Semigrupa(specializare,anStudiu,numeSemigrupa);

            if (semigrupa.specializare == "C"  || semigrupa.specializare == "c")
                cout<<endl<<"\nCALCULATOARE  "<<"Anul "<<anStudiu<<"    Semigrupa "<<numeSemigrupa;
            if (semigrupa.specializare == "SE"  || semigrupa.specializare == "se")
                cout<<endl<<"\nSISTEME ELECTRICE  "<<"Anul "<<anStudiu<<"    Semigrupa "<<numeSemigrupa;

            if (semigrupa.validareNume())
            {
                tabel.completeazaTabelCuInfo(semigrupa.transmitereNumeFisier());
                tabel.Ident();
                cout << endl;
                cout<< " "<<endl;
                tabel.afiseazaTabel();
            }
            else
            {
                cout << "Numele semigrupei este incorect!" << endl;
            }

            break;
        case 2:
            cout << " Alege sala (ex: Aula, Amf RR, Amf NB): ";


            cin.ignore();
            getline(cin, textCautat);
            cout<<endl;
            if(textCautat == "Aula")
            {
                cout<<"\n\nAULA MAGNA"<<endl;
                cout<<"-----------"<<endl;
                sala.cautaNume(textCautat);
                cout<<endl;
            }
            else if(textCautat == "Amf RR")
            {
                cout<<"\n\nAmfiteatrul REMUS RADULET"<<endl;
                cout<<"-------------------------"<<endl;
                sala.cautaNume(textCautat);
                cout<<endl;
            }
            else if(textCautat == "Amf NB")
            {
                cout<<"\n\nAmfiteatrul NICOLAE BOTAN"<<endl;
                cout<<"-------------------------"<<endl;
                sala.cautaNume(textCautat);
                cout<<endl;
            }
            else
            {
                cout<<"\n\n"<<textCautat<<endl;
                for (int i =1; i<=textCautat.length(); i++)
                {
                    cout<<"-";
                }
                cout<<endl;
                sala.cautaNume(textCautat);
                cout<<endl;
            }

            break;
        case 3:
            cout << "Pass: ";

            while ((ch = _getch()) != '\r')
            {
                if (ch == '\b')
                {
                    if (!pass.empty())
                    {
                        pass.pop_back();
                        cout << "\b \b";
                    }
                }
                else
                {
                    pass.push_back(ch);
                    cout << "*";
                }
            }


            if ( pass == "1234")
            {
                cout << "\nAlege specializarea (ex. Calculatoare - C sau Sisteme Electrice - SE): ";
                cin >> spc;

                cout << "Alege anul de studiu(ex. 1,2,3): ";
                cin >> anDeStudiu;

                cout << "Alege semigrupa(ex: pt.anul 1 - 1a,1b): ";
                cin.ignore();
                getline(cin, numeSemig);

                cout << "Alege disciplina: ";
                cin.ignore();
                getline(cin, discip);

                cout << "Alege sala: ";
                cin.ignore();
                getline(cin, salaa);

                cout << "Alege tipul activitatii (curs - C, seminar - S sau laborator - L): ";
                cin>>tipAct;

                cout << "Alege ziua si ora in care planifici activitatea: ";
                cout << "\nZiua: ";
                cin.ignore();
                getline(cin, ziua);

                cout << "Ora: ";
                cin>> ora;

                cout << "Cate ore dureaza activitatea: ";
                cin>>oreAct;

                IndexZiua = GetZiua(ziua) ;
                IndexOra = GetOra(ora);

                numeFisier = seteazaFText(spc, anDeStudiu, numeSemig);
                infos = completeazaInfo(discip,salaa,tipAct);
                completeazaTabelCuCuvant(numeFisier, IndexOra, IndexZiua, tabell, infos);

                table_one.completeazaTitluri();
                table_one.completeazaTabelCuInfo(semigrupa.transmitereNumeFisier());
                table_one.Ident();
                cout<<endl<<endl<<"ORAR MODIFICAT "<<"Anul "<<anDeStudiu<<" ,semigrupa "<<numeSemig<<endl;
                table_one.afiseazaTabel();

                break;

            case 4:
                return 0;

            default:
                cout << "Optiunea introdusa nu este valida." << endl;
                break;
            }

            cout << endl;
        }
    }

    return 0;
}
