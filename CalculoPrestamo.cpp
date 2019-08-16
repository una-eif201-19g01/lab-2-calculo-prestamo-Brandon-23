/*
 * =====================================================================================
 *
 *       Filename:  CalculoPrestamo.cpp
 *
 *    Description:  Implementacion de casteo, metodos find y string.
 *
 *        Created:  12/08/2019
 *
 *         Author:  Brandon Arguedas Brandonxd1970@gmail.com
 *   Organization:  Universidad Nacional de Costa Rica
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include "CalculoPrestamo.h"

CalculoPrestamo::CalculoPrestamo() {
	setMonto(0);
}

CalculoPrestamo::CalculoPrestamo(int64_t monto) : monto(monto) {}

float CalculoPrestamo::obtenerPorcentaje(std::string porcentajeTXT) {
	float porcentaje = 0;
	std::string porcentajeS = porcentajeTXT.substr(0, porcentajeTXT.find("%"));
	porcentaje = std::stof(porcentajeS);
	return porcentaje / 100;
}

int CalculoPrestamo::calcularTiempoEnMeses(std::string tiempoTXT) {
	int ano = tiempoTXT.find("A");
	int mes = tiempoTXT.find("M");
	int nAno = 0;
	int nMes = 0;
	if (ano != -1) {
		std::string comodin = tiempoTXT.substr(0, 1);
		nAno = stoi(comodin);
		return nAno = nAno * 12;
	}
	else
		if (mes != -1) {
			std::string comodin = tiempoTXT.substr(0, 1);
			nAno = stoi(comodin);
			return nMes + nAno;
		}
}

float CalculoPrestamo::calcularInteresMensual(float balance, float tasaAnual) {
	float interesM = 0;
	interesM = balance * (tasaAnual / 12);
	return interesM;
}

std::string CalculoPrestamo::reporteCalculoPrestamo(std::string tiempoTXT, std::string porcentajeTXT) {
	int contra = calcularTiempoEnMeses(tiempoTXT);
	float CBalance = getMonto();
	for (int i = 0; i < contra; i++) {
		float interes = calcularInteresMensual(CBalance, obtenerPorcentaje(porcentajeTXT));
		std::string reporte = "";
		reporte = porcentajeTXT;
		//"tasa\n["  porcentajeTXT "]," << "mes\n[" << i << "]," << "balance inicial\n[" << CBalance << "]," << "interes\n[" << interes << "]," << "balance nuevo\n[" << CBalance + interes << "]";
		CBalance += interes;
		return reporte;
	}
}

float CalculoPrestamo::getMonto() const {
	return monto;
}

void CalculoPrestamo::setMonto(float monto) {
	CalculoPrestamo::monto = monto;
}