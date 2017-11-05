# Simple Buffer Overflow Attack Example

This program demonstrates a simple buffer overflow attack

## Usage
1. run `make` or `make all`. This will compile the vulnarable program into an executable called vuln_program, and the string generator into attack-string

2. Using objdump and/or GDB, find the address of the target function, and calculate the number of bytes needed to overflow the stack into the stored %eip register (112 bytes for this program. 108 for the buffer + 4 for %ebp)

3. Run `./attack-string <BIG_ENDIAN_ADDRESS> [<PAD_AMOUNT>]` to generate the attack string
	* 	BIG_ENDIAN_ADDRESS - The big endian address of the target function 
	* 	PAD_AMOUNT (optional) - The number of bytes needed before the target address
	*	optionally add > outfile to redirect the output to a file
	
	This will output the attack string in the format AAAA...AAAA<LITTLE_ENDIAN_ADDRESS_IN_ASCII>

4. Run `./vuln_program < <GENERATED_ATTACK_STRING>`. If everything went right this should overflow the buffer and call the target function printing "Haha! You got pwned!"
