/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   cub.h											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ydorene <ydorene@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/10/31 22:30:59 by ydorene		   #+#	#+#			 */
/*   Updated: 2021/03/14 18:32:30 by ydorene		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# define BUFFER_SIZE 64

typedef struct	s_player
{
	int			xP;
	int			yP;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeY;
	double		planeX;
	char		direction;
	
}				t_player;

typedef struct	s_list2
{
	int			fir;
	int			sec;
	void		*mlx;
	void		*win;
	void		*img;
	char		**map;
	int			start;
	char		*addr;
	int			ll;
	int			bpp;
	int			endian;
	t_player	player;
}				t_list2;


int				ret(int readed, char *ostatok);
int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *a);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(const char *s1, const char *s2, int z);
void			*ft_calloc(size_t number, size_t size);
char			*ft_strchr(const char *str, int ch);
#endif
