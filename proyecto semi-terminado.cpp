#include <iostream>
#include <cstring> // Para usar strlen

using namespace std;

int main() {
    char libros[5][30];        // Vector para almacenar nombres de 5 libros
    int codigosLibros[5];      // Vector para almacenar los códigos de los libros
    float precios[5];          // Vector para almacenar el precio de los libros
    int disponible[5];         // Estado de disponibilidad (1: disponible, 0: no disponible)

    char estudiante[30];       // Almacena el nombre del estudiante (con o sin espacios)
    int codigoEstudiante;      // Almacena el código único del estudiante
    int opcion;
    int libroSeleccionado;
    int cantidad;

    // Inicializando el vector de libros
    for (int i = 0; i < 5; i++) {
        disponible[i] = 1;  // Todos los libros están disponibles inicialmente (1)
    }

    do {
        // Mostrar menú
        cout << "\n--- Sistema de Préstamos de Biblioteca ---" << endl;
        cout << "1. Registrar libros" << endl;
        cout << "2. Registrar estudiante" << endl; // Cambiar a singular
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
                cout<<"cuantos libros desea registrar"<<endl;
                cin>>cantidad;
                for (int i = 0; i < cantidad; i++) {
                    cout << "Ingrese el nombre del libro " << i + 1 << ": ";
                    cin >> libros[i];  // Almacenar nombre del libro (sin espacios)

                    cout << "Ingrese el código del libro " << i + 1 << ": ";
                    cin >> codigosLibros[i];  // Almacenar código del libro

                    cout << "Ingrese el precio del libro " << i + 1 << ": ";
                    cin >> precios[i];  // Almacenar precio del libro

                    disponible[i] = 1;  // Marcamos el libro como disponible (1)
                }
                break;
            }
            case 2: {
                // Registrar estudiante
                cout << "\n--- Registrar Estudiante ---" << endl;
                cout << "Ingrese el nombre del estudiante: ";
                cin.ignore(); // Ignorar el salto de línea anterior
                cin.getline(estudiante, 30); // Permitir nombre con espacios

                cout << "Ingrese el código único del estudiante: ";
                cin >> codigoEstudiante;  // Almacenar código único del estudiante

                break;
            }
            case 3: {
                // Prestar libro a estudiante
                cout << "\n--- Prestar Libro a Estudiante ---" << endl;
                cout << "Ingrese el código del estudiante: ";
                cin >> codigoEstudiante;

                // Verificar si el estudiante está registrado (aquí se asume que siempre está)
                cout << "Ingrese el número del libro a prestar (1-5): ";
                cin >> libroSeleccionado;

                if (libroSeleccionado >= 1 && libroSeleccionado <= 5) {
                    if (disponible[libroSeleccionado - 1] == 1) {
                        disponible[libroSeleccionado - 1] = 0;  // Marcar como no disponible (0)
                        cout << "Libro " << libros[libroSeleccionado - 1] << " ha sido prestado al estudiante " << estudiante << "." << endl;
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
                    if (disponible[libroSeleccionado - 1] == 0) {
                        disponible[libroSeleccionado - 1] = 1;  // Marcar como disponible (1)
                        cout << "Libro " << libros[libroSeleccionado - 1] << " ha sido devuelto." << endl;
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
                    cout << "Libro " << i + 1 << ": " << libros[i] << ", Código: " << codigosLibros[i] 
                         << ", Precio: " << precios[i] << ", Disponible: " 
                         << (disponible[i] == 1 ? "Sí" : "No") << endl;
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

