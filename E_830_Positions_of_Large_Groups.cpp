class Solution {
public:
    vector<vector<int>>largeGroupPositions(string S) {
        vector<vector<int>> res;
        if((int)S.length() < 3) return res;
        char a;

        int i = 0;
        while(S[i] != '\0')
        {
            int j = 0;
            a = S[i];
            while(a == S[i + j])
            {
                j++;
            }
            if(j >= 3)
                res.push_back({ i, i+j-1 });
            i+=j; 
        }
        return res;
    }
};