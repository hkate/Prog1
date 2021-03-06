#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include <string>
#include <iostream>

// g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_Window.cpp drill13.cpp `fltk-config --ldflags --use-images` -o a2.out

using namespace Graph_lib;
using namespace std;

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

    int x_grid = 100;
    int y_grid = 100;

    Vector_ref<Rectangle> rectangles;
        for (int i = 0; i < x_size; i+=x_grid) {
            rectangles.push_back(new Rectangle(Point{i, i}, Point{i+x_grid, i+x_grid}));
            rectangles[rectangles.size()-1].set_fill_color(Color::red);
            rectangles[rectangles.size()-1].set_color(Color::invisible);
            win.attach(rectangles[rectangles.size()-1]);
        }

    win.wait_for_button();


    Image kep1 (Point(200,0),"kep.jpg");
    win.attach(kep1);
    Image kep2 (Point(500,200),"kep.jpg");
    win.attach(kep2);
    Image kep3 (Point(100,500),"kep.jpg");
    win.attach(kep3);

    win.wait_for_button();

    while (true)
        {
            int randx = rand() % 7 + 1;     // v2 in the range 1 to 8
            randx *= 100;
            int randy = rand() % 7 + 1;     //8x8 már kilógna a grid-ből
            randy *= 100;
            Image kep4 (Point(randx,randy),"kep.jpg");
            kep4.set_mask(Point(0,0),100,100);
            win.attach(kep4);
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