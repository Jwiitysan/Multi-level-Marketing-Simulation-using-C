#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <scene/Salary.h>
#include <system/struct.h>
#include <system/nodeHandle.h>
#include <string.h>

//image
SDL_Rect Salary_nodeRect;
SDL_Texture *Salary_nodeTexture, *Salary_nodeTexture2;

SDL_Rect Salary_imgRect1;
SDL_Texture *Salary_imgTexture1;
SDL_Rect Salary_imgRect2;
SDL_Texture *Salary_imgTexture2;
SDL_Rect Salary_imgRect3;
SDL_Texture *Salary_imgTexture3;
SDL_Rect Salary_imgRect4;
SDL_Texture *Salary_imgTexture4;
SDL_Rect Salary_imgRect5;
SDL_Texture *Salary_imgTexture5;
SDL_Rect Salary_imgRect6;
SDL_Texture *Salary_imgTexture6;
SDL_Rect Salary_imgRect7;
SDL_Texture *Salary_imgTexture7;


//text
SDL_Texture *Salary_texTexture1;
SDL_Rect Salary_texRect1;
SDL_Texture *Salary_texTexture2;
SDL_Rect Salary_texRect2;
SDL_Texture *Salary_texTexture3;
SDL_Rect Salary_texRect3;


void Salary_Initial(SDL_Renderer *renderer){

    //image
    SDL_Surface *nodeSurface = IMG_Load("src/image/NodeActive1.png");
    Salary_nodeTexture = SDL_CreateTextureFromSurface(renderer, nodeSurface);
    SDL_Surface *nodeSurface2 = IMG_Load("src/image/NodeActive2.png");
    Salary_nodeTexture2 = SDL_CreateTextureFromSurface(renderer, nodeSurface2);
    Salary_nodeRect.x = 170;
    Salary_nodeRect.y = 180;
    Salary_nodeRect.w = 80;
    Salary_nodeRect.h = (int)(Salary_nodeRect.w * ((float)nodeSurface->h / nodeSurface->w));

    SDL_FreeSurface(nodeSurface);
    SDL_FreeSurface(nodeSurface2);

    SDL_Surface *imgSur1 = IMG_Load("src/image/Salary_Background.png");
    Salary_imgTexture1 = SDL_CreateTextureFromSurface(renderer, imgSur1);
    Salary_imgRect1.x = 30;
    Salary_imgRect1.y = 30;
    Salary_imgRect1.w = 300;
    Salary_imgRect1.h = (int)(Salary_imgRect1.w * ((float)imgSur1->h / imgSur1->w));

    SDL_Surface *imgSur2 = IMG_Load("src/image/Search.png");
    Salary_imgTexture2 = SDL_CreateTextureFromSurface(renderer, imgSur2);
    Salary_imgRect2.x = 400;
    Salary_imgRect2.y = 30;
    Salary_imgRect2.w = 330;
    Salary_imgRect2.h = (int)(Salary_imgRect2.w * ((float)imgSur2->h / imgSur2->w));

    // SDL_Surface *imgSur3 = IMG_Load("src/image/Salary_ShowTable.png");
    // Salary_imgTexture3 = SDL_CreateTextureFromSurface(renderer, imgSur3);
    // Salary_imgRect3.x = 420;
    // Salary_imgRect3.y = 650;
    // Salary_imgRect3.w = 300;
    // Salary_imgRect3.h = (int)(Salary_imgRect3.w * ((float)imgSur3->h / imgSur3->w));

    SDL_Surface *imgSur4 = IMG_Load("src/image/Back.png");
    Salary_imgTexture4 = SDL_CreateTextureFromSurface(renderer, imgSur4);
    Salary_imgRect4.x = 25;
    Salary_imgRect4.y = 690;
    Salary_imgRect4.w = 60;
    Salary_imgRect4.h = (int)(Salary_imgRect4.w * ((float)imgSur4->h / imgSur4->w));


    //text

    TTF_Font *fFont1 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 40);
    SDL_Color fColor1 = {0, 0, 0, 255};
    SDL_Surface *textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, "Salary", fColor1, 750);
    Salary_texTexture1 = SDL_CreateTextureFromSurface(renderer, textSur1);
    Salary_texRect1.x = 120;
    Salary_texRect1.y = 45;
    Salary_texRect1.w = textSur1->w;
    Salary_texRect1.h = textSur1->h;

    // TTF_Font *fFont2 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 25);
    // SDL_Color fColor2 = {0, 0, 0, 255};
    // SDL_Surface *textSur2 = TTF_RenderText_Blended_Wrapped(fFont2, "Show Table", fColor2, 720);
    // Salary_texTexture2 = SDL_CreateTextureFromSurface(renderer, textSur2);
    // Salary_texRect2.x = 445;
    // Salary_texRect2.y = 675;
    // Salary_texRect2.w = textSur2->w;
    // Salary_texRect2.h = textSur2->h;

    
}

