#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <scene/title.h>
#include <system/struct.h>
#include <system/nodeHandle.h>
#include <system/componentLoad.h>
#include <stdlib.h>

SDL_Rect Title_imgRect1;
SDL_Texture *Title_imgTexture1;

//กรอบ
SDL_Rect Title_rect1;

//text
SDL_Texture *Title_texTexture1;
SDL_Rect Title_texRect1;
SDL_Texture *Title_texTexture2;
SDL_Rect Title_texRect2;
SDL_Texture *Title_texTexture3;
SDL_Rect Title_texRect3;
SDL_Texture *Title_texTexture4;
SDL_Rect Title_texRect4;
SDL_Texture *Title_texTexture5;
SDL_Rect Title_texRect5;

int Title_CurrentFirstRun = 1;

void StartButtonEvent(){
    currentRoom = 1;
    // Title_DestoryObject();
}
//object
struct object *Title_StartButton;


void Title_Initial(SDL_Renderer *renderer){
    Title_StartButton = (struct object*) malloc(sizeof(struct object));
    Title_StartButton->clickEvent = StartButtonEvent;

    //กรอบหัวข้อ
    Title_rect1.x = 50;
    Title_rect1.y = 80;
    Title_rect1.w = 650;
    Title_rect1.h = 165;

    createIMGTexture_Rect(renderer, &Title_imgTexture1, &Title_imgRect1, "src/image/Title_StartSim.png", 70, 340, 590);
    Title_StartButton->pos1[0] = Title_imgRect1.x;
    Title_StartButton->pos1[1] = Title_imgRect1.y;
    Title_StartButton->pos2[0] = Title_imgRect1.x + Title_imgRect1.w;
    Title_StartButton->pos2[1] = Title_imgRect1.y + Title_imgRect1.h;

    createTextTexture_Rect(renderer, &Title_texTexture1, &Title_texRect1, "Multi-Level Marketing", "src/font/HoltwoodOneSC-Regular.ttf", 40, 180, 234, 230, 255, 70, 100);
    createTextTexture_Rect(renderer, &Title_texTexture2, &Title_texRect2, "Simulation", "src/font/HoltwoodOneSC-Regular.ttf", 40, 180, 234, 230, 255, 225, 165);
    createTextTexture_Rect(renderer, &Title_texTexture3, &Title_texRect3, "Using Amway Marketing", "src/font/Alegreya-VariableFont_wght.ttf", 20, 2, 54, 81, 255, 520, 710);
    createTextTexture_Rect(renderer, &Title_texTexture4, &Title_texRect4, "Start", "src/font/HoltwoodOneSC-Regular.ttf", 45, 0, 0, 0, 255, 280, 380);
    createTextTexture_Rect(renderer, &Title_texTexture5, &Title_texRect5, "Simulation", "src/font/HoltwoodOneSC-Regular.ttf", 45, 0, 0, 0, 255, 180, 450);
}

void Title_Run(SDL_Renderer *renderer, struct eventTrigger *eventData){
    if(isClickOnObject(eventData, &Title_imgRect1) == 2)
    {
        StartButtonEvent();
        initialNode(&rootOfMLM);
    }
    Title_DrawScene(renderer);
}

void Title_DrawScene(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 199, 231, 240, 200);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, Title_imgTexture1, NULL, &Title_imgRect1);

    SDL_SetRenderDrawColor(renderer, 1, 19, 74 ,255);
    SDL_RenderFillRect(renderer, &Title_rect1);

    SDL_RenderCopy(renderer, Title_texTexture1, NULL, &Title_texRect1);
    SDL_RenderCopy(renderer, Title_texTexture2, NULL, &Title_texRect2);
    SDL_RenderCopy(renderer, Title_texTexture3, NULL, &Title_texRect3);
    SDL_RenderCopy(renderer, Title_texTexture4, NULL, &Title_texRect4);
    SDL_RenderCopy(renderer, Title_texTexture5, NULL, &Title_texRect5);
    
    SDL_RenderPresent(renderer);
}