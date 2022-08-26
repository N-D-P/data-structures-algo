Question Link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Video -> https://www.youtube.com/watch?v=eMSfBgbiEjk&list=PLByG0Le9gW1ukPzWdArXFN8iHh5OgUWOV

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Approach 1 ->

Traverse the array, for each element traverse the right and check the difference for each element on 
right, store the maximum diff.

Approch 2 ->

keep 2 variables, maxPro=0 & minStk=INT_MAX, traverse the array, check - minStk = min(minStk, Arr[i]) 
and for profit, check - maxPro = max(maxPro, Arr[i] - minStk)

 int maxProfit(vector<int>& prices) {
    int MinPri=INT_MAX;
    int MaxPro=0;
    for(int i=0;i<prices.size();i++)
    {
        MinPri = min(MinPri,prices[i]);
        MaxPro = max(MaxPro,prices[i]-MinPri);
    }
    return MaxPro;   
}