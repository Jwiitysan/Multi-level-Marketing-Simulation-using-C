#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <system/scene.h>
#include <system/struct.h>
#include <system/nodeHandle.h>
#include <system/componentLoad.h>

#define NEWDOWN_IMG_AMOUNT 14
#define NEWDOWN_TEXT_AMOUNT 5

// Declare Varibles
objectComponent NewDownline_imgObj[NEWDOWN_IMG_AMOUNT];
objectComponent NewDownline_textObj[NEWDOWN_TEXT_AMOUNT];

void NewDownline_Initial(SDL_Renderer *renderer){

    // Define Images
    createIMGTexture_Rect(renderer, &NewDownline_imgObj[0], "src/image/NewDownline_Name.png", 160, 130, 300, -1);

    createIMGTexture_Rect(renderer, &NewDownline_imgObj[1], "src/image/eSpring.png", 50, 280, 50, -1);
    createIMGTexture_Rect(renderer, &NewDownline_imgObj[2], "src/image/Water_filter.png", 50, 405, 50, -1);
    createIMGTexture_Rect(renderer, &NewDownline_imgObj[3], "src/image/Atmosphere.png", 50, 535, 50, -1);
    createIMGTexture_Rect(renderer, &NewDownline_imgObj[4], "src/image/Air_filter.png", 390, 282, 70, -1);
    createIMGTexture_Rect(renderer, &NewDownline_imgObj[5], "src/image/Smart_watch.png", 390, 415, 70, -1);

    createIMGTexture_Rect(renderer, &NewDownline_imgObj[6], "src/image/NewDownline_Block.png", 135, 300, 200, 50);
    createIMGTexture_Rect(renderer, &NewDownline_imgObj[7], "src/image/NewDownline_Block.png", 135, 430, 200, 50);
    createIMGTexture_Rect(renderer, &NewDownline_imgObj[8], "src/image/NewDownline_Block.png", 135, 555, 200, 50);
    createIMGTexture_Rect(renderer, &NewDownline_imgObj[9], "src/image/NewDownline_Block.png", 500, 300, 200, 50);
    createIMGTexture_Rect(renderer, &NewDownline_imgObj[10], "src/image/NewDownline_Block.png", 500, 430, 200, 50);

    createIMGTexture_Rect(renderer, &NewDownline_imgObj[11], "src/image/NewDownline_Random.png", 600, 200, 100, -1);
    createIMGTexture_Rect(renderer, &NewDownline_imgObj[12], "src/image/NewDownline_Cancel.png", 30, 680, 150, -1);
    createIMGTexture_Rect(renderer, &NewDownline_imgObj[13], "src/image/NewDownline_Submit.png", 570, 665, 150, -1);
    
    // Define Texts
    createTextTexture_Rect(renderer, &NewDownline_textObj[0], "New Downline", "src/font/HoltwoodOneSC-Regular.ttf", 55, 0, 0, 0, 255, 100, 15);
    createTextTexture_Rect(renderer, &NewDownline_textObj[1], "NAME", "src/font/HoltwoodOneSC-Regular.ttf", 30, 0, 0, 0, 255, 30, 130);
    createTextTexture_Rect(renderer, &NewDownline_textObj[2], "Sell Amount", "src/font/HoltwoodOneSC-Regular.ttf", 30, 0, 0, 0, 255, 50, 210);
    createTextTexture_Rect(renderer, &NewDownline_textObj[3], "Cancel", "src/font/HoltwoodOneSC-Regular.ttf", 15, 0, 0, 0, 255, 48, 687);
    createTextTexture_Rect(renderer, &NewDownline_textObj[4], "Submit", "src/font/HoltwoodOneSC-Regular.ttf", 15, 0, 0, 0, 255, 610, 682);
}

// The function handles display and user input data for creating a new node
int selecting = 0;
char NDL_UsernameLine[12] = "AB";
char NDLAmount1[6] = "0";
char NDLAmount2[6] = "0";
char NDLAmount3[6] = "0";
char NDLAmount4[6] = "0";
char NDLAmount5[6] = "0";

