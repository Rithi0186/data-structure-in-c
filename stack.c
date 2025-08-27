
#include <stdio.h>
#define N 10
void push();
void pop();
void peek();
void display();
 int stack[N];
 int top=-1;
void main() {
   
    int ch;
    do{
        printf("1.push\n  2.pop\n 3.peek\n 4.display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: push();
            break;
             case 2: pop();
            break;
             case 3: peek();
            break;
             case 4: display();
            break;
            default: 
            printf("invalid");
        }
                 }
        while(ch!=0);
    }
   


void push(){
    int x;
    printf("enter a stack element:\n");
    scanf("%d",&x);
    if(top==N-1){
        printf("overflow\n");
        
    }
    else{
        top++;
        stack[top]=x;
    }
}
void pop(){
    if(top==-1){
        printf("underflow\n");
        
    }
    else{
        int item;
        item=stack[top];
        top--;
        printf("\nthe deleted element is %d\n",item);
         }
    }
     void peek(){
        printf("the top element is %d",stack[top]);
        
    }
    void display(){
        int i;
        for (i=top;i>=0;i--){
            printf("%d\t",stack[i]);
        }
    }
        
