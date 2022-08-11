#include <iostream>
using namespace std;

int main() 
{
	int n, a, b, c, d;
	cin>>n;
	while(n--)
	{
	    cin>>a>>b>>c>>d;
    	if(a-c == b-d)
    	    cout<<"Any\n";
    	else if(a-c < b-d)
    	    cout<<"First\n";
    	else
    	    cout<<"Second\n";
	}
	return 0;
}
