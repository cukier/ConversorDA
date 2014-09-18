/*
 * press.h
 *
 *  Created on: 11/10/2012
 *      Author: cuki
 */

#ifndef PRESS_H_
#define PRESS_H_
#define buffer_size 10

long value[buffer_size], *from, *to, somaElementos, leitura;
int cont, nrElementos;
float media;

void reset_variables(void) {
	for (cont = 0; cont < buffer_size; cont++) {
		value[cont] = 0;
	}
	somaElementos = leitura = nrElementos = media = 0;
	from = to = '\0';
}

void setup_DAC(void) {
	setup_adc(ADC_CLOCK_INTERNAL);
	setup_adc_ports(AN0_AN1_VSS_VREF);
	set_adc_channel(0);
}

float push(long dado) {
	leitura = value[nrElementos] = dado;
	somaElementos += dado;
	nrElementos++;
	if (nrElementos == buffer_size) {
		nrElementos--;
		somaElementos -= value[0];
		to = value;
		from = to + 1;
		for (cont = 0; cont < buffer_size; cont++) {
			*to = *from;
			to++;
			from++;
		}
	}
	media = (float) somaElementos / nrElementos;
//	leitura = value[nrElementos - 1];
	return media;
}

short check(float max) {
	return push(1023 - read_adc()) >= max ? 0 : 1;
}

float mostra_media(void) {
	return media;
}

long mostra_leitura(void) {
	return leitura;
}

int mostra_nrelementos(void) {
	return nrElementos;
}

#endif /* PRESS_H_ */
