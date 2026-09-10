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
    for (int i = 0; i < (pPrioridad); i++)
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

void Dequeue(Nodo*& frente, Nodo*& fin)
{ 
  // Si frente es NULL, significa que no hay ningun nodo enlazado, es decir,
  // no hay vuelos esperando para aterrizar.
    if (frente == NULL)
    {
        cout << "La cola esta vacia. No hay vuelos en espera para aterrizar." << endl;
        return;
    }

    // Antes de mover frente hacia el siguiente nodo, guardamos su direccion
    // actual en nodoAEliminar. 
    Nodo* nodoAEliminar = frente;

    cout << "Autorizando aterrizaje del vuelo " << frente->vuelo
        << " (prioridad " << frente->prioridad << ")." << endl;

    // El frente de la cola avanza al siguiente nodo.
    frente = frente->next;

    // Si al avanzar frente este quedo en NULL, significa que el nodo que
    // acabamos de sacar era el unico que quedaba en la cola. 
    if (frente == NULL)
    {
        fin = NULL;
    }

    delete nodoAEliminar;
}

void Mostrar(Nodo *frente)
{
    if (frente == NULL)
    {
        cout << "La cola esta vacia. No hay vuelos en espera." << endl;
        return;
    }

    cout << "\n=== Vuelos en espera de aterrizaje ===" << endl;
    cout << "Posicion | Vuelo | Prioridad" << endl;
    cout << "---------|-------|----------" << endl;

    Nodo *actual = frente;
    int posicion = 1;

    while (actual != NULL)
    {
        cout << posicion << "        | " << actual->vuelo << "     | " << actual->prioridad << endl;
        actual = actual->next;
        posicion++;
    }
    cout << "\nTotal de vuelos en espera: " << (posicion - 1) << endl;
}

void LimpiarPantalla()
{
    cout << "\n";
    cout << "Presione ENTER para continuar...";
    cin.ignore();
    cin.get();
    cout << "\033[2J\033[1;1H"; // Limpia la pantalla (funciona en Linux/Mac)
}

// Función para validar entrada entera
int ObtenerEnteroValido(const string& mensaje)
{
    int valor;
    string entrada;
    bool valido = false;

    while (!valido)
    {
        cout << mensaje;
        cin >> entrada;

        // Limpiar el buffer de entrada en caso de que haya caracteres extra
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
        }

        // Validar que la entrada sea un número entero válido
        valido = true;
        for (int i = 0; i < entrada.length(); i++)
        {
            // Permitir signo negativo al inicio
            if (i == 0 && entrada[i] == '-')
            {
                continue;
            }
            // El resto deben ser dígitos
            if (!isdigit(entrada[i]))
            {
                valido = false;
                break;
            }
        }

        if (!valido)
        {
            cout << "ERROR: Entrada no valida. Por favor, ingrese un numero entero valido." << endl;
            continue;
        }

        // Convertir la entrada validada a entero
        valor = stoi(entrada);
        break;
    }

    return valor;
}

// Función para validar la opción del menú
int ObtenerOpcionValida()
{
    int opcion;
    string entrada;
    bool valido = false;

    while (!valido)
    {
        cout << "Seleccione una opcion (1-4): ";
        cin >> entrada;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
        }

        valido = true;
        for (int i = 0; i < entrada.length(); i++)
        {
            if (!isdigit(entrada[i]))
            {
                valido = false;
                break;
            }
        }

        if (!valido)
        {
            cout << "ERROR: Entrada no valida. Por favor, ingrese un numero entre 1 y 4." << endl;
            continue;
        }

        opcion = stoi(entrada);

        if (opcion < 1 || opcion > 4)
        {
            cout << "ERROR: Opcion fuera de rango. Por favor, ingrese un numero entre 1 y 4." << endl;
            valido = false;
            continue;
        }

        break;
    }

    return opcion;
}
int main()
{
  bool continuar = true;
    Nodo* frente = NULL;
    Nodo* fin = NULL;
    
    while (continuar)
    {
        cout << "\n========================================" << endl;
        cout << "Sistema del Aeropuerto de Ciudad Gotica" << endl;
        cout << "========================================" << endl;
        cout << "1. Agregar vuelo a la cola de aterrizaje (Enqueue)" << endl;
        cout << "2. Autorizar aterrizaje del siguiente vuelo (Dequeue)" << endl;
        cout << "3. Mostrar vuelos en espera" << endl;
        cout << "4. Salir" << endl;
        cout << "----------------------------------------" << endl;
        
        int opcion = ObtenerOpcionValida();
        cout << "\n";
        
        switch (opcion)
        {
        case 1: // Lógica para agregar vuelo
        {
            int numeroVuelo, prioridad;
            
            numeroVuelo = ObtenerEnteroValido("Ingrese el numero del vuelo: ");
            
            // Validar que el número de vuelo sea positivo
            if (numeroVuelo <= 0)
            {
                cout << "ERROR: El numero de vuelo debe ser un numero positivo." << endl;
                LimpiarPantalla();
                break;
            }
            
            prioridad = ObtenerEnteroValido("Ingrese la prioridad del vuelo (0-16+): ");
            
            Enqueue(frente, fin, numeroVuelo, prioridad);
            
            if (prioridad > 16)
            {
                cout << "Vuelo " << numeroVuelo << " agregado a la cola con prioridad default (16)." << endl;
            }
            else if (prioridad < 0)
            {
                cout << "Vuelo " << numeroVuelo << " agregado a la cola con prioridad ajustada (0)." << endl;
            }
            else
            {
                cout << "Vuelo " << numeroVuelo << " agregado a la cola con prioridad " << prioridad << "." << endl;
            }
            
            LimpiarPantalla();
            break;
        }
        case 2: // Lógica para autorizar aterrizaje
        {
            Dequeue(frente, fin);
            LimpiarPantalla();
            break;
        }
        case 3: // Lógica para mostrar vuelos en espera
        {
            Mostrar(frente);
            LimpiarPantalla();
            break;
        }
        case 4:
        {
            cout << "Gracias por usar el sistema del Aeropuerto de Ciudad Gotica." << endl;
            continuar = false;
            break;
        }
        }
    }
}
