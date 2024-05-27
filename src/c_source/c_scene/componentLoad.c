#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <system/struct.h>

void createIMGTexture_Rect(SDL_Renderer *renderer, objectComponent *obj, const char* source, int x, int y, int w, int h){
    SDL_Surface *imgSur = IMG_Load(source);
    obj->objectTexture = SDL_CreateTextureFromSurface(renderer, imgSur);
    obj->objectRect.x = x;
    obj->objectRect.y = y;
    obj->objectRect.w = w;
    obj->objectRect.h = h == -1 ? (int)(obj->objectRect.w * ((float)imgSur->h / imgSur->w)) : h;

    SDL_FreeSurface(imgSur);
}

void createTextTexture_Rect(SDL_Renderer *renderer, objectComponent *obj, const char* text, const char* fontSource, int size, Uint8 r, Uint8 g, Uint8 b, Uint8 a, int x, int y){
    TTF_Font *fFont = TTF_OpenFont(fontSource, size);
    SDL_Color fColor = {r, g, b, a};
    SDL_Surface *textSur = TTF_RenderText_Blended_Wrapped(fFont, text, fColor, 750);
    obj->objectTexture = SDL_CreateTextureFromSurface(renderer, textSur);
    obj->objectRect.x = x;
    obj->objectRect.y = y;
    obj->objectRect.w = textSur->w;
    obj->objectRect.h = textSur->h;

    SDL_FreeSurface(textSur);
    TTF_CloseFont(fFont);
}

void placeObject(SDL_Renderer *renderer, objectComponent *obj){
    SDL_RenderCopy(renderer, obj->objectTexture, NULL, &obj->objectRect);
}

int isClickOnObject(struct eventTrigger *eventData, objectComponent *obj){
    if(eventData->mouseX >= obj->objectRect.x && eventData->mouseX <= obj->objectRect.x + obj->objectRect.w && eventData->mouseY >= obj->objectRect.y && eventData->mouseY <= obj->objectRect.y + obj->objectRect.h){
        if(eventData->isTrigger == 1) return 2;
        else return 1;
    }
    return 0;
}