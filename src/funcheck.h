#ifndef FUNCHECK_H
#define FUNCHECK_H

#include "errors.h"

#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>   // For opendir, readdir, closedir
#include <unistd.h>   // For access()
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <strings.h>

typedef enum s_type {
	NONE,
	IS_FILE,
	IS_DIRECTORY,
	NOACCESS,
	OTHER
}	e_type;


//	types 
// bool	is_directory(const char *path);
e_type	find_type(const char *path);


// errors
void	write_err(char *msg, char *keyword);


#endif