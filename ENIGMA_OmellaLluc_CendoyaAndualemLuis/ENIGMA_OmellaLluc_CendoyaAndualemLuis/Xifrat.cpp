#include "const.h"
#include <string>
#include <fstream>
#include <iostream>
#include "PreXifrat.h"
#include "Xifrat.h"
#include "PostXifrat.h"


void XifrarMissatge(std::string& mensaje, std::string& rot1, std::string& rot2, std::string& rot3, std::string notchRot1, std::string notchRot2, std::string notchRot3, bool& notchRot1Found, bool& notchRot2Found) {
	for (int i = minAbecedari; i < mensaje.length(); i++)
	{
		if (rot1[minAbecedari] == notchRot1[minAbecedari])
		{
			notchRot1Found = true;
		}

		if (mensaje[i] != espai)
		{
			mensaje[i] = rot1[mensaje[i] - iniciAbecedariMax];

			mensaje[i] = rot2[mensaje[i] - iniciAbecedariMax];

			mensaje[i] = rot3[mensaje[i] - iniciAbecedariMax];
		}

		rot1 += rot1[minAbecedari];

		rot1.erase(minAbecedari, 1);

		if (rot2[minAbecedari] == notchRot2[minAbecedari])
		{
			notchRot2Found = true;
		}

		if (notchRot1Found)
		{
			rot2 += rot2[minAbecedari];
			rot2.erase(minAbecedari, 1);
		}

		if (notchRot2Found)
		{
			rot3 += rot3[minAbecedari];
			rot3.erase(minAbecedari, 1);
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

	for (int i = minAbecedari; i < mensajeEncriptado.length(); i++)
	{
		if (rot1[minAbecedari] == notchRot1[minAbecedari])
		{
			notchRot1Found = true;
		}

		if (mensajeEncriptado[i] != espai)
		{
			mensajeEncriptado[i] = inv_rot3[mensajeEncriptado[i] - iniciAbecedariMax];

			mensajeEncriptado[i] = inv_rot2[mensajeEncriptado[i] - iniciAbecedariMax];

			mensajeEncriptado[i] = inv_rot1[mensajeEncriptado[i] - iniciAbecedariMax];
		}

		rot1 += rot1[minAbecedari];
		rot1.erase(minAbecedari, 1);

		for (int j = minAbecedari; j < maxAbecedari; j++) {
			inv_rot1[rot1[j] - iniciAbecedariMax] = iniciAbecedariMax + j;
		}

		if (rot2[minAbecedari] == notchRot2[minAbecedari])
		{
			notchRot2Found = true;
		}

		if (notchRot1Found)
		{
			rot2 += rot2[minAbecedari];
			rot2.erase(minAbecedari, 1);

			for (int j = minAbecedari; j < maxAbecedari; j++) {
				inv_rot2[rot2[j] - iniciAbecedariMax] = iniciAbecedariMax + j;
			}
		}

		if (notchRot2Found)
		{
			rot3 += rot3[minAbecedari];
			rot3.erase(minAbecedari, 1);
			for (int j = minAbecedari; j < maxAbecedari; j++) {
				inv_rot3[rot3[j] - iniciAbecedariMax] = iniciAbecedariMax + j;
			}
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
