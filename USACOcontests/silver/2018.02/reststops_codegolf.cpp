#include <bits/stdc++.h>
int64_t N,F,B,A,R,d=-1,i;main(){std::ifstream f("reststops.in");std::ofstream o("reststops.out");f>>N>>N>>F>>B;int D[N],T[N];for(;i<N;i++)f>>D[i]>>T[i];while(d<N-1){d=std::max_element(T+d+1,T+N)-T;R+=(D[d]-A)*(F-B)*T[d];A=D[d];}o<<R<<"\n";}
