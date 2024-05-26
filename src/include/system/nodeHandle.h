#include "struct.h"

#ifndef NODEHANDLE_H
#define NODEHANDEL_H

void initialNode(NodePtr *pRoot);
NodePtr searchNode(NodePtr Root ,char string[]);
NodePtr delNode(char nameTodel[],NodePtr Root);
NodePtr searchprevNode(NodePtr Root,char nameTodel[]);
NodePtr addNode(NodePtr Root ,char cParent[],char string[]);
void writeFile(NodePtr Root);
NodePtr freeTree(NodePtr Root, NodePtr OriRoot);
void generateTree(NodePtr Root);
void clearQueue();

float Allincome(char *sName, NodePtr pRoot);
int calPV(NodePtr pNode);

#endif