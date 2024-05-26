#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#ifndef COMLOAD_H
#define COMLOAD_H

void createIMGTexture_Rect(SDL_Renderer *renderer, SDL_Texture **texture, SDL_Rect *rect, const char* source, int x, int y, int w);
void createTextTexture_Rect(SDL_Renderer *renderer, SDL_Texture **texture, SDL_Rect *rect, const char* text, const char* fontSource, int size, Uint8 r, Uint8 g, Uint8 b, Uint8 a, int x, int y);
int isClickOnObject(struct eventTrigger *eventData, SDL_Rect checkedItem);

// Search bar Setting
extern NodePtr previousRoot;
extern NodePtr currentSelect;
extern NodePtr currentRoot;

extern char searchText[10];
extern int searchBarUsing;
extern char currentShift;
extern SDL_Rect searchbarRect;
extern SDL_Rect searchButtonRect;

void SearchBar(SDL_Renderer *renderer, struct eventTrigger* eventData);
#endif
