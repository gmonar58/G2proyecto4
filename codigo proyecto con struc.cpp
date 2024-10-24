#include <iostream>
#include <cstring> // Para usar strlen

using namespace std;

// Definición del struct para un libro
struct Libro {
    char titulo[30];       // Almacenar nombre del libro
    int codigo;            // Almacenar código único del libro
    float precio;          // Almacenar el precio del libro
    int disponible;        // Estado de disponibilidad (1: disponible, 0: no disponible)
};

// Definición del struct para un estudiante
struct Estudiante {
    char nombre[30];       // Almacenar nombre del estudiante
    int codigo;            // Almacenar código único del estudiante
};

int main() {
    // Crear un array de 5 libros
    Libro libros[5];  // Cada libro es un struct
    Estudiante estudiante;  // Un único estudiante
    int opcion;
    int libroSeleccionado;
    int cantidad;

    // Inicializando los libros para que estén disponibles (disponible = 1)
    for (int i = 0; i < 5; i++) {
        libros[i].disponible = 1;
    }

    do {
        // Mostrar menú
        cout << "\n--- Sistema de Préstamos de Biblioteca ---" << endl;
        cout << "1. Registrar libros" << endl;
        cout << "2. Registrar estudiante" << endl;
        cout << "3. Prestar libro a estudiante" << endl;
        cout << "4. Devolver libro" << endl;
        cout << "5. Ver libros registrados" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Registrar libros
                cout << "\n--- Registrar Libros ---" << endl;
                cout << "¿Cuántos libros desea registrar? (máximo 5): ";
                cin >> cantidad;

                for (int i = 0; i < cantidad; i++) {
                    cout << "Ingrese el nombre del libro " << i + 1 << ": ";
                    cin >> libros[i].titulo;  // Almacenar nombre del libro (sin espacios)

                    cout << "Ingrese el código del libro " << i + 1 << ": ";
                    cin >> libros[i].codigo;  // Almacenar código del libro

                    cout << "Ingrese el precio del libro " << i + 1 << ": ";
                    cin >> libros[i].precio;  // Almacenar precio del libro

                    libros[i].disponible = 1;  // Marcamos el libro como disponible (1)
                }
                break;
            }
            case 2: {
                // Registrar estudiante
                cout << "\n--- Registrar Estudiante ---" << endl;
                cout << "Ingrese el nombre del estudiante: ";
                cin.ignore();  // Ignorar el salto de línea anterior
                cin.getline(estudiante.nombre, 30);  // Permitir nombre con espacios

                cout << "Ingrese el código único del estudiante: ";
                cin >> estudiante.codigo;  // Almacenar código único del estudiante

                break;
            }
            case 3: {
                // Prestar libro a estudiante
                cout << "\n--- Prestar Libro a Estudiante ---" << endl;
                cout << "Ingrese el código del estudiante: ";
                cin >> estudiante.codigo;

                cout << "Ingrese el número del libro a prestar (1-5): ";
                cin >> libroSeleccionado;

                if (libroSeleccionado >= 1 && libroSeleccionado <= 5) {
                    if (libros[libroSeleccionado - 1].disponible == 1) {
                        libros[libroSeleccionado - 1].disponible = 0;  // Marcar como no disponible (0)
                        cout << "Libro " << libros[libroSeleccionado - 1].titulo << " ha sido prestado al estudiante " << estudiante.nombre << "." << endl;
                    } else {
                        cout << "El libro no está disponible." << endl;
                    }
                } else {
                    cout << "Número de libro inválido." << endl;
                }
                break;
            }
            case 4: {
                // Devolver libro
                cout << "\n--- Devolver Libro ---" << endl;
                cout << "Ingrese el número del libro a devolver (1-5): ";
                cin >> libroSeleccionado;

                if (libroSeleccionado >= 1 && libroSeleccionado <= 5) {
                    if (libros[libroSeleccionado - 1].disponible == 0) {
                        libros[libroSeleccionado - 1].disponible = 1;  // Marcar como disponible (1)
                        cout << "Libro " << libros[libroSeleccionado - 1].titulo << " ha sido devuelto." << endl;
                    } else {
                        cout << "El libro ya estaba disponible." << endl;
                    }
                } else {
                    cout << "Número de libro inválido." << endl;
                }
                break;
            }
            case 5: {
                // Ver libros registrados
                cout << "\n--- Libros Registrados ---" << endl;
                for (int i = 0; i < 5; i++) {
                    cout << "Libro " << i + 1 << ": " << libros[i].titulo << ", Código: " << libros[i].codigo 
                         << ", Precio: " << libros[i].precio << ", Disponible: " 
                         << (libros[i].disponible == 1 ? "Sí" : "No") << endl;
                }
                break;
            }
            case 6:
                // Salir del sistema
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}
