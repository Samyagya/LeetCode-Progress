// Last updated: 01/08/2026, 22:46:15
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for(int i = 0 ; i < tokens.size() ; i ++){
            if(tokens[i] == "+"){
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                int sum = a + b;
                numbers.push(sum);
            }else if(tokens[i] == "*"){
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                int prod = a * b;
                numbers.push(prod);
            }else if(tokens[i] == "-"){
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                int diff = a - b;
                numbers.push(diff);
            }else if(tokens[i] == "/"){
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                int div = a / b;
                numbers.push(div);
            }else{
                numbers.push(stoi(tokens[i]));
            }
        }
        return numbers.top();
    }
};