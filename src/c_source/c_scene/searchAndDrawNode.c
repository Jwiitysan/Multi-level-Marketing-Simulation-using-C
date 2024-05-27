#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <system/componentLoad.h>
#include <system/struct.h>
#include <system/nodeHandle.h>

// Set the extern variable corresponding to Searching components in componentLoad.h
objectComponent nodeObj[2];

NodePtr previousRoot = NULL;
NodePtr currentSelect = NULL;
NodePtr currentRoot = NULL;

SDL_Rect searchbarRect = {418, 41, 638-418, 73-41};
SDL_Rect searchButtonRect = {657, 38, 711-657, 73-38};

void searchResult(){
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
        currentSelect = currentRoot;
    }
}

// Seaching Function
void SearchBar(SDL_Renderer *renderer, struct eventTrigger* eventData){
    // Create a checked object to fit into the isClickOnObject function
    objectComponent searchbarCheckObj, searchButtonCheckObj;
    searchbarCheckObj.objectRect = searchbarRect;
    searchButtonCheckObj.objectRect = searchButtonRect;

    // When press "Return" on keyboard (Search the Node)
    if(eventData->currentInput == SDLK_RETURN){
        searchResult();
    }

    // Define Red color variable
    int isRed = 0;
    if(eventData->isTrigger == 1){
        // Check if using search bar
        if(isClickOnObject(eventData, &searchbarCheckObj) > 0){
            searchBarUsing = 1;
        }
        else{
            searchBarUsing = 0;
        }
        // when click on search button
        if(isClickOnObject(eventData, &searchButtonCheckObj) > 0){
            searchResult();
        }
    }
    // When using the search bar
    if(searchBarUsing == 1){
        isRed = 1;
        // Check if keyboard input is A-Z or 0-9 (Add that letter to search bar if only if the length is less than 10)
        if(((eventData->currentInput >= SDLK_a && eventData->currentInput <= SDLK_z) || 
        (eventData->currentInput >= SDLK_0 && eventData->currentInput <= SDLK_9)) && strlen(searchText) < 10){
            char alphabet[2];
            alphabet[0] = (char)(currentShift + eventData->currentInput - SDLK_a);
            alphabet[1] = '\0';
            if(strcmp(searchText, "|") == 0){
                strcpy(searchText, alphabet);
            }else strcat(searchText, alphabet);
        // Check if keyboard input is leftShift (Interchange Uppercase and Lowercase)
        }else if(eventData->currentInput == SDLK_LSHIFT){
            currentShift = (currentShift == 'A') ? 'a' : 'A';
        // Check if keyboard input is backspace (Delete the letter)
        }else if(eventData->currentInput == SDLK_BACKSPACE){
            if(strlen(searchText)>=2)
                searchText[strlen(searchText)-1] = '\0';
            else if(strlen(searchText) == 1)
                strcpy(searchText, "|");
        }

}

    // Create text in search bar
    objectComponent searchTextObj;
    createTextTexture_Rect(renderer, &searchTextObj, (const char*) searchText, "src/font/Alegreya-VariableFont_wght.ttf", 30, isRed*255, 0, 0, 255, 425, 35);
    placeObject(renderer, &searchTextObj);

    SDL_DestroyTexture(searchTextObj.objectTexture); // Free Texture (Avoid Memory Leak)
}

void DrawNode(SDL_Renderer *renderer, struct eventTrigger* eventData){
    // Initial Node used for refer to current node during screen creation
    NodePtr showNode = currentRoot;
    objectComponent Result_currentName;
    if(showNode == NULL) showNode = currentRoot = rootOfMLM;
    
    int isRed; // Check if the node's name should be red

    // Create the root (of subtree) node
    nodeObj[0].objectRect.x = 10 + 2*nodeObj[0].objectRect.w;
    nodeObj[0].objectRect.y = 150;
    int oldW = nodeObj[0].objectRect.w;
    int bigImgW = nodeObj[0].objectRect.w = 100;
    int bigImgH = nodeObj[0].objectRect.h = (int)(nodeObj[0].objectRect.w * ((float)nodeObj[0].objectRect.h / oldW));
    isRed = currentSelect == currentRoot;
    createTextTexture_Rect(renderer, &Result_currentName, (const char*) showNode->name, "src/font/Alegreya-VariableFont_wght.ttf", 20, isRed*255, 0, 0, 255, 100, 180);
    placeObject(renderer, &Result_currentName);

    SDL_DestroyTexture(Result_currentName.objectTexture); // Free Texture (Avoid Memory Leak)

    isRed = 0;
    
    objectComponent currentObj;
    placeObject(renderer, &nodeObj[0]);

    nodeObj[0].objectRect.x = 20;
    nodeObj[0].objectRect.y = 300;
    oldW = nodeObj[0].objectRect.w;
    nodeObj[0].objectRect.w = 80;
    nodeObj[0].objectRect.h = (int)(nodeObj[0].objectRect.w * ((float)nodeObj[0].objectRect.h / oldW));

    int count = 0;
    int countX = 0;
    int* Rw = &nodeObj[0].objectRect.w;
    int* Rh = &nodeObj[0].objectRect.h;
    int* x = &nodeObj[0].objectRect.x;
    int* y = &nodeObj[0].objectRect.y;

    // Generate children node to screen
    showNode = showNode->child;
    while(showNode != NULL && count < 15){
        isRed = 0;

        // Don't draw any line or node when status = 0
        if(showNode->status == 0);
        // when current showNode is the node which is selected, its name will turn to red
        else if(showNode == currentSelect){
            nodeObj[1].objectRect = nodeObj[0].objectRect;
            placeObject(renderer, &nodeObj[1]);

            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            isRed = 1;
            SDL_RenderDrawLine(renderer, (10 + 2*(*Rw)) + bigImgW/2, 150 + bigImgH, *x + *Rw/2, *y);
            // Deselect the node
            if(isClickOnObject(eventData, &nodeObj[0]) == 2){
                currentSelect = currentRoot;
            }
        }
        // Check if hovering the current showNode
        else if(isClickOnObject(eventData, &nodeObj[0]) > 0){
            if(eventData->isTrigger){
                currentSelect = showNode;
                strcpy(searchText, showNode->name);
            }
            nodeObj[1].objectRect = nodeObj[0].objectRect;
            placeObject(renderer, &nodeObj[1]);

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawLine(renderer, (10 + 2*(*Rw)) + bigImgW/2, 150 + bigImgH, *x + *Rw/2, *y);
        }
        else{
            placeObject(renderer, &nodeObj[0]);
        }

        createTextTexture_Rect(renderer, &Result_currentName, (const char*) showNode->name, "src/font/Alegreya-VariableFont_wght.ttf", 20, isRed*255, 0, 0, 255, *x + 10, *y - 25);
        placeObject(renderer, &Result_currentName);
        SDL_DestroyTexture(Result_currentName.objectTexture);

        // Move to draw the next node
        nodeObj[0].objectRect.x += nodeObj[0].objectRect.w;
        countX++;
        if(countX == 5){
            nodeObj[0].objectRect.x = 20;
            nodeObj[0].objectRect.y += nodeObj[0].objectRect.h + 20;
            countX = 0;
        }
        count++;
        showNode = showNode->nextSi;
    }
}