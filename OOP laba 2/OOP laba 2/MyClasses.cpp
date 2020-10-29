#include <iostream>
#include <string>
#include "MyClasses.h"

using namespace std;

void life:: status() {
    cout << "Живое - " << alive << endl << "Вес - " << weight << endl << "Рост - " << height << endl;
}

void life::kill() {
    alive = false;
}

int life::weightGet() {
    return weight;
}
void life::weightSet(int val) {
    if (val >= 0)
        weight = val;
}

int life::heightGet() {
    return height;
}
void life::heightSet(int val) {
    if (val >= 0)
        height = val;
}

bool life::isAlive() {
    return alive;
}

life::life() {
    alive = true;
    weight = 0;
    height = 0;
    cout << "life создан" << endl;
}

life::life(int _weight, int _height) {
    alive = true;
    weight = _weight;
    height = _height;
    cout << "life создан" << endl;
}

life::life(life* a) {
    alive = a->alive;
    weight = a->weight;
    height = a->height;
    cout << "life создан" << endl;
}

life:: ~life() {
    cout << "life уничтожен" << endl;
}

//  Реализация animal

int animal:: moveSpeedGet() {
    return moveSpeed;
}
void animal::moveSpeedSet(int val) {
    if (val >= 0)
        moveSpeed = val;
}

void animal::status() {
    life::status();
    cout << "Скорость - " << moveSpeed << endl;
}

animal::animal() :life() {
    moveSpeed = 0;
    cout << "animal создан" << endl;
}

animal::animal(int _weight, int _height, int _moveSpeed) :life(_weight, _height) {
    moveSpeed = _moveSpeed;
    cout << "animal создан" << endl;
}

animal::animal(animal* a) :life(a) {
    moveSpeed = a->moveSpeed;
    cout << "animal создан" << endl;
}

animal::~animal() {
    cout << "animal уничтожен" << endl;
}

//  Реализация plant

int plant:: dertpGet() {
    return dertp;
}

void plant::dertpSet(int val) {
    if (val >= 0)
        dertp = val;
}

void plant::status() {
    life::status();
    cout << "Глубина корней - " << dertp << endl;
}


plant::plant() :life() {
    dertp = 0;
    cout << "plant создан" << endl;
}

plant::plant(int _weight, int _height, int _derpt) : life(_weight, _height) {
    dertp = _derpt;
    cout << "plant создан" << endl;
}

plant::plant(plant* a) : life(a) {
    dertp = a->dertp;
    cout << "plant создан" << endl;
}

plant:: ~plant() {
    cout << "plant уничтожен" << endl;
}

//  Реализация collar

void collar:: colInfo() {
    cout << "Цвет ошейника - " << color << endl;
}

collar::collar() {
    color = "none";
}

collar::collar(string a) {
    color = a;
}

collar::collar(collar* a) {
    color = a->color;
}

collar:: ~collar() {
    cout << "collar уничтожен" << endl;
}

//  Реализация dog

void dog:: bark() {
    cout << "Ав-ав-ав" << endl;
}

void dog::status() {
    animal::status();
    col->colInfo();
}

dog::dog() :animal() {
    col = new collar();
    cout << "dog создан" << endl;
}

dog::dog(int _weight, int _height, int _moveSpeed) :animal(_weight, _height, _moveSpeed) {
    col = new collar();
    cout << "dog создан" << endl;
}

dog::dog(dog* a) :animal(a) {
    col = new collar();
    cout << "dog создан" << endl;
}

dog::dog(int _weight, int _height, int _moveSpeed, collar* _col) :animal(_weight, _height, _moveSpeed) {
    col = new collar(_col);
    cout << "dog создан" << endl;
}

dog::dog(dog* a, collar* _col) :animal(a) {
    col = new collar(_col);
    cout << "dog создан" << endl;
}

dog::dog(int _weight, int _height, int _moveSpeed, string _col) :animal(_weight, _height, _moveSpeed) {
    col = new collar(_col);
    cout << "dog создан" << endl;
}

dog::dog(dog* a, string _col) :animal(a) {
    col = new collar(_col);
    cout << "dog создан" << endl;
}

dog:: ~dog() {
    delete col;
    cout << "dog уничтожен" << endl;
}
