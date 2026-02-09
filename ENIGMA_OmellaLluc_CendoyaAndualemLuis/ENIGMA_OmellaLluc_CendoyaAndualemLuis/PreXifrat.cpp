#include "const.h"
#include <string>
#include <fstream>
#include <iostream>
#include "PreXifrat.h"
#include "Xifrat.h"
#include "PostXifrat.h"

void editarRotors(std::string rotor1, std::string rotor2, std::string rotor3, std::string notchRotor1, std::string notchRotor2, std::string notchRotor3) {

	//Escollir quin rotor volem editar
	short opcioRotors;
	std::cout << "Quin rotor vols editar (1 - 3): ";
	std::cin >> opcioRotors;
	std::cin.get();

	//Les diferentes opcions segons rotor
	if (opcioRotors == quantitatPrincipal)
	{
		std::cout << "Introdueix una permutacio valida per al Rotor 1: ";
		std::cin >> rotor1;

		//Comprovacio de llargada de rotors
		if (rotor1.length() != maxAbecedari)
		{
			std::cout << "[ERROR] Rotor1: Permutacio introduida no valida.";
			return;
		}

		// Sol·licitar lletra pel notch
		char posclau;
		std::cout << "Introdueix una lletra com a posicio de clau: ";
		std::cin >> posclau;

		// Si el resultat es incorrecte per default agafa Z
		if ((posclau < 'A' || posclau > 'Z') && (posclau < 'a' || posclau > 'z')) {
			posclau = 'Z';
		}
		posclau = toupper(posclau);

		//Edicio del archiu
		std::ofstream edicioRotor1;
		edicioRotor1.open("Rotor1.txt");

		//Comprovació errors, si esta obert
		if (!edicioRotor1.is_open())
		{
			std::cout << "No s'ha pogut obrir el fitxer Rotor1.txt";
			std::exit(1);
		}

		edicioRotor1 << rotor1 << std::endl << posclau;
		edicioRotor1.close();
	}

	else if (opcioRotors == 2)
	{
		std::cout << "Introdueix una permutacio valida per al Rotor 2: ";
		std::cin >> rotor2;

		//Comprovacio de llargada de rotors
		if (rotor2.length() != maxAbecedari)
		{
			std::cout << "[ERROR] Rotor2: Permutacio introduida no valida.";
			return;
		}

		// Sol·licitar lletra pel notch
		char posclau;
		std::cout << "Introdueix una lletra com a posicio de clau: ";
		std::cin >> posclau;

		// Si el resultat es incorrecte per default agafa Z
		if ((posclau < 'A' || posclau > 'Z') && (posclau < 'a' || posclau > 'z')) {
			posclau = 'Z';
		}
		posclau = toupper(posclau);

		//Edicio del archiu
		std::ofstream edicioRotor2;
		edicioRotor2.open("Rotor2.txt");

		//Comprovació errors, si esta obert
		if (!edicioRotor2.is_open())
		{
			std::cout << "No s'ha pogut obrir el fitxer Rotor2.txt";
			std::exit(1);
		}
		edicioRotor2 << rotor2 << std::endl << posclau;
		edicioRotor2.close();
	}

	else if (opcioRotors == 3)
	{
		std::cout << "Introdueix una permutacio valida per al Rotor 3: ";
		std::cin >> rotor3;

		//Comprovacio de llargada de rotors
		if (rotor3.length() != maxAbecedari)
		{
			std::cout << "[ERROR] Rotor3: Permutacio introduida no valida.";
			return;
		}

		// Sol·licitar lletra pel notch
		char posclau;
		std::cout << "Introdueix una lletra com a posicio de clau: ";
		std::cin >> posclau;

		// Si el resultat es incorrecte per default agafa Z
		if ((posclau < 'A' || posclau > 'Z') && (posclau < 'a' || posclau > 'z')) {
			posclau = 'Z';
		}
		posclau = toupper(posclau);

		//Edició archiu
		std::fstream edicioRotor3;
		edicioRotor3.open("Rotor3.txt");

		//Comprovació errors, si esta obert
		if (!edicioRotor3.is_open())
		{
			std::cout << "No s'ha pogut obrir el fitxer Rotor3.txt";
			std::exit(1);
		}
		edicioRotor3 << rotor3 << std::endl << posclau;
		edicioRotor3.close();
	}

	//Si no es cap dels 3 dona error
	else
	{
		std::cout << "Opcio invalida" << std::endl;
		return;
	}
}

