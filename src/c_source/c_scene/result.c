#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <system/scene.h>
#include <system/struct.h>
#include <system/nodeHandle.h>
#include <system/componentLoad.h>

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

// Set the extern variable corresponding to Searching components in componentLoad.h
NodePtr previousRoot = NULL;
NodePtr currentSelect = NULL;
NodePtr currentRoot = NULL;

SDL_Rect searchbarRect = {418, 41, 638-418, 73-41};
SDL_Rect searchButtonRect = {657, 38, 711-657, 73-38};

void Result_Initial(SDL_Renderer *renderer){
    currentSelect = rootOfMLM;
    currentRoot = rootOfMLM;
    
    // Define Image
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

    // Define Texts
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

void optionHandle(SDL_Renderer *renderer, struct eventTrigger *eventData){
    // Draw Options on the right of screen
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

    // when click on "Delete This Person" button
    if(isClickOnObject(eventData, Result_imgRect6) == 2){
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
    else if(isClickOnObject(eventData, Result_imgRect5) == 2){
        currentRoom = 5;
        sendingNode = currentSelect != NULL ? currentSelect : currentRoot; // Send the current node data to "Edit Selling" page
        currentSelect = currentRoot;
    }
    // when click on "Add Downline" button
    else if(isClickOnObject(eventData, Result_imgRect7) == 2){
        currentRoom = 6;
        sendingNode = currentSelect != NULL ? currentSelect : currentRoot; // Send the current node data to "Add Downline" page
        currentSelect = currentRoot;
    }
    // when click on "Reset" button
    else if(isClickOnObject(eventData, Result_imgRect8) == 2){
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
    else if(isClickOnObject(eventData, Result_imgRect4) == 2){
        currentRoom = 2;
        sendingNode = currentSelect != NULL ? currentSelect : currentRoot;
        currentSelect = NULL;
    }
    // when click on "Calculate PV and Salary" button
    else if(isClickOnObject(eventData, Result_imgRect9) == 2){
        currentRoom = 4;
        previousRoot = NULL;
        currentSelect = rootOfMLM;
        currentRoot = rootOfMLM;     
    }
}

// Seaching Function
void SearchBar(SDL_Renderer *renderer, struct eventTrigger* eventData){
    // Define Red color variable
    int isRed = 0;
    if(eventData->isTrigger == 1){
        // Check if using search bar
        if(isClickOnObject(eventData, searchbarRect) > 0){
            searchBarUsing = 1;
        }
        else{
            searchBarUsing = 0;
        }
        // when click on search button
        if(isClickOnObject(eventData, searchButtonRect) > 0){
            // if type "back", it will set the root to the last root
            if(strcmp(searchText, "back") == 0){
                NodePtr temp = currentRoot;
                currentRoot = previousRoot;
                previousRoot = temp;
            // if type "parent", it will set the root to the parent of this node
            }else if(strcmp(searchText, "parent") == 0 && currentRoot != rootOfMLM){
                previousRoot = currentRoot;
                NodePtr prevRoot = searchprevNode(rootOfMLM, currentRoot->name);
                while(prevRoot->nextSi == currentRoot){
                    currentRoot = prevRoot;
                    prevRoot = searchprevNode(rootOfMLM, currentRoot->name); 
                }
                currentRoot = prevRoot;
            }
            // Otherwise, it will set the root to the name that user type
            else{
                previousRoot = currentRoot;
                currentRoot = searchNode(rootOfMLM, searchText);
            }
        }
    }
    // When using the search bar
    if(searchBarUsing == 1){
        isRed = 1;
        // Check if keyboard input is A-Z or 0-9 (Add that letter to search bar if only if the length is less than 11)
        if((eventData->currentInput >= SDLK_a && eventData->currentInput <= SDLK_z) || (eventData->currentInput >= SDLK_0 && eventData->currentInput <= SDLK_9)){
            char alphabet[3];
            alphabet[0] = (char)(currentShift + eventData->currentInput - SDLK_a);
            alphabet[1] = '\0';
            if(strcmp(searchText, "|") == 0){
                strcpy(searchText, alphabet);
            }else if(strlen(searchText) != 10)
                strcat(searchText, alphabet);
        // Check if keyboard input is leftShift (Interchange Uppercase and Lowercase)
        }if(eventData->currentInput == SDLK_LSHIFT){
            currentShift = currentShift == 'A' ? 'a' : 'A';
        // Check if keyboard input is backspace (Delete the letter)
        }if(eventData->currentInput == SDLK_BACKSPACE){
            if(strlen(searchText)>=2)
                searchText[strlen(searchText)-1] = '\0';
            else if(strlen(searchText) == 1)
                strcpy(searchText, "|");
        }
    }

    // Create text in search bar
    SDL_Texture *searchTex;
    SDL_Rect TextRect;
    createTextTexture_Rect(renderer, &searchTex, &TextRect, (const char*) searchText, "src/font/Alegreya-VariableFont_wght.ttf", 30, isRed*255, 0, 0, 255, 425, 35);
    SDL_RenderCopy(renderer, searchTex, NULL, &TextRect);
    SDL_DestroyTexture(searchTex);
}

void Result_DrawNode(SDL_Renderer *renderer, struct eventTrigger* eventData){
    // Initial Node used for refer to current node during screen creation
    NodePtr showNode = currentRoot;
    SDL_Texture *Result_currentNameTex;
    SDL_Rect Result_currentNameRect;
    if(showNode == NULL) showNode = currentRoot = rootOfMLM;
    
    // Create the root (of subtree) node
    int isRed;
    Result_nodeRect.x = 10 + 2*Result_nodeRect.w;
    Result_nodeRect.y = 150;
    int oldW = Result_nodeRect.w;
    int bigImgW = Result_nodeRect.w = 100;
    int bigImgH = Result_nodeRect.h = (int)(Result_nodeRect.w * ((float)Result_nodeRect.h / oldW));
    isRed = currentSelect == currentRoot;
    createTextTexture_Rect(renderer, &Result_currentNameTex, &Result_currentNameRect, (const char*) showNode->name, "src/font/Alegreya-VariableFont_wght.ttf", 20, isRed*255, 0, 0, 255, 100, 180);
    SDL_RenderCopy(renderer, Result_currentNameTex, NULL, &Result_currentNameRect);
    SDL_DestroyTexture(Result_currentNameTex);

    isRed = 0;

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

    // Generate children node to screen
    showNode = showNode->child;
    while(showNode != NULL && count < 15){
        isRed = 0;

        // Don't draw any line or node when status = 0
        if(showNode->status == 0);
        // when current showNode is the node which is selected, its name will turn to red
        else if(showNode == currentSelect){
            SDL_RenderCopy(renderer, Result_nodeTexture2, NULL, &Result_nodeRect);
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            isRed = 1;
            SDL_RenderDrawLine(renderer, (10 + 2*(*Rw)) + bigImgW/2, 150 + bigImgH, *x + *Rw/2, *y);
            // Deselect the node
            if(isClickOnObject(eventData, Result_nodeRect) == 2){
                currentSelect = currentRoot;
            }
        }
        else if(isClickOnObject(eventData, Result_nodeRect) > 0){
            if(eventData->isTrigger){
                currentSelect = showNode;
                strcpy(searchText, showNode->name);
            }
            SDL_RenderCopy(renderer, Result_nodeTexture2, NULL, &Result_nodeRect);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawLine(renderer, (10 + 2*(*Rw)) + bigImgW/2, 150 + bigImgH, *x + *Rw/2, *y);
        }
        else{
            SDL_RenderCopy(renderer, Result_nodeTexture, NULL, &Result_nodeRect);
        }

        createTextTexture_Rect(renderer, &Result_currentNameTex, &Result_currentNameRect, (const char*) showNode->name, "src/font/Alegreya-VariableFont_wght.ttf", 20, isRed*255, 0, 0, 255, *x + 10, *y - 25);
        SDL_RenderCopy(renderer, Result_currentNameTex, NULL, &Result_currentNameRect);
        SDL_DestroyTexture(Result_currentNameTex);

        // Move to draw the next node
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
}

void Result_Run(SDL_Renderer *renderer, struct eventTrigger* eventData){
    // Draw Scene
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

    // Special Function (Draw Node, Search bar, Options)
    Result_DrawNode(renderer, eventData);
    SearchBar(renderer, eventData);
    optionHandle(renderer, eventData);

    SDL_RenderPresent(renderer);
}