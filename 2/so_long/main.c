/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:42:24 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/10/31 15:23:20 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include<unistd.h>

int main(void)
{
    void	*mlx;
    void	*mlx_win;
    void	*img;
    
    mlx = mlx_init();
    img = mlx_init();
    img = mlx_new_image(mlx, 1920, 1080);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Santos");
    mlx_loop(mlx);
    
    write(1, "S\n", 2);    
}