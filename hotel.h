/*
 * Proyecto POO TC1030 - Hotel implementación
 * Emilio Pinelo Landarte - A01710103
 * 14/06/2024
 * SISTEMA DE RESERVACIONES DE CADENA HOTELERA
 * En este archivo se definen e implementan las clases:
 * - Habitacion
 * - HabitacionSimple
 * - HabitacionDoble
 * - Suite
 * - Cliente
 * - Hotel
 * - Reservacion
*/

#ifndef HOTEL_H
#define HOTEL_H

#include <iostream> // Para imprimir
#include <string> // Para manipulación de cadenas de caracteres
#include <vector> // Para el uso de vectores
#include <iomanip> // Para manipulación de la entrada/salida
#include <limits> // Para obtener información sobre tipos de datos

using namespace std;

// Clase Habitacion (clase abstracta)

class Habitacion {
// Variables de instancia protegidas
protected:
    int numero;
    string tipo;
    double precio;
    bool disponibilidad;

// Métodos públicos
public:
    Habitacion(string t, double p); // Constructor por omisón
    Habitacion(int num, string t, double p, bool d);
    virtual void mostrarDetalles() const = 0; // Método abstracto
    void cambiarDisp();
    virtual double calcularPrecio() = 0; // Método abstracto
    // Getters y Setters
    int getNumero() const {return numero;};
    string getTipo() const {return tipo;};
    double getPrecio() const {return precio;};
    bool getDisponibilidad() const {return disponibilidad;};
    void setNumero(int num) {numero = num;};
    void setTipo(string t) {tipo = t;};
    void setPrecio(double p) {precio = p;};
};

// Implementación de métodos Habitacion

Habitacion::Habitacion(string t, double p) : numero(404), tipo(t), precio(p), disponibilidad(true) {}

Habitacion::Habitacion(int num, string t, double p, bool d) : numero(num), tipo(t), precio(p), disponibilidad(d) {}

// Cambio de disponibilidad de una habitación
void Habitacion::cambiarDisp() {
    disponibilidad = !disponibilidad;
}

// Clases derivadas de clase base Habitacion

// Clase HabitacionSimple derivada de Habitacion

class HabitacionSimple : public Habitacion {
// Variables de instancia privadas
private:
    string vista;

// Métodos públicos
public:
    HabitacionSimple(); // Constructor por omisión
    HabitacionSimple(int num, bool d, string v);
    // Métodos sobreescritos
    void mostrarDetalles() const;
    double calcularPrecio();
    // Getter y Setter
    string getVista() const {return vista;};
    void setVista(string v) {vista = v;};
};

// Implementación de métodos HabitacionSimple

HabitacionSimple::HabitacionSimple() : Habitacion("Simple", 150), vista("Especial") {}

HabitacionSimple::HabitacionSimple(int num, bool d, string v) : Habitacion(num, "Simple", 150, d), vista(v) {}

// Infromación sobre una habitación simple
void HabitacionSimple::mostrarDetalles() const {
    cout << "Habitación Simple #" << numero << endl;
    cout << "Disponibilidad: " << (disponibilidad ? "Sí" : "No") << endl;
    cout << "Precio base: $" << precio << endl;
    cout << "Vista: " << vista << endl;
    cout << endl;
}

// Cálculo del precio de una habitación simple, con o sin vista especial.
double HabitacionSimple::calcularPrecio() {
    if (vista == "Especial") {
        precio = precio + 100;
    }
    return precio;
}

// Clase HabitacionDoble derivada de Habitacion

class HabitacionDoble : public Habitacion {
// Variables de instancia privadas
private:
    string vista;
    bool balcon;

// Métodos públicos
public:
    HabitacionDoble(); // Constructor por omisión
    HabitacionDoble(int num, bool d, string v, bool b);
    // Métodos sobreescritos
    void mostrarDetalles() const;
    double calcularPrecio();
    // Getters y Setters
    string getVista() const {return vista;};
    void setVista(string v) {vista = v;};
    bool getBalcon() const {return balcon;};
    void setBalcon(bool b) {balcon = b;};
};

// Implementación de métodos HabitacionDoble 

HabitacionDoble::HabitacionDoble() : Habitacion("Doble", 300), vista("Especial"), balcon(true) {}

