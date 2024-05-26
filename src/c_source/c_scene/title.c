#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <scene/title.h>
#include <system/struct.h>
#include <system/nodeHandle.h>
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

void Title_DestoryObject(){
    SDL_DestroyTexture(Title_imgTexture1);
    SDL_DestroyTexture(Title_texTexture1);
    SDL_DestroyTexture(Title_texTexture2);
    SDL_DestroyTexture(Title_texTexture3);
    SDL_DestroyTexture(Title_texTexture4);
    SDL_DestroyTexture(Title_texTexture5); 
}

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


    SDL_Surface *imgSur1 = IMG_Load("src/image/Title_StartSim.png");
    Title_imgTexture1 = SDL_CreateTextureFromSurface(renderer, imgSur1);
    Title_imgRect1.x = 70;
    Title_imgRect1.y = 340;
    Title_imgRect1.w = 590;
    Title_imgRect1.h = (int)(Title_imgRect1.w * ((float)imgSur1->h / imgSur1->w));
    Title_StartButton->pos1[0] = Title_imgRect1.x;
    Title_StartButton->pos1[1] = Title_imgRect1.y;
    Title_StartButton->pos2[0] = Title_imgRect1.x + Title_imgRect1.w;
    Title_StartButton->pos2[1] = Title_imgRect1.y + Title_imgRect1.h;

    // SDL_FreeSurface(imgSur1);
    //text

    TTF_Font *fFont1 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 40);
    SDL_Color fColor1 = {180, 234, 230 , 255};
    SDL_Surface *textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, "Multi-Level Marketing", fColor1, 700);
    Title_texTexture1 = SDL_CreateTextureFromSurface(renderer, textSur1);
    Title_texRect1.x = 70;
    Title_texRect1.y = 100;
    Title_texRect1.w = textSur1->w;
    Title_texRect1.h = textSur1->h;

    // SDL_FreeSurface(textSur1);
    // free(fFont1);

    TTF_Font *fFont2 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 40);
    SDL_Color fColor2 = {180, 234, 230 , 255};
    SDL_Surface *textSur2 = TTF_RenderText_Blended_Wrapped(fFont2, "Simulation", fColor2, 500);
    Title_texTexture2 = SDL_CreateTextureFromSurface(renderer, textSur2);
    Title_texRect2.x = 225;
    Title_texRect2.y = 165;
    Title_texRect2.w = textSur2->w;
    Title_texRect2.h = textSur2->h;

    // SDL_FreeSurface(textSur2);
    // free(fFont2);

    TTF_Font *fFont3 = TTF_OpenFont("src/font/Alegreya-VariableFont_wght.ttf", 20);
    SDL_Color fColor3 = {2, 54, 81, 255};
    SDL_Surface *textSur3 = TTF_RenderText_Blended_Wrapped(fFont3, "Using Amway Marketing", fColor3, 720);
    Title_texTexture3 = SDL_CreateTextureFromSurface(renderer, textSur3);
    Title_texRect3.x = 520;
    Title_texRect3.y = 710;
    Title_texRect3.w = textSur3->w;
    Title_texRect3.h = textSur3->h;

    // SDL_FreeSurface(textSur3);
    // free(fFont3);

    TTF_Font *fFont4 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 45);
    SDL_Color fColor4 = {0, 0, 0, 255};
    SDL_Surface *textSur4 = TTF_RenderText_Blended_Wrapped(fFont4, "Start", fColor4, 500);
    Title_texTexture4 = SDL_CreateTextureFromSurface(renderer, textSur4);
    Title_texRect4.x = 280;
    Title_texRect4.y = 380;
    Title_texRect4.w = textSur4->w;
    Title_texRect4.h = textSur4->h;

    // SDL_FreeSurface(textSur4);
    // free(fFont4);

    TTF_Font *fFont5 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 45);
    SDL_Color fColor5 = {0, 0, 0, 255};
    SDL_Surface *textSur5 = TTF_RenderText_Blended_Wrapped(fFont4, "Simulation", fColor5, 500);
    Title_texTexture5 = SDL_CreateTextureFromSurface(renderer, textSur5);
    Title_texRect5.x = 180;
    Title_texRect5.y = 450;
    Title_texRect5.w = textSur5->w;
    Title_texRect5.h = textSur5->h;

    // SDL_FreeSurface(textSur5);
    // free(fFont5);
}

void Title_Run(SDL_Renderer *renderer, struct eventTrigger *eventData){
    if(eventData->isTrigger == 1 && eventData->mouseX > Title_StartButton->pos1[0] && eventData->mouseX < Title_StartButton->pos2[0] && eventData->mouseY > Title_StartButton->pos1[1] && eventData->mouseY < Title_StartButton->pos2[1]){
        Title_StartButton->clickEvent();
        initialNode(&rootOfMLM);
    }
    Title_DrawScene(renderer);
}

void Title_DrawScene(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 199, 231, 240, 200); //217,241,255
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