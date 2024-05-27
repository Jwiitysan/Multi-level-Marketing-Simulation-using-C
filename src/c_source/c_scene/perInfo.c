#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <system/scene.h>
#include <system/struct.h>
#include <system/componentLoad.h>

#define PERINFO_IMG_AMOUNT 5
#define PERINFO_TEXT_AMOUNT 3

// Declare Variable
objectComponent PersonalInfo_imgObj[PERINFO_IMG_AMOUNT];
objectComponent PersonalInfo_textObj[PERINFO_TEXT_AMOUNT];

void PersonalInfo_Initial(SDL_Renderer *renderer){
    // Define Images
    createIMGTexture_Rect(renderer, &PersonalInfo_imgObj[0], "src/image/PerInfo_Background.png", 70, 30, 630, 120);
    createIMGTexture_Rect(renderer, &PersonalInfo_imgObj[1], "src/image/PerInfo_Tree.png", 10, 160, 500, 510);
    createIMGTexture_Rect(renderer, &PersonalInfo_imgObj[2], "src/image/PerInfo_Name.png", 515, 300, 220, -1);
    createIMGTexture_Rect(renderer, &PersonalInfo_imgObj[3], "src/image/PerInfo_BV.png", 515, 490, 220, -1);
    createIMGTexture_Rect(renderer, &PersonalInfo_imgObj[4], "src/image/Back.png", 25, 690, 60, -1);

    // Define Texts
    createTextTexture_Rect(renderer, &PersonalInfo_textObj[0], "Personal Info", "src/font/HoltwoodOneSC-Regular.ttf", 55, 0, 0, 0, 255, 125, 43);
    createTextTexture_Rect(renderer, &PersonalInfo_textObj[1], "Name", "src/font/HoltwoodOneSC-Regular.ttf", 30, 0, 0, 0, 255, 530, 245);
    createTextTexture_Rect(renderer, &PersonalInfo_textObj[2], "BV", "src/font/HoltwoodOneSC-Regular.ttf", 30, 0, 0, 0, 255, 530, 435);
}

void PersonalInfo_TextShowInformation(SDL_Renderer *renderer, struct eventTrigger *eventData){
    objectComponent text;
    // Show name
    createTextTexture_Rect(renderer, &text, (const char* ) sendingNode->name, "src/font/Alegreya-VariableFont_wght.ttf", 25, 0, 0, 0, 255, 595, 320);
    placeObject(renderer, &text);
    // Show BV
    char String[10];
    sprintf(String, "%d", sendingNode->BV);
    createTextTexture_Rect(renderer, &text, (const char* ) String, "src/font/Alegreya-VariableFont_wght.ttf", 25, 0, 0, 0, 255, 595, 500);
    placeObject(renderer, &text);

    // Show each item selling information
    for(int i=0; i < 5; i++){
        char finalText[100];
        sprintf(finalText, "%s -> %d x %d (BV: %d)", product[i]->name, sendingNode->produce[2*i+1], sendingNode->produce[2*i], product[i]->price);
        
        createTextTexture_Rect(renderer, &text, (const char* ) finalText, "src/font/Alegreya-VariableFont_wght.ttf", 25, 0, 0, 0, 255, 75, 275+50*i);
        placeObject(renderer, &text);
    }

    SDL_DestroyTexture(text.objectTexture); // Free Texture (Avoid Memory Leak)
}

void PersonalInfo_Run(SDL_Renderer *renderer, struct eventTrigger *eventData){
    SDL_SetRenderDrawColor(renderer, 199, 231, 240, 200);
    SDL_RenderClear(renderer);

    // Move back to "Result" Page when click "Back" Button
    if(isClickOnObject(eventData, &PersonalInfo_imgObj[4]) == 2){
        currentRoom = 1;
    }

    // Draw Scene
    for(int i=0; i<PERINFO_IMG_AMOUNT; i++){
        placeObject(renderer, &PersonalInfo_imgObj[i]);
    }
    for(int i=0; i<PERINFO_TEXT_AMOUNT; i++){
        placeObject(renderer, &PersonalInfo_textObj[i]);
    } 

    PersonalInfo_TextShowInformation(renderer, eventData);

    SDL_RenderPresent(renderer);
}