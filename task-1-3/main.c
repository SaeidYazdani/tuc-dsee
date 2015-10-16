/**
*		Design Of Software For Embedde Systems
*
*						TASK-1-3
*	Description:
*		This program takes a unsigned char (8 bit) and reverses its bits.
*
*	Authors:
*	Milad Lashini
*	Saeid Yazdani
*/

#include "stdio.h"

//name of the executable (read from Makefile)
#ifndef EXECUTABLE_NAME			//if app name is not supplied through make
#define EXECUTABLE_NAME			"bitreverse" //default name of app
#endif

//error codes
#define ERROR_INVALID_ARG_COUNT		1
#define ERROR_INVALID_ARG_RANGE		2

/* function declarations start */
int exit_application(int error_code);
/* function declarations end */

int main (int argc, char *argv[])
{

	 /*	checking for valid argument count and value	*/

	//we should only have 1 argument!
	//note that the './executable' also counts as an argument itself!
    if (argc != 2 ){
 		return exit_application(ERROR_INVALID_ARG_COUNT);
 	}

 	//check for validty of argument (should be 0 t0 255)
 	//TODO this can not tell if the given argument was integer or string(char)
 	//c's atoi() function will case almost anything to integer!!! bad bad bad!
	int value = atoi(argv[1]); //convert argument 1 to integer
	if((value > 255 || value < 0)) {
		return exit_application(ERROR_INVALID_ARG_RANGE);
	}

    //correct argument...doing what we supposed to do :) pfffffff......
    printf("%d\n", value ^= 0xFF); //XOR with 255 to reverse the bits

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
			printf("no or invalid arguments. usage: %s [0,255]\n"
				, EXECUTABLE_NAME);
			return error_code;

		case ERROR_INVALID_ARG_RANGE:
			printf("argument should be between 0 and 255. usage: %s [0,255]\n"
				, EXECUTABLE_NAME);
			return error_code;

		default:
			return 3; //this should never happen, but to be safe ;)
	}
}

/* function definitons end */
