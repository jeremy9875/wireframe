/*
** my_draw_line.c for my_draw_line in /home/jeremy.elkaim/wireframe
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Tue Dec  6 08:17:55 2016 jeremy elkaim
** Last update Tue Dec  6 08:44:16 2016 jeremy elkaim
*/
#include "struct.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <stdlib.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

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

void	my_draw_line(t_my_framebuffer* framebuffer, sfVector2f from, sfVector2f to, sfColor color)
{
  t_my_framebuffer*	my_framebuffer_create(int width, int height);
}
