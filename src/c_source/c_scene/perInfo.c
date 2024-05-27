#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <system/scene.h>
#include <system/struct.h>
#include <system/componentLoad.h>

// Declare Images Variable
SDL_Rect PersonalInfo_imgRect1;
SDL_Texture *PersonalInfo_imgTexture1;
SDL_Rect PersonalInfo_imgRect2;
SDL_Texture *PersonalInfo_imgTexture2;
SDL_Rect PersonalInfo_imgRect3;
SDL_Texture *PersonalInfo_imgTexture3;
SDL_Rect PersonalInfo_imgRect4;
SDL_Texture *PersonalInfo_imgTexture4;
SDL_Rect PersonalInfo_imgRect7;
SDL_Texture *PersonalInfo_imgTexture7;

// Declare Texts Variable
SDL_Texture *PersonalInfo_texTexture1;
SDL_Rect PersonalInfo_texRect1;
SDL_Texture *PersonalInfo_texTexture2;
SDL_Rect PersonalInfo_texRect2;
SDL_Texture *PersonalInfo_texTexture3;
SDL_Rect PersonalInfo_texRect3;


void PersonalInfo_Initial(SDL_Renderer *renderer){
    // Define Images
    createIMGTexture_Rect(renderer, &PersonalInfo_imgTexture1, &PersonalInfo_imgRect1, "src/image/PerInfo_Background.png", 70, 30, 630, 120);
    createIMGTexture_Rect(renderer, &PersonalInfo_imgTexture2, &PersonalInfo_imgRect2, "src/image/PerInfo_Tree.png", 10, 160, 500, 510);
    createIMGTexture_Rect(renderer, &PersonalInfo_imgTexture3, &PersonalInfo_imgRect3, "src/image/PerInfo_Name.png", 515, 300, 220, -1);
    createIMGTexture_Rect(renderer, &PersonalInfo_imgTexture4, &PersonalInfo_imgRect4, "src/image/PerInfo_BV.png", 515, 490, 220, -1);
    createIMGTexture_Rect(renderer, &PersonalInfo_imgTexture7, &PersonalInfo_imgRect7, "src/image/Back.png", 25, 690, 60, -1);

    // Define Texts
    createTextTexture_Rect(renderer, &PersonalInfo_texTexture1, &PersonalInfo_texRect1, "Personal Info", "src/font/HoltwoodOneSC-Regular.ttf", 55, 0, 0, 0, 255, 125, 43);
    createTextTexture_Rect(renderer, &PersonalInfo_texTexture2, &PersonalInfo_texRect2, "Name", "src/font/HoltwoodOneSC-Regular.ttf", 30, 0, 0, 0, 255, 530, 245);
    createTextTexture_Rect(renderer, &PersonalInfo_texTexture3, &PersonalInfo_texRect3, "BV", "src/font/HoltwoodOneSC-Regular.ttf", 30, 0, 0, 0, 255, 530, 435);
}

void PersonalInfo_TextShowInformation(SDL_Renderer *renderer, struct eventTrigger *eventData){
    SDL_Texture *textTexture;
    SDL_Rect textRect;
    // Show name
    createTextTexture_Rect(renderer, &textTexture, &textRect, (const char* ) sendingNode->name, "src/font/Alegreya-VariableFont_wght.ttf", 25, 0, 0, 0, 255, 595, 320);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    // Show BV
    char String[10];
    sprintf(String, "%d", sendingNode->BV);
    createTextTexture_Rect(renderer, &textTexture, &textRect, (const char* ) String, "src/font/Alegreya-VariableFont_wght.ttf", 25, 0, 0, 0, 255, 595, 500);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

    // Show each item selling information
    for(int i=0; i < 5; i++){
        char finalText[100];
        sprintf(finalText, "%s -> %d x %d (%d)", product[i]->name, sendingNode->produce[2*i+1], sendingNode->produce[2*i], product[i]->price);
        
        createTextTexture_Rect(renderer, &textTexture, &textRect, (const char* ) finalText, "src/font/Alegreya-VariableFont_wght.ttf", 25, 0, 0, 0, 255, 75, 275+50*i);
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    }

    SDL_DestroyTexture(textTexture);
}

void PersonalInfo_DrawScene(SDL_Renderer *renderer, struct eventTrigger *eventData){
    SDL_SetRenderDrawColor(renderer, 199, 231, 240, 200);
    SDL_RenderClear(renderer);

    // Move back to "Result" Page when click "Back" Button
    if(isClickOnObject(eventData, PersonalInfo_imgRect7) == 2){
        currentRoom = 1;
    }

    // Draw Scene
    SDL_RenderCopy(renderer, PersonalInfo_imgTexture1, NULL, &PersonalInfo_imgRect1);
    SDL_RenderCopy(renderer, PersonalInfo_imgTexture2, NULL, &PersonalInfo_imgRect2);
    SDL_RenderCopy(renderer, PersonalInfo_imgTexture3, NULL, &PersonalInfo_imgRect3);
    SDL_RenderCopy(renderer, PersonalInfo_imgTexture4, NULL, &PersonalInfo_imgRect4);
    SDL_RenderCopy(renderer, PersonalInfo_imgTexture7, NULL, &PersonalInfo_imgRect7);

    SDL_RenderCopy(renderer, PersonalInfo_texTexture1, NULL, &PersonalInfo_texRect1);
    SDL_RenderCopy(renderer, PersonalInfo_texTexture2, NULL, &PersonalInfo_texRect2);
    SDL_RenderCopy(renderer, PersonalInfo_texTexture3, NULL, &PersonalInfo_texRect3);
    
    PersonalInfo_TextShowInformation(renderer, eventData);

    SDL_RenderPresent(renderer);
}