#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <system/scene.h>
#include <system/struct.h>
#include <system/nodeHandle.h>
#include <system/componentLoad.h>

#define RESULT_IMG_AMOUNT 10
#define RESULT_TEXT_AMOUNT 13

// Declare Variables
objectComponent Result_imgObj[RESULT_IMG_AMOUNT];
objectComponent Result_textObj[RESULT_TEXT_AMOUNT];

void Result_Initial(SDL_Renderer *renderer){
    currentSelect = rootOfMLM;
    currentRoot = rootOfMLM;
    
    // Define Image
    createIMGTexture_Rect(renderer, &nodeObj[0], "src/image/NodeActive1.png", 170, 180, 80, -1);
    createIMGTexture_Rect(renderer, &nodeObj[1], "src/image/NodeActive2.png", 170, 180, 80, -1);
    createIMGTexture_Rect(renderer, &Result_imgObj[0], "src/image/Result_Background.png", 30, 30, 300, -1);
    createIMGTexture_Rect(renderer, &Result_imgObj[1], "src/image/Result_search.png", 400, 30, 330, -1);
    createIMGTexture_Rect(renderer, &Result_imgObj[2], "src/image/Result_BackgroundAllOption.png", 480, 180, 250, -1);
    createIMGTexture_Rect(renderer, &Result_imgObj[3], "src/image/Result_ButtonOption.png", 500, 235, 210, -1);
    createIMGTexture_Rect(renderer, &Result_imgObj[4], "src/image/Result_ButtonOption.png", 500, 315, 210, -1);
    createIMGTexture_Rect(renderer, &Result_imgObj[5], "src/image/Result_ButtonOption.png", 500, 395, 210, -1);
    createIMGTexture_Rect(renderer, &Result_imgObj[6], "src/image/Result_ButtonOption.png", 500, 475, 210, -1);
    createIMGTexture_Rect(renderer, &Result_imgObj[7], "src/image/Result_Restart.png", 660, 670, 60, -1);
    createIMGTexture_Rect(renderer, &Result_imgObj[8], "src/image/Result_Cal.png", 25, 640, 100, -1);

    // Define Texts
    createTextTexture_Rect(renderer, &Result_textObj[0], "Result", "src/font/HoltwoodOneSC-Regular.ttf", 45, 0, 0, 0, 255, 120, 43);
    createTextTexture_Rect(renderer, &Result_textObj[1], "All Options", "src/font/HoltwoodOneSC-Regular.ttf", 20, 0, 0, 0, 255, 525, 195);
    createTextTexture_Rect(renderer, &Result_textObj[2], "Show", "src/font/HoltwoodOneSC-Regular.ttf", 14, 0, 0, 0, 255, 590, 245);
    createTextTexture_Rect(renderer, &Result_textObj[3], "Information", "src/font/HoltwoodOneSC-Regular.ttf", 14, 0, 0, 0, 255, 560, 270);
    createTextTexture_Rect(renderer, &Result_textObj[4], "Edit", "src/font/HoltwoodOneSC-Regular.ttf", 14, 0, 0, 0, 255, 595, 325);
    createTextTexture_Rect(renderer, &Result_textObj[5], "Selling", "src/font/HoltwoodOneSC-Regular.ttf", 14, 0, 0, 0, 255, 580, 350);
    createTextTexture_Rect(renderer, &Result_textObj[6], "Delete", "src/font/HoltwoodOneSC-Regular.ttf", 14, 0, 0, 0, 255, 585, 405);
    createTextTexture_Rect(renderer, &Result_textObj[7], "This Person", "src/font/HoltwoodOneSC-Regular.ttf", 14, 0, 0, 0, 255, 565, 428);
    createTextTexture_Rect(renderer, &Result_textObj[8], "Add", "src/font/HoltwoodOneSC-Regular.ttf", 14, 0, 0, 0, 255, 598, 485);
    createTextTexture_Rect(renderer, &Result_textObj[9], "Downline", "src/font/HoltwoodOneSC-Regular.ttf", 14, 0, 0, 0, 255, 572, 510);
    createTextTexture_Rect(renderer, &Result_textObj[10], "Calculate", "src/font/HoltwoodOneSC-Regular.ttf", 10, 0, 0, 0, 255, 49, 675);
    createTextTexture_Rect(renderer, &Result_textObj[11], "PV and", "src/font/HoltwoodOneSC-Regular.ttf", 10, 0, 0, 0, 255, 58, 690);
    createTextTexture_Rect(renderer, &Result_textObj[12], "Salary", "src/font/HoltwoodOneSC-Regular.ttf", 10, 0, 0, 0, 255, 59, 705);
}

