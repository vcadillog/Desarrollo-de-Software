#include <fstream>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

struct DatosEntrada {
  int N;
  int M;
  int S;
  bool estado;
};

struct DatosSocio {
  int p;
  int t;
};

struct socioArray {
  vector<DatosSocio> socios;
  int cantidad;
};

struct DatosCliente {
  int c;
  int t;
};

struct clienteArray {
  vector<DatosCliente> cliente;
  int cantidad;
};

const DatosEntrada errinput1 = {-1, -1, -1, false};
const string errmsg = "Error, fuera de rango\n";
const string errmsg2 = "Error, fuera de rango, intente nuevamente\n";

DatosEntrada entrada(ifstream &archivo) {

  int N, M, S;

  archivo >> N >> M >> S;

  if (N <= 0 || N > 1000) {
    cout << errmsg;
    return errinput1;
  }

  if (M <= 0 || M > 1000) {
    cout << errmsg;
    return errinput1;
  }

  if (S <= 0 || S > 1000) {
    cout << errmsg;
    return errinput1;
  }

  DatosEntrada datos = {N, M, S, true};

  return datos;
}

socioArray socioEntrada(DatosEntrada entrada, ifstream &archivo) {

  int p, t;

  socioArray s;
  s.cantidad = 0;

  for (int i = 0; i < entrada.M; i++) {

    archivo >> p >> t;

    if (p <= 0 || p > entrada.N || t <= 0 || t > 10000) {

      cout << errmsg2;
      return s;
    }

    DatosSocio ds = {p, t};

    s.socios.push_back(ds);
    s.cantidad++;
  }

  return s;
}

clienteArray clienteEntrada(DatosEntrada entrada, ifstream &archivo) {

  int c, t;

  clienteArray s;
  s.cantidad = 0;

  for (int i = 0; i < entrada.S; i++) {

    archivo >> c >> t;

    if (c <= 0 || c > 100000 || t <= 0 || t > 10000) {

      cout << errmsg2;
      return s;
    }

    DatosCliente dc = {c, t};

    s.cliente.push_back(dc);
    s.cantidad++;
  }

  return s;
}

void procesamientoDatos(DatosEntrada entrada, socioArray socios,
                        clienteArray clientes) {

  unordered_map<int, int> terminalSocio;

  for (int i = 0; i < socios.cantidad; i++) {

    int socio = socios.socios[i].p;
    int terminal = socios.socios[i].t;

    terminalSocio[terminal] = socio;
  }

  map<int, map<int, int>> compras;

  for (int i = 0; i < clientes.cantidad; i++) {

    int cliente = clientes.cliente[i].c;
    int terminal = clientes.cliente[i].t;

    if (terminalSocio.find(terminal) != terminalSocio.end()) {

      int socio = terminalSocio[terminal];

      compras[socio][cliente]++;
    }
  }

  for (int socio = 1; socio <= entrada.N; socio++) {

    int mejorCliente = -1;
    int mejorCantidad = 0;

    if (compras.find(socio) != compras.end()) {

      for (auto const &dato : compras[socio]) {

        int cliente = dato.first;
        int cantidad = dato.second;

        if (cantidad > mejorCantidad ||
            (cantidad == mejorCantidad &&
             (mejorCliente == -1 || cliente < mejorCliente))) {

          mejorCantidad = cantidad;
          mejorCliente = cliente;
        }
      }
    }

    cout << socio << " " << mejorCliente << endl;
  }
}

int main() {

  ifstream archivo("entradas/banco.txt");

  if (!archivo.is_open()) {

    cout << "Error: no se pudo abrir el archivo banco.txt" << endl;

    return 1;
  }

  DatosEntrada datosE = entrada(archivo);

  if (!datosE.estado) {

    cout << "Error al ingresar datos, terminando el programa" << endl;

    archivo.close();

    return 0;
  }

  socioArray socios = socioEntrada(datosE, archivo);

  clienteArray clientes = clienteEntrada(datosE, archivo);

  procesamientoDatos(datosE, socios, clientes);

  archivo.close();

  return 0;
}
