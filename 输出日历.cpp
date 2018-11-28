#include<iostream>
#include <iomanip>
using namespace std;

int monthLength[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

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
	if (is_leap_year(y) == 0)
		monthLength[1] = 29;//确定2月的天数
	int sum = 0;
	for (int i = 0; i < m; i++)
		sum = monthLength[i] + sum;//计算本月1号以前共有多少天
	int d = (sum + first_day_of_year(y)) % 7;//计算本月1号为星期几
	return d;//直接对应weekday
}
void print_calender(int y, int m)
{
	char* weekday[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	for (int k = 0; k < 7; k++)
		cout << setw(5) << weekday[k];//输出weekday作为表头
	cout << endl;
	int first_day = first_day_of_month(y, m);
	if (first_day > 0)//判断是否为Sun

		cout << setw(5 * first_day) << " " << 1;
	for (int i = 2; i < monthLength[m]; i++)
	{
		cout << setw(5) << i << " ";//逐个输出日期
		if ((i + first_day) % 7 == 0)//若为Sun则换行
			cout << endl;
	}
}
int main()
{
	int y, m;
	cout << "输入年份和月份";
	cin >> y >> m;
	cout << first_day_of_year(y);//test：1月1日为周几
	print_calender(y, m);//输出日历
	system("pause");
	return 0;
}