/*
有效的括号

知识点：
stack

stack 模板类的定义在<stack>头文件中。

stack 模板类需要两个模板参数，一个是元素类型，一个容器类型，但只有元素类型是必要的，在不指定容器类型时，默认的容器类型为deque。

定义stack 对象的示例代码如下：

stack<int> s1;

stack<string> s2;

stack 的基本操作有：

入栈，如例：s.push();在栈顶增加元素

出栈，如例：s.pop();注意，出栈操作只是删除栈顶元素，并不返回该元素。

访问栈顶，如例：s.top()

判断栈空，如例：s.empty()，当栈空时，返回true。

访问栈中的元素个数，如例：s.size()。

补充知识：
queue 模板类的定义在<queue>头文件中。

与stack 模板类很相似，queue 模板类也需要两个模板参数，一个是元素类型，一个容器类型，元素类型是必要的，容器类型是可选的，默认为deque 类型。

定义queue 对象的示例代码如下：

queue<int> q1;

queue<double> q2;

queue 的基本操作有：

入队，如例：q.push(x); 将x 接到队列的末端。

出队，如例：q.pop(); 弹出队列的第一个元素，注意，并不会返回被弹出元素的值。

访问队首元素，如例：q.front()，即最早被压入队列的元素。

访问队尾元素，如例：q.back()，即最后被压入队列的元素。

判断队列空，如例：q.empty()，当队列空时，返回true。

访问队列中的元素个数，如例：q.size()
*/


#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isValid(string s){
    stack<char> st;
    for(auto ch:s)
    {
        if(ch == '{' || ch == '[' || ch == '(')
        {
            st.push(ch);//在栈顶增加元素
        }
        else if(ch == '}' || ch == ']' || ch == ')')
        {
            if(st.empty())//当栈为空的时候，返回true
                return false;
            char sch = st.top(); //访问栈顶
            if((sch == '{' && ch == '}') || (sch == '[' && ch == ']') || (sch == '(' && ch == ')'))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else{
            return false;
        }
    }
    return st.empty();
}
int main(int argc, char const *argv[])
{
    string s = "{{}{[]()}}";
    if(argc > 1)
    {
        s = argv[1];
    }
    cout << "str == \"" << (s) << "\"" << endl;
    cout << isValid(s) << endl;
    return 0;
}



