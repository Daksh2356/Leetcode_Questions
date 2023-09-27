class Solution {
public:
    string decodeAtIndex(string s, int k) {
        queue<char> encoded ;

        for(int i =0 ; i<s.size(); i++)
        {
            encoded.push(s[i]);
        }

        string res = "";

        while(!encoded.empty())
        {
            char c = encoded.front();

            if(!isdigit(c))
            {
                res = res + c;
            }
            else 
            {
                int d = c - '0';
                string tape = res;
                for(int i = 1; i < d; i++) {
                    res = res + tape;
                }
            }

            encoded.pop();
        }

        return res ;
    }
};