#include <iostream>
#include <string>

class Ave {
public:
    virtual ~Ave() = default;
    virtual std::string getNombre() const = 0;
};

class AveVoladora : public Ave {
public:
    virtual void volar() const { std::cout << getNombre() << " volando alto." << std::endl; }
};

class Pinguino : public Ave {
public:
    std::string getNombre() const override { return "Pinguino"; }
};

int main() {
    Pinguino p;
    std::cout << "Ave: " << p.getNombre() << std::endl;
    return 0;
}
