#include "funcheck.h"

static char *get_name(char *dir, char *name) {
	int len = strlen(dir) + strlen(name) + 1;
	char *full_name = calloc((len + 1), sizeof(char));
	if (!full_name)
		return (NULL);
	strcpy(full_name, dir);
	full_name[strlen(dir)] = '/';
	strcat(full_name, name);
	return (full_name);
}

void fnchk(char *entry, e_type type, char *funlst[]) {
	if (type == IS_FILE) {
		get_functions(entry, funlst);
	}
	else if (type == IS_DIRECTORY) {
		errno = 0;
		DIR *directory = opendir(entry);
		if (!directory) { perror("opendir: "); return ; }
		
		struct dirent *new_entry = readdir(directory);
		while (new_entry) {
			if (*new_entry->d_name != '.') {
				if (*entry == '.')
					fnchk(new_entry->d_name, find_type(new_entry->d_name), funlst);
				else {
					char *new_name = get_name(entry, new_entry->d_name);
					if (!new_name) { perror("malloc: "); exit(1); }
					fnchk(new_name, find_type(new_name), funlst);
					free(new_name);
				}
			}
			new_entry = readdir(directory);
		}
		closedir(directory);
		if (errno)
			perror("readdir: ");
	}
}
