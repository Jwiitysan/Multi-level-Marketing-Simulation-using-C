#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <system/scene.h>
#include <system/struct.h>
#include <system/nodeHandle.h>
#include <system/componentLoad.h>

char searchText[10] = "NULL";

// Declare Image Variables

SDL_Rect Result_nodeRect;
SDL_Texture *Result_nodeTexture, *Result_nodeTexture2;

SDL_Rect Result_imgRect1;
SDL_Texture *Result_imgTexture1;
SDL_Rect Result_imgRect2;
SDL_Texture *Result_imgTexture2;
SDL_Rect Result_imgRect3;
SDL_Texture *Result_imgTexture3;
SDL_Rect Result_imgRect4;
SDL_Texture *Result_imgTexture4;
SDL_Rect Result_imgRect5;
SDL_Texture *Result_imgTexture5;
SDL_Rect Result_imgRect6;
SDL_Texture *Result_imgTexture6;
SDL_Rect Result_imgRect7;
SDL_Texture *Result_imgTexture7;
SDL_Rect Result_imgRect8;
SDL_Texture *Result_imgTexture8;
SDL_Rect Result_imgRect9;
SDL_Texture *Result_imgTexture9;
SDL_Rect Result_imgRect10;
SDL_Texture *Result_imgTexture10;

// Declare Text Variables
SDL_Texture *Result_texTexture1;
SDL_Rect Result_texRect1;
SDL_Texture *Result_texTexture2;
SDL_Rect Result_texRect2;
SDL_Texture *Result_texTexture3;
SDL_Rect Result_texRect3;
SDL_Texture *Result_texTexture4;
SDL_Rect Result_texRect4;
SDL_Texture *Result_texTexture5;
SDL_Rect Result_texRect5;
SDL_Texture *Result_texTexture6;
SDL_Rect Result_texRect6;
SDL_Texture *Result_texTexture7;
SDL_Rect Result_texRect7;
SDL_Texture *Result_texTexture8;
SDL_Rect Result_texRect8;
SDL_Texture *Result_texTexture9;
SDL_Rect Result_texRect9;
SDL_Texture *Result_texTexture10;
SDL_Rect Result_texRect10;
SDL_Texture *Result_texTexture11;
SDL_Rect Result_texRect11;
SDL_Texture *Result_texTexture12;
SDL_Rect Result_texRect12;
SDL_Texture *Result_texTexture13;
SDL_Rect Result_texRect13;

