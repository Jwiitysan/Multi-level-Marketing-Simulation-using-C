#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <system/scene.h>
#include <system/struct.h>
#include <string.h>
#include <system/nodeHandle.h>

//image
SDL_Rect NewDownline_imgRect1;
SDL_Texture *NewDownline_imgTexture1;
SDL_Rect NewDownline_imgRect2;
SDL_Texture *NewDownline_imgTexture2;
SDL_Rect NewDownline_imgRect3;
SDL_Texture *NewDownline_imgTexture3;
SDL_Rect NewDownline_imgRect4;
SDL_Texture *NewDownline_imgTexture4;
SDL_Rect NewDownline_imgRect5;
SDL_Texture *NewDownline_imgTexture5;
SDL_Rect NewDownline_imgRect6;
SDL_Texture *NewDownline_imgTexture6;
SDL_Rect NewDownline_imgRect7;
SDL_Texture *NewDownline_imgTexture7;
SDL_Rect NewDownline_imgRect8;
SDL_Texture *NewDownline_imgTexture8;
SDL_Rect NewDownline_imgRect9;
SDL_Texture *NewDownline_imgTexture9;
SDL_Rect NewDownline_imgRect10;
SDL_Texture *NewDownline_imgTexture10;
SDL_Rect NewDownline_imgRect11;
SDL_Texture *NewDownline_imgTexture11;
SDL_Rect NewDownline_imgRect12;
SDL_Texture *NewDownline_imgTexture12;
SDL_Rect NewDownline_imgRect13;
SDL_Texture *NewDownline_imgTexture13;
SDL_Rect NewDownline_imgRect14;
SDL_Texture *NewDownline_imgTexture14;




//text
SDL_Texture *NewDownline_texTexture1;
SDL_Rect NewDownline_texRect1;
SDL_Texture *NewDownline_texTexture2;
SDL_Rect NewDownline_texRect2;
SDL_Texture *NewDownline_texTexture3;
SDL_Rect NewDownline_texRect3;
SDL_Texture *NewDownline_texTexture4;
SDL_Rect NewDownline_texRect4;
SDL_Texture *NewDownline_texTexture5;
SDL_Rect NewDownline_texRect5;




