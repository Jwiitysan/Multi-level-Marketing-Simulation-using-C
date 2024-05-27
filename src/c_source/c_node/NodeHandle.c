#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <system/nodeHandle.h>
#include <system/struct.h>

int AmountProduce = 5;
struct pro product[5][2]={{"eSpring",40000},
                        {"Water filter",5500},
                        {"Atmosphere",25000},
                        {"Air filter",6000},
                        {"Smart watch",8800}};
QueuePtr pRear=NULL ,pFront=NULL;

/* ********************************* getnode of queue ********************************* */
QueuePtr getQueue(NodePtr pNode)
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(struct queue));
    p->pointer = pNode;
    p->next = NULL;
    return p;
}

/* ********************************* Enqueue ********************************* */
void Enqueue(NodePtr input)
{
    QueuePtr pNewnode;
    pNewnode = getQueue(input);

    if(pFront == NULL)
    {
        pFront = pNewnode;
        pRear = pFront;
    }
    else
    {
        pRear->next = pNewnode;
        pRear = pRear->next;
    }
}

/* ********************************* dequeue ********************************* */
//return address of node in tree
NodePtr Dequeue()
{
    QueuePtr pTemp;
    NodePtr p;

    pTemp = pFront;
    if(pFront == NULL)
    {
        return NULL;
    }
    p = pFront->pointer;
    if(pFront == pRear)
    {
        pFront = pRear= NULL;
    }
    else
    {
        pFront = pFront->next;
    }
    free(pTemp);
    return p;
}

/* ********************************* clear queue ********************************* */
void clearQueue()
{
    QueuePtr p;
    while(pFront!=NULL)
    {
        p = pFront;
        pFront = pFront->next;
        free(p);
    }
    pFront = NULL;
    pRear = NULL;
}

/* ********************************* random data to table ********************************* */
void randomIncome(int *table ,int num)
{
    int rannumtype,rantype,ranprice;
    int icount;
    int temp;

    for(icount=0 ;icount<num ;icount++)
    {
        *(table+(icount*2)) = 0;
        *(table+(icount*2)+1) = 0;
    }

    rannumtype = rand()%6;
    if(rannumtype != 0)
    {
        for(icount=1 ;icount<=rannumtype ;icount++)
        {
            rantype = rand()%5;
            if(*(table+(rantype*2)) == 0)
            {
                temp = (0.1* product[rantype]->price);
                ranprice = (rand() % temp);
                *(table+(rantype*2)) = ranprice + product[rantype]->price;
                *(table+(rantype*2)+1) = (rand()%10)+1;
            }
            else
            {
                icount--;
            }
        }
    }
}

/* ********************************* initialize PV ********************************* */
void initialPV(NodePtr pNode)
{
    int iretail=0, icost=0, iproductprice, iPV, iincome=0;
    int *ptable;

    /* ***** 1.retail ***** */ // Use produce
    ptable = pNode->produce;
    for(int icount=0; icount<AmountProduce; icount++)
    {
        iproductprice = product[icount][0].price;
        icost+= iproductprice * *(ptable+(icount*2)+1);
        iretail+=*(ptable+(icount*2)) * *(ptable+(icount*2)+1);
    }
    iincome+= iretail-icost;

    /* ***** initial retail ,BV and PV ***** */
    pNode->retail=iincome;
    pNode->BV = icost;
    pNode->PV = pNode->BV/3;
}

/* ********************************* getnode for tree ********************************* */
NodePtr getnode(char inputN[20] ,int status)
{
    NodePtr p;
    int icount;
    int *pTable;

    p = (NodePtr)malloc(sizeof(struct node));
    pTable = (int*)malloc(sizeof(int)*AmountProduce*2);

    // printf("%s",inputN);
    if(strcmp(inputN,"Com") != 0)
        randomIncome(pTable,AmountProduce);

    strcpy(p->name,inputN);
    p->produce = pTable;
    p->status = status;
    p->child = NULL;
    p->nextSi = NULL;

    if(p->status != 0)
        initialPV(p);
    return p;
}

/* ********************************* search location node in tree ********************************* */
//return location of node
NodePtr searchNode(NodePtr Root ,char string[])
{
    NodePtr pRun,pSibling;

    pRun = Root;
    while(pRun!=NULL && strcmp(pRun->name,string) != 0)
    {
        for(pSibling=pRun->child ;pSibling!=NULL ;pSibling=pSibling->nextSi)
        {
            Enqueue(pSibling);
        }
        pRun = Dequeue();
    }
    return pRun;
}

