#include <iostream>
#include <iterator>
#include <vector>

template <typename T>
class Stack{
private: struct node{
    node* next;
    T data;
    node(T val):data(val){}
};
public: node* head=nullptr;

public:Stack(){}
void AddNode(T val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
node* begin(){return head;}

public: struct Iterator{
public: node* ptr=nullptr;
public: Iterator (){}
Iterator& operator =(node* p){ptr=p;
    return *this;}
    Iterator& operator ++(){
    ptr=ptr->next;
    return *this;
}
};


    Stack& operator =(std::vector<T> vec){
        typename std::vector<T>::iterator iter=vec.begin();
        while(iter<vec.end()){
            AddNode(*iter);
            iter++;}
        return *this;
    }

};

int main(){
    Stack<int> s1;
    s1.AddNode(90);
    s1.AddNode(88);
    s1.AddNode(45);
    s1.AddNode(44);

    Stack<int>s2;
    s2={12,23,34,55};

    Stack<int>::Iterator iter;
    iter=s2.begin();
    ++iter;
    ++iter;
    std::cout<<iter.ptr->data;

}

