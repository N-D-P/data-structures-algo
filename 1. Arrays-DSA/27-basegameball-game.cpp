// Question Link -> https://leetcode.com/problems/baseball-game/


    int calPoints(vector<string>& A) {
        stack<int> stk;
        for(int i=0;i< A.size();i++) {
            if(A[i] == "C") {
                stk.pop();
            }
            else if(A[i] == "D") {
                int x = stk.top();
                x+=x;
                stk.push(x);
            }
            else if(A[i] == "+") {
                int f = stk.top(); stk.pop();
                int s = stk.top(); stk.pop();
                int r = f + s;
                stk.push(s);
                stk.push(f);
                stk.push(r);
            }
            else {
                int x = stoi(A[i]);
                stk.push(x);
            }
        }
        int res = 0;
        while(stk.size()) {
            res += stk.top();
            stk.pop();
        }
        
        
        return res;
    }