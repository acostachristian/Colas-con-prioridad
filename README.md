# Colas-con-prioridad

PROBLEMA COLA CON PRIORIDAD

En el aeropuerto de Ciudad Gótica, los aviones pueden aterrizar en sus pistas de acuerdo a la prioridad que maneje el vuelo. Los que tengan un número de prioridad más bajo se van atendiendo primero. Así si un vuelo tiene prioridad 0 será el primero en aterrizar, luego el que tenga prioridad inmediatamente superior y ocupe la posición mas cercana a la cabeza tendrá derecho a utilizar la pista. Al considerar la prioridad para entrar en la
cola, la prioridad se compara con la posición que ocupa cada nodo (avión), de modo que la posición del nodo (avión) es la que demanda la prioridad. En el caso de que no existan suficientes vuelos para insertar en la posición que demanda la prioridad, el nuevo vuelo se insertara al final. Los vuelos con prioridad a 16 o superiores se atenderán según la prioridad default (16), es decir, que todo vuelo con prioridad igual o superior a 16 se insertaran en la cola inmediatamente después del que ocupe la última posición en la cola. 

Utilizando la siguiente estructura para el nodo
struct Nodo {
int vuelo;
int prioridad;
Nodo *next;
};

RESTRICCIONES

Haga un programa C++ que permita manejar la pista de aterrizaje del aeropuerto de Ciudad Gótica, sabiendo que, el programa debe insertar (encolar = Enqueue) los vuelos en la cola priorizada según se describió anteriormente.

1- Tenga en consideración que un vuelo puede aparecer más de una vez en la cola. El programa debe permitir autorizar el aterrizaje del vuelo que esté en la cabeza de la cola priorizada al seleccionar Desencolar = Dequeue.

2- En el caso de tratar de autorizar el aterrizaje cuando la cola no contenga vuelos, el programa debe notificar al usuario de que la cola esta vacía.

3- De igual manera, el programa debe poder mostrar los vuelos según el orden en la cola realizando dequeue. En el caso de que no haya vuelos debe notificar que la cola esta vacía.

4- El programa debe contener un menú donde se ofrezcan las opciones para realizar las operaciones además de la opción de salir del programa (Enqueue, Dequeue, Mostrar, Salir).