HabitacionDoble::HabitacionDoble(int num, bool d, string v, bool b) : Habitacion(num, "Doble", 300, d), vista(v), balcon(b) {}

// Información de una habitación doble
void HabitacionDoble::mostrarDetalles() const {
    cout << "Habitación Doble #" << numero << endl;
    cout << "Disponibilidad: " << (disponibilidad ? "Sí" : "No") << endl;
    cout << "Precio base: $" << precio << endl;
    cout << "Vista: " << vista << endl;
    cout << "Balcon: " << (balcon ? "Sí" : "No") << endl;
    cout << endl;
}

// Cálculo del precio de una habitación doble, con o sin vista especial y con o sin balcón
double HabitacionDoble::calcularPrecio() {
    if (vista == "Especial") {
        precio = precio + 100;
    }
    if (balcon) {
            precio = precio + 250;
        }
    return precio;
}

// Clase Suite derivada de Habitacion

class Suite : public Habitacion {
// Variables de instancia privadas
private:
    string vista;
    int n_cuartos;

// Métodos públicos
public:
    Suite(); // Constructor por omisión
    Suite(int num, bool d, string v, int nc);
    // Métodos sobreescritos
    void mostrarDetalles() const;
    double calcularPrecio();
    // Getters y Setters
    string getVista() const {return vista;};
    void setVista(string v) {vista = v;};
    int getNcuartos() const {return n_cuartos;};
    void setNcuartos(int nc) {n_cuartos = nc;};
};

// Implementación de métodos Suite

Suite::Suite() : Habitacion("Suite", 1000), vista("Especial"), n_cuartos(4) {}

Suite::Suite(int num, bool d, string v, int nc) : Habitacion(num, "Suite", 1000, d), vista(v), n_cuartos(nc) {}

// Información de una suite
void Suite::mostrarDetalles() const {
    cout << "Suite #" << numero << endl;
    cout << "Disponibilidad: " << (disponibilidad ? "Sí" : "No") << endl;
    cout << "Precio base: $" << precio << endl;
    cout << "Vista: " << vista << endl;
    cout << "Número de cuartos: " << n_cuartos << endl;
    cout << endl;
}

// Cálculo de una habitación en base al número de cuartos y si tiene o no vista especial
double Suite::calcularPrecio() {
    if (vista == "Especial") {
        precio = precio + (n_cuartos*200) + 100;
    } else {
        precio = precio + (n_cuartos*200);
    }
    return precio;
}

// Clase Cliente

class Cliente {
// Variables de instancia privadas
private:
    string nombre;
    string telefono;
    string email;

// Métodos públicos
public:
    Cliente(); // Constructoe por omisión
    Cliente(string n, string t, string e);
    void mostrarDetalles() const;
    void actualizarInfo(const string& n, const string& t, const string& e);
    // Gatters
    string getNombre() const {return nombre;};
    string getTelefono() const {return telefono;};
    string getEmail() const {return email;};
};

// Implementación de métodos Cliente

Cliente::Cliente() : nombre("Emilio"), telefono("55 6790 6442"), email("a01710103@tec.mx") {}

Cliente::Cliente(string n, string t, string e) : nombre(n), telefono(t), email(e) {}

// Información sobre el cliente
void Cliente::mostrarDetalles() const {
    cout << "Cliente: " << nombre << endl;
    cout << "Teléfono: " << telefono << endl;
    cout << "Email: " << email << endl;
    cout << endl;
}

// Actualización de la información del cliente (Setter)
void Cliente::actualizarInfo(const string& n, const string& t, const string& e) {
    nombre = n;
    telefono = t;
    email = e;
}

// Clase Hotel

class Hotel {
// Variables de intsancia privadas
private:
    string nombre;
    string direccion;
    int n_habitaciones;
    vector<Habitacion*> habitaciones; // Vector de apuntadores a objetos de tipo Habitacion

// Métodos públicos
public:
    Hotel(); // Constructor por omisión
    Hotel(const string& n, const string& d);
    void agregarHab(Habitacion* hab);
    void buscarHabDisp() const;
    void mostrarDetalles() const;
    void imprimeHabitaciones();
    // Getters y Setters
    string getNombre() const {return nombre;};
    string getDireccion () const {return direccion;};
    int getNhabitaciones () const {return n_habitaciones;};
    vector<Habitacion*> getHabitaciones() const {return habitaciones;};
};

