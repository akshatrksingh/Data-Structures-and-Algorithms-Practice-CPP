int Solution::solve(vector<vector<int> > &arr, int n) 
{
  vector<int> s1, s;
  vector<vector<int>> s2;
  int a = arr.size(), sum = 0, k;
  for(int i = 0; i < a-n+1; i++)
  {
      for(int j = 0; j < a; j++)
      {
          sum = 0;
          k = i;
          while(k < i+n)
          {
            sum += arr[k][j];
            k++;
          }
          s1.push_back(sum);
      }
      s2.push_back(s1);
      s1.clear();
  }
  for(int i = 0; i < s2.size(); i++)
  {
    for(int j = 0; j < s2[0].size()-n+1; j++)
    {
        sum = 0;
        for(int k = j; k < j+n; k++)
        {
            sum += s2[i][k];
        }
        s.push_back(sum);
    }
  }
  return *max_element(s.begin(), s.end());
}

