import java.io.*;
import java.util.*;
import kotlin.math.*;

fun main(){
	val br = BufferedReader(InputStreamReader(System.`in`));
	val T = br.readLine().toInt();
	for(tc in 1..T){
		val st = StringTokenizer(br.readLine());
		val a = st.nextToken().toInt();
		val b = st.nextToken().toInt();
		val diff = abs(a-b) + 9;
		println(diff/10);
	}
}