/*
** wireframe.c for wireframe in /home/jeremy.elkaim/wireframe
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Mon Dec  5 10:16:38 2016 jeremy elkaim
** Last update Mon Dec 12 16:57:28 2016 jeremy elkaim
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
  window = create_window("window", framebuffer->width, framebuffer->height);
  sprite = sfSprite_create();
  texture = sfTexture_create(framebuffer->width, framebuffer->height);
  framebuffer->pixels = create_pixel_buffer(framebuffer->width, framebuffer->height);
  sfSprite_setTexture(sprite, texture, sfTrue);
  my_put_pixel(framebuffer, 30, 300, sfRed);
  sfTexture_updateFromPixels(texture, framebuffer->pixels, framebuffer->width, framebuffer->height, 0, 0);
  while (sfRenderWindow_isOpen(window))
    {
      if (sfKeyboard_isKeyPressed(sfKeyEscape))
	{
	  sfRenderWindow_destroy(window);
	  return (EXIT_FAILURE);
	}
      sfRenderWindow_clear(window, sfBlack);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
    }
  sfRenderWindow_destroy(window);
  return (EXIT_SUCCESS);
}
