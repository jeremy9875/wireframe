/*
** my_put_pixel.c for my_put_pixel in /home/jeremy.elkaim/wireframe
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Tue Dec  6 08:46:42 2016 jeremy elkaim
** Last update Mon Dec 12 16:54:57 2016 jeremy elkaim
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Window/Keyboard.h>

typedef struct          s_my_framebuffer
{
  sfUint8*              pixels;
  int                   width;
  int                   height;
}                       t_my_framebuffer;

/*t_my_framebuffer *create_buffer(int width, int height)
{
  int i;
  int	*framebuffer;

  framebuffer = malloc(sizeof(t_my_framebuffer));
  framebuffer->width = width;
  framebuffer->height = height;
  framebuffer-pixels = malloc(framebuffer->width * framebuffer->height * 4 * sizeof(*framebuffer->pixels));
  {
    exit(EXIT_FAILURE);
  }
  i = 0;
  while (i < framebuffer->width * framebuffer->height * 4)
    {
      framebuffer->pixels[i] = 0;
      i = i + 1;
    }
  return (framebuffer);
}*/

sfUint8* create_pixel_buffer(int width, int height)
{
  int i;
  sfUint8* pixels;

  pixels = malloc(width * height * 4 * sizeof(*pixels));
  if (pixels == NULL)
    {
      exit(EXIT_FAILURE);
    }
  i = 0;
  while (i < width * height * 4)
    {
      pixels[i] = 0;
      i = i + 1;
    }
  return pixels;
}

sfRenderWindow*	create_window(char* name, int width, int height)
{
  sfRenderWindow* window;
  sfVideoMode mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    {
      exit(EXIT_FAILURE);
    }
  return window;
}

void	my_put_pixel(t_my_framebuffer* framebuffer, int x, int y, sfColor color)
{
  framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
}
