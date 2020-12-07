#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // ������������ ����������� ��������
using namespace std;
enum Data_narodzhennia { DEN_NARODZHENIA, MISIATS_NARODZHENNIA, RIK_NARODZHENNIA };
string data_narodzhenniaStr[] = { "����", "�����", "��" };
struct Note
{
	string prizv;
	string nomer_telephonu;
	Data_narodzhennia data_narodzhennia;
};
void Create(Note* p, const int N);
void Print(Note* p, const int N);
void Sort(Note* p, const int N);
void LineSearch(Note* p, const int N);
int main()
{ 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
	int N;
	cout << "������ ������� ���������� ����� N: "; cin >> N;
	Note* p = new Note[N];
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ������������� ������ �� ������ ����������" << endl;
		cout << " [4] - ���� ���������� ��� ������, ����� �������� ��� �������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			Sort(p, N);
			break;
		case 4:
			LineSearch(p, N);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Note* p, const int N)
{
	int DEN_NARODZHENIA;
	int MISIATS_NARODZHENNIA;
	int RIK_NARODZHENNIA;
	for (int i = 0; i < N; i++)
	{
		cout << "������ � " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
		cout << " �������: "; getline(cin, p[i].prizv);
		cout << "����� ��������: "; getline(cin, p[i].nomer_telephonu);
		cout << "���� ����������: "; cin >> DEN_NARODZHENIA;
		cout << "����� ����������: "; cin >> MISIATS_NARODZHENNIA;
		cout << "�� ����������: "; cin >> RIK_NARODZHENNIA;
		cout << endl;
	}
}
void Print(Note* p, const int N)
{
	cout << "==================================================="
		<< endl;
	cout << "| � | ������� | ����� �������� | ���� ���������� |"
		<< endl;
	cout << "---------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].prizv
			<< "| " << setw(13) << right << p[i].nomer_telephonu << " "
			<< "| " << setw(11) << left << DEN_NARODZHENIA << " . " << MISIATS_NARODZHENNIA << " . " << RIK_NARODZHENNIA << " . "
			<< " |" << endl;
		
	}
	cout << "========================================================================="
		<< endl;
	cout << endl;
}
void Sort(Note* p, const int N)
{
	Note tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if (p[i1].data_narodzhennia > p[i1 + 1].data_narodzhennia)
				
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}
void LineSearch(Note* p, const int N)
{
	string nomer_telephonu1;
	cout << "������ ����� ��������: "; getline(cin, nomer_telephonu1);
	cout << "���������� ��� ������, ����� ��� �� �����: " << endl;
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].nomer_telephonu == nomer_telephonu1)
		{
			cout << "�������: " << p[i].prizv << "  " << "���� ����������: " << data_narodzhenniaStr << endl;
		}
	}
	
}