#pragma once
#include <iostream>
#include "CapaDeDomini.h"



class CapaDePresentacio
{
public:
	static CapaDePresentacio& getInstance() {
		static CapaDePresentacio instance;
		return instance;
	}
	void menuPrincipal();

	void menuPrincipalSessio();

	void menuVisualitza();

	void menuConsultes();

	void gestioUsuaris();

	void registreUsuari();

	void iniciarSessio();

};

