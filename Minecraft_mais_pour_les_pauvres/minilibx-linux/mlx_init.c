#include "mlx_int.h"

void *mlx_init()
{
    t_xvar *xvar;

    if (!(xvar = malloc(sizeof(*xvar))))
        return ((void *)0);
    if ((xvar->display = XOpenDisplay("")) == 0)
    {
        free(xvar);
        return ((void *)0);
    }
    xvar->root = DefaultRootWindow(xvar->display);
    xvar->depth = 32;
    if (mlx_int_get_visual(xvar) == -1)
    {
        printf(ERR_NO_TRUECOLOR);
        XCloseDisplay(xvar->display);
        free(xvar);
        exit(1);
    }
    xvar->pict_format = XRenderFindStandardFormat(xvar->display, PictStandardARGB32);
    xvar->cmap = XCreateColormap(xvar->display, xvar->root, xvar->visual, AllocNone);
    xvar->win_list = NULL; // Initialize the window list
    xvar->loop_hook = 0;
    xvar->loop_param = (void *)0;
    xvar->do_flush = 1;
    xvar->wm_delete_window = XInternAtom(xvar->display, "WM_DELETE_WINDOW", False);
    xvar->wm_protocols = XInternAtom(xvar->display, "WM_PROTOCOLS", False);
    mlx_int_deal_shm(xvar);
    mlx_int_rgb_conversion(xvar);
    xvar->end_loop = 0;
    return (xvar);
}

void mlx_cleanup(t_xvar *xvar)
{
    if (xvar)
    {
        if (xvar->display)
        {
            // Free resources allocated by the X11 library
            t_win_list *win_list = xvar->win_list;
            while (win_list)
            {
                t_win_list *next = win_list->next;
                if (win_list->gc)
                {
                    XFreeGC(xvar->display, win_list->gc);
                }
                if (win_list->pict)
                {
                    XRenderFreePicture(xvar->display, win_list->pict);
                }
                if (win_list->pict_back)
                {
                    XRenderFreePicture(xvar->display, win_list->pict_back);
                }
                if (win_list->window_back)
                {
                    XFreePixmap(xvar->display, win_list->window_back);
                }
                if (win_list->window)
                {
                    XDestroyWindow(xvar->display, win_list->window);
                }
                free(win_list);
                win_list = next;
            }
            if (xvar->cmap)
            {
                XFreeColormap(xvar->display, xvar->cmap);
            }
            XCloseDisplay(xvar->display);
        }
        free(xvar);
    }
}

/*
** pshm_format of -1 : Not XYBitmap|XYPixmap|ZPixmap
** alpha libX need a check of the DISPLAY env var, or shm is allowed
** in remote Xserver connections.
*/

int mlx_int_deal_shm(t_xvar *xvar)
{
    int use_pshm;
    int bidon;
    char *dpy;
    char buff[33];

    xvar->use_xshm = XShmQueryVersion(xvar->display, &bidon, &bidon, &(use_pshm));
    if (xvar->use_xshm && use_pshm)
        xvar->pshm_format = XShmPixmapFormat(xvar->display);
    else
        xvar->pshm_format = -1;
    gethostname(buff, 32);
    dpy = getenv(ENV_DISPLAY);
    if (dpy && strlen(dpy) && *dpy != ':' && strncmp(dpy, buff, strlen(buff)) &&
        strncmp(dpy, LOCALHOST, strlen(LOCALHOST)))
    {
        xvar->pshm_format = -1;
        xvar->use_xshm = 0;
    }
}

/*
** TrueColor Visual is needed to have *_mask correctly set
*/

int mlx_int_rgb_conversion(t_xvar *xvar)
{
    bzero(xvar->decrgb, sizeof(int) * 6);
    while (!(xvar->visual->red_mask & 1))
    {
        xvar->visual->red_mask >>= 1;
        xvar->decrgb[0]++;
    }
    while (xvar->visual->red_mask & 1)
    {
        xvar->visual->red_mask >>= 1;
        xvar->decrgb[1]++;
    }
    while (!(xvar->visual->green_mask & 1))
    {
        xvar->visual->green_mask >>= 1;
        xvar->decrgb[2]++;
    }
    while (xvar->visual->green_mask & 1)
    {
        xvar->visual->green_mask >>= 1;
        xvar->decrgb[3]++;
    }
    while (!(xvar->visual->blue_mask & 1))
    {
        xvar->visual->blue_mask >>= 1;
        xvar->decrgb[4]++;
    }
    while (xvar->visual->blue_mask & 1)
    {
        xvar->visual->blue_mask >>= 1;
        xvar->decrgb[5]++;
    }
}
