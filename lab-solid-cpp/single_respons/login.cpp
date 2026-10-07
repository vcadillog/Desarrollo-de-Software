#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class Logger {
public:
  void registrarLog(const string &mensaje) {
    cout << "[LOG EN ARCHIVO]: " << mensaje << endl;
  }
};

class ServicioAutenticacion {
private:
  Logger logger;

public:
  bool login(const string &usuario, const string &contrasenia) {
    if (usuario == "admin" && contrasenia == "1234") {
      logger.registrarLog("Usuario admin accedido correctamente.");
      return true;
    }
    logger.registrarLog("Error para ingresar el usuario: " + usuario);
    return false;
  }
};

int main() {
  ServicioAutenticacion autenticador;
  autenticador.login("admin", "1234");
  autenticador.login("hacker", "0000");
  return 0;
}
