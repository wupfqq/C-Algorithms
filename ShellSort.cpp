#include <iostream>
#include <vector>
template<typename T>
void InsSort(std::vector<T>* mass, int k,int n){
    for(int id=0;id<n-3;++id){
        for(int i=k+id;i<n;i+=k){
            T temp=mass->at(i);
            int j=i-k;
            while(j>=0 && temp<mass->at(j)){
                mass->at(j+k)=mass->at(j);
                j-=k;
            }
            mass->at(j+k)=temp;
        }}}

        template<typename T>
        void ShellSort(std::vector<T>* mass, int n,int* args,int k){
    for(int t=0;t<k;++t){
        InsSort(mass,args[t],n);
    }
}

int main(){
    int n;
    std::vector<char>ch;
    std::cin>>n;
    char e;
    for(int i=0;i<n;++i){
        std::cin>>e;
        ch.push_back(e);
    }
    int arg[2]={1,3};
    ShellSort(&ch,n,arg,2);

    for(auto it=ch.begin();it!=ch.end();++it){
        std::cout<<*it<<" ";
    }
}
