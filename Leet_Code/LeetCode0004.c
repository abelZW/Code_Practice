/*
两个排序数组的中位数查找
数组是有序的:
解题思路：要求O(log(m+n))的时间复杂度，一般来说都是分治法或者二分搜索。
假设两个有序序列共有n个元素（根据中位数的定义我们要分两种情况考虑）：
1、当n为奇数时，搜寻第(n/2+1)个元素\
2、当n为偶数时，搜寻第(n/2+1)和第(n/2)个元素，然后取他们的均值。
把这题抽象为“搜索两个有序序列的第k个元素”。
如果我们解决了这个k元素问题，那中位数不过是k的取值不同罢了。

解题：
对于第一个序列中前p个元素和第二个序列中前q个元素，
我们想要的最终结果是：p+q等于k-1,且一序列第p个元素和二序列第q个元素都小于总序列第k个元素。
因为总序列中，必然有k-1个元素小于等于第k个元素。
这样第p+1个元素或者第q+1个元素就是我们要找的第k个元素
通过二分法将问题规模缩小，假设p=k/2-1，则q=k-p-1，且p+q=k-1。
如果第一个序列第p个元素小于第二个序列第q个元素，
我们不确定二序列第q个元素是大了还是小了，但一序列的前p个元素肯定都小于目标，
所以我们将第一个序列前p个元素全部抛弃，形成一个较短的新序列。
然后，用新序列替代原先的第一个序列，再找其中的第k-p个元素（因为我们已经排除了p个元素，k需要更新为k-p），
依次递归。同理，如果第一个序列第p个元素大于第二个序列第q个元素，
我们则抛弃第二个序列的前q个元素。递归的终止条件有如下几种：
1、较短序列所有元素都被抛弃，则返回较长序列的第k个元素（在数组中下标是k-1）
2、一序列第p个元素等于二序列第q个元素，此时总序列第p+q=k-1个元素的后一个元素，也就是总序列的第k个元素
注意： 每次递归不仅要更新数组起始位置（起始位置之前的元素被抛弃），也要更新k的大小（扣除被抛弃的元素）

*/
#include <stdio.h>
#include <stdlib.h>

static double find_kth(int a[], int alen,int b[],int blen, int k)
{
    //确保alen<=blen
    //k为寻找的那个数
    if(alen > blen){
        return find_kth(b, blen, a, alen, k);
    }
    if(alen == 0){
        return b[k-1];
    }
    if(k == 1){
        return a[0]<b[0]?a[0]:b[0];
    }
    /*将k划分为两部分*/
    int ia = k/2 < alen ? k/2:alen;
    int ib = k - ia;
    if(a[ia-1] < b[ib-1]){
        return find_kth(a+ia, alen-ia, b, blen, k-ia);
    }
    else if(a[ia-1] > b[ib-1]){
        return find_kth(a, alen, b+ib, blen-ib, k-ib);
    }else{
        return a[ia-1];
    }
}

static double findMedianSortedArrays(int* nums1,int nums1size,int* nums2,int nums2size)
{
    int half = (nums1size + nums2size)/2;
    if( (nums1size + nums2size)&0x1)//判定是否为奇数
    {
        return find_kth(nums1,nums1size,nums2,nums2size,half+1);
    }
    else{
        return (find_kth(nums1,nums1size,nums2,nums2size,half) + find_kth(nums1,nums1size,nums2,nums2size,half+1))/2;
    }
}

int main()
{
    int len1[] = {1,2,4,5};
    int len2[] = {3,3,4,5};
    int size_len1 = sizeof(len1)/sizeof(len1[0]);
    int size_len2 = sizeof(len2)/sizeof(len2[0]);
    double media = findMedianSortedArrays(len1,size_len1,len2,size_len2);
    printf("Media is %2.1f\n",media);
}