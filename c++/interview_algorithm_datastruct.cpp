/*
一、方法：
1、计算机的思维方式：子结构、同步；
常用子结构：dp、树；
基础案例、变种案例；如：upper_bound是二分的变种；两节点的最长路径是树的高度的变种；贪心算法是dp的变种；

二、代码：
2、把思想，翻译成代码，而代码有边界条件，所以要用特殊案例来测试；
翻译为代码一般的套路：
    • 循环不变式；=>通过for循环实现；停止条件；翻译成for就是取反，即!停止 do{}；
    • 初始条件、边界条件；=>通过增加几个变量实现；
    • 把代码写完，拿特殊案例测试；=>修改的方向：增加变量，修改初始条件、边界条件；

3、程序设计，无非就是顺序、分支、循环，没有那么多复杂的东西，遇到问题从循环不变式考虑；=>立马要想到递归结构、for循环；

三、案例：
4、大量阅读优秀代码，理解之后，保证正确了，放到这里，要背下来；作为随机应变的基础；就和乘法表一样；*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <queue>
#include <unistd.h>
#include <time.h>
using namespace std;
//////算法//////

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

int Atoi(char *input)
{
    if (input == NULL)
        return 0;

    char *s = input;
    for (; *s == ' '; s++)
        ; // 删空格

    bool neg = false;
    if (*s == '-')
    {
        s++;
        neg = true;
    }

    for (; *s == '0'; s++)
        ; // 删0

    int res = 0;
    for (; *s; s++)
    {
        char c = *s;
        if (c >= '0' && c <= '9')
            c = c - '0';
        else if (c >= 'A' && c <= 'Z')
            c = c - 'A';
        else if (c >= 'a' && c <= 'z')
            c = c - 'a';
        else
            break;
        res = res * 10 + c;
        // if(res > INTMAX)
    }
    if (neg)
        res = -1 * res;
    return res;
}
//////数据结构//////
struct LinkNode
{
    struct LinkNode *next;
    int data;
};

class LinkList
{
public:
    LinkList()
    {
        m_head = NULL;
        m_tail = NULL;
    }

    // 反转链表
    struct LinkNode *ReverseLink(struct LinkNode *head)
    {
        if (head == NULL)
            return NULL;

        struct LinkNode *pre = NULL;
        struct LinkNode *next = NULL;
        while (head)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    struct LinkNode *Add(LinkNode *node)
    {
        if (m_head == NULL)
        {
            m_head = m_tail = node;
            return m_head;
        }

        m_tail->next = node;
        node->next = NULL;
        m_tail = node;
    }

    struct LinkNode *Del(LinkNode *node)
    {
        struct LinkNode *p = m_head;
        struct LinkNode *pre = NULL;

        if (p->data == node->data)
        {
            m_head = m_head->next;
            delete p;
            return m_head;
        }

        pre = p;
        p++;
        for (; p != NULL; p++)
        {
            if (p->data == node->data)
            {
                pre->next = p->next;
                delete p;
                return m_head;
            }
            else
            {
                pre = p;
            }
        }
        return m_head;
    }
    virtual ~LinkList()
    {
        struct LinkNode *p = m_head;
        for (; p != NULL; p++)
        {
            struct LinkNode *temp = p;
            p = p->next;
            delete temp;
        }
    }

private:
    struct LinkNode *m_head, *m_tail;
};

class TimestampQueueRateLimiter
{
public:
    TimestampQueueRateLimiter(int seconds, int limit)
    {
        m_seconds = seconds;
        m_limit = limit;
    }
    virtual ~TimestampQueueRateLimiter()
    {
    }

    bool tryAcquire()
    {
        int min = m_queue.front();
        int now = time(NULL);
        for (; m_queue.size() && now - min > m_seconds;)
        {
            m_queue.pop();
            min = m_queue.front();
        }
        if (m_queue.size() < m_limit)
        {
            m_queue.push(now);
            return true;
        }
        return false;
    }

private:
    int m_seconds;           // 多少秒为一个周期
    int m_limit;             // 限制多少次
    std::queue<int> m_queue; // 时间戳队列
};

int test_TimestampQueueRateLimiter()
{
    int seconds = 10;// 10秒 内 至多 5个请求
    int limits = 5;

    TimestampQueueRateLimiter rate_limiter(seconds, limits);
    cout << rate_limiter.tryAcquire() << endl;
    cout << rate_limiter.tryAcquire() << endl;
    cout << rate_limiter.tryAcquire() << endl;
    cout << rate_limiter.tryAcquire() << endl;
    cout << rate_limiter.tryAcquire() << endl;
    cout << rate_limiter.tryAcquire() << endl;
    cout << rate_limiter.tryAcquire() << endl;

    sleep(seconds + 1);
    cout << rate_limiter.tryAcquire() << endl;
    return 0;
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

void testAtoi()
{
    while (true)
    {
        char s[100];
        scanf("%s", s);
        int a = Atoi(s);
        printf("a=%d\n", a);
    }
}

void test()
{
    int a[3][3][9];
    memset(a, 0, sizeof(a) / sizeof(int));

    printf("%d,%d\n", a[0][0][0], sizeof(a) / sizeof(int));
}

int TotalPrice(const map<int, int> &count2price, int n)
{
    int total = 0;
    // n < a(0)
    if (count2price.empty())
        return 0;

    if (n < count2price.begin()->first)
        return 0;

    // a(i-1)<=n<a(i),1=2…N
    map<int, int>::const_iterator m_count2price_it = count2price.begin();
    int pre = m_count2price_it->first;
    int pre_price = m_count2price_it->second;
    for (m_count2price_it++;
         m_count2price_it != count2price.end() && n >= m_count2price_it->first;
         m_count2price_it++)
    {
        total = total + (m_count2price_it->first - pre) * pre_price;
        pre = m_count2price_it->first;
        pre_price = m_count2price_it->second;
    }

    // a(i-1)<=n<a(i) || n>=a(N)
    total = total + (n - pre + 1) * pre_price;

    return total;
}
int mainTotalPrice()
{
    map<int, int> count2price;
    count2price.insert(make_pair(1, 10));
    count2price.insert(make_pair(6, 9));
    count2price.insert(make_pair(11, 5));
    count2price.insert(make_pair(31, 4));
    count2price.insert(make_pair(51, 1));
    // TODO add more

    int n = 6;
    cout << TotalPrice(count2price, n);
    return 0;
}

int main()
{
    // (void)testupperbound_lowerbound();
    //test();
    test_TimestampQueueRateLimiter();
    return 0;
}
