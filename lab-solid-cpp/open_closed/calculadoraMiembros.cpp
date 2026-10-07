#include <iostream>
#include <string>

using namespace std;

class PlanMembresia {
public:
  virtual ~PlanMembresia() = default;
  virtual double calcularCosto(double tarifaBase) const = 0;
};

class MembresiaVIP : public PlanMembresia {
public:
  double calcularCosto(double tarifaBase) const override {
    return tarifaBase * 1.5;
  }
};

class MembresiaEstudiante : public PlanMembresia {
public:
  double calcularCosto(double tarifaBase) const override {
    return tarifaBase * .7;
  }
};

class CalculadoraMembresia {
public:
  double calcular(const PlanMembresia &plan, double tarifaBase) {
    return plan.calcularCosto(tarifaBase);
  }
};

int main(){
    CalculadoraMembresia calculadora;
    MembresiaVIP vip;
    MembresiaEstudiante estudiante;

    cout << "VIP: $" << calculadora.calcular(vip, 100.0) << endl;
    cout << "Estudiante: $" << calculadora.calcular(estudiante, 100.0) << endl;
    return 0;
}