int Salary_searchBarUsing = 0;
char Salary_currentShift = 'a';
char Salary_searchText[10] = "NULL";

NodePtr Salary_previousRoot = NULL;
NodePtr Salary_currentSelect = NULL;
NodePtr Salary_currentRoot = NULL;

void Salary_SearchBar(SDL_Renderer *renderer, struct eventTrigger* eventData){
    TTF_Font *fFont0 = TTF_OpenFont("src/font/Alegreya-VariableFont_wght.ttf", 30);
    SDL_Color fColor1 = {0, 0, 0, 255};
    if(eventData->isTrigger == 1){
        if(eventData->mouseX >= 418 && eventData->mouseX <= 638 && eventData->mouseY >= 41 && eventData->mouseY<=73){
            Salary_searchBarUsing = 1;
        }
        else{
            Salary_searchBarUsing = 0;
        }
        if(eventData->mouseX >= 657 && eventData->mouseX <= 711 && eventData->mouseY >= 38 && eventData->mouseY<=73){

            if(strcmp(Salary_searchText, "back") == 0){
                NodePtr temp = Salary_currentRoot;
                Salary_currentRoot = Salary_previousRoot;
                Salary_previousRoot = temp;
            }else if(strcmp(Salary_searchText, "prev") == 0){
                Salary_previousRoot = Salary_currentRoot;
                Salary_currentRoot = searchprevNode(rootOfMLM, Salary_currentRoot->name); 
            }
            else{
                Salary_previousRoot = Salary_currentRoot;
                Salary_currentRoot = searchNode(rootOfMLM, Salary_searchText);
            }
        }
    }
    if(Salary_searchBarUsing == 1){
        fColor1.r = 255;
        if((eventData->currentInput >= SDLK_a && eventData->currentInput <= SDLK_z) || (eventData->currentInput >= SDLK_0 && eventData->currentInput <= SDLK_9)){
            char alphabet[3];
            alphabet[0] = (char)(Salary_currentShift + eventData->currentInput - SDLK_a);
            alphabet[1] = '\0';
            if(strcmp(Salary_searchText, "|") == 0){
                strcpy(Salary_searchText, alphabet);
            }else
                strcat(Salary_searchText, alphabet);
        }if(eventData->currentInput == SDLK_LSHIFT){
            Salary_currentShift = Salary_currentShift == 'A' ? 'a' : 'A';
        }if(eventData->currentInput == SDLK_BACKSPACE){
            if(strlen(Salary_searchText)>=2)
                Salary_searchText[strlen(Salary_searchText)-1] = '\0';
            else if(strlen(Salary_searchText) == 1)
                strcpy(Salary_searchText, "|");
        }
    }
    SDL_Surface *searchSur = TTF_RenderText_Blended_Wrapped(fFont0, Salary_searchText, fColor1, 750);
    SDL_Texture *Salary_searchTex = SDL_CreateTextureFromSurface(renderer, searchSur);
    SDL_Rect TextRect = {425, 35, searchSur->w, searchSur->h};
    SDL_RenderCopy(renderer, Salary_searchTex, NULL, &TextRect);

    TTF_CloseFont(fFont0);
    SDL_FreeSurface(searchSur);
    SDL_DestroyTexture(Salary_searchTex);
}

