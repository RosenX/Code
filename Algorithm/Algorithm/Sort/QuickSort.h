#pragma once

#include "../utils.h"

using namespace std;

/*
���ַ�������ȥ���ȶ��ģ����������Ԫ����ͬ
��ѡ����ͬԪ���е�һ����Ϊkey����᲻�ȶ�
���У��������...7....7...2...2...��key��3��
�������key��������7֮�䣬�����ǲ��ȶ���
*/

inline int randIndex(const int &begin, const int &end) {
	return rand() % (end - begin + 1) + begin;
}

int partion(vector<int> &array, int begin, int end) {
	int small = begin - 1;
	int pivot = randIndex(begin, end);
	swap(array[pivot], array[end]);
	for (int i = begin; i <= end; i++) {
		if (array[i] <= array[end]) {
			small++;
			if (i == small) continue;
			swap(array[i], array[small]);
		}
	}
	return small;
}

int partion2(vector<int> &array, int begin, int end) {
	int pivot = randIndex(begin, end);
	swap(array[pivot], array[end]);
	int l = begin, r = end;
    while (l < r) {
        while (l < r && array[l] <= array[r]) l++;
        swap(array[l], array[r]);
        while (l < r && array[l] <= array[r]) r--;
        swap(array[l], array[r]);
    }
    return l;
}

void quickSort(vector<int> &array, int begin, int end) {
	if (begin >= end) return;
	int index = partion2(array, begin, end);
	quickSort(array, begin, index - 1);
	quickSort(array, index + 1, end);
}
