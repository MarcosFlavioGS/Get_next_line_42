/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:11:48 by coder             #+#    #+#             */
/*   Updated: 2022/09/28 01:49:43 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	read_line(int fd)
{
	while (read(fd) != 0)
	{
		if (gnl_strchr('\n'))
		{
			return ;
		}
	}
}

char	*get_next_line(int fd)
{
  static char 	extra;
  char			*line;
  if (!fd || BUFFER_SIZE <= 0)
	  return (NULL);
  read_line();
  if (extra)
  {
	  extra = get_extra();
	  line = get_line;
  }
  if (!line)
  {
	  free(extra);
	  return (NULL);
  }
  return (line);
}
