# encoding=utf-8
# date 2016-09-13
# dfg
# insert sort

def insert_sort(arr, asc = True):
    '''
    简单插入排序
    时间复杂度：O(n2) 待排序列基本有序时达到最好的时间复杂度：O(n)
    空间复杂度：O(1)
    是稳定的排序算法。
    :param arr: 待排序列
    :param asc: 默认升序排序，否则降序
    :return: 有序的列表
    '''

    length = len(arr)
    if asc is True:
        for i in range(1, length):
            temp = arr[i]
            j = i
            while j >0 and temp < arr[j-1]:
                arr[j] = arr[j-1]
                j = j-1
            arr[j] = temp
            print arr
    else:
        for i in range(1, length):
            temp = arr[i]
            j = i
            while j >0 and temp > arr[j-1]:
                arr[j] = arr[j-1]
                j = j-1
            arr[j] = temp
            print arr
    return arr

if __name__ == "__main__":
    arr = [10,9,8,11,22,1,3,4]
    insert_sort(arr)