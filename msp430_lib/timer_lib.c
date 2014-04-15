#include <msp430g2553.h>
#include <config_lib.h>
#include "timer_lib.h"

void timer_init(void)
{
#ifdef CONF_TIMER_A0_USE
    TA0CTL = 0;
#if defined(CONF_TIMER_A0_SRC_TACLK)
#elif defined(CONF_TIMER_A0_SRC_ACLK)
#elif defined(CONF_TIMER_A0_SRC_SMCLK)
    TA0CTL |= TASSEL_2;
#elif defined(CONF_TIMER_A0_SRC_INCLK)
#else
#error Undefined TA0 source
#endif

#if CONF_TIMER_A0_DIV == 1
    TA0CTL |= ID_0;
#elif CONF_TIMER_A0_DIV == 2
    TA0CTL |= ID_1;
#elif CONF_TIMER_A0_DIV == 4
    TA0CTL |= ID_2;
#elif CONF_TIMER_A0_DIV == 8
    TA0CTL |= ID_3;
#else
#error Wrong TA0 divider
#endif

#ifdef CONF_TIMER_A0_MODE_UP_TO_CCR0
    TA0CTL |= MC_1;
#elif defined CONF_TIMER_A0_MODE_UP
    TA0CTL |= MC_2;
#elif defined CONF_TIMER_A0_MODE_UP_DOWN
    TA0CTL |= MC_3;
#endif

#ifdef CONF_TIMER_A0_IE
    TA0CTL |= TAIE;
#endif
#endif

#if 0
	/* Timer A */
	/* Source SMCLK (1MHz) TASSEL_2
	 * divider 8 (125 kHz) ID_3
	 * Mode UP/Down MC_3
	 * Interrupt enable TAIE
	 */
#ifdef CONF_TIMER_A0_SRC_SMCLK
    TA0CTL = TASSEL_2 | ID_3 | MC_3 | TAIE;
    TA0CCR0 = 0xF424; /* 125 kHz / 2 */
#endif
#endif
}

