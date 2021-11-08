/*
 * Nexo.h
 *
 *  Created on: 22 oct. 2021
 *      Author: Leandro
 */
#ifndef NEXO_H_
#define NEXO_H_

#include "Clientes.h"
#include "Pedidos.h"
#include "Localidad.h"

/// @fn int crearPedido(Clientes*, Pedidos*, int, int, int*)
/// @brief Funcion que crea un pedido con verificacion de datos
///
/// @param list
/// @param listaPedidos
/// @param len
/// @param pedidosTam
/// @param id
/// @return devuelve 0 si hubo exito y -1 en caso de error
int crearPedido(Clientes *list, Pedidos *listaPedidos, int len, int pedidosTam,
		int *id);

/// @fn int contadorPedidosPendientes(int, Pedidos*, int)
/// @brief funcion encargada de contar los pedidos pendientes
///
/// @param id
/// @param list
/// @param len
/// @return devuelve la cantidad de pedidos pendientes
int contadorPedidosPendientes(int id, Pedidos *list, int len);

/// @fn int mostrarPedidosPendientesClientes(Clientes*, Pedidos*, int, int, Localidad*, int)
/// @brief funcion encargada de mostrar los clientes
///
/// @param list
/// @param listaPedidos
/// @param len
/// @param pedidosTam
/// @param listadoLocalidad
/// @param locLen
/// @return devuelve 0 si fue ejecutada con exito y -1 en caso de error
int mostrarPedidosPendientesClientes(Clientes *list, Pedidos *listaPedidos,
		int len, int pedidosTam, Localidad *listadoLocalidad, int locLen);

/// @fn int mostrarPedidosPendientes(Clientes*, Pedidos*, int, int)
/// @brief funcion encargada de mostrar los pedidos pendientes
///
/// @param list
/// @param listaPedidos
/// @param len
/// @param pedidosTam
/// @return -1 en caso de error y 0 si fue ejecutada con exito
int mostrarPedidosPendientes(Clientes *list, Pedidos *listaPedidos, int len,
		int pedidosTam);

/// @fn int mostrarPedidosCompletados(Clientes*, Pedidos*, int, int)
/// @brief funcion que muestra los pedidos completados
///
/// @param list
/// @param listaPedidos
/// @param len
/// @param pedidosTam
/// @return -1 en caso de error y 0 si fue exitosa
int mostrarPedidosCompletados(Clientes *list, Pedidos *listaPedidos, int len,
		int pedidosTam);
int encontrarIPorLocalidad(char cadena[], int len,
		Localidad *listadoLocalidad);

/// @fn int buscarPedidosPendientesPorLocalidad(Pedidos*, int, int, Localidad*, Clientes*, int)
/// @brief funcion que busca y muestra los pedidos pendientes de cada localidad
///
/// @param listaPedidos
/// @param lenLocalidad
/// @param pedidosTam
/// @param listadoLocalidad
/// @param listadoDeClientes
/// @param lenClientes
/// @return -1 en caso de error y 0 si fue exitosa
int buscarPedidosPendientesPorLocalidad(Pedidos *listaPedidos, int lenLocalidad,
		int pedidosTam, Localidad *listadoLocalidad, Clientes *listadoDeClientes, int lenClientes) ;

/// @fn int promedioPPCliente(Clientes*, Pedidos*, int, int, float*)
/// @brief funcion que calcula el promedio de polipropileno reciclado por cliente y lo muestra
///
/// @param list
/// @param listaPedidos
/// @param len
/// @param pedidosTam
/// @param promedioPPCliente
/// @return 1 en caso de exito 0 en caso de erorr
int promedioPPCliente(Clientes *list, Pedidos *listaPedidos, int len,
		int pedidosTam, float *promedioPPCliente);

/// @fn int altaCliente(Clientes*, int, int*)
/// @brief funcion que da de alta clientes
///
/// @param list
/// @param len
/// @param id
/// @return devuelve -1 si hubo error y 0 si fue ejecutada con exito
int altaCliente(Clientes *list, int len, int *id, Localidad *listadoLocalidad, int locLen);

/// @fn int modificarCliente(Clientes*, int)
/// @brief funcion que permite la modficiacion de un cliente
///
/// @param list
/// @param len
/// @return devuelve -1 si hubo error y 0 si fue exitosa
int modificarCliente(Clientes *list, int len, Localidad *listadoLocalidad, int locLen);

/// @fn int mostrarClientes(Clientes*, int)
/// @brief funcion que imprime los clientes por pantalla
///
/// @param list
/// @param len
/// @return -1 si hubo error y 0 si fue exitosa
int mostrarClientes(Clientes *list, int len, Localidad *listadoLocalidad, int locLen);

/// @fn int contarrPedidos(int, Pedidos*, int, int)
/// @brief funcion que cuenta los pedidos
///
/// @param id
/// @param list
/// @param len
/// @param estado
/// @return devuelve la cantidad de pedidos
int contarrPedidos(int id, Pedidos *list, int len, int estado);

/// @fn int contarPedidosPorLocalidad(int, Pedidos*, int, Clientes*, int)
/// @brief Cuenta los pedidos realizados por los clientes segun su localidad
///
/// @param id
/// @param listadoDePedidos
/// @param lenPedidos
/// @param listadoDeClientes
/// @param lenClientes
/// @return
int contarPedidosPorLocalidad(int id, Pedidos *listadoDePedidos, int lenPedidos,
		Clientes *listadoDeClientes, int lenClientes);

/// @fn int contarPedidosCompletados(Clientes*, Pedidos*, int, int, int)
/// @brief Cuenta la mayor cantidad de pedidos
///
/// @param list
/// @param listadoPedidos
/// @param len
/// @param orderLen
/// @param estado
/// @return
int contarPedidosCompletados(Clientes *list, Pedidos *listadoPedidos, int len,
		int orderLen, int estado);

/// @fn int bajaCliente(Clientes*, int)
/// @brief funcion que da de baja del sistema a un cliente
///
/// @param list
/// @param len
/// @return -1 si hubo error y 1 si fue exitosa
int bajaCliente(Clientes *list, int len, int locLen, Localidad *listadoLocalidad);
#endif /* NEXO_H_ */
