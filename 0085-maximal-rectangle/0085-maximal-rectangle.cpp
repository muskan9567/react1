class Solution {
public:

    vector<int> nextsmallerright(vector<int>& matrix, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; i--) {
            int curr = matrix[i];
            while(s.top() != -1 && matrix[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> nextsmallerleft(vector<int>& matrix, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            int curr = matrix[i];
            while(s.top() != -1 && matrix[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int findarea(vector<int>& matrix, int m) {
        vector<int> NSR = nextsmallerright(matrix, m);
        vector<int> NSL = nextsmallerleft(matrix, m);
        int area = INT_MIN;
        for(int i = 0; i < m; i++) {
            int length = matrix[i];
            if(NSR[i] == -1) {
                NSR[i] = m;
            }
            int width = NSR[i] - NSL[i] - 1;
            int newarea = length * width;
            area = max(area, newarea);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> temp(m, 0);

        for(int j = 0; j < m; j++) {
            temp[j] = matrix[0][j] - '0';
        }

        int area = findarea(temp, m);

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    temp[j] = temp[j] + 1;
                }
                else {
                    temp[j] = 0;
                }
            }
            area = max(area, findarea(temp, m));
        }
        return area;
    }
};