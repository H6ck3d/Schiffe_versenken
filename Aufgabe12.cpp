#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
#include <string>
using namespace std;

string Ship_symbol = "<>";
string no_hit_symbol = "XX";
string hit_symbol = "!!";
const int zeilen = 7;
const int spalten = 10;
char Letter = 'A';
int Points = 0;
int Bewegungen = 0;
string Feld[10][spalten]; //[Zeile][Spalte]

string create()
{
    for (int x = 0; x < zeilen; x++)
    {
        for (int y = 0; y < spalten; y++)
        {
            string input = Letter + to_string(y);
            Feld[x][y] = input;
        }
        Letter++;
    }
}

string show()
{
    system("cls");
    for (int x = 0; x < zeilen; x++)
    {
        for (int y = 0; y < spalten; y++)
        {
            cout << Feld[x][y] << " ";
        }
        cout << "\n";
    }
}

int Nummer()
{   
    srand(time(NULL));
    int zahl = 1;
    int Nummer = 0;
    for (int x = 0; x < zahl; x++)
    {   
        number:
        Nummer = rand();
        if (Nummer > 9)
        {
            x--;
        }
        else
        {
            return Nummer;
        }
    }
}

char Buchstabe()
{   
    srand(time(NULL));
    char Zeichen[7] = {'A','B','C','D','E','F','G'};
    int index = rand() % 7; // Generieren einer Zufallszahl zwischen 0 und 6
    return Zeichen[index]; // Rückgabe eines zufälligen Buchstabens aus dem Array
}

string create_ship()
{
    srand(time(NULL));
    int Anzahl = 4;
    int Zahlen[4];
    int Nummer = 0;
    for (int x = 0; x < 1; x++)
    {   
        number:
        Nummer = rand();
        if (Nummer > 9)
        {
            x--;
        }
        else
        {
            if (Nummer < 4)
            {
                for (int i = 0; i < Anzahl; i++)
                {
                    Zahlen[i] = Nummer;
                    Nummer++;
                }
            }
            else if (Nummer > 6)
            {
                for (int i = 0; i < Anzahl; i++)
                {
                    Zahlen[i] = Nummer;
                    Nummer--;
                }
            }
            else
            {
                for (int i = 0; i < Anzahl; i++)
                {
                    Zahlen[i] = Nummer;
                    Nummer++;
                }
        
            }
        }
    }/*
    for (int y = 0; y < Anzahl; y++)
    {
        cout << Zahlen[y] << " ";
    }
    cout << "\n"; */
    //cout << "Ship location: ";
    for (int m = 0; m < Anzahl; m++)
    {
        Feld[9][m] = Buchstabe() + to_string(Zahlen[m]);
        //cout << Feld[9][m] << " ";
    }
    //cout << "\n";
}

string show_ship()
{   
    Letter = 'A';
    //cout << "\n";
    for (int z = 0; z < 4; z++)
    {
        string Ship = Feld[9][z];
        //cout << "Ship_check:" << Ship << " ";
        for (int x = 0; x < zeilen; x++)
        {
            for (int y = 0; y < spalten; y++)
            {
                string Field = Letter + to_string(y);
                //cout << Field << " ";
                if (Ship == Field)
                {
                    Feld[x][y] = Ship_symbol;
                }
            }
            Letter++;
            //cout << "\n";
        }
        Letter = 'A';
    }
    //cout << "\n";
}

string move_player()
{
    int input_Number;
    string move_player;
    cout << "Bitte Feld (Bsp. F8) eingeben: ";
    cin >> move_player;

    // Konvertiere den Buchstaben in Kleinbuchstaben
    move_player[0] = tolower(move_player[0]);

    // Validiere die Spaltennummer
    if (!isdigit(move_player[1])) {
        cout << "Ungueltige Eingabe! Bitte geben Sie den Buchstaben A bis G gefolgt von einer Zahl zwischen 0 und 9 ein." << endl;
        return "1"; // Hier wird die Funktion beendet
    }
    input_Number = stoi(move_player.substr(1));
    if (move_player[0] != 'a' && move_player[0] != 'b' && move_player[0] != 'c' && move_player[0] != 'd' && move_player[0] != 'e' && move_player[0] != 'f' && move_player[0] != 'g')
    {
        cout << "Ungueltige Eingabe! Bitte geben Sie den Buchstaben A bis G gefolgt von einer Zahl zwischen 0 und 9 ein." << endl;
        return "1"; // Hier wird die Funktion beendet
    } 
    else if (input_Number < 0 || input_Number > 9)
    {
        cout << "Ungueltige Eingabe! Bitte geben Sie den Buchstaben A bis G gefolgt von einer Zahl zwischen 0 und 9 ein." << endl;
        return "1"; // Hier wird die Funktion beendet
    }
    else
    {
        move_player[0] = toupper(move_player[0]);
        Feld[8][0] = move_player[0];  // setze Zeile auf den ersten Buchstaben des Eingabestrings (in Großbuchstaben)
        Feld[8][1] = move_player.substr(1);     // setze Spalte auf den restlichen Teil des Eingabestrings (die Zahlenkomponente)
        //cout << "Zeile: " << Feld[8][0] << "\n";
        //cout << "Spalte: " << Feld[8][1] << "\n";
        Letter = 'A';
        //cout << "Feld: " <<move_player << "\n";
        for (int z = 0; z < 4; z++)
        {
            string Ship = Feld[9][z];
            //cout << "Ship_check:" << Ship << "\n";
            for (int x = 0; x < zeilen; x++)
            {
                for (int y = 0; y < spalten; y++)
                {
                    string Field = Letter + to_string(y);
                    //cout << "Aktuelles Prueffeld: " << Field << "\n";
                    if (Ship == move_player && Field == move_player)
                    {
                        Feld[x][y] = hit_symbol;
                        Points++;
                        Bewegungen++;
                        //cout << Points << "\n";
                        //cout << "Set Hit Field: " << "[" << x << "]" << "[" << y << "] to " << hit_symbol << "\n";
                        return "0";
                    }
                }
                Letter++;
                //cout << "\n";
            }
            Letter = 'A';
        }
        for (int z = 0; z < 4; z++)
        {
            string Ship = Feld[9][z];
            //cout << "Ship_check:" << Ship << "\n";
            for (int x = 0; x < zeilen; x++)
            {
                for (int y = 0; y < spalten; y++)
                {
                    string Field = Letter + to_string(y);
                    //cout << "Aktuelles Prueffeld: " << Field << "\n";
                    if (Field == move_player && Ship != move_player)
                    {
                        Feld[x][y] = no_hit_symbol;
                        Bewegungen++;
                        //cout << "Set no_hit Field: " << "[" << x << "]" << "[" << y << "] to " << no_hit_symbol << "\n";
                        return "0";
                    }
                }
                Letter++;
                //cout << "\n";
            }
            Letter = 'A';
        }
    return "0";
    }
}

string move()
{
    while (move_player() == "1")
    {
        //Wenn die Funktion 1 zurückgibt, rufen Sie die Funktion erneut auf
    }
}

int main()
{
    create();
    create_ship();
    show();
    while (Points < 4)
    {
        move();
        show();
    }
    if (Points > 3)
    {
        //cout << "You needed " << trys << "Trys to sink the Ship" << "\n";
        cout << "!!! You Win !!!"<< "\n" << " Ship was: ";
        for (int m = 0; m < 4; m++)
        {
            cout << Feld[9][m] << " ";
        }
    }
}