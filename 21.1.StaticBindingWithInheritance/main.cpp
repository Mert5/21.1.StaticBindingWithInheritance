#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

//  Reference => https://www.youtube.com/watch?v=8jLOx1hD3_o

void draw_circle(const Circle& circle){
    circle.draw();
}

void draw_oval(const Oval& oval){
    oval.draw();
}

// More functions as you deal with more shape types. 30? 100? It's messy.

int main(){

    Shape shape1{"Shape1"};
    //shape1.draw();

    Oval oval1{2.0,3.5,"Oval1"};
    //oval1.draw();

    Circle circle1(3.3, "Circle");
    //circle1.draw();
    

    // Base pointers
    Shape *shape_ptr = &shape1; // Compiler is looking at the type of the object
    //shape_ptr->draw();        // to decide which method should it call ( static binding )
                                // (if you watch out there are 3 draw() methods here)

    shape_ptr = &oval1;
    //shape_ptr->draw();    // Draw an oval -> in most cases, we won't get what we want

    shape_ptr = &circle1;
    //shape_ptr->draw();    // in most cases, we won't get what we want


    // Base references  => // in here also, we don't get what we want. ( static binding )
    Shape& shape_ref = shape1;      
    //shape_ref.draw();

    shape_ref = oval1;              
    //shape_ref.draw();

    shape_ref = circle1;            
    //shape_ref.draw();


    /*
    // Drawing shapes
    draw_circle(circle1);
    draw_oval(oval1);
    */


    /*
    // Shapes stored in collections - Bad design
    Circle circle_collection[]{circle1, Circle(10.2,"Circle2"), Circle(20.3,"Circle3")};
    Oval oval_collection[]{oval1, Oval(21.5,52.3,"Oval2")};
    // More arrays as you have more types, right?
    */

    return 0;
}