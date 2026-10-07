#include <iostream>

class Impresora {
    public:
    virtual void imprimir() = 0;
};

class Scanner {
    public:
    virtual void escanear() = 0;
};

class ImpresoraBasica : public Impresora {
    public:
    void imprimir() override { std::cout <<"Imprimiendo pagina..." << std::endl;
    }
};

int main() {
    ImpresoraBasica imp;
    imp.imprimir();
    return 0;
}