void Result_Initial(SDL_Renderer *renderer){
    //Define Image
    createIMGTexture_Rect(renderer, &Result_nodeTexture, &Result_nodeRect, "src/image/NodeActive1.png", 170, 180, 80);
    createIMGTexture_Rect(renderer, &Result_nodeTexture2, &Result_nodeRect, "src/image/NodeActive1.png", 170, 180, 80);
    createIMGTexture_Rect(renderer, &Result_imgTexture1, &Result_imgRect1, "src/image/Result_Background.png", 30, 30, 300);
    createIMGTexture_Rect(renderer, &Result_imgTexture2, &Result_imgRect2, "src/image/Result_search.png", 400, 30, 330);
    createIMGTexture_Rect(renderer, &Result_imgTexture3, &Result_imgRect3, "src/image/Result_BackgroundAllOption.png", 480, 180, 250);
    createIMGTexture_Rect(renderer, &Result_imgTexture4, &Result_imgRect4, "src/image/Result_ButtonOption.png", 500, 235, 210);
    createIMGTexture_Rect(renderer, &Result_imgTexture5, &Result_imgRect5, "src/image/Result_ButtonOption.png", 500, 315, 210);
    createIMGTexture_Rect(renderer, &Result_imgTexture6, &Result_imgRect6, "src/image/Result_ButtonOption.png", 500, 395, 210);
    createIMGTexture_Rect(renderer, &Result_imgTexture7, &Result_imgRect7, "src/image/Result_ButtonOption.png", 500, 475, 210);
    createIMGTexture_Rect(renderer, &Result_imgTexture8, &Result_imgRect8, "src/image/Result_Restart.png", 660, 670, 60);
    createIMGTexture_Rect(renderer, &Result_imgTexture9, &Result_imgRect9, "src/image/Result_Cal.png", 25, 640, 100);

    //Define Texts
    createTextTexture_Rect(renderer, &Result_texTexture1, &Result_texRect1, "Result", "src/font/HoltwoodOneSC-Regular.ttf", 45, 0, 0, 0, 255, 120, 43);
    createTextTexture_Rect(renderer, &Result_texTexture2, &Result_texRect2, "All Options", "src/font/HoltwoodOneSC-Regular.ttf", 20, 0, 0, 0, 255, 525, 195);
    createTextTexture_Rect(renderer, &Result_texTexture3, &Result_texRect3, "Show", "src/font/HoltwoodOneSC-Regular.ttf", 14, 0, 0, 0, 255, 590, 245);
    createTextTexture_Rect(renderer, &Result_texTexture4, &Result_texRect4, "Information", "src/font/HoltwoodOneSC-Regular.ttf", 14, 0, 0, 0, 255, 560, 270);
    createTextTexture_Rect(renderer, &Result_texTexture5, &Result_texRect5, "Edit", "src/font/HoltwoodOneSC-Regular.ttf", 14, 0, 0, 0, 255, 595, 325);
    createTextTexture_Rect(renderer, &Result_texTexture6, &Result_texRect6, "Selling", "src/font/HoltwoodOneSC-Regular.ttf", 14, 0, 0, 0, 255, 580, 350);
    createTextTexture_Rect(renderer, &Result_texTexture7, &Result_texRect7, "Delete", "src/font/HoltwoodOneSC-Regular.ttf", 14, 0, 0, 0, 255, 585, 405);
    createTextTexture_Rect(renderer, &Result_texTexture8, &Result_texRect8, "This Person", "src/font/HoltwoodOneSC-Regular.ttf", 14, 0, 0, 0, 255, 565, 428);
    createTextTexture_Rect(renderer, &Result_texTexture9, &Result_texRect9, "Add", "src/font/HoltwoodOneSC-Regular.ttf", 14, 0, 0, 0, 255, 598, 485);
    createTextTexture_Rect(renderer, &Result_texTexture10, &Result_texRect10, "Downline", "src/font/HoltwoodOneSC-Regular.ttf", 14, 0, 0, 0, 255, 572, 510);
    createTextTexture_Rect(renderer, &Result_texTexture11, &Result_texRect11, "Calculate", "src/font/HoltwoodOneSC-Regular.ttf", 10, 0, 0, 0, 255, 49, 675);
    createTextTexture_Rect(renderer, &Result_texTexture12, &Result_texRect12, "PV and", "src/font/HoltwoodOneSC-Regular.ttf", 10, 0, 0, 0, 255, 58, 690);
    createTextTexture_Rect(renderer, &Result_texTexture13, &Result_texRect13, "Salary", "src/font/HoltwoodOneSC-Regular.ttf", 10, 0, 0, 0, 255, 59, 705);
}

NodePtr Result_previousRoot = NULL;
NodePtr Result_currentSelect = NULL;
NodePtr Result_currentRoot = NULL;

int searchBarUsing = 0;
char currentShift = 'a';

void optionHandle(SDL_Renderer *renderer, struct eventTrigger *eventData){
    SDL_RenderCopy(renderer, Result_imgTexture3, NULL, &Result_imgRect3);
    SDL_RenderCopy(renderer, Result_imgTexture4, NULL, &Result_imgRect4);
    SDL_RenderCopy(renderer, Result_imgTexture5, NULL, &Result_imgRect5);
    SDL_RenderCopy(renderer, Result_imgTexture6, NULL, &Result_imgRect6);
    SDL_RenderCopy(renderer, Result_imgTexture7, NULL, &Result_imgRect7);
    SDL_RenderCopy(renderer, Result_texTexture2, NULL, &Result_texRect2);
    SDL_RenderCopy(renderer, Result_texTexture3, NULL, &Result_texRect3);
    SDL_RenderCopy(renderer, Result_texTexture4, NULL, &Result_texRect4);
    SDL_RenderCopy(renderer, Result_texTexture5, NULL, &Result_texRect5);
    SDL_RenderCopy(renderer, Result_texTexture6, NULL, &Result_texRect6);
    SDL_RenderCopy(renderer, Result_texTexture7, NULL, &Result_texRect7);
    SDL_RenderCopy(renderer, Result_texTexture8, NULL, &Result_texRect8);
    SDL_RenderCopy(renderer, Result_texTexture9, NULL, &Result_texRect9);
    SDL_RenderCopy(renderer, Result_texTexture10, NULL, &Result_texRect10);

    if(isClickOnObject(eventData, Result_imgRect6) == 2){
        rootOfMLM = delNode(Result_currentSelect->name, rootOfMLM);
        writeFile(rootOfMLM);
    }
    else if(isClickOnObject(eventData, Result_imgRect5) == 2){
        currentRoom = 5;
        sendingNode = Result_currentSelect != NULL ? Result_currentSelect : Result_currentRoot;
        Result_currentSelect = NULL;
    }
    else if(isClickOnObject(eventData, Result_imgRect7) == 2){
        currentRoom = 6;
        sendingNode = Result_currentSelect != NULL ? Result_currentSelect : Result_currentRoot;
        Result_currentSelect = NULL;
    }
    else if(isClickOnObject(eventData, Result_imgRect8) == 2){
        if(rootOfMLM->child != NULL){
            Result_currentRoot = rootOfMLM;
            Result_previousRoot = NULL;
            Result_currentSelect = rootOfMLM;
            rootOfMLM = freeTree(rootOfMLM, rootOfMLM);
            rootOfMLM->child = NULL;
        }else{
            generateTree(rootOfMLM);
        }
        writeFile(rootOfMLM);
    }
    else if(isClickOnObject(eventData, Result_imgRect4) == 2){
        currentRoom = 2;
        sendingNode = Result_currentSelect != NULL ? Result_currentSelect : Result_currentRoot;
        Result_currentSelect = NULL;
    }
    else if(isClickOnObject(eventData, Result_imgRect9) == 2){
        currentRoom = 4;
    }
}

