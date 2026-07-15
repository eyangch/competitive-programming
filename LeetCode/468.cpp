class Solution {
public:
    bool isNum(string s, bool isHex){
        string ns;
        int ita;
        if(isHex){
            ns = "0123456789abcdef";
            ita = 16;
        }else{
            ns = "0123456789";
            ita = 10;
        }
        for(int i = 0; i < s.length(); i++){
            bool good = false;
            for(int j = 0; j < ita; j++){
                if(tolower(s[i]) == ns[j]){
                    good = true;
                    break;
                }
            }
            if(good == false){
                return false;
            }
        }
        return true;
    }
    bool isIPv4(vector<string> ipstuff){
        if(ipstuff.size() != 4){
            return false;
        }
        try{
            for(int i = 0; i < 4; i++){
                
                if(!isNum(ipstuff[i], false)){
                    throw 0;
                }
                int x = stoi(ipstuff[i]);
                if(x > 255 || x < 0){
                    return false;
                }
            }
        }catch(...){
            return false;
        }
        return true;
    }
    bool isIPv6(vector<string> ip6stuff){
        if(ip6stuff.size() != 8){
            return false;
        }
        try{
            for(int i = 0; i < 8; i++){
                if(!isNum(ip6stuff[i], true) || ip6stuff[i].length() > 4){
                    throw 0;
                }
                int x = stoi(ip6stuff[i], nullptr, 16);
            }
        }catch(...){
            return false;
        }
        return true;
    }
    string validIPAddress(string IP) {
        stringstream ipdelim(IP);
        string tmp;
        vector<string> ipstuff;
        bool possible = true;
        int c1 = 1;
        size_t f = IP.find(".");
        while(f != string::npos){
            f = IP.find(".", f + 1);
            c1++;
        }
        if(c1 == 4){
            while(getline(ipdelim, tmp, '.')){
                if(tmp[0] == '0' && tmp.length() > 1){
                    possible = false;
                    break;
                }
                ipstuff.push_back(tmp);
            }
            if(possible && isIPv4(ipstuff)){
                return "IPv4";
            }
        }
        stringstream ipdelim6(IP);
        string tmp6;
        vector<string> ip6stuff;
        int c2 = 1;
        size_t f2 = IP.find(":");
        while(f2 != string::npos){
            f2 = IP.find(":", f2 + 1);
            c2++;
        }
        if(c2 == 8){
            while(getline(ipdelim6, tmp6, ':')){
                ip6stuff.push_back(tmp6);
            }
            if(isIPv6(ip6stuff)){
                return "IPv6";
            }
        }
        return "Neither";
    }
};