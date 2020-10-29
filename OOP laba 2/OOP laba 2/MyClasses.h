#pragma once
class life {
private:
    bool alive;
    int weight;
    int height;

public:
    virtual void status() {
        cout << "Живое - " << alive << endl << "Вес - " << weight << endl << "Рост - " << height << endl;
    }

    void kill() {
        alive = false;
    }

    int weightGet() {
        return weight;
    }
    void weightSet(int val) {
        if (val >= 0)
            weight = val;
    }

    int heightGet() {
        return height;
    }
    void heightSet(int val) {
        if (val >= 0)
            height = val;
    }

    bool isAlive() {
        return alive;
    }

    life() {
        alive = true;
        weight = 0;
        height = 0;
        cout << "life создан" << endl;
    }

    life(int _weight, int _height) {
        alive = true;
        weight = _weight;
        height = _height;
        cout << "life создан" << endl;
    }

    life(life* a) {
        alive = a->alive;
        weight = a->weight;
        height = a->height;
        cout << "life создан" << endl;
    }

    ~life() {
        cout << "life уничтожен" << endl;
    }
};

class animal : public life {
protected:
    int moveSpeed; //животные двигаются

public:
    int moveSpeedGet() {
        return moveSpeed;
    }
    void moveSpeedSet(int val) {
        if (val >= 0)
            moveSpeed = val;
    }

    void status() override {
        life::status();
        cout << "Скорость - " << moveSpeed << endl;
    }

    animal() :life() {
        moveSpeed = 0;
        cout << "animal создан" << endl;
    }

    animal(int _weight, int _height, int _moveSpeed) :life(_weight, _height) {
        moveSpeed = _moveSpeed;
        cout << "animal создан" << endl;
    }

    animal(animal* a) :life(a) {
        moveSpeed = a->moveSpeed;
        cout << "animal создан" << endl;
    }

    ~animal() {
        cout << "animal уничтожен" << endl;
    }
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
    collar(string a);
    collar(collar* a);
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