void Result_SearchBar(SDL_Renderer *renderer, struct eventTrigger* eventData){
    TTF_Font *fFont0 = TTF_OpenFont("src/font/Alegreya-VariableFont_wght.ttf", 30);
    SDL_Color fColor1 = {0, 0, 0, 255};
    if(eventData->isTrigger == 1){
        if(eventData->mouseX >= 418 && eventData->mouseX <= 638 && eventData->mouseY >= 41 && eventData->mouseY<=73){
            searchBarUsing = 1;
        }
        else{
            searchBarUsing = 0;
        }
        if(eventData->mouseX >= 657 && eventData->mouseX <= 711 && eventData->mouseY >= 38 && eventData->mouseY<=73){

            if(strcmp(searchText, "back") == 0){
                NodePtr temp = Result_currentRoot;
                Result_currentRoot = Result_previousRoot;
                Result_previousRoot = temp;
            }else if(strcmp(searchText, "prev") == 0){
                Result_previousRoot = Result_currentRoot;
                Result_currentRoot = searchprevNode(rootOfMLM, Result_currentRoot->name); 
            }
            else{
                Result_previousRoot = Result_currentRoot;
                Result_currentRoot = searchNode(rootOfMLM, searchText);
            }
        }
    }
    if(searchBarUsing == 1){
        fColor1.r = 255;
        if((eventData->currentInput >= SDLK_a && eventData->currentInput <= SDLK_z) || (eventData->currentInput >= SDLK_0 && eventData->currentInput <= SDLK_9)){
            char alphabet[3];
            alphabet[0] = (char)(currentShift + eventData->currentInput - SDLK_a);
            alphabet[1] = '\0';
            if(strcmp(searchText, "|") == 0){
                strcpy(searchText, alphabet);
            }else
                strcat(searchText, alphabet);
        }if(eventData->currentInput == SDLK_LSHIFT){
            currentShift = currentShift == 'A' ? 'a' : 'A';
        }if(eventData->currentInput == SDLK_BACKSPACE){
            if(strlen(searchText)>=2)
                searchText[strlen(searchText)-1] = '\0';
            else if(strlen(searchText) == 1)
                strcpy(searchText, "|");
        }
    }
    SDL_Surface *searchSur = TTF_RenderText_Blended_Wrapped(fFont0, searchText, fColor1, 750);
    SDL_Texture *Result_searchTex = SDL_CreateTextureFromSurface(renderer, searchSur);
    SDL_Rect TextRect = {425, 35, searchSur->w, searchSur->h};
    SDL_RenderCopy(renderer, Result_searchTex, NULL, &TextRect);

    TTF_CloseFont(fFont0);
    SDL_FreeSurface(searchSur);
    SDL_DestroyTexture(Result_searchTex);
}

