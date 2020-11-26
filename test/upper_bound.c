/**
 题目描述
请实现有重复数字的有序数组的二分查找。
输出在数组中第一个大于等于查找值的位置，如果数组中不存在这样的数，则输出数组长度加一。
 * 二分查找
 * @param n int整型 数组长度
 * @param v int整型 查找值
 * @param a int整型一维数组 有序数组
 * @param aLen int a数组长度
 * @return int整型
 */
int upper_bound_(int n, int v, int* a, int aLen ) {
    // write code here
    int l = 0, r = n;
    if (a[n-1] < v)
        return n+1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (a[mid] < v)  //在右边
            l = mid + 1;
        else             //a[mid] >= v时需要往左边继续查找
            r = mid;
        
    }
    return l+1;
}