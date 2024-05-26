#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <system/scene.h>
#include <system/struct.h>
#include <string.h>

//image
SDL_Rect PersonalInfo_imgRect1;
SDL_Texture *PersonalInfo_imgTexture1;
SDL_Rect PersonalInfo_imgRect2;
SDL_Texture *PersonalInfo_imgTexture2;
SDL_Rect PersonalInfo_imgRect3;
SDL_Texture *PersonalInfo_imgTexture3;
SDL_Rect PersonalInfo_imgRect4;
SDL_Texture *PersonalInfo_imgTexture4;
SDL_Rect PersonalInfo_imgRect5;
SDL_Texture *PersonalInfo_imgTexture5;
SDL_Rect PersonalInfo_imgRect6;
SDL_Texture *PersonalInfo_imgTexture6;
SDL_Rect PersonalInfo_imgRect7;
SDL_Texture *PersonalInfo_imgTexture7;


//text
SDL_Texture *PersonalInfo_texTexture1;
SDL_Rect PersonalInfo_texRect1;
SDL_Texture *PersonalInfo_texTexture2;
SDL_Rect PersonalInfo_texRect2;
SDL_Texture *PersonalInfo_texTexture3;
SDL_Rect PersonalInfo_texRect3;


void PersonalInfo_Initial(SDL_Renderer *renderer){

    //image

    SDL_Surface *imgSur1 = IMG_Load("src/image/PerInfo_Background.png");
    PersonalInfo_imgTexture1 = SDL_CreateTextureFromSurface(renderer, imgSur1);
    PersonalInfo_imgRect1.x = 70;
    PersonalInfo_imgRect1.y = 30;
    PersonalInfo_imgRect1.w = 630;
    PersonalInfo_imgRect1.h = 120;

    SDL_Surface *imgSur2 = IMG_Load("src/image/PerInfo_Tree.png");
    PersonalInfo_imgTexture2 = SDL_CreateTextureFromSurface(renderer, imgSur2);
    PersonalInfo_imgRect2.x = 10;
    PersonalInfo_imgRect2.y = 160;
    PersonalInfo_imgRect2.w = 500;
    PersonalInfo_imgRect2.h = 510;

    SDL_Surface *imgSur3 = IMG_Load("src/image/PerInfo_Name.png");
    PersonalInfo_imgTexture3 = SDL_CreateTextureFromSurface(renderer, imgSur3);
    PersonalInfo_imgRect3.x = 515;
    PersonalInfo_imgRect3.y = 300;
    PersonalInfo_imgRect3.w = 220;
    PersonalInfo_imgRect3.h = (int)(PersonalInfo_imgRect3.w * ((float)imgSur3->h / imgSur3->w));

    SDL_Surface *imgSur4 = IMG_Load("src/image/PerInfo_BV.png");
    PersonalInfo_imgTexture4 = SDL_CreateTextureFromSurface(renderer, imgSur4);
    PersonalInfo_imgRect4.x = 515;
    PersonalInfo_imgRect4.y = 490;
    PersonalInfo_imgRect4.w = 220;
    PersonalInfo_imgRect4.h = (int)(PersonalInfo_imgRect4.w * ((float)imgSur4->h / imgSur4->w));

    SDL_Surface *imgSur5 = IMG_Load("src/image/PerInfo_Back.png");
    PersonalInfo_imgTexture5 = SDL_CreateTextureFromSurface(renderer, imgSur5);
    PersonalInfo_imgRect5.x = 40;
    PersonalInfo_imgRect5.y = 605;
    PersonalInfo_imgRect5.w = 50;
    PersonalInfo_imgRect5.h = (int)(PersonalInfo_imgRect5.w * ((float)imgSur5->h / imgSur5->w));

    SDL_Surface *imgSur6 = IMG_Load("src/image/PerInfo_Next.png");
    PersonalInfo_imgTexture6 = SDL_CreateTextureFromSurface(renderer, imgSur6);
    PersonalInfo_imgRect6.x = 445;
    PersonalInfo_imgRect6.y = 605;
    PersonalInfo_imgRect6.w = 50;
    PersonalInfo_imgRect6.h = (int)(PersonalInfo_imgRect6.w * ((float)imgSur6->h / imgSur6->w));

    SDL_Surface *imgSur7 = IMG_Load("src/image/Back.png");
    PersonalInfo_imgTexture7 = SDL_CreateTextureFromSurface(renderer, imgSur7);
    PersonalInfo_imgRect7.x = 25;
    PersonalInfo_imgRect7.y = 690;
    PersonalInfo_imgRect7.w = 60;
    PersonalInfo_imgRect7.h = (int)(PersonalInfo_imgRect7.w * ((float)imgSur7->h / imgSur7->w));


    //text

    TTF_Font *fFont1 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 55);
    SDL_Color fColor1 = {0, 0, 0, 255};
    SDL_Surface *textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, "Personal Info", fColor1, 750);
    PersonalInfo_texTexture1 = SDL_CreateTextureFromSurface(renderer, textSur1);
    PersonalInfo_texRect1.x = 125;
    PersonalInfo_texRect1.y = 43;
    PersonalInfo_texRect1.w = textSur1->w;
    PersonalInfo_texRect1.h = textSur1->h;

    TTF_Font *fFont2 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 30);
    SDL_Color fColor2 = {0, 0, 0, 255};
    SDL_Surface *textSur2 = TTF_RenderText_Blended_Wrapped(fFont2, "Name", fColor2, 720);
    PersonalInfo_texTexture2 = SDL_CreateTextureFromSurface(renderer, textSur2);
    PersonalInfo_texRect2.x = 530;
    PersonalInfo_texRect2.y = 245;
    PersonalInfo_texRect2.w = textSur2->w;
    PersonalInfo_texRect2.h = textSur2->h;

    TTF_Font *fFont3 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 30);
    SDL_Color fColor3 = {0, 0, 0, 255};
    SDL_Surface *textSur3 = TTF_RenderText_Blended_Wrapped(fFont3, "BV", fColor3, 720);
    PersonalInfo_texTexture3 = SDL_CreateTextureFromSurface(renderer, textSur3);
    PersonalInfo_texRect3.x = 530;
    PersonalInfo_texRect3.y = 435;
    PersonalInfo_texRect3.w = textSur3->w;
    PersonalInfo_texRect3.h = textSur3->h;
}

