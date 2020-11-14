/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:03:44 by titorium          #+#    #+#             */
/*   Updated: 2020/11/14 09:48:14 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cublib.h"
#include	"libft.h"

/*
*** This functions tell you the distance until you impact a wall
*/

static int	ft_give_nextwall(int isx, int cuadrant, int value, double angle)
{
	int result;

	result = value;
	if (isx == 1)
	{
		if ((int)(angle*10000) == (int)(PI*(30000/2)) || (int)(angle*10000)  == (int)(PI *10000/2))
			return (result);
		if (cuadrant == 4 || cuadrant == 1)
			return (result + 1);
		return (result - 1);
	}
	if ((int)(angle*10000) == (int)(PI * 10000) || (int)(angle*10000)  == 0)
		return (result);
	if (cuadrant == 3 || cuadrant == 4)
		return (result - 1);
	return (result + 1);
}

static int	ft_give_prevwall(int isx, int cuadrant, int value, double angle)
{
	int	result;
   
	result	= value;
	if (isx == 1)
	{
		if ((int)(angle*10000) == (int)(PI*(30000/2)) || (int)(angle*10000)  == (int)(PI *10000/2))
			return (result);
		if (cuadrant == 4 || cuadrant == 1)
			return (result - 1);
		return (result + 1);
	}
	if ((int)(angle*10000) == (int)(PI * 10000) || (int)(angle*10000)  == 0)
		return (result);
	if (cuadrant == 3 || cuadrant == 4)
		return (result + 1);
	return (result - 1);
}

//-------------------------------------------------
//-------------------------------------------------
//-------------------------------------------------
static int ft_getdx(int x, t_data data, int cuadrant, int wallx)
{
/*
***  calculates the dx distance = from x to the wall given by wallx
*/
	int dxpos;
	

	ft_putstr("\n  wallx to add= "); ft_putnbr(wallx); //
	if (cuadrant == 1 || cuadrant == 4)
	{
		dxpos = (ft_mapx(x , data) + wallx) * data.map_size.cols_size;
ft_putstr("\n  wallx place in px= "); ft_putnbr(dxpos); 
		return (dxpos - x);
	}
	dxpos = (ft_mapx(x, data) + wallx +1) * data.map_size.cols_size;
ft_putstr("\n  wallx place in px= "); ft_putnbr(dxpos); 
	return (x - dxpos);
}

//-------------------------------------------------

static int ft_getdy(int y, t_data data, int cuadrant, int wally)
{
/*
***  calculates the dy distance = from y to wall given by wally
*/
	int dypos;


	if (cuadrant == 1 || cuadrant == 2)
	{
		dypos = (ft_mapy(y, data) + wally) * data.map_size.rows_size;
ft_putstr("\n  wally place in py= "); ft_putnbr(dypos);
		return (dypos - y);
	}
	dypos = (ft_mapy(y , data) + wally +1) * data.map_size.rows_size;
ft_putstr("\n  wally place in py= "); ft_putnbr(dypos);
	return (y - dypos);
}

//-------------------------------------------------
//-------------------------------------------------
//-------------------------------------------------
static int ft_returndx(int dx, t_data data)
{
	int aux;
(void)data;
	aux = dx * -1;// - data.map_size.cols_size;
	if (dx < 0)
		return (aux);

	aux = dx; //+ data.map_size.cols_size;
	return (aux);
}


static int ft_returndy(int dy, t_data data)
{
	int aux;
(void)data;

	aux = dy * -1;// - data.map_size.rows_size;
	if (dy < 0)
		return (aux);

	aux = dy ;//+ data.map_size.rows_size;
	return (aux);
}



//-------------------------------------------------------------------------------------------------------
//*******************************************************************************************************
//*******************************************************************************************************
//*******************************************************************************************************
//-------------------------------------------------------------------------------------------------------


