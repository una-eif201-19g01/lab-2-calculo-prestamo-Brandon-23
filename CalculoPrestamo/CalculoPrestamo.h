//
// Created by Brandon Arguedas on 2019-08-08.
//

#ifndef CALCULOPRESTAMO_CALCULOPRESTAMO_H
#define CALCULOPRESTAMO_CALCULOPRESTAMO_H


#include <cstdint>
#include <string>
#include <iostream>

using namespace std;

class CalculoPrestamo {
private:
	float monto;

	float obtenerPorcentaje(std::string porcentajeTXT);

	int calcularTiempoEnMeses(std::string tiempoTXT);

	float calcularInteresMensual(float balance, float tasaAnual);

public:
	CalculoPrestamo();
	CalculoPrestamo(int64_t monto);

	std::string reporteCalculoPrestamo(std::string tiempoTXT, std::string porcentajeTXT);

	int getMonto() const;

	void setMonto(float monto);

};

#endif //CALCULOPRESTAMO_CALCULOPRESTAMO_H
