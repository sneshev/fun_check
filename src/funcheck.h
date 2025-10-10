#ifndef FUNCHECK_H
#define FUNCHECK_H

#include "errors.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>   // For opendir, readdir, closedir
#include <unistd.h>   // For access()
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <strings.h>
#include <string.h>

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

// 
void fnchk(char *entry, e_type type, char *funlst[]);
void get_functions(char *filename, char *funlst[]);


void write_err(char *msg, char *keyword);


#endif