/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:20:02 by waziz             #+#    #+#             */
/*   Updated: 2024/03/13 10:15:12 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Create with our hands
#include "Libft/libft.h"

// Standard libraries
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <readline/readline.h>
#include <readline/history.h>

extern char **environ;

typedef struct s_export
{
    void    **ptr_tab;
    int     count_ptr;
    int     not_environ;
    int     status;
}           t_export;

typedef struct  s_token
{
    char    **argument;
    char    *cmd;
    char    *operator;
    char    **arg_opérator;
    int     pipe;
    int     quotes;
    char    *next;
}   t_token;

// all opérators
int             redirect_input(char *filename);
int             redirect_output(char *filename);
int             redirect_input_command(void (*f)(char *), char *end);
int             redirect_stdout_append(const char *fichier);
int             ft_pipe(int fd_out, int fd_in);

// all commandes
int             dollars(char *var_name, int option);
int             last_return(int value);
int             echo(char *input);
int             echon(char *input);
int             echo_input_file();
int             cd(char *path);
int             pwd();
int             export(char *v_env, t_export *alloctrack);
int             ft_unset(const char *var_name, t_export *alloctrack);
int             ft_env(void);
void            ft_exit();

// utils export
struct t_export *init(t_export *alloctrack);

// wildcards
char            **all_files();
char            **filter_a(char *input);
char            **filter_b(char *input);
char            **filter_more(char *input);
char            **wilcards(char *input);

// free
void            free_tab(char **entries);
void            free_at(t_export *alloctrack);

// error
int             error_zero(int num);
char            *error_null(int n);
int             error_neg(int n);

// utils parsing argument (!! LEXING !!)
char            *dollars_lex(char *var_name);
int             check_wildcard(char *s);
int             check_dollars(char **arg_more);
char            **alloc_tab(char *arg);
char            *ft_strcat(char *dst, char *src);
void            squote_parse(char *arg, char **arg_more, int t);

// parsing argument (!! LEXING !!)
char            *convert_n_concat(char **arg_more);
void            replace_argument(t_token *tokens);

#endif