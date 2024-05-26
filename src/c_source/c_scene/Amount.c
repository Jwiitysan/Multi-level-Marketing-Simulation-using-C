#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <scene/Amount.h>
#include <system/struct.h>
#include <system/edit.h>
#include <stdlib.h>
#include <string.h>
//image
SDL_Rect Amount_imgRect1;
SDL_Texture *Amount_imgTexture1;
SDL_Rect Amount_imgRect2;
SDL_Texture *Amount_imgTexture2;
SDL_Rect Amount_imgRect3;
SDL_Texture *Amount_imgTexture3;
SDL_Rect Amount_imgRect4;
SDL_Texture *Amount_imgTexture4;
SDL_Rect Amount_imgRect5;
SDL_Texture *Amount_imgTexture5;
SDL_Rect Amount_imgRect6;
SDL_Texture *Amount_imgTexture6;

SDL_Rect Amount_imgRect7;
SDL_Texture *Amount_imgTexture7;
SDL_Rect Amount_imgRect8;
SDL_Texture *Amount_imgTexture8;
SDL_Rect Amount_imgRect9;
SDL_Texture *Amount_imgTexture9;
SDL_Rect Amount_imgRect10;
SDL_Texture *Amount_imgTexture10;
SDL_Rect Amount_imgRect11;
SDL_Texture *Amount_imgTexture11;

//text
SDL_Texture *Amount_texTexture1;
SDL_Rect Amount_texRect1;
SDL_Texture *Amount_texTexture2;
SDL_Rect Amount_texRect2;
SDL_Texture *Amount_texTexture3;
SDL_Rect Amount_texRect3;
SDL_Texture *Amount_texTexture4;
SDL_Rect Amount_texRect4;


