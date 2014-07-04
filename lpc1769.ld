ENTRY(ResetISR)

MEMORY
{
	flash (rx) : ORIGIN = 0x00000000, LENGTH = 512K
	ram (wr) : ORIGIN = 0x10000000, LENGTH = 32K
}

vTopStack = ORIGIN(ram) + LENGTH(ram);

SECTIONS
{
	.text :
	{
		KEEP(*(.isrvectors))
		. = ALIGN(4);
		*(.text)
		*(.rodata)
		*(.rodata*)
		. = ALIGN(4);
		_endflash = .;
	} > flash
	
	.data :
	{
		. = ALIGN(4);
		_start_data = .;
		*(.data)
		. = ALIGN(4);
		_end_data = .;
	} >  ram AT > flash
	
	.bss :
	{
		. = ALIGN(4);
		_start_bss = .;
		*(.bss)
		. = ALIGN(4);
		_end_bss = .;
	} >  ram
}