/* 
把思想，翻译成代码，而代码有边界条件，所以要用特殊案例来测试；
翻译为代码一般的套路：
	• 循环不变式；=>通过for循环实现；
	• 初始条件、边界条件；=>通过增加几个变量实现；
	• 把代码写完，拿特殊案例测试；=>修改的方向：增加变量，修改初始条件、边界条件； */

struct Node
{
    struct  Node * next;
    int data;
    /* data */
};

Node * ReverseLink(Node *head)
{
    if(head == NULL )  return NULL;

    Node * pre = NULL;
    Node * next = NULL;
    while(head)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

int main()
{

    return 0;
}
