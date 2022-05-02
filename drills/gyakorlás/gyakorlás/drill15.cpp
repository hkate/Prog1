#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

class Person
{
private:
    string fn;
    string sn;
    int a;

public:
    Person() {}             //üres konstruktor
    Person(string first_name, string second_name, int age) : fn(first_name), sn(second_name), a(age)    //itt hívom meg a konstruktort, (paraméterek) : szintakszis
    {
        // age check
        if (a < 0 || a > 150)
            throw runtime_error("invalid age");

        // name check
        string invalid[] = {";", ":", "\"", "\'", "[", "]", "*", "&", "^", "%", "$", "@", "!"};     //tömb létrehozása
        for (int i = 0; i < 13; i++)
        {
            if (fn.find(invalid[i]) != string::npos || sn.find(invalid[i]) != string::npos)     //npos = indicate no matches, fn 
                throw runtime_error("invalid name");
        }
    };
    string first_name() const { return fn; }        //annyit csinál hogy visszaadja az fn privát változónkat
    string second_name() const { return sn; }       //gettelés (nem akarjuk h a classon belül a privát változónk felül írják), const miatt nme módosíthat a classon belüli változón, cvsak kiolvashatja
    int age() const { return a; }       //visszaadja az 'a' privát változónkat
};

//jön két operátor overload

ostream &operator<<(ostream &os, const Person &p)                                   //ostream csak elmenti egy külön helyre (mint pipe)
{
    return os << p.first_name() << " " << p.second_name() << " " << p.age();
}

istream &operator>>(istream &is, Person &p)                //bekérek 2 nevet meg egy életkort
{
    string first_name;
    string second_name;
    int age;
    is >> first_name >> second_name >> age;
    p = Person(first_name, second_name, age);       //konstructor a Person classnak, definiálom a p-t
    return is;          //visszaadjuk az input streamet
}

int main()
{
    Person p = Person("Goofy", "Goo", 63);
    cout << p.first_name() << " " << p.second_name() << " " << p.age() << endl;
    cout << p << endl;
    Person p2;
    cin >> p2;
    cout << p2 << endl;

    vector<Person> vec;
    for (Person p; cin >> p;)
    {
        if (p.first_name() == "end")        //speciális esetek adok meg
            break;
        vec.push_back(p);
    }

    for (auto person : vec)     //írassuk ki az egészet még1x, inhersed for loop? // for(Person person : vec) is lehetne
    {
        cout << person << endl;     // ugyan az mint az előző csak más megoldással, megadtunk egy változót : meg hogy min fusson végig
    }
}