void Amount_Initial(SDL_Renderer *renderer){

    //image

    SDL_Surface *imgSur1 = IMG_Load("src/ImgPro/Amount_Background.png");
    Amount_imgTexture1 = SDL_CreateTextureFromSurface(renderer, imgSur1);
    Amount_imgRect1.x = 110;
    Amount_imgRect1.y = 25;
    Amount_imgRect1.w = 530;
    Amount_imgRect1.h = 90;

    SDL_FreeSurface(imgSur1);

    SDL_Surface *imgSur2 = IMG_Load("src/ImgPro/selling_Tree.png");
    Amount_imgTexture2 = SDL_CreateTextureFromSurface(renderer, imgSur2);
    Amount_imgRect2.x = 10;
    Amount_imgRect2.y = 150;
    Amount_imgRect2.w = 500;
    Amount_imgRect2.h = 510;

    SDL_FreeSurface(imgSur2);

    SDL_Surface *imgSur3 = IMG_Load("src/ImgPro/Amount_Amount.png");
    Amount_imgTexture3 = SDL_CreateTextureFromSurface(renderer, imgSur3);
    Amount_imgRect3.x = 515;
    Amount_imgRect3.y = 250;
    Amount_imgRect3.w = 220;
    Amount_imgRect3.h = (int)(Amount_imgRect3.w * ((float)imgSur3->h / imgSur3->w));

    SDL_FreeSurface(imgSur3);

    SDL_Surface *imgSur4 = IMG_Load("src/ImgPro/selling_PriceFix2.png");
    Amount_imgTexture4 = SDL_CreateTextureFromSurface(renderer, imgSur4);
    Amount_imgRect4.x = 515;
    Amount_imgRect4.y = 420;
    Amount_imgRect4.w = 220;
    Amount_imgRect4.h = (int)(Amount_imgRect4.w * ((float)imgSur4->h / imgSur4->w));

    SDL_FreeSurface(imgSur4);

    SDL_Surface *imgSur5 = IMG_Load("src/ImgPro/selling_OK.png");
    Amount_imgTexture5 = SDL_CreateTextureFromSurface(renderer, imgSur5);
    Amount_imgRect5.x = 580;
    Amount_imgRect5.y = 550;
    Amount_imgRect5.w = 90;
    Amount_imgRect5.h = (int)(Amount_imgRect5.w * ((float)imgSur5->h / imgSur5->w));

    SDL_FreeSurface(imgSur5);

    SDL_Surface *imgSur6 = IMG_Load("src/ImgPro/Back.png");
    Amount_imgTexture6 = SDL_CreateTextureFromSurface(renderer, imgSur6);
    Amount_imgRect6.x = 25;
    Amount_imgRect6.y = 680;
    Amount_imgRect6.w = 60;
    Amount_imgRect6.h = (int)(Amount_imgRect6.w * ((float)imgSur6->h / imgSur6->w));

    SDL_FreeSurface(imgSur6);

    //img_product

    SDL_Surface *imgSur7 = IMG_Load("src/ImgPro/eSpring.png");
    Amount_imgTexture7 = SDL_CreateTextureFromSurface(renderer, imgSur7);
    Amount_imgRect7.x = 65;
    Amount_imgRect7.y = 260;
    Amount_imgRect7.w = 80;
    Amount_imgRect7.h = (int)(Amount_imgRect7.w * ((float)imgSur7->h / imgSur7->w));

    SDL_FreeSurface(imgSur7);

    SDL_Surface *imgSur8 = IMG_Load("src/ImgPro/Water_filter.png");
    Amount_imgTexture8 = SDL_CreateTextureFromSurface(renderer, imgSur8);
    Amount_imgRect8.x = 225;
    Amount_imgRect8.y = 260;
    Amount_imgRect8.w = 80;
    Amount_imgRect8.h = (int)(Amount_imgRect8.w * ((float)imgSur8->h / imgSur8->w));

    SDL_FreeSurface(imgSur8);

    SDL_Surface *imgSur9 = IMG_Load("src/ImgPro/Atmosphere.png");
    Amount_imgTexture9 = SDL_CreateTextureFromSurface(renderer, imgSur9);
    Amount_imgRect9.x = 385;
    Amount_imgRect9.y = 260;
    Amount_imgRect9.w = 80;
    Amount_imgRect9.h = (int)(Amount_imgRect9.w * ((float)imgSur9->h / imgSur9->w));

    SDL_FreeSurface(imgSur9);

    SDL_Surface *imgSur10 = IMG_Load("src/ImgPro/Air_filter.png");
    Amount_imgTexture10 = SDL_CreateTextureFromSurface(renderer, imgSur10);
    Amount_imgRect10.x = 110;
    Amount_imgRect10.y = 460;
    Amount_imgRect10.w = 110;
    Amount_imgRect10.h = (int)(Amount_imgRect10.w * ((float)imgSur10->h / imgSur10->w));

    SDL_FreeSurface(imgSur10);

    SDL_Surface *imgSur11 = IMG_Load("src/ImgPro/Smart_watch.png");
    Amount_imgTexture11 = SDL_CreateTextureFromSurface(renderer, imgSur11);
    Amount_imgRect11.x = 290;
    Amount_imgRect11.y = 460;
    Amount_imgRect11.w = 110;
    Amount_imgRect11.h = (int)(Amount_imgRect11.w * ((float)imgSur11->h / imgSur11->w));

    SDL_FreeSurface(imgSur11);


    //text

    TTF_Font *fFont1 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 45);
    SDL_Color fColor1 = {0, 0, 0, 255};
    SDL_Surface *textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, "Selling amount", fColor1, 750);
    Amount_texTexture1 = SDL_CreateTextureFromSurface(renderer, textSur1);
    Amount_texRect1.x = 140;
    Amount_texRect1.y = 30;
    Amount_texRect1.w = textSur1->w;
    Amount_texRect1.h = textSur1->h;

    SDL_FreeSurface(textSur1);

    TTF_Font *fFont2 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 30);
    SDL_Color fColor2 = {0, 0, 0, 255};
    SDL_Surface *textSur2 = TTF_RenderText_Blended_Wrapped(fFont2, "Amount", fColor2, 720);
    Amount_texTexture2 = SDL_CreateTextureFromSurface(renderer, textSur2);
    Amount_texRect2.x = 530;
    Amount_texRect2.y = 195;
    Amount_texRect2.w = textSur2->w;
    Amount_texRect2.h = textSur2->h;

    SDL_FreeSurface(textSur2);

    TTF_Font *fFont3 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 30);
    SDL_Color fColor3 = {0, 0, 0, 255};
    SDL_Surface *textSur3 = TTF_RenderText_Blended_Wrapped(fFont3, "Fix", fColor3, 720);
    Amount_texTexture3 = SDL_CreateTextureFromSurface(renderer, textSur3);
    Amount_texRect3.x = 530;
    Amount_texRect3.y = 365;
    Amount_texRect3.w = textSur3->w;
    Amount_texRect3.h = textSur3->h;

    SDL_FreeSurface(textSur3);

    TTF_Font *fFont4 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 20);
    SDL_Color fColor4 = {2, 54, 81, 255};
    SDL_Surface *textSur4 = TTF_RenderText_Blended_Wrapped(fFont3, "OK", fColor3, 720);
    Amount_texTexture4 = SDL_CreateTextureFromSurface(renderer, textSur4);
    Amount_texRect4.x = 595;
    Amount_texRect4.y = 570;
    Amount_texRect4.w = textSur4->w;
    Amount_texRect4.h = textSur4->h;
    
    SDL_FreeSurface(textSur4);
}

