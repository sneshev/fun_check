#include "funcheck.h"

bool is_c_file(char *file) {
	if (!file || !*file)
		return (false);

	int len = strlen(file);
	if (len <= 2)
		return (false);
	if (file[len - 2] != '.')
		return (false);
	if (file[len - 1] != 'c')
		return (false);
	return (true);
}

void get_functions(char *filename, char *funlst[]) {
	(void)funlst;
	if (is_c_file(filename))
		printf("%s\n", filename);

}


/*
	.use read() to read the whole file.
	.if i encounter a {, i need to increase a "brace depth" counter. When i find a }, i decrease
		->if the counter is pisitive, i am inside of a function, therefore searching for functions
	.if i encounter a single quote ' or double quotes ", i need to ignore (skip) everything inside
	.comments:
		->if i encounter //, i need to ignore everything until the end of the line
		->if i encounter / *, i need to ignore everything until the end of comment
	
	.if i encounter ( that means maybe that is a function, therefore read_prev_word().
		->i need a list of keywords to ignore such as if, while, for, ..
		->i need to discern between functions and other things like:
			! if (!str || (type != 'r' && type != 'w'))
			! S_ISDIR(st.st_mode)
			! sizeof(char *)
		meaning i will have to look at the previous word. If before the spaces the thing is 
		alphanumeric or underscore, i need to substr() the whole word. If before the spaces is
		another symbol such as || or &&, then this is not a function. Im not sure about things
		that expand, such as S_ISDIR.?

	.i will need to save all the internal functions somewhere so that i can check that the 
	functions used are external. so if the depth counter is 0 and there is a function, this is 
	the function being defined and this is an internal function
*/