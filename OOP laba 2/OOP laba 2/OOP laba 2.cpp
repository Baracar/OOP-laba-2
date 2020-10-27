#include <iostream>
#include <string>
#include "MyClasses.h"

using namespace std;



void dog:: bark() {                         //реализация метода после определения
    cout << "Ав-ав-ав" << endl;
}

int main()
{
    cout << boolalpha;
    setlocale(LC_ALL, "Russian");

    life d{10, 20};
    d.status();
    d.kill();
    d.heightSet(40);
    d.weightSet(777);
    d.status();
    cout << endl;

    plant* c = new plant(24, 52, 532);
    c->status();
    delete c;
    cout << endl;

    life* a = new animal(10, 20, 51);
    a->status();
    cout << endl;

    animal* b = new animal((animal*)a);
    b->status();
    delete b;
    cout << endl;

    delete a;
    cout << endl;

    dog* e = new dog(124, 32, 132, "красный");
    e->status();
    delete e;
    cout << endl;
}