#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Cafe {
public:
  virtual ~Cafe() = default;
  virtual double getCosto() const = 0;
  virtual string getDesc() const = 0;
};

class CafeSolo : public Cafe {
public:
  double getCosto() const override { return 2.0; }
  string getDesc() const override { return "Cafe Solo"; }
};

class DecoratorCafe : public Cafe {
protected:
  unique_ptr<Cafe> cafeBase;

public:
  DecoratorCafe(unique_ptr<Cafe> c) : cafeBase(std::move(c)) {}
};

class ConLeche : public DecoratorCafe {
public:
  ConLeche(unique_ptr<Cafe> c) : DecoratorCafe(std::move(c)) {}
  double getCosto() const override { return cafeBase->getCosto() + 0.5; }
  string getDesc() const override { return cafeBase->getDesc() + " con Leche"; }
};

int main() {
  unique_ptr<Cafe> miCafe = make_unique<CafeSolo>();
  miCafe = make_unique<ConLeche>(std::move(miCafe));
  cout << miCafe->getDesc() << " costo: $" << miCafe->getCosto() << endl;
  return 0;
}
