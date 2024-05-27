#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <system/struct.h>

#ifndef COMLOAD_H
#define COMLOAD_H

void createIMGTexture_Rect(SDL_Renderer *renderer, objectComponent *obj, const char* source, int x, int y, int w, int h);
void createTextTexture_Rect(SDL_Renderer *renderer, objectComponent *obj, const char* text, const char* fontSource, int size, Uint8 r, Uint8 g, Uint8 b, Uint8 a, int x, int y);
void placeObject(SDL_Renderer *renderer, objectComponent *obj);
int isClickOnObject(struct eventTrigger *eventData, objectComponent *obj);

// Search bar Setting
extern NodePtr previousRoot;
extern NodePtr currentSelect;
extern NodePtr currentRoot;

extern char searchText[11];
extern int searchBarUsing;
extern char currentShift;
extern SDL_Rect searchbarRect;
extern SDL_Rect searchButtonRect;

extern objectComponent nodeObj[2];

void SearchBar(SDL_Renderer *renderer, struct eventTrigger* eventData);
void DrawNode(SDL_Renderer *renderer, struct eventTrigger* eventData);
#endif
