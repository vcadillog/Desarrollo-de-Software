#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Ruta {
    string path;
    string contenido;
};

string resolverRuta(const vector<Ruta>& rutas, const string& transicion) {

    for (const Ruta& ruta : rutas) {

        int i = 0;
        int j = 0;

        bool coincide = true;
        string parametro = "";

        while (i < ruta.path.length() &&
               j < transicion.length()) {

            if (ruta.path[i] == '/') {
                i++;
                j++;
                continue;
            }

            int inicioRuta = i;

            while (i < ruta.path.length() &&
                   ruta.path[i] != '/') {
                i++;
            }

            int inicioTransicion = j;

            while (j < transicion.length() &&
                   transicion[j] != '/') {
                j++;
            }

            string segmentoRuta =
                ruta.path.substr(
                    inicioRuta,
                    i - inicioRuta
                );

            string segmentoTransicion =
                transicion.substr(
                    inicioTransicion,
                    j - inicioTransicion
                );


            if (segmentoRuta[0] == ':') {

                parametro = segmentoTransicion;
            }
            else {

                if (segmentoRuta != segmentoTransicion) {

                    coincide = false;
                    break;
                }
            }
        }


        if (i != ruta.path.length() ||
            j != transicion.length()) {

            coincide = false;
        }


        if (coincide) {

            if (!parametro.empty()) {
                return ruta.contenido + " " + parametro;
            }

            return ruta.contenido;
        }
    }

    return "404 Not Found";
}


int main() {

    ifstream archivo("entradas/enrutador.txt");

    if (!archivo.is_open()) {

        cout << "Error: no se pudo abrir enrutador.txt"
             << endl;

        return 1;
    }


    int N;

    archivo >> N;
    archivo.ignore();


    vector<Ruta> rutas;

    for (int i = 0; i < N; i++) {

        string path;
        string contenido;

        archivo >> path;

        getline(archivo, contenido);

        if (!contenido.empty() &&
            contenido[0] == ' ') {

            contenido.erase(0, 1);
        }


        int posicion = contenido.find("{id}");

        if (posicion != string::npos) {

            contenido.erase(posicion, 4);

            if (!contenido.empty() &&
                contenido.back() == ' ') {

                contenido.pop_back();
            }
        }


        Ruta ruta;

        ruta.path = path;
        ruta.contenido = contenido;

        rutas.push_back(ruta);
    }


    int M;

    archivo >> M;
    archivo.ignore();


    for (int i = 0; i < M; i++) {

        string transicion;

        getline(archivo, transicion);

        cout << resolverRuta(rutas, transicion)
             << endl;
    }


    archivo.close();

    return 0;
}
