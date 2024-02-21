/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:19:54 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/20 14:18:25 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

/* LIBFT ------------------------------------------------------------------- */
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_strlen(const char *str);
void			*ft_memset(void *dest, int c, size_t count);
void			*ft_bzero(void *dest, size_t count);
void			*ft_memcpy(void *dest, const void *src, size_t count);
void			*ft_memmove(void *dest, const void *src, size_t count);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memchr(void *buffer, int c, size_t count);
int				ft_memcmp(const void *buffer1, const void *buffer2, \
size_t count);
char			*ft_strnstr(const char *str, const char *find, size_t slen);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t number, size_t size);
char			*ft_strdup(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(const char *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int nb, int fd);
/* ------------------------------------------------------------------------- */

/* LIBFT BONUS (LISTS) ----------------------------------------------------- */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
void (*del)(void *));
/* ------------------------------------------------------------------------- */

/* GET NEXT LINE BONUS FUNCTIONS ------------------------------------------- */
char			*get_next_line(int fd);
int				ft_strlen_to_limit(char *str, int delimiter);
char			*ft_strchr_mod(char *str, int c);
char			*ft_strdup_mod(char *str);
char			*ft_strjoin_mod(char *s1, char *s2);
char			*ft_substr_mod(char *s, unsigned int start, size_t len);
/* ------------------------------------------------------------------------- */

/* PRINTF FUNCTIONS -------------------------------------------------------- */
int				ft_putchar_mod(char c, int printcount);
int				ft_putstr_mod(char *str, int printcount);
int				ft_puthex_low(unsigned long long h, int printcount);
int				ft_puthex_upp(unsigned long long h, int printcount);
int				ft_putptr(void *ptr, int printcount);
int				ft_putnbr_mod(int nb, int printcount);
int				ft_putnbr_mod_unsigned(unsigned int nb, int printcount);
int				ft_checking_the_format(char *str, int i, va_list args, \
int printcount);
int				ft_printf(char const *str, ...);
/* ------------------------------------------------------------------------- */

#endif