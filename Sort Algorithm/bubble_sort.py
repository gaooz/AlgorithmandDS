# encoding=utf-8
# date 2016-09-13
# dfg
# bubble sort

def bubble_sort(arr, asc = True):
    '''
    冒泡排序
    时间复杂度：O(n2) 待排序列基本有序时达到最好的时间复杂度：O(n)
    空间复杂度：O(1)
    稳定的算法。
    :param arr:待排序列 asc = True升序排序，否则降序排序
    :return: 有序列表
    '''

    length = len(arr)
    if asc is True:
        for i in range(length-1):
            for j in range(i+1, length):
                if arr[i] > arr[j]:
                    temp = arr[i]
                    arr[i] = arr[j]
                    arr[j] = temp

            print arr
    else:
        for i in range(length-1):
            for j in range(i+1, length):
                if arr[i] < arr[j]:
                    temp = arr[i]
                    arr[i] = arr[j]
                    arr[j] = temp

            print arr
    return arr

if __name__ == "__main__":
    arr = [10,9,8,11,22,1,3,4]
    arr = bubble_sort(arr, False)
    print arr
