# encoding=utf-8
# date 2016-09-23
# dfg
# count sort

def count_sort(arr, k):
    '''
    计数排序，时间复杂度：O(n),空间复杂度：O(k)
    适用于关键字取值在一定范围内的情况。
    :param arr: 待排序列
    :param k: 关键字的取值上限+1，下限为0
    :return:
    '''
    count = []
    # 初始化count数组
    for i in range(k):
        count.append(0)
    # 计算count数组
    for i in range(len(arr)):
        count[arr[i]] = count[arr[i]] + 1
    # 根据count数组对序列进行排序
    arr_sorted = []
    for key in range(len(count)):
        for key_num in [key for repeat in range(count[key])]:# 列表解析生成j个重复的i
            arr_sorted.append(key_num)
    # 返回排序好的元素序列
    return arr_sorted

if __name__ == "__main__":
    arr = [0, 0 , 3, 1, 1, 2, 6]
    arr = count_sort(arr, 7)
    print  arr



