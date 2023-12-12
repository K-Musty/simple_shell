#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <wchar.h>

/**
 * struct main_instruction - The main struct instruction
 * @instructio: instruction pointer arg
 * @pointer: pointer indicating ahead next
 */
typedef struct main_instuction
{
	char **instruction;
	struct main_instruction *pointer;
} cool_instruction;

size_t _parser_arg(char *, char **, size_t *);
void print_char_pointer_arr(char **, size_t);
void print_listint(const history_t *);
int verif_built_comm(char *str, char **env);

void cool_error_handl(char *, int);

/**
 * struct cool_error - ERROR STRUCTURE
 *
 * @size: length of the displayed error
 * @error_out: error display key
 * @output: character pointer
 */
typedef struct cool_error
{
	int size;
	int error_out;
	char *output;/*character pointer*/
} cool_error_out;

int cool_main(int argc, char **argv, char **env);
cool_instruction **cool_prompt(char *entry, char *cool_arg);
cool_instruction *cool_space_parser(char *term, char *entry);
char *cool_in_line(void);
int cool_fork(char *entry, cool_instruction *cool_node, char *_pth, char **env);
void cool_exit_fuction(char **envi);
int cool_execute(char *instruction, char **instruct, char **env);
int cool_detail(char *entry, char *instrut);
char *cool_path(char **enviroment);
char cool_find(char *path_k, char *cool_ar);
cool_instruction *cool_get_term(char *entry);
void cool_token(char *dry, cool_instruction cool_node, size_t srt, char *keyy);

size_t strlength(char *string);
char *strdupl(char *string);
int strcom(char *string, char *strr);
char *str_conc(char *string, char *strr, unsigned int num);
char *strcoin(char *adam, char *kalli);
void cool_print_env(char **enviroment)
#endif
