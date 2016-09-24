# encoding=utf-8
# date 2016-09-22
# dfg
# merge sort

'''
归并排序，最常使用的是2路归并排序
归并排序分为两个部分：划分、归并
时间复杂度：O(nlongn),空间复杂度：O(n)
'''
# 归并
def merge(list, left, mid, right):
    '''
      将列表list中两个有序序列：list[left:mid],
      list[mid+1:right]归并成一个有序的序列：list[left:right]
    :param list:
    :param left:
    :param mid:
    :param right:
    :return:
    '''
    i = left
    j = mid + 1
    temp = []
    while i <= mid and j <= right:
        if list[i] < list[j]:
            temp.append(list[i])
            i = i+1
        else:
            temp.append(list[j])
            j = j+1
    while i <= mid:
        temp.append(list[i])
        i = i+1
    while j <= right:
        temp.append(list[j])
        j = j+1

    # 将临时表中数据复制到原理的表中
    index = range(left, right+1)
    for i in range(len(temp)):
        list[index[i]] = temp[i]

def merge_sort(arr, left, right):
    '''
      先对序列进行划分，再归并
    :param arr:
    :param left:
    :param right:
    :return:
    '''
    if left < right:
        # 划分
        mid = (left+right)/2
        merge_sort(arr, left, mid)
        merge_sort(arr, mid+1, right)
        # 归并
        merge(arr, left, mid, right)

if __name__ == "__main__":
    arr = [2,1,9,4,10, -1]
    merge_sort(arr, 0, 5)
    print arr

