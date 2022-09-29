#include <iostream>
#include <memory>
using namespace std;

class Son;

class Father {
public:
    weak_ptr<Son> son_;// 改了这里
    Father() {
        test=0;
        cout << __FUNCTION__ << endl;
    }
    void FatherPrint(){test=1;cout <<__FUNCTION__<<endl;}
    ~Father() {
        cout << __FUNCTION__ << endl;
    }
    int test;
};

class Son {
public:
    weak_ptr<Father> father_;// 改了这里
    Son() {
        cout << __FUNCTION__ << endl;
    }
    ~Son() {
        cout << __FUNCTION__ << endl;
    }
};

int main()
{
    auto son = make_shared<Son>();
    {
      auto father = make_shared<Father>();
      father->son_ = son;// son的shared_count==1,father->son_的weak_count==1
      cout << "father: " << father.use_count() << endl;
      son->father_ = father;// father的shared_count==1，son->father_的weak_count==1
    }
    cout << "son: " << son.use_count() << endl;
    cout << "father expire: " << son->father_.expired() << endl;
    if(!son->father_.expired())// 没有被释放
    {
      son->father_.lock()->FatherPrint();// lock是返回Father的指针
    }
    return 0;
}
