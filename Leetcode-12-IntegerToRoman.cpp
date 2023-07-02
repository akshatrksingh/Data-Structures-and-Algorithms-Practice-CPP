class Solution 
{
    public:
        string intToRoman(int num) 
        {
            string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX","X"};
            string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC","C"};
            string huns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM","M"};
            string thos[] = {"","M","MM","MMM"};
            string res = thos[(num/1000)%10] + huns[(num/100)%10] + tens[(num/10)%10] + ones[num%10];
            return res;
        }
};