char Amount_productName[20];
int Amount_currentHover = 0;
int AmountSelected = 0;
char Amount_Input[10];

void SelectingItem(SDL_Renderer *renderer, struct eventTrigger *eventData){
    char numAmount[20];
    if(eventData->mouseX >= Amount_imgRect7.x && eventData->mouseX <= Amount_imgRect7.x + Amount_imgRect7.w
    && eventData->mouseY >= Amount_imgRect7.y && eventData->mouseY <= Amount_imgRect7.y + Amount_imgRect7.h){
        Amount_currentHover = 0;
        if(eventData->isTrigger == 1){
            AmountSelected = 0;
            itoa(sendingNode->produce[AmountSelected*2+1], numAmount, 10);
            strcpy(Amount_Input, numAmount);
        }
    }
    else if(eventData->mouseX >= Amount_imgRect8.x && eventData->mouseX <= Amount_imgRect8.x + Amount_imgRect8.w
    && eventData->mouseY >= Amount_imgRect8.y && eventData->mouseY <= Amount_imgRect8.y + Amount_imgRect8.h){
        Amount_currentHover = 1;
        if(eventData->isTrigger == 1){
            AmountSelected = 1;
            itoa(sendingNode->produce[AmountSelected*2+1], numAmount, 10);
            strcpy(Amount_Input, numAmount);
        }
    }else if(eventData->mouseX >= Amount_imgRect9.x && eventData->mouseX <= Amount_imgRect9.x + Amount_imgRect9.w
    && eventData->mouseY >= Amount_imgRect9.y && eventData->mouseY <= Amount_imgRect9.y + Amount_imgRect9.h){
        Amount_currentHover = 2;
        if(eventData->isTrigger == 1){
            AmountSelected = 2;
            itoa(sendingNode->produce[AmountSelected*2+1], numAmount, 10);
            strcpy(Amount_Input, numAmount);
        }
    }else if(eventData->mouseX >= Amount_imgRect10.x && eventData->mouseX <= Amount_imgRect10.x + Amount_imgRect10.w
    && eventData->mouseY >= Amount_imgRect10.y && eventData->mouseY <= Amount_imgRect10.y + Amount_imgRect10.h){
        Amount_currentHover = 3;
        if(eventData->isTrigger == 1){
            AmountSelected = 3;
            itoa(sendingNode->produce[AmountSelected*2+1], numAmount, 10);
            strcpy(Amount_Input, numAmount);
        }
    }else if(eventData->mouseX >= Amount_imgRect11.x && eventData->mouseX <= Amount_imgRect11.x + Amount_imgRect11.w
    && eventData->mouseY >= Amount_imgRect11.y && eventData->mouseY <= Amount_imgRect11.y + Amount_imgRect11.h){
        Amount_currentHover = 4;
        if(eventData->isTrigger == 1){
            AmountSelected = 4;
            itoa(sendingNode->produce[AmountSelected*2+1], numAmount, 10);
            strcpy(Amount_Input, numAmount);
        }
    }else if(eventData->mouseX >= Amount_imgRect5.x && eventData->mouseX <= Amount_imgRect5.x + Amount_imgRect5.w
    && eventData->mouseY >= Amount_imgRect5.y && eventData->mouseY <= Amount_imgRect5.y + Amount_imgRect5.h && eventData->isTrigger == 1){
        int newAddOn = (atoi(Amount_Input) - sendingNode->produce[2*AmountSelected+1]) * sendingNode->produce[2*AmountSelected];
        int newAddOnBV = (atoi(Amount_Input) - sendingNode->produce[2*AmountSelected+1]) * product[AmountSelected]->price;
        editSellAmount(sendingNode->name, atoi(Amount_Input), AmountSelected, rootOfMLM);
        sendingNode->retail += newAddOn;
        sendingNode->BV += newAddOnBV;
        sendingNode->PV = sendingNode->BV / 3.0f;
    }
}

