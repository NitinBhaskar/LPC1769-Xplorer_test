#include <stdio.h>
#include "LPC17xx.h"

#define LED_BIT_POS 10
int main(void)
{
	int i;
	LPC_GPIO0->FIODIR |= (1 << LED_BIT_POS);
	LPC_GPIO0->FIOCLR |= (1 << LED_BIT_POS);
	while(1)
	{
		LPC_GPIO0->FIOCLR |= (1 << LED_BIT_POS);
		for (i = 0; i < 0xFFFF ; i++);
		LPC_GPIO0->FIOSET |= (1 << LED_BIT_POS);
		for (i = 0; i < 0xFFFF ; i++);
	}
	return 0;
}