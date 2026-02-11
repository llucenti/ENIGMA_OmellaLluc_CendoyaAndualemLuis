#pragma once
#include <string>

//Inicialització funcions
void xifrarMissatge(std::string& missatge, std::string& rotor1, std::string& rotor2, std::string& rotor3, std::string notchRotor1, std::string notchRotor2, std::string notchRotor3, bool& notchRotor1Trobat, bool& notchRotor2Trobat);
void desxifrarMissatge(std::string missatgeXifrat, std::string rotor1, std::string notchRotor1, bool notchRotor1Trobat, std::string rotor2, std::string notchRotor2, bool notchRotor2Trobat, std::string rotor3, std::string notchRotor3);