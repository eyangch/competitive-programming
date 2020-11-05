import java.io.*;
import java.util.*;

public final class f{

    static int N, M, K, mat[][];
    static int row_val[][], row_dp[][][];
    static int dp[][];

    public static void main(String[] args) throws IOException{
        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        M = in.nextInt();
        K = in.nextInt();
        mat = new int[70][70];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                mat[i][j] = in.nextInt();
            }
        }
        row_dp = new int[70][70][70];
        row_val = new int[70][70];
        for(int i = 0; i < N; i++){
            for(int j = 1; j < K; j++){
                row_val[i][j] = -9999999;
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                for(int k = 0; k < M; k++){
                    for(int l = 0; l < K; l++){
                        row_dp[j][k][l] = -9999999;
                    }
                }
            }
            for(int j = 0; j < M; j++){
                row_dp[j][0][0] = 0;
            }
            row_dp[0][1][mat[i][0] % K] = mat[i][0];
            for(int j = 1; j < M; j++){
                for(int k = 1; k <= M/2; k++){
                    for(int l = 0; l < K; l++){
                        int lpmat = (l+mat[i][j]) % K;
                        row_dp[j][k][lpmat] = Math.max(row_dp[j][k][lpmat], Math.max(row_dp[j-1][k][lpmat], row_dp[j-1][k-1][l] + mat[i][j]));
                        row_val[i][lpmat] = Math.max(row_val[i][lpmat], row_dp[j][k][lpmat]);
                    }
                }
            }
        }
        /*for(int i = 0; i < N; i++){
            for(int j = 0; j < K; j++) System.out.print(row_val[i][j] + " ");
            System.out.println();
        }*/
        dp = new int[70][70];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < K; j++){
                dp[i][j] = -9999999;
            }
        }
        for(int i = 0; i < K; i++){
            dp[0][i] = row_val[0][i];
        }
        for(int i = 1; i < N; i++){
            for(int j = 0; j < K; j++){
                for(int k = 0; k < K; k++){
                    int diff = (j - k + K) % K;
                    dp[i][j] = Math.max(dp[i][j], dp[i-1][k] + row_val[i][diff]);
                }
            }
        }
        /*for(int i = 0; i < N; i++){
            for(int j = 0; j < K; j++) System.out.print(dp[i][j] + " ");
            System.out.println();
        }*/
        System.out.println(Math.max(0, dp[N-1][0]));
    }
}
