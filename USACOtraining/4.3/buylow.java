/*
ID: sireric1
LANG: JAVA
TASK: buylow
*/

import java.io.*;
import java.util.*;
import java.math.*;

class buylow{

    static int N, a[], dp0[];
    static BigInteger dp1[];

    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("buylow.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("buylow.out")));
        N = Integer.parseInt(new StringTokenizer(br.readLine()).nextToken());
        a = new int[N];
        dp0 = new int[N];
        dp1 = new BigInteger[N];
        int inp_cnt = 0;
        while(true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            while(st.hasMoreTokens()){
                a[inp_cnt] = Integer.parseInt(st.nextToken());
                inp_cnt++;
            }
            if(inp_cnt == N){
                break;
            }
        }
        Set<Integer> vis = new HashSet<Integer>();
        for(int i = 0; i < N; i++){
            dp0[i] = 1;
            dp1[i] = BigInteger.ONE;
            for(int j = i-1; j >= 0; j--){
                if(a[j] > a[i]){
                    if(vis.contains(a[j])){
                        continue;
                    }
                    vis.add(a[j]);
                    if(dp0[j]+1 > dp0[i]){
                        dp0[i] = dp0[j]+1;
                        dp1[i] = dp1[j];
                    }else if(dp0[j]+1 == dp0[i]){
                        dp1[i] = dp1[i].add(dp1[j]);
                    }
                }
            }
            vis.clear();
        }
        int maxn = 0;
        BigInteger maxcnt = BigInteger.ZERO;
        for(int i = N-1; i >= 0; i--){
            if(vis.contains(a[i])){
                continue;
            }
            vis.add(a[i]);
            if(dp0[i] > maxn){
                maxn = dp0[i];
                maxcnt = dp1[i];
            }else if(dp0[i] == maxn){
                maxcnt = maxcnt.add(dp1[i]);
            }
        }
        pw.println(maxn + " " + maxcnt);
        pw.close();
    }
}