// Implementación de métodos Hotel

Hotel::Hotel() : nombre("Occidental Cancún"), direccion("Blvd Kukulcan"), n_habitaciones(0) {}

Hotel::Hotel(const string& n, const string& d) : nombre(n), direccion(d), n_habitaciones(0) {}

// Agregar habitación al hotel
void Hotel::agregarHab(Habitacion* hab) {
    habitaciones.push_back(hab); // Se agrega el apuntador hab al vector habitaciones
    n_habitaciones++; // Incrementa el número de habitaciones en el hotel
}

// Obtener una lista de las habitaciones disponibles en el hotel
void Hotel::buscarHabDisp() const {
    cout << endl;
    cout << "Habitaciones disponibles:" << endl;
    // Ciclo for que itera sobre los punteros en el vector habitaciones
    for (const auto& hab : habitaciones) {
        // Si getDisponibilidad regresa verdadero, se mostrará la información de la habitación
        if (hab->getDisponibilidad()) {
            hab->mostrarDetalles();
        }
    }
}

// Información del hotel
void Hotel::mostrarDetalles() const {
    cout << endl;
    cout << "Hotel: " << nombre << endl;
    cout << "Dirección: " << direccion << endl;
    cout << "Número de habitaciones: " << n_habitaciones << endl;
}

// Obtener la lista de habitaciones de un hotel
void Hotel::imprimeHabitaciones() {
    for (Habitacion* ptr : habitaciones) {
        ptr->mostrarDetalles();
    }
}

// Clase Reservación

class Reservacion {
// Variables de instancia privadas
private:
    string id;
    int n_noches;
    double costoTotal;
    Cliente cliente;
    Habitacion* habitacion; // Apuntador de tipo Habitacion
    Hotel* hotel; // Apuntador de tipo Hotel

// Métodos públicos
public:
    Reservacion(const Cliente& c, Habitacion* h, Hotel* ho); // Constructor por omisión
    Reservacion(const string& i, int nn, const Cliente& c, Habitacion* h, Hotel* ho);
    void mostrarDetalles() const;
    void calcularCosto();
    void confirmaReservacion();
    // Getters y Setters
    string getID() const {return id;};
    int getNoches() const {return n_noches;};
    double getCostoT() const {return costoTotal;};
    void setID(const string& i) {id = i;};
    void setNoches(int nn) {n_noches = nn;};
};

// Implementación de métodos Reservación

Reservacion::Reservacion(const Cliente& c, Habitacion* h, Hotel* ho) : id("R003"), n_noches(5), cliente(c), habitacion(h), hotel(ho) {}

Reservacion::Reservacion(const string& i, int nn, const Cliente& c, Habitacion* h, Hotel* ho)
    : id(i), n_noches(nn), cliente(c), habitacion(h), hotel(ho) {
    calcularCosto();
}

// Información de la reservación de un cliente en un hotel
void Reservacion::mostrarDetalles() const {
    cout << "ID: " << id <<endl;
    cout << "Número de noches: " << n_noches << endl;
    cout << "Costo Total: " << costoTotal << endl;
    cliente.mostrarDetalles();
    cout << "Hotel: " << hotel->getNombre() << endl;
    habitacion->mostrarDetalles();
    cout << endl;
}

// Cálculo del costo total según el número de noches
void Reservacion::calcularCosto() {
    costoTotal = habitacion->calcularPrecio();
    cout << "Precio por noche en la habitación " << habitacion->getNumero() << ": $" << costoTotal << endl;
    costoTotal = (habitacion->getPrecio())*n_noches;
    cout << "Total: $" << costoTotal << endl;
}

// Confirmación de la reservación del cliente
void Reservacion::confirmaReservacion() {
    // Se verifica que el apuntador habitacion no sea nulo
    if (habitacion == nullptr) {
        cout << "Error: No se puede confirmar la reservación debido a una habitación inválida." << endl;
        return;
    }
    // Se verifica la disponibilidad de la habitación 
    if (habitacion->getDisponibilidad()) {
        habitacion->cambiarDisp(); //Cambia el valor de disponibilidad a falso
        calcularCosto(); // Se calcula el costo de la reservación
        cout << "Reservación de " << cliente.getNombre() << " confirmada." << endl;
    } else {
        cout << "La habitación no está disponible." << endl;
    }
}

#endif
