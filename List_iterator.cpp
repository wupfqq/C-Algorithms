#include <iostream>

class LList{
private:  struct Node{
    Node* f=nullptr;
    int data;
};

    Node* tail;
    friend  LList::Node* next();
public: LList(){
        tail=new Node();
        tail->f=nullptr;
    }
    void PushBack(int val){
        Node* nn=new Node;
        nn->data=val;
        nn->f=tail->f;
        tail->f=nn;

    }


    typedef Node* iterator;
    typedef const Node* const_iterator;


    iterator next(){
        return tail->f;
    }



    iterator begin(){
        return tail->f;
    }
    iterator end(){
        Node* temo=tail;
        while(temo->f!=nullptr)
            temo=temo->f;
        return temo;
    }


    void vizz(){
        Node* t=tail->f;
        while(t!=nullptr){
            std::cout<<t->data<<" ";
            t=t->f;
        }
    }
};

int next(LList::iterator& it){
    it=it->f;
    return it->data;
}


int main(){
    LList l1;
    l1.PushBack(1);
    l1.PushBack(2);
    l1.PushBack(3);
    l1.PushBack(4);
    //l1.vizz();
    LList::iterator iter;
    iter=l1.begin();
    std::cout<<iter->data<<" ";
    next(iter);

    std::cout<<iter->data<<" ";
    next(iter);

    std::cout<<iter->data<<" ";
    next(iter);

    std::cout<<iter->data<<" ";
}
