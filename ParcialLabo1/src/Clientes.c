/*
 * Clientes.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Leandro
 */

#include "Clientes.h"

int inicializarClientes(Clientes *list, int len) {
	int i;
	int retorno;

	retorno = -1;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}

int buscarPrimerPosicionLibre(Clientes *list, int len) {
	int i;
	int banderaLibre;
	int retorno;

	i = 0;
	banderaLibre = FALSE;
	retorno = -1;

	while (banderaLibre == FALSE && i < len) {
		if (list[i].isEmpty == TRUE) {
			banderaLibre = TRUE;
			retorno = i;
		} else {
			i++;
		}
	}

	return retorno;
}

int agregarCliente(Clientes *list, Clientes clientesParam, int len, int id) {
	int i;
	int retorno;

	retorno = -1;
	i = buscarPrimerPosicionLibre(list, len);
	FormatearCadena(clientesParam.name);

	if (i != -1 && len > 0 && list != NULL) {
		list[i] = clientesParam;
		list[i].id = id;
		list[i].isEmpty = FALSE;
		retorno = 0;
	} else {
		printf(
				"\nHa ocurrido un error en la carga del cliente. Por favor, reintente la operacion.\n");
	}

	return retorno;
}

int buscarClientePorId(Clientes *list, int len, int id) {
	int i;
	int retorno;
	int banderaLibre;

	i = 0;
	retorno = -1;
	banderaLibre = FALSE;

	if (list != NULL && len > 0) {
		while (banderaLibre == FALSE && i < len) {
			if (list[i].id == id && list[i].isEmpty != TRUE) {
				retorno = i;
				banderaLibre = TRUE;
			} else {
				i++;
			}
		}
	}

	return retorno;
}

int eliminarCliente(Clientes *list, int len, int id) {
	int i;
	int retorno;

	retorno = -1;

	i = buscarClientePorId(list, len, id);

	if (i != -1 && len > 0 && list != NULL) {
		list[i].isEmpty = TRUE;
	}

	return retorno;
}




