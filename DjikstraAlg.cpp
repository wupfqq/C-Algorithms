#include <iostream>
#include <iostream>

template<typename T>
T* Djikstra(T** mass, int len, T top){
    bool stat[len];
    for(int i=0;i<len;++i){
        stat[i]=true;     //вот если здесь векторы сделать вместо массивов и ресайзнуть,  а если вместо обычного мин/мах еще бинарное/к-ичное дерево сделать
    }                   //то не придется все ручками заполнять                                             то асимптотика -- сумма логарифмов
    T* dist=new T[len];
    for(int i=0;i<len;++i){
        dist[i]=1000;
    }
    dist[top]=0;
    for(int i=0;i<len;++i){
        T mindist=10000;
        int el=-1;
        for(int j=0;j<len;++j){
            if(stat[j] && dist[j]<mindist){
                mindist=dist[j];
                el=j;
            }}
        for(int t=0;t<len;++t){
            if(mass[el][t]!=0 and mass[el][t]+dist[el]<dist[t]){
                dist[t]=mass[el][t]+dist[el];
            }
        }
        stat[el]=false;
    }
    return dist;
}

int main(){
    int n;
    std::cin>>n;
    int **mass=new int*[n];
    for(int i=0;i<n;++i)
        mass[i]=new int[n];
    for(int j=0;j<n;++j)
        for(int h=0;h<n;++h){
            std::cout<<"Enter el "<<j<<" "<<h<<'\n';
            std::cin>>mass[j][h];}

    for(int j=0;j<n;++j){
        for(int h=0;h<n;++h)
            std::cout<<mass[j][h]<<" ";
        std::cout<<'\n';

    }
    int* a=Djikstra<int>(mass,5,0);    //если 0 или 10000 то пути неть
    for(int i=0;i<n;++i){
        std::cout<<a[i]<<" ";
    }
}

