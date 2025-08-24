#include <stdio.h>
#include <string.h>

int stackPointer = 100;
int basePointer = 100;
char stack[100];

int push(char data[])
{
    if((stackPointer - strlen(data)) <= 0)
    {
        return 0; // StackOverflow...
    }
    else
    {
        stack[--stackPointer] = basePointer;
        basePointer = stackPointer;

        for(int i = strlen(data)-1; i >= 0; i--)
        {
            
            stack[--stackPointer] = data[i];
        }
    }

    return strlen(data);
}

void pop(){
    if(stackPointer >= 100)
    {
        return; //Nothing to pop...
    }
    else
    {
        stackPointer = basePointer;
        basePointer = stack[stackPointer++];
    }    
}

int main(int argc, char** argv) {
    push("Blinky");
    push("Pinky");
    pop();
    push("Inky");
    push("Clyde");
}
