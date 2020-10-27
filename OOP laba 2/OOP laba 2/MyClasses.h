#pragma once
class life {
private:
    bool alive;
    int weight;
    int height;

public:
    virtual void status() {
        cout << "����� - " << alive << endl << "��� - " << weight << endl << "���� - " << height << endl;
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
        cout << "life ������" << endl;
    }

    life(int _weight, int _height) {
        alive = true;
        weight = _weight;
        height = _height;
        cout << "life ������" << endl;
    }

    life(life* a) {
        alive = a->alive;
        weight = a->weight;
        height = a->height;
        cout << "life ������" << endl;
    }

    ~life() {
        cout << "life ���������" << endl;
    }
};

class animal : public life {
protected:
    int moveSpeed; //�������� ���������

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
        cout << "�������� - " << moveSpeed << endl;
    }

    animal() :life() {
        moveSpeed = 0;
        cout << "animal ������" << endl;
    }

    animal(int _weight, int _height, int _moveSpeed) :life(_weight, _height) {
        moveSpeed = _moveSpeed;
        cout << "animal ������" << endl;
    }

    animal(animal* a) :life(a) {
        moveSpeed = a->moveSpeed;
        cout << "animal ������" << endl;
    }

    ~animal() {
        cout << "animal ���������" << endl;
    }
};

class plant : public life {
protected:
    int dertp;  // �������� ������ ��� � ������

public:
    int dertpGet() {
        return dertp;
    }
    void dertpSet(int val) {
        if (val >= 0)
            dertp = val;
    }

    void status() override {
        life::status();
        cout << "������� ������ - " << dertp << endl;
    }


    plant() :life() {
        dertp = 0;
        cout << "plant ������" << endl;
    }

    plant(int _weight, int _height, int _derpt) : life(_weight, _height) {
        dertp = _derpt;
        cout << "plant ������" << endl;
    }

    plant(plant* a) : life(a) {
        dertp = a->dertp;
        cout << "plant ������" << endl;
    }

    ~plant() {
        cout << "plant ���������" << endl;
    }
};

class collar {
    string color;

public:
    void colInfo() {
        cout << "���� �������� - " << color << endl;
    }

    collar() {
        color = "none";
    }

    collar(string a) {
        color = a;
    }

    collar(collar* a) {
        color = a->color;
    }

    ~collar() {
        cout << "collar ���������" << endl;
    }
};

class dog : public animal {
    collar* col;
public:
    void bark();
    void status() override;

    void status() override {
        animal::status();
        col->colInfo();
    }

    dog() :animal() {
        col = new collar();
        cout << "dog ������" << endl;
    }

    dog(int _weight, int _height, int _moveSpeed) :animal(_weight, _height, _moveSpeed) {
        col = new collar();
        cout << "dog ������" << endl;
    }

    dog(dog* a) :animal(a) {
        col = new collar();
        cout << "dog ������" << endl;
    }

    dog(int _weight, int _height, int _moveSpeed, collar* _col) :animal(_weight, _height, _moveSpeed) {
        col = new collar(_col);
        cout << "dog ������" << endl;
    }

    dog(dog* a, collar* _col) :animal(a) {
        col = new collar(_col);
        cout << "dog ������" << endl;
    }

    dog(int _weight, int _height, int _moveSpeed, string _col) :animal(_weight, _height, _moveSpeed) {
        col = new collar(_col);
        cout << "dog ������" << endl;
    }

    dog(dog* a, string _col) :animal(a) {
        col = new collar(_col);
        cout << "dog ������" << endl;
    }

    ~dog() {
        delete col;
        cout << "dog ���������" << endl;
    }
};
