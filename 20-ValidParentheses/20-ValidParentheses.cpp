// Last updated: 01/08/2026, 22:47:52
class Solution {
public:
    bool isValid(string s) {
        stack<int> bracketStack;
        for(int i = 0 ; i < s.size() ; i ++){
            if(s[i] == '(' || s[i] =='{' || s[i] == '['){
                bracketStack.push(s[i]);
            }else{
                if(bracketStack.empty()) return false;
                if(s[i] == ')'){
                    if(bracketStack.top() == '(') {
                        bracketStack.pop();
                    }else{
                        return false;
                    }
                }else if(s[i] == '}'){
                    if(bracketStack.top() == '{'){
                        bracketStack.pop();
                    }else{
                        return false;
                    }
                }else{
                    if(bracketStack.top() == '['){
                        bracketStack.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        if(bracketStack.empty()){
            return true;
        }
        return false;
    }
};