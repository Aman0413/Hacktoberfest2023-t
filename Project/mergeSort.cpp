#include <iostream>
#include <vector>
using namespace std;

void mergeArray(vector<int> &arr, int s, int e)
{
  int mid = s + (e - s) / 2;
  int len1 = mid - s + 1;
  int len2 = e - mid;

  int *first = new int[len1];
  int *second = new int[len2];

  int mainArrayIndex = s;
  for (int i = 0; i < len1; i++)
  {
    first[i] = arr[mainArrayIndex++];
  }

  mainArrayIndex = mid + 1;
  for (int i = 0; i < len2; i++)
  {
    second[i] = arr[mainArrayIndex++];
  }

  int index1 = 0;
  int index2 = 0;
  mainArrayIndex = s;

  while (index1 < len1 && index2 < len2)
  {
    if (first[index1] < second[index2])
    {
      arr[mainArrayIndex++] = first[index1++];
    }
    else
    {
      arr[mainArrayIndex++] = second[index2++];
    }
  }

  while (index1 < len1)
  {
    arr[mainArrayIndex++] = first[index1++];
  }
  while (index2 < len2)
  {
    arr[mainArrayIndex++] = second[index2++];
  }

  delete[] first;
  delete[] second;
}

void mergeSort(vector<int> &arr, int s, int e)
{
  if (s >= e)
    return;

  int mid = s + (e - s) / 2;
  // left part sort
  mergeSort(arr, s, mid);

  // right part sort
  mergeSort(arr, mid + 1, e);

  // merge array
  mergeArray(arr, s, e);
}
int main()
{
  vector<int> arr;
  arr.push_back(12);
  arr.push_back(2);
  arr.push_back(1);
  arr.push_back(0);
  arr.push_back(16);
  int s = 0;
  int e = 6 - 1;

  mergeSort(arr, s, e);
  for (int i : arr)
  {
    cout << i << endl;
  }
  return 0;
}
