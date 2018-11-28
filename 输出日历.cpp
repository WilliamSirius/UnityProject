#include<iostream>
#include <iomanip>
using namespace std;

int monthLength[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

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
	if (is_leap_year(y) == 0)
		monthLength[1] = 29;//ȷ��2�µ�����
	int sum = 0;
	for (int i = 0; i < m; i++)
		sum = monthLength[i] + sum;//���㱾��1����ǰ���ж�����
	int d = (sum + first_day_of_year(y)) % 7;//���㱾��1��Ϊ���ڼ�
	return d;//ֱ�Ӷ�Ӧweekday
}
void print_calender(int y, int m)
{
	char* weekday[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	for (int k = 0; k < 7; k++)
		cout << setw(5) << weekday[k];//���weekday��Ϊ��ͷ
	cout << endl;
	int first_day = first_day_of_month(y, m);
	if (first_day > 0)//�ж��Ƿ�ΪSun

		cout << setw(5 * first_day) << " " << 1;
	for (int i = 2; i < monthLength[m]; i++)
	{
		cout << setw(5) << i << " ";//����������
		if ((i + first_day) % 7 == 0)//��ΪSun����
			cout << endl;
	}
}
int main()
{
	int y, m;
	cout << "������ݺ��·�";
	cin >> y >> m;
	cout << first_day_of_year(y);//test��1��1��Ϊ�ܼ�
	print_calender(y, m);//�������
	system("pause");
	return 0;
}