void Amount_UserInputPrice(SDL_Renderer *renderer, struct eventTrigger *eventData){
    if(eventData->currentInput >= SDLK_0 && eventData->currentInput <= SDLK_9){
        char currentKey[2];
        currentKey[0] = eventData->currentInput - SDLK_0 + '0';
        if(strcmp(Amount_Input, "0") == 0)
            strcpy(Amount_Input, currentKey);
        else
            strcat(Amount_Input, currentKey);
    }else if(eventData->currentInput == SDLK_BACKSPACE){
        if(strlen(Amount_Input) > 1)
            Amount_Input[strlen(Amount_Input)-1] = '\0';
        else
            strcpy(Amount_Input, "0");
    }
    if(strlen(Amount_Input) == 0) strcpy(Amount_Input, "0");
    TTF_Font *fFont1 = TTF_OpenFont("src/font/Alegreya-VariableFont_wght.ttf", 30);
    SDL_Color fColor1 = {0, 0, 0, 255};
    SDL_Surface *textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, Amount_Input, fColor1, 750);
    SDL_Texture *textTex = SDL_CreateTextureFromSurface(renderer, textSur1);
    SDL_Rect textRect = {600, 440, textSur1->w, textSur1->h};

    SDL_RenderCopy(renderer, textTex, NULL, &textRect);
    TTF_CloseFont(fFont1);
    SDL_FreeSurface(textSur1);
    SDL_DestroyTexture(textTex);
}

