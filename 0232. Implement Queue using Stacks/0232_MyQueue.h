﻿#pragma once
#include <stack>
using namespace std;

/*
232. 用栈实现队列
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：
  ● void push(int x) 将元素 x 推到队列的末尾
  ● int pop() 从队列的开头移除并返回元素
  ● int peek() 返回队列开头的元素
  ● boolean empty() 如果队列为空，返回 true ；否则，返回 false

说明：
你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
*/

/*
思路分析：双栈
将一个栈当作输入栈，用于压入 push 传入的数据；另一个栈当作输出栈，用于 pop 和 peek 操作。
每次 pop 或 peek 时，若输出栈为空则将输入栈的全部数据依次弹出并压入输出栈，这样输出栈从栈顶往栈底的顺序就是队列从队首往队尾的顺序。

理解这个解法的关键在于：
    把数据从输入栈倒入输出栈的条件是输出栈为空，这样就维持了输出栈顶是队列开头的定义。

*/
class MyQueue {
public:
    MyQueue() { }

    void push(int x)
    {
        inStk.push(x);
    }

    int pop()
    {
        if (outStk.empty()) {
            in2out();
        }
        int x = outStk.top();
        outStk.pop();
        return x;
    }

    int peek()
    {
        if (outStk.empty()) {
            in2out();
        }
        return outStk.top();
    }

    bool empty()
    {
        return inStk.empty() && outStk.empty();
    }

private:
    stack<int> inStk, outStk;

    void in2out()
    {
        while (!inStk.empty()) {
            outStk.push(inStk.top());
            inStk.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */