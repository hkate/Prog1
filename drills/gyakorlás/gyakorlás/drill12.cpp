#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

#include <string>
#include <iostream>
using namespace Graph_lib;

int main(){

    try{
        Point t1 {100, 100}; // kreálok egy kezdő pontot (a képernyőm valamelyik pontját kiválasztom bal felső sarokból számítva)

        Simple_window win {t1, 640, 640, "My window"}; //simple window gondolom beépített a GUI-ba 'win'-nek elnevezem (kezdőpont, szélesség, magasság, sáv neve)

        win.wait_for_bottom(); //melyik lépéstól várjon a kattintásig

        Axis xa {Axis::x, Point {20, 300}, 200, 10, "X axis"}; //elnevezem xa-nak (megadjuk neki hogy x tengelyről van szó, az ablakon belül melyik ponttól, hány képpont széles, tördelés, elnevezés a tengelyen)

        win.attach(xa);     //az ablakba bele(hívom?) az x tengelyt
        win.set_label("X Axis");    //az ablak név sávját nevezem el
        win.wait_for_button();

        Axis ya {Axis::y, Point(20, 300), 200, 10, "Y axis"};
        ya.set_color(Color::cyan);  //cyan színű lesz az y tengely
        ya.set_color_labe(Color::dark red); //tengely nevének a színe változik
        win.attach(ya);
        win.set_label("Y Axis");
        win.wait_for_button();

        Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50}; //(felismertetem vele hogy sinus, 0-tól 100-as terjedelem, kezdőpont, hány pixelen, ?, ?)
        win.attach(sine);
        win.set_label("Sine function");
        win.wait_for_button;
        sine.set_color(Color::blue);

        Polygon poly;   //sokszöget ábrázolok, ha több szöget adnék meg akkor nem háromszög hanem annyi szög lenne, inkább háromszögre használjuk
        poly.add(Point{300, 200});
        poly.add(Point{350, 100});
        poly.add(Point{400, 200};)

        poly.set_color(Color::red);
        poly.set_style(Line_style::dash);   //rajzolási stílusát adom meg (solid(alapértelmezett), dash ----, dot ...., dashdot -.-.-., dashdotdot -..-..-..)
        win.attach(poly);
        win.set_label("Draw polygon");
        win.wait_for_button;

        Rectangle r {Point{200, 200}, 100, 50}; //másik mód a négyszög rajzolásra (kezdőpont, szélesség, magasság)
        win.attach(r);
        win.set_label("Draw rectangle");
        win.wait_for_button();

        Closed_polyline poly_rect; //másik megoldás a sokszögre
        poly_rect.add(Point{100, 50});
        poly_rect.add(Point{200, 50});
        poly_rect.add(Point{200, 100});
        poly_rect.add(Point{100, 100});
        poly_rect.add(Point{50, 75});

        win.attach(poly_rect);
        win.set_label("Draw rectangle");
        win.wait_for_button();

        r.set_fill_color(Color::yellow); //milyen színnez színezze ki, set_fill_color elé h mit színezzen
        poly.set_style(Line_style(Line_style::dash,4)); //nem tudom miért kell 2x a line_style, a 4 a vastagságát jelöle a vonalnak
        poly_rect.set_style(Line_style(Line_style::dash,2));
        poly_rect.set_fill_color(Color::green);
        win.set_label("Color");
        win.wait_for_button();

        Text t {Point{150, 150}, "Hello, Graphical world!"};    //szöveget ír ki (kezdőpont, mit)
        win.attach(t);
        win.set_label("Text");
        win.wait_for_button();

        t.set_font(Graph_lib::Font::times_bold);    //betűtípus
        t.set_font_size(20);                        //betűméret
        win.set_label("Font");
        win.wait_for_button();

        Image ii (Point{100, 50}, "image.jpg");     //elnevezem ii-nek a képet (kezdőpont, elnevezés)
        win.attach(ii);
        win.set_label("Image");
        win.wait_for_button();

        ii.move(100, 200);      //mozgatom a képet (előző értékétől szélességben és magasságban mennyit mozog)
        win.set_label("Image moving");
        win.wait_for_button();

        Circle c {Point{100, 200}, 50};     //kört rajzolok (kör közepe, sugár mérete)
        Ellipse e {Point{100, 200}, 75, 25};        //elipszis rajzolása (kezdőpont, szélső sugár, hosszában sugár)
        e.set_color(Color::dark_red);
        Mark m {Point{100, 200}, 'x'};      //jelzés kitétele, lehet bármi amit megadok (hova, mi legyen)

        ostringstream oss;
        oss << "Screen size: " << x_max() << "*" << y_max()         //kiírta az ablak adataid amiket lekértem?
            << "; windows size: " << win.x_max() << "*" << win.y_max();         //???
        Text size {Point{100, 20}, oss.str()};

        Image cal {Point{225, 225}, "snow_cpp.gif"};    //újabb kép, itt gif betétele
        cal.set_mask(Point{40,40},200,150);     //??

        win.attach(c);
        win.attach(m);
        win.attach(e);

        win.attach(size);
        win.attach(cal);
        win.set_label("Canvas 12");
        win.wait_for_button();

    } catch(exception& e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    } catch(...) {
        cerr << "error" << endl;
        return 2;
    }
}
/*
try{
    //ide jön a kód
} catch(exception& e) {
    cerr << "exception" << e.what() << endl;
    return 1;   //return nulla a try-ba lenne, 1 ah hibás
} catch(...){
    cerr << "Oops: unknown exception!" << endl;
    return 2;
}
*/

//  (exception& e) will catch std exceptions only
//  (...) will catch everything there after
