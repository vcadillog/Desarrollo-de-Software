#include <iostream>
#include <memory>

class CanalNotificacion {
public:
    virtual ~CanalNotificacion() = default;
    virtual void enviar(const std::string& msg) = 0;
};

class ServicioSMS : public CanalNotificacion {
public:
    void enviar(const std::string& msg) override { 
        std::cout << "SMS enviado: " << msg << std::endl; 
    }
};

class Notificador {
private:
    std::shared_ptr<CanalNotificacion> canal;
public:
    Notificador(std::shared_ptr<CanalNotificacion> c) : canal(c) {}
    void notificarTransaccion() { 
        canal->enviar("Pagamento aprobado!"); 
    }
};

int main() {
    auto sms = std::make_shared<ServicioSMS>();
    Notificador app(sms);
    app.notificarTransaccion();
    return 0;
}
