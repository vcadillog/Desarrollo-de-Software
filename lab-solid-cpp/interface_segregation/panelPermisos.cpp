#include <iostream>

class Lector {
    public:
    virtual void leerArticulo() = 0;
};

class Administrador {
    public:
    virtual void eliminarUsuario() = 0;
};

class UsuarioComum : public Lector {
    public: void leerArticulo() override { std::cout << "Leyendo contenido..." << std::endl; }
};

int main() {
    UsuarioComum usr;
    usr.leerArticulo();
    return 0;
}
