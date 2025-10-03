#include "funcheck.h"

bool is_valid_input(int argc, char *argv[]) {
	(void)argv;
	if (argc == 1)
		return (true);
	//...
	return (true);
}

/*
	dont know if i even should validate input or not because why
	open every directory for validation and then close it and then
	open it again..
*/