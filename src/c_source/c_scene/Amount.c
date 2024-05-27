#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <system/scene.h>
#include <system/struct.h>
#include <system/edit.h>
#include <system/componentLoad.h>

#define AMOUNT_IMG_AMOUNT 11
#define AMOUNT_TEXT_AMOUNT 4

// Declare Variables
objectComponent Amount_imgObj[AMOUNT_IMG_AMOUNT];
objectComponent Amount_textObj[AMOUNT_TEXT_AMOUNT];

void Amount_Initial(SDL_Renderer *renderer){

    // Define Images
    createIMGTexture_Rect(renderer, &Amount_imgObj[0], "src/image/Amount_Background.png", 110, 25, 530, 90);
    createIMGTexture_Rect(renderer, &Amount_imgObj[1], "src/image/selling_Tree.png", 10, 150, 500, 510);
    createIMGTexture_Rect(renderer, &Amount_imgObj[2], "src/image/Amount_Amount.png", 515, 250, 220, -1);
    createIMGTexture_Rect(renderer, &Amount_imgObj[3], "src/image/selling_PriceFix2.png", 515, 420, 220, -1);
    createIMGTexture_Rect(renderer, &Amount_imgObj[4], "src/image/selling_OK.png", 580, 550, 90, -1);
    createIMGTexture_Rect(renderer, &Amount_imgObj[5], "src/image/Back.png", 25, 680, 60, -1);

    createIMGTexture_Rect(renderer, &Amount_imgObj[6], "src/image/eSpring.png", 65, 260, 80, -1);
    createIMGTexture_Rect(renderer, &Amount_imgObj[7], "src/image/Water_filter.png", 225, 260, 80, -1);
    createIMGTexture_Rect(renderer, &Amount_imgObj[8], "src/image/Atmosphere.png", 385, 260, 80, -1);
    createIMGTexture_Rect(renderer, &Amount_imgObj[9], "src/image/Air_filter.png", 110, 460, 110, -1);
    createIMGTexture_Rect(renderer, &Amount_imgObj[10], "src/image/Smart_watch.png", 290, 460, 110, -1);

    // Define Texts
    createTextTexture_Rect(renderer, &Amount_textObj[0], "Selling amount", "src/font/HoltwoodOneSC-Regular.ttf", 45, 0, 0, 0, 255, 140, 30);
    createTextTexture_Rect(renderer, &Amount_textObj[1], "Amount", "src/font/HoltwoodOneSC-Regular.ttf", 30, 0, 0, 0, 255, 530, 195);
    createTextTexture_Rect(renderer, &Amount_textObj[2], "Fix", "src/font/HoltwoodOneSC-Regular.ttf", 30, 0, 0, 0, 255, 530, 365);
    createTextTexture_Rect(renderer, &Amount_textObj[3], "OK", "src/font/HoltwoodOneSC-Regular.ttf", 30, 2, 54, 81, 255, 595, 570);
}

// The function about Selecting Item to change the amount of selling
char Amount_productName[20];
char Amount_Input[10];
int Amount_currentHover = 0;
int AmountSelected = 0;

void SelectingItem(SDL_Renderer *renderer, struct eventTrigger *eventData){
    char numAmount[20];
    // Check if hover/click on item 1 (eSpring)
    if(isClickOnObject(eventData, &Amount_imgObj[6]) > 0){
        Amount_currentHover = 0;
        if(eventData->isTrigger == 1){ // Check if select item
            AmountSelected = 0;
            itoa(sendingNode->produce[AmountSelected*2+1], numAmount, 10);
            strcpy(Amount_Input, numAmount);
        }
    }
    // Check if hover/click on item 2 (Water filter)
    else if(isClickOnObject(eventData, &Amount_imgObj[7]) > 0){
        Amount_currentHover = 1;
        if(eventData->isTrigger == 1){
            AmountSelected = 1;
            itoa(sendingNode->produce[AmountSelected*2+1], numAmount, 10);
            strcpy(Amount_Input, numAmount);
        }
    }
    // Check if hover/click on item 3 (Atmosphere)
    else if(isClickOnObject(eventData, &Amount_imgObj[8]) > 0){
        Amount_currentHover = 2;
        if(eventData->isTrigger == 1){
            AmountSelected = 2;
            itoa(sendingNode->produce[AmountSelected*2+1], numAmount, 10);
            strcpy(Amount_Input, numAmount);
        }
    }

    // Check if hover/click on item 4 (Air filter)
    else if(isClickOnObject(eventData, &Amount_imgObj[9]) > 0){
        Amount_currentHover = 3;
        if(eventData->isTrigger == 1){
            AmountSelected = 3;
            itoa(sendingNode->produce[AmountSelected*2+1], numAmount, 10);
            strcpy(Amount_Input, numAmount);
        }
    }

    // Check if hover/click on item 5 (Smart Watch)
    else if(isClickOnObject(eventData, &Amount_imgObj[10]) > 0){
        Amount_currentHover = 4;
        if(eventData->isTrigger == 1){
            AmountSelected = 4;
            itoa(sendingNode->produce[AmountSelected*2+1], numAmount, 10);
            strcpy(Amount_Input, numAmount);
        }
    
    // Check if click "OK" Button (Change the amount)
    }else if(isClickOnObject(eventData, &Amount_imgObj[4]) == 2){
        int newAddOn = (atoi(Amount_Input) - sendingNode->produce[2*AmountSelected+1]) * sendingNode->produce[2*AmountSelected];
        int newAddOnBV = (atoi(Amount_Input) - sendingNode->produce[2*AmountSelected+1]) * product[AmountSelected]->price;
        editSellAmount(sendingNode->name, atoi(Amount_Input), AmountSelected, rootOfMLM);
        sendingNode->retail += newAddOn;
        sendingNode->BV += newAddOnBV;
        sendingNode->PV = sendingNode->BV / 3.0f;
    }
}

