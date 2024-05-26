#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <system/struct.h>

void createIMGTexture_Rect(SDL_Renderer *renderer, SDL_Texture **texture, SDL_Rect *rect, const char* source, int x, int y, int w){
    SDL_Surface *imgSur = IMG_Load(source);
    *texture = SDL_CreateTextureFromSurface(renderer, imgSur);
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = (int)(rect->w * ((float)imgSur->h / imgSur->w));

    SDL_FreeSurface(imgSur);
}

void createTextTexture_Rect(SDL_Renderer *renderer, SDL_Texture **texture, SDL_Rect *rect, const char* text, const char* fontSource, int size, Uint8 r, Uint8 g, Uint8 b, Uint8 a, int x, int y){
    TTF_Font *fFont = TTF_OpenFont(fontSource, size);
    SDL_Color fColor = {r, g, b, a};
    SDL_Surface *textSur = TTF_RenderText_Blended_Wrapped(fFont, text, fColor, 750);
    *texture = SDL_CreateTextureFromSurface(renderer, textSur);
    rect->x = x;
    rect->y = y;
    rect->w = textSur->w;
    rect->h = textSur->h;

    SDL_FreeSurface(textSur);
    TTF_CloseFont(fFont);
}

int isClickOnObject(struct eventTrigger *eventData, SDL_Rect *checkedItem){
    if(eventData->mouseX > checkedItem->x && eventData->mouseX < checkedItem->x + checkedItem->w && eventData->mouseY > checkedItem->y && eventData->mouseY < checkedItem->y + checkedItem->h){
        if(eventData->isTrigger == 1) return 2;
        else return 1;
    }
    return 0;
}