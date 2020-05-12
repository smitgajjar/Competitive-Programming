class Solution {
public:
    int trustOf[1001];
    bool trustSomeone[1001];
    int findJudge(int N, vector<vector<int>>& trust) {
        memset(trustOf, 0, sizeof trustOf);
        memset(trustSomeone, 0, sizeof trustSomeone);
        for(int i=0; i<trust.size(); i++) {
            trustOf[trust[i][1]]++;
            trustSomeone[trust[i][0]]=true;
        }
        for(int i=1; i<=N; i++) {
            if(trustOf[i]==N-1 and trustSomeone[i]==false)
                return i;
        }
        return -1;
        
    }
};