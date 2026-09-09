/*
10/9/26
Grupo 1:
- Alessandro Salamone - 1132116
- Carlos Minaya - 1132836
- Axel Almonte - 1131078
- ⁠Octavio Ramírez - 1132995
- ⁠José Pinales - 1133255
- Christian Acosta - 1132698

Haga un programa C++ que permita manejar la pista de aterrizaje del aeropuerto de
Ciudad Gótica, sabiendo que, el programa debe insertar (encolar = Enqueue) los vuelos
en la cola priorizada según se describió anteriormente..
*/

#include <iostream>
using namespace std;

struct Nodo
{
  int vuelo;
  int prioridad;
  Nodo *next;
};

int ContarNodos(Nodo *frente)
{ // para determinar cuantos nodos hay en la cola.
  int contador = 0;
  Nodo *actual = frente;

  while (actual != NULL)
  {
    contador++;
    actual = actual->next;
  }

  return contador;
}

void Enqueue(Nodo *&frente, Nodo *&fin, int pVuelo, int pPrioridad)
{ // frente es por donde se sale y fin es por donde se entra
  Nodo *nuevoNodo = new Nodo();

  nuevoNodo->vuelo = pVuelo;
  if (pPrioridad > 16)
  {
    pPrioridad = 16;
  }
  else if (pPrioridad < 0)
  {
    pPrioridad = 0;
  }
  nuevoNodo->prioridad = pPrioridad;

  //[[Auxiliares para recorrer la cola]]
  Nodo *nodoActual = frente;
  Nodo *nodoAnterior = NULL;

  int cantidadNodos = ContarNodos(frente);

  if (frente == NULL)
  {
    frente = nuevoNodo;
    fin = nuevoNodo;
    nuevoNodo->next = NULL;
    return;
  }

  // Se recorre la cola, y se guarda el nodoAnterior a donde se insertara nuevoNodo
  // y nodoActual sera el que va siguiente a nuevoNodo
  else if (pPrioridad <= cantidadNodos)
  {
    for (int i = 0; i < (pPrioridad - 1); i++)
    {
      nodoAnterior = nodoActual;
      nodoActual = nodoActual->next;
    }

    if (frente == nodoActual)
    {
      frente = nuevoNodo;
    }
    else
    {
      nodoAnterior->next = nuevoNodo;
    }

    nuevoNodo->next = nodoActual;

    if (nodoActual == NULL)
    {
      fin = nuevoNodo;
    }
  }
  else
  {
    fin->next = nuevoNodo;
    fin = nuevoNodo;
    nuevoNodo->next = NULL;
  }
}

int main()
{
  return 0;
}
