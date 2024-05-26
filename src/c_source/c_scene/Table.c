#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <scene/Table.h>

//image
SDL_Rect Table_imgRect1;
SDL_Texture *Table_imgTexture1;
SDL_Rect Table_imgRect2;
SDL_Texture *Table_imgTexture2;
SDL_Rect Table_imgRect3;
SDL_Texture *Table_imgTexture3;
SDL_Rect Table_imgRect4;
SDL_Texture *Table_imgTexture4;
SDL_Rect Table_imgRect5;
SDL_Texture *Table_imgTexture5;


//text
SDL_Texture *Table_texTexture1;
SDL_Rect Table_texRect1;
SDL_Texture *Table_texTexture2;
SDL_Rect Table_texRect2;
SDL_Texture *Table_texTexture3;
SDL_Rect Table_texRect3;
SDL_Texture *Table_texTexture4;
SDL_Rect Table_texRect4;
SDL_Texture *Table_texTexture5;
SDL_Rect Table_texRect5;
SDL_Texture *Table_texTexture6;
SDL_Rect Table_texRect6;


void Table_Initial(SDL_Renderer *renderer){

    //image

    SDL_Surface *imgSur1 = IMG_Load("src/image/Table_Tree.png");
    Table_imgTexture1 = SDL_CreateTextureFromSurface(renderer, imgSur1);
    Table_imgRect1.x = 20;
    Table_imgRect1.y = 30;
    Table_imgRect1.w = 180;
    Table_imgRect1.h = (int)(Table_imgRect1.w * ((float)imgSur1->h / imgSur1->w));

    SDL_Surface *imgSur2 = IMG_Load("src/image/Result_search.png");
    Table_imgTexture2 = SDL_CreateTextureFromSurface(renderer, imgSur2);
    Table_imgRect2.x = 460;
    Table_imgRect2.y = 35;
    Table_imgRect2.w = 270;
    Table_imgRect2.h = (int)(Table_imgRect2.w * ((float)imgSur2->h / imgSur2->w));

    SDL_Surface *imgSur3 = IMG_Load("src/image/Table_TableMix.png");
    Table_imgTexture3 = SDL_CreateTextureFromSurface(renderer, imgSur3);
    Table_imgRect3.x = 35;
    Table_imgRect3.y = 110;
    Table_imgRect3.w = 680;
    Table_imgRect3.h = (int)(Table_imgRect3.w * ((float)imgSur3->h / imgSur3->w));

    SDL_Surface *imgSur4 = IMG_Load("src/image/Table_Back.png");
    Table_imgTexture4 = SDL_CreateTextureFromSurface(renderer, imgSur4);
    Table_imgRect4.x = 10;
    Table_imgRect4.y = 705;
    Table_imgRect4.w = 35;
    Table_imgRect4.h = (int)(Table_imgRect4.w * ((float)imgSur4->h / imgSur4->w));

    SDL_Surface *imgSur5 = IMG_Load("src/image/Table_Next.png");
    Table_imgTexture5 = SDL_CreateTextureFromSurface(renderer, imgSur5);
    Table_imgRect5.x = 700;
    Table_imgRect5.y = 705;
    Table_imgRect5.w = 35;
    Table_imgRect5.h = (int)(Table_imgRect5.w * ((float)imgSur5->h / imgSur5->w));


    //text

    TTF_Font *fFont1 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 30);
    SDL_Color fColor1 = {0, 0, 0, 255};
    SDL_Surface *textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, "Tree", fColor1, 750);
    Table_texTexture1 = SDL_CreateTextureFromSurface(renderer, textSur1);
    Table_texRect1.x = 87;
    Table_texRect1.y = 30;
    Table_texRect1.w = textSur1->w;
    Table_texRect1.h = textSur1->h;

    TTF_Font *fFont2 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 55);
    SDL_Color fColor2 = {0, 0, 0, 255};
    SDL_Surface *textSur2 = TTF_RenderText_Blended_Wrapped(fFont2, "Table", fColor2, 750);
    Table_texTexture2 = SDL_CreateTextureFromSurface(renderer, textSur2);
    Table_texRect2.x = 230;
    Table_texRect2.y = 10;
    Table_texRect2.w = textSur2->w;
    Table_texRect2.h = textSur2->h;

    TTF_Font *fFont3 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 42);
    SDL_Color fColor3 = {0, 0, 0, 255};
    SDL_Surface *textSur3 = TTF_RenderText_Blended_Wrapped(fFont3, "Name", fColor3, 750);
    Table_texTexture3 = SDL_CreateTextureFromSurface(renderer, textSur3);
    Table_texRect3.x = 65;
    Table_texRect3.y = 133;
    Table_texRect3.w = textSur3->w;
    Table_texRect3.h = textSur3->h;

    TTF_Font *fFont4 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 42);
    SDL_Color fColor4 = {0, 0, 0, 255};
    SDL_Surface *textSur4 = TTF_RenderText_Blended_Wrapped(fFont4, "BV", fColor4, 750);
    Table_texTexture4 = SDL_CreateTextureFromSurface(renderer, textSur4);
    Table_texRect4.x = 263;
    Table_texRect4.y = 133;
    Table_texRect4.w = textSur4->w;
    Table_texRect4.h = textSur4->h;

    TTF_Font *fFont5 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 42);
    SDL_Color fColor5 = {0, 0, 0, 255};
    SDL_Surface *textSur5 = TTF_RenderText_Blended_Wrapped(fFont5, "PV", fColor5, 750);
    Table_texTexture5 = SDL_CreateTextureFromSurface(renderer, textSur5);
    Table_texRect5.x = 385;
    Table_texRect5.y = 133;
    Table_texRect5.w = textSur5->w;
    Table_texRect5.h = textSur5->h;

    TTF_Font *fFont6 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 42);
    SDL_Color fColor6 = {0, 0, 0, 255};
    SDL_Surface *textSur6 = TTF_RenderText_Blended_Wrapped(fFont6, "Salary", fColor6, 750);
    Table_texTexture6 = SDL_CreateTextureFromSurface(renderer, textSur6);
    Table_texRect6.x = 495;
    Table_texRect6.y = 133;
    Table_texRect6.w = textSur6->w;
    Table_texRect6.h = textSur6->h;

}

void Table_DrawScene(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 199, 231, 240, 200); //217,241,255
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, Table_imgTexture1, NULL, &Table_imgRect1);
    SDL_RenderCopy(renderer, Table_imgTexture2, NULL, &Table_imgRect2);
    SDL_RenderCopy(renderer, Table_imgTexture3, NULL, &Table_imgRect3);
    SDL_RenderCopy(renderer, Table_imgTexture4, NULL, &Table_imgRect4);
    SDL_RenderCopy(renderer, Table_imgTexture5, NULL, &Table_imgRect5);


    SDL_RenderCopy(renderer, Table_texTexture1, NULL, &Table_texRect1);
    SDL_RenderCopy(renderer, Table_texTexture2, NULL, &Table_texRect2);
    SDL_RenderCopy(renderer, Table_texTexture3, NULL, &Table_texRect3);
    SDL_RenderCopy(renderer, Table_texTexture4, NULL, &Table_texRect4);
    SDL_RenderCopy(renderer, Table_texTexture5, NULL, &Table_texRect5);
    SDL_RenderCopy(renderer, Table_texTexture6, NULL, &Table_texRect6);
    

    
    SDL_RenderPresent(renderer);
}