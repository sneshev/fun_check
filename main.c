#include "funcheck.h"

/*
	funcheck() prints out a list of all (external) functions used
	in any file of the current/specified directory and any subdirectory
*/

int main(int argc, char *argv[]) {

}

/*
	1.initialize
	2.check arguments
	3.opendir(".")
	4.run a function to go through the stream and if its a file check it and if its a directory call recursively
		->check for permissions
		->read the file and identify all functions used
		->add to list, if not already added
	
	.am gonna need cool print messages and errors
	.am gonna need to create a list/array for the functions already used
	.
*/