void NewDownline_Initial(SDL_Renderer *renderer){

    //image

    SDL_Surface *imgSur1 = IMG_Load("src/image/NewDownline_Name.png");
    NewDownline_imgTexture1 = SDL_CreateTextureFromSurface(renderer, imgSur1);
    NewDownline_imgRect1.x = 160;
    NewDownline_imgRect1.y = 130;
    NewDownline_imgRect1.w = 300;
    NewDownline_imgRect1.h = (int)(NewDownline_imgRect1.w * ((float)imgSur1->h / imgSur1->w));

    //Sell Amount
    SDL_Surface *imgSur2 = IMG_Load("src/image/eSpring.png");
    NewDownline_imgTexture2 = SDL_CreateTextureFromSurface(renderer, imgSur2);
    NewDownline_imgRect2.x = 50;
    NewDownline_imgRect2.y = 280;
    NewDownline_imgRect2.w = 50;
    NewDownline_imgRect2.h = (int)(NewDownline_imgRect2.w * ((float)imgSur2->h / imgSur2->w));

    SDL_Surface *imgSur3 = IMG_Load("src/image/Water_filter.png");
    NewDownline_imgTexture3 = SDL_CreateTextureFromSurface(renderer, imgSur3);
    NewDownline_imgRect3.x = 50;
    NewDownline_imgRect3.y = 405;
    NewDownline_imgRect3.w = 50;
    NewDownline_imgRect3.h = (int)(NewDownline_imgRect3.w * ((float)imgSur3->h / imgSur3->w));

    SDL_Surface *imgSur4 = IMG_Load("src/image/Atmosphere.png");
    NewDownline_imgTexture4 = SDL_CreateTextureFromSurface(renderer, imgSur4);
    NewDownline_imgRect4.x = 50;
    NewDownline_imgRect4.y = 535;
    NewDownline_imgRect4.w = 50;
    NewDownline_imgRect4.h = (int)(NewDownline_imgRect4.w * ((float)imgSur4->h / imgSur4->w));

    SDL_Surface *imgSur5 = IMG_Load("src/image/Air_filter.png");
    NewDownline_imgTexture5 = SDL_CreateTextureFromSurface(renderer, imgSur5);
    NewDownline_imgRect5.x = 390;
    NewDownline_imgRect5.y = 282;
    NewDownline_imgRect5.w = 70;
    NewDownline_imgRect5.h = (int)(NewDownline_imgRect5.w * ((float)imgSur5->h / imgSur5->w));

    SDL_Surface *imgSur6 = IMG_Load("src/image/Smart_watch.png");
    NewDownline_imgTexture6 = SDL_CreateTextureFromSurface(renderer, imgSur6);
    NewDownline_imgRect6.x = 390;
    NewDownline_imgRect6.y = 415;
    NewDownline_imgRect6.w = 70;
    NewDownline_imgRect6.h = (int)(NewDownline_imgRect6.w * ((float)imgSur6->h / imgSur6->w));

    //block sell amount
    SDL_Surface *imgSur7 = IMG_Load("src/image/NewDownline_Block.png");
    NewDownline_imgTexture7 = SDL_CreateTextureFromSurface(renderer, imgSur7);
    NewDownline_imgRect7.x = 135;
    NewDownline_imgRect7.y = 300;
    NewDownline_imgRect7.w = 200;
    NewDownline_imgRect7.h = 50;

    SDL_Surface *imgSur8 = IMG_Load("src/image/NewDownline_Block.png");
    NewDownline_imgTexture8 = SDL_CreateTextureFromSurface(renderer, imgSur8);
    NewDownline_imgRect8.x = 135;
    NewDownline_imgRect8.y = 430;
    NewDownline_imgRect8.w = 200;
    NewDownline_imgRect8.h = 50;

    SDL_Surface *imgSur9 = IMG_Load("src/image/NewDownline_Block.png");
    NewDownline_imgTexture9 = SDL_CreateTextureFromSurface(renderer, imgSur9);
    NewDownline_imgRect9.x = 135;
    NewDownline_imgRect9.y = 555;
    NewDownline_imgRect9.w = 200;
    NewDownline_imgRect9.h = 50;

    SDL_Surface *imgSur10 = IMG_Load("src/image/NewDownline_Block.png");
    NewDownline_imgTexture10 = SDL_CreateTextureFromSurface(renderer, imgSur10);
    NewDownline_imgRect10.x = 500;
    NewDownline_imgRect10.y = 300;
    NewDownline_imgRect10.w = 200;
    NewDownline_imgRect10.h = 50;

    SDL_Surface *imgSur11 = IMG_Load("src/image/NewDownline_Block.png");
    NewDownline_imgTexture11 = SDL_CreateTextureFromSurface(renderer, imgSur11);
    NewDownline_imgRect11.x = 500;
    NewDownline_imgRect11.y = 430;
    NewDownline_imgRect11.w = 200;
    NewDownline_imgRect11.h = 50;

    //option

    SDL_Surface *imgSur12 = IMG_Load("src/image/NewDownline_Random.png");
    NewDownline_imgTexture12 = SDL_CreateTextureFromSurface(renderer, imgSur12);
    NewDownline_imgRect12.x = 600;
    NewDownline_imgRect12.y = 200;
    NewDownline_imgRect12.w = 100;
    NewDownline_imgRect12.h = (int)(NewDownline_imgRect12.w * ((float)imgSur12->h / imgSur12->w));

    SDL_Surface *imgSur13 = IMG_Load("src/image/NewDownline_Cancel.png");
    NewDownline_imgTexture13 = SDL_CreateTextureFromSurface(renderer, imgSur13);
    NewDownline_imgRect13.x = 30;
    NewDownline_imgRect13.y = 680;
    NewDownline_imgRect13.w = 150;
    NewDownline_imgRect13.h = (int)(NewDownline_imgRect13.w * ((float)imgSur13->h / imgSur13->w));

    SDL_Surface *imgSur14 = IMG_Load("src/image/NewDownline_Submit.png");
    NewDownline_imgTexture14 = SDL_CreateTextureFromSurface(renderer, imgSur14);
    NewDownline_imgRect14.x = 570;
    NewDownline_imgRect14.y = 665;
    NewDownline_imgRect14.w = 150;
    NewDownline_imgRect14.h = (int)(NewDownline_imgRect14.w * ((float)imgSur14->h / imgSur14->w));





    //text

    TTF_Font *fFont1 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 55);
    SDL_Color fColor1 = {0, 0, 0, 255};
    SDL_Surface *textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, "New Downline", fColor1, 750);
    NewDownline_texTexture1 = SDL_CreateTextureFromSurface(renderer, textSur1);
    NewDownline_texRect1.x = 100;
    NewDownline_texRect1.y = 15;
    NewDownline_texRect1.w = textSur1->w;
    NewDownline_texRect1.h = textSur1->h;

    TTF_Font *fFont2 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 30);
    SDL_Color fColor2 = {0, 0, 0, 255};
    SDL_Surface *textSur2 = TTF_RenderText_Blended_Wrapped(fFont2, "NAME", fColor2, 750);
    NewDownline_texTexture2 = SDL_CreateTextureFromSurface(renderer, textSur2);
    NewDownline_texRect2.x = 30;
    NewDownline_texRect2.y = 130;
    NewDownline_texRect2.w = textSur2->w;
    NewDownline_texRect2.h = textSur2->h;

    TTF_Font *fFont3 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 30);
    SDL_Color fColor3 = {0, 0, 0, 255};
    SDL_Surface *textSur3 = TTF_RenderText_Blended_Wrapped(fFont3, "Sell Amount", fColor3, 750);
    NewDownline_texTexture3 = SDL_CreateTextureFromSurface(renderer, textSur3);
    NewDownline_texRect3.x = 50;
    NewDownline_texRect3.y = 210;
    NewDownline_texRect3.w = textSur3->w;
    NewDownline_texRect3.h = textSur3->h;

    TTF_Font *fFont4 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 15);
    SDL_Color fColor4 = {0, 0, 0, 255};
    SDL_Surface *textSur4 = TTF_RenderText_Blended_Wrapped(fFont4, "Cancel", fColor4, 750);
    NewDownline_texTexture4 = SDL_CreateTextureFromSurface(renderer, textSur4);
    NewDownline_texRect4.x = 48;
    NewDownline_texRect4.y = 687;
    NewDownline_texRect4.w = textSur4->w;
    NewDownline_texRect4.h = textSur4->h;

    TTF_Font *fFont5 = TTF_OpenFont("src/font/HoltwoodOneSC-Regular.ttf", 15);
    SDL_Color fColor5 = {0, 0, 0, 255};
    SDL_Surface *textSur5 = TTF_RenderText_Blended_Wrapped(fFont5, "Submit", fColor5, 750);
    NewDownline_texTexture5 = SDL_CreateTextureFromSurface(renderer, textSur5);
    NewDownline_texRect5.x = 610;
    NewDownline_texRect5.y = 682;
    NewDownline_texRect5.w = textSur5->w;
    NewDownline_texRect5.h = textSur5->h;



}

