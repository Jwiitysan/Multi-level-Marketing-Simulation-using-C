#include <SDL2/SDL.h>

#ifndef SCENE_H
#define SCENE_H

void Amount_Initial(SDL_Renderer *renderer);
void Amount_DrawScene(SDL_Renderer *renderer, struct eventTrigger *eventData);

void NewDownline_Initial(SDL_Renderer *renderer);
void NewDownline_DrawScene(SDL_Renderer *renderer, struct eventTrigger *eventData);

void PersonalInfo_Initial(SDL_Renderer *renderer);
void PersonalInfo_DrawScene(SDL_Renderer *renderer, struct eventTrigger *eventData);

void Result_Initial(SDL_Renderer *renderer);
void Result_Run(SDL_Renderer *renderer, struct eventTrigger *eventData);

void Salary_Initial(SDL_Renderer *renderer);
void Salary_DrawScene(SDL_Renderer *renderer, struct eventTrigger *eventData);

void Selling_Initial(SDL_Renderer *renderer);
void Selling_DrawScene(SDL_Renderer *renderer);

void Title_Initial(SDL_Renderer *renderer);
void Title_Run(SDL_Renderer *renderer, struct eventTrigger *eventData);

#endif