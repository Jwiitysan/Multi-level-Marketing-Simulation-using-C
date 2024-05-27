#include <system/struct.h>
#include <system/edit.h>
#include <system/nodeHandle.h>

/* ********************************* edit original price ********************************* */
void editOriginalPrice(int newPrice, int LocationItem, struct pro product[][2]) {
    //locationItem 0:"eSpring" 1:"Water filter" 2:"Atmosphere" 3:"Air filter" 4:"Smart watch"
    if (LocationItem >= 0 && LocationItem < 5) {
        product[LocationItem][0].price = newPrice;
    }
}

/* ********************************* edit sell amount   ********************************* */
void editSellAmount(char *stringName ,int newSellAmount ,int LocationItem ,NodePtr Root)
{
    //locationItem 0:"eSpring" 1:"Water filter" 2:"Atmosphere" 3:"Air filter" 4:"Smart watch"
    NodePtr pNode;
    int *table;
    int icount;
    pNode = searchNode(Root,stringName);
    clearQueue();
    table = pNode->produce;
    if(newSellAmount == 0){
        *(table+(LocationItem*2)) = 0;
    }
    else if(*(table+(LocationItem*2)+1) == 0){
        *(table+(LocationItem*2)) = (int)(product[LocationItem]->price * (100-rand()%8)/100.0f);
    } 
    *(table+(LocationItem*2)+1) = newSellAmount;
}