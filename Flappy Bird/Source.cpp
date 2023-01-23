#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;

int main() {
    srand(time(NULL));
    char mv, repeta = 'y';
    int i, j;
    int scor = 0, record = 0;
    while (repeta == 'y') {
        bool viata = true;
        int x = 9;
        int inaltime[3];
        int lungime[3];
        lungime[0] = 10;
        lungime[1] = 18;
        lungime[2] = 27;
        for (i = 0; i < 3; i++) {
            inaltime[i] = (rand() - 1) % 12 + 2;
        }
        //crearea mapei 
        string map[20][30];
        for (i = 0; i < 20; i++) {
            for (j = 0; j < 30; j++) {
                if (i == 0 || i == 19 || j == 0 || j == 29) {  //borderline-uri
                    map[i][j] = "* ";
                }
                else {
                    map[i][j] = "  ";
                }
            }
        }
        while (viata == true) {
            for (i = 0; i < 3; i++) {
                for (j = 1; j < 19; j++) {
                    map[j][lungime[i]] = "  ";
                }
            }
            for (i = 0; i < 3; i++) {
                lungime[i]--;
            }
            for (i = 0; i < 3; i++) {
                for (j = 1; j < 19; j++) {
                    map[j][lungime[i]] = "| ";
                }
            }
            for (i = 0; i < 3; i++) {
                map[inaltime[i]][lungime[i]] = "  ";
                map[inaltime[i] + 1][lungime[i]] = "  ";
                map[inaltime[i] + 2][lungime[i]] = "  ";
                map[inaltime[i] + 3][lungime[i]] = "  ";
                map[inaltime[i] + 4][lungime[i]] = "  ";
            }
            for (i = 0; i < 3; i++) {
                if (lungime[i] == 1)
                {
                    lungime[i] = 28;
                    inaltime[i] = (rand() - 1) % 12 + 2;
                }
            }
            map[x][3] = "  ";
            // cu functiile _kbhit si _getch avem ca input-uri tastele de la tastatura ce vor controla pasarea noastra
            if (_kbhit()) {
                mv = _getch();
                x -= 3;
            }
            x++;
            if (x < 1) {
                x = 1;
            }
            for (i = 0; i < 3; i++) {
                if (lungime[i] == 3) {
                    if (map[x][3] == "  ") {
                        scor++;
                    }
                }
                //conditii de oprire a jocului: daca atinge obstacolele, adica border-urile
                if (map[x][3] == "| ") {
                    viata = false;
                }
                if (map[x - 1][3] == "* " || map[x + 1][3] == "* ") {
                    viata = false;
                }
            }
            map[x][3] = "$ ";  //simbolizeaza "pasarea"
            for (i = 1; i < 19; i++) {
                map[i][1] = "  ";
            }
            for (i = 0; i < 20; i++) {
                for (j = 0; j < 30; j++) {
                    cout << map[i][j];
                }
                cout << "\n";
            }
            cout << "scor = " << scor;
            Sleep(100);
            system("cls");  //"clear the screen"
        }
        cout << "scor = " << scor << "\n";
        if (record < scor) {
            record = scor;
        }
        cout << "record = " << record << "\n";
        cout << "Reincearca(y/n) = ";
        scor = 0;
        cin >> repeta;
        if (repeta == 'n') {
            cout << "Joc incheiat\n" << "Scor record: " << record << "\nFelicitari!\n";
        }
    }
    return 0;
}

