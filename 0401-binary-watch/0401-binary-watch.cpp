class Solution {
public:
    void solve(string& s, int start, int num, vector<string>& res){
        
        
        int hr = stoi(s.substr(0,4),0,2);
        int min = stoi(s.substr(4,6),0,2);
        
        if(hr > 11 || min > 59){
            return;
        }
        
        if(num==0){
            res.push_back(to_string(hr) + ":" + (min < 10 ? "0" : "") + to_string(min));
            return;
        }
        
        
        for(int i=start; i<s.length(); ++i){
            s[i] = '1';
            solve(s, i+1, num-1, res);
            s[i] = '0';
        }
    }
    
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        string s = "0000000000";
        solve(s, 0, num, res);
        return res;
    }
};