/* ********************************* insert tree ********************************* */
// return location of root
NodePtr insertTree(NodePtr Root ,char string[] ,int iLen ,int status)
{
    NodePtr pNewnode,pRun;

    if(string[iLen-1] == '/')
    {
        string[iLen-1] = '\0';
        if(Root == NULL)
        {
            pNewnode = getnode(string,status);
            return pNewnode;
        }
        else
        {
            pRun = searchNode(Root,string);//search node function;
            clearQueue();
            return pRun;
        }
    }
    else
    {
        pNewnode = getnode(string,status);
        // printf("pNewnode: %p\n",pNewnode);
        if(Root!=NULL && Root->child == NULL)
        {
            Root->child = pNewnode;
        }
        else
        {
            if(status == 1)
            {
                for(pRun=Root->child ;pRun->nextSi!=NULL && pRun->nextSi->status!=0 ;pRun=pRun->nextSi)
                {
                    if(pRun->nextSi != NULL)
                    {
                        if(strcmp(pNewnode->name,pRun->nextSi->name) == -1)
                        {
                            break;
                        }
                    }
                }
                if(pRun == Root->child)
                {
                    if(strcmp(pNewnode->name,pRun->name) == -1 || pRun->status==0)
                    {
                        pNewnode->nextSi = pRun;
                        Root->child = pNewnode;
                        return Root;
                    }
                }
                pNewnode->nextSi = pRun->nextSi;
                pRun->nextSi = pNewnode;
            }
            else
            {
                for(pRun=Root->child ;pRun->nextSi!=NULL ;pRun=pRun->nextSi);
                pRun->nextSi = pNewnode;
            }
        }
        return Root;
    }
}

/* ********************************* edit price ********************************* */
void editPrice(char *stringName ,int newPrice ,int LocationItem ,NodePtr Root)
{
    NodePtr pNode;
    int *table;
    int icount;

    pNode = searchNode(Root,stringName);
    clearQueue();
    table = pNode->produce;
    *(table+(LocationItem*2)) = newPrice;
}

/* ********************************* cal PV ********************************* */
int calPV(NodePtr pNode)
{
    int iPV=0;
    iPV += pNode->PV;
    if(pNode->child==NULL)
    {
        return iPV;
    }

    NodePtr pChild;
    pChild = pNode->child;

    do
    {
        iPV += calPV(pChild);
        pChild = pChild->nextSi;
    }while(pChild!=NULL);

    return iPV;
}

/* ********************************* cal Bonus from PV ********************************* */
int calBonus(int iPV)
{
    if(iPV<5000)
        return 0;
    else if(iPV<15000)
        return 6;
    else if(iPV<30000)
        return 9;
    else if(iPV<55000)
        return 12;
    else if(iPV<90000)
        return 15;
    else if(iPV<150000)
        return 18;
    else
        return 21;
}

/* ********************************* cal % downline ********************************* */
float calPercent(NodePtr pNode)
{
    int iPercentChild, iPercent, iPV;
    float fdownline=0;

    if(pNode->child==NULL)
    {
        return 0;
    }

    NodePtr pChild;
    pChild = pNode->child;
    iPV = calPV(pNode);
    iPercent = calBonus(iPV);

    do
    {
        iPercentChild = calBonus(calPV(pChild));
        fdownline += (iPercent-iPercentChild)*0.01*(pChild->BV);
        pChild = pChild->nextSi;
    }while(pChild!=NULL);

    return fdownline;
}

/* ********************************* cal income ********************************* */
// return all of income
float Allincome(char *sName, NodePtr pRoot)
{
    int iPV, ibonus;
    float fincome=0;
    NodePtr pNode;
    pNode = searchNode(pRoot, sName);
    clearQueue();
    /* ***** check status ***** */
    if(pNode->status == 0)
    {
        return 0; // -1 = Not exist
    }
    /* ***** 1.retail ***** */
    fincome+= pNode->retail;

    /* ***** 2.Personal PV ***** */
    iPV=calPV(pNode);
    ibonus= calBonus(iPV);
    fincome+= pNode->BV * ibonus * 0.01;

    /* ***** 3.Downline PV ***** */
    fincome+= calPercent(pNode);

    pNode->total = fincome;

    return fincome;
}

/* ********************************* Add Node ********************************* */
//return Root
NodePtr addNode(NodePtr Root ,char cParent[],char string[])
{
    NodePtr pAddnode,iFindAddress;
    int iLen;
    iLen = strlen(string);

    iFindAddress = searchNode(Root,cParent);
    clearQueue();
    iFindAddress = insertTree(iFindAddress,string,iLen,1);
    return Root;
}

/* ********************************* write file ********************************* */
void writeFile(NodePtr Root)
{
    NodePtr pRun,pSibling;
    int icount=0;
    FILE *pfile;

    pfile = fopen("Data.txt","w");
    clearQueue();
    Enqueue(Root);
    pRun = Root;
    fprintf(pfile,"%s/ %d",pRun->name,pRun->status);
    while(pFront!=NULL || pRun!=NULL)
    {
        for(pSibling=pRun->child ;pSibling!=NULL ;pSibling=pSibling->nextSi)
        {
            Enqueue(pSibling);
            fprintf(pfile," %s %d",pSibling->name,pSibling->status);
        }
        if(icount == 0)
        {
            pRun = Dequeue();
        }
        pRun = Dequeue();
        if(pRun != NULL)
            fprintf(pfile,"\n%s/ %d",pRun->name,pRun->status);
        icount++;
    }
    fclose(pfile);
}

