#include "msplib_common.h"
#include <msp430g2553.h>
#include <config_lib.h>

void default_state(void)
{
	/* by default all GPIO should be in IN (High Impedance) direction */
	P1DIR = 0x00;
	P2DIR = 0x00;
	P1REN = 0x00;
	P2REN = 0x00;
}

void clock_init(void)
{
#if DCO_CLK==1
	/* Set DCO to 1 MHz */
	DCOCTL = CALDCO_1MHZ;				//calibrate DCO
	BCSCTL1 = CALBC1_1MHZ;				//calibrate basic clock
#elif DCO_CLK==8
	DCOCTL = CALDCO_8MHZ;				//calibrate DCO
	BCSCTL1 = CALBC1_8MHZ;				//calibrate basic clock
#elif DCO_CLK==12
	DCOCTL = CALDCO_12MHZ;				//calibrate DCO
	BCSCTL1 = CALBC1_12MHZ;				//calibrate basic clock
#elif DCO_CLK==16
	DCOCTL = CALDCO_16MHZ;				//calibrate DCO
	BCSCTL1 = CALBC1_16MHZ;				//calibrate basic clock
#endif

	/* MCLK - 1MHz (MCLK = DCO/1)*/
	/* SMCLK - 1MHz (SMCLK = DCO/1)*/
	BCSCTL2 = SELM_0 | DIVM_0 | /*SELS |*/ DIVS_0; // .
}
