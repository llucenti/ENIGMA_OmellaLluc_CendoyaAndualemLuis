#include "const.h"
#include "utils.h"
#include "PreXifrat.h"
#include "Xifrat.h"
#include "PostXifrat.h"
#include <iostream>
#include <fstream>

void main() {

	asignacioRotors(rotor1, rotor2, rotor3, notchRotor1, notchRotor2, notchRotor3);

	menuPrincipal(opcio, missatge, rotor1, rotor2, rotor3, notchRotor1, notchRotor2, notchRotor3, notchRotor1Trobat, notchRotor2Trobat, missatgeXifrat);
}