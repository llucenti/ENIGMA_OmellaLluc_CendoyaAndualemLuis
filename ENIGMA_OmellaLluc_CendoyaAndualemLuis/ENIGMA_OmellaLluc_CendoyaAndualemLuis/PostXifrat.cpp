#include "const.h"
#include <string>
#include <fstream>
#include <iostream>
#include "PreXifrat.h"
#include "Xifrat.h"
#include "PostXifrat.h"

void comprobacions(char& caracterMissatge) {
	
	//Borrar els espais
	if (caracterMissatge >= iniciAbecedariMin && caracterMissatge <= fiAbecedariMin)
	{
		caracterMissatge -= SPACE;
	}

	//Canvis ASCII vocals
	else if (caracterMissatge == accentTancatAmin || caracterMissatge == accentObertAmin || caracterMissatge == accentTancatAmax || caracterMissatge == accentObertAmax)
	{
		caracterMissatge = A;
	}

	if (caracterMissatge == accentTancatEmin || caracterMissatge == accentObertEmin || caracterMissatge == accentTancatEmax || caracterMissatge == accentObertEmax)
	{
		caracterMissatge = E;
	}

	else if (caracterMissatge == accentTancatImin || caracterMissatge == accentObertImin || caracterMissatge == accentTancatImax || caracterMissatge == accentObertImax)
	{
		caracterMissatge = I;
	}

	else if (caracterMissatge == accentTancatOmin || caracterMissatge == accentObertOmin || caracterMissatge == accentTancatOmax || caracterMissatge == accentObertOmax)
	{
		caracterMissatge = O;
	}

	else if (caracterMissatge == accentTancatUmin || caracterMissatge == accentObertUmin || caracterMissatge == accentTancatUmax || caracterMissatge == accentObertUmax)
	{
		caracterMissatge = U;
	}
}

void separacio(std::string& missatge) {

	//Verificar si la lletra es correcte, en el sentit de que es un caracter que tenim compres, en cas contrari l'eliminem
	for (int i = minAbecedari; i < missatge.length(); i++)
	{

		//Funcio que comprova les lletres, els accents
		comprobacions(missatge[i]);
		if (missatge[i] < iniciAbecedariMax || missatge[i] > fiAbecedariMax) {
			missatge.erase(i, quantitatPrincipal);
			i--;
		}

		//Cada 5 lletres afegim un espai
		if (i % iteracioXEspai == minAbecedari && i > minAbecedari)
		{
			missatge.insert(i - quantitatPrincipal, quantitatPrincipal, SPACE);
		}
	}
}