int selecting = 0;
char NDL_UsernameLine[12] = "AB";
char NDLAmount1[5] = "0";
char NDLAmount2[5] = "0";
char NDLAmount3[5] = "0";
char NDLAmount4[5] = "0";
char NDLAmount5[5] = "0";
char NDL_currentShift = 'a';


void NewDownlineInputData(SDL_Renderer *renderer, struct eventTrigger *eventData){
    TTF_Font *fFont1 = TTF_OpenFont("src/font/Alegreya-VariableFont_wght.ttf", 30);
    SDL_Color fColor1 = {0, 0, 0, 255};
    if(selecting == 0) fColor1.r = 255;
    SDL_Surface *textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, NDL_UsernameLine, fColor1, 750);
    SDL_Texture *textTex = SDL_CreateTextureFromSurface(renderer, textSur1);
    SDL_Rect textRect = {248, 130, textSur1->w, textSur1->h};

    SDL_RenderCopy(renderer, textTex, NULL, &textRect);
    SDL_FreeSurface(textSur1);
    SDL_DestroyTexture(textTex);

    fColor1.r = 0;
    if(selecting == 1) fColor1.r = 255;
    textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, NDLAmount1, fColor1, 750);
    textTex = SDL_CreateTextureFromSurface(renderer, textSur1);
    SDL_Rect textRect2 = {155, 303, textSur1->w, textSur1->h};

    SDL_RenderCopy(renderer, textTex, NULL, &textRect2);
    SDL_FreeSurface(textSur1);
    SDL_DestroyTexture(textTex);

    fColor1.r = 0;
    if(selecting == 2) fColor1.r = 255;
    textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, NDLAmount2, fColor1, 750);
    textTex = SDL_CreateTextureFromSurface(renderer, textSur1);
    SDL_Rect textRect3 = {155, 435, textSur1->w, textSur1->h};

    SDL_RenderCopy(renderer, textTex, NULL, &textRect3);
    SDL_FreeSurface(textSur1);
    SDL_DestroyTexture(textTex);

    fColor1.r = 0;
    if(selecting == 3) fColor1.r = 255;
    textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, NDLAmount3, fColor1, 750);
    textTex = SDL_CreateTextureFromSurface(renderer, textSur1);
    SDL_Rect textRect4 = {155, 560, textSur1->w, textSur1->h};

    SDL_RenderCopy(renderer, textTex, NULL, &textRect4);
    SDL_FreeSurface(textSur1);
    SDL_DestroyTexture(textTex);

    fColor1.r = 0;
    if(selecting == 4) fColor1.r = 255;
    textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, NDLAmount4, fColor1, 750);
    textTex = SDL_CreateTextureFromSurface(renderer, textSur1);
    SDL_Rect textRect5 = {520, 303, textSur1->w, textSur1->h};

    SDL_RenderCopy(renderer, textTex, NULL, &textRect5);
    SDL_FreeSurface(textSur1);
    SDL_DestroyTexture(textTex);

    fColor1.r = 0;
    if(selecting == 5) fColor1.r = 255;
    textSur1 = TTF_RenderText_Blended_Wrapped(fFont1, NDLAmount5, fColor1, 750);
    textTex = SDL_CreateTextureFromSurface(renderer, textSur1);
    SDL_Rect textRect6 = {520, 435, textSur1->w, textSur1->h};

    SDL_RenderCopy(renderer, textTex, NULL, &textRect6);
    SDL_FreeSurface(textSur1);
    SDL_DestroyTexture(textTex);

    TTF_CloseFont(fFont1);

    if(eventData->isTrigger == 1){
        if(eventData->mouseX >= NewDownline_imgRect1.x && eventData->mouseX <= NewDownline_imgRect1.x + NewDownline_imgRect1.w &&
        eventData->mouseY >= NewDownline_imgRect1.y && eventData->mouseY <= NewDownline_imgRect1.y + NewDownline_imgRect1.h){
            selecting = 0;
        }
        else if(eventData->mouseX >= NewDownline_imgRect7.x && eventData->mouseX <= NewDownline_imgRect7.x + NewDownline_imgRect7.w &&
        eventData->mouseY >= NewDownline_imgRect7.y && eventData->mouseY <= NewDownline_imgRect7.y + NewDownline_imgRect7.h){
            selecting = 1;
        }else if(eventData->mouseX >= NewDownline_imgRect8.x && eventData->mouseX <= NewDownline_imgRect8.x + NewDownline_imgRect8.w &&
        eventData->mouseY >= NewDownline_imgRect8.y && eventData->mouseY <= NewDownline_imgRect8.y + NewDownline_imgRect8.h){
            selecting = 2;
        }else if(eventData->mouseX >= NewDownline_imgRect9.x && eventData->mouseX <= NewDownline_imgRect9.x + NewDownline_imgRect9.w &&
        eventData->mouseY >= NewDownline_imgRect9.y && eventData->mouseY <= NewDownline_imgRect9.y + NewDownline_imgRect9.h){
            selecting = 3;
        }else if(eventData->mouseX >= NewDownline_imgRect10.x && eventData->mouseX <= NewDownline_imgRect10.x + NewDownline_imgRect10.w &&
        eventData->mouseY >= NewDownline_imgRect10.y && eventData->mouseY <= NewDownline_imgRect10.y + NewDownline_imgRect10.h){
            selecting = 4;
        }else if(eventData->mouseX >= NewDownline_imgRect11.x && eventData->mouseX <= NewDownline_imgRect11.x + NewDownline_imgRect11.w &&
        eventData->mouseY >= NewDownline_imgRect11.y && eventData->mouseY <= NewDownline_imgRect11.y + NewDownline_imgRect11.h){
            selecting = 5;
        }
        else if(eventData->mouseX >= NewDownline_imgRect12.x && eventData->mouseX <= NewDownline_imgRect12.x + NewDownline_imgRect12.w &&
        eventData->mouseY >= NewDownline_imgRect12.y && eventData->mouseY <= NewDownline_imgRect12.y + NewDownline_imgRect12.h){
            int RandNum;
            RandNum = rand()%10;
            itoa(RandNum, NDLAmount1 , 10);
            RandNum = rand()%10;
            itoa(RandNum, NDLAmount2 , 10);
            RandNum = rand()%10;
            itoa(RandNum, NDLAmount3 , 10);
            RandNum = rand()%10;
            itoa(RandNum, NDLAmount4 , 10);
            RandNum = rand()%10;
            itoa(RandNum, NDLAmount5 , 10);
        }
        //Image 14
        else if(eventData->mouseX >= NewDownline_imgRect14.x && eventData->mouseX <= NewDownline_imgRect14.x + NewDownline_imgRect14.w &&
        eventData->mouseY >= NewDownline_imgRect14.y && eventData->mouseY <= NewDownline_imgRect14.y + NewDownline_imgRect14.h && strlen(NDL_UsernameLine) != 0){
            rootOfMLM = addNode(rootOfMLM, sendingNode->name, NDL_UsernameLine);
            NodePtr setNode = searchNode(rootOfMLM, NDL_UsernameLine);
            setNode->produce[1] = atoi(NDLAmount1);
            setNode->produce[0] = product[0]->price * rand()%8/100.0f;
            setNode->produce[3] = atoi(NDLAmount2);
             setNode->produce[2] = product[1]->price * rand()%8/100.0f;
            setNode->produce[5] = atoi(NDLAmount3);
             setNode->produce[4] = product[2]->price * rand()%8/100.0f;
            setNode->produce[7] = atoi(NDLAmount4);
             setNode->produce[6] = product[3]->price * rand()%8/100.0f;
            setNode->produce[9] = atoi(NDLAmount5);
             setNode->produce[8] = product[4]->price * rand()%8/100.0f;

            writeFile(rootOfMLM);
            currentRoom = 1;               
        }
        else if(eventData->mouseX >= NewDownline_imgRect13.x && eventData->mouseX <= NewDownline_imgRect13.x + NewDownline_imgRect13.w &&
        eventData->mouseY >= NewDownline_imgRect13.y && eventData->mouseY <= NewDownline_imgRect13.y + NewDownline_imgRect13.h){
            currentRoom = 1;              
        }
    }

    if(selecting == 0){
        if(eventData->currentInput >= SDLK_a && eventData->currentInput <= SDLK_z && strlen(NDL_UsernameLine) <= 10){
            char alphabet[3];
            alphabet[0] = (char)(NDL_currentShift + eventData->currentInput - SDLK_a);
            alphabet[1] = '\0';
            if(strcmp(NDL_UsernameLine, "|") == 0){
                strcpy(NDL_UsernameLine, alphabet);
            }else
                strcat(NDL_UsernameLine, alphabet);
        }if(eventData->currentInput == SDLK_LSHIFT){
            NDL_currentShift = NDL_currentShift == 'A' ? 'a' : 'A';
        }if(eventData->currentInput == SDLK_BACKSPACE){
            if(strlen(NDL_UsernameLine)>=2)
                NDL_UsernameLine[strlen(NDL_UsernameLine)-1] = '\0';
            else if(strlen(NDL_UsernameLine) == 1)
                strcpy(NDL_UsernameLine, "|");
        }
    }
    else{
        char *NDLAmountUsing;
        switch(selecting){
            case 1:
                NDLAmountUsing = NDLAmount1;
                break;
            case 2:
                NDLAmountUsing = NDLAmount2;
                break;
            case 3:
                NDLAmountUsing = NDLAmount3;
                break;
            case 4:
                NDLAmountUsing = NDLAmount4;
                break;
            case 5:
                NDLAmountUsing = NDLAmount5;
                break;
        }
        if(eventData->currentInput >= SDLK_0 && eventData->currentInput <= SDLK_9){
            char alphabet[3];
            alphabet[0] = (char)('0' + eventData->currentInput - SDLK_0);
            alphabet[1] = '\0';
            if(strcmp(NDLAmountUsing, "0") == 0){
                strcpy(NDLAmountUsing, alphabet);
            }else{
                strcat(NDLAmountUsing, alphabet);
            }
        }if(eventData->currentInput == SDLK_BACKSPACE){
            if(strlen(NDLAmountUsing)>=2)
                NDLAmountUsing[strlen(NDLAmountUsing)-1] = '\0';
            else if(strlen(NDLAmountUsing) == 1)
                strcpy(NDLAmountUsing, "0");
        }
    }
}

