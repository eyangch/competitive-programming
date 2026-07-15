class Solution {
public:
    string largestPalindrome(int n, int k) {
        if(k == 1 || k == 3 || k == 9){
            return string(n, '9');
        }
        if(k == 2){
            if(n == 1 || n == 2){
                return string(n, '8');
            }
            return "8" + string(n-2, '9') + "8";
        }
        if(k == 4){
            if(n <= 4){
                return string(n, '8');
            }
            return "88" + string(n-4, '9') + "88";
        }
        if(k == 5){
            if(n <= 2){
                return string(n, '5');
            }
            return "5" + string(n-2, '9') + "5";
        }
        if(k == 8){
            if(n <= 6){
                return string(n, '8');
            }
            return "888" + string(n-6, '9') + "888";
        }
        if(k == 6){
            if(n <= 2){
                return string(n, '6');
            }
            if(n % 2 == 0){
                return "8" + string(n/2-2, '9') + "77" + string(n/2-2, '9') + "8";
            }
            return "8" + string(n/2-1, '9') + "8" + string(n/2-1, '9') + "8";
        }
        if(k == 7){
            if(n <= 2){
                return string(n, '7');
            }
            int arr[] = {1, 3, 2, 6, 4, 5};
            int slen = (n-1)/2;
            string res = string(n, '0');
            int cur = 0;
            for(int i = 0; i < slen; i++){
                res[i] = '9';
                cur += 9 * arr[i%6];
                int z = n-1-i;
                res[z] = '9';
                cur += 9 * arr[z%6];
            }
            cur %= 7;
            int mp = arr[(n/2) % 6];
            if(n % 2 == 0){
                mp = (arr[(n/2-1) % 6] + mp) % 7;
            }
            int nb = -1;
            for(int i = 9; i >= 0; i--){
                if((cur + mp * i) % 7 == 0){
                    nb = i;
                    break;
                }
            }
            assert(nb != -1);
            res[n/2] = '0'+nb;
            res[(n-1)/2] = '0'+nb;
            return res;
        }
        return "goober";
    }
};