void Salary_ShowTextResult(SDL_Renderer *renderer, struct eventTrigger *eventData){
    TTF_Font *fFont0 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 40);
    SDL_Color fColor1 = {0, 0, 0, 255};
    SDL_Surface *searchSur = TTF_RenderText_Blended_Wrapped(fFont0, "INFO", fColor1, 750);
    SDL_Texture *Salary_searchTex = SDL_CreateTextureFromSurface(renderer, searchSur);
    SDL_Rect TextRect = {510, 150, searchSur->w, searchSur->h};
    SDL_RenderCopy(renderer, Salary_searchTex, NULL, &TextRect);

    TTF_CloseFont(fFont0);
    SDL_FreeSurface(searchSur);
    SDL_DestroyTexture(Salary_searchTex);

    fFont0 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 20);

    searchSur = TTF_RenderText_Blended_Wrapped(fFont0, "Retail Profit", fColor1, 750);
    Salary_searchTex = SDL_CreateTextureFromSurface(renderer, searchSur);
    SDL_Rect TextRect2 = {450, 270, searchSur->w, searchSur->h};
    SDL_RenderCopy(renderer, Salary_searchTex, NULL, &TextRect2);

    SDL_FreeSurface(searchSur);
    SDL_DestroyTexture(Salary_searchTex);

    searchSur = TTF_RenderText_Blended_Wrapped(fFont0, "BV", fColor1, 750);
    Salary_searchTex = SDL_CreateTextureFromSurface(renderer, searchSur);
    SDL_Rect TextRect99 = {450, 370, searchSur->w, searchSur->h};
    SDL_RenderCopy(renderer, Salary_searchTex, NULL, &TextRect99);

    SDL_FreeSurface(searchSur);
    SDL_DestroyTexture(Salary_searchTex);

    searchSur = TTF_RenderText_Blended_Wrapped(fFont0, "PV", fColor1, 750);
    Salary_searchTex = SDL_CreateTextureFromSurface(renderer, searchSur);
    SDL_Rect TextRect3 = {450, 400, searchSur->w, searchSur->h};
    SDL_RenderCopy(renderer, Salary_searchTex, NULL, &TextRect3);

    SDL_FreeSurface(searchSur);
    SDL_DestroyTexture(Salary_searchTex);

    searchSur = TTF_RenderText_Blended_Wrapped(fFont0, "Salary", fColor1, 750);
    Salary_searchTex = SDL_CreateTextureFromSurface(renderer, searchSur);
    SDL_Rect TextRect4 = {450, 430, searchSur->w, searchSur->h};
    SDL_RenderCopy(renderer, Salary_searchTex, NULL, &TextRect4);

    SDL_FreeSurface(searchSur);
    SDL_DestroyTexture(Salary_searchTex);
    TTF_CloseFont(fFont0);

    if(Salary_currentSelect == NULL){
        if(Salary_currentRoot == NULL)
            Salary_currentSelect = rootOfMLM;
        else Salary_currentSelect = Salary_currentRoot;
    }

    fFont0 = TTF_OpenFont("src/font/Alegreya-VariableFont_wght.ttf", 30);
    
    searchSur = TTF_RenderText_Blended_Wrapped(fFont0, Salary_currentSelect->name, fColor1, 750);
    Salary_searchTex = SDL_CreateTextureFromSurface(renderer, searchSur);
    SDL_Rect TextRect5 = {460, 215, searchSur->w, searchSur->h};
    SDL_RenderCopy(renderer, Salary_searchTex, NULL, &TextRect5);

    SDL_FreeSurface(searchSur);
    SDL_DestroyTexture(Salary_searchTex);

    char str[20];
    sprintf(str, "%d", Salary_currentSelect->retail);

    searchSur = TTF_RenderText_Blended_Wrapped(fFont0, str, fColor1, 750);
    Salary_searchTex = SDL_CreateTextureFromSurface(renderer, searchSur);
    SDL_Rect TextRect6 = {510, 300, searchSur->w, searchSur->h};
    SDL_RenderCopy(renderer, Salary_searchTex, NULL, &TextRect6);

    SDL_FreeSurface(searchSur);
    SDL_DestroyTexture(Salary_searchTex);

    sprintf(str, "%d", Salary_currentSelect->BV);

    searchSur = TTF_RenderText_Blended_Wrapped(fFont0, str, fColor1, 750);
    Salary_searchTex = SDL_CreateTextureFromSurface(renderer, searchSur);
    SDL_Rect TextRect999 = {510, 362, searchSur->w, searchSur->h};
    SDL_RenderCopy(renderer, Salary_searchTex, NULL, &TextRect999);

    SDL_FreeSurface(searchSur);
    SDL_DestroyTexture(Salary_searchTex);

    sprintf(str, "%d", calPV(Salary_currentSelect));

    searchSur = TTF_RenderText_Blended_Wrapped(fFont0, str, fColor1, 750);
    Salary_searchTex = SDL_CreateTextureFromSurface(renderer, searchSur);
    SDL_Rect TextRect7 = {510, 392, searchSur->w, searchSur->h};
    SDL_RenderCopy(renderer, Salary_searchTex, NULL, &TextRect7);

    SDL_FreeSurface(searchSur);
    SDL_DestroyTexture(Salary_searchTex);

    sprintf(str, "%.2f", Allincome(Salary_currentSelect->name, rootOfMLM));
    searchSur = TTF_RenderText_Blended_Wrapped(fFont0, str, fColor1, 750);
    Salary_searchTex = SDL_CreateTextureFromSurface(renderer, searchSur);
    SDL_Rect TextRect8 = {510, 462, searchSur->w, searchSur->h};
    SDL_RenderCopy(renderer, Salary_searchTex, NULL, &TextRect8);

    SDL_FreeSurface(searchSur);
    SDL_DestroyTexture(Salary_searchTex);
    TTF_CloseFont(fFont0);
}

