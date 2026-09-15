class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        int n = students.size();
        int m = sandwiches.size();
        for(int i = 0 ; i<n ; i++){
            q.push(students[i]);
        }
        stack<int>st;
        for(int i = m-1 ; i>=0 ;i-- ){
            st.push(sandwiches[i]);
        }
        int count = 0;
        
        while(q.size()>0 && count!= q.size()){
            if(q.front() == st.top()){
                q.pop();
                st.pop();
                count = 0;
            }
            else{
                q.push(q.front());
                q.pop();
                count++;
            }
        }
        return q.size();
    }
};