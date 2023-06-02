#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <vector>
#include <iostream>
#include "login.h"
using namespace std;

class usuario {
    private: string username;
    int password;
    int color;
    int intensity;

    public: usuario();

    usuario(string username, int password, int color, int intensity) {
        this -> username = username;
        this -> password = password;
        this -> color = color;
        this -> intensity = intensity;
    }

    string getUsuario() {
        return this -> username;
    }

    int getContra() {
        return this -> password;
    }

    int getColor() {
        return this -> color;
    }

    int getIntensity() {
        return this -> intensity;
    }

    void editUsuario(string username, int password, int color, int intensity) {
        this -> username = username;
        this -> password = password;
        this -> color = color;
        this -> intensity = intensity;
    }

};

#endif