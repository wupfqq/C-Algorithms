#include <iostream>

template<typename T>
void Merge(T* mass, T r, T l,int n){
    int ind1=n-l+1;
    int ind2=r-n;

    T* mass1=new T[ind1];
    T* mass2=new T[ind2];

    for(int i=0;i<ind1;++i)
        mass1[i]=mass[l+i];
    for(int j=0;j<ind2;++j)
        mass2[j]=mass[n+1+j];


    int i,j;
    i=j=0;
    int k = l;

    while (i < ind1 && j < ind2) {
        if (mass1[i] <= mass2[j]) {
            mass[k] = mass1[i];
            i++;
        }
        else {
            mass[k] = mass2[j];
            j++;
        }
        k++;
    }
    while (i < ind1) {
        mass[k] = mass1[i];
        i++;
        k++;
    }
    while (j <ind2) {
        mass[k] = mass2[j];
        j++;
        k++;
    }
}

template<typename T>
void Deliver(T* mass,T r,T l){
    if(l>=r)
        return;
    int m=(r-l)/2 + l;
    Deliver(mass,m,l);
    Deliver(mass,r,m+1);
    Merge(mass,r,l,m);

}



int main(){


    int c[4]={4,9,1,8};
    Deliver(c,3,0);
    for(int i=0;i<4;++i)
        std::cout<<c[i]<<" ";



    return 0;
}

