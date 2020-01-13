/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:51:44 by mbrogg            #+#    #+#             */
/*   Updated: 2020/01/13 22:30:11 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

typedef	struct	s_lst
{
	int				index_number:6;
	int				upperleft;
	int				deep:3;
	int				l:3;
	int				r:3;
	short			*coords;
	struct s_lst	*next;
}				t_lst;

t_lst			*lst_new(t_lst** head, int counter);
int				lst_push_front(t_lst **head, t_lst *new);
void			lst_del(t_lst **head);
void			lst_print(t_lst *head);
void			lst_reverse(t_lst **head);
void			lst_foreach(t_lst *head, void (*f)(void *));
int				amount_of_items(t_lst *head, t_lst *cur);
int				check_input_with_lst(t_lst **head, char *str, int *i, char *ar);
void			deep_and_hor(t_lst **head, short *mas);
void			lst_rev(t_lst **head);
int				validation(char *file_name, t_lst **head);
char			check_area(short *ar, int i, int j);
int				check_height(short *coords, int map_size);
int				ft_sqrt(int nbr);
void			find_min_coords(char *line, int *min_x, int *min_y);
int				print_map(short *map, int size);
short			*create_map(int size);
void			delete_map(short **map);
void			move_upleft(short **c);
int				can_push(short *map, int map_size, short *coord, int *r_l_curr);
void			clear_tetri(short **map, t_lst **node, int curr_pos);
void			push_tetri(short **map, t_lst **node, int curr_pos, int num);
int				can_tetri_be_in_map(short *map, int map_size, short *coord);
int				solve(short **map, int map_size, t_lst **node, int num);
void			bruteforce(t_lst *node, int tetri_nbr);
void			change_map_size(short **c, int src_size, int dest_size);
void			change_size_for_lst(t_lst *node, int start_size, int dest_size);
int				print_with_letters(t_lst *head, t_lst *cur, int size);
char			**create_charmap(int size);
void			print_charmap(char **map, int map_size);
void			delete_charmap(char ***map, int size);
char			ft_mod(int a);
void			endblock_loop(short **mas);
#endif
