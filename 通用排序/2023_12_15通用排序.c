#include<stdio.h>
#include<string.h>
struct stu
{
	char name[20];
	int age;
};
int cmp(const void* e1, const void* e2)
{//具体排序方法函数 
	return *(int*)e1 - *(int*)e2;
}
void swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
int cmp_age(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}
int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);//库函数strcmp按字母顺序给字符串排序
}

int cmp_float(const void* e1, const void* e2)
{
	if (*(float*)e1 - *(float*)e2 > 0)
	{
		return 1;
	}
	else if (*(float*)e1 - *(float*)e2 < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void bubble_sort(void* base, int sz, int width, int(*cmp)(void* e1, void* e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{//排序的趟数
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{//每一趟要排序的次数
			if (cmp((char*)base + j * width, (char*)base + (1 + j) * width) > 0)
			{//交换排序数据位置
				swap((char*)base + j * width, (char*)base + (1 + j) * width, width);

			}
		}
	}
}
void test1()//小数排序
{
	float f[] = { 10.0,9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	bubble_sort(f, sz, sizeof(f[0]), cmp_float);
	for (int i = 0; i < sz; i++)
	{
		printf("%f ", f[i]);
	}
}

void test2()//数组排序
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
void test3()//结构体年龄排序
{
	struct stu s[] = { {"tj",20},{"lt",15},{"zs",21} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_age);
}
void test4()// 结构体姓名排序
{
	struct stu s[] = { {"cj",20},{"bt",15},{"as",21} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_name);
}
int main()
{
	test1();
}