void optionHandle(SDL_Renderer *renderer, struct eventTrigger *eventData){
    // Draw Options on the right of screen
    for(int i=2; i<7; i++){
        placeObject(renderer, &Result_imgObj[i]);
    }
    for(int i=1; i<10; i++){
        placeObject(renderer, &Result_textObj[i]);
    }

    // when click on "Delete This Person" button
    if(isClickOnObject(eventData, &Result_imgObj[5]) == 2){
        if(currentSelect->name != rootOfMLM->name)
        {
            // when delete root (of subtree) it will set the currentRoot to parent immediately
            if(currentSelect->name == currentRoot->name){
                previousRoot = NULL;
                NodePtr currentRootCpy = currentRoot;
                NodePtr prevRoot = searchprevNode(rootOfMLM, currentRootCpy->name);
                while(prevRoot->nextSi == currentRootCpy){
                    currentRootCpy = prevRoot;
                    prevRoot = searchprevNode(rootOfMLM, currentRootCpy->name); 
                }
                rootOfMLM = delNode(currentSelect->name, rootOfMLM);
                currentSelect = currentRoot = prevRoot;
            }else{
                rootOfMLM = delNode(currentSelect->name, rootOfMLM);
            }
            
            writeFile(rootOfMLM);
        }
    }
    // when click on "Edit Selling" button
    else if(isClickOnObject(eventData, &Result_imgObj[4]) == 2){
        currentRoom = 5;
        sendingNode = currentSelect != NULL ? currentSelect : currentRoot; // Send the current node data to "Edit Selling" page
        currentSelect = currentRoot;
    }
    // when click on "Add Downline" button
    else if(isClickOnObject(eventData, &Result_imgObj[6]) == 2){
        currentRoom = 6;
        sendingNode = currentSelect != NULL ? currentSelect : currentRoot; // Send the current node data to "Add Downline" page
        currentSelect = currentRoot;
    }
    // when click on "Reset" button
    else if(isClickOnObject(eventData, &Result_imgObj[7]) == 2){
        if(rootOfMLM->child != NULL){
            currentRoot = rootOfMLM;
            previousRoot = NULL;
            currentSelect = rootOfMLM;
            rootOfMLM = freeTree(rootOfMLM, rootOfMLM);
            rootOfMLM->child = NULL;
        }else{
            generateTree(rootOfMLM);
        }
        writeFile(rootOfMLM);
    }
    // when click on "Show Information" button
    else if(isClickOnObject(eventData, &Result_imgObj[3]) == 2){
        currentRoom = 2;
        sendingNode = currentSelect != NULL ? currentSelect : currentRoot;
        currentSelect = NULL;
    }
    // when click on "Calculate PV and Salary" button
    else if(isClickOnObject(eventData, &Result_imgObj[8]) == 2){
        currentRoom = 4;
        previousRoot = NULL;
        currentSelect = rootOfMLM;
        currentRoot = rootOfMLM;     
    }
}

void Result_Run(SDL_Renderer *renderer, struct eventTrigger* eventData){
    // Draw Scene
    SDL_SetRenderDrawColor(renderer, 199, 231, 240, 200);
    SDL_RenderClear(renderer);

    int imgPlaceID[] = {0, 1, 7, 8};
    int textPlaceID[] = {0, 10, 11, 12};

    for(int i=0; i<4; i++){
        placeObject(renderer, &Result_imgObj[imgPlaceID[i]]);
    }
    for(int i=0; i<4; i++){
        placeObject(renderer, &Result_textObj[textPlaceID[i]]);
    }

    // Event Function (Draw Node, Search bar, Options)
    DrawNode(renderer, eventData);
    SearchBar(renderer, eventData);
    optionHandle(renderer, eventData);

    SDL_RenderPresent(renderer);
}