// The function about User Input (From keyboard)
void Amount_UserInputPrice(SDL_Renderer *renderer, struct eventTrigger *eventData){
    // Check if user input in a number (add that number behind current input string)
    if(eventData->currentInput >= SDLK_0 && eventData->currentInput <= SDLK_9){
        char currentKey[2];
        currentKey[0] = eventData->currentInput - SDLK_0 + '0';
        currentKey[1] = '\0';
        if(strcmp(Amount_Input, "0") == 0)
            strcpy(Amount_Input, currentKey);
        else if(strlen(Amount_Input) != 4)
            strcat(Amount_Input, currentKey);
    // Check if user input backspace (delete the last char)
    }else if(eventData->currentInput == SDLK_BACKSPACE){
        if(strlen(Amount_Input) > 1)
            Amount_Input[strlen(Amount_Input)-1] = '\0';
        else
            strcpy(Amount_Input, "0");
    }
    if(strlen(Amount_Input) == 0) strcpy(Amount_Input, "0");

    // Write a string on input bar
    objectComponent text;
    createTextTexture_Rect(renderer, &text, (const char*) Amount_Input, "src/font/Alegreya-VariableFont_wght.ttf", 30, 255, 0, 0, 255, 600, 440);

    placeObject(renderer, &text);
    SDL_DestroyTexture(text.objectTexture); // Free Texture (Avoid Leak Memory)
}

// The function about showing the option to select
void Amount_dataOption(SDL_Renderer *renderer, struct eventTrigger *eventData){
    objectComponent text;

    // Show the node name
    TTF_Font *fFont1 = TTF_OpenFont("src/font/Alegreya-VariableFont_wght.ttf", 30);
    SDL_Color fColor1 = {0, 0, 0, 255};
    if(Amount_currentHover == AmountSelected){
        fColor1.r = 26;
        fColor1.g = 19;
        fColor1.b = 237;
    }

    createTextTexture_Rect(renderer, &text, (const char *) sendingNode->name, "src/font/Alegreya-VariableFont_wght.ttf", 30, fColor1.r, fColor1.g, fColor1.b, 255, 102, 134);
    placeObject(renderer, &text);
    SDL_DestroyTexture(text.objectTexture);

    // Show the seleting product
    createTextTexture_Rect(renderer, &text, (const char *) product[AmountSelected]->name, "src/font/Alegreya-VariableFont_wght.ttf", 30, 0, 0, 0, 255, 140, 200);
    placeObject(renderer, &text);
    SDL_DestroyTexture(text.objectTexture); 

    // Show the amount of seleting product
    char amountString[30];
    sprintf(amountString, "%d", sendingNode->produce[2*AmountSelected+1]);
    createTextTexture_Rect(renderer, &text, (const char *) amountString, "src/font/Alegreya-VariableFont_wght.ttf", 30, 0, 0, 0, 255, 600, 270);
    placeObject(renderer, &text);
    SDL_DestroyTexture(text.objectTexture); 

    // Show the actual selling price (not BV)
    sprintf(amountString, "%d", sendingNode->produce[2*AmountSelected]);
    strcat(amountString, " (Actual Selling Price)");
    createTextTexture_Rect(renderer, &text, (const char *) amountString, "src/font/Alegreya-VariableFont_wght.ttf", 18, 0, 0, 0, 255, 550, 320);
    placeObject(renderer, &text);
    SDL_DestroyTexture(text.objectTexture); 
}

void Amount_Run(SDL_Renderer *renderer, struct eventTrigger *eventData){
    SDL_SetRenderDrawColor(renderer, 199, 231, 240, 200);
    SDL_RenderClear(renderer);
    // Check if click "Back" Button (Return to "Result" Page)
    if(isClickOnObject(eventData, &Amount_imgObj[5]) == 2){
        currentRoom = 1;
    }

    // Draw Scene
    for(int i=0; i<AMOUNT_IMG_AMOUNT; i++){
        placeObject(renderer, &Amount_imgObj[i]);
    }
    for(int i=0; i<AMOUNT_TEXT_AMOUNT; i++){
        placeObject(renderer, &Amount_textObj[i]);
    }
    
    SelectingItem(renderer, eventData);
    Amount_dataOption(renderer, eventData);
    Amount_UserInputPrice(renderer, eventData);

    SDL_RenderPresent(renderer);
}