class Solution {
public:
    
    vector<int> prs(vector<int>&heights){
        stack<int> st;
        int n = heights.size();
        vector<int> ps;
        for(int i=0;i<n;i++){
            
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) ps.push_back(-1);
            else ps.push_back(st.top());
            
            st.push(i);
        }
        return ps;
    }
    vector<int> nrs(vector<int>&heights){
        stack<int> st;
        int n = heights.size();
        vector<int> ns;
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) ns.push_back(n);
            else ns.push_back(st.top());
            
            st.push(i);
        }
        reverse(ns.begin(),ns.end());
        return ns ;
    }
    int solve(vector<int>& heights) {
        
        vector<int> p = prs(heights);
        vector<int> s = nrs(heights);
        
        int ans = 0 ;
        for(int i=0;i<heights.size();i++){
            int tmp = (s[i]-p[i]-1)*heights[i];
            ans = max(ans,tmp);
        }  
        return ans ;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            }
            int area = solve(heights);
            ans = max(ans , area);
        }
        return ans ;
    }
};