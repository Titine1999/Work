#include "libft/libft.h"
#include "math.h"
#define rien 1 == 1
#define dirX s.k
#define dirY s.l
#define absX s.i
#define absY s.j
int         absv(int i)
{
	return ((i < 0 ? -i : i));
}

void        pixel_puttest(int xa, int ya, int xb, int yb)
{
	t_bresenham s;
	printf("Valeurs de depart : [%d;%d] - [%d;%d]",xa,ya,xb,yb);
	printf("\nInitialisation :\n\n");
	absX = absv(xa - xb);
	absY = absv(ya - yb);
	printf("Valeur absX :%d\nValeur absY :%d\n",absX,    absY);
	dirX = xb < xa ? 1 : -1;
	dirY = yb < ya ? 1 : -1;
	s.m = (absX > absY ? absX : -absX) / 2;
	printf("Milieu : %d\n\n",s.m);
	printf("Debut algo \n");
	getchar();
	while (xb != xa || yb != ya)
	{
		s.n = s.m;
		printf("sn : %d\n", s.n);
		s.n > -absX ? s.m -= absY : rien;
		s.n > -absX ? xb += dirX : rien;
		s.n < absY ? s.m += absX : rien;
		s.n < absY ? yb += dirY : rien;
		printf("sm : %d\n", s.m);
		printf("xb :%d - yb :%d\n\n",xb,yb);
		getchar();
	}
}

int		main(int argc, char **argv)
{
	int xa = ft_atoi(argv[1]);
	int ya = ft_atoi(argv[2]);
	int xb = ft_atoi(argv[3]);
	int yb = ft_atoi(argv[4]);

	pixel_puttest(xa, ya, xb, yb);
	return(0);
}
