class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        string conc = s + s;

        if(conc.find(goal)!=std::string::npos){
            return true;
        }
        return false;
        
    }
};