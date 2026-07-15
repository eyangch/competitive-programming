class Solution {
public:
    string baseTR(int &n, int iv, string a){
        int nb = n/iv;
        n -= nb * iv;
        string ret = "";
        for(int i = 0; i < nb; i++){
            ret += a;
        }
        return ret;
    }
    string intToRoman(int num) {
        string ret = "";
        if(num >= 1000){
            ret += baseTR(num, 1000, "M");
        }if(num >= 900){
            ret += baseTR(num, 900, "CM");
        }if(num >= 500){
            ret += baseTR(num, 500, "D");
        }if(num >= 400){
            ret += baseTR(num, 400, "CD");
        }if(num >= 100){
            ret += baseTR(num, 100, "C");
        }if(num >= 90){
            ret += baseTR(num, 90, "XC");
        }if(num >= 50){
            ret += baseTR(num, 50, "L");
        }if(num >= 40){
            ret += baseTR(num, 40, "XL");
        }if(num >= 10){
            ret += baseTR(num, 10, "X");
        }if(num >= 9){
            ret += baseTR(num, 9, "IX");
        }if(num >= 5){
            ret += baseTR(num, 5, "V");
        }if(num >= 4){
            ret += baseTR(num, 4, "IV");
        }
        ret += baseTR(num, 1, "I");
        return ret;
    }
};