/*
ID: sireric1
TASK: race3
LANG: JAVA
*/
import java.io.*; 
import java.util.*;

class race3{
    
    static int N = 0;
    static boolean vis[];
    static ArrayList<Integer> graph[];
    
    static void bfs(int start, int avoid){
        for(int i = 0; i < 101; i++){
            vis[i] = false;
        }
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(start);
        while(!q.isEmpty()){
            int id = q.remove();
            if(id == avoid || vis[id]){
                continue;
            }
            vis[id] = true;
            for(int i : graph[id]){
                q.add(i);
            }
        }
    }

    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("race3.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("race3.out")));
        graph = new ArrayList[101];
        vis = new boolean[101];
        while(true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int nxt = 0;
            graph[N] = new ArrayList<Integer>();
            while(true){
                nxt = Integer.parseInt(st.nextToken());
                if(nxt < 0){
                    break;
                }
                graph[N].add(nxt);
            }
            if(nxt == -1){
                break;
            }
            N++;
        }
        ArrayList<Integer> ans1 = new ArrayList<Integer>();
        for(int i = 1; i < N-1; i++){
            bfs(0, i);
            boolean good = true;
            for(int j = 0; j < N; j++){
                if(j == i) continue;
                good &= vis[j];
            }
            if(!good){
                ans1.add(i);
            }
        }
        if(ans1.size() == 0){
            pw.println(0);
        }else{
            pw.print(ans1.size() + " ");
            for(int i = 0; i < ans1.size()-1; i++){
                pw.print(ans1.get(i) + " ");
            }
            pw.println(ans1.get(ans1.size()-1));
        }
        ArrayList<Integer> ans2 = new ArrayList<Integer>();
        for(int i : ans1){
            bfs(0, i);
            ArrayList<Integer> r1 = new ArrayList<Integer>();
            for(int j = 0; j < N; j++){
                if(vis[j]){
                    r1.add(j);
                }
            }
            bfs(i, -1);
            boolean good = false;
            for(int j : r1){
                good |= vis[j];
            }
            if(!good){
                ans2.add(i);
            }
        }
        if(ans2.size() == 0){
            pw.println(0);
        }else{
            pw.print(ans2.size() + " ");
            for(int i = 0; i < ans2.size()-1; i++){
                pw.print(ans2.get(i) + " ");
            }
            pw.println(ans2.get(ans2.size()-1));
        }
        pw.close();
    }
}
