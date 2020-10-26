/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:15:29 by isaadi            #+#    #+#             */
/*   Updated: 2020/10/26 19:05:38 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H

# define MALLOC_H

# define malloc xmalloc
# define free xfree
# define exit xexit
# include <stddef.h>
void	*xmalloc(size_t xbytes);
void	xfree(void *adr);
void	leakcheck();
void	leakcheckfull();
void	xexit(int x);

#endif
