/*
 * Proyecto POO TC1030 - Hotel implementación
 * Emilio Pinelo Landarte - A01710103
 * 14/06/2024
 * SISTEMA DE RESERVACIONES DE CADENA HOTELERA
 * En este archivo se define e implementa la clase Menu.
*/

#ifndef MENU_H
#define MENU_H

#include <iostream> // Para imprimir en la consola
#include <string> // Para manipulación de cadenas de caracteres
#include <vector> // Para el uso del contenedor vector
#include "Hotel.h" // Para el uso del contenido en el archivo hotel.h

using namespace std;

class Menu {
// Varibale de instancia y métodos del menú privados
private:
    vector<Hotel> hoteles; // Vector de hoteles

    void mostrarMenu();
    void mostrarDetallesHotel(Hotel& hotel);
    void agregarHabitacion(Hotel& hotel);
    void hacerReservacion(Hotel& hotel);

// Métodos públicos
public:
    Menu(); // Constructor por omisión
    void iniciar();
};

// Implementación de métodos Menu

Menu::Menu() {
    // Crear hoteles con el constructor por omisión de la clase Hotel
    // Se agregan los hoteles creados al vector hotel
    hoteles.push_back(Hotel());
    hoteles.push_back(Hotel("Hotel Fantasía", "123 Calle Principal"));
    hoteles.push_back(Hotel("IBIS", "Av Árbol"));
}

// Método para inicar la interacción con el usuario
void Menu::iniciar() {
    // Selección del hotel
    while (true) {
        cout << endl;
        cout << "Seleccione un hotel:" << endl;
        // Ciclo for que itera sobre el vector hoteles 
        for (size_t i = 0; i < hoteles.size(); ++i) {
            // Imprime una lista de los hoteles creados
            cout << i + 1 << ". " << hoteles[i].getNombre() << endl;
        }
        cout << hoteles.size() + 1 << ". Salir" << endl;
        cout << "Opción: ";
        int opcionHotel;
        // Lectura y verificación de la entrada
        // Mientras la entrada sea leída correctamente, sea menor que uno o mayor que el tamaño del vector + 1, se marcará error
        while (!(cin >> opcionHotel) || opcionHotel < 1 || opcionHotel > hoteles.size()+1) {
            cout << "Opción no válida. Introduzca nuevamente: ";
            cin.clear(); // Eliminar el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada incorrecta para volver a pedirla
        }

        if (opcionHotel == hoteles.size() + 1) {
            cout << "Finalizando..." << endl;
            return;
        }

        // Crear una referencia al hotel seleccionado para su manipulación
        Hotel& hotel = hoteles[opcionHotel - 1];

        // Menú del hotel seleccionado
        while (true) {
            mostrarMenu();
            cout << "Seleccione una opción: ";
            int opcion;
            // Lectura y verificación de la entrada
            // Mientras la entrada sea leída correctamente, sea menor que uno o mayor que 5, se marcará error
            while (!(cin >> opcion) || opcion < 1 || opcion > 5) {
                cout << endl;
                cout << "Opción no válida. Introduzca nuevamente: ";
                cin.clear(); // Eliminar el estado de error de cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada incorrecta para volver a pedirla
            }

            // Instrucciones para cada opción del menú
            switch (opcion) {
                case 1:
                    mostrarDetallesHotel(hotel);
                    break;
                case 2:
                    agregarHabitacion(hotel);
                    break;
                case 3:
                    hacerReservacion(hotel);
                    break;
                case 4:
                    // Regresa a la lista de hoteles
                    break;
                case 5:
                    // Fin del programa
                    cout << "Finalizando..." << endl;
                    return;
                default:
                    cout << endl;
                    cout << "Opción no válida" << endl;
            }
        }
    }
}

// Despliega el menú del hotel seleccionado
void Menu::mostrarMenu() {
    cout << endl;
    cout << "Menu:" << endl;
    cout << "1. Mostrar detalles del hotel" << endl;
    cout << "2. Agregar habitación" << endl;
    cout << "3. Hacer reservación" << endl;
    cout << "4. Regresar" << endl;
    cout << "5. Finalizar" << endl;
}

// Opción 1:
// Utiliza métodos de la clase Hotel para mostrar la información y las habitaciones del hotel seleccionado
void Menu::mostrarDetallesHotel(Hotel& hotel) {
    hotel.mostrarDetalles();
    hotel.imprimeHabitaciones();
}

// Agrega habitaciones al hotel seleccionado
void Menu::agregarHabitacion(Hotel& hotel) {
    int tipo;
    cout << endl;
    // Lista de tipos de habitaciones 
    cout << "Seleccione el tipo de habitación:" << endl;
    cout << "1. Simple" << endl;
    cout << "2. Doble" << endl;
    cout << "3. Suite" << endl;
    cout << "Opción: ";
    // Lectura y verificación de la entrada
    // Mientras la entrada sea leída correctamente, sea menor que uno o mayor que 3, se marcará error
    while (!(cin >> tipo) || tipo < 1 || tipo > 3) {
        cout << endl;
        cout << "Opción no válida. Introduzca nuevamente: ";
        cin.clear(); // Eliminar el estado de error de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada incorrecta para volver a pedirla
    }

    // Inicializa un apuntador de tipo Habitacion* nulo
    Habitacion* habitacion = nullptr;

    // Creación dinámica de un objeto de tipo Habitacion según la opción seleccionada
    switch (tipo) {
        case 1:
            habitacion = new HabitacionSimple(); // Crea una nueva HabitacionSimple
            break;
        case 2:
            habitacion = new HabitacionDoble(); // Crea una nueva HabitacionDoble
            break;
        case 3:
            habitacion = new Suite(); // Crea una nueva Suite
            break;
        default:
            cout << endl;
            cout << "Opción no válida" << endl;    
            return;                               
    }

    // Se agrega la habitación creada al hotel utilizando agregarHab de la clase Hotel
    hotel.agregarHab(habitacion);
    cout << endl;
    cout << "Habitación agregada exitosamente." << endl;
}

// Se genera la reservación del cliente
void Menu::hacerReservacion(Hotel& hotel) {
    // Crear un objeto de tipo Cliente por omisión
    Cliente cliente; 

    // Lista de habitaciones disponibles utilizando buscarHabDisp de la clase Hotel
    hotel.buscarHabDisp();

    int opcion;
    cout << "Seleccione una habitación para reservar:" << endl; 

    // Lectura y verificación de la entrada
    // Mientras la entrada sea leída correctamente, sea menor que uno o mayor que el número de habitaciones, se marcará error
    while (!(cin >> opcion) || opcion < 1 || opcion > hotel.getNhabitaciones()) {
        cout << "Opción no válida. Introduzca nuevamente: ";
        cin.clear(); // Eliminar el estado de error de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada incorrecta para volver a pedirla
    }

    // Se obtiene un puntero a la habitación seleccionada por el usuario 
    Habitacion* habitacion = hotel.getHabitaciones()[opcion - 1]; 

    // Si el apuntador sigue siendo nulo se marcará error
    if (habitacion == nullptr) {
        cout << "Error: Habitación no válida." << endl;
        return;
    }

    // Si la habitación no está disponible se marcará error
    if (!habitacion->getDisponibilidad()) {
        cout << "La habitación no está disponible." << endl;
        return;
    }

    // Se crea un objeto de tipo Reservacion por omisión
    Reservacion reservacion(cliente, habitacion, &hotel);

    // Se confirma la reservación utilizando confirmaReservacion() de la clase Reservacion 
    reservacion.confirmaReservacion(); 
}

#endif
