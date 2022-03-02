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

package main

import "fmt"

func pair(c string) string {
	switch {
	case c == ")":
		return "("
	case c == "]":
		return "["
	case c == "}":
		return "{"
	}
	return ""
}

func isValid(s string) bool {
	length := len(s)
	stack := make([]string, length)
	top := 0
	//字符非偶数直接返回false
	if length%2 == 1 {
		return false
	}
	for _, v := range s {
		_char := string(v)
		ch := pair(_char)
		if ch != "" {
			if top == 0 || stack[top-1] != ch {
				return false
			}
			top--
		} else {
			stack[top] = _char
			top++
		}
	}
	return top == 0
}

func main() {
	str := "{()}"
	fmt.Println(isValid(str))
}
