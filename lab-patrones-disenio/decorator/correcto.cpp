#include <iostream>
#include <string>
#include <memory>

// 1. Componente Base Abstracto
class Bebida {
public:
    virtual ~Bebida() = default;
    virtual std::string getDescripcion() const = 0;
    virtual double getCosto() const = 0;
};

// 2. Componente Concreto
class CafeBase : public Bebida {
public:
    std::string getDescripcion() const override { return "Café Seleccionado"; }
    double getCosto() const override { return 2.00; }
};

// 3. Decorador Base Estructural (Mantiene relación IS-A y HAS-A)
class AgregadoDecorator : public Bebida {
protected:
    std::shared_ptr<Bebida> bebidaEnvoltorio;
public:
    AgregadoDecorator(std::shared_ptr<Bebida> bebida) : bebidaEnvoltorio(bebida) {}
};

// 4. Decoradores Concretos que acumulan estados/costos
class ConLeche : public AgregadoDecorator {
public:
    ConLeche(std::shared_ptr<Bebida> bebida) : AgregadoDecorator(bebida) {}

    std::string getDescripcion() const override {
        return bebidaEnvoltorio->getDescripcion() + ", con Leche Premium";
    }

    double getCosto() const override {
        return bebidaEnvoltorio->getCosto() + 0.50;
    }
};

class ConChocolate : public AgregadoDecorator {
public:
    ConChocolate(std::shared_ptr<Bebida> bebida) : AgregadoDecorator(bebida) {}

    std::string getDescripcion() const override {
        return bebidaEnvoltorio->getDescripcion() + ", con Sabor Chocolate";
    }

    double getCosto() const override {
        return bebidaEnvoltorio->getCosto() + 0.70;
    }
};

class ConCaramelo : public AgregadoDecorator {
public:
    ConCaramelo(std::shared_ptr<Bebida> bebida) : AgregadoDecorator(bebida) {}

    std::string getDescripcion() const override {
        return bebidaEnvoltorio->getDescripcion() + ", enriquecido con Caramelo";
    }

    double getCosto() const override {
        return bebidaEnvoltorio->getCosto() + 0.65;
    }
};

int main() {
    // Pedido dinámico: Café + Leche + Caramelo
    std::shared_ptr<Bebida> pedido = std::make_shared<CafeBase>();
    pedido = std::make_shared<ConLeche>(pedido);
    pedido = std::make_shared<ConCaramelo>(pedido);

    std::cout << "Detalle de Entrega: " << pedido->getDescripcion() << "\n";
    std::cout << "Importe Liquidación: $" << pedido->getCosto() << "\n";

    return 0;
}