void NewDownlineInputData(SDL_Renderer *renderer, struct eventTrigger *eventData){
    objectComponent text;
    
    // Show the current string in Username bar
    int isRed = selecting == 0;
    createTextTexture_Rect(renderer, &text, (const char*) NDL_UsernameLine, "src/font/Alegreya-VariableFont_wght.ttf", 30, isRed*255, 0, 0, 255, 248, 130);
    placeObject(renderer, &text);
    SDL_DestroyTexture(text.objectTexture);

    // Show the current string in eSpring bar
    isRed = selecting == 1;
    createTextTexture_Rect(renderer, &text, (const char*) NDLAmount1, "src/font/Alegreya-VariableFont_wght.ttf", 30, isRed*255, 0, 0, 255, 155, 303);
    placeObject(renderer, &text);
    SDL_DestroyTexture(text.objectTexture);

    // Show the current string in Water filter bar
    isRed = selecting == 2;
    createTextTexture_Rect(renderer, &text, (const char*) NDLAmount2, "src/font/Alegreya-VariableFont_wght.ttf", 30, isRed*255, 0, 0, 255, 155, 435);
    placeObject(renderer, &text);
    SDL_DestroyTexture(text.objectTexture);

    // Show the current string in Atmosphere bar
    isRed = selecting == 3;
    createTextTexture_Rect(renderer, &text, (const char*) NDLAmount3, "src/font/Alegreya-VariableFont_wght.ttf", 30, isRed*255, 0, 0, 255, 155, 560);
    placeObject(renderer, &text);
    SDL_DestroyTexture(text.objectTexture);

    // Show the current string in Air Filter bar
    isRed = selecting == 4;
    createTextTexture_Rect(renderer, &text, (const char*) NDLAmount4, "src/font/Alegreya-VariableFont_wght.ttf", 30, isRed*255, 0, 0, 255, 520, 303);
    placeObject(renderer, &text);
    SDL_DestroyTexture(text.objectTexture);

    // Show the current string in Smart Watch bar
    isRed = selecting == 5;
    createTextTexture_Rect(renderer, &text, (const char*) NDLAmount5, "src/font/Alegreya-VariableFont_wght.ttf", 30, isRed*255, 0, 0, 255, 520, 435);
    placeObject(renderer, &text);
    SDL_DestroyTexture(text.objectTexture);

    /*
        Selecting Item (selecting)
        0 -> Username bar
        1-5 -> The same order as the upper code
    */
    if(isClickOnObject(eventData, &NewDownline_imgObj[0]) == 2){
        selecting = 0;
    }else if(isClickOnObject(eventData, &NewDownline_imgObj[6]) == 2){
        selecting = 1;
    }else if(isClickOnObject(eventData, &NewDownline_imgObj[7]) == 2){
        selecting = 2;
    }else if(isClickOnObject(eventData, &NewDownline_imgObj[8]) == 2){
        selecting = 3;
    }else if(isClickOnObject(eventData, &NewDownline_imgObj[9]) == 2){
        selecting = 4;
    }else if(isClickOnObject(eventData, &NewDownline_imgObj[10]) == 2){
        selecting = 5;
    
    // Check if click "Random" icon (random amount of selling)
    }else if(isClickOnObject(eventData, &NewDownline_imgObj[11]) == 2){
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
    // Check if click "Submit" (Create new child node and set the selected node to root)
    }else if(isClickOnObject(eventData, &NewDownline_imgObj[13]) == 2){
        rootOfMLM = addNode(rootOfMLM, sendingNode->name, NDL_UsernameLine);
        NodePtr setNode = searchNode(rootOfMLM, NDL_UsernameLine);
        setNode->produce[1] = atoi(NDLAmount1);
        setNode->produce[0] = product[0]->price * (1 + rand()%8)/100.0f;
        setNode->produce[3] = atoi(NDLAmount2);
        setNode->produce[2] = product[1]->price * (1 + rand()%8)/100.0f;
        setNode->produce[5] = atoi(NDLAmount3);
        setNode->produce[4] = product[2]->price * (1 + rand()%8)/100.0f;
        setNode->produce[7] = atoi(NDLAmount4);
        setNode->produce[6] = product[3]->price * (1 + rand()%8)/100.0f;
        setNode->produce[9] = atoi(NDLAmount5);
        setNode->produce[8] = product[4]->price * (1 + rand()%8)/100.0f;

        writeFile(rootOfMLM);

        currentSelect = sendingNode;
        currentRoot = currentSelect;
        currentRoom = 1; 

    // Check if click "Back" (Return to "Result" page)
    }else if(isClickOnObject(eventData, &NewDownline_imgObj[12]) == 2){
        currentRoom = 1;
    }

    // Check if selecting "Username" bar (Keyboard control)
    if(selecting == 0){
        if(eventData->currentInput >= SDLK_a && eventData->currentInput <= SDLK_z && strlen(NDL_UsernameLine) <= 10){ // Only A-Z or a-z
            // Create string to store only 1 character (Use for strcat)
            char alphabet[3];
            alphabet[0] = (char)(currentShift + eventData->currentInput - SDLK_a);
            alphabet[1] = '\0';

            if(strcmp(NDL_UsernameLine, "|") == 0){
                strcpy(NDL_UsernameLine, alphabet);
            }else if(strlen(NDL_UsernameLine) != 10)
                strcat(NDL_UsernameLine, alphabet);
        }if(eventData->currentInput == SDLK_LSHIFT){
            currentShift = currentShift == 'A' ? 'a' : 'A';
        }if(eventData->currentInput == SDLK_BACKSPACE){
            if(strlen(NDL_UsernameLine)>=2)
                NDL_UsernameLine[strlen(NDL_UsernameLine)-1] = '\0';
            else if(strlen(NDL_UsernameLine) == 1)
                strcpy(NDL_UsernameLine, "|");
        }
    }
    // Check if selecting Product Selling Amount bar (Keyboard control)
    else{
        // Define this variable so that it can be used in all cases
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
            // Create string to store only 1 character (Use for strcat)
            char alphabet[3];
            alphabet[0] = (char)('0' + eventData->currentInput - SDLK_0);
            alphabet[1] = '\0';

            if(strcmp(NDLAmountUsing, "0") == 0){
                strcpy(NDLAmountUsing, alphabet);
            }else if(strlen(NDLAmountUsing) != 4){
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

void NewDownline_Run(SDL_Renderer *renderer, struct eventTrigger *eventData){
    // Draw Scene
    SDL_SetRenderDrawColor(renderer, 199, 231, 240, 200);
    SDL_RenderClear(renderer);

    for(int i=0; i<NEWDOWN_IMG_AMOUNT; i++){
        placeObject(renderer, &NewDownline_imgObj[i]);
    }
    for(int i=0; i<NEWDOWN_TEXT_AMOUNT; i++){
        placeObject(renderer, &NewDownline_textObj[i]);
    }

    NewDownlineInputData(renderer, eventData);

    
    SDL_RenderPresent(renderer);
}