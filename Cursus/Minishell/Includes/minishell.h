/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:20:02 by waziz             #+#    #+#             */
/*   Updated: 2024/03/21 10:24:33 by waziz            ###   ########.fr       */
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
}   t_export;

typedef struct  s_parse
{
    char    *input;
    int     quote;
    int     r_op;
    int     l_op;
    int     dr_op;
    int     lr_op;
    int     pipe;
}   t_parse;

typedef struct  s_token
{
    char    **argument;
    char    *cmd;
    char    *operator;
    char    *arg_operator;
    int     pipe;
    char    *next;
}   t_token;

// all opérators
int             redirect_input(char *filename);
int             redirect_output(char *filename);
int             redirect_input_command(char *end);
int             redirect_stdout_append(const char *fichier);
int             ft_pipe(int fd_out, int fd_in);

// all commandes
int             dollars(char *var_name, int option);
char            *last_return(int value);
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
void            erase_quote_a(char *input, char *tmp);
void            skip_quote_a(char *input, int skip_a, int quote);
char            **filter_b(char *input);
void            erase_quote_b(char *input, char *tmp);
void            skip_quote_b(char *input, int skip_b, int quote);
char            **filter_more(char *input);
char            **init_search(char *tmp);
char            **wilcards(char *input);

// free
void            free_tab(char **entries);
void            free_at(t_export *alloctrack);

// error
int             error_zero(int num);
char            *error_null(int n);
int             error_neg(int n);

// utils parsing
char            *dollars_lex(char *var_name);
char            *ft_strcat(char *dst, char *src);
char            *convert_n_concat(char **arg_more, t_export *alloctrack);
char            **alloc_tab(char *arg);
void            quote_parse(char *arg, char **arg_more, int t);
int             check_tabdollars(char **arg_more);
int             check_wildcard(char *s);
int             erase_quote(char *s);
void            replace_argument(char **argument, t_export *alloctrack);

// parsing
int             ft_parsing(char **argument, t_export *alloctrack);

// utils command not found
int             error_echo(char *cmd);
int             error_cd(char *cmd);
int             error_pwd(char *cmd);
int             error_export_unset_env(char *cmd);
int             error_exit(char *cmd);

// command not found
int             command_not_found(char *cmd);

// utils lexing cmd
int             make_echo(t_token *tokens);
int             make_echon(t_token *tokens);
int             make_cd(t_token *tokens);
int             make_pwd(t_token *tokens);
int             make_export(t_token *tokens, t_export *alloctrack);
int             make_unset(t_token *tokens, t_export *alloctrack);
int             make_env(t_token *tokens);
int             make_exit(t_token *tokens);
int             make_exec(t_token *tokens);
int             cmd(t_token *tokens, t_export *alloctrack);

// lexing cmd
int             lexing_cmd(t_token *tokens, t_export *alloctrack);

// utils
int             tablen(char **tab);
int             tab_slen(char **tab);

#endif