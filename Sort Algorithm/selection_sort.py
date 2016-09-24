# encoding=utf-8
# date 2016-09-13
# dfg
# selection sort

def selection_sort(arr, asc = True):
    '''
    选择排序算法
    时间复杂度最好最坏：O(n2) 元素比较次数和待排序列排序顺序无关。
    空间复杂度：O(1)
    不稳定的算法。
    :param arr: 待排序列
    :param asc: 默认升序排序，否则降序
    :return: 有序的列表
    '''

    length = len(arr)
    if asc is True:
        for i in range(length-1, 0, -1):
            index = i
            for j in range(i-1, -1, -1):
                if arr[j] > arr[index]:
                    index = j
            if index != i:
                temp = arr[i]
                arr[i] = arr[index]
                arr[index] = temp
            print arr
    else:
        for i in range(length-1, 0, -1):
            index = i
            for j in range(i-1, -1, -1):
                if arr[j] < arr[index]:
                    index = j
            if index != i:
                temp = arr[i]
                arr[i] = arr[index]
                arr[index] = temp
            print arr

if __name__ == "__main__":
    arr = [10,9,8,11,22,1,3,4]
    selection_sort(arr, False)


