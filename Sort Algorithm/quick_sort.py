# encoding=utf-8
# date 2016-09-20
# dfg
# quick sort

def quick_sort(arr, left_index, right_index):
    '''
    快速排序，平均时间复杂度：(nlogn)，综合性能最好的排序算法。
    最坏：O(n2)，空间复杂度：O(1)，不稳定的排序算法。
    :param arr: 待排列表
    :param left_index: 左边元素索引
    :param right_index: 右边元素索引
    :return: None
    '''
    # 递归终止条件
    if left_index >= right_index:
        return None
    # 选择第一个元素为枢纽节点
    key = arr[left_index]
    # 左下标
    low = left_index
    # 右下标
    high = right_index
    while low < high:
        while low < high and key < arr[high]:
            high = high -1

        # 找到key > arr[high]的元素，交换
        arr[low] = arr[high]

        while low < high and key > arr[low]:
            low = low + 1

        # 找到key < arr[low]的元素，交换
        arr[high] = arr[low]

    # 此时必定low == high
    arr[low]= key
    # 递归排序左半部分序列
    quick_sort(arr, left_index, low-1)
    # 递归排序右半部分序列
    quick_sort(arr, low+1, right_index)

arr = [2,1,9,4,10]
quick_sort(arr, 0, 4)
print arr
