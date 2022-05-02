#include <string>
#include <iostream>

using namespace std;

class jarmu {
    public:
        virtual void kerekek() = 0;
        virtual void utasszam() = 0;
};

class autok : public jarmu {
    public:
        void kerekek() {cout << "ideális esetben 4, de lehet 8(?)" << endl;}
        void utasszam() {cout << "5 személy" << endl;} 
};

class kia : public autok {
    public:
        void kerekek() {cout << "4 kerék" << endl;}
        void utasszam() {cout << "5 személy" << endl;}
};

class kerekpar : public jarmu {
    public:
        void kerekek() {cout << "ideális esetben 2" << endl;}
        void utasszam() {cout << "1 személy, esetleg 2" << endl;} 
};

void meret(jarmu& jarmu){           //bicikli, teher autó stb.
    jarmu.kerekek();
}

void szallitas(jarmu& jarmu) {      //utas szállítás
    jarmu.utasszam();
}

int main() {

    autok teherauto;
    meret(teherauto);
    szallitas(teherauto);

    cout << endl;

    kia ceed;
    meret(ceed);
    szallitas(ceed);

    cout << endl;

    kerekpar bicikli;
    meret(bicikli);
    szallitas(bicikli);

    return 0;
}