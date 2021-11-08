/*
 ============================================================================
 Name        : ParcialLabo1.c
 Author      : Leandro Mu�oz DIV C
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Nexo.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int id;
	int pedidoId;
	float promedioPoliprop;
	int banderaDeAlta;
	int banderaDePedido;
	int masPedidosCompletados;
	int masPedidosPendientes;
	int masPedidos;
	Clientes arrayClientes[TAM];
	Localidad arrayLocalidades[LOCTAM] = { { 1, "Burzaco" }, { 2, "Jose Marmol" },
			{ 3, "San Jose" }, { 4, "Adrogue" }, { 5, "Claypole" } };

	Pedidos arrayPedidos[T];


	opcion=0;
	id = 0;
	pedidoId = 0;
	promedioPoliprop = 0;
	banderaDeAlta = 0;
	banderaDePedido = 0;



	inicializarClientes(arrayClientes, TAM);
	inicializarPedidos(arrayPedidos, T);

	do {
		IngresarEnteroValidado(
				"*******************************************************\n 1.ALTA DE CLIENTE \n 2.MODIFICACION DATOS DE CLIENTE\n 3.BAJA DE CLIENTE\n 4.CREAR PEDIDO DE RECOLECCION\n 5.PROCESAR RESIDUOS\n 6.IMPRIMIR CLIENTES\n 7.IMPRIMIR PEDIDOS CLIENTES\n 8.IMPRIMIR PEDIDOS PROCESADOS\n 9.MOSTRAR PEDIDOS PENDIENTES DE LA LOCALIDAD\n 10.PROMEDIO DE KILOS DE POLIPROPILENO POR CLIENTE\n 11.MOSTRAR LOS CLIENTES CON MAYOR CANTIDAD DE PEDIDOS\n 0.SALIR DEL PROGRAMA\n******************************************************* \nSeleccione la opcion deseada:\n",
				0, 11, &opcion);
		switch (opcion) {
		case 1:
			if (altaCliente(arrayClientes, TAM, &id, arrayLocalidades, LOCTAM)
					== -1) {
				printf(
						"\nHa ocurrido un error en su peticion de ALTA DE CLIENTE. Por favor, reintente la operacion.\n");
			} else {
				printf("\nEl usuario fue dado de alta exitosamente.\n");

				banderaDeAlta = 1;
			}

			break;

		case 2:
			if (banderaDeAlta == 1) {
				if (modificarCliente(arrayClientes, TAM, arrayLocalidades,
						LOCTAM) == -1) {
					printf(
							"\nHa ocurrido un error en su peticion de MODIFICACION DATOS DE CLIENTE. Por favor, reintente la operacion.\n");
				} else {
					printf("\nLa modificacion se ha realizado exitosamente.\n");
				}
			} else {
				printf(
						"\nPara continuar con el programa, por favor cargue en el sistema al menos un usuario.\n");
			}

			break;

		case 3:
			if (banderaDeAlta == 1) {
				if (bajaCliente(arrayClientes, TAM, LOCTAM, arrayLocalidades) == -1) {
					printf(
							"\nHa ocurrido un error su peticion de BAJA DE CLIENTE. Por favor, reintente la operacion.\n");
				}else {
					printf("\nLa baja del cliente se ha realiza con exito.\n");
				}
			} else {
				printf(
						"\nPara continuar con el programa, por favor cargue en el sistema al menos un usuario.\n");
			}

			break;

		case 4:
			if (banderaDeAlta == 1) {
				if (mostrarClientes(arrayClientes, TAM, arrayLocalidades,
						LOCTAM) == -1) {
					printf(
							"Ha ocurrido un error en su peticion de CREAR PEDIDO DE RECOLECCION. Por favor, reintente la operacion.\n");
				} else {
					if (crearPedido(arrayClientes, arrayPedidos, TAM, T,
							&pedidoId) != -1) {
						printf(
								"El pedido de recolección se ha creado con exito.\n");
						banderaDePedido = 1;
					} else {
						printf(
								"Ha ocurrido un error en su peticion de CREAR PEDIDO DE RECOLECCION. Por favor, reintente la operacion.\n");
					}
				}
			} else {
				printf(
						"Para continuar con el programa, por favor cargue en el sistema al menos un usuario.\n");
			}

			break;

		case 5:
			if (banderaDeAlta == 1 && banderaDePedido == 1) {
				if (PedidosProcesados(arrayPedidos, T) == -1) {
					printf(
							"Ha ocurrido un error en su peticion de PROCESAR RESIDUOS. Por favor, reintente la operacion.\n");
				} else {
					printf("Los residuos se han procesado con exito.\n");
				}
			} else {
				printf(
						"Para continuar con el programa, por favor cargue en el sistema al menos un usuario.\n");
			}

			break;

		case 6:
			if (banderaDeAlta == 1 && banderaDePedido == 1) {
				if (mostrarPedidosPendientesClientes(arrayClientes,
						arrayPedidos,
						TAM, T, arrayLocalidades,LOCTAM) == -1) {
					printf(
							"Ha ocurrido un error en su peticion de IMPRIMIR CLIENTES . Por favor, reintente la operacion.\n");
				}
			} else {
				printf(
						"Para continuar con el programa, por favor cargue en el sistema al menos un usuario.\n");
			}

			break;

		case 7:
			if (banderaDeAlta == 1 && banderaDePedido == 1) {
				if (mostrarPedidosPendientes(arrayClientes, arrayPedidos, TAM,
						T) == -1) {
					printf(
							"Ha ocurrido un error en su peticion de PEDIDOS PENDIENTES . Por favor, reintente la operacion.\n");
				}
			} else {
				printf(
						"Para continuar con el programa, por favor cargue en el sistema al menos un usuario.\n");
			}

			break;

		case 8:
			if (banderaDeAlta == 1 && banderaDePedido == 1) {
				if (mostrarPedidosCompletados(arrayClientes, arrayPedidos, TAM,
						T) == -1) {
					printf(
							"Ha ocurrido un error en su peticion de IMPRIMIR PEDIDOS PROCESADOS. Por favor, reintente la operacion.\n");
				}
			} else {
				printf(
						"Para continuar con el programa, por favor cargue en el sistema al menos un usuario.\n");
			}

			break;

		case 9:
			if (banderaDeAlta == 1 && banderaDePedido == 1) {
				if (buscarPedidosPendientesPorLocalidad(arrayPedidos, LOCTAM,
				T, arrayLocalidades, arrayClientes, TAM) == -1) {
					printf(
							"\nHa ocurrido un error en su peticion de MOSTRAR PEDIDOS PENDIENTES DE LA LOCALIDAD. Por favor, reintente la operacion.\n");
				}
			} else {
				printf(
						"\nPrimero debe dar de alta al menos un cliente y/o pedido\n");
			}

			break;

		case 10:
			if (banderaDeAlta == 1 && banderaDePedido == 1) {
				if (promedioPPCliente(arrayClientes, arrayPedidos,
				TAM, T, &promedioPoliprop) == -1) {
					printf(
							"\nHa ocurrido un error en su peticion de mostrar PROMEDIO DE KILOS DE POLIPROPILENO POR CLIENTE. Por favor, reintente la operacion.\n");
				}
			} else {
				printf(
						"\nPrimero debe dar de alta al menos un cliente y/o pedido\n");
			}

			break;

		case 11:
			if(banderaDeAlta==1 && banderaDePedido==1){
				masPedidosPendientes=contarPedidosCompletados(arrayClientes, arrayPedidos, TAM, T, PENDIENTE);
				printf("\nLa denominacion social de la empresa con mas pedidos PENDIENTES es: %s\n", arrayClientes[masPedidosPendientes].name);
				masPedidosCompletados=contarPedidosCompletados(arrayClientes, arrayPedidos, TAM, T, COMPLETADO);
							printf("\nLa denominacion social de la empresa con mas pedidos COMPLETADOS es: %s\n", arrayClientes[masPedidosCompletados].name);
							masPedidos=contarPedidosCompletados(arrayClientes, arrayPedidos, TAM, T,-1);
										printf("\nLa denominacion social de la empresa con mas pedidos es: %s\n", arrayClientes[masPedidos].name);
			}
			break;
		}
	} while (opcion != 0);

	return EXIT_SUCCESS;
}