//Falta comentar be
void asignacioRotors(std::string& rot1, std::string& rot2, std::string& rot3, std::string& notchRot1, std::string& notchRot2, std::string& notchRot3) {

	std::fstream rotor1;
	rotor1.open("Rotor1.txt");

	if (!rotor1.is_open())
	{
		std::cout << "No s'ha pogut obrir el fitxer Rotor1.txt";
		std::exit(1);
	}
	std::getline(rotor1, rot1);
	while (std::getline(rotor1, notchRot1)) {}

	if (notchRot1.empty())
	{
		notchRot1 = DEFAULT_NOTCH;
	}
	rotor1.close();

	if (rot1.length() != maxAbecedari)
	{
		std::cout << "[ERROR] Rotor1.txt: Permutacio invalida - calen 26 lletres." << std::endl;
		editarRotors(rot1, rot2, rot3, notchRot1, notchRot2, notchRot3);
		std::exit(0);

	}

	std::fstream rotor2;
	rotor2.open("Rotor2.txt");

	if (!rotor2.is_open())
	{
		std::cout << "No s'ha pogut obrir el fitxer Rotor2.txt";
		std::exit(1);
	}
	std::getline(rotor2, rot2);
	while (std::getline(rotor2, notchRot2)) {}

	if (notchRot2.empty())
	{
		notchRot2 = DEFAULT_NOTCH;
	}
	rotor2.close();

	if (rot2.length() != maxAbecedari)
	{
		std::cout << "[ERROR] Rotor2.txt: Permutacio invalida - calen 26 lletres." << std::endl;
	}

	std::fstream rotor3;
	rotor3.open("Rotor3.txt");

	if (!rotor3.is_open())
	{
		std::cout << "No s'ha pogut obrir el fitxer Rotor3.txt";
		std::exit(1);
	}
	std::getline(rotor3, rot3);
	while (std::getline(rotor3, notchRot3)) {}

	if (notchRot3.empty())
	{
		notchRot3 = DEFAULT_NOTCH;
	}
	rotor3.close();

	if (rot3.length() != maxAbecedari)
	{
		std::cout << "[ERROR] Rotor3.txt: Permutacio invalida - calen 26 lletres." << std::endl;
	}
}

void menuPrincipal(short opcio, std::string missatge, std::string rot1, std::string rot2, std::string rot3, std::string notchRot1, std::string notchRot2, std::string notchRot3, bool notchRot1Trobat, bool notchRot2Trobat, std::string missatgeXifrat) {

	std::cout << "      ENIGMA:\n ----------------" << std::endl;
	std::cout << "1. Xifrar missatge\n2. Desxifrar missatge\n3. Editar rotors\n4. Sortir" << std::endl;
	std::cout << "Escogeix una opcio (1 - 4): ";
	std::cin >> opcio;
	std::cin.get();

	switch (opcio)
	{
	case 1:
	{
		std::cout << std::endl << "Introdueix el missatge: ";
		std::getline(std::cin, missatge);
		std::ofstream missatgeOG;
		missatgeOG.open("Missatge.txt");

		if (!missatgeOG.is_open())
		{
			std::cout << "No s'ha pogut obrir el fitxer Missatge.txt";
			std::exit(1);
		}
		missatgeOG << missatge;
		missatgeOG.close();

		separacio(missatge);

		XifrarMissatge(missatge, rot1, rot2, rot3, notchRot1, notchRot2, notchRot3, notchRot1Trobat, notchRot2Trobat);
		std::cout << "[OK] Missatge xifrat a 'Xifrat.txt'" << std::endl;
	}
	break;
	case 2:
		desxifrarMissatge(missatgeXifrat, rot1, notchRot1, notchRot1Trobat, rot2, notchRot2, notchRot2Trobat, rot3, notchRot3);
		std::cout << "[OK] Missatge desxifrat a 'Desxifrat.txt'" << std::endl;
		break;
	case 3:
		editarRotors(rot1, rot2, rot3, notchRot1, notchRot2, notchRot3);
		break;
	case 4:
		std::cout << "Sortint de la maquina ENIGMA!" << std::endl;
		break;
	default:
		std::cout << "Opcio Invalida!";
		break;
	}
}
