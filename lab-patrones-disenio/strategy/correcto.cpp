#include <iostream>
#include <memory>
#include <string>

// 1. Interfaz abstracta para la Estrategia de Precios
class EstrategiaPrecio {
public:
    virtual ~EstrategiaPrecio() = default;
    virtual double calcular(double tarifaBase) const = 0;
};

// 2. Implementaciones Concretas de las Estrategias
class PrecioRegular : public EstrategiaPrecio {
public:
    double calcular(double tarifaBase) const override { return tarifaBase; }
};

class PrecioVIP : public EstrategiaPrecio {
public:
    double calcular(double tarifaBase) const override { return tarifaBase * 1.5; }
};

class PrecioEstudiante : public EstrategiaPrecio {
public:
    double calcular(double tarifaBase) const override { return tarifaBase * 0.70; }
};

class PrecioSenior : public EstrategiaPrecio {
public:
    double calcular(double tarifaBase) const override { return tarifaBase * 0.50; }
};

// 3. El Contexto: Clase Socio que delega el comportamiento
class Socio {
private:
    std::string nombre;
    std::shared_ptr<EstrategiaPrecio> estrategia;

public:
    Socio(const std::string& nom, std::shared_ptr<EstrategiaPrecio> est)
        : nombre(nom), estrategia(est) {}

    void setEstrategia(std::shared_ptr<EstrategiaPrecio> nuevaEstrategia) {
        estrategia = nuevaEstrategia;
    }

    double obtenerCostoMembresia(double tarifaBase) const {
        if (!estrategia) return 0.0;
        return estrategia->calcular(tarifaBase);
    }

    std::string getNombre() const { return nombre; }
};

int main() {
    double tarifaBase = 100.0;

    auto socio = std::make_shared<Socio>("Carlos", std::make_shared<PrecioRegular>());
    std::cout << "Socio: " << socio->getNombre() << " | Costo: $" << socio->obtenerCostoMembresia(tarifaBase) << "\n";

    // El negocio exige cambiar su membresia a VIP de manera dinámica
    socio->setEstrategia(std::make_shared<PrecioVIP>());
    std::cout << "Socio (Cambiado a VIP): " << socio->getNombre() << " | Costo: $" << socio->obtenerCostoMembresia(tarifaBase) << "\n";

    return 0;
}
