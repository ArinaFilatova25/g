#include <iostream>
#include <graphics.h>
#include <locale.h>
#include <cmath>
#include <windows.h>
#include <conio.h>


using namespace std;

//#define _CRT_SECURE_NO_WARNINGS
#define SIZE 7


int main()
{
    setlocale(LC_ALL,"Rus");
    int a[SIZE][SIZE]; // ������� ������
    int d[SIZE]; // ����������� ����������
    int v[SIZE]; // ���������� �������
    int temp, minindex, min, begin_index;
    //system("chcp 1251");
    //system("cls");
    // ������������� ������� ������
    for (int i = 0; i<SIZE; i++)
    {
        a[i][i] = 0;
        for (int j = i + 1; j<SIZE; j++)
        {
            cout<<"������� ���������� �� "<< i + 1<< " �� " << j + 1<<" ������� :";
            cin>>temp;
            a[i][j] = temp;
            a[j][i] = temp;

        }
    }
    // ����� ������� ������
//  for (int i = 0; i<SIZE; i++)
//  {
//    for (int j = 0; j<SIZE; j++)
//      printf("%5d ", a[i][j]);
//    printf("\n");
//  }
    //������������� ������ � ����������
    for (int i = 0; i<SIZE; i++)
    {
        d[i] = 10000;
        v[i] = 1;
    }
    cout<<"������� �������, ���������� �� ������� ������ �����"<<endl;
    cin>>begin_index;
    begin_index--;
    d[begin_index] = 0;
    // ��� ���������
    do
    {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i<SIZE; i++)
        {
            // ���� ������� ��� �� ������ � ��� ������ min
            if ((v[i] == 1) && (d[i]<min))
            {
                // ��������������� ��������
                min = d[i];
                minindex = i;
            }
        }
        // ��������� ��������� ����������� ���
        // � �������� ���� �������
        // � ���������� � ������� ����������� ����� �������
        if (minindex != 10000)
        {
            for (int i = 0; i<SIZE; i++)
            {
                if (a[minindex][i] > 0)
                {
                    temp = min + a[minindex][i];
                    if (temp < d[i])
                    {
                        d[i] = temp;
                    }
                }
            }
            v[minindex] = 0;
        }
    }
    while (minindex < 10000);
    // ����� ���������� ���������� �� ������
    cout<<" ���������� ���������� �� ������: "<<endl;
    for (int i = 0; i<SIZE; i++)
        cout<<"     "<<d[i];

    cout<<"\n";
    // �������������� ����
    // ������ ���������� ������
    //int end; // ������ �������� �������
    // cout<<"������� �������, ���������� �� ������� ������ �����"<<endl;
    // cin>>end;
    // end--;
    //ver[0] = end + 1; // ��������� ������� - �������� �������
    int ver[SIZE];
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm,"");            //�������� ������������ ������
    setbkcolor(13);
    cleardevice();
    char st[SIZE];
    for (int i=1; i<=SIZE; i++)
    {
        sprintf(st,"%d",i);
        setcolor (10);
        setlinestyle(0, 0, 4);
        circle(60+70*i, 350, 20);
        setcolor(0);
        settextstyle(BOLD_FONT,0,6);
        outtextxy(55+70*i,340, st);
    }
    for (int i = 0; i<SIZE; i++)
    {
        for (int j = 0; j<SIZE; j++)
        {
            if(a[i][j]!=0)
            {
                setcolor(11);
                setlinestyle(0, 0, 2);
                ellipse(130+35*(i+j),330,0,180,35*(abs(j-i)),40*(abs(j-i)));

            }
        }
    }

    for (int i = 0; i<SIZE; i++)
    {
        int end=i;
        ver[0]=1+i;
        int k = 1; // ������ ���������� �������
        int weight = d[end]; // ��� �������� �������

        while (end != begin_index) // ���� �� ����� �� ��������� �������
        {
            for (int i = 0; i<SIZE; i++) // ������������� ��� �������
                if (a[i][end] != 0)   // ���� ����� ����
                {
                    int temp = weight - a[i][end]; // ���������� ��� ���� �� ���������� �������
                    if (temp == d[i]) // ���� ��� ������ � ������������
                    {
                        // ������ �� ���� ������� � ��� �������
                        weight = temp; // ��������� ����� ���
                        end = i;       // ��������� ���������� �������
                        ver[k] = i + 1; // � ���������� �� � ������
                        k++;
                    }
                }
        }

        int otvet[k];
        cout<<endl<<" ����� ����������� ����"<<endl;
        for (int i = k - 1; i >= 0; i--)
        {
            cout<<"   "<<ver[i];
            otvet[i]=ver[i]-1;
        }

        for (int i = 0; i<SIZE; i++)
        {
            for (int j = 0; j<SIZE; j++)
            {
                for(int m=0; m<k-1; m++)
                {
                    if( (i==otvet[m] && j==otvet[m+1] && a[i][j]!=0) || (j==otvet[m] && i==otvet[m+1]&& a[i][j]!=0))
                    {
                        setcolor(14);
                        setlinestyle(0, 0, 2);

                        ellipse(130+35*(i+j),330,0,180,35*(abs(j-i)),40*(abs(j-i)));
                    }
                }
            }
        }


    }

    // ����� ���� (��������� ������� ��������� � ����� ������� �� k ���������)




    getchar();
    getchar();
    getch();
    closegraph();

    return 0;
}
