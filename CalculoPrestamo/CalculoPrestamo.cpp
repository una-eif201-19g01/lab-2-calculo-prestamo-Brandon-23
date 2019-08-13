//
// Created by Brandon Arguedas on 2019-08-08.
//

#include <iostream>
#include <string>
#include "CalculoPrestamo.h"

CalculoPrestamo::CalculoPrestamo() {
	setMonto(0);
}

CalculoPrestamo::CalculoPrestamo(int64_t monto) : monto(monto) {}

float CalculoPrestamo::obtenerPorcentaje(std::string porcentajeTXT) {
	std::string num = porcentajeTXT.substr(0, 4);
	return (stof(num)*0.01);
}

int CalculoPrestamo::calcularTiempoEnMeses(std::string tiempoTXT) {
	if (tiempoTXT.find("A") == true) {
		std::string tiempoM = tiempoTXT.substr(0, 1);
		int tiempoT = stoi(tiempoM);
		if (tiempoT != 0) {
			return tiempoT * 12;
		}
	}
	else
		return 0;
}

float CalculoPrestamo::calcularInteresMensual(float balance, float tasaAnual) {
	float suma =((balance*(1 + tasaAnual / 12))-balance);
	return suma;
}


