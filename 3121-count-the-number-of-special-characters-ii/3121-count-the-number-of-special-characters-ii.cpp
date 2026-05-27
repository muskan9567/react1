class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<int> lower(26, -1);
        vector<int> upper(26, -1);

        // store first occurrence
        for(int i = 0; i < word.length(); i++) {

            char ch = word[i];

            // lowercase
            if(ch >= 'a' && ch <= 'z') {

            
                    lower[ch - 'a'] = i;
                
            }

            // uppercase
            else if(ch >= 'A' && ch <= 'Z') {

                if(upper[ch - 'A'] == -1) {
                    upper[ch - 'A'] = i;
                }
            }
        }

        int count = 0;

        // check special characters
        for(int i = 0; i < 26; i++) {

            if(lower[i] != -1 &&
               upper[i] != -1 &&
               lower[i] < upper[i]) {

                count++;
            }
        }

        return count;
    }
};