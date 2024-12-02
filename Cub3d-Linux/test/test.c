#include "../minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdio.h>

int loop_hook(void *param)
{
    void *mlx = ((void **)param)[0];
    void *win = ((void **)param)[1];
    int x, y;
    mlx_mouse_get_pos(mlx, win, &x, &y);
    printf("Cursor Position: (%d, %d)\n", x, y);
    return 0;
}

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "test");

    void *params[] = {mlx, win};
    mlx_loop_hook(mlx, loop_hook, params);
    mlx_loop(mlx);

    return 0;
}