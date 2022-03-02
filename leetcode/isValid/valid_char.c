#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char map(char c)
{
    switch(c)
    {
        case ')':return '(';break;
        case ']':return '[';break;
        case '}': return '{';break;
    }
    return 0;
}

bool isValid(char * s){
    int length = strlen(s);
    char stack[length+1];
    int top = 0;//栈顶
    //如果不是偶数个字符，直接返回false
    if(length % 2 == 1)
    {
        return false;
    }

    for(int i = 0;i < length;i++)
    {
        char ch = map(s[i]);

        if(ch)
        {
            if(top == 0 ||ch != stack[top-1])
            {
                return false;
            }
            top --;
        }else
        {
            stack[top] = s[i];
            top ++;
        }
    }

    return top == 0;

}

int main(int argc,char *argv[])
{
    char *str = "{}";
    printf("%s is %d\n",str,isValid(str));
    return 0;
}