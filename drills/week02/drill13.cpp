#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

//#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
{
    try {

    Point t1{300,500};
    Simple_window win (t1, 1000, 800, "My window"); //elóállttom magát az ablakom
    win.wait_for_button(); // vár addig amig megnyomja a gombot

    Lines grid;
    int x_size = 800;
    int y_size = 800;
    for (int i=100; i<=x_size; i+=100) {
                    grid.add(Point{i, 0}, Point{i, y_size});
                    grid.add (Point{0, i}, Point{x_size, i});
    }
    win.attach(grid);
    win.wait_for_button() ;

    for (int t=0; t<8; t++) {
            Graph_lib::Rectangle rect{Point{t * 100, t * 100}, 100, 100};
            rect.set_color(Color::red);
            rect.set_fill_color(Color::red); //néqyzetek átlósan pirosak
            win.attach(rect);               //kattintásra egy négyzettel tovább
            win.wait_for_button();
    }
    win.wait_for_button();

    } catch (exception& e) {
        cerr << "exception: " << e.what()<< '\n';
        return 1; 
    } catch (...) {
        cerr << "error\n";
        return 2;
    }
}