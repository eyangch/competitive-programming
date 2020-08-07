#include<bits/stdc++.h>
main(){std::ifstream f("teleport.in");std::ofstream o("teleport.out");int a,b,x,y;f>>a>>b>>x>>y;o<<std::min({abs(a-b),abs(a-x)+abs(b-y),abs(a-y)+abs(b-x)})<<"\n";}


