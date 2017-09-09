/*
*用另一个stack<int> trackMin来记录min值的变化，trackMin.top()表示当前最小值。
*当有新的xi<=trackMin.top()被压入时，将xi压入trackMin变为新的当前最小值。
*当xi==trackMin.top()时被pop出时，trackMin也同时pop。
*例如压入以下数后：
xi:    3 2 1 2 1 
trackMin: 3 2 1

此时如果pop，则变为
xi:    3 2 1 2
trackMin: 3 2
*
*/
class MinStack {
    stack<int> s;
    stack<int> trackMin;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(trackMin.empty() || x<=trackMin.top())
            trackMin.push(x);
        s.push(x);
    }
    
    void pop() {
        if(s.empty()) return;
        if(s.top()==trackMin.top())
            trackMin.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return trackMin.top();
    }
};
