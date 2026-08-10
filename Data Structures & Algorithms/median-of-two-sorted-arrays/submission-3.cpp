class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        int a=n1.size(),b=n2.size();
        if(a==0 && b==0)return 0;
        else if(a==0)
        {
            if(b%2==0)
            {
                int x=n2[b/2];
                int y=n2[b/2-1];
                return (x+y)/2.0;
            }else return 1.0*n2[b/2];
        }
        else if(b==0)
        {
            if(a%2==0)
            {
                int x=n1[a/2];
                int y=n1[a/2-1];
                return (x+y)/2.0;
            }else return 1.0*n1[a/2];
        }
        int i=0,j=n1.size();
        double ans=0;
        while(i<=j)
        {
            int cut1=i+(j-i)/2;
            int cut2=(a+b+1)/2-cut1;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(cut1>0)l1=n1[cut1-1];
            if(cut1<a)r1=n1[cut1];
            if(cut2>0)l2=n2[cut2-1];
            if(cut2<b)r2=n2[cut2];
            if(l1<=r2 && l2<=r1)
            {
                if((a+b)%2!=0)
                {
                    ans=1.0*max(l1,l2);
                    break;
                }
                ans=((max(l1,l2)+min(r1,r2))/2.0);
                break;
            }else if(l1>r2)j=cut1-1;
            else i=cut1+1;
        }
        return ans;
    }
};
