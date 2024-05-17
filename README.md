Emilio Pinelo Landarte - A01710103

TC.1030.301 Proyecto POO 

# SISTEMA DE RESERVACIONES DE CADENA HOTELERA

## CONTEXTO/UML (Avance 1)
Para este proyecto decidí crear un sistema de reservaciones de una cadena hotelera. La idea principal del programa es generar una serie de reservaciones de hotel para los clientes de diferentes hoteles. El cliente tendrá la opción de elegir el tipo de habitación que deseé y se le hará la cotización y confirmación de su reservación con los métodos correspondientes. El programa está sujeto a cambios indefinidos y hay detalles que se deben afinar en las próximas semanas para lograr el objetivo. Detalles que podrían provocar errores en el programa, como el tipo de atributos y/o métodos utilizados, la definición de las clases y las relaciones entre estas o algunos métodos que podrían funcionar de forma diferente o no funcionar correctamente. 

El programa tiene como base 7 clases diferentes: Hotel, Habitacion, HabitancionSimple, HabitacionDoble, Suite, Cliente y Reserva. Donde la clase Hotel está compuesta por una serie de habitaciones, sabiendo que un hotel debe tener habitaciones para cumplir con su funcionamiento, y la clase base Habitacion tiene una relación de herencia con las clases derivadas HabitacionSimple, Habitacion Doble y Suite, debido a que las clases derivadas son los tipos de habitación con las que el hotel puede contar. La clase Cliente tiene una relación de agregación con la clase Hotel, pues el hotel no depende del cliente para ser un hotel, pero es una parte importante para la actividad en este. Finalmente, la clase Reserva está asociada con las clases Cliente, Habitacion y Hotel, pues para realizar una reservación se necesita información sobre el cliente, como el nombre y el número de teléfono, sobre la habitación reservada, como el tipo de habitación, y sobre el hotel, como en que hotel de la cadena se realizó la reservación. 
