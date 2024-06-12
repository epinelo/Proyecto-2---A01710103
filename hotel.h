#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <chrono>
#include <ctime>

using namespace std;

// Clase Habitacion

class Habitacion {
protected:
    int numero;
    string tipo;
    double precio;
    bool disponibilidad;

public:
    Habitacion();
    Habitacion(int num, string t, double p, bool d);
    virtual void mostrarDetalles() const = 0;
    void cambiarDisp();
    virtual void calcularPrecio() = 0;
    int getNumero() const {return numero;};
    string getTipo() const {return tipo;};
    double getPrecio() const {return precio;};
    bool getDisponibilidad() const {return disponibilidad;};
    void setNumero(int num) {numero = num;};
    void setTipo(string t) {tipo = t;};
    void setPrecio(double p) {precio = p;};
};

// Métodos Habitacion

Habitacion::Habitacion() : numero(404), tipo("Suite"), precio(1000), disponibilidad(true) {}

Habitacion::Habitacion(int num, string t, double p, bool d) : numero(num), tipo(t), precio(p), disponibilidad(d) {}

void Habitacion::cambiarDisp() {
    disponibilidad = !disponibilidad;
}

// Clase HabitacionSimple

class HabitacionSimple : public Habitacion {
private:
    string vista;

public:
    HabitacionSimple(int num, bool d, string v);
    void mostrarDetalles() const;
    void calcularPrecio();
    string getVista() const {return vista;};
    void setVista(string v) {vista = v;};
};

// Métodos HabitacionSimple

HabitacionSimple::HabitacionSimple(int num, bool d, string v) : Habitacion(num, "Simple", 150, d), vista(v) {}

void HabitacionSimple::mostrarDetalles() const {
    cout << "Habitación Simple #" << numero << endl;
    cout << "Disponibilidad: " << (disponibilidad ? "Sí" : "No") << endl;
    cout << "Precio base: $" << precio << endl;
    cout << "Vista: " << vista << endl;
    cout << endl;
}

void HabitacionSimple::calcularPrecio() {
    if (vista == "Especial") {
        precio = precio + 100;
    }
    cout << "Precio calculado por noche en la habitación " << numero << ": $" << precio << endl;
    cout << endl;
}

// Clase HabitacionDoble

class HabitacionDoble : public Habitacion {
private:
    string vista;
    bool balcon;

public:
    HabitacionDoble(int num, bool d, string v, bool b);
    void mostrarDetalles() const;
    void calcularPrecio();
    string getVista() const {return vista;};
    void setVista(string v) {vista = v;};
    bool getBalcon() const {return balcon;};
    void setBalcon(bool b) {balcon = b;};
};

// Métodos HabitacionDoble 

HabitacionDoble::HabitacionDoble(int num, bool d, string v, bool b) : Habitacion(num, "Doble", 300, d), vista(v), balcon(b) {}

void HabitacionDoble::mostrarDetalles() const {
    cout << "Habitación Doble #" << numero << endl;
    cout << "Disponibilidad: " << (disponibilidad ? "Sí" : "No") << endl;
    cout << "Precio base: $" << precio << endl;
    cout << "Vista: " << vista << endl;
    cout << "Balcon: " << (balcon ? "Sí" : "No") << endl;
    cout << endl;
}

void HabitacionDoble::calcularPrecio() {
    if (vista == "Especial") {
        precio = precio + 100;
    }
    if (balcon) {
            precio = precio + 250;
        }
    cout << "Precio calculado por noche en la habitación " << numero << ": $" << precio << endl;
    cout << endl;
}

// Clase Suite

class Suite : public Habitacion {
private:
    string vista;
    int n_cuartos;

public:
    Suite();
    Suite(int num, bool d, string v, int nc);
    void mostrarDetalles() const;
    void calcularPrecio();
    string getVista() const {return vista;};
    void setVista(string v) {vista = v;};
    int getNcuartos() const {return n_cuartos;};
    void setNcuartos(int nc) {n_cuartos = nc;};
};

// Métodos Suite

Suite::Suite() : Habitacion(), vista("Especial"), n_cuartos(4) {}

Suite::Suite(int num, bool d, string v, int nc) : Habitacion(num, "Suite", 1000, d), vista(v), n_cuartos(nc) {}

void Suite::mostrarDetalles() const {
    cout << "Suite #" << numero << endl;
    cout << "Disponibilidad: " << (disponibilidad ? "Sí" : "No") << endl;
    cout << "Precio base: $" << precio << endl;
    cout << "Vista: " << vista << endl;
    cout << "Número de cuartos: " << n_cuartos << endl;
    cout << endl;
}

