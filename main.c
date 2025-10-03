#include "funcheck.h"

/*
	funcheck() prints out a list of all (external) functions used
	in any file of the current/specified directory and any subdirectory
*/



void fnchk(char *entry) {
	e_type	type = find_type(entry);
	if (type == IS_DIRECTORY) {
		//...
	}
	else if (type == IS_FILE) {
		//...
	}
	else if (type == NOACCESS) {
		write_err(PERMISSION_DENIED, entry);
	}
	else if (type == NONE) {
		write_err(NOFILE, entry);
	}
	else if (type == OTHER) {
		write_err(UNRECOGNIZED_FILE, entry);
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		fnchk(".");
	}
	else {
		for (int i = 1; i < argc; i++)
			fnchk(argv[i]);
	}
}

//  argc = 3
//  argv[0]  [1]  [2]
// ./fnchk   kur  eee



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