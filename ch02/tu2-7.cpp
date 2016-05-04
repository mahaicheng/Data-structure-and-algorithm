/*************************************************************************
	> 文件名: tu2-7.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月09日 星期三 18时19分00秒
 ************************************************************************/

#include<vector>
#include<iostream>
using std::vector;


int maxSubSumRec(const vector<int>& a, int left, int right)
{
    if (left == right){      //base case
        return a[left];
    }

    int center = (left + right) / 2;
    int maxLeftSum = maxSubSumRec(a, left, center);
    int maxRightSum = maxSubSumRec(a, center + 1, right);

    int maxLeftBoardSum = 0, leftBoardSum = 0;
    for (int index = center; index >= left; --index){
        leftBoardSum += a[index];
        if (maxLeftBoardSum < leftBoardSum){
            maxLeftBoardSum = leftBoardSum;
        }
    }

    int maxRightBoardSum = 0, rightBoardSum = 0;
    for (int index = center + 1; index <= right; ++index){
        rightBoardSum += a[index];
        if (maxRightBoardSum < rightBoardSum){
            maxRightBoardSum = rightBoardSum;
        }
    }

    int maxBoardSum = maxLeftBoardSum + maxRightBoardSum;

    if (maxLeftSum < maxRightSum){
        if (maxRightSum < maxBoardSum){
            return maxBoardSum;
        }
        else {
            return maxRightSum;
        }
    }
    else {
        if (maxLeftSum < maxBoardSum){
            return maxBoardSum;
        }
        else {
            return maxLeftSum;
        }
    }
}

int maxSubSum(const vector<int>& a)
{
    std::cout<<"Using tu2-7.cpp"<<std::endl;
    return maxSubSumRec(a, 0, a.size() - 1);
}
