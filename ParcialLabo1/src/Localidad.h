/*
 * Localidad.h
 *
 *  Created on: 25 oct. 2021
 *      Author: Leandro
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#define TRUE 1
#define FALSE 0
#define LOCTAM 5

#include "biblioteca.h"

typedef struct {

	int id;
	char localidad[51];

}Localidad;

/// @fn int mostrarLocalidad(int, Localidad*)
/// @brief Imprime en pantalla el listado de localidad
///
/// @param len
/// @param listadoLocalidad
/// @return devuelve -1 en caso de error y 0 si se ejecuto con exito
///
int mostrarLocalidad(int len, Localidad *listadoLocalidad);
/// @fn int inicializarLocalidad(Localidad*, Localidad, int)
/// @brief Carga cinco localidades en el array
///
/// @param list
/// @param pedido
/// @param len
/// @return devuelve -1 en caso de error y 0 si fue exitosa

int inicializarLocalidad(Localidad *list, Localidad pedido, int len);

/// @fn int retornarIndicePorId(Localidad*, int, int)
/// @brief Recorre el array en busca de un id igual y retorna su indice
///
/// @param listadoLocalidad
/// @param len
/// @param id
/// @return -1 si hubo error y el indice si fue ejecutada con exito
int retornarIndicePorId(Localidad *listadoLocalidad, int len, int id);

#endif /* LOCALIDAD_H_ */
