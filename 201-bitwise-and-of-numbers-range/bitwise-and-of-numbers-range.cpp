class Solution {
public:
    vector<int> convertor(int x){
        vector<int> ans(32,0);
        int i=31;
        while(x>0){
            if(x%2==1){
                ans[i] = 1;
            }
            x/=2;
            i--;
        }
        return ans;
    }

    int revConvertor(vector<int> bits){
        int ans=0;
        long long current=1;
        for(int i=31; i>=0; i--){
            if(bits[i] == 1){
                ans+=current;

            }
            if(i==0){
                break;
            }
            current*=2;
        }
        return ans;
    }

    int rangeBitwiseAnd(int left, int right) {
        long long x=1;
        
        vector<int> bitsLeft= convertor(left);
        vector<int> bitsRight= convertor(right);

        vector<int> ansBits(32,0);
        for(int i=31; i>=0; i--){
            int diff=right-left;

            if(diff < x && bitsLeft[i]!=0 && bitsRight[i]!=0){
                ansBits[i]=1;
            }
            x*=2;
        }
        int ans=revConvertor(ansBits);

        return ans;
    }
};