int Solution::romanToInt(string s) 
{
    map<char, int> m;
    m.insert(pair<char, int>('I', 1));
    m.insert(pair<char, int>('V', 5));
    m.insert(pair<char, int>('X', 10));
    m.insert(pair<char, int>('L', 50));
    m.insert(pair<char, int>('C', 100));
    m.insert(pair<char, int>('D', 500));
    m.insert(pair<char, int>('M', 1000));
    int num = 0;
    for(auto its = s.begin(); its != s.end(); its++)
    {
        if(m[*its] < m[*(its+1)])
        {
            num -= m[*its];
        }
        else 
        {
            num += m[*its];
        }
    }
    return num;
}
