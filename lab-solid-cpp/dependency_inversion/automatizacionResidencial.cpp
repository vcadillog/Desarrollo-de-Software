#include <iostream>
#include <memory>

class Dispositivo {
public:
    virtual ~Dispositivo() = default;
    virtual void encender() = 0;
};

class Lampara : public Dispositivo {
public:
    void encender() override { std::cout << "Lampara encendida." << std::endl; }
};

class Interruptor {
private:
    std::shared_ptr<Dispositivo> dispositivo;
public:
    Interruptor(std::shared_ptr<Dispositivo> d) : dispositivo(d) {}
    void presionar() { dispositivo->encender(); }
};

int main() {
    auto lamp = std::make_shared<Lampara>();
    Interruptor boton(lamp);
    boton.presionar();
    return 0;
}
