/*
** wireframe.c for wireframe in /home/jeremy.elkaim/wireframe
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Mon Dec  5 10:16:38 2016 jeremy elkaim
** Last update Wed Dec  7 16:59:37 2016 jeremy elkaim
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <stdlib.h>
#include <SFML/Window/Keyboard.h>

typedef struct          s_my_framebuffer
{
  sfUint8*              pixels;
  int                   width;
  int                   height;
}			t_my_framebuffer;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

sfUint8* create_pixel_buffer(int width, int height)
{
  int i;
  sfUint8* pixels;

  pixels = malloc(width * height * 4 * sizeof(pixels));
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

sfRenderWindow* create_window(char* name, int width, int height)
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

void            my_put_pixel(t_my_framebuffer* framebuffer, int x, int y, sfColor color)
{
  framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
}

int main()
{
  sfRenderWindow* window;
  sfTexture* texture;
  sfSprite* sprite;
  t_my_framebuffer* framebuffer;
  int	a;
  int	b;

  a = 640;
  b = 480;
  framebuffer->width = a;
  framebuffer->height = b;
  sprite = sfSprite_create();
  texture = sfTexture_create(framebuffer->width, framebuffer->height);
  framebuffer->pixels = create_pixel_buffer(framebuffer->width, framebuffer->height);
  sfSprite_setTexture(sprite, texture, sfTrue);
  my_put_pixel(framebuffer->pixels, 20, 40, sfRed);
  sfTexture_updateFromPixels(texture, framebuffer->pixels, framebuffer->width, framebuffer->height, 0, 0);
  window = create_window("window", framebuffer->width, framebuffer->height);
  while (sfRenderWindow_isOpen(window))
    {
      if (sfKeyboard_isKeyPressed(sfKeyEscape))
	{
	  sfRenderWindow_destroy(window);
	  return (EXIT_FAILURE);
	}
      sfRenderWindow_clear(window, sfBlack);
      sfRenderWindow_display(window);
    }
  sfRenderWindow_destroy(window);
  return (EXIT_SUCCESS);
}
