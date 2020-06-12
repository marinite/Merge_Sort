#include <iostream>
#include <list>
using namespace std;

void Merge(int length, int* array_sort, int first, int last)
{
	int middle, start, final, j;
	int* mas = new int[length];

	middle = (first + last) / 2; //���������� �������� ��������
	start = first; //������ ����� �����
	final = middle + 1; //������ ������ �����

	for (j = first; j <= last; j++) //��������� �� ������ �� �����
		if ((start <= middle) && ((final > last) || (array_sort[start] < array_sort[final])))
		{
			mas[j] = array_sort[start];
			start++;
		}
		else
		{
			mas[j] = array_sort[final];
			final++;
		}

	//����������� ���������� � ������
	for (j = first; j <= last; j++)
	{
		array_sort[j] = mas[j];
	}

	delete[]mas;
}
//����������� ��������� ����������
void Merge_Sort(int length, int* array_sort, int first, int last)
{
	{
		if (first < last)
		{
			Merge_Sort(length, array_sort, first, (first + last) / 2); //���������� ����� �����
			Merge_Sort(length, array_sort, (first + last) / 2 + 1, last); //���������� ������ �����
			Merge(length, array_sort, first, last); //������� ���� ������
		}
	}
}

int main()
{
	int length=0;
	cout << "Enter the size of the array: ";
	cin >> length;
	int* array_sort = new int[length];
	for (int i = 0; i < length; i++)
	{
		cout << i+1 << ": "; 
		cin >> array_sort[i];
	}

	Merge_Sort(length, array_sort, 0, length-1);

	cout << "Sorted array: ";
	for (int i = 0; i < length; i++)
	{
		cout << array_sort[i] << " ";
	}

	delete[] array_sort;
	return 0;
}