typedef struct s_stock_str
{
int size;
char *str;
char *copy;
} t_stock_str;

struct s_stock_str *ft_strs_to_tab(int ac, char **av);



/*int	main(int argc, char **argv)
{
	struct s_stock_str *stock;
	
	stock = ft_strs_to_tab(argc, argv);
	ft_show_tab(stock);
	return (0);
}*/