void NewDownline_DrawScene(SDL_Renderer *renderer, struct eventTrigger *eventData){
    SDL_SetRenderDrawColor(renderer, 199, 231, 240, 200); //217,241,255
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, NewDownline_imgTexture1, NULL, &NewDownline_imgRect1);
    SDL_RenderCopy(renderer, NewDownline_imgTexture2, NULL, &NewDownline_imgRect2);
    SDL_RenderCopy(renderer, NewDownline_imgTexture3, NULL, &NewDownline_imgRect3);
    SDL_RenderCopy(renderer, NewDownline_imgTexture4, NULL, &NewDownline_imgRect4);
    SDL_RenderCopy(renderer, NewDownline_imgTexture5, NULL, &NewDownline_imgRect5);
    SDL_RenderCopy(renderer, NewDownline_imgTexture6, NULL, &NewDownline_imgRect6);
    SDL_RenderCopy(renderer, NewDownline_imgTexture7, NULL, &NewDownline_imgRect7);
    SDL_RenderCopy(renderer, NewDownline_imgTexture8, NULL, &NewDownline_imgRect8);
    SDL_RenderCopy(renderer, NewDownline_imgTexture9, NULL, &NewDownline_imgRect9);
    SDL_RenderCopy(renderer, NewDownline_imgTexture10, NULL, &NewDownline_imgRect10);
    SDL_RenderCopy(renderer, NewDownline_imgTexture11, NULL, &NewDownline_imgRect11);
    SDL_RenderCopy(renderer, NewDownline_imgTexture12, NULL, &NewDownline_imgRect12);
    SDL_RenderCopy(renderer, NewDownline_imgTexture13, NULL, &NewDownline_imgRect13);
    SDL_RenderCopy(renderer, NewDownline_imgTexture14, NULL, &NewDownline_imgRect14);
    

    SDL_RenderCopy(renderer, NewDownline_texTexture1, NULL, &NewDownline_texRect1);
    SDL_RenderCopy(renderer, NewDownline_texTexture2, NULL, &NewDownline_texRect2);
    SDL_RenderCopy(renderer, NewDownline_texTexture3, NULL, &NewDownline_texRect3);
    SDL_RenderCopy(renderer, NewDownline_texTexture4, NULL, &NewDownline_texRect4);
    SDL_RenderCopy(renderer, NewDownline_texTexture5, NULL, &NewDownline_texRect5);

    NewDownlineInputData(renderer, eventData);

    
    SDL_RenderPresent(renderer);
}