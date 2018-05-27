#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

# define	R_START			1
# define	R_END			2
# define	R_LOCK			4

typedef struct		s_room
{
	char			name;
	int				y;
	int				x;
	t_room			*way;
	t_list			*connection;
	int				status;
	int				order;
}					t_room;

typedef struct		s_ant
{
	int				number;
	t_room			*location;
}					t_ant;

typedef struct 		s_board
{
	int				num;
	t_room			*start;
	t_room			*end;
	t_list			ants;
	t_list			rooms;
}					t_board;

/*
**rooms.c
*/
t_room				*new_room(void);
void				clear_room(void *r, size_t size);
t_list				*obj_in_lst(void *obj);
void				for_unlock_all_rooms(t_list *lst);

/*
**ants.c
*/
int					step_colony(t_list *lst);
t_list				*get_colony(int num, t_room *start);
void				clear_ant(void	*a, size_t size);


#endif