void Result_DrawNode(SDL_Renderer *renderer, struct eventTrigger* eventData){
    NodePtr showNode;
    if(Result_currentRoot == NULL){
        showNode = rootOfMLM;
        Result_currentRoot = rootOfMLM;
    }else{
        showNode = Result_currentRoot;
    }

    TTF_Font *fFont0 = TTF_OpenFont("src/font/Alegreya-VariableFont_wght.ttf", 20);
    SDL_Color fColor1 = {0, 0, 0, 255};

    Result_nodeRect.x = 10 + 2*Result_nodeRect.w;
    Result_nodeRect.y = 150;
    int oldW = Result_nodeRect.w;
    int bigImgW = Result_nodeRect.w = 100;
    int bigImgH = Result_nodeRect.h = (int)(Result_nodeRect.w * ((float)Result_nodeRect.h / oldW));
    if(Result_currentSelect == NULL){
        fColor1.r = 255;
    }
    SDL_Surface *searchSur = TTF_RenderText_Blended_Wrapped(fFont0, showNode->name, fColor1, 750);
    SDL_Texture *Result_searchTex = SDL_CreateTextureFromSurface(renderer, searchSur);
    SDL_Rect TextRect = {100, 180, searchSur->w, searchSur->h};
    SDL_RenderCopy(renderer, Result_searchTex, NULL, &TextRect);
    fColor1.r = 0;

    SDL_FreeSurface(searchSur);
    SDL_DestroyTexture(Result_searchTex);

    SDL_RenderCopy(renderer, Result_nodeTexture, NULL, &Result_nodeRect);
    Result_nodeRect.x = 20;
    Result_nodeRect.y = 300;
    oldW = Result_nodeRect.w;
    Result_nodeRect.w = 80;
    Result_nodeRect.h = (int)(Result_nodeRect.w * ((float)Result_nodeRect.h / oldW));
    int count = 0;
    int countX = 0;
    int* Rw = &Result_nodeRect.w;
    int* Rh = &Result_nodeRect.h;
    int* x = &Result_nodeRect.x;
    int* y = &Result_nodeRect.y;

    showNode = showNode->child;
    while(showNode != NULL && count < 15){
        SDL_Surface *searchSur = TTF_RenderText_Blended_Wrapped(fFont0, showNode->name, fColor1, 750);
        SDL_Texture *Result_searchTex = SDL_CreateTextureFromSurface(renderer, searchSur);
        SDL_Rect TextRect = {*x + 10, *y - 25, searchSur->w, searchSur->h};
        SDL_RenderCopy(renderer, Result_searchTex, NULL, &TextRect);

        SDL_FreeSurface(searchSur);
        SDL_DestroyTexture(Result_searchTex);

        if(showNode->status == 0);
        else if(showNode == Result_currentSelect){
            SDL_RenderCopy(renderer, Result_nodeTexture2, NULL, &Result_nodeRect);
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderDrawLine(renderer, (10 + 2*(*Rw)) + bigImgW/2, 150 + bigImgH, *x + *Rw/2, *y);
            if(eventData->mouseX >= *x && eventData->mouseX <= *x+*Rw && eventData->mouseY >= *y && eventData->mouseY <= *y + *Rh && eventData->isTrigger == 1){
                Result_currentSelect = NULL;
            }
        }
        else if(eventData->mouseX >= *x && eventData->mouseX <= *x+*Rw && eventData->mouseY >= *y && eventData->mouseY <= *y + *Rh){
            if(eventData->isTrigger){
                Result_currentSelect = showNode;
                strcpy(searchText, showNode->name);
            }
            SDL_RenderCopy(renderer, Result_nodeTexture2, NULL, &Result_nodeRect);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawLine(renderer, (10 + 2*(*Rw)) + bigImgW/2, 150 + bigImgH, *x + *Rw/2, *y);
        }
        else{
            SDL_RenderCopy(renderer, Result_nodeTexture, NULL, &Result_nodeRect);
        }

        Result_nodeRect.x += Result_nodeRect.w;
        countX++;
        if(countX == 5){
            Result_nodeRect.x = 20;
            Result_nodeRect.y += Result_nodeRect.h + 20;
            countX = 0;
        }
        count++;
        showNode = showNode->nextSi;
    }

    TTF_CloseFont(fFont0);
}

void Result_Run(SDL_Renderer *renderer, struct eventTrigger* eventData){
    SDL_SetRenderDrawColor(renderer, 199, 231, 240, 200);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, Result_imgTexture1, NULL, &Result_imgRect1);
    SDL_RenderCopy(renderer, Result_imgTexture2, NULL, &Result_imgRect2);
    SDL_RenderCopy(renderer, Result_imgTexture8, NULL, &Result_imgRect8);
    SDL_RenderCopy(renderer, Result_imgTexture9, NULL, &Result_imgRect9);
    SDL_RenderCopy(renderer, Result_texTexture1, NULL, &Result_texRect1);
    SDL_RenderCopy(renderer, Result_texTexture11, NULL, &Result_texRect11);
    SDL_RenderCopy(renderer, Result_texTexture12, NULL, &Result_texRect12);
    SDL_RenderCopy(renderer, Result_texTexture13, NULL, &Result_texRect13);

    Result_DrawNode(renderer, eventData);
    Result_SearchBar(renderer, eventData);
    optionHandle(renderer, eventData);

    SDL_RenderPresent(renderer);
}