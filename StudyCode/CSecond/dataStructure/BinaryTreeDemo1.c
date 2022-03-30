#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BinaryTreeNode
{
    char nodeName[10];
    struct BinaryTreeNode* lchildNode;
    struct BinaryTreeNode* rchildNode;
};

void printfDLR(struct BinaryTreeNode* node, int *count)
{
    if(node == NULL)
    {
        //printf("------------");
        return;

    }

    printf("%s", node->nodeName);

    if(node->lchildNode== NULL && node->rchildNode== NULL)
    {
        (*count)++;
    }
    printfDLR(node->lchildNode, count);

    printfDLR(node->rchildNode, count);



}

void printfLDR(struct BinaryTreeNode* node)
{
    if(node == NULL)
    {
        //printf("------------");
        return;

    }

    printfLDR(node->lchildNode);
    printf("%s", node->nodeName);
    printfLDR(node->rchildNode);

    
}

void printfLRD(struct BinaryTreeNode* node)
{
    if(node == NULL)
    {
        //printf("------------");
        return;

    }

    printfLRD(node->lchildNode);
    printfLRD(node->rchildNode);
    printf("%s", node->nodeName);
}

int getTreeHeight(struct BinaryTreeNode* node)
{
    if(NULL == node)
    {
        return 0;
    }

    int lHeight = getTreeHeight(node->lchildNode);
    int rHeight = getTreeHeight(node->rchildNode);

    return lHeight >= rHeight?lHeight+1:rHeight+1;

}

struct BinaryTreeNode* copyTree(struct BinaryTreeNode* srcNode)
{
    if(srcNode == NULL)
    {
        //printf("------------");
        return NULL;

    }
    
    struct BinaryTreeNode*  lchildNode = copyTree(srcNode->lchildNode);

    struct BinaryTreeNode* rchildNode = copyTree(srcNode->rchildNode);

    struct BinaryTreeNode* newNode = malloc(sizeof(struct BinaryTreeNode));
    memcpy(newNode->nodeName,srcNode->nodeName,sizeof(char)*10);
    newNode->lchildNode = lchildNode;
    newNode->rchildNode = rchildNode;
    return newNode;
}


void destoryTree(struct BinaryTreeNode* srcNode)
{
    if(srcNode == NULL)
    {
        //printf("------------srcNode == NULL\n");
        return;

    }
    
    destoryTree(srcNode->lchildNode);
    destoryTree(srcNode->rchildNode);
    //(srcNode->nodeName,0,10*sizeof(char));
    printf("-----destory nodeName:%s-------\n",srcNode->nodeName);
    free(srcNode);
}


int main()
{
    //先序 ABCDEFGH
    //中序 BDCEAFHG
    //后序 DECBHGFA
    //  A
    // B  F
    //  C  G
    // D E H
    struct BinaryTreeNode Node_A = {"A", NULL, NULL};
    struct BinaryTreeNode Node_B = {"B", NULL, NULL};
    struct BinaryTreeNode Node_C = {"C", NULL, NULL};
    struct BinaryTreeNode Node_D = {"D", NULL, NULL};
    struct BinaryTreeNode Node_E = {"E", NULL, NULL};
    struct BinaryTreeNode Node_F = {"F", NULL, NULL};
    struct BinaryTreeNode Node_G = {"G", NULL, NULL};
    struct BinaryTreeNode Node_H = {"H", NULL, NULL};

    Node_A.lchildNode = &Node_B;
    Node_A.rchildNode =  &Node_F;

    Node_B.rchildNode =  &Node_C;

    Node_C.lchildNode = &Node_D;
    Node_C.rchildNode =  &Node_E;

    Node_F.rchildNode =  &Node_G;

    Node_G.rchildNode =  &Node_H;
    

    //C:\mingw64\bin\gcc.exe
    //先序 ABCDEFGH
    // int count = 0;
    // printf("ABCDEFGH---root first:");
    // printfDLR(&Node_A, &count);
    // printf("\n");
    // printf("count:%d\n", count);
    // //中序 BDCEAFHG
    // int height = 0;
    // printf("BDCEAFHG---mid first:");
    // printfLDR(&Node_A);
    // printf("\n");
    // printf("height:%d\n", getTreeHeight(&Node_A));
    //后序 DECBHGFA
    printf("DECBHGFA---later first:");
    printfLRD(&Node_A);
    printf("\n");


    struct BinaryTreeNode *Node_A_Copy= copyTree(&Node_A);
    
    printf("Node_A_Copy->nodeName:%s\n",Node_A_Copy->nodeName);
    // printfLRD(Node_A_Copy);
    // printf("\n");
    //释放的时候，将指针传入给函数的时候，实际上函数是进行了参数的赋值，也就是说
    //虽然函数内部对指针指向的内存对象进行了对应的操作，但是实际上指针本身并没有
    //被操作，相当于是函数内部重新创建了一个指针，但是指向的对象与传给函数的指针
    //参数指向的内存对象是同一个而已。
    destoryTree(Node_A_Copy);
    printf("---------------destoryTree\n");
    Node_A_Copy = NULL;
    if(Node_A_Copy == NULL)
    {
        printf("---------------&Node_A == NULL\n");
    }
    printfLRD(Node_A_Copy);

    printf("\n");
    return 0;
}