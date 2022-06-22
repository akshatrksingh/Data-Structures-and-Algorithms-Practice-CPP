/*
struct Item
{
    int value;
    int weight;
};
*/

class Solution
{
    public:
    static bool compare(Item a, Item b)
    {
        return (double)(a.value)/(double)(a.weight) >= (double)(b.value)/(double)(b.weight);
    }
    double fractionalKnapsack(int capacity, Item arr[], int n)
    {
        sort(arr, arr+n, compare);
        double currentWeight = 0, knapsackValue = 0;
        for(int i = 0; i < n; i++)
        {
            if(capacity <= 0) break;
            currentWeight = min(arr[i].weight, capacity);
            knapsackValue += min(arr[i].weight, capacity)*(double)(arr[i].value)/(double)(arr[i].weight);
            capacity -= currentWeight;
        }
        return knapsackValue;
    }
        
};
