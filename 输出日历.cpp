#include<iostream>
#include <iomanip>
using namespace std;

int monthLength[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//                      0  1   2   3   4    5   6   7   8  9   10  11  12  
bool is_leap_year(int y)  // 判断闰年
{
	//	return ((y%4==0 && y%100!=0) || y%400==0);  //100，200等能被4和100整除但不能被400整除的年不是闰年，以后只要能被4整除，就是闰年
	if (y % 4 != 0)
		return false;
	else if (y % 100 != 0 || y % 400 == 0)
		return true;
	else
		return false;
}

int first_day_of_year(int y)  // 判断1月1号是星期几
{
	long n;
	n = y * 365;
	for (int i = 1; i < y; i++)
		n += is_leap_year(i);
	y = y - 1;
	n += y / 4 - y / 100 + y / 400;
	return n % 7;
}
int first_day_of_month(int y, int m)
{
	if (is_leap_year(y) == 1)
		monthLength[1] = 29;//确定2月的天数
	int sum = 0;
	if (m == 1)
	{
		return first_day_of_year(m);
	}
	else
	{
		for (int i = 0; i < m; i++)
			sum = monthLength[i] + sum;//计算本月1号以前共有多少天
		int d = (sum + first_day_of_year(y)) % 7;//计算本月1号为星期几
		return d;//直接对应weekday
	}
}
void print_calender(int y, int m)
{
	char* weekday[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	//                    0      1      2      3      4      5      6
	for (int k = 0; k < 7; k++)
		cout << setw(6) << weekday[k];//输出weekday作为表头
	cout << endl;
	if (m == 1)
	{
		int day1 = first_day_of_year(y)+1;
		for (int s = 0; s<6 * day1; s++)
			cout << " ";
		for (int i = 1; i <= monthLength[m]; i++)
		{
			cout << setw(6) << i;//逐个输出日期
			if ((i + day1) % 7 == 0)//若为Sun则换行
				cout << endl;
		}
		return;
	}
	int first_day = first_day_of_month(y, m) + 1;
	if (first_day > 0 && first_day < 6)//判断若不是星期天就先输出议定数量的空格
	{
		
		for (int s = 0; s < 6 * first_day; s++)
			cout << " ";
		//int length = 6 * first_day;
		//cout << setw(length);
		//cout << "                        ";
		for (int i = 1; i <= monthLength[m]; i++)
		{
			cout << setw(6) << i;//逐个输出日期
			if ((i + first_day) % 7 == 0)//若为Sun则换行
				cout << endl;
		}
	}
	else//判断若是星期天则直接按顺序输出日期
	{
		for (int i = 1; i <= monthLength[m]; i++)
		{
			cout << setw(6) << i;//逐个输出日期
			if ((i + first_day) % 7 == 0)//若为Sun则换行
				cout << endl;
		}
	}
}
int main()
{
	int y, m;
	do
	{
		cout << "输入年份和月份";
		cout << setiosflags(ios::left);
		cin >> y >> m;

		print_calender(y, m);//输出日历
		//cout << first_day_of_year(y);//test：1月1日对应数组序号
		//cout << first_day_of_month(y, m);//test:每月1号对应数组序号
	} while (y != 0 && m != 0);
	system("pause");
	return 0;
}