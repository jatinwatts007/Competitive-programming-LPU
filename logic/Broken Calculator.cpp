class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans=0;
        while(target>startValue){
            ans++;
            if(target%2==0) target/=2;
            else target+=1;
            cout<<target<<" ";
        }
        if(target!=startValue) ans+=(startValue-target);
        return ans;
    }
};
