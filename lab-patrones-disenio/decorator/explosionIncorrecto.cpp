#include <iostream>
#include <string>
#include <vector>
#include <memory>

class CafeSolo {
public:
    virtual double getCosto() { return 2.0; }
    virtual std::string getDesc() { return "Cafe Solo"; }
};

class CafeConLeche : public CafeSolo {
public:
    double getCosto() override { return 2.5; }
    std::string getDesc() override { return "Cafe Solo con Leche"; }
};

class CafeConLecheYChocolate : public CafeConLeche {
public:
    double getCosto() override { return 3.2; }
    std::string getDesc() override { return "Cafe Solo con Leche y Chocolate"; }
};
// Imagine tener que codificar clases para todas las permutaciones posibles...

int main() {
    std::cout << "--- Pedidos de Café (Enfoque por Herencia Rigida) ---\n\n";

    // 1. Creando los cafés de forma polimórfica usando Smart Pointers
    // Esto simula un carrito de compras o una lista de pedidos en un sistema real
    std::vector<std::unique_ptr<CafeSolo>> carrito;

    carrito.push_back(std::make_unique<CafeSolo>());
    carrito.push_back(std::make_unique<CafeConLeche>());
    carrito.push_back(std::make_unique<CafeConLecheYChocolate>());

    // 2. Recorriendo la lista y calculando el total dinámicamente
    double totalPedido = 0.0;

    for (const auto& cafe : carrito) {
        std::cout << "Producto: " << cafe->getDesc() << "\n";
        std::cout << "Costo:   $" << cafe->getCosto() << "\n";
        std::cout << "-------------------------------------\n";
        totalPedido += cafe->getCosto();
    }

    std::cout << "TOTAL DEL PEDIDO: $" << totalPedido << "\n";

    return 0;
}
