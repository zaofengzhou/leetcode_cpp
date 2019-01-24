//
// Created by zfzhou on 1/24/2019.
//
#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int ret = 0;
    heights.push_back(0);
    vector<int> index;  //用来把下标压栈

    for(int i = 0; i < heights.size(); i++)
    {
        while(index.size() > 0 && heights[index.back()] >= heights[i])
        {
            int h = heights[index.back()];
            index.pop_back();

            int sidx = index.size() > 0 ? index.back() : -1;
            if(h * (i-sidx-1) > ret)
                ret = h * (i-sidx-1);
        }
        index.push_back(i);
    }

    return ret;
}

int largestRectangleArea1(vector<int>& heights) {
    int ret = 0;
    heights.push_back(0);
    stack<int> index;  //用来把下标压栈

    for(int i = 0; i < heights.size(); i++)
    {
        while(index.size() > 0 && heights[index.top()] >= heights[i])
        {
            int h = heights[index.top()];
            index.pop();

            int l = index.size() > 0 ? index.top() : -1;
            ret = max(ret, h*(i-l-1));
        }
        index.push(i);
    }

    return ret;
}

int main()
{
    vector<int> heights = {2,1,5,6,2,3};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}
