#ifndef CUB_H
# define CUB_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# define BUFFER_SIZE 64
# include <math.h>

typedef struct	s_wall
{
	int			linehight;
	int			drawstart;
	int			drawend;
}				t_wall;

typedef struct	s_ray
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

typedef struct	s_player
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
}				t_player;

typedef struct	s_tur
{
	void		*imgw;
	int			llw;
	int			bppw;
	int			endianw;
	char		*addrw;
	int			img_width_w;
	int			img_height_w;
	void		*imge;
	int			lle;
	int			bppe;
	int			endiane;
	char		*addre;
	int			img_width_e;
	int			img_height_e;
}				t_tur;

typedef struct	s_tex
{
	void		*imgn;
	int			lln;
	int			bppn;
	int			endiann;
	char		*addrn;
	int			img_width_n;
	int			img_height_n;
	void		*imgso;
	int			llso;
	int			bppso;
	int			endianso;
	char		*addrso;
	int			img_width_so;
	int			img_height_so;
}				t_tex;

typedef struct	s_texturka
{
	int			width;
	int			hight;
	char		*addr;
	int			ll;
	int			bpp;
}				t_texturka;


typedef struct	s_bar
{
	int			x;
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
	t_player	*player;
	t_ray		*ray;
	t_wall		*wall;
	t_tex		*tex;
	t_tur		*tur;
	double		wallx;
	int			texside;
	int			texx;
	int			texy;
	t_texturka	*texturka;
}				t_bar;

void			defstruct(t_bar *a);
void			text(t_bar *a);
void			sidetex(t_bar *a, t_ray *ray, t_player *player);
void			textur(t_bar *a, t_tex *tex, t_tur *tur);
void			reader(t_bar *a);
void			f1(char *line, t_bar *a, int i, int num);
void			paint(int i, t_bar *a);
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
void			verline(int drawstart, int drawend, int color, t_bar *a, t_texturka *texturka);
void			mmpp(t_bar *a, int x, int y, int color);
void			readbuf(t_list **head, int size, t_bar *a);
int				search(char **map);
int				ret(int readed, char *ostatok);
int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *a);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(const char *s1, const char *s2, int z);
void			*ft_calloc(size_t number, size_t size);
char			*ft_strchr(const char *str, int ch);
#endif
