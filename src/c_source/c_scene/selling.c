#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <scene/selling.h>

//image
SDL_Rect Selling_imgRect1;
SDL_Texture *Selling_imgTexture1;
SDL_Rect Selling_imgRect2;
SDL_Texture *Selling_imgTexture2;
SDL_Rect Selling_imgRect3;
SDL_Texture *Selling_imgTexture3;
SDL_Rect Selling_imgRect4;
SDL_Texture *Selling_imgTexture4;
SDL_Rect Selling_imgRect5;
SDL_Texture *Selling_imgTexture5;
SDL_Rect Selling_imgRect6;
SDL_Texture *Selling_imgTexture6;

SDL_Rect Selling_imgRect7;
SDL_Texture *Selling_imgTexture7;
SDL_Rect Selling_imgRect8;
SDL_Texture *Selling_imgTexture8;
SDL_Rect Selling_imgRect9;
SDL_Texture *Selling_imgTexture9;
SDL_Rect Selling_imgRect10;
SDL_Texture *Selling_imgTexture10;
SDL_Rect Selling_imgRect11;
SDL_Texture *Selling_imgTexture11;

//text
SDL_Texture *Selling_texTexture1;
SDL_Rect Selling_texRect1;
SDL_Texture *Selling_texTexture2;
SDL_Rect Selling_texRect2;
SDL_Texture *Selling_texTexture3;
SDL_Rect Selling_texRect3;
SDL_Texture *Selling_texTexture4;
SDL_Rect Selling_texRect4;

void Selling_Initial(SDL_Renderer *renderer){

    //image

    SDL_Surface *imgSur1 = IMG_Load("src/ImgPro/selling_Background.png");
    Selling_imgTexture1 = SDL_CreateTextureFromSurface(renderer, imgSur1);
    Selling_imgRect1.x = 40;
    Selling_imgRect1.y = 25;
    Selling_imgRect1.w = 680;
    Selling_imgRect1.h = 90;

    SDL_Surface *imgSur2 = IMG_Load("src/ImgPro/selling_Tree.png");
    Selling_imgTexture2 = SDL_CreateTextureFromSurface(renderer, imgSur2);
    Selling_imgRect2.x = 10;
    Selling_imgRect2.y = 150;
    Selling_imgRect2.w = 500;
    Selling_imgRect2.h = 510;

    SDL_Surface *imgSur3 = IMG_Load("src/ImgPro/selling_price.png");
    Selling_imgTexture3 = SDL_CreateTextureFromSurface(renderer, imgSur3);
    Selling_imgRect3.x = 515;
    Selling_imgRect3.y = 250;
    Selling_imgRect3.w = 220;
    Selling_imgRect3.h = (int)(Selling_imgRect3.w * ((float)imgSur3->h / imgSur3->w));

    SDL_Surface *imgSur4 = IMG_Load("src/ImgPro/selling_PriceFix2.png");
    Selling_imgTexture4 = SDL_CreateTextureFromSurface(renderer, imgSur4);
    Selling_imgRect4.x = 515;
    Selling_imgRect4.y = 420;
    Selling_imgRect4.w = 220;
    Selling_imgRect4.h = (int)(Selling_imgRect4.w * ((float)imgSur4->h / imgSur4->w));

    SDL_Surface *imgSur5 = IMG_Load("src/ImgPro/selling_OK.png");
    Selling_imgTexture5 = SDL_CreateTextureFromSurface(renderer, imgSur5);
    Selling_imgRect5.x = 580;
    Selling_imgRect5.y = 550;
    Selling_imgRect5.w = 90;
    Selling_imgRect5.h = (int)(Selling_imgRect5.w * ((float)imgSur5->h / imgSur5->w));

    SDL_Surface *imgSur6 = IMG_Load("src/ImgPro/Back.png");
    Selling_imgTexture6 = SDL_CreateTextureFromSurface(renderer, imgSur6);
    Selling_imgRect6.x = 25;
    Selling_imgRect6.y = 680;
    Selling_imgRect6.w = 60;
    Selling_imgRect6.h = (int)(Selling_imgRect6.w * ((float)imgSur6->h / imgSur6->w));

    //img_product

    SDL_Surface *imgSur7 = IMG_Load("src/ImgPro/eSpring.png");
    Selling_imgTexture7 = SDL_CreateTextureFromSurface(renderer, imgSur7);
    Selling_imgRect7.x = 65;
    Selling_imgRect7.y = 260;
    Selling_imgRect7.w = 80;
    Selling_imgRect7.h = (int)(Selling_imgRect7.w * ((float)imgSur7->h / imgSur7->w));

    SDL_Surface *imgSur8 = IMG_Load("src/ImgPro/Water_filter.png");
    Selling_imgTexture8 = SDL_CreateTextureFromSurface(renderer, imgSur8);
    Selling_imgRect8.x = 225;
    Selling_imgRect8.y = 260;
    Selling_imgRect8.w = 80;
    Selling_imgRect8.h = (int)(Selling_imgRect8.w * ((float)imgSur8->h / imgSur8->w));

    SDL_Surface *imgSur9 = IMG_Load("src/ImgPro/Atmosphere.png");
    Selling_imgTexture9 = SDL_CreateTextureFromSurface(renderer, imgSur9);
    Selling_imgRect9.x = 385;
    Selling_imgRect9.y = 260;
    Selling_imgRect9.w = 80;
    Selling_imgRect9.h = (int)(Selling_imgRect9.w * ((float)imgSur9->h / imgSur9->w));

    SDL_Surface *imgSur10 = IMG_Load("src/ImgPro/Air_filter.png");
    Selling_imgTexture10 = SDL_CreateTextureFromSurface(renderer, imgSur10);
    Selling_imgRect10.x = 110;
    Selling_imgRect10.y = 460;
    Selling_imgRect10.w = 110;
    Selling_imgRect10.h = (int)(Selling_imgRect10.w * ((float)imgSur10->h / imgSur10->w));

    SDL_Surface *imgSur11 = IMG_Load("src/ImgPro/Smart_watch.png");
    Selling_imgTexture11 = SDL_CreateTextureFromSurface(renderer, imgSur11);
    Selling_imgRect11.x = 290;
    Selling_imgRect11.y = 460;
    Selling_imgRect11.w = 110;
    Selling_imgRect11.h = (int)(Selling_imgRect11.w * ((float)imgSur11->h / imgSur11->w));


    //text

    TTF_Font *fFont1 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 45);
    SDL_Color fColor1 = {0, 0, 0, 255};
    SDL_Surface *textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, "Fix the selling price", fColor1, 750);
    Selling_texTexture1 = SDL_CreateTextureFromSurface(renderer, textSur1);
    Selling_texRect1.x = 70;
    Selling_texRect1.y = 30;
    Selling_texRect1.w = textSur1->w;
    Selling_texRect1.h = textSur1->h;

    TTF_Font *fFont2 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 30);
    SDL_Color fColor2 = {0, 0, 0, 255};
    SDL_Surface *textSur2 = TTF_RenderText_Blended_Wrapped(fFont2, "Price", fColor2, 720);
    Selling_texTexture2 = SDL_CreateTextureFromSurface(renderer, textSur2);
    Selling_texRect2.x = 530;
    Selling_texRect2.y = 195;
    Selling_texRect2.w = textSur2->w;
    Selling_texRect2.h = textSur2->h;

    TTF_Font *fFont3 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 30);
    SDL_Color fColor3 = {0, 0, 0, 255};
    SDL_Surface *textSur3 = TTF_RenderText_Blended_Wrapped(fFont3, "Fix", fColor3, 720);
    Selling_texTexture3 = SDL_CreateTextureFromSurface(renderer, textSur3);
    Selling_texRect3.x = 530;
    Selling_texRect3.y = 365;
    Selling_texRect3.w = textSur3->w;
    Selling_texRect3.h = textSur3->h;

    TTF_Font *fFont4 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 20);
    SDL_Color fColor4 = {2, 54, 81, 255};
    SDL_Surface *textSur4 = TTF_RenderText_Blended_Wrapped(fFont3, "OK", fColor3, 720);
    Selling_texTexture4 = SDL_CreateTextureFromSurface(renderer, textSur4);
    Selling_texRect4.x = 595;
    Selling_texRect4.y = 570;
    Selling_texRect4.w = textSur4->w;
    Selling_texRect4.h = textSur4->h;
    
}

void Selling_DrawScene(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 199, 231, 240, 200); //217,241,255
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, Selling_imgTexture1, NULL, &Selling_imgRect1);
    SDL_RenderCopy(renderer, Selling_imgTexture2, NULL, &Selling_imgRect2);
    SDL_RenderCopy(renderer, Selling_imgTexture3, NULL, &Selling_imgRect3);
    SDL_RenderCopy(renderer, Selling_imgTexture4, NULL, &Selling_imgRect4);
    SDL_RenderCopy(renderer, Selling_imgTexture5, NULL, &Selling_imgRect5);
    SDL_RenderCopy(renderer, Selling_imgTexture6, NULL, &Selling_imgRect6);

    SDL_RenderCopy(renderer, Selling_imgTexture7, NULL, &Selling_imgRect7);
    SDL_RenderCopy(renderer, Selling_imgTexture8, NULL, &Selling_imgRect8);
    SDL_RenderCopy(renderer, Selling_imgTexture9, NULL, &Selling_imgRect9);
    SDL_RenderCopy(renderer, Selling_imgTexture10, NULL, &Selling_imgRect10);
    SDL_RenderCopy(renderer, Selling_imgTexture11, NULL, &Selling_imgRect11);

    //text
    SDL_RenderCopy(renderer, Selling_texTexture1, NULL, &Selling_texRect1);
    SDL_RenderCopy(renderer, Selling_texTexture2, NULL, &Selling_texRect2);
    SDL_RenderCopy(renderer, Selling_texTexture3, NULL, &Selling_texRect3);
    SDL_RenderCopy(renderer, Selling_texTexture4, NULL, &Selling_texRect4);
    
    SDL_RenderPresent(renderer);
}