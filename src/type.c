#include "funcheck.h"

/*
	is_file() (with permission and stff..), is_dir(), etc. utils
*/

e_type find_type(const char *path) {
	struct stat	st;	

	if (access(path, F_OK) != 0)
	    return NONE;

	if (access(path, R_OK) != 0 || stat(path, &st) != 0)
	    return NOACCESS;

	if (S_ISREG(st.st_mode))
		return (IS_FILE);
	if (S_ISDIR(st.st_mode))
		return (IS_DIRECTORY);
	return (OTHER);
}