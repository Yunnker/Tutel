#include "CTurtle.hpp"
#include <iostream>

namespace ct = cturtle;

void triangle(ct::Turtle &turtle, float lenght, int counter)
{
    if (counter<=0)
    {
        return;
    }
    for (int i = 0; i < 3; i++) {
        triangle(turtle, lenght / 2, counter - 1);
        turtle.forward(lenght);
        turtle.left(120);
    }
}

void sieciokat(ct::Turtle& turtle, float lenght, int counter)
{
    if (counter <= 0)
    {
        return;
    }
    
    for (int i = 0; i < 6; i++) {
        sieciokat(turtle, lenght / 2, counter - 1);
        turtle.forward(lenght/2);
        turtle.left(60);
    }
}

void dmochawiec(ct::Turtle& turtle, float lenght, int counter)
{
    if (counter <= 0)
    {
        turtle.forward(lenght);
        turtle.backward(lenght);
        return;
    }
        
    turtle.forward(lenght);
    turtle.left(140);
    
    for (int i = 0; i < 8; i++) {
        dmochawiec(turtle, lenght / 2, counter - 1);
        turtle.right(40);
       }
    turtle.forward(lenght);
    turtle.right(180);
}

void trojkat(ct::Turtle& turtle, int bok, int minBok)
{
    if (bok < minBok)
        return;
    for (int i = 0; i < 3; i++)
    {
        trojkat(turtle, bok / 3, minBok);
        turtle.forward(bok);
        turtle.left(120);
    }
}

void trojkat2(ct::Turtle& turtle, int bok, int minBok)
{
    if (bok < minBok)
        return;
    turtle.left(60);
    for (int i = 0; i < 3; i++)
    {
        turtle.forward(bok / 4);
        trojkat2(turtle, bok / 2, minBok);
        turtle.forward((3 * bok) / 4);
        turtle.right(120);
    }
    turtle.right(60);
}

void kwadrat(ct::Turtle& turtle, int bok, int minBok)
{
    if (bok < minBok)
        return;
     
    for (int i = 0; i < 4; i++)
    {
        turtle.forward(bok);
        turtle.left(90);
    }
    turtle.forward(bok / 2);
    turtle.left(45);
    kwadrat(turtle, ((bok / 2) * sqrt(2)), minBok);
}



int main()
{
    // Inicjalizajca
    ct::TurtleScreen scr;
    ct::Turtle turtle(scr);

    // Parametry wykonywania się programu
    turtle.speed(ct::TS_FASTEST);
    turtle.setshowturtle(false);

    // Program

    dmochawiec(turtle, 100, 3);
    
    // Dekonstrukcja
    std::cin.get();
    scr.bye();
    return 0;
}