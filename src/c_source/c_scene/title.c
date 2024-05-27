#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <system/struct.h>
#include <system/nodeHandle.h>
#include <system/componentLoad.h>
#include <system/scene.h>

#define TITLE_IMG_AMOUNT 1
#define TITLE_TEXT_AMOUNT 5

// Declare Object Variable
objectComponent Title_imgObj[TITLE_IMG_AMOUNT];
objectComponent Title_textObj[TITLE_TEXT_AMOUNT];

SDL_Rect Title_rect1;

// Function when click start button
void StartButtonEvent(){
    currentRoom = 1; // Change to Result
}

void Title_Initial(SDL_Renderer *renderer){
    //Define border property
    Title_rect1.x = 50;
    Title_rect1.y = 80;
    Title_rect1.w = 650;
    Title_rect1.h = 165;

    //Define Image
    createIMGTexture_Rect(renderer, &Title_imgObj[0], "src/image/Title_StartSim.png", 70, 340, 590, -1);

    //Define Texts
    createTextTexture_Rect(renderer, &Title_textObj[0], "Multi-Level Marketing", "src/font/HoltwoodOneSC-Regular.ttf", 40, 180, 234, 230, 255, 70, 100);
    createTextTexture_Rect(renderer, &Title_textObj[1], "Simulation", "src/font/HoltwoodOneSC-Regular.ttf", 40, 180, 234, 230, 255, 225, 165);
    createTextTexture_Rect(renderer, &Title_textObj[2], "Using Amway Marketing", "src/font/Alegreya-VariableFont_wght.ttf", 20, 2, 54, 81, 255, 520, 710);
    createTextTexture_Rect(renderer, &Title_textObj[3], "Start", "src/font/HoltwoodOneSC-Regular.ttf", 45, 0, 0, 0, 255, 280, 380);
    createTextTexture_Rect(renderer, &Title_textObj[4], "Simulation", "src/font/HoltwoodOneSC-Regular.ttf", 45, 0, 0, 0, 255, 180, 450);
}

void Title_Run(SDL_Renderer *renderer, struct eventTrigger *eventData){
    // When clicking the start button
    if(isClickOnObject(eventData, &Title_imgObj[0]) == 2)
    {
        StartButtonEvent();
        initialNode(&rootOfMLM); // Build the tree by referring to Data.txt
    }

    // Scene Draw
    SDL_SetRenderDrawColor(renderer, 199, 231, 240, 200);
    SDL_RenderClear(renderer);
    placeObject(renderer, &Title_imgObj[0]);

    SDL_SetRenderDrawColor(renderer, 1, 19, 74 ,255);
    SDL_RenderFillRect(renderer, &Title_rect1);

    for(int i=0; i<TITLE_TEXT_AMOUNT; i++){
        placeObject(renderer, &Title_textObj[i]);
    }
    
    SDL_RenderPresent(renderer);
}