import java.io.*;
import java.util.*;
import kotlin.math.*;

fun main(){
	val br = BufferedReader(InputStreamReader(System.`in`));
	val T = br.readLine().toInt();
	for(i in 1..T){
		val st = StringTokenizer(br.readLine());
		var N = st.nextToken().toInt();
		var x = st.nextToken().toInt();
		var y = st.nextToken().toInt();
		var diff = y-x;
		var div = diff;
		for(i in N-1 downTo 1){
			if(diff % i == 0){
				div = diff/i;
				break;
			}
		}
		var cnt = 0;
		for(i in y downTo 1 step div){
			print(i);
			print(" ");
			cnt++;
			if(cnt == N) break;
		}
		for(i in 1..N-cnt){
			print(y+i*div);
			print(" ");
		}
		println();
	}
}