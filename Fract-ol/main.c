#include "MacroLibX/includes/mlx.h"
#include "MacroLibX/includes/mlx_extended.h"

typedef struct
{
    mlx_context mlx;
    mlx_window win;
	mlx_image		img;
} mlx_t;

void paint(mlx_t *mlx, char key)
{
	static int	x = 10;
	static int	y = 10;
    mlx_color color;
    mlx_color black;
    
	color.rgba = 0x00FF00FF; // green
    black.rgba = 0x00000000; // black
	mlx_clear_window(mlx->mlx, mlx->win, black);
	if (key == 'w' && y >= 0)
		mlx_set_image_pixel(mlx->mlx, mlx->img, x, y--, color);
	else if (key == 's' && y <= 400)
		mlx_set_image_pixel(mlx->mlx, mlx->img, x, y++, color);
	else if (key == 'a' && x >= 0)
		mlx_set_image_pixel(mlx->mlx, mlx->img, x--, y, color);
	else if (key == 'd' && x <= 400)
		mlx_set_image_pixel(mlx->mlx, mlx->img, x++, y, color);
	else
		printf("caca");
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void window_hook(int event, void* param)
{
    if(event == 0)
        mlx_loop_end((mlx_context)param);
}

void key_hook(int key, void* param)
{
	mlx_t* mlx = (mlx_t*)param;


    if(key == 41) // 41 is the key code for escape
        mlx_loop_end(mlx->mlx); // if escape is pressed we stop the mlx_loop and so we continue in the main function
	else if (key == 26)
		paint(mlx, 'w');
	else if (key == 22)
		paint(mlx, 's');
	else if (key == 4)
		paint(mlx, 'a');
	else if (key == 7)
		paint(mlx, 'd');
	else
		paint(mlx, 'q');
}

int main(void)
{
	mlx_t					xlm;
	mlx_context				mlx;
	mlx_window_create_info	info;

	mlx = mlx_init();
	info.title = "Hello World!";
    info.width = 400;
    info.height = 400;
	info.is_fullscreen = 0;
	info.is_resizable = 0;
	info.render_target = 0;
	
	mlx_window win = mlx_new_window(mlx, &info);
    mlx_color color;
    mlx_color black;
    color.rgba = 0x00FF00FF; // green
    black.rgba = 0x00000000; // green
	mlx_image img = mlx_new_image(mlx, 400, 400);
    
	xlm.mlx = mlx;
	xlm.win = win;
	xlm.img = img;

	mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_hook, mlx);
	mlx_on_event(mlx, win, MLX_KEYDOWN, key_hook, &xlm);
    mlx_loop(mlx);
	mlx_clear_window(mlx, win, black);
	mlx_destroy_image(mlx, img);
    mlx_destroy_window(mlx, win);
    mlx_destroy_context(mlx);
}
