class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double slope;
        bool vertical=0;
        if((coordinates[1][0]-coordinates[0][0])!=0)
            slope=(coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]);
        else
            vertical=1;
        
        for(int i=2; i<coordinates.size(); i++)
        {
            if((vertical and (coordinates[i][0]-coordinates[i-1][0]))
              or !vertical and !(coordinates[i][0]-coordinates[i-1][0]))
                return false;
            if(((double)(coordinates[i][1]-coordinates[i-1][1])/(coordinates[i][0]-coordinates[i-1][0]))!=slope)
                return false;
        }
        return true;
    }
};