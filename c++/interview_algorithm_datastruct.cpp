/*
把思想，翻译成代码，而代码有边界条件，所以要用特殊案例来测试；
翻译为代码一般的套路：
    • 循环不变式；=>通过for循环实现；
    • 初始条件、边界条件；=>通过增加几个变量实现；
    • 把代码写完，拿特殊案例测试；=>修改的方向：增加变量，修改初始条件、边界条件； */

//////算法//////
#include <stdio.h>

// 返回有序数组中满足key的最大的下标
// 等价于 https://en.cppreference.com/w/cpp/algorithm/upper_bound
int UpperBound(int *array, int size, int key)
{
    int first = 0, len = size;
    int half, middle;

    while (len > 0)
    {
        half = len >> 1;
        middle = first + half;
        if (key < array[middle]) //中位数大于key,在包含last的左半边序列中查找。
            len = half;
        else
        {
            first = middle + 1; //中位数小于等于key,在右半边序列中查找。
            len -= half + 1;
        }
    }
    return first;
}

// 返回有序数组中满足key的最小的下标
int LowerBound(int *array, int size, int key)
{
    int first = 0, len = size;
    int half, middle;

    while (len > 0)
    {
        half = len >> 1;
        middle = first + half;
        if (key <= array[middle])
            len = half;
        else
        {
            first = middle + 1;
            len -= half + 1;
        }
    }
    return first;
}

//////数据结构//////
struct Node
{
    struct Node *next;
    int data;
    /* data */
};

Node *ReverseLink(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *pre = NULL;
    Node *next = NULL;
    while (head)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

int testupperbound_lowerbound()
{
    int a[] = {1, 2, 3, 4, 6, 6, 6, 8, 9};
    int n = 0;
    while (true)
    {
        scanf("%d", &n);
        printf("sizeof(a)=%d,%d\n", sizeof(a), sizeof(int));
        // int upp_index = UpperBound(a, sizeof(a) / sizeof(int), n);
        int upp_index = UpperBound(a, sizeof(a) / sizeof(int), n);
        int lower_index = LowerBound(a, sizeof(a) / sizeof(int), n);
        printf("loewr_index=%d,value=%d,upp_index=%d,value=%d\n",
               lower_index, a[lower_index], upp_index, a[upp_index]);
    }
    return 0;
}

int main()
{
    (void)testupperbound_lowerbound();
    return 0;
}
