#include <iostream>


template <typename T>
class Tree{
private: struct node{
    node *lch=nullptr;
    node *rch=nullptr;
    T val=0;
    node(T t):val(t){}
};
public:  node* root=nullptr;

public: void add(T dat){

    node* temp=root;
    node* ptemp=root;
    while(temp!=nullptr){
        if(dat>=temp->val){
            ptemp=temp;
            temp=temp->rch;
        }
        else{
            ptemp=temp;
            temp=temp->lch;
        }
    }
    node* nody=new node(dat);
    if(root==nullptr)
    {root=nody;
        return;}

    if(dat>=ptemp->val)
        ptemp->rch=nody;
    else
        ptemp->lch=nody;

}


public: node* del_node(T val){
    node* temp=root;
    node* ptemp=root;
    while(temp!=nullptr && temp->val!=val){
        if(val>temp->val)
        {ptemp=temp;
            temp=temp->rch;
        }
        else
        {ptemp=temp;
            temp=temp->lch;
        }
    }


    if(temp->lch==nullptr && temp->rch==nullptr){
        if(temp==ptemp){
            delete root;
            return NULL;
        }
        if(ptemp->lch==temp)
            ptemp->lch=nullptr;
        else
            ptemp->rch=nullptr;
        delete temp;
        return root;
    }

    if(temp->lch==nullptr){
        if(temp==ptemp){
            root=temp->rch;
            delete temp;
            return root;
        }
        if(ptemp->lch==temp){
            ptemp->lch=temp->rch;
        }
        else
            ptemp->rch=temp->rch;

        delete temp;
        return root;
    }
    if(temp->rch==nullptr){
        if(temp==ptemp){
            root=temp->lch;
            delete temp;
            return root;
        }
        if(ptemp->lch==temp){
            ptemp->lch=temp->lch;
        }
        else
            ptemp->rch=temp->lch;

        delete temp;
        return root;
    }

    node* tr=temp->lch;
    node* ptr=temp->lch;
    if(tr->rch==nullptr)
        tr->rch=temp->rch;
    else{
        while(tr->rch!=nullptr){
            ptr=tr;
            tr=tr->rch;
        }
        ptr->rch=tr->lch;
        tr->rch=temp->rch;
        tr->lch=temp->lch;

    }
    if(temp==ptemp){
        root=tr;
        delete temp;
        return root;}

    if(ptemp->lch==temp)
    {
        ptemp->lch=nullptr;
        delete temp;}
    else{
        ptemp->rch=nullptr;
        delete temp;}
    return root;
}



private: void dely(node* roo){
    if(roo==nullptr)
        return;
    dely(roo->lch);
    dely(roo->rch);
    delete roo;
}
public: ~Tree(){
    dely(root);
}
};


int main(){
    Tree<int> t1;
    t1.add(12);
    t1.add(90);
    t1.add(88);
    t1.add(6);
    t1.add(2);
    t1.add(19);
    auto nody=t1.del_node(19);
    std::cout<<nody->val;
}
