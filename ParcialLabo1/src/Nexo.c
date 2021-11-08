/*
 * Nexo.c
 *
 *  Created on: 22 oct. 2021
 *      Author: Leandro
 */

#include "Nexo.h"

int crearPedido(Clientes *list, Pedidos *pedidosList, int len, int pedidosTam,
		int *id) {
	int pedidosId;
	int iCliente;
	int retorno;
	Pedidos pedido;

	retorno = -1;
	IngresarEntero("\nIngrese el ID del cliente que realizara el pedido: ",
			&pedidosId);
	iCliente = buscarClientePorId(list, len, pedidosId);
	while (iCliente == -1) {
		IngresarEntero("\nIngrese el ID de un cliente existente: ", &pedidosId);
		iCliente = buscarClientePorId(list, len, pedidosId);
	}

	pedido.idCliente = list[iCliente].id;
	IngresarEnteroValidado(
			"Ingrese la cantidad de kilos totales a recolectar: ", 1, 30000,
			&pedido.residuosTotales);

	if (agregarPedido(pedidosList, pedido, pedidosTam, *id) != -1) {
		*id = *id + 1;
		retorno = 0;
	} else {
		printf(
				"\nHa ocurrido un error en su peticion. Reintente la operacion...\n");
	}

	return retorno;
}

int contadorPedidosPendientes(int id, Pedidos *list, int len) {
	int i;
	int contadorPendPedidos;

	contadorPendPedidos = 0;
	for (i = 0; i < len; i++) {
		if ((list[i].idCliente == id) && (list[i].estado == PENDIENTE)) {
			contadorPendPedidos++;
		}
	}

	return contadorPendPedidos;
}

int mostrarPedidosPendientesClientes(Clientes *list, Pedidos *listaPedidos,
		int len, int pedidosTam, Localidad *listadoLocalidad, int locLen) {
	int i;
	int retorno;
	int contadorPedPend;
	int indiceLocalidad;

	retorno = -1;

	if (list != NULL && len > 0) {
		printf(
				"\n************************************************************************************************\n ID          NOMBRE         DIRECCION          LOCALIDAD           CUIT     PEDIDOS PENDIENTES\n");
		for (i = 0; i < len; i++) {
			contadorPedPend = contadorPedidosPendientes(list[i].id,
					listaPedidos, pedidosTam);
			indiceLocalidad=retornarIndicePorId(listadoLocalidad, locLen, list[i].idLocalidad);
			if (list[i].isEmpty != TRUE) {
				printf("%3d %15s %18s %18s %16s %10d\n", list[i].id,
						list[i].name, list[i].direccion,
						listadoLocalidad[indiceLocalidad].localidad, list[i].cuit,
						contadorPedPend);
			}
		}
		printf(
				"************************************************************************************************\n\n\n");
		retorno = 0;
	}

	return retorno;
}

int mostrarPedidosPendientes(Clientes *list, Pedidos *listaPedidos, int len,
		int pedidosTam) {
	int i;
	int retorno;
	int iCliente;
	int contadorPedidPend;

	contadorPedidPend = 0;
	retorno = -1;

	if (list != NULL && pedidosTam > 0) {
		contadorPedidPend = contarPedidos(listaPedidos, pedidosTam, PENDIENTE);
		if (contadorPedidPend > 0) {
			printf(
					"\n-------------------------------------------------------------------------\n ID PEDIDO            CUIT            DIRECCION       KILOS A RECOLECTAR\n");
			for (i = 0; i < pedidosTam; i++) {
				iCliente = buscarClientePorId(list, len,
						listaPedidos[i].idCliente);
				if ((listaPedidos[i].estado == PENDIENTE)
						&& (listaPedidos[i].idCliente == list[iCliente].id)) {
					printf("%6d %23s %19s %15d\n", listaPedidos[i].id,
							list[iCliente].cuit, list[iCliente].direccion,
							listaPedidos[i].residuosTotales);
				}
			}
			printf(
					"-------------------------------------------------------------------------\n\n\n");
		} else {
			printf("No se han encontrado pedidos pendientes");
		}

		retorno = 0;
	}

	return retorno;
}

