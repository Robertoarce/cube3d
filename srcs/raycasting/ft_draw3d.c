/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:24:00 by titorium          #+#    #+#             */
/*   Updated: 2020/12/03 16:27:54 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"
#define multiplier 1


static unsigned long ft_rgba(int r, int g, int b)
{  
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static long double ft_round(long double num, long places)
{
	int counter;
	counter = 0;
	while (counter++ < places)
	{	
		num = num *10;
	}
	num = floor(num);
	while (counter--)
		num = num / 10;
	return (num);

}


static double ft_avgray(double raydistance, double fixed)
{	
	double avg;


	avg = 	(raydistance * cos(fixed-1e-9)+ raydistance * cos(fixed-1e-5) + raydistance * cos(fixed-1e-4) + raydistance * cos(fixed-1e-3) + raydistance * cos(fixed-1e-2) + raydistance * (cos(fixed)) +
		 	 raydistance * cos(fixed+1e-2)+ raydistance * cos(fixed+1e-3) + raydistance * cos(fixed+1e-4) + raydistance * cos(fixed+1e-5) + raydistance * cos(fixed+1e-7) + raydistance * cos(fixed+1e-9)); 
	avg = avg/12;
	return (avg);
}




static void		ft_drawcube2(t_cube cube, t_pixel *img, int color)
{
	double x;
	double y;

	x = cube.x0 ;

	while (x < cube.x1)
	{
		y = cube.y0 ;
		while (y < cube.y1)
		{
//		ft_putstr("\n x0 = "); ft_putnbr(cube.x0);
//		ft_putstr("\t x1 = "); ft_putnbr(cube.x1);
//		ft_putstr("\n y0 = "); ft_putnbr(cube.y0);
//		ft_putstr("\t y1 = "); ft_putnbr(cube.y1);
			my_mlx_pixel_put(img, x, y, color);
			y++;
		}
		x++;
	}
}

/********************************************************************************************************************************************************/
/********************************************************************************************************************************************************/
/********************************************************************************************************************************************************/
/********************************************************************************************************************************************************/

static void ft_drawstripplane(int place, t_pixel *img, t_data data, long double pa)
{
	t_cube		cube;
	long double	lineHeight;
	long double	raydistance;
	long double fixed;
	int			lineWidth;


	raydistance = ft_raydist(data, data.player.cube, data.player.angle);



	if ( place == 31 )
		place = place +1 - 1;
//	fixed = ft_round((pa - data.player.angle),9) ;
	fixed = (pa - data.player.angle);
		if (fixed > 2 * PI)
			fixed = fixed - (2* PI);
		if (fixed < 0 )
			fixed = fixed + (2 * PI);

		if ( place == 31 || place == 51 )
			ft_putstr("\n ---------HERE ---------"); 
//	if ((place > 1 && place < 7 )|| (place > 1135 && place < 1150))
//	{
		ft_putstr("\n ------------------"); 
		ft_putstr("\n place= "); ft_putnbr(place);
	//	ft_putstr("\n*********");
/*
	*/	ft_putstr("\n data[1] = \t"); ft_putnbr( data.r[1] );
	/*	ft_putstr("\n pa  = \t"); ft_putnbr( pa * 100000000 );
	*/	ft_putstr("\n ra  = \t"); ft_putnbr( data.player.angle * 100000000 );
	/*	ft_putstr("\n pa - ra angle=\t "); ft_putnbr((pa - data.player.angle)*100000000);
		ft_putstr("\n fixed=\t\t "); ft_putnbr(fixed * 100000000);
		ft_putstr("\n cosine (ra - pa)=\t"); ft_putnbr((cosl(pa - data.player.angle) )* 100000000  );
		ft_putstr("\n cosine (fixed)=\t"); ft_putnbr((cosl(fixed) )* 100000000  );

		ft_putstr("\n  " );
		ft_putstr("\n 32 * data.r[1]= "); ft_putnbr(32 * data.r[1]);
		ft_putstr("\n raydistance pure= "); ft_putnbr(raydistance);
		ft_putstr("\n raydistance * cosl(fixed)=\t "); ft_putnbr(raydistance*cosl(fixed));
		ft_putstr("\n raydistance * cosl(fixed) * 1000000 =\t"); ft_putnbr(raydistance*cosl(fixed));
*/
//	}

	(void) ft_round;
	(void) ft_avgray;

	//raydistance = raydistance * (cosl((fixed) )) - 3e-4 ;
	raydistance = raydistance * ((cosl(pa)*cosl(data.player.angle)))+ raydistance*((sin(pa)*sin(data.player.angle))) ;
	lineHeight =  (32 * data.r[1] / raydistance);
	
//	if ((place > 1 && place < 7 )|| (place > 1135 && place < 1150))
//	{
	
	//	ft_putstr("\n (FLOAT ) lineHeight= wide/real raydist (* 1 000 000)=\t"); 		ft_putnbr( lineHeight*1000000);	
	//	ft_putstr("\n (INT) LineHeight =\t"); 										ft_putnbr((int) lineHeight);	
	
//	}

	if (lineHeight > data.r[1])
		lineHeight =  data.r[1];
	
/*----  line width + cube points ----*/
	lineWidth = ((data.r[0]) / (60 * multiplier +1));

	int offset=0;
	offset = (data.r[1]/2) - (lineHeight/2) ;


	cube.x0 = (place - 1) * lineWidth;
	cube.x1 = place * lineWidth;
	cube.y0 = 0 + offset;
	cube.y1 = lineHeight + offset;

/*---- drawing ----*/
	ft_drawcube2(cube, img, ft_rgba(0,0,100));
	if (place %2 == 0)
		ft_drawcube2(cube, img, ft_rgba(0,100,0));

	if ( place == 31 || place == 31 )
		ft_drawcube2(cube, img, ft_rgba(100,100,0));

/*---- infos ----*/

//dd	if (place > 1 && place < 7)
//	{
//	}

	if ( place == 31 || place == 59 )
		ft_putstr("\n ---------HERE ---------"); 

}

/********************************************************************************************************************************************************/
/********************************************************************************************************************************************************/
/********************************************************************************************************************************************************/
/********************************************************************************************************************************************************/



void	ft_draw3d(t_data *data, t_pixel *img)
{
	long double	pa;
	int			counter;
	
	counter = 0;
	pa = data->player.angle;

	data->player.angle = ft_addangle(data->player.angle, -0.522);

ft_putstr("\n =============================================================");
ft_putstr("\n ===========================START=============================");
ft_putstr("\n =============================================================");

	while (counter++ <= 60* multiplier )
	{
		ft_drawstripplane(counter, img, *data, pa);
		data->player.angle = ft_addangle(data->player.angle, 0.0174 / multiplier);
	}

ft_putstr("\n =============================================================");
ft_putstr("\n ============================END==============================");
ft_putstr("\n =============================================================");

	ft_putstr("\n raydistance pure= "); ft_putnbr(counter);

	data->player.angle = pa;
}

