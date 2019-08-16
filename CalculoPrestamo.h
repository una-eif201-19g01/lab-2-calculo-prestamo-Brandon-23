//
// Created by Maikol Guzman  on 2019-08-08.
//

#ifndef CALCULOPRESTAMO_CALCULOPRESTAMO_H
#define CALCULOPRESTAMO_CALCULOPRESTAMO_H


#include <cstdint>
#include <string>

class CalculoPrestamo {
private:
	float monto;

	float obtenerPorcentaje(std::string porcentajeTXT);

	int calcularTiempoEnMeses(std::string tiempoTXT);

	float calcularInteresMensual(float balance, float tasaAnual);

public:
	CalculoPrestamo();

	explicit CalculoPrestamo(int64_t monto);

	std::string reporteCalculoPrestamo(std::string tiempoTXT, std::string porcentajeTXT);

	float getMonto() const;

	void setMonto(float monto);

};

#endif //CALCULOPRESTAMO_CALCULOPRESTAMO_H