void Amount_dataInformation(SDL_Renderer *renderer, struct eventTrigger *eventData){
    TTF_Font *fFont1 = TTF_OpenFont("src/font/Alegreya-VariableFont_wght.ttf", 30);
    SDL_Color fColor1 = {0, 0, 0, 255};
    if(Amount_currentHover == AmountSelected){
        fColor1.r = 26;
        fColor1.g = 19;
        fColor1.b = 237;
    }
    SDL_Surface *textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, sendingNode->name, fColor1, 750);
    SDL_Texture *textTex = SDL_CreateTextureFromSurface(renderer, textSur1);
    SDL_Rect textRect = {102, 134, textSur1->w, textSur1->h};

    SDL_RenderCopy(renderer, textTex, NULL, &textRect);

    fColor1.r = fColor1.g = fColor1.b = 0;

    SDL_FreeSurface(textSur1);
    SDL_DestroyTexture(textTex);
    
    textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, product[AmountSelected]->name, fColor1, 750);
    textTex = SDL_CreateTextureFromSurface(renderer, textSur1);
    SDL_Rect textRect2 = {140, 200, textSur1->w, textSur1->h};

    SDL_RenderCopy(renderer, textTex, NULL, &textRect2); 

    SDL_FreeSurface(textSur1);
    SDL_DestroyTexture(textTex);

    char amountSting[10];
    itoa(sendingNode->produce[2*AmountSelected+1], amountSting, 10);
    textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, amountSting, fColor1, 750);
    textTex = SDL_CreateTextureFromSurface(renderer, textSur1);
    SDL_Rect textRect3 = {600, 270, textSur1->w, textSur1->h};

    SDL_RenderCopy(renderer, textTex, NULL, &textRect3);

    
    SDL_FreeSurface(textSur1);
    SDL_DestroyTexture(textTex); 

    itoa(sendingNode->produce[2*AmountSelected], amountSting, 10);
    strcat(amountSting, " ***");
    textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, amountSting, fColor1, 750);
    textTex = SDL_CreateTextureFromSurface(renderer, textSur1);
    SDL_Rect textRect4 = {550, 320, textSur1->w, textSur1->h};

    SDL_RenderCopy(renderer, textTex, NULL, &textRect4);
    SDL_FreeSurface(textSur1);
    SDL_DestroyTexture(textTex); 
    TTF_CloseFont(fFont1);
}

void Amount_DrawScene(SDL_Renderer *renderer, struct eventTrigger *eventData){
    SDL_SetRenderDrawColor(renderer, 199, 231, 240, 200);
    SDL_RenderClear(renderer);

    if(eventData->mouseX >= Amount_imgRect6.x && eventData->mouseX <= Amount_imgRect6.x + Amount_imgRect6.w
    && eventData->mouseY >= Amount_imgRect6.y && eventData->mouseY <= Amount_imgRect6.y + Amount_imgRect6.h
    && eventData->isTrigger == 1){
        currentRoom = 1;
    }

    SDL_RenderCopy(renderer, Amount_imgTexture1, NULL, &Amount_imgRect1);
    SDL_RenderCopy(renderer, Amount_imgTexture2, NULL, &Amount_imgRect2);
    SDL_RenderCopy(renderer, Amount_imgTexture3, NULL, &Amount_imgRect3);
    SDL_RenderCopy(renderer, Amount_imgTexture4, NULL, &Amount_imgRect4);
    SDL_RenderCopy(renderer, Amount_imgTexture5, NULL, &Amount_imgRect5);
    SDL_RenderCopy(renderer, Amount_imgTexture6, NULL, &Amount_imgRect6);

    SDL_RenderCopy(renderer, Amount_imgTexture7, NULL, &Amount_imgRect7);
    SDL_RenderCopy(renderer, Amount_imgTexture8, NULL, &Amount_imgRect8);
    SDL_RenderCopy(renderer, Amount_imgTexture9, NULL, &Amount_imgRect9);
    SDL_RenderCopy(renderer, Amount_imgTexture10, NULL, &Amount_imgRect10);
    SDL_RenderCopy(renderer, Amount_imgTexture11, NULL, &Amount_imgRect11);

    //text
    SDL_RenderCopy(renderer, Amount_texTexture1, NULL, &Amount_texRect1);
    SDL_RenderCopy(renderer, Amount_texTexture2, NULL, &Amount_texRect2);
    SDL_RenderCopy(renderer, Amount_texTexture3, NULL, &Amount_texRect3);
    SDL_RenderCopy(renderer, Amount_texTexture4, NULL, &Amount_texRect4);
    
    SelectingItem(renderer, eventData);
    Amount_dataInformation(renderer, eventData);
    Amount_UserInputPrice(renderer, eventData);
    SDL_RenderPresent(renderer);
}