#pragma once
#include <iostream>
#include <string>

using namespace std;


class life {
private:
    bool alive;
    int weight;
    int height;

public:
    virtual void status();
    bool isAlive();
    void kill();
    int weightGet();
    void weightSet(int val);
    int heightGet();
    void heightSet(int val);
    life();
    life(int _weight, int _height);
    life(life* a);
    ~life();
    
};

class animal : public life {
protected:
    int moveSpeed; //животные двигаются

public:
    int moveSpeedGet();
    void moveSpeedSet(int val);
    void status() override;
    animal();
    animal(int _weight, int _height, int _moveSpeed);
    animal(animal* a);
    ~animal();
    
};

class plant : public life {
protected:
    int dertp;  // растения растут ещё и вглубь

public:
    int dertpGet();
    void dertpSet(int val);
    void status() override;
    plant();
    plant(int _weight, int _height, int _derpt);
    plant(plant* a);
    ~plant();
    
};

class collar {
    string color;

public:
    void colInfo();
    collar();
    collar(string);
    collar(collar*);
    ~collar();
};

class dog : public animal {
    collar* col;
public:
    void bark();
    void status() override;
    dog();
    dog(int _weight, int _height, int _moveSpeed);
    dog(dog* a);
    dog(int _weight, int _height, int _moveSpeed, collar* _col);
    dog(dog* a, collar* _col);
    dog(int , int , int , string );
    dog(dog* a, string _col);
    ~dog();
};
