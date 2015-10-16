/**
*		Design Of Software For Embedde Systems
*
*						TASK-1-4
*
*	Authors:
*	Milad Lashini
*	Saeid Yazdani
*/

#include "stdio.h"
#include "stdint.h" //best friend of embedded programmers

//name of the executable (read from Makefile)
#ifndef EXECUTABLE_NAME			//if app name is not supplied through make
#define EXECUTABLE_NAME			"bitcount" //default name of app
#endif

//error codes
#define ERROR_INVALID_ARG_COUNT		1
#define ERROR_INVALID_ARG_RANGE		2

/* function declarations start */
int exit_application(int error_code);
uint8_t count_set_bits(uint32_t i);
/* function declarations end */

int main (int argc, char *argv[]) {

	 /*	checking for valid argument count and value	*/

	//we should only have 1 argument!
	//note that the './executable' also counts as an argument itself!
    if (argc != 2 ){
 		return exit_application(ERROR_INVALID_ARG_COUNT);
 	}

 	//check for validty of argument (should be 0 to UINT32_MAX)
 	//TODO this can not tell if the given argument was integer or string(char)
 	//c's atoi() function will case almost anything to integer!!! bad bad bad!
	uint32_t value = atoi(argv[1]); //convert argument 1 to integer
	if((value > UINT32_MAX || value < 0)) {
		return exit_application(ERROR_INVALID_ARG_RANGE);
	}

    //correct argument...doing what we supposed to do :) pfffffff......
    printf("%d\n", count_set_bits(value)); //XOR with 255 to reverse the bits

    return 0; //alles klaaaaaaaaar
}

/* function definitons start */

/**
*	@brief	Prints usage message and exits the application with given code
*	@param error_code	The error code to end the application with
*	@return	int	The error code to the stdio
*/
int exit_application(int error_code) {
	switch(error_code) {

		case ERROR_INVALID_ARG_COUNT:
			printf("no or invalid arguments. usage: %s [0,%u]\n"
				, EXECUTABLE_NAME, UINT32_MAX);
			return error_code;

		case ERROR_INVALID_ARG_RANGE:
			printf("argument should be between 0 and %u. usage: %s [0,%u]\n"
				, UINT32_MAX, EXECUTABLE_NAME, UINT32_MAX);
			return error_code;

		default:
			return 3; //this should never happen, but to be safe ;)
	}
}

/**
*	@brief	Counts the number of set bits (1's) in a number < UINT32_MAX
*			Using parallel SWAR algorithm. Performance is architecture
*			dependent.
*			
*	@param 	i 	The number to check number of set bits in it
*	@return	int	Number of ones in its bits
*/
uint8_t count_set_bits(uint32_t i) {
	 i = i - ((i >> 1) & 0x55555555); //01010101
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333); //00110011
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
     //0x0F0F0F0F - 0000111100001111
}

/* function definitons end */
