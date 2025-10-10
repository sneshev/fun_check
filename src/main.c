#include "funcheck.h"

/*
	funcheck() prints out a list of all (external) functions used
	in any file of the current/specified directory and any subdirectory
*/


int main(int argc, char *argv[]) {
	char *funlst[256];
	bzero(funlst, 256 * sizeof(char *));

	if (argc == 1) {
		fnchk(".", IS_DIRECTORY, funlst);
	} else {
		for (int i = 1; i < argc; i++) {
			e_type type = find_type(argv[i]);
			if (type == IS_DIRECTORY || type == IS_FILE) {
				fnchk(argv[i], type, funlst);
			}
			else if (type == NOACCESS)
				write_err(PERMISSION_DENIED, argv[i]);
			else if (type == NONE)
				write_err(NOFILE, argv[i]);
			else
				write_err(UNRECOGNIZED_FILE, argv[i]);
		}
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


/*
	for readdir():
       If  the  end  of the directory stream is reached,
       NULL is returned and errno is not changed.  If an
       error occurs, NULL is returned and errno  is  set
       to  indicate  the  error.   To distinguish end of
       stream from an error, set errno  to  zero  before
       calling readdir() and then check the value of er‐
       rno if NULL is returned.
*/