int mostrarPedidosCompletados(Clientes *list, Pedidos *listaPedidos, int len,
		int pedidosTam) {
	int i;
	int retorno;
	int ClienteIndice;
	int contadorPedidosCompletados;

	contadorPedidosCompletados = 0;
	retorno = -1;

	if (list != NULL && pedidosTam > 0) {
		contadorPedidosCompletados = contarPedidos(listaPedidos, pedidosTam,
				COMPLETADO);
		if (contadorPedidosCompletados > 0) {
			printf(
					"\n----------------------------------------------------------------------------------------------------\n ID PEDIDO            CUIT            DIRECCION       KILOS DE PAD     KILOS DE PBD     KILOS DE PP\n");
			for (i = 0; i < pedidosTam; i++) {
				ClienteIndice = buscarClientePorId(list, len,
						listaPedidos[i].idCliente);
				if ((listaPedidos[i].estado == COMPLETADO)
						&& (listaPedidos[i].idCliente == list[ClienteIndice].id)) {
					printf("%6d %23s %19s %11d %16d %16d\n", listaPedidos[i].id,
							list[ClienteIndice].cuit,
							list[ClienteIndice].direccion,
							listaPedidos[i].residuosEspecificos.HDPE,
							listaPedidos[i].residuosEspecificos.LDPE,
							listaPedidos[i].residuosEspecificos.PP);
				}
			}
			printf(
					"----------------------------------------------------------------------------------------------------\n\n\n");
		} else {
			printf("No se han procesado pedidos hasta el momento");
		}
		retorno = 0;
	}

	return retorno;
}

int buscarPedidosPendientesPorLocalidad(Pedidos *listaPedidos, int lenLocalidad,
		int pedidosTam, Localidad *listadoLocalidad, Clientes *listadoDeClientes, int lenClientes) {

	int retorno;
	int indiceLocalidad;
	int contadorPedPend;
	int id;

	retorno = -1;

	mostrarLocalidad(lenLocalidad, listadoLocalidad);
	IngresarEnteroValidado("Ingrese el Id de la localidad:\n", 1, 5, &id);
	indiceLocalidad = retornarIndicePorId(listadoLocalidad, lenLocalidad, id);

	if (indiceLocalidad == -1) {
		printf("No se han registrado pedidos con esa localidad\n");
	} else {
		contadorPedPend = contarPedidosPorLocalidad(listadoLocalidad[indiceLocalidad].id, listaPedidos, pedidosTam, listadoDeClientes, lenClientes);
		if ((contadorPedPend > 0)) {
			printf("La cantidad de pedidos pendientes para %s, es: %d\n",
					listadoLocalidad[indiceLocalidad].localidad,
					contadorPedPend);
		} else {
			printf("La localidad %s, no tiene pedidos pendientes\n",
					listadoLocalidad[indiceLocalidad].localidad);
		}
		retorno = 0;

	}

	return retorno;
}

int promedioPPCliente(Clientes *list, Pedidos *listaPedidos, int len,
		int pedidosTam, float *promedioPPCliente) {
	int i;
	int j;
	int retorno;
	int contadorClientes;
	int acumuladorPP;

	retorno = 0;
	contadorClientes = 0;
	acumuladorPP = 0;

	if (promedioPPCliente != NULL) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty != TRUE) {
				contadorClientes++;
			}
		}
		for (j = 0; j < pedidosTam; j++) {
			acumuladorPP += listaPedidos[j].residuosEspecificos.PP;
		}
		*promedioPPCliente = acumuladorPP / contadorClientes;
		if (*promedioPPCliente > 0) {
			printf(
					"El promedio de polipropileno reciclado por cliente es: %.2f\n\n",
					*promedioPPCliente);
		} else {
			printf(
					"\nNo se han procesado pedidos que contengan polipropileno por el momento\n");
		}
		retorno = 1;
	}

	return retorno;
}

int altaCliente(Clientes *list, int len, int *id, Localidad *listadoLocalidad,
		int locLen) {
	int retorno;
	Clientes clientesParam;
	retorno = -1;

	IngresarCadena("\nIngrese la denominacion social de su empresa:\n ",
			clientesParam.name, 51);
	IngresarCadena("Ingrese direccion: \n", clientesParam.direccion, 51);
	GetCuit(clientesParam.cuit);
	mostrarLocalidad(locLen, listadoLocalidad);
	IngresarEnteroValidado("Ingrese el id de la localidad: \n", 1, 5,
			&clientesParam.idLocalidad);

	if ((agregarCliente(list, clientesParam, len, *id) != -1)) {
		*id = *id + 1;
		retorno = 0;
	} else {
		printf(
				"\nHa ocurrido un error en su peticion. Reintente la operacion...\n");
	}

	return retorno;
}

