
#include "const.h"
#include <string>
#include <fstream>
#include <iostream>
#include "prexifrat.h"
#include "xifrat.h"
#include "postxifrat.h"


void xifrarMissatge(std::string& text, std::string& rot1, std::string& rot2, std::string& rot3, std::string notchRot1, std::string notchRot2, std::string notchRot3, bool& notchRot1Trobat, bool& notchRot2Trobat) {
	// Variables per controlar el gir
	bool girarRotor2 = false;
	bool girarRotor3 = false;

	for (int i = minAbecedari; i < text.length(); i++)
	{
		// Comprovar notch del primer rotor abans d'avançar
		if (rot1[0] == notchRot1[0])
		{
			girarRotor2 = true;
		}

		if (text[i] != espai)
		{
			text[i] = rot1[text[i] - iniciAbecedariMax];

			text[i] = rot2[text[i] - iniciAbecedariMax];

			text[i] = rot3[text[i] - iniciAbecedariMax];
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

	std::ofstream fitxerXifrat;
	fitxerXifrat.open("Xifrat.txt");

	if (!fitxerXifrat.is_open())
	{
		std::cout << "No s'ha pogut obrir el fitxer Xifrat.txt";
		std::exit(1);
	}
	fitxerXifrat << text;
	fitxerXifrat.close();
}

void desxifrarMissatge(std::string textXifrat, std::string rot1, std::string notchRot1, bool notchRot1Trobat, std::string rot2, std::string notchRot2, bool notchRot2Trobat, std::string rot3, std::string notchRot3) {

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

	std::fstream fitxerXifrat;
	fitxerXifrat.open("Xifrat.txt");

	if (!fitxerXifrat.is_open())
	{
		std::cout << "No s'ha pogut obrir el fitxer Xifrat.txt";
		std::exit(1);
	}
	std::string linea;
	while (std::getline(fitxerXifrat, linea)) {
		textXifrat += linea;
	}
	fitxerXifrat.close();

	// Variables per controlar el gir
	bool girarRotor2 = false;
	bool girarRotor3 = false;

	for (int i = minAbecedari; i < textXifrat.length(); i++)
	{
		// Comprovar notch del primer rotor abans d'avançar
		if (rot1[0] == notchRot1[0])
		{
			girarRotor2 = true;
		}

		if (textXifrat[i] != espai)
		{
			textXifrat[i] = inv_rot3[textXifrat[i] - iniciAbecedariMax];

			textXifrat[i] = inv_rot2[textXifrat[i] - iniciAbecedariMax];

			textXifrat[i] = inv_rot1[textXifrat[i] - iniciAbecedariMax];
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

	std::ofstream fitxerDesxifrat;
	fitxerDesxifrat.open("Desxifrat.txt");

	if (!fitxerDesxifrat.is_open())
	{
		std::cout << "No s'ha pogut obrir el fitxer Xifrat.txt";
		std::exit(1);
	}
	fitxerDesxifrat << textXifrat;
	fitxerDesxifrat.close();
}

