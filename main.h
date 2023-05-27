#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>

extern char **environ;

typedef struct list_s
{
	const char *str;
	struct list_s *next;
} list_t;

char **_strtok(char *str, const char *delim);
int _fork(void);
void _execve(const char *pathname, char *const argv[], char *const env[]);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_getenv(const char *name);
char *_strstr(char *haystack, const char *needle);
char *path_dir(char *program);
list_t *add_node_end(list_t **head, const char *str);
size_t print_list(const list_t *h);
void delete_node(list_t **head, char *key);
void path_dir_list(void);
int _setenv(const char *name, const char *value, int overwrite);
char *_strdup(const char *str);
char *str_concat(char *s1, char *s2);
void _free(char **argv);
void _isatty(void);
int _strlen(char *s);

#endif /* _MAIN_H_ */
