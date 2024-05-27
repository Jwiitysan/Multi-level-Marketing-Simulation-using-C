#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <system/scene.h>
#include <system/struct.h>
#include <system/nodeHandle.h>
#include <system/componentLoad.h>

#define SALARY_IMG_AMOUNT 7
#define SALARY_TXT_AMOUNT 6

// Declare Variables
objectComponent Salary_imgObj[SALARY_IMG_AMOUNT];
objectComponent Salary_textObj[SALARY_TXT_AMOUNT];


void Salary_Initial(SDL_Renderer *renderer){
    // Define Images
    createIMGTexture_Rect(renderer, &Salary_imgObj[0], "src/image/Salary_Background.png", 30, 30, 300, -1);
    createIMGTexture_Rect(renderer, &Salary_imgObj[1], "src/image/Search.png", 400, 30, 330, -1);
    createIMGTexture_Rect(renderer, &Salary_imgObj[2], "src/image/Back.png", 25, 690, 60, -1);

    // Define Texts
    createTextTexture_Rect(renderer, &Salary_textObj[0], "Salary", "src/font/HoltwoodOneSC-Regular.ttf", 40, 0, 0, 0, 255, 120, 45);
    createTextTexture_Rect(renderer, &Salary_textObj[1], "INFO", "src/font/HoltwoodOneSC-Regular.ttf", 40, 0, 0, 0, 255, 510, 150);
    createTextTexture_Rect(renderer, &Salary_textObj[2], "Retail Profit", "src/font/HoltwoodOneSC-Regular.ttf", 20, 0, 0, 0, 255, 450, 270);
    createTextTexture_Rect(renderer, &Salary_textObj[3], "BV", "src/font/HoltwoodOneSC-Regular.ttf", 20, 0, 0, 0, 255, 450, 370);
    createTextTexture_Rect(renderer, &Salary_textObj[4], "PV", "src/font/HoltwoodOneSC-Regular.ttf", 20, 0, 0, 0, 255, 450, 400);
    createTextTexture_Rect(renderer, &Salary_textObj[5], "Salary", "src/font/HoltwoodOneSC-Regular.ttf", 20, 0, 0, 0, 255, 450, 430);
}

// The function used to show the retail profit, PV, BV, and Final income (Salary)
void Salary_ShowTextResult(SDL_Renderer *renderer, struct eventTrigger *eventData){
    objectComponent textResult;

    // Avoid the error from currentSelect is NULL
    if(currentSelect == NULL){
        if(currentRoot == NULL)
            currentSelect = rootOfMLM;
        else currentSelect = currentRoot;
    }

    // Show node name
    createTextTexture_Rect(renderer, &textResult, (const char*) currentSelect->name, "src/font/Alegreya-VariableFont_wght.ttf", 30, 0, 0, 0, 255, 460, 215);
    placeObject(renderer, &textResult);
    SDL_DestroyTexture(textResult.objectTexture);

    // Show node retail profit
    char str[20];
    sprintf(str, "%d", currentSelect->retail);
    createTextTexture_Rect(renderer, &textResult, (const char*) str, "src/font/Alegreya-VariableFont_wght.ttf", 30, 0, 0, 0, 255, 510, 300);
    placeObject(renderer, &textResult);
    SDL_DestroyTexture(textResult.objectTexture);

    // Show node BV (self BV)
    sprintf(str, "%d", currentSelect->BV);
    createTextTexture_Rect(renderer, &textResult, (const char*) str, "src/font/Alegreya-VariableFont_wght.ttf", 30, 0, 0, 0, 255, 510, 362);
    placeObject(renderer, &textResult);
    SDL_DestroyTexture(textResult.objectTexture);

    // Show node PV (Include the downline PV)
    sprintf(str, "%d", calPV(currentSelect));
    createTextTexture_Rect(renderer, &textResult, (const char*) str, "src/font/Alegreya-VariableFont_wght.ttf", 30, 0, 0, 0, 255, 510, 392);
    placeObject(renderer, &textResult);
    SDL_DestroyTexture(textResult.objectTexture);

    // Show node final income (Salary)
    sprintf(str, "%.2f", Allincome(currentSelect->name, rootOfMLM));
    createTextTexture_Rect(renderer, &textResult, (const char*) str, "src/font/Alegreya-VariableFont_wght.ttf", 30, 0, 0, 0, 255, 510, 462);
    placeObject(renderer, &textResult);
    SDL_DestroyTexture(textResult.objectTexture);
}

// Draw Scene
void Salary_Run(SDL_Renderer *renderer, struct eventTrigger* eventData){
    SDL_SetRenderDrawColor(renderer, 199, 231, 240, 200);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 112, 255, 200, 255);
    SDL_Rect Salary_backgroundResult = {416, 137, 700-416, 530-137};
    SDL_RenderFillRect(renderer, &Salary_backgroundResult);

    if(isClickOnObject(eventData, &Salary_imgObj[2]) == 2){
        currentRoom = 1;
        previousRoot = NULL;
        currentSelect = rootOfMLM;
        currentRoot = rootOfMLM;   
    }

    for(int i=0; i<SALARY_IMG_AMOUNT; i++){
        placeObject(renderer, &Salary_imgObj[i]);
    }
    for(int i=0; i<SALARY_TXT_AMOUNT; i++){
        placeObject(renderer, &Salary_textObj[i]);
    }
    
    Salary_ShowTextResult(renderer, eventData);

    // Event Function (Draw Node, Search bar, Options)
    DrawNode(renderer, eventData);
    SearchBar(renderer, eventData);

    SDL_RenderPresent(renderer);
}