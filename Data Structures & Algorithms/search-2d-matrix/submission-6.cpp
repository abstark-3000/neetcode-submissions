class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int n=mat.size(),m=mat[0].size();
        int i=0,j=n-1;
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            if(mat[mid][0]==tar)return true;
            else if(mat[mid][0]<tar)i++;
            else j--;
        }
        //j->actual index
        if(j<0)return false;
        int left=0,right=m-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(mat[j][mid]==tar)return true;
            else if(mat[j][mid]>tar)right--;
            else left++;
        }
        return false;
    }
};
