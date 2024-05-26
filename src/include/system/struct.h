#include <stdio.h>
#include <stdlib.h>

#ifndef STRUCT_H
#define STRUCT_H
/* ********************************* define structure and global variable in program ********************************* */

struct object{
    int pos1[2];
    int pos2[2];
    void (*clickEvent)();
};

struct eventTrigger{
    int mouseX;
    int mouseY;
    int isTrigger;
    int isUsingKeyboard;
    int currentInput;
};

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