int modificarCliente(Clientes *list, int len, Localidad *listadoLocalidad,
		int locLen) {
	int id;
	int iCliente;
	int option;
	int retorno;

	retorno = -1;

	mostrarClientes(list, len, listadoLocalidad, locLen);
	IngresarEntero("\nIngrese el ID del cliente que desea modificar: \n", &id);
	iCliente = buscarClientePorId(list, len, id);

	if (iCliente != -1 && list != NULL) {
		IngresarEnteroValidado(
				"1. Direccion\n2. Localidad\nIndique la opcion que desea modificar: ",
				1, 2, &option);
		switch (option) {
		case 1:
			IngresarCadena("Ingrese su nueva direccion: \n",
					list[iCliente].direccion, 51);
			break;

		case 2:
			mostrarLocalidad(locLen, listadoLocalidad);
			IngresarEnteroValidado("Ingrese el Id de su nueva localidad:\n", 1,
					5, &list[iCliente].idLocalidad);
			break;

		}
		retorno = 0;
	}

	return retorno;
}

int mostrarClientes(Clientes *list, int len, Localidad *listadoLocalidad,
		int locLen) {
	int i;
	int retorno;
	int indiceLocalidad;
	retorno = -1;

	if (list != NULL && len > 0) {
		printf(
				"\n***************************************************************************\n ID         NOMBRE         CUIT             DIRECCION            LOCALIDAD   \n");
		for (i = 0; i < len; i++) {
			indiceLocalidad = retornarIndicePorId(listadoLocalidad, locLen,
					list[i].idLocalidad);
			if (list[i].isEmpty != TRUE) {
				printf("%3d %15s %16s %18s %18s\n", list[i].id, list[i].name,
						list[i].cuit, list[i].direccion,
						listadoLocalidad[indiceLocalidad].localidad);
			}
		}
		printf(
				"\n***************************************************************************\n\n\n");
		retorno = 0;
	}

	return retorno;
}

int contarPedidosCompletados(Clientes *list, Pedidos *listadoPedidos, int len,
		int orderLen, int estado) {
	int i;
	int mayorPedidos;
	int iMayorPedidos;
	int contadorPedidos;
	int banderaPedidos;

	banderaPedidos = FALSE;

	for (i = 0; i < len; i++) {
		contadorPedidos = contarrPedidos(list[i].id, listadoPedidos, orderLen,
				estado);
		if ((banderaPedidos == 0) || contadorPedidos > mayorPedidos) {
			mayorPedidos = contadorPedidos;
			iMayorPedidos = i;
			banderaPedidos = TRUE;
		}
	}

	return iMayorPedidos;
}

int contarrPedidos(int id, Pedidos *list, int len, int estado) {
	int i;
	int contadorPedidos;

	contadorPedidos = 0;

	for (i = 0; i < len; i++) {
		if (estado != -1) {
			if ((list[i].idCliente == id) && (list[i].estado == estado)) {
				contadorPedidos++;
			}
		} else {
			if ((list[i].idCliente == id) && ((list[i].estado == PENDIENTE) || (list[i].estado== COMPLETADO))) {
				contadorPedidos++;
			}
		}

	}

	return contadorPedidos;
}

int contarPedidosPorLocalidad(int id, Pedidos *listadoDePedidos, int lenPedidos,
		Clientes *listadoDeClientes, int lenClientes) {
	int i;
	int contador;
	contador=0;

	for (i = 0; i < lenPedidos; i++) {
		for (int j = 0; j < lenClientes; j++) {
			if ((listadoDePedidos[i].idCliente == listadoDeClientes[j].id) && (listadoDeClientes[j].idLocalidad == id)) {
				contador++;
			}
		}
	}
	return contador;
}



int bajaCliente(Clientes *list, int len, int locLen, Localidad *listadoLocalidad) {
	int id;
	int retorno;
	char character;

	retorno = -1;

	if (list != NULL) {
		mostrarClientes(list, len, listadoLocalidad, LOCTAM);/*int mostrarClientes(Clientes *list, int len, Localidad *listadoLocalidad,
				int locLen)*/
		IngresarEntero("\nIngrese el ID del cliente que desea dar de baja: ",
				&id);
		IngresarCaracterValidado(
				"\nDesea confirmar la baja del cliente?\nIndique 's' (si) o 'n' (no): \n",
				&character, 's', 'n');
		if (character == 's') {
			eliminarCliente(list, len, id);
			retorno = 1;
		} else {
			printf("\nSe ha cancelado la baja del cliente");
			retorno = 0;
		}
	}

	return retorno;
}


