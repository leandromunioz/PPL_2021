/*
 * Clientes.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Leandro
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

#include "biblioteca.h"

#define FALSE 0
#define TRUE 1

#define TAM 100

typedef struct {
	int id;
	int isEmpty;
	int idLocalidad;
	char name[51];
	char cuit[51];
	char direccion[51];

} Clientes;

/// @fn int inicializarClientes(Clientes*, int)
/// @brief funcion que inicializa los clientes
///
/// @param list
/// @param len
/// @return devuelve -1 si hubo error y 0 si fue ejecutada con exito
int inicializarClientes(Clientes *list, int len);

/// @fn int agregarCliente(Clientes*, Clientes, int, int)
/// @brief funcion utilizada para dar de alta un cliente
///
/// @param list
/// @param customerOne
/// @param len
/// @param id
/// @return devuelve -1 si hubo error y 0 si fue ejectuada con exito
int agregarCliente(Clientes *list, Clientes customerOne, int len, int id);

/// @fn int eliminarCliente(Clientes*, int, int)
/// @brief funcion utilizada para dar de baja un cliente
///
/// @param list
/// @param len
/// @param id
/// @return -1 si hubo error y 0 si fue ejecutada con exito
int eliminarCliente(Clientes *list, int len, int id);



/// @fn int buscarPrimerPosicionLibre(Clientes*, int)
/// @brief funcion que busca la primer posicion libre del array
///
/// @param list
/// @param len
/// @return -1 si hubo error y 0 si fue exitosa
int buscarPrimerPosicionLibre(Clientes *list, int len);

/// @fn int buscarClientePorId(Clientes*, int, int)
/// @brief funcion utilizada pra buscar un cliente por su id
///
/// @param list
/// @param len
/// @param id
/// @return -1 si hubo error y 0 si fue exitosa
int buscarClientePorId(Clientes *list, int len, int id);

#endif /* CLIENTES_H_ */
