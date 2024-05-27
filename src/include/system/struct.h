#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#ifndef STRUCT_H
#define STRUCT_H
/* ********************************* define structure and global variable in program ********************************* */

// The struct used to store the user interface data
struct eventTrigger{
    // Mouse Position & Clicking (isTrigger)
    int mouseX;
    int mouseY;
    int isTrigger;
    // Keybord current type (-1 = default)
    int currentInput;
};

typedef struct objectComponent{
    SDL_Rect objectRect;
    SDL_Texture *objectTexture;
}objectComponent;

struct node
{
    char name[20];
    int retail;
    int PV;
    int BV;
    float total; //total of income
    int *produce;
    int status; //1:ready 0:delete
    struct node *nextSi; //Sibling
    struct node *child;
};
typedef struct node *NodePtr;
extern NodePtr sendingNode;

struct pro
{
    char name[20];
    int price;
};
extern int AmountProduce;
extern struct pro product[5][2];

struct queue
{
    NodePtr pointer;
    struct queue *next;
};
typedef struct queue *QueuePtr;
extern QueuePtr pRea ,pFront;

extern int currentRoom;
extern struct eventTrigger *eventData;
extern NodePtr rootOfMLM;

#endif