#include <iostream>
//#include <type_traits>


template<bool B, typename U,typename V>
struct conditional{
    using type=V;
};
template<typename U,typename V>
struct conditional<true,U,V>{
    using type=U;
};
template<bool B, typename U,typename V>
using cond_t=typename conditional<B,U,V>::type;



template <typename T>
class Vector{
    int n;
    T* str;

    template<bool isConst>
    struct iterator_condit{
    private:
        using cond_ptr=cond_t<isConst,const T,T>;

        cond_ptr* pls;

    public:
        template<typename U>
        U& operator ->*(U T::*p){
            return (*pls).*p;
        }

        cond_ptr* operator ->(){
            return pls;
        }

        cond_ptr& operator *(){
            return *pls;
        }

        iterator_condit<isConst> operator +=(int n){
            pls+=n;
            return *this;
        }

        iterator_condit<isConst> operator +(int n){
            auto temp=*this;
            temp+=n;
            return temp;
        }
    };

public: using iterator=iterator_condit<false>;
    using iterator_const=iterator_condit<true>;

};

template<typename T>
typename Vector<T>::iterator operator +(int n, typename Vector<T>::iterator iter){
    return iter+=n;
}


int main(){

}