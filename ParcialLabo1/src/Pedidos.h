/*
 * Pedidos.h
 *
 *  Created on: 22 oct. 2021
 *      Author: Leandro
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#include "biblioteca.h"

#define TRUE 1
#define FALSE 0

#define VACIO -1
#define PENDIENTE 1
#define COMPLETADO 0

#define T 1000

typedef struct {
	int HDPE;
	int LDPE;
	int PP;
} KilosTotales;

typedef struct {
	int id;
	int idCliente;
	int estado;
	int residuosTotales;
	KilosTotales residuosEspecificos;
} Pedidos;

/// @fn int inicializarPedidos(Pedidos*, int)
/// @brief Funcion que inicializa pedidos
///
/// @param list
/// @param len
/// @return -1 si hubo error y 0 si fue exitosa
int inicializarPedidos(Pedidos *list, int len);

/// @fn int buscarPrimerPosPedidoLibre(Pedidos*, int)
/// @brief funcion que busca una posicion libre y la devuelve
///
/// @param list
/// @param len
/// @return -1 si hubo error , si fue exitosamente ejecutada devuelve la posicion libre
int buscarPrimerPosPedidoLibre(Pedidos *list, int len);

/// @fn int agregarPedido(Pedidos*, Pedidos, int, int)
/// @brief funcion utilizada para agregarun pedido
///
/// @param list
/// @param orderOne
/// @param len
/// @param id
/// @return -1 si hubo error y 0 si fue ejecutada con exito
int agregarPedido(Pedidos *list, Pedidos pedido, int len, int id);

/// @fn int mostrarPedidos(Pedidos*, int)
/// @brief funcion que muestra los pedidos
///
/// @param list
/// @param len
/// @return -1 si hubo error o 0 si fue ejecutada con exito
int mostrarPedidos(Pedidos *list, int len);

/// @fn int buscarPedidoPorId(Pedidos*, int, int)
/// @brief funcion que busca un pedido por su correspondiente ID
///
/// @param list
/// @param len
/// @param id
/// @return -1 si hubo error y si fue ejecutada con exito devuelve el indice
int buscarPedidoPorId(Pedidos *list, int len, int id);

/// @fn int PedidosProcesados(Pedidos*, int)
/// @brief funcion que muestra los pedidos procesados
///
/// @param list
/// @param len
/// @return -1 si hubo error y 0 si fue ejecutada con exito
int PedidosProcesados(Pedidos *list, int len);

/// @fn int agregarPedidoProcs(Pedidos*, KilosTotales, int, int)
/// @brief funcion que agrega el estado de los pedidos procesados
///
/// @param list
/// @param kilosTotales
/// @param len
/// @param indexOrder
/// @return -1 si hubo error y 0 si fue ejecutada con exito
int agregarPedidoProcs(Pedidos *list, KilosTotales kilosTotales, int len,int iPedido);

/// @fn int contarPedidos(Pedidos*, int, int)
/// @brief funcion que cuenta los pedidos completados
///
/// @param list
/// @param len
/// @param estado
/// @return devuelve la cantidad de pedidos procesados
int contarPedidos(Pedidos *list, int len, int estado);

#endif /* PEDIDOS_H_ */
