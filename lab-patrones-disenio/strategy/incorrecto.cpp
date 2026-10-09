#include <iostream>
#include <string>
#include <stdexcept>

class CalculadorMembresia {
public:
    double calcularCosto(const std::string& tipoSocio, double tarifaBase) {
        if (tipoSocio == "REGULAR") {
            return tarifaBase;
        } else if (tipoSocio == "VIP") {
            return tarifaBase * 1.5;
        } else if (tipoSocio == "ESTUDIANTE") {
            return tarifaBase * 0.70;
        } else if (tipoSocio == "SENIOR") {
            return tarifaBase * 0.50;
        } else {
            throw std::invalid_argument("Tipo de socio no soportado de manera nativa.");
        }
    }
};

int main() {
    CalculadorMembresia calculador;
    double tarifaBase = 100.0;

    std::cout << "--- Probando Calculador de Membresía (Versión Inicial) ---\n\n";

    // 1. Probando escenarios válidos
    std::cout << "Socio REGULAR: $" << calculador.calcularCosto("REGULAR", tarifaBase) << "\n";
    std::cout << "Socio VIP:     $" << calculador.calcularCosto("VIP", tarifaBase) << "\n";
    std::cout << "Socio SENIOR:  $" << calculador.calcularCosto("SENIOR", tarifaBase) << "\n\n";

    // 2. Probando el bloque de excepción (try/catch) para un tipo inválido
    try {
        std::cout << "Intentando tipo inválido...\n";
        double custoInvalido = calculador.calcularCosto("CORPORATIVO", tarifaBase);
        std::cout << "Costo: $" << custoInvalido << "\n";
    } catch (const std::invalid_argument& e) {
        // Captura el 'throw std::invalid_argument' que está dentro de su método
        std::cerr << "Error esperado capturado: " << e.what() << "\n";
    }

    return 0;
}
