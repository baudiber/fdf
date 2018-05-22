
void	redraw(t_setup *stp)
{
	int		i;

	get_newpts(stp);
	mlx_clear_window(stp->mlx_ptr, stp->win_ptr);
	mlx_destroy_image(stp->mlx_ptr, stp->img_ptr);
	stp->img_ptr = mlx_new_image(stp->mlx_ptr, stp->width, stp->height);
	stp->data = (int *)mlx_get_data_addr(stp->img_ptr, &stp->bpx, &stp->s_line, &stp->ed);
	i = 0;
	while (i < stp->ptnb - 1) 
	{
		ft_bresenham(stp->npts[i].vect.x + 200, stp->npts[i].vect.y + 200, stp->npts[i + 1].vect.x + 200, stp->npts[i + 1].vect.y + 200, stp);
		if (i < stp->lastrow)
			ft_bresenham(stp->npts[i].vect.x + 200, stp->npts[i].vect.y + 200, stp->npts[i + stp->ptnb / stp->ynb].vect.x + 200, stp->npts[i + stp->ptnb / stp->ynb].vect.y + 200, stp);
		i++;
	}
	mlx_put_image_to_window(stp->data, stp->win_ptr, stp->img_ptr, 0, 0);
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, 850, 740, 0xF0F0F0, "Press h for help");
}
/*

void	display(t_setup *stp)
{

	create_window("FDF", 1024, 768, stp);
	get_matrix(stp->q0, stp);
	matrix_multiplication(stp);
	draw(stp);
	mlx_key_hook(stp->win_ptr, deal_key, stp);
	mlx_loop(stp->mlx_ptr);
}
*/
