class Solution {
public:
    string intToRoman(int num) {
        vector<int> val={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> sym={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string res="";
        int i=0;
        while(num!=0){
            int times=num/val[i];
            while(times--) res+=sym[i];
            num=num%val[i];
            i++;
        }
        return res;
        
    }
};