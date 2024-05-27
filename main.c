#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <system/struct.h>
#include <system/nodeHandle.h>
#include <system/scene.h>
#include <system/componentLoad.h>

// Set the default value of the extern variable in struct.h
int currentRoom = 0;
NodePtr rootOfMLM = NULL;
NodePtr sendingNode = NULL;

// Set the default value of the extern variable (SearchBar) in componentLoad.h
char searchText[10] = "NULL";
int searchBarUsing = 0;
char currentShift = 'a';

// The function which use to reset the eventData in each round of loop
void resetEventTrigger(struct eventTrigger *eventData){
    eventData->mouseX = -1;
    eventData->mouseY = -1;
    eventData->isTrigger = 0;
    eventData->currentInput = -1;
}

// The main function
int main(int argc, char **argv)
{
    // Initial the window screen and event
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(IMG_INIT_PNG);
    TTF_Init();
    SDL_Window *window = SDL_CreateWindow("MLM Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 750, 750, SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    bool running = true;
    
    SDL_Event event;
    struct eventTrigger *eventData = (struct eventTrigger*) malloc(sizeof(struct eventTrigger));

    // Initial each scene's component
    Title_Initial(renderer);
    Result_Initial(renderer);
    PersonalInfo_Initial(renderer);
    // Selling_Initial(renderer);
    // Salary_Initial(renderer);
    // NewDownline_Initial(renderer);
    // Amount_Initial(renderer);

    // Main loop
    while(running){
        // Reset the eventData in each round of loop and get current mouse position
        resetEventTrigger(eventData);
        SDL_GetMouseState(&eventData->mouseX, &eventData->mouseY);
        
        // Event handling
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = false;
            }
            if(event.type == SDL_KEYDOWN){
                eventData->currentInput = event.key.keysym.sym;
            }
            if(event.type == SDL_MOUSEBUTTONDOWN){
                eventData->isTrigger = 1;
            }
            else{
                eventData->isTrigger = 0;
            }
        }
        
        // Scene switching (depends on currentRoom which is extern variable in struct.h)
        switch(currentRoom){
            case 0:
                Title_Run(renderer, eventData);
                break;
            case 1:
                Result_Run(renderer, eventData);
                break;
            case 2:
                PersonalInfo_Run(renderer, eventData);
                break;
            // case 3:
            //     Selling_DrawScene(renderer);
            //     break;
            // case 4:
            //     Salary_DrawScene(renderer, eventData);
            //     break;
            // case 5:
            //     Amount_DrawScene(renderer, eventData);
            //     break;
            // case 6:
            //     NewDownline_DrawScene(renderer, eventData);
            //     break;
        }
    }

    // Destroy window and exit program
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}