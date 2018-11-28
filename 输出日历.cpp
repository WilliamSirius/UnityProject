#include<iostream>
#include <iomanip>
using namespace std;

int monthLength[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//                      0  1   2   3   4    5   6   7   8  9   10  11  12  
bool is_leap_year(int y)  // �ж�����
{
	//	return ((y%4==0 && y%100!=0) || y%400==0);  //100��200���ܱ�4��100���������ܱ�400�������겻�����꣬�Ժ�ֻҪ�ܱ�4��������������
	if (y % 4 != 0)
		return false;
	else if (y % 100 != 0 || y % 400 == 0)
		return true;
	else
		return false;
}

int first_day_of_year(int y)  // �ж�1��1�������ڼ�
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
		monthLength[1] = 29;//ȷ��2�µ�����
	int sum = 0;
	if (m == 1)
	{
		return first_day_of_year(m);
	}
	else
	{
		for (int i = 0; i < m; i++)
			sum = monthLength[i] + sum;//���㱾��1����ǰ���ж�����
		int d = (sum + first_day_of_year(y)) % 7;//���㱾��1��Ϊ���ڼ�
		return d;//ֱ�Ӷ�Ӧweekday
	}
}
void print_calender(int y, int m)
{
	char* weekday[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	//                    0      1      2      3      4      5      6
	for (int k = 0; k < 7; k++)
		cout << setw(6) << weekday[k];//���weekday��Ϊ��ͷ
	cout << endl;
	if (m == 1)
	{
		int day1 = first_day_of_year(y)+1;
		for (int s = 0; s<6 * day1; s++)
			cout << " ";
		for (int i = 1; i <= monthLength[m]; i++)
		{
			cout << setw(6) << i;//����������
			if ((i + day1) % 7 == 0)//��ΪSun����
				cout << endl;
		}
		return;
	}
	int first_day = first_day_of_month(y, m) + 1;
	if (first_day > 0 && first_day < 6)//�ж��������������������鶨�����Ŀո�
	{
		
		for (int s = 0; s < 6 * first_day; s++)
			cout << " ";
		//int length = 6 * first_day;
		//cout << setw(length);
		//cout << "                        ";
		for (int i = 1; i <= monthLength[m]; i++)
		{
			cout << setw(6) << i;//����������
			if ((i + first_day) % 7 == 0)//��ΪSun����
				cout << endl;
		}
	}
	else//�ж�������������ֱ�Ӱ�˳���������
	{
		for (int i = 1; i <= monthLength[m]; i++)
		{
			cout << setw(6) << i;//����������
			if ((i + first_day) % 7 == 0)//��ΪSun����
				cout << endl;
		}
	}
}
int main()
{
	int y, m;
	do
	{
		cout << "������ݺ��·�";
		cout << setiosflags(ios::left);
		cin >> y >> m;

		print_calender(y, m);//�������
		//cout << first_day_of_year(y);//test��1��1�ն�Ӧ�������
		//cout << first_day_of_month(y, m);//test:ÿ��1�Ŷ�Ӧ�������
	} while (y != 0 && m != 0);
	system("pause");
	return 0;
}