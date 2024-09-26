#include <iostream>

using namespace std;

int main() {
    int codigo;
    string nombre;
    int menu = 0;

    cout << "♣ Bienvenido a la Central de Préstamos de la Universidad ♣" << endl;
    cout << "Ingrese su código, por favor: ";
    cin >> codigo;
    cout << "Ingrese su nombre y apellido, por favor (sin espacios): ";
    cin >> nombre; // Se asume que el nombre no contiene espacios

    do {
        cout << "\nSeleccione una opción del menú:\n";
        cout << "1. Agregar un recurso\n";
        cout << "2. Agregar un estudiante\n";
        cout << "3. Mirar los recursos disponibles\n";
        cout << "4. Consultar los recursos de los estudiantes\n";
        cout << "5. Consultar la información de un préstamo\n";
        cout << "6. Devolver un recurso prestado\n";
        cout << "7. Salir\n";
        cout << "Ingrese su opción: ";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Desea agregar un recurso\n";
                break;
            case 2:
                cout << "Desea agregar un estudiante\n";
                break;
            case 3:
                cout << "Desea mirar los recursos disponibles\n";
                break;
            case 4:
                cout << "Consultar los recursos de los estudiantes\n";
                break;
            case 5:
                cout << "Consultar la información de un préstamo\n";
                break;
            case 6:
                cout << "Devolver un recurso prestado\n";
                break;
            case 7:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Debes elegir una opción válida\n";
        }
    } while (menu != 7);

    return 0;
}
