#include<iostream>
#include<cstdio>
using namespace std;
int a[100005];
int main(){
    int t,x;
    scanf("%d",&t);
    for(int i=4;i<100002;i++){
        if(i%4==0) a[i]=(i/4)*(i/4)*2;
        else if(i%4==1) a[i]=a[i-1]+i/4-0.5;
        else if(i%4==2) a[i]=(i/4)*(i/4+1)*2;
        else if(i%4==3) a[i]=a[i-1]+i/4+0.5;
    }
    while(t--){
        scanf("%d",&x);
        for(int i=4;i<100002;i++){
            if(a[i]>=x){printf("%d\n",i);break;}
        }
    }
}
