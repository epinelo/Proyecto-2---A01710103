#include "hotel.h"

int main() {
    // Crear habitaciones
    HabitacionSimple* hab1 = new HabitacionSimple(101, true, "Especial");
    HabitacionDoble* hab2 = new HabitacionDoble(202, true, "Normal", true);
    Suite* hab3 = new Suite(303, true, "Especial", 3);

    // Crear un hotel y agregar las habitaciones
    Hotel hotel("Hotel Fantasía", "123 Calle Principal");
    hotel.agregarHab(hab1);
    hotel.agregarHab(hab2);
    hotel.agregarHab(hab3);

    // Mostrar detalles del hotel
    hotel.mostrarDetalles();
    hotel.buscarHabDisp();

    hab1->calcularPrecio();
    hab2->calcularPrecio();
    hab3->calcularPrecio();

    // Crear clientes
    Cliente cliente1("Juan Pérez", "55 1234 5678", "juan.perez@example.com");
    Cliente cliente2("Ana López", "55 9284 5762", "ana.lopez@example.com");

    // Mostrar detalles de los clientes
    cliente1.mostrarDetalles();
    cliente2.mostrarDetalles();

    // Crear reservas
    Reserva reserva1("R001", 3, cliente1, hab1, &hotel);
    Reserva reserva2("R002", 5, cliente2, hab3, &hotel);

    // Mostrar detalles de las reservas
    reserva1.mostrarDetalles();
    reserva2.mostrarDetalles();

    // Confirmar reservas
    reserva1.confirmaReserva();
    reserva2.confirmaReserva();

    // Mostrar detalles del hotel después de las reservas
    hotel.buscarHabDisp();

    // Limpiar memoria
    delete hab1;
    delete hab2;
    delete hab3;

    return 0;
}
