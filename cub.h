/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:43:35 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/21 23:28:08 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# define BUFFER_SIZE 64
# include <math.h>

typedef struct s_wall
{
	int			linehight;
	int			drawstart;
	int			drawend;
}				t_wall;

typedef struct s_ray
{
	double		raydirx;
	double		raydiry;
	double		deltadistx;
	double		deltadisty;
	double		sidedistx;
	double		sidedisty;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		perp;
}				t_ray;

typedef struct s_player
{
	int			xp;
	int			yp;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	float		olddirx;
	double		planey;
	double		planex;
	float		oldplanex;
	double		camerax;
	char		ch;
	double		*perpmass;
}				t_player;

typedef struct s_sprite
{
	double		x;
	double		y;
}				t_sprite;

typedef struct s_tur
{
	void		*imgw;
	int			llw;
	int			bppw;
	int			endianw;
	char		*addrw;
	int			iw_w;
	int			ih_w;
	void		*imge;
	int			lle;
	int			bppe;
	int			endiane;
	char		*addre;
	int			iw_e;
	int			ih_e;
}				t_tur;

typedef struct s_tex
{
	void		*imgn;
	int			lln;
	int			bppn;
	int			endiann;
	char		*addrn;
	int			iw_n;
	int			ih_n;
	void		*imgso;
	int			llso;
	int			bppso;
	int			endianso;
	char		*addrso;
	int			iw_so;
	int			ih_so;
}				t_tex;

typedef struct s_texturka
{
	int			width;
	int			hight;
	char		*addr;
	int			ll;
	int			bpp;
	int			*massdist;
}				t_texturka;

typedef struct s_win
{
	char		*addr;
	int			ll;
	int			bpp;
	int			endian;
	void		*mlx;
	void		*win;
	void		*img;
}				t_win;

typedef struct s_drawsp
{
	double		spritex;
	double		spritey;
	double		invdet;
	double		transx;
	double		transy;
	int			ssx;
	int			sph;
	int			spw;
	int			dsx;
	int			dsy;
	int			dex;
	int			dey;
	int			texx;
	int			texy;
	int			c;
	int			d;
	int			color;
}				t_drawsp;

typedef struct s_readsp
{
	void		*imgsp;
	int			llsp;
	int			bppsp;
	int			endiansp;
	char		*addrsp;
	int			iw_sp;
	int			ih_sp;
}				t_readsp;

typedef struct s_screen
{
	int			h;
	int			w;
}				t_screen;

typedef struct s_bar
{
	int			x;
	int			fir;
	int			sec;
	char		**map;
	int			start;
	t_readsp	sp;
	t_drawsp	dr;
	t_win		win;
	t_player	player;
	t_ray		ray;
	t_wall		wall;
	t_tex		tex;
	t_tur		tur;
	t_texturka	texturka;
	t_sprite	*sprite;
	double		wallx;
	int			texside;
	int			texx;
	int			texy;
	int			kolspr;
	t_screen	sett;
}				t_bar;

typedef struct s_gnl
{
	char		buf[BUFFER_SIZE + 1];
	int			readed;
	char		*perehod;
	char		*tmp;
}				t_gnl;

int				ftclose2(t_bar *a);
void			drawspr(t_bar *a, t_player *player, t_drawsp *dr,
					t_texturka *texturka);
void			casting(int fd, t_bar *a);
void			scsh(int fd, t_bar *a);
void			screenshot(t_bar *a);
void			screenshot2(int fd, t_bar *a);
int				*spdist(t_bar *a, int r);
void			readsprite(t_bar *a, t_readsp *sp);
int				*sort(int *massdist, t_bar *a);
void			ft_swap(int *fir, int *sec);
void			readsprite(t_bar *a, t_readsp *sp);
void			drstruct(t_drawsp *dr);
void			drawspr(t_bar *a, t_player *player,
					t_drawsp *dr, t_texturka *texturka);
void			ifn(void *a);
void			freeall(t_bar *a, t_player *player);
int				*spdist(t_bar *a, int r);
void			n(t_bar *a, t_tex *tex);
void			so(t_bar *a, t_tex *tex);
void			w(t_bar *a, t_tur *tur);
void			e(t_bar *a, t_tur *tur);
void			pn(t_bar *a);
void			pso(t_bar *a);
void			pw(t_bar *a);
void			pe(t_bar *a);
void			sprite(t_bar *a);
void			defstruct(t_bar *a);
void			text(t_bar *a);
void			sidetex(t_bar *a, t_tex *tex, t_tur *tur, t_player *player);
void			textur(t_bar *a, t_tex *tex, t_tur *tur);
void			reader(t_bar *a, int fd);
void			f1(char *line, t_bar *a, int i, int num);
void			paint(int i, t_bar *a, t_player *player);
void			playerstruct(t_bar *a, char pla);
void			againstr(t_bar *a);
int				render_next_frame(t_bar *a);
void			movefb(int keycode, t_bar *a, t_player *player);
void			rotlr(int keycode, t_bar *a, t_player *player);
void			movelr(int keycode, t_bar *a, t_player *player);
int				ftclose(int keycode, t_bar *a);
void			cikl(t_bar *a, t_player *player, t_ray *ray);
void			delta(t_bar *a, t_player *player);
void			ft_ray(t_bar *a, t_player *player, t_ray *ray);
void			runray(t_bar *a);
void			wall(t_bar *a, t_player *player, t_ray *ray);
void			verline(t_wall *wall, t_bar *a, t_texturka *texturka);
void			mmpp(t_bar *a, int x, int y, int color);
void			readbuf(t_list **head, int size, t_bar *a);
int				search(char **map);
int				ret(int readed, char *ostatok);
int				get_next_line(int fd, char **line);
int				ft_strlen(const char *a);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(const char *s1, const char *s2, int z);
void			*ft_calloc(size_t number, size_t size);
char			*ft_strchr(const char *str, int ch);
#endif
