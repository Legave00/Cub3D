/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:30:59 by ydorene           #+#    #+#             */
/*   Updated: 2021/03/20 12:41:05 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
int				ft_toupper(int a);
int				ft_tolower(int a);
char			*ft_strrchr(const char *str, int ch);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *a);
size_t			ft_strlcpy(char *dtst, const char *str, size_t size);
size_t			ft_strlcat(char *dst, char *str, size_t size);
char			*ft_strchr(const char *str, int ch);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
int				ft_memcmp(const void *arr1, const void *arr2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
int				ft_isprint(int a);
int				ft_isdigit(int a);
int				ft_isascii(int a);
int				ft_isalpha(int a);
int				ft_isalnum(int a);
void			*ft_calloc(size_t number, size_t size);
void			*ft_bzero(void *s, size_t n);
int				ft_atoi(const char *a);
char			*ft_strdup(const char *s1);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2, int z);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));
#endif
