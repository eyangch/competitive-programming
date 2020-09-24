import java.io.*;
import java.util.*;
import kotlin.math.*;

fun main(){
	val br = BufferedReader(InputStreamReader(System.`in`));
	val T = br.readLine().toInt();
	for(tc in 1..T){
		val st = StringTokenizer(br.readLine());
		var a = st.nextToken().toLong();
		var b = st.nextToken().toLong();
		var x = st.nextToken().toLong();
		var y = st.nextToken().toLong();
		var n = st.nextToken().toLong();
		var adif = max(a-n, x);
		var bdif = max(b-n, y);
		if(adif < bdif){
			n -= a-adif;
			println(adif * max(b-n, y));
		}else{
			n -= b-bdif;
			println(bdif * max(a-n, x));
		}
	}
}