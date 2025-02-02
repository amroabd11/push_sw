/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:18:09 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/02 10:45:38 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	f_strlen(char *s);
char	*f_strjoin(char *s1, char *s2);
char	*f_strchr(char *s, int c);
#endif