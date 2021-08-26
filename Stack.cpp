#include <iostream>
#include <cassert>
#include <utility>
//stack(then dack with templates)
//integr with buffer methods from dynar
template<typename T>
class Stack{
public: int bufsize;
    T hind;
    std::pair<T,int>* buff;
public: Stack(int buffsize):bufsize(buffsize), hind(-1) {buff=new std::pair<T,int>[bufsize];}

~Stack(){delete[] buff;}

void push(T x){
        assert(hind<bufsize-1);
        std::pair<T,int> par;
        par.first=x;
        if(hind==-1)
            par.second=0;
        else if(buff[buff[hind].second].first<x)
            par.second=buff[hind].second;
        else
            par.second=hind+1;
        buff[++hind]=par;
    }

    T& pop(){
        assert(hind!=-1);
        return buff[hind--].first;
    }



    bool epmty() const{
        return hind==-1;
    }


    T MinFinder(){
        return buff[buff[hind].second].first;
    }
};

int main(){
    Stack<int> s1(20);
    s1.push(23);
    s1.push(56);
    s1.push(90);
    s1.push(11);
    s1.push(62);
    s1.push(7);
    s1.push(88);
    s1.push(11);
    s1.push(3);
    s1.pop();
    int s=s1.MinFinder();
    std::cout<<s;
    return 0;
}