void Salary_DrawNode(SDL_Renderer *renderer, struct eventTrigger* eventData){
    NodePtr showNode;
    if(Salary_currentRoot == NULL){
        showNode = rootOfMLM;
        Salary_currentRoot = rootOfMLM;
    }else{
        showNode = Salary_currentRoot;
    }

    TTF_Font *fFont0 = TTF_OpenFont("src/font/Alegreya-VariableFont_wght.ttf", 20);
    SDL_Color fColor1 = {0, 0, 0, 255};

    Salary_nodeRect.x = 10 + 2*Salary_nodeRect.w;
    Salary_nodeRect.y = 150;
    int oldW = Salary_nodeRect.w;
    int bigImgW = Salary_nodeRect.w = 100;
    int bigImgH = Salary_nodeRect.h = (int)(Salary_nodeRect.w * ((float)Salary_nodeRect.h / oldW));
    if(Salary_currentSelect == NULL){
        fColor1.r = 255;
    }
    SDL_Surface *searchSur = TTF_RenderText_Blended_Wrapped(fFont0, showNode->name, fColor1, 750);
    SDL_Texture *Salary_searchTex = SDL_CreateTextureFromSurface(renderer, searchSur);
    SDL_Rect TextRect = {100, 180, searchSur->w, searchSur->h};
    SDL_RenderCopy(renderer, Salary_searchTex, NULL, &TextRect);
    fColor1.r = 0;

    SDL_FreeSurface(searchSur);
    SDL_DestroyTexture(Salary_searchTex);

    SDL_RenderCopy(renderer, Salary_nodeTexture, NULL, &Salary_nodeRect);
    Salary_nodeRect.x = 20;
    Salary_nodeRect.y = 300;
    oldW = Salary_nodeRect.w;
    Salary_nodeRect.w = 80;
    Salary_nodeRect.h = (int)(Salary_nodeRect.w * ((float)Salary_nodeRect.h / oldW));
    int count = 0;
    int countX = 0;
    int* Rw = &Salary_nodeRect.w;
    int* Rh = &Salary_nodeRect.h;
    int* x = &Salary_nodeRect.x;
    int* y = &Salary_nodeRect.y;

    showNode = showNode->child;
    while(showNode != NULL && count < 15){
        SDL_Surface *searchSur = TTF_RenderText_Blended_Wrapped(fFont0, showNode->name, fColor1, 750);
        SDL_Texture *Salary_searchTex = SDL_CreateTextureFromSurface(renderer, searchSur);
        SDL_Rect TextRect = {*x + 10, *y - 25, searchSur->w, searchSur->h};
        SDL_RenderCopy(renderer, Salary_searchTex, NULL, &TextRect);

        SDL_FreeSurface(searchSur);
        SDL_DestroyTexture(Salary_searchTex);

        if(showNode->status == 0);
        else if(showNode == Salary_currentSelect){
            SDL_RenderCopy(renderer, Salary_nodeTexture2, NULL, &Salary_nodeRect);
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderDrawLine(renderer, (10 + 2*(*Rw)) + bigImgW/2, 150 + bigImgH, *x + *Rw/2, *y);
            if(eventData->mouseX >= *x && eventData->mouseX <= *x+*Rw && eventData->mouseY >= *y && eventData->mouseY <= *y + *Rh && eventData->isTrigger == 1){
                Salary_currentSelect = NULL;
            }
        }
        else if(eventData->mouseX >= *x && eventData->mouseX <= *x+*Rw && eventData->mouseY >= *y && eventData->mouseY <= *y + *Rh){
            if(eventData->isTrigger){
                Salary_currentSelect = showNode;
                strcpy(Salary_searchText, showNode->name);
            }
            SDL_RenderCopy(renderer, Salary_nodeTexture2, NULL, &Salary_nodeRect);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawLine(renderer, (10 + 2*(*Rw)) + bigImgW/2, 150 + bigImgH, *x + *Rw/2, *y);
        }
        else{
            SDL_RenderCopy(renderer, Salary_nodeTexture, NULL, &Salary_nodeRect);
        }

        Salary_nodeRect.x += Salary_nodeRect.w;
        countX++;
        if(countX == 5){
            Salary_nodeRect.x = 20;
            Salary_nodeRect.y += Salary_nodeRect.h + 20;
            countX = 0;
        }
        count++;
        showNode = showNode->nextSi;
    }

    TTF_CloseFont(fFont0);
    //free(fFont0);
    // 40 310
}

