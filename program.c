#include <stdio.h>
#define MAX 6
int deQueue[MAX];
int rear=-1,frond=-1;
int isNull(){
    if(rear==-1&&frond==-1)
        return 1;
    return 0;
}
int isFull(){
    if((rear+1)%MAX==frond)
        return 1;
    return 0;
}
void inFrond(int value){
    if(isFull()==1)
        printf("overflow");
    else{
        if(isNull()){
            rear=0;
            frond=0;
        }
        else if(frond==0)
            frond=MAX-1;
        else
            frond--;
        deQueue[frond]=value;
    }
}
void inRear(int value){
    if(isFull()==1)
        printf("Overflow");
    else{
        if(isNull()){
            frond=0;
            rear=0;
        }
        else
            rear=(rear+1)%MAX;
        deQueue[rear]=value;
    }
}
void deFrond(){
    if(isNull()==1)
        printf("Under flow");
    else if(frond==rear){
        frond=-1;
        rear=-1;
    }
    else
        frond=(frond+1)%MAX;
}
void deRear(){
    if(isNull()==1)
        printf("Under flow");
    else if(frond==rear){
        frond=-1;
        rear=-1;
    }
    else if(rear==0)
        rear=MAX-1;
    else
        rear--;
}
void view(){
    int i;
    printf("\n-----------");
    printf("\nDeQueue\n");
    if(isNull()==1)
        printf("Queue is full");
    else{
        for(i=frond;i!=rear;i=(i+1)%MAX)
            printf("%d\n",deQueue[i]);
        printf("%d\n",deQueue[i]);
    }
    printf("-----------\n");
    
}
void main(){
    int dis;
    int value;
    printf("Menu\n1-Insertion from left\n2-Insertion from right\n3-deletion form left\n4-deletion form left\n5-exit\n");
    do{
        scanf("%d",&dis);
        switch(dis){
            case 1: printf("Enter value : ");
                    scanf("%d",&value);
                    inFrond(value);
                    view();
                    break;
            case 2: printf("Enter value : ");
                    scanf("%d",&value);
                    inRear(value);
                    view();
                    break;
            case 3: deFrond();
                    view();
                    break;
            case 4: deRear();
                    view();
                    break;
            case 5: break;
            default:printf("Wrong input\n");
                    printf("Menu\n1-Insertion from left\n2-Insertion from right\n3-deletion form left\n4-deletion form left\n5-exit\n");
        }
    }while(dis!=5);
}