static int	ft_get_distance(t_data data, int x, int y, int cuadrant)
{
	int wallx;
	int wally;
	int dx;
	int dy;
	int aux;

	ft_putstr("\n================================================================================");
	ft_putstr("\n================================================================================");
	ft_putstr("\n=============================     START   ======================================");
	ft_putstr("\n================================================================================");
	ft_putstr("\n================================================================================");
	ft_putstr("\n---- initial data ---");
	

	ft_putstr("\n[x] = ");	ft_putnbr(ft_mapx(x, data));ft_putstr("\t[y] = "); ft_putnbr(ft_mapy(y, data));
	ft_putstr("\nx size col= ");ft_putnbr(data.map_size.cols_size);ft_putstr("\ty size row= "); ft_putnbr(data.map_size.rows_size);
	ft_putstr("\nx pix pos  = "); ft_putnbr(x);ft_putstr("  \ty pix pos = ");ft_putnbr(y);	
	ft_putstr("\nangle = "); ft_putnbr(data.player.angle *10000);
	ft_putstr("\ncuadrant  = ");	ft_putnbr(cuadrant);

	
	wallx = 0;
	wally = 0;

			

int counter =0;

//--------------------------------------------------------------------------------------------------------
//---------------- START  --------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
	while (ft_mapx(x, data) + wallx > -1 &&
		   	ft_mapx(x, data) + wallx < data.cols &&
				ft_mapy(y, data) + wally > -1 &&
		   			ft_mapy(y, data) + wally < data.rows && counter < 20)
	{

	ft_putstr("\n---------inside loop --------------");
	ft_putstr("\n >>>> counter:");ft_putnbr(counter);ft_putstr("<<<<\n");
	ft_putstr("\n1)*** add to wall X and WALL Y a position ***");//
	
	wallx = ft_give_nextwall(1, cuadrant, wallx, data.player.angle);
	wally = ft_give_nextwall(0, cuadrant, wally, data.player.angle);

		
	ft_putstr("\n wallx=");	ft_putnbr(wallx);ft_putstr("\t wally=");	ft_putnbr(wally);
	ft_putstr("\n[x] = ");	ft_putnbr(ft_mapx(x, data));ft_putstr("\t[y] = "); ft_putnbr(ft_mapy(y, data));
	ft_putstr("\n[x + wallx]= ");	ft_putnbr(ft_mapx(x, data) + wallx);ft_putstr("\t[y + wally] = "); ft_putnbr(ft_mapy(y, data)+ wally);

//-------------------------------------------------
//---------------- DX  DY ==> DIST to the WAlLS ---
//-------------------------------------------------

	ft_putstr("\n2) **** Get dx and dy **** ");
		dx = ft_getdx(x, data, cuadrant, wallx);
	 	dy = ft_getdy(y, data, cuadrant, wally);

	ft_putstr("\n>>dx ="); 	ft_putnbr(dx);ft_putstr("\t dy ="); ft_putnbr(dy);

//-------------------------------------------------
//---------------- HX  HY--------------------------
//-------------------------------------------------

		aux = 100000;	
		if (data.player.angle != PI/2 && data.player.angle != PI *3/2)
			aux = (int)((dx) /(cos(data.player.angle))); //hypotenus distance on x
		dx = aux;
		
		aux = 100000;
		if (data.player.angle != PI && data.player.angle != 0)
			aux = (int)(dy /(sin(data.player.angle) )); // same on y
		dy = aux;

	ft_putstr("\n3)*** Get hx and hy ***");
	ft_putstr("\nangle =");
	ft_putnbr(data.player.angle *1000);
	ft_putstr("\nhx =");
	ft_putnbr(dx);
	ft_putstr("\t hy=");
	ft_putnbr(dy);
	ft_putstr("\n 4)*** Pick the smallest Hx Hy*** \n");


		if (dx < -2147483640 || dx > 2147483640)
			dx = 1000000;
		if (dy < -2147483640 || dy > 2147483640)
			dy = 1000000;
//-------------------------------------------------
//-----------------  DX  --------------------------
//-------------------------------------------------
		if (abs(dx) <= abs(dy) )
		{
			wally = ft_give_prevwall(0, cuadrant, wally, data.player.angle);

	
	ft_putstr("\n -----------hx is smaller-------\n");

			if (ft_checkwall(ft_mapx(x, data) + wallx, ft_mapy(y ,data) + wally, data) == 1)
				return (ft_returndx(dx, data));
	ft_putstr("\n  no wall hit on X, thus new WALLX =");ft_putnbr(wallx);ft_putstr("\n");

		}

//-------------------------------------------------
//-----------------  DY  --------------------------
//-------------------------------------------------
		if (abs(dy) < abs(dx))
		{
			wallx = ft_give_prevwall(1, cuadrant, wallx, data.player.angle);
		
//	ft_putstr("\n ----------- hy is smaller-------\n");


			if (ft_checkwall(ft_mapx(x, data) + wallx, ft_mapy(y ,data) + wally, data) == 1)
				return (ft_returndy(dy, data));
	ft_putstr("\n  no wall hit on Y, thus new WALLY =");ft_putnbr(wally);ft_putstr("\n");
		}
//-------------------------------------------------
//-------------------------------------------------
	ft_putstr("\n ----------LOOPING --------\n");
	counter++;
	}
	return (0);
}


static int 	ft_raydist(t_data data, t_cube cube, double angle)
{
	int		x;
	int		y;
	int		cuadrant;

	x = cube.x0 + ((cube.x1 - cube.x0) / 2);
	y = cube.y0 + ((cube.y1 - cube.y0) / 2);
	
	cuadrant = ft_cuadrant(angle);
	return (ft_get_distance(data, x, y, cuadrant));
}



void	ft_drawray(t_data data, t_cube playercube, t_pixel *img)
{
	int raydistance;


//	ft_putstr("\nangle = "); ft_putnbr(data.player.angle *100);
	
	raydistance = ft_raydist(data, playercube, data.player.angle);
	ft_drawtail(data, img, 0x000FFFF00, raydistance);
	ft_putstr("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
	ft_putstr("\n********FINISH************");
	ft_putstr("\n//////////////////////////");
(void) data;
(void) raydistance;
(void) playercube;
(void) img;
(void) ft_raydist;

}


