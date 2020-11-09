import java.io.*;
import java.util.*;

public final class e{
    
    static int M, N;
    static boolean dora[][];

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        M = in.nextInt();
        N = in.nextInt();
        dora = new boolean[50][10000];
        for(int i = 0; i < M; i++){
            int s = in.nextInt();
            boolean good = true;
            for(int j = 0; j < s; j++){
                int x = in.nextInt();
                dora[i][x-1] = true;
            }
        }
        boolean ans = true;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < i; j++){
                boolean curr = false;
                for(int k = 0; k < N; k++){
                    curr |= (dora[i][k] && dora[j][k]);
                }
                ans &= curr;
            }
        }
        if(!ans){
            System.out.print("im");
        }
        System.out.println("possible");
    }
}