void Salary_DrawScene(SDL_Renderer *renderer, struct eventTrigger* eventData){
    SDL_SetRenderDrawColor(renderer, 199, 231, 240, 200); //217,241,255
    SDL_RenderClear(renderer);

    if(eventData->mouseX >= Salary_imgRect4.x && eventData->mouseX <= Salary_imgRect4.x + Salary_imgRect4.w &&
        eventData->isTrigger == 1 && eventData->mouseY >= Salary_imgRect4.y && eventData->mouseY <= Salary_imgRect4.y + Salary_imgRect4.h){
        currentRoom = 1;
    }

    SDL_RenderCopy(renderer, Salary_imgTexture1, NULL, &Salary_imgRect1);
    SDL_RenderCopy(renderer, Salary_imgTexture2, NULL, &Salary_imgRect2);
    // SDL_RenderCopy(renderer, Salary_imgTexture3, NULL, &Salary_imgRect3);
    SDL_RenderCopy(renderer, Salary_imgTexture4, NULL, &Salary_imgRect4);

    SDL_RenderCopy(renderer, Salary_texTexture1, NULL, &Salary_texRect1);
    // SDL_RenderCopy(renderer, Salary_texTexture2, NULL, &Salary_texRect2);
    
    Salary_ShowTextResult(renderer, eventData);
    Salary_DrawNode(renderer, eventData);
    Salary_SearchBar(renderer, eventData);

    SDL_RenderPresent(renderer);
}