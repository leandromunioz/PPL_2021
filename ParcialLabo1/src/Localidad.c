/*
 * Localidad.c
 *
 *  Created on: 25 oct. 2021
 *      Author: Leandro
 */

#include "Localidad.h"

int inicializarLocalidad(Localidad *list, Localidad pedido, int len) {
	int i;
	int retorno;
	Localidad auxiliar[LOCTAM] = { { 1, "Quilmes" }, { 2, "Rafael Calzada" }, {
			3, "Jose Marmol" }, { 4, "Burzaco" }, { 5, "Adrogue" } };
	retorno = -1;

	if (len > 0 && list != NULL) {

		for (i = 0; i < len; i++) {
			list[i] = auxiliar[i];
		}
		retorno = 0;
	} else {
		printf(
				"\nHa ocurrido un error en su peticion. Reintente la operacion...\n");
	}

	return retorno;
}

int mostrarLocalidad(int len, Localidad *listadoLocalidad) {
	int i;
	int retorno;

	retorno = -1;

	if (listadoLocalidad != NULL && len > 0) {
		printf(
				"\n************************************\n ID            LOCALIDAD   \n");
		for (i = 0; i < len; i++) {

			printf("%3d %18s\n", listadoLocalidad[i].id,
					listadoLocalidad[i].localidad);

		}
		printf("\n************************************\n");
		retorno = 0;
	}

	return retorno;
}

int retornarIndicePorId(Localidad *listadoLocalidad, int len, int id) {

	int retorno;
	int i;
	int bandera;
	bandera = 0;
	retorno = -1;
	i=0;

	while ((i < len) && (bandera == 0)) {

		if (listadoLocalidad[i].id == id) {
			retorno = i;
			bandera = 1;
		} else {
			i++;
		}
	}
	return retorno;
}
