#include<stdio.h>
#include<stdlib.h>
#define size 5
struct stack
{
    int data[size];
    int top;

};
void stackinitialize(struct stack *s);
void push(struct stack*s,int element);
int pop(struct stack *s);
int isfull(struct stack *s);
int isempty(struct stack *s);
void display(struct stack*s);
int initialize(struct stack*s);


int main()
{
    int ch,element,x;
   struct stack s;
   stackinitialize(&s);
   while (1)
   {

       printf("1.push");

       printf("2.pop");
       printf("3.display");
       printf("4.stack top");
       printf("5.exit(0)");
       printf("enter choice");

       scanf("%d",&ch);
       switch(ch)

       {
           case 1:printf("enter element");
           scanf("%d",&element);
           push(&s,element);
           break;


           case 2:x=pop(&s);
           printf("popped element %d",&x);
           break;
           case 3:display(&s);
           break;
           case 4:x=stacktop(&s);
           break;
           case 5:exit(0);

       }

   }

}

int stacktop(struct stack *s)
{
    return(s->data[s->s=top]);
}
void display(struct stack *s)
{
    int i;
    if(isempty(s))

    {
      printf("stack is empty");
      return;
    }

    for(i=s->top;i>=0;i--)
        printf("%d",s->data[i]);
    return;
}

void push(struct stack*s,int element)
{
    if(isfull(s))
    {
        printf("stack overflow");
        return;
    }

    s->top++;
    s->data[s->top]=element;
    return;

}
void stackinitialize(struct stack *s)
{
    int top;

    s->top=-1;

}

int pop(struct stack *s)
{
    int p,element;
    if(isempty(s))
    {
        printf("stack empty");
        return -1;

    }
    p=s->data[s->top]=element;
    s->top--;
    return element;

}

int isfull(struct stack *s)

{
    if(s->top==size-1)
        return 1;
    return 0;

}
int isempty(struct stack *s)

{
    if(s->top==-1)
        return 1;
    return 0;

}
