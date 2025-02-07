#pragma once
#include <iostream>
#include "PassarellaUsuari.h"
using namespace std;


class CapaDeDomini
{
public:
	static CapaDeDomini& getInstance() {
		static CapaDeDomini instance;
		return instance;
	}

	void registrarUsuari(string sobrenomU, string nomU, string correuU);
};
