/*
 * Pedidos.c
 *
 *  Created on: 22 oct. 2021
 *      Author: Leandro
 */

#include "Pedidos.h"

int inicializarPedidos(Pedidos *list, int len) {
	int i;
	int retorno;

	retorno = -1;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].estado = VACIO;
		}
		retorno = 0;
	}

	return retorno;
}

int buscarPrimerPosPedidoLibre(Pedidos *list, int len) {
	int i;
	int banderaLibre;
	int retorno;

	i = 0;
	banderaLibre = FALSE;
	retorno = -1;

	while (banderaLibre == FALSE && i < len) {
		if (list[i].estado == VACIO) {
			banderaLibre = TRUE;
			retorno = i;
		} else {
			i++;
		}
	}

	return retorno;
}

int agregarPedido(Pedidos *list, Pedidos pedido, int len, int id) {
	int i;
	int retorno;

	retorno = -1;
	i = buscarPrimerPosPedidoLibre(list, len);

	if (i != -1 && len > 0 && list != NULL) {
		list[i] = pedido;
		list[i].id = id + 1;
		list[i].estado = PENDIENTE;
		retorno = 0;
	} else {
		printf(
				"\nHa ocurrido un error en su peticion. Reintente la operacion...\n");
	}

	return retorno;
}

int mostrarPedidos(Pedidos *list, int len) {
	int i;
	int retorno;

	retorno = -1;

	if (list != NULL && len > 0) {
		printf(
				"\n*************************************************\n ID PEDIDO        KILOS TOTALES       ID CLIENTE\n");
		for (i = 0; i < len; i++) {
			if (list[i].estado == PENDIENTE) {
				printf("%6d %20d %15d\n", list[i].id, list[i].residuosTotales,
						list[i].idCliente);
			}
		}
		printf("\n*************************************************\n");
		retorno = 0;
	}

	return retorno;
}

int buscarPedidoPorId(Pedidos *list, int len, int id) {
	int i;
	int retorno;
	int banderaLibre;

	i = 0;
	retorno = -1;
	banderaLibre = FALSE;

	if (list != NULL && len > 0) {
		while (banderaLibre == FALSE && i < len) {
			if (list[i].id == id && list[i].estado == PENDIENTE) {
				retorno = i;
				banderaLibre = TRUE;
			} else {
				i++;
			}
		}
	}

	return retorno;
}

int agregarPedidoProcs(Pedidos *list, KilosTotales kilosTotales, int len,
		int iPedido) {
	int retorno;

	retorno = -1;

	if (iPedido != -1 && len > 0 && list != NULL) {
		list[iPedido].residuosEspecificos = kilosTotales;
		list[iPedido].estado = COMPLETADO;
		retorno = 0;
	} else {
		printf(
				"\nHa ocurrido un error en su peticion. Reintente la operacion...\n");
	}

	return retorno;
}

int PedidosProcesados(Pedidos *list, int len) {
	int retorno;
	int id;
	int iPedido;
	KilosTotales kilosTotales = { 0, 0, 0 };

	retorno = -1;

	mostrarPedidos(list, len);
	IngresarEnteroValidado("Ingrese el ID del pedido que desea procesar: \n", 0,
			1001, &id);
	iPedido = buscarPedidoPorId(list, len, id);
	while (iPedido == -1) {
		IngresarEnteroValidado("Error, ID invalido: \n", 0,
				1001, &id);
		iPedido = buscarPedidoPorId(list, len, id);
	}

	IngresarEnteroValidado(
			"Ingrese la cantidad de kilos de polietileno de alta densidad procesados: \n",
			0, list[iPedido].residuosTotales, &kilosTotales.HDPE);
	IngresarEnteroValidado(
			"Ingrese la cantidad de kilos de polietileno de baja densidad procesados: \n",
			0, list[iPedido].residuosTotales, &kilosTotales.LDPE);

	while ((kilosTotales.HDPE + kilosTotales.LDPE + kilosTotales.PP)
			> list[iPedido].residuosTotales) {
		printf(
				"\nLa cantidad de kilos totales ingresados no puede ser mayor a la cantidad total de kilos declarados(%dkgs)\n",
				list[iPedido].residuosTotales);
		IngresarEnteroValidado(
				"\nIngrese la cantidad de kilos de polietileno de baja densidad procesados:\n ",
				0, list[iPedido].residuosTotales, &kilosTotales.LDPE);
	}
	IngresarEnteroValidado(
			"Ingrese la cantidad de kilos de polipropileno procesados: \n", 0,
			list[iPedido].residuosTotales, &kilosTotales.PP);
	while ((kilosTotales.HDPE + kilosTotales.LDPE + kilosTotales.PP)
			> list[iPedido].residuosTotales) {
		printf(
				"\nLa cantidad de kilos totales ingresados no puede ser mayor a la cantidad total de kilos declarados(%dkgs)\n",
				list[iPedido].residuosTotales);
		IngresarEnteroValidado(
				"\nIngrese la cantidad de kilos de polipropileno procesados:\n ",
				0, list[iPedido].residuosTotales, &kilosTotales.PP);
	}

	if (agregarPedidoProcs(list, kilosTotales, len, iPedido) != -1) {
		retorno = 0;
	} else {
		printf(
				"\nHa ocurrido un error en su peticion. Reintente la operacion...\n");
	}

	return retorno;
}

int contarPedidos(Pedidos *list, int len, int estado) {
	int i;
	int contadorPedidosCompletados;

	contadorPedidosCompletados = 0;

	for (i = 0; i < len; i++) {
		if (list[i].estado == estado) {
			contadorPedidosCompletados++;
		}
	}

	return contadorPedidosCompletados;
}


