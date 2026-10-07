#include <iostream>
#include <string>

using namespace std;

class ServicioEmail {
public:
  void enviarEmailConfirmacion(const string &cliente, double total) {
    cout << "Enviando email para " << cliente << " con un total de: $ " << total
         << endl;
  }
};

class Pedido {
private:
  string cliente;
  double total;

public:
  Pedido(string c, double t) : cliente(c), total(t) {}
  string getCliente() const { return cliente; }
  double getTotal() const { return total; }
};

int main() {
  Pedido nuevoPedido("Carlos Silva", 250.75);
  ServicioEmail emailService;
  emailService.enviarEmailConfirmacion(nuevoPedido.getCliente(),
                                       nuevoPedido.getTotal());
  return 0;
}
