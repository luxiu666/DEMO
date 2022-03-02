/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。


示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false
示例 4：

输入：s = "([)]"
输出：false
示例 5：

输入：s = "{[]}"
输出：true

*/
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