#include "ft_printf.h"
#include "stdio.h"

int	main(void)
{	
    int total;
/*   char    c;
    char    *s;
    int     di;
    unsigned int     u;
    short int x;
    

	x = 230;
    c = 'Z';
    s = "One";
    di = -6574;
    u = -2;

    total = ft_printf("%c\t", c);
    total += ft_printf("%s\t", s);

    ft_printf("%d\t", di);
    ft_printf("%u\n", u);
    printf("u=%u\n", u);
    ft_printf("x=%x\n", u);
    ft_printf("X=%X\n", u);
    printf("printf_x=%x\n", u);
    printf("Printf_X=%X\n", u);
    ft_printf("p=%p\n", &u);
    printf("printf_p=%p\n", &u);

	printf("\noutput of %% %%%%\t %%% %%%\n");
	ft_printf("\nft_output of %% %%%%\t %%% %%%\n");
//	printf("\nx= %hd", x);
	
	ft_printf("ft_p %p %p  \n", 0, 0);
	printf("p %p %p  \n", 0, 0);
	ft_printf("ft_p %p \n", 17);
	printf("p %p \n", 17);

//    test_analyze();
*/
	char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";

	printf("\np%s\n", "");
	ft_printf("\nf%s\n", "");
	printf("\np %s\n", "");
	ft_printf("\nf %s\n", "");
	printf("\np%s \n", "");
	ft_printf("\nf%s \n", "");
	printf("\np %s \n", "");
	ft_printf("\nf %s \n", "");
	printf("\np %s \n", "-");
	ft_printf("\nf %s \n", "-");
	printf("\np %s %s \n", "", "-");
	ft_printf("\nf %s %s \n", "", "-");
	printf("\np %s %s \n", " - ", "");
	ft_printf("\nf %s %s \n", " - ", "");
	printf("\np %s %s %s %s %s\n", " - ", "", "4", "", s2);
	ft_printf("\nf %s %s %s %s %s\n", " - ", "", "4", "", s2);
	printf("\np %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
	ft_printf("\nf %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
	printf("\np NULL %s NULL \n", NULL);
	ft_printf("\nf NULL %s NULL \n", NULL);
	return (total);
}
