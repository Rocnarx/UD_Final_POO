#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>

#include <vector>

#include <string>

#include <thread>

#include <chrono>

#include <conio.h>

#include <cstdlib>

#include <time.h>

#include <windows.h>

#include "usuario.h"

using namespace std;

using namespace std::chrono;

class login {
    private: usuario superAdmin {
        "mora",
        123,
        0,
        10

    };
    vector < usuario > listaUsuarios {
        superAdmin
    };

    public:

        void addUser(usuario user) {
            listaUsuarios.push_back(user);
            cout << "Usuario añadido" << endl;
        }

    bool isCorrect(string user, int pass) {
        for (auto & element: listaUsuarios) {
            if (user == element.getUsuario() && pass == element.getContra()) {
                system("cls");
                return true;
            }
        }
        return false;
    }

    void editUser() {
        string user;
        int pass, color, intensity;
        cout << "Digite el usuario a cambiar" << endl;
        cin >> user;
        for (auto & element: listaUsuarios) {

            if (user == element.getUsuario()) {
                cout << "Digite el nuevo usuario" << endl;
                cin >> user;
                cout << "Digite la nueva contrasena" << endl;
                cin >> pass;
                cout << "Digite el nuevo color" << endl;
                cin >> color;
                cout << "Digite la nueva intensidad" << endl;
                cin >> intensity;
                element.editUsuario(user, pass, color, intensity);
            }
        }
    }

    void showUsers() {
        for (auto & element: listaUsuarios) {
            cout << "usuario: " << element.getUsuario() << " contrasena: " << element.getContra() << " color: " << element.getColor() << " intensity: " << element.getIntensity() << endl;
        }
    }

    void deleteUser() {
        string user;
        int contador = 0;
        cout << "Digite el usuario a eliminar" << endl;
        cin >> user;

        for (auto & element: listaUsuarios) {
            if (element.getUsuario() == user && user != "mora") {
                listaUsuarios.erase(listaUsuarios.begin() + contador);
                system("cls");
                cout << "Usuario borrado" << endl;
                return;

            }
            contador++;
        }
        cout << "Usuario no encontrado" << endl;
        return;
    }


    void automatic (string user){

         int fin = 0;
         int op;
         cout << "Cuantas habitaciones desea" << endl;
    int room; cin>>room;
    for (int i=0; i < room; i++  ){
    system("cls");

for (auto & element: listaUsuarios) {
            if (element.getUsuario() == user) {
                op = element.getColor();
            }
        }

        switch (op) {
        case 1:
            system("color 19");
            break;
        case 2:
            system("color A2");
            break;
        case 3:
            system("color C4");
            break;
        case 4:
            system("color D5");
            break;
        case 5:
            system("color E6");
            break;
        case 6:
            system("color F7");
            break;

        }
    Sleep(1);
    system("cls");
    system("color 0F");
    Sleep(1);
    system("cls");
    }
    
    return;
    }


    void clock(string user) {
        int segundos = 0;
        int minutos = 0;
        int horas = 0;
        int fin = 0;
        int op;

        cout << "Ingrese las horas" << endl;
        cin >> horas;
        cout << "Ingrese los minutos" << endl;
        cin >> minutos;
        cout << "Ingrese los segundos" << endl;
        cin >> segundos;

        for (auto & element: listaUsuarios) {
            if (element.getUsuario() == user) {
                op = element.getColor();
            }
        }

        switch (op) {
        case 1:
            system("color 19");
            break;
        case 2:
            system("color A2");
            break;
        case 3:
            system("color C4");
            break;
        case 4:
            system("color D5");
            break;
        case 5:
            system("color E6");
            break;
        case 6:
            system("color F7");
            break;

        }

        for (auto & element: listaUsuarios) {
            if (element.getUsuario() == user) {
                cout << "Brillo establecido en: " << element.getIntensity() << endl;
            }
        }

        while (fin == 0) {
            system("cls");
            cout << horas << ":" << minutos << ":" << segundos << endl;
            Sleep(1000);
            segundos--;
            if (minutos == 0 && segundos == 0 && horas == 0) {
                fin = 1;
            }
            if (minutos == 0 && segundos == 0) {
                horas--;
                minutos = 59;
                segundos = 60;
            }
            if (segundos == 0) {
                minutos--;
                segundos = 60;
            }
        }
        system("color 0F");
        system("cls");
        cout << "Brillo reestablecido en 100" << endl;

        return;

    }

};

#endif