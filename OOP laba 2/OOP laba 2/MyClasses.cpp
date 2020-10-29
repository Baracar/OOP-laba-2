#include <iostream>
#include <string>
#include "MyClasses.h"

using namespace std;



int plant:: dertpGet() {
    return dertp;
}

void plant::dertpSet(int val) {
    if (val >= 0)
        dertp = val;
}

void plant::status() {
    life::status();
    cout << "������� ������ - " << dertp << endl;
}


plant::plant() :life() {
    dertp = 0;
    cout << "plant ������" << endl;
}

plant::plant(int _weight, int _height, int _derpt) : life(_weight, _height) {
    dertp = _derpt;
    cout << "plant ������" << endl;
}

plant::plant(plant* a) : life(a) {
    dertp = a->dertp;
    cout << "plant ������" << endl;
}

plant:: ~plant() {
    cout << "plant ���������" << endl;
}

//  ���������� collar

void collar:: colInfo() {
    cout << "���� �������� - " << color << endl;
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
    cout << "collar ���������" << endl;
}

//  ���������� dog

void dog:: bark() {
    cout << "��-��-��" << endl;
}

void dog::status() {
    animal::status();
    col->colInfo();
}

dog::dog() :animal() {
    col = new collar();
    cout << "dog ������" << endl;
}

dog::dog(int _weight, int _height, int _moveSpeed) :animal(_weight, _height, _moveSpeed) {
    col = new collar();
    cout << "dog ������" << endl;
}

dog::dog(dog* a) :animal(a) {
    col = new collar();
    cout << "dog ������" << endl;
}

dog::dog(int _weight, int _height, int _moveSpeed, collar* _col) :animal(_weight, _height, _moveSpeed) {
    col = new collar(_col);
    cout << "dog ������" << endl;
}

dog::dog(dog* a, collar* _col) :animal(a) {
    col = new collar(_col);
    cout << "dog ������" << endl;
}

dog::dog(int _weight, int _height, int _moveSpeed, string _col) :animal(_weight, _height, _moveSpeed) {
    col = new collar(_col);
    cout << "dog ������" << endl;
}

dog::dog(dog* a, string _col) :animal(a) {
    col = new collar(_col);
    cout << "dog ������" << endl;
}

dog:: ~dog() {
    delete col;
    cout << "dog ���������" << endl;
}
