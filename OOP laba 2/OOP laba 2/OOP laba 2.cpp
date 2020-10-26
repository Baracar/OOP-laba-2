#include <iostream>

using namespace std;

class life {
protected :
    bool alive;
    int weight;
    int height;

public:
    virtual void status() {
        cout << "Живое - " << alive << endl << "Вес - " << weight << endl << "Рост - " << height << endl;
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

class animal: public life {
protected:
    int moveSpeed;

public:
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

int main()
{
    cout << boolalpha;
    setlocale(LC_ALL, "Russian");

    life* a = new animal(10, 20, 51);
    a->status();

    animal* b = new animal((animal*)a);
    b->status();

    delete a;
    delete b;
}