void PersonalInfo_TextShowInformation(SDL_Renderer *renderer, struct eventTrigger *eventData){
    TTF_Font *fFont0 = TTF_OpenFont("src/font/Alegreya-VariableFont_wght.ttf", 25);
    SDL_Color fColor3 = {0, 0, 0, 255};
    SDL_Surface *textSur3 = TTF_RenderText_Blended_Wrapped(fFont0, sendingNode->name, fColor3, 720);
    SDL_Texture *textTex = SDL_CreateTextureFromSurface(renderer, textSur3);
    SDL_Rect textRect = {595, 320, textSur3->w, textSur3->h};

    SDL_RenderCopy(renderer, textTex, NULL, &textRect);

    SDL_FreeSurface(textSur3);
    SDL_DestroyTexture(textTex);

    char intToString[10];
    itoa(sendingNode->BV, intToString, 10);
    textSur3 = TTF_RenderText_Blended_Wrapped(fFont0, intToString, fColor3, 720);
    textTex = SDL_CreateTextureFromSurface(renderer, textSur3);
    SDL_Rect textRect2 = {595, 500, textSur3->w, textSur3->h};

    SDL_RenderCopy(renderer, textTex, NULL, &textRect2);

    SDL_FreeSurface(textSur3);
    SDL_DestroyTexture(textTex);

    for(int i=0; i < 5; i++){
        char finalText[100];
        strcpy(finalText, "");
        char intToString[10];
        strcat(finalText, product[i]->name);
        strcat(finalText, " -> ");
        itoa(sendingNode->produce[2*i+1], intToString, 10);
        strcat(finalText, intToString);
        strcat(finalText, " x ");
        itoa(sendingNode->produce[2*i], intToString, 10);
        strcat(finalText, intToString);
        strcat(finalText, " (");
        itoa(product[i]->price, intToString, 10);
        strcat(finalText, intToString);
        strcat(finalText, ")");
        
        textSur3 = TTF_RenderText_Blended_Wrapped(fFont0, finalText, fColor3, 720);
        textTex = SDL_CreateTextureFromSurface(renderer, textSur3);
        SDL_Rect textRect3 = {75, 275+(textSur3->h+20)*i, textSur3->w, textSur3->h};

        SDL_RenderCopy(renderer, textTex, NULL, &textRect3);

        SDL_FreeSurface(textSur3);
        SDL_DestroyTexture(textTex);
    }

    TTF_CloseFont(fFont0);
}

void PersonalInfo_DrawScene(SDL_Renderer *renderer, struct eventTrigger *eventData){
    SDL_SetRenderDrawColor(renderer, 199, 231, 240, 200); //217,241,255
    SDL_RenderClear(renderer);

    if(eventData->mouseX >= PersonalInfo_imgRect7.x && eventData->mouseX <= PersonalInfo_imgRect7.x + PersonalInfo_imgRect7.w && 
        eventData->mouseY >= PersonalInfo_imgRect7.y && eventData->mouseY<=PersonalInfo_imgRect7.y + PersonalInfo_imgRect7.h && eventData->isTrigger == 1){
        currentRoom = 1;
    }

    SDL_RenderCopy(renderer, PersonalInfo_imgTexture1, NULL, &PersonalInfo_imgRect1);
    SDL_RenderCopy(renderer, PersonalInfo_imgTexture2, NULL, &PersonalInfo_imgRect2);
    SDL_RenderCopy(renderer, PersonalInfo_imgTexture3, NULL, &PersonalInfo_imgRect3);
    SDL_RenderCopy(renderer, PersonalInfo_imgTexture4, NULL, &PersonalInfo_imgRect4);
    SDL_RenderCopy(renderer, PersonalInfo_imgTexture5, NULL, &PersonalInfo_imgRect5);
    SDL_RenderCopy(renderer, PersonalInfo_imgTexture6, NULL, &PersonalInfo_imgRect6);
    SDL_RenderCopy(renderer, PersonalInfo_imgTexture7, NULL, &PersonalInfo_imgRect7);

    SDL_RenderCopy(renderer, PersonalInfo_texTexture1, NULL, &PersonalInfo_texRect1);
    SDL_RenderCopy(renderer, PersonalInfo_texTexture2, NULL, &PersonalInfo_texRect2);
    SDL_RenderCopy(renderer, PersonalInfo_texTexture3, NULL, &PersonalInfo_texRect3);
    
    PersonalInfo_TextShowInformation(renderer, eventData);

    SDL_RenderPresent(renderer);
}