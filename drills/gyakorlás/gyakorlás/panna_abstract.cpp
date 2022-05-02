#include <iostream>
#include <string>

using namespace std;

class allat
{
public:
    virtual void jaras()=0;
    virtual void eves()=0;
};

class kutya : public allat
{
public:
    void jaras(){
        cout << "hasra esett :D" << endl;
    }
    void eves(){
        cout << "mint egy malac..." << endl;
    }
};

class macska : public allat
{
public:
    void jaras(){
        cout << "ugrál össze-vissza" << endl;
    }
    void eves(){}
};

class bengali : public macska
{
public:
    void jaras(){
        cout << "ugrál össze-vissza" << endl;
    }
    void eves() override {
        cout << "csámcsog" << endl;
    }
};

void setaltatas(allat &allat){
    allat.jaras();
}

void etetes(allat &allat){
    allat.eves();
}

int main(){
    kutya buksi;
    setaltatas(buksi);
    etetes(buksi);
    macska cirmi;
    setaltatas(cirmi);
    bengali smaragd;
    setaltatas(smaragd);
    etetes(smaragd);
}