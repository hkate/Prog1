#include <string>
#include <iostream>

using namespace std;

class B1 {
    public:
        virtual void vf() {cout << "B1::vf()\n";}
        void f() {cout << "B1::f()\n";}     //mitől nem felül írható? -> ha referenciát csinálok megmarad az értéke
        virtual void pvf() = 0;
};

class D1 : public B1{
    public:
        virtual void vf() {cout << "D1::vf()\n";}
        void f() {cout << "D1::f()\n";}
};

class D2 : public D1{
    public:
        void pvf() {cout << "D2::pvf()\n";}

};

class B2 {
    public:
        virtual void pvf() = 0;
};

class D21 : public B2 {
    public:
    void pvf() {cout << s << endl;}
    string s;
};

class D22 : public B2 {
    public:
    void pvf() {cout << n << endl;}
    int n;
};

void f(B2& b2ref){
    b2ref.pvf();
};

int main() {

/*
    B1 b1;      //create an object
    b1.vf();    //meghívni a class függvényeit
    b1.f();

    D1 d1;
    d1.vf();
    d1.f();

    B1& bref = d1;       //referenciát hozok létre, mivel d1 leszármazottja b1-nek, referenciánál a vf() mivel felülírható felülíródik, f() nem
    bref.f();
    bref.vf();
*/

    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();

    D21 d21;
    d21.s = "d21.s";
    d21.pvf();

    D22 d22;
    d22.n = 22;
    d22.pvf();

    f(d21);
    f(d22);

}
