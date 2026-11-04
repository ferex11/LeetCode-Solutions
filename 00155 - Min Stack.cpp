class MinStack {
private:
  stack<pair<int, int>> st;
public:
  MinStack() {
  }
  
  void push(int value) {
    int mn = value;
    if (!st.empty()) {
      mn = min(mn, st.top().second);
    }
    st.push({value, mn});
  }
  
  void pop() {
    st.pop();
  }
  
  int top() {
    return st.top().first;
  }
  
  int getMin() {
    return st.top().second;
  }
};
