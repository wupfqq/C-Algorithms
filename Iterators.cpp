#include <iostream>
#include <iterator>

//+ добавить functions back_inserter(), front_inserter(), inserter()

template <typename Cont>
class Back_OutputIter{       //+front output iterator
    Cont& container;

public:

    Back_OutputIter(Cont& cont): container(cont){}

    Back_OutputIter<Cont>& operator ++(){
        return *this;}

        Back_OutputIter<Cont>& operator *(){
        return *this;
    }
    typename std::iterator_traits<typename Cont::iterator>::value_type operator =(typename std::iterator_traits<typename Cont::iterator>::value_type& value){
        container.push_back(value);
        return container.back();   //последний элемнет(штоб можно было присвоить дальше)
    }
};


template <typename Cont>
class insert_OutputIter{           //вставка в рандомное место
    Cont& container;
    typename Cont::iterator iter;

public:

    insert_OutputIter(Cont& cont, typename Cont::iterator iter): container(cont), iter(iter){}

    insert_OutputIter<Cont>& operator ++(){
        return *this;}

        insert_OutputIter<Cont>& operator *(){
        return *this;
    }
    typename std::iterator_traits<typename Cont::iterator>::value_type operator =      //return object(?)
            (typename std::iterator_traits<typename Cont::iterator>::value_type& value){
        auto res_iter=container.insert(iter,value);
        return *res_iter;
    }
};
