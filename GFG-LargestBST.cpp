struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution
{
    public:

        void largestBstRecursion(Node *root, int &maxVal, int &minVal, int &bstSize, bool &isBst)
        {
            if(root == NULL)
            {
                isBst = true;
                return;
            }
            bool isLeftBst = false, isRightBst = false;
        	int leftSize = 0, rightSize = 0;
        	int leftMaxVal = INT_MIN, leftMinVal = INT_MAX, rightMaxVal = INT_MIN, rightMinVal = INT_MAX;
        	largestBstRecursion(root->left, leftMaxVal, leftMinVal, leftSize, isLeftBst);
        	largestBstRecursion(root->right, rightMaxVal, rightMinVal, rightSize, isRightBst);
        	maxVal = max(root->data, max(leftMaxVal, rightMaxVal));
        	minVal = min(root->data, min(leftMinVal, rightMinVal));
        	if (isLeftBst && isRightBst && leftMaxVal < root->data && rightMinVal > root->data) 
        	{
        		isBst = true;
        		bstSize = 1 + leftSize + rightSize;
        	} 
        	else 
        	{
        		bstSize = max(leftSize, rightSize);
        	}
        }
    
        int largestBst(Node *root)
        {
        	int maxVal = INT_MIN;
        	int minVal = INT_MAX;
        	bool isBst = false;
        	int bstSize = 0;
        	largestBstRecursion(root, maxVal, minVal, bstSize, isBst);
        	return bstSize;
        }
};
