/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:42:13 by jaham             #+#    #+#             */
/*   Updated: 2021/11/13 03:42:13 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(const char *s, int fd)
{
  ssize_t written;
  size_t  len;

  written = 0;
  len = ft_strlen(s);
  while (len > 0)
  {
    written = write(fd, s, len);
    if (written < 0)
      return (0);
    len -= (size_t) written;
  }
  return (len == 0);
}
