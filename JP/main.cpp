#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "login.h"
#include "usuario.h"





int main() {
    login loginx;
    bool superadm = false, logged = false;
    string username;
    int password, op, color, intensity;
    string activeUsername;
    

    do {

        do {

            cout << "Digite sus credenciales" << endl;
            cout << "Digite el usuario" << endl;
            cin >> username;
            activeUsername=username;
            cout << "Digite la password" << endl;
            cin >> password;

            if (loginx.isCorrect(username, password)) {
                if (username == "mora" && password == 123) {
                    cout << "El usuario es correcto" << endl;
                    superadm = true;
                    logged = true;
                } else {
                    logged = true;
                }
            } else {
                system("cls");
                cout << "Usuario incorrecto, intente denuevo" << endl;
            }

        } while (!superadm && !logged);

        if (superadm)
            cout << "Usted logeo como superadm" << endl;
        else
            cout << "Usted logeo como usuario" << endl;

        if (superadm) {
            do {
                cout << "1.Register" << endl;
                cout << "2.Delete user" << endl;
                cout << "3.Edit user" << endl;
                cout << "4.Main menu" << endl;
                cout << "5.Show users" << endl;
                cout << "6.Exit" << endl;

                cin >> op;

                switch (op) {

                case 1: { //REGISTRAR
                    if (superadm) {
                        cout << "Digite el usuario" << endl;
                        cin >> username;
                        cout << "Digite la password" << endl;
                        cin >> password;
                        cout << "\t\t\t\t Define the light color: " << endl;
                        cout << "\t\t\t\t Colors available: " << endl;
                        cout << "\t\t\t\t 1 = Blue" << endl;
                        cout << "\t\t\t\t 2 = Green" << endl;
                        cout << "\t\t\t\t 3 = Red " << endl;
                        cout << "\t\t\t\t 4 = Purple" << endl;
                        cout << "\t\t\t\t 5 = Yellow " << endl;
                        cout << "\t\t\t\t 6 = White " << endl;
                        cout << "Digite el color" << endl;
                        cin >> color;
                        cout << "Digite la intensidad (0-100)" << endl;
                        cin >> intensity;
                        usuario temp(username, password, color, intensity);
                        loginx.addUser(temp);
                        break;
                    } else {
                        cout << "Usted no es superadm" << endl;
                    }

                    break;
                }

                case 2: {
                    if (superadm) {
                        loginx.deleteUser();
                        break;
                    } else {
                        cout << "Usted no es superadm" << endl;
                    }

                }

                case 3: {
                    if (superadm) {
                        loginx.editUser();
                        break;
                    } else {
                        cout << "Usted no es superadm" << endl;
                    }

                }

                case 4: {
                    superadm = false;
                    logged = false;
                    break;
                }

                case 5: {
                    system("cls");
                    loginx.showUsers();
                    break;
                }

                default:
                    cout << "Opcion incorrecta" << endl;
                    break;

                }

            } while (op != 4 && op != 6);

        } else {

            do{
            cout << "1.Automatico" << endl;
            cout << "2.Horario" << endl;
            cout << "4.Main menu" << endl;
            cout << "6.Exit" << endl;
            cin >> op;
            switch (op){
                    case 1:
                    loginx.automatic(activeUsername);
                    break;

                    case 2:
                    loginx.clock(activeUsername);
                    break;

                    case 4:
                    system("CLS");
                    break;
                    

                    case 6:
                    system("CLS");
                    break;

                    

                    default:
                    cout<<"Opcion incorrecta" << endl;
            } 

            if (op == 4)
            logged = false;

            } while (op != 4 && op != 6);
        }
    }
    while (op != 6);

    return 0;
}