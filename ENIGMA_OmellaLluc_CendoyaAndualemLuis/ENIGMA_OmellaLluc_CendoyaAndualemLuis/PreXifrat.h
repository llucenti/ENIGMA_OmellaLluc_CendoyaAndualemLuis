#pragma once
#include <string>

//Inicialització funcions
void asignacioRotors(std::string& rotor1, std::string& rotor2, std::string& rotor3, std::string& notchRot1, std::string& notchRot2, std::string& notchRot3);
void editarRotors(std::string rotor1, std::string rotor2, std::string rotor3, std::string notchRotor1, std::string notchRotor2, std::string notchRotor3);
void menuPrincipal(short opcio, std::string missatge, std::string rotor1, std::string rotor2, std::string rotor3, std::string notchRot1, std::string notchRot2, std::string notchRot3, bool notchRot1Trobat, bool notchRot2Trobat, std::string textXifrat);
void definirPosicionsInicials(std::string& rot1, std::string& rot2, std::string& rot3);
