/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:48:36 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/18 20:37:41 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <string.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
int				ft_atoi(const char *str);
void			ft_bzero(void *ptr, size_t n);
void			*ft_calloc(size_t n, size_t t);
int				ft_isalnum(int str);
int				ft_isalpha(int str);
int				ft_isascii(int str);
int				ft_isdigit(int str);
int				ft_isprint(int str);
char			*ft_itoa(int n);
char			*ft_substr(char const *src, unsigned int start, size_t len);
void			*ft_memccpy(void *dst,
				const void *src, int c, size_t n);
size_t			ft_strlen(const char *str);
void			*ft_memchr(const void *src, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void
				*src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *ptr, int x, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *s, int fd);
char			**ft_split(char const *str, char c);
char			*ft_strchr(const char *src, int d);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char
				*src, size_t maxlen);
size_t			ft_strlcpy(char *dst, const char
				*src, size_t maxlen);
char			*ft_strmapi(char const *s, char (*f) (unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char
				*needle, size_t size);
char			*ft_strrchr(const char *src, int d);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_tolower(int str);
int				ft_toupper(int str);
char			**free_tab(char **rtn, int i);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new0);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *nw);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *));
#endif
