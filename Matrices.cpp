#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream archivo2023("input/ingresos-2023.csv");
    ifstream archivo2024("input/ingresos-2024.csv");
    ifstream archivo2025("input/ingresos-2025.csv");

    if (!archivo2023 || !archivo2024 || !archivo2025) {
        cout << "Error al abrir los archivos de entrada." << endl;
        return 1;
    }

    ofstream archivoOut("output/resultado.csv");
    if (!archivoOut) {
        cout << "Error al crear el archivo de salida." << endl;
        return 1;
    }
archivoOut << "Empresa,Total 2023,Total 2024,Total 2025,Total 3 Años\n";

    string linea, dato;

    for (int i = 0; i < 5; i++) {
        int suma2023 = 0;
        int suma2024 = 0;
        int suma2025 = 0;

        getline(archivo2023, linea);
        stringstream ss23(linea);
        for (int j = 0; j < 12; j++) {
            getline(ss23, dato, ',');
            suma2023 += stoi(dato);
        }

        getline(archivo2024, linea);
        stringstream ss24(linea);
        for (int j = 0; j < 12; j++) {
            getline(ss24, dato, ',');
            suma2024 += stoi(dato);
        }

        getline(archivo2025, linea);
        stringstream ss25(linea);
        for (int j = 0; j < 12; j++) {
            getline(ss25, dato, ',');
            suma2025 += stoi(dato);
        }

        int totalGeneral = suma2023 + suma2024 + suma2025;

        archivoOut << "Empresa " << (i + 1) << ","
                << suma2023 << ","
                << suma2024 << ","
                << suma2025 << ","
                << totalGeneral << "\n";
    }

    archivo2023.close();
    archivo2024.close();
    archivo2025.close();
    archivoOut.close();

    cout << "Proceso completado archivo generado con exito" << endl;

    return 0;
}
