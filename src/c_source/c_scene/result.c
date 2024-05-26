#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <scene/Result.h>
#include <system/struct.h>
#include <string.h>
#include <system/nodeHandle.h>

//image
SDL_Rect Result_nodeRect;
SDL_Texture *Result_nodeTexture, *Result_nodeTexture2;

char searchText[10] = "NULL";

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

//text
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
    //image
    SDL_Surface *nodeSurface = IMG_Load("src/image/NodeActive1.png");
    Result_nodeTexture = SDL_CreateTextureFromSurface(renderer, nodeSurface);
    SDL_Surface *nodeSurface2 = IMG_Load("src/image/NodeActive2.png");
    Result_nodeTexture2 = SDL_CreateTextureFromSurface(renderer, nodeSurface2);
    Result_nodeRect.x = 170;
    Result_nodeRect.y = 180;
    Result_nodeRect.w = 80;
    Result_nodeRect.h = (int)(Result_nodeRect.w * ((float)nodeSurface->h / nodeSurface->w));

    SDL_FreeSurface(nodeSurface);
    SDL_FreeSurface(nodeSurface2);

    SDL_Surface *imgSur1 = IMG_Load("src/image/Result_Background.png");
    Result_imgTexture1 = SDL_CreateTextureFromSurface(renderer, imgSur1);
    Result_imgRect1.x = 30;
    Result_imgRect1.y = 30;
    Result_imgRect1.w = 300;
    Result_imgRect1.h = (int)(Result_imgRect1.w * ((float)imgSur1->h / imgSur1->w));

    SDL_FreeSurface(imgSur1);

    SDL_Surface *imgSur2 = IMG_Load("src/image/Result_search.png");
    Result_imgTexture2 = SDL_CreateTextureFromSurface(renderer, imgSur2);
    Result_imgRect2.x = 400;
    Result_imgRect2.y = 30;
    Result_imgRect2.w = 330;
    Result_imgRect2.h = (int)(Result_imgRect2.w * ((float)imgSur2->h / imgSur2->w));
    SDL_FreeSurface(imgSur2);

    SDL_Surface *imgSur3 = IMG_Load("src/image/Result_BackgroundAllOption.png");
    Result_imgTexture3 = SDL_CreateTextureFromSurface(renderer, imgSur3);
    Result_imgRect3.x = 480;
    Result_imgRect3.y = 180;
    Result_imgRect3.w = 250;
    Result_imgRect3.h = (int)(Result_imgRect3.w * ((float)imgSur3->h / imgSur3->w));
    SDL_FreeSurface(imgSur3);

    SDL_Surface *imgSur4 = IMG_Load("src/image/Result_ButtonOption.png");
    Result_imgTexture4 = SDL_CreateTextureFromSurface(renderer, imgSur4);
    Result_imgRect4.x = 500;
    Result_imgRect4.y = 235;
    Result_imgRect4.w = 210;
    Result_imgRect4.h = (int)(Result_imgRect4.w * ((float)imgSur4->h / imgSur4->w));
    SDL_FreeSurface(imgSur4);

    SDL_Surface *imgSur5 = IMG_Load("src/image/Result_ButtonOption.png");
    Result_imgTexture5 = SDL_CreateTextureFromSurface(renderer, imgSur5);
    Result_imgRect5.x = 500;
    Result_imgRect5.y = 315;
    Result_imgRect5.w = 210;
    Result_imgRect5.h = (int)(Result_imgRect5.w * ((float)imgSur5->h / imgSur5->w));
    SDL_FreeSurface(imgSur5);

    SDL_Surface *imgSur6 = IMG_Load("src/image/Result_ButtonOption.png");
    Result_imgTexture6 = SDL_CreateTextureFromSurface(renderer, imgSur6);
    Result_imgRect6.x = 500;
    Result_imgRect6.y = 395;
    Result_imgRect6.w = 210;
    Result_imgRect6.h = (int)(Result_imgRect6.w * ((float)imgSur6->h / imgSur6->w));
    SDL_FreeSurface(imgSur6);

    SDL_Surface *imgSur7 = IMG_Load("src/image/Result_ButtonOption.png");
    Result_imgTexture7 = SDL_CreateTextureFromSurface(renderer, imgSur7);
    Result_imgRect7.x = 500;
    Result_imgRect7.y = 475;
    Result_imgRect7.w = 210;
    Result_imgRect7.h = (int)(Result_imgRect7.w * ((float)imgSur7->h / imgSur7->w));
    SDL_FreeSurface(imgSur7);

    SDL_Surface *imgSur8 = IMG_Load("src/image/Result_Restart.png");
    Result_imgTexture8 = SDL_CreateTextureFromSurface(renderer, imgSur8);
    Result_imgRect8.x = 660;
    Result_imgRect8.y = 670;
    Result_imgRect8.w = 60;
    Result_imgRect8.h = (int)(Result_imgRect8.w * ((float)imgSur8->h / imgSur8->w));
    SDL_FreeSurface(imgSur8);

    SDL_Surface *imgSur9 = IMG_Load("src/image/Result_Cal.png");
    Result_imgTexture9 = SDL_CreateTextureFromSurface(renderer, imgSur9);
    Result_imgRect9.x = 25;
    Result_imgRect9.y = 640;
    Result_imgRect9.w = 100;
    Result_imgRect9.h = (int)(Result_imgRect9.w * ((float)imgSur9->h / imgSur9->w));
    SDL_FreeSurface(imgSur9);

    // SDL_Surface *imgSur10 = IMG_Load("src/image/Result_edit.png");
    // Result_imgTexture10 = SDL_CreateTextureFromSurface(renderer, imgSur10);
    // Result_imgRect10.x = 170;
    // Result_imgRect10.y = 650;
    // Result_imgRect10.w = 80;
    // Result_imgRect10.h = (int)(Result_imgRect10.w * ((float)imgSur10->h / imgSur10->w));
    // SDL_FreeSurface(imgSur10);

    //text


    TTF_Font *fFont1 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 45);
    SDL_Color fColor1 = {0, 0, 0, 255};
    SDL_Surface *textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, "Result", fColor1, 750);
    Result_texTexture1 = SDL_CreateTextureFromSurface(renderer, textSur1);
    Result_texRect1.x = 120;
    Result_texRect1.y = 43;
    Result_texRect1.w = textSur1->w;
    Result_texRect1.h = textSur1->h;
    SDL_FreeSurface(textSur1);
    TTF_CloseFont(fFont1);

    TTF_Font *fFont2 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 20);
    SDL_Color fColor2 = {0, 0, 0, 255};
    SDL_Surface *textSur2 = TTF_RenderText_Blended_Wrapped(fFont2, "All Options", fColor2, 750);
    Result_texTexture2 = SDL_CreateTextureFromSurface(renderer, textSur2);
    Result_texRect2.x = 525;
    Result_texRect2.y = 195;
    Result_texRect2.w = textSur2->w;
    Result_texRect2.h = textSur2->h;
    SDL_FreeSurface(textSur2);
    TTF_CloseFont(fFont2);

    TTF_Font *fFont3 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 14);
    SDL_Color fColor3 = {0, 0, 0, 255};
    SDL_Surface *textSur3 = TTF_RenderText_Blended_Wrapped(fFont3, "Show", fColor3, 750);
    Result_texTexture3 = SDL_CreateTextureFromSurface(renderer, textSur3);
    Result_texRect3.x = 590;
    Result_texRect3.y = 245;
    Result_texRect3.w = textSur3->w;
    Result_texRect3.h = textSur3->h;
    SDL_FreeSurface(textSur3);
    TTF_CloseFont(fFont3);

    TTF_Font *fFont4 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 14);
    SDL_Color fColor4 = {0, 0, 0, 255};
    SDL_Surface *textSur4 = TTF_RenderText_Blended_Wrapped(fFont4, "Information", fColor4, 750);
    Result_texTexture4 = SDL_CreateTextureFromSurface(renderer, textSur4);
    Result_texRect4.x = 560;
    Result_texRect4.y = 270;
    Result_texRect4.w = textSur4->w;
    Result_texRect4.h = textSur4->h;
    SDL_FreeSurface(textSur4);
    TTF_CloseFont(fFont4);

    TTF_Font *fFont5 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 14);
    SDL_Color fColor5 = {0, 0, 0, 255};
    SDL_Surface *textSur5 = TTF_RenderText_Blended_Wrapped(fFont5, "Edit", fColor5, 750);
    Result_texTexture5 = SDL_CreateTextureFromSurface(renderer, textSur5);
    Result_texRect5.x = 595;
    Result_texRect5.y = 325;
    Result_texRect5.w = textSur5->w;
    Result_texRect5.h = textSur5->h;
    SDL_FreeSurface(textSur5);
    TTF_CloseFont(fFont5);

    TTF_Font *fFont6 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 14);
    SDL_Color fColor6 = {0, 0, 0, 255};
    SDL_Surface *textSur6 = TTF_RenderText_Blended_Wrapped(fFont6, "Selling", fColor6, 750);
    Result_texTexture6 = SDL_CreateTextureFromSurface(renderer, textSur6);
    Result_texRect6.x = 580;
    Result_texRect6.y = 350;
    Result_texRect6.w = textSur6->w;
    Result_texRect6.h = textSur6->h;
    SDL_FreeSurface(textSur6);
    TTF_CloseFont(fFont6);

    TTF_Font *fFont7 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 14);
    SDL_Color fColor7 = {0, 0, 0, 255};
    SDL_Surface *textSur7 = TTF_RenderText_Blended_Wrapped(fFont7, "Delete", fColor7, 750);
    Result_texTexture7 = SDL_CreateTextureFromSurface(renderer, textSur7);
    Result_texRect7.x = 585;
    Result_texRect7.y = 405;
    Result_texRect7.w = textSur7->w;
    Result_texRect7.h = textSur7->h;
    SDL_FreeSurface(textSur7);
    TTF_CloseFont(fFont7);

    TTF_Font *fFont8 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 14);
    SDL_Color fColor8 = {0, 0, 0, 255};
    SDL_Surface *textSur8 = TTF_RenderText_Blended_Wrapped(fFont8, "This Person", fColor8, 750);
    Result_texTexture8 = SDL_CreateTextureFromSurface(renderer, textSur8);
    Result_texRect8.x = 565;
    Result_texRect8.y = 428;
    Result_texRect8.w = textSur8->w;
    Result_texRect8.h = textSur8->h;
    SDL_FreeSurface(textSur8);
    TTF_CloseFont(fFont8);

    TTF_Font *fFont9 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 14);
    SDL_Color fColor9 = {0, 0, 0, 255};
    SDL_Surface *textSur9 = TTF_RenderText_Blended_Wrapped(fFont9, "Add", fColor9, 750);
    Result_texTexture9 = SDL_CreateTextureFromSurface(renderer, textSur9);
    Result_texRect9.x = 598;
    Result_texRect9.y = 485;
    Result_texRect9.w = textSur9->w;
    Result_texRect9.h = textSur9->h;
    SDL_FreeSurface(textSur9);
    TTF_CloseFont(fFont9);

    TTF_Font *fFont10 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 14);
    SDL_Color fColor10 = {0, 0, 0, 255};
    SDL_Surface *textSur10 = TTF_RenderText_Blended_Wrapped(fFont10, "Downline", fColor10, 750);
    Result_texTexture10 = SDL_CreateTextureFromSurface(renderer, textSur10);
    Result_texRect10.x = 572;
    Result_texRect10.y = 510;
    Result_texRect10.w = textSur10->w;
    Result_texRect10.h = textSur10->h;
    SDL_FreeSurface(textSur10);
    TTF_CloseFont(fFont10);

    TTF_Font *fFont11 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 10);
    SDL_Color fColor11 = {0, 0, 0, 255};
    SDL_Surface *textSur11 = TTF_RenderText_Blended_Wrapped(fFont11, "Calculate", fColor11, 750);
    Result_texTexture11 = SDL_CreateTextureFromSurface(renderer, textSur11);
    Result_texRect11.x = 49;
    Result_texRect11.y = 675;
    Result_texRect11.w = textSur11->w;
    Result_texRect11.h = textSur11->h;
    SDL_FreeSurface(textSur11);
    TTF_CloseFont(fFont11);

    TTF_Font *fFont12 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 10);
    SDL_Color fColor12 = {0, 0, 0, 255};
    SDL_Surface *textSur12 = TTF_RenderText_Blended_Wrapped(fFont12, "PV and", fColor12, 750);
    Result_texTexture12 = SDL_CreateTextureFromSurface(renderer, textSur12);
    Result_texRect12.x = 58;
    Result_texRect12.y = 690;
    Result_texRect12.w = textSur12->w;
    Result_texRect12.h = textSur12->h;
    SDL_FreeSurface(textSur12);
    TTF_CloseFont(fFont12);

    TTF_Font *fFont13 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 10);
    SDL_Color fColor13 = {0, 0, 0, 255};
    SDL_Surface *textSur13 = TTF_RenderText_Blended_Wrapped(fFont13, "Salary", fColor13, 750);
    Result_texTexture13 = SDL_CreateTextureFromSurface(renderer, textSur13);
    Result_texRect13.x = 59;
    Result_texRect13.y = 705;
    Result_texRect13.w = textSur13->w;
    Result_texRect13.h = textSur13->h;
    SDL_FreeSurface(textSur13);
    TTF_CloseFont(fFont13);
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
    if(eventData->isTrigger == 1){
        if(eventData->mouseX >= Result_imgRect6.x && eventData->mouseX <= Result_imgRect6.x + Result_imgRect6.w && 
        eventData->mouseY >= Result_imgRect6.y && eventData->mouseY<=Result_imgRect6.y + Result_imgRect6.h){
            rootOfMLM = delNode(Result_currentSelect->name, rootOfMLM);
            writeFile(rootOfMLM);
        }
        if(eventData->mouseX >= Result_imgRect5.x && eventData->mouseX <= Result_imgRect5.x + Result_imgRect5.w && 
        eventData->mouseY >= Result_imgRect5.y && eventData->mouseY<=Result_imgRect5.y + Result_imgRect5.h){
            currentRoom = 5;
            sendingNode = Result_currentSelect != NULL ? Result_currentSelect : Result_currentRoot;
            Result_currentSelect = NULL;
        }
        if(eventData->mouseX >= Result_imgRect7.x && eventData->mouseX <= Result_imgRect7.x + Result_imgRect7.w && 
        eventData->mouseY >= Result_imgRect7.y && eventData->mouseY<=Result_imgRect7.y + Result_imgRect7.h){
            currentRoom = 6;
            sendingNode = Result_currentSelect != NULL ? Result_currentSelect : Result_currentRoot;
            Result_currentSelect = NULL;
        }
        if(eventData->mouseX >= Result_imgRect8.x && eventData->mouseX <= Result_imgRect8.x + Result_imgRect8.w && 
        eventData->mouseY >= Result_imgRect8.y && eventData->mouseY<=Result_imgRect8.y + Result_imgRect8.h){
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
        if(eventData->mouseX >= Result_imgRect4.x && eventData->mouseX <= Result_imgRect4.x + Result_imgRect4.w && 
        eventData->mouseY >= Result_imgRect4.y && eventData->mouseY<=Result_imgRect4.y + Result_imgRect4.h){
            currentRoom = 2;
            sendingNode = Result_currentSelect != NULL ? Result_currentSelect : Result_currentRoot;
            Result_currentSelect = NULL;
        }
        if(eventData->mouseX >= Result_imgRect9.x && eventData->mouseX <= Result_imgRect9.x + Result_imgRect9.w && 
        eventData->mouseY >= Result_imgRect9.y && eventData->mouseY<=Result_imgRect9.y + Result_imgRect9.h){
            currentRoom = 4;
            
        }
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
    //free(fFont0);
    // 40 310
}

void Result_DrawScene(SDL_Renderer *renderer, struct eventTrigger* eventData){
    SDL_SetRenderDrawColor(renderer, 199, 231, 240, 200); //217,241,255
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, Result_imgTexture1, NULL, &Result_imgRect1);
    SDL_RenderCopy(renderer, Result_imgTexture2, NULL, &Result_imgRect2);
    SDL_RenderCopy(renderer, Result_imgTexture8, NULL, &Result_imgRect8);
    SDL_RenderCopy(renderer, Result_imgTexture9, NULL, &Result_imgRect9);
    // SDL_RenderCopy(renderer, Result_imgTexture10, NULL, &Result_imgRect10);
    SDL_RenderCopy(renderer, Result_texTexture1, NULL, &Result_texRect1);
    SDL_RenderCopy(renderer, Result_texTexture11, NULL, &Result_texRect11);
    SDL_RenderCopy(renderer, Result_texTexture12, NULL, &Result_texRect12);
    SDL_RenderCopy(renderer, Result_texTexture13, NULL, &Result_texRect13);

    Result_DrawNode(renderer, eventData);
    Result_SearchBar(renderer, eventData);
    optionHandle(renderer, eventData);

    SDL_RenderPresent(renderer);
}