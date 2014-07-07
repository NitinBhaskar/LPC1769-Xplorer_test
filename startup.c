#include <stdio.h>
#include <stdint.h>
#include "LPC17xx.h"

extern unsigned int vTopRam;

extern int main(void);

void ResetISR(void);

__attribute__((section(".isrvectors")))
void (* vecTable[])(void) =
{
	&vTopRam,
	ResetISR
};
void ResetISR(void)
{
	LPC_SC->FLASHCFG  = (LPC_SC->FLASHCFG & ~0x0000F000) | 0x00004000;
	main();
	while (1)
		;
}