void Suite::calcularPrecio() {
    if (vista == "Especial") {
        precio = precio + (n_cuartos*200) + 100;
    } else {
        precio = precio + (n_cuartos*200);
    }
    cout << "Precio calculado por noche en la habitación " << numero << ": $" << precio << endl;
    cout << endl;
}

// Clase Cliente

class Cliente {
private:
    string nombre;
    string telefono;
    string email;

public:
    Cliente();
    Cliente(string n, string t, string e);
    void mostrarDetalles() const;
    void actualizarInfo(const string& n, const string& t, const string& e);
    string getNombre() const {return nombre;};
    string getTelefono() const {return telefono;};
    string getEmail() const {return email;};
};

// Métodos Cliente

Cliente::Cliente() : nombre("Emilio"), telefono("55 6790 6442"), email("a01710103@tec.mx") {}

Cliente::Cliente(string n, string t, string e) : nombre(n), telefono(t), email(e) {}

void Cliente::mostrarDetalles() const {
    cout << "Cliente: " << nombre << endl;
    cout << "Teléfono: " << telefono << endl;
    cout << "Email: " << email << endl;
    cout << endl;
}

void Cliente::actualizarInfo(const string& n, const string& t, const string& e) {
    nombre = n;
    telefono = t;
    email = e;
}

// Clase Hotel

class Hotel {
private:
    string nombre;
    string direccion;
    int n_habitaciones;
    vector<Habitacion*> habitaciones;

public:
    Hotel();
    Hotel(const string& n, const string& d);
    void agregarHab(Habitacion* hab);
    void buscarHabDisp() const;
    void mostrarDetalles() const;
    string getNombre() const {return nombre;};
    string getDireccion () const {return direccion;};
    int getNhabitaciones () const {return n_habitaciones;};
    void getHabitaciones() const;
};

// Métodos Hotel

Hotel::Hotel() : nombre("Occidental Cancún"), direccion("Blvd Kukulcan"), n_habitaciones(0) {}

Hotel::Hotel(const string& n, const string& d) : nombre(n), direccion(d), n_habitaciones(0) {}

void Hotel::agregarHab(Habitacion* hab) {
    habitaciones.push_back(hab);
    n_habitaciones++;
}

void Hotel::buscarHabDisp() const {
    cout << "Habitaciones disponibles:" << endl;
    for (const auto& hab : habitaciones) {
        if (hab->getDisponibilidad()) {
            hab->mostrarDetalles();
        }
    }
    cout << endl;
}

void Hotel::mostrarDetalles() const {
    cout << "Hotel: " << nombre << endl;
    cout << "Dirección: " << direccion << endl;
    cout << "Número de habitaciones: " << n_habitaciones << endl;
}

void Hotel::getHabitaciones() const {
    for (Habitacion* ptr : habitaciones) {
        ptr->mostrarDetalles();
    }
    for (Habitacion* ptr : habitaciones) {
        delete ptr;
    }
}

// Clase Reserva

class Reserva {
private:
    string id;
    int n_noches;
    double costoTotal;
    Cliente cliente;
    Habitacion* habitacion;
    Hotel* hotel;

public:
    Reserva();
    Reserva(const string& i, int nn, const Cliente& c, Habitacion* h, Hotel* ho);
    void mostrarDetalles() const;
    void calcularCosto();
    void confirmaReserva();
    string getID() const {return id;};
    int getNoches() const {return n_noches;};
    double getCostoT() const {return costoTotal;};
    void setID(const string& i) {id = i;};
    void setNoches(int nn) {n_noches = nn;};
};

// Métodos Reserva

Reserva::Reserva() : id("R003"), n_noches(5), cliente(), habitacion(nullptr), hotel(nullptr) {}

Reserva::Reserva(const string& i, int nn, const Cliente& c, Habitacion* h, Hotel* ho)
    : id(i), n_noches(nn), cliente(c), habitacion(h), hotel(ho) {
    calcularCosto();
}

void Reserva::mostrarDetalles() const {
    cout << "ID: " << id <<endl;
    cout << "Número de noches: " << n_noches << endl;
    cout << "Costo Total: " << costoTotal << endl;
    cliente.mostrarDetalles();
    cout << "Hotel: " << hotel->getNombre() << endl;
    habitacion->mostrarDetalles();
    cout << endl;
}

void Reserva::calcularCosto() {
    costoTotal = (habitacion->getPrecio())*n_noches;
}

void Reserva::confirmaReserva() {
    if (habitacion->getDisponibilidad()) {
        habitacion->cambiarDisp();
        cout << "Reserva de " << cliente.getNombre() << " confirmada." << endl;
    } else {
        cout << "La habitación no está disponible." << endl;
    }
    cout << endl;
}

#endif