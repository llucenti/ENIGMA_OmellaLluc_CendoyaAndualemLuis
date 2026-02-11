
#include "const.h"
#include <string>
#include <fstream>
#include <iostream>
#include "PreXifrat.h"
#include "Xifrat.h"
#include "PostXifrat.h"


void XifrarMissatge(std::string& mensaje, std::string& rot1, std::string& rot2, std::string& rot3, std::string notchRot1, std::string notchRot2, std::string notchRot3, bool& notchRot1Found, bool& notchRot2Found) {
	// Variables per controlar el gir
	bool girarRotor2 = false;
	bool girarRotor3 = false;

	for (int i = minAbecedari; i < mensaje.length(); i++)
	{
		// Comprovar notch del primer rotor abans d'avançar
		if (rot1[0] == notchRot1[0])
		{
			girarRotor2 = true;
		}

		if (mensaje[i] != espai)
		{
			mensaje[i] = rot1[mensaje[i] - iniciAbecedariMax];

			mensaje[i] = rot2[mensaje[i] - iniciAbecedariMax];

			mensaje[i] = rot3[mensaje[i] - iniciAbecedariMax];
		}

		// Avançar primer rotor (sempre)
		rot1 += rot1[minAbecedari];
		rot1.erase(minAbecedari, 1);

		// Avançar segon rotor si cal
		if (girarRotor2)
		{
			// Comprovar notch del segon rotor abans d'avançar
			if (rot2[0] == notchRot2[0])
			{
				girarRotor3 = true;
			}

			// Avançar segon rotor
			rot2 += rot2[minAbecedari];
			rot2.erase(minAbecedari, 1);

			// Fem un 'reset' de l'operador
			girarRotor2 = false;
		}

		// Avançar tercer rotor si cal
		if (girarRotor3)
		{
			rot3 += rot3[minAbecedari];
			rot3.erase(minAbecedari, 1);

			// Reset flag
			girarRotor3 = false;
		}
	}

	std::ofstream mensajeCifrado;
	mensajeCifrado.open("Xifrat.txt");

	if (!mensajeCifrado.is_open())
	{
		std::cout << "No s'ha pogut obrir el fitxer Xifrat.txt";
		std::exit(1);
	}
	mensajeCifrado << mensaje;
	mensajeCifrado.close();
}

void desxifrarMissatge(std::string mensajeEncriptado, std::string rot1, std::string notchRot1, bool notchRot1Found, std::string rot2, std::string notchRot2, bool notchRot2Found, std::string rot3, std::string notchRot3) {

	//Nombro la funcio per posicionar els rotors amb el notch desitjat
	definirPosicionsInicials(rot1, rot2, rot3);
	
	std::string inv_rot1(maxAbecedari, SPACE);
	std::string inv_rot2(maxAbecedari, SPACE);
	std::string inv_rot3(maxAbecedari, SPACE);

	for (int i = minAbecedari; i < maxAbecedari; i++) {
		inv_rot1[rot1[i] - iniciAbecedariMax] = iniciAbecedariMax + i;
		inv_rot2[rot2[i] - iniciAbecedariMax] = iniciAbecedariMax + i;
		inv_rot3[rot3[i] - iniciAbecedariMax] = iniciAbecedariMax + i;
	}

	std::fstream mensajeCifrado;
	mensajeCifrado.open("Xifrat.txt");

	if (!mensajeCifrado.is_open())
	{
		std::cout << "No s'ha pogut obrir el fitxer Xifrat.txt";
		std::exit(1);
	}
	std::string linea;
	while (std::getline(mensajeCifrado, linea)) {
		mensajeEncriptado += linea;
	}
	mensajeCifrado.close();

	// Variables per controlar el gir
	bool girarRotor2 = false;
	bool girarRotor3 = false;

	for (int i = minAbecedari; i < mensajeEncriptado.length(); i++)
	{
		// Comprovar notch del primer rotor abans d'avançar
		if (rot1[0] == notchRot1[0])
		{
			girarRotor2 = true;
		}

		if (mensajeEncriptado[i] != espai)
		{
			mensajeEncriptado[i] = inv_rot3[mensajeEncriptado[i] - iniciAbecedariMax];

			mensajeEncriptado[i] = inv_rot2[mensajeEncriptado[i] - iniciAbecedariMax];

			mensajeEncriptado[i] = inv_rot1[mensajeEncriptado[i] - iniciAbecedariMax];
		}

		// Avançar primer rotor
		rot1 += rot1[minAbecedari];
		rot1.erase(minAbecedari, 1);

		// Actualitzar inv_rot1
		for (int j = minAbecedari; j < maxAbecedari; j++) {
			inv_rot1[rot1[j] - iniciAbecedariMax] = iniciAbecedariMax + j;
		}

		// Avançar segon rotor si cal
		if (girarRotor2)
		{
			// Comprovar notch del segon
			if (rot2[0] == notchRot2[0])
			{
				girarRotor3 = true;
			}

			// Avançar segon rotor
			rot2 += rot2[minAbecedari];
			rot2.erase(minAbecedari, 1);

			// Actualitzar inv_rot2
			for (int j = minAbecedari; j < maxAbecedari; j++) {
				inv_rot2[rot2[j] - iniciAbecedariMax] = iniciAbecedariMax + j;
			}

			girarRotor2 = false;
		}

		// Avançar tercer rotor si cal
		if (girarRotor3)
		{
			rot3 += rot3[minAbecedari];
			rot3.erase(minAbecedari, 1);

			// Actualitzar inv_rot3
			for (int j = minAbecedari; j < maxAbecedari; j++) {
				inv_rot3[rot3[j] - iniciAbecedariMax] = iniciAbecedariMax + j;
			}

			girarRotor3 = false;
		}
	}

	std::ofstream mensajeDescifrado;
	mensajeDescifrado.open("Desxifrat.txt");

	if (!mensajeDescifrado.is_open())
	{
		std::cout << "No s'ha pogut obrir el fitxer Xifrat.txt";
		std::exit(1);
	}
	mensajeDescifrado << mensajeEncriptado;
	mensajeDescifrado.close();
}

