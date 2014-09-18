/*
 * main.c
 *
 *  Created on: 05/10/2012
 *      Author: cuki
 */
#include<18F452.h>
#DEVICE ADC=10

#fuses HS,NOOSCSEN,NOPUT,NOBROWNOUT,NOWDT,NOSTVREN,NOLVP,NODEBUG,NOPROTECT,NOCPB,NOCPD,NOWRT,NOWRTC,NOWRTB,NOWRTD,NOEBTR,NOEBTRB
#use delay(clock=8MHz)
#use rs232(baud=9660, xmit=pin_c6, rcv=pin_c7)

#include "press.h"

int main(void) {

	delay_ms(500);

	setup_DAC();
	reset_variables();

	while (true) {
		delay_ms(300);
		if (check(512))
			printf("Dentro %f \n%4Lu %d", mostra_media(), mostra_leitura(),
					mostra_nrelementos());
		else
			printf("\Fora   %f \n%4Lu %d", mostra_media(), mostra_leitura(),
					mostra_nrelementos());
		puts("");
	}
	return 0;
}