/* ********************************* main ********************************* */
void initialNode(NodePtr *pRoot)
{
    char ctemp[20];
    int modeInsert,iLen;
    int iStatus;
    NodePtr pParent;
    FILE *pFile;
    pFile = fopen("Data.txt","r");

    srand(time(NULL));
    while(!feof(pFile))
    {
        fscanf(pFile,"%s %d",ctemp,&iStatus);
        iLen = strlen(ctemp);
        if(ctemp[iLen-1] == '/' && *pRoot == NULL) //insert root
        {
            *pRoot = insertTree(*pRoot,ctemp,iLen,iStatus);
            pParent = *pRoot;
        }
        else if(ctemp[iLen-1] == '/')
        {
            pParent = insertTree(*pRoot,ctemp,iLen,iStatus);

        }
        else
        {
            pParent = insertTree(pParent,ctemp,iLen,iStatus);
        }
    }
    fclose(pFile);
}

NodePtr searchprevNode(NodePtr Root,char nameTodel[])
{
    NodePtr pRun,pSibling;
    pRun = Root;
    while(pRun!=NULL&&strcmp(pRun->name,nameTodel)!=0)
        {
            if(pRun->child!=NULL&&strcmp(pRun->child->name,nameTodel)==0){
                return pRun;
            }
            if(pRun->nextSi!=NULL&&strcmp(pRun->nextSi->name,nameTodel)==0){
                return pRun;
            }
            
            for(pSibling=pRun->child ; pSibling!=NULL;pSibling=pSibling->nextSi){
                Enqueue(pSibling);
            }
            pRun = Dequeue();
        
        }
    return NULL;
}

NodePtr delNode(char nameTodel[],NodePtr Root)
{
    NodePtr pNodeToDel = searchNode(Root,nameTodel);
    clearQueue();
    
    if(pNodeToDel == NULL)
    {
        return Root;
    }
    
    pNodeToDel->status=0;
    if(pNodeToDel->nextSi == NULL)
    {
        return Root;
    }
NodePtr pPrevSi = searchprevNode(Root,nameTodel);
     clearQueue();
    NodePtr ptemp;
if(pPrevSi->child==pNodeToDel){
    pPrevSi->child=pNodeToDel->nextSi;
    pNodeToDel->nextSi=NULL;
    for(ptemp=pPrevSi->child;ptemp->nextSi!=NULL&&ptemp->nextSi->status!=0;ptemp=ptemp->nextSi);
    for(;ptemp->nextSi!=NULL&&strcmp(ptemp->nextSi->name,nameTodel)<0;ptemp=ptemp->nextSi);
        pNodeToDel->nextSi=ptemp->nextSi;
        ptemp->nextSi=pNodeToDel;
}else{
     pPrevSi->nextSi=pNodeToDel->nextSi;
    for(ptemp=pPrevSi->nextSi;ptemp->nextSi!=NULL&&ptemp->nextSi->status!=0;ptemp=ptemp->nextSi);
    for(;ptemp->nextSi!=NULL&&strcmp(ptemp->nextSi->name,nameTodel)<0;ptemp=ptemp->nextSi);
        pNodeToDel->nextSi=ptemp->nextSi;
        ptemp->nextSi=pNodeToDel;
}
    return Root;
}

NodePtr freeTree(NodePtr Root, NodePtr OriRoot){
    if(Root->child != NULL){
        freeTree(Root->child, OriRoot);
    }
    if(Root->nextSi != NULL){
        freeTree(Root->nextSi, OriRoot);
    }
    if(Root == OriRoot){
        return Root;
    }
    else{
        free(Root);
        return NULL;
    }
}

int countHandle = 1;
char countString[4];
char nameOfNode[10];

void generateTreeRecursive(NodePtr Root){
    for(int i=0; i<3; i++){
        itoa(countHandle++, countString, 10);
        if(countHandle > 200) break;
        strcpy(nameOfNode, "Node");
        strcat(nameOfNode, countString);
        addNode(rootOfMLM, Root->name, nameOfNode);
    }
    while(rand()%3 != 0){
        itoa(countHandle++, countString, 10);
        if(countHandle > 200) break;
        strcpy(nameOfNode, "Node");
        strcat(nameOfNode, countString);
        addNode(rootOfMLM, Root->name, nameOfNode);
    }
    if (Root->nextSi != NULL) {
        generateTreeRecursive(Root->nextSi);
    }

    if (Root->child != NULL) {
        generateTreeRecursive(Root->child);
    }
}

void generateTree(NodePtr Root){
    countHandle = 1;   
    generateTreeRecursive(Root); 
}