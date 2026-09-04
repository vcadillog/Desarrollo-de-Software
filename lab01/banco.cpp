#include <iostream>
#include <vector>

using namespace std;

struct DatosEntrada{
    int N;
    int M;
    int S;
    bool estado;
};

struct DatosSocio{
    int p;
    int t;
};

struct socioArray{
    std::vector<DatosSocio> socios;
    int cantidad;
};

struct DatosCliente{
    int c;
    int t;
};

struct clienteArray{
    std::vector<DatosCliente> cliente;
    int cantidad;
};


const DatosEntrada errinput1 = {-1,-1,-1,false};
const string errmsg = "Error, fuera de rango\n";
const string errmsg2 = "Error, fuera de rango, intente nuevamente\n";

DatosEntrada entrada(){
    
    int N,M,S;
    cin >> N;
    cout << " ";
    cin >> M;
    cout << " ";
    cin >> S;
    cout << endl;

    

    if (N<=0){        
        cout << errmsg;
        return errinput1;
    }
    if (M<=0){
        cout << errmsg;
        return errinput1;
    }
    if (S<=0 or S>1000){
        cout << errmsg;
        return errinput1;
    }
    DatosEntrada datos = {N,M,S,true};
    return datos;
}

socioArray socioEntrada(DatosEntrada entrada){
   int p,t;
   socioArray s;   
   s.cantidad = 0;
   int cantidadDatos = entrada.M;

    do{ 
        bool error = false;
        cin >> p;
        cout << " ";
        cin >> t;
        cout << endl;
        if (p <= 0 or p > entrada.N){
            cout << errmsg2;
            error = true;
        }
        if (t <= 0 or t > 10000){
            cout << errmsg2;
            error = true;
        }        
        // comprobar terminales unicas
        /*
        if (s.cantidad > 0){
            for(int i=0; i<s.cantidad; i++){
                
            }
        }
        */
        if (!error){
            DatosSocio ds = {p,t};           
            s.socios.push_back(ds);
            cantidadDatos--;
            s.cantidad++;
        }
    } while (cantidadDatos > 0);
    return s;
}

clienteArray clienteEntrada(DatosEntrada entrada, socioArray socios){
   int c,t;
   clienteArray s;   
   s.cantidad = 0;
   int cantidadDatos = entrada.S;   

    do{ 
        bool error = false;
        cin >> c;
        cout << " ";
        cin >> t;
        cout << endl;
        if (c <= 0 or c > c>100000){
            cout << errmsg2;
            error = true;
        }
        if (t <= 0 or t > 10000){
            cout << errmsg2;
            error = true;
        }        
        // comprobar terminales que coincidan
        
        if (!error){
            DatosCliente ds = {c,t};           
            s.cliente.push_back(ds);
            cantidadDatos--;
            s.cantidad++;
        }
    } while (cantidadDatos > 0);
    return s;
}

void procesamientoDatos(DatosEntrada entrada, socioArray socios, clienteArray clientes){
    for (int i = 0; i<entrada.N ; i++){
        int mejorCliente=-1;
        int mejorCantidad = 0;
        for (int j = 0; j< socios.cantidad ; j++){
            int cantidad = 0;
            int cliente = -1;
            if (socios.socios[j].p == i){
            for(int k=0 ; k< clientes.cantidad; k++){
                if (socios.socios[j].t == clientes.cliente[k].t){
                    cantidad++;
                    cliente = clientes.cliente[k].t;

                }

            }
            if (cantidad > mejorCantidad){
                mejorCliente = cliente;
            }
        }

        }

    }
}

int main(){
    
    
    DatosEntrada datosE = entrada();
    if (datosE.estado){
      cout << datosE.N << " " << datosE.M << " " << datosE.S <<endl;
      socioArray socios = socioEntrada(datosE);
      for (int i=0; i<socios.cantidad; i++){
        cout << socios.socios[i].p << " " << socios.socios[i].t << endl;
      }
    clienteArray clientes = clienteEntrada(datosE, socios);
      for (int i=0; i<socios.cantidad; i++){
        cout << clientes.cliente[i].c << " " << clientes.cliente[i].t << endl;
      }
      procesamientoDatos(datosE, socios, clientes);
    }
    else{
        cout << "Error al ingresar datos, terminando el programa\n";
    }   
 
    return 0;
}