#include <iostream>

class Forma {
public:
    virtual ~Forma() = default;
    virtual int calcularArea() const = 0;
};

class Retangulo : public Forma {
private:
    int largo, alto;
public:
    Retangulo(int w, int h) : largo(w), alto(h) {}
    int calcularArea() const override { return largo* alto; }
};

class Cuadrado : public Forma {
private:
    int lado;
public:
    Cuadrado(int s) : lado(s) {}
    int calcularArea() const override { return lado * lado; }
};

int main() {
    Retangulo r(5, 4);
    Cuadrado q(5);
    std::cout << "Area Rectángulo: " << r.calcularArea() << std::endl;
    std::cout << "Area Cuadrado: " << q.calcularArea() << std::endl;
    return 0;
}
