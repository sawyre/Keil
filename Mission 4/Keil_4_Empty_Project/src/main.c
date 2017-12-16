#include "CMSIS/stm32f10x.h" 
#include "string.h" 
#include "stdint.h"

struct array11{
	int32_t mass4[11];
};

volatile int32_t j; 

void true_sort(int32_t *buf, int32_t left, int32_t right){
  int32_t pivot; // разрешающий элемент
  int32_t l_hold = left; //левая граница
  int32_t r_hold = right; // правая граница
  pivot = buf[left];
  while (left < right) // пока границы не сомкнутся
  {
    while ((buf[right] >= pivot) && (left < right))
      right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      buf[left] = buf[right]; // перемещаем элемент [right] на место разрешающего
      left++; // сдвигаем левую границу вправо 
    }
    while ((buf[left] <= pivot) && (left < right))
      left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
    if (left != right) // если границы не сомкнулись
    { 
      buf[right] = buf[left]; // перемещаем элемент [left] на место [right]
      right--; // сдвигаем правую границу вправо 
    }
  }
  buf[left] = pivot; // ставим разрешающий элемент на место
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
    true_sort(buf, left, pivot - 1);
  if (right > pivot)
    true_sort(buf, pivot + 1, right);
}

void sort(int32_t *buf, int32_t size){
	int32_t left = 0;
	int32_t right = size-1;
  int32_t pivot; // разрешающий элемент
  int32_t l_hold = left; //левая граница
  int32_t r_hold = right; // правая граница
  pivot = buf[left];
  while (left < right) // пока границы не сомкнутся
  {
    while ((buf[right] >= pivot) && (left < right))
      right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      buf[left] = buf[right]; // перемещаем элемент [right] на место разрешающего
      left++; // сдвигаем левую границу вправо 
    }
    while ((buf[left] <= pivot) && (left < right))
      left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
    if (left != right) // если границы не сомкнулись
    { 
      buf[right] = buf[left]; // перемещаем элемент [left] на место [right]
      right--; // сдвигаем правую границу вправо 
    }
  }
  buf[left] = pivot; // ставим разрешающий элемент на место
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
    true_sort(buf, left, pivot - 1);
  if (right > pivot)
    true_sort(buf, pivot + 1, right);
}

int true_getOrderStatistic(int32_t *buf, int32_t left, int32_t right, int32_t j){
  int32_t pivot; // разрешающий элемент
  int32_t l_hold = left; //левая граница сортируемой части массива
  int32_t r_hold = right; // правая граница сортируемой части массива
  pivot = buf[left];
  while (left < right) 
  {
    while ((buf[right] >= pivot) && (left < right))
      right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
    if (left != right) 
    {
      buf[left] = buf[right]; // перемещаем элемент [right] на место разрешающего
      left++; 
    }
    while ((buf[left] <= pivot) && (left < right))
      left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
    if (left != right) 
    { 
      buf[right] = buf[left]; // перемещаем элемент [left] на место [right]
      right--; 
    }
  }
  buf[left] = pivot; // ставим разрешающий элемент на место
  pivot = left;
  left = l_hold;
  right = r_hold;
	if (pivot == j)
		return buf[pivot];
	else if (j < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
    true_getOrderStatistic(buf, left, pivot - 1, j);
  else
    true_getOrderStatistic(buf, pivot + 1, right, j);
}

int getOrderStatistic(int32_t *buf, int32_t size, int32_t j){
	int32_t left = 0;
	int32_t right = size-1;
  int32_t pivot; // разрешающий элемент
  int32_t l_hold = left; //левая граница сортируемой части массива
  int32_t r_hold = right; // правая граница сортируемой части массива
  pivot = buf[left];
  while (left < right) 
  {
    while ((buf[right] >= pivot) && (left < right))
      right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
    if (left != right) 
    {
      buf[left] = buf[right]; // перемещаем элемент [right] на место разрешающего
      left++; 
    }
    while ((buf[left] <= pivot) && (left < right))
      left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
    if (left != right) 
    { 
      buf[right] = buf[left]; // перемещаем элемент [left] на место [right]
      right--; 
    }
  }
  buf[left] = pivot; // ставим разрешающий элемент на место
  pivot = left;
  left = l_hold;
  right = r_hold;
	if (pivot == j)
		return buf[pivot];
	else if (j < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
    true_getOrderStatistic(buf, left, pivot - 1, j);
  else
    true_getOrderStatistic(buf, pivot + 1, right, j);
}

void true_strsort(struct array11 buf, int32_t left, int32_t right){
  int32_t pivot; // разрешающий элемент
  int32_t l_hold = left; //левая граница
  int32_t r_hold = right; // правая граница
  pivot = buf.mass4[left];
  while (left < right) // пока границы не сомкнутся
  {
    while ((buf.mass4[right] >= pivot) && (left < right))
      right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      buf.mass4[left] = buf.mass4[right]; // перемещаем элемент [right] на место разрешающего
      left++; // сдвигаем левую границу вправо 
    }
    while ((buf.mass4[left] <= pivot) && (left < right))
      left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
    if (left != right) // если границы не сомкнулись
    { 
      buf.mass4[right] = buf.mass4[left]; // перемещаем элемент [left] на место [right]
      right--; // сдвигаем правую границу вправо 
    }
  }
  buf.mass4[left] = pivot; // ставим разрешающий элемент на место
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
    true_strsort(buf, left, pivot - 1);
  if (right > pivot)
    true_strsort(buf, pivot + 1, right);
}

void strsort(struct array11 buf, int32_t size){
	int32_t left = 0;
	int32_t right = size-1;
  int32_t pivot; // разрешающий элемент
  int32_t l_hold = left; //левая граница
  int32_t r_hold = right; // правая граница
  pivot = buf.mass4[left];
  while (left < right) // пока границы не сомкнутся
  {
    while ((buf.mass4[right] >= pivot) && (left < right))
      right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      buf.mass4[left] = buf.mass4[right]; // перемещаем элемент [right] на место разрешающего
      left++; // сдвигаем левую границу вправо 
    }
    while ((buf.mass4[left] <= pivot) && (left < right))
      left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
    if (left != right) // если границы не сомкнулись
    { 
      buf.mass4[right] = buf.mass4[left]; // перемещаем элемент [left] на место [right]
      right--; // сдвигаем правую границу вправо 
    }
  }
  buf.mass4[left] = pivot; // ставим разрешающий элемент на место
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
    true_strsort(buf, left, pivot - 1);
  if (right > pivot)
    true_strsort(buf, pivot + 1, right);
}

int main(void) 
{
	int32_t mass1[10]={5,5,6,4,8,1,9,3,2,7};
	sort(mass1,10);
	int32_t mass2[13]={5,5,6,4,-4,0,0,8,1,9,3,2,7};
	j = getOrderStatistic(mass2,13,8);
	struct array11 arr;
	int32_t mass5[11]={0,4,6,8,4,-5,10,54,18,-12,56};
	for(int i=0; i<11; i++){
		arr.mass4[i]=mass5[i];
	}
	strsort(arr, 11);
	int32_t mass3[12]={5,6,4,-4,0,0,8,1,9,3,2,7};
	j = getOrderStatistic(mass3,12,4);
	while(1){
	}
	return(0); 
}