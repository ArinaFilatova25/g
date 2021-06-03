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
    int a[SIZE][SIZE]; // матрица связей
    int d[SIZE]; // минимальное расстояние
    int v[SIZE]; // посещенные вершины
    int temp, minindex, min, begin_index;
    //system("chcp 1251");
    //system("cls");
    // Инициализация матрицы связей
    for (int i = 0; i<SIZE; i++)
    {
        a[i][i] = 0;
        for (int j = i + 1; j<SIZE; j++)
        {
            cout<<"Введите расстояние от "<< i + 1<< " до " << j + 1<<" вершины :";
            cin>>temp;
            a[i][j] = temp;
            a[j][i] = temp;

        }
    }
    // Вывод матрицы связей
//  for (int i = 0; i<SIZE; i++)
//  {
//    for (int j = 0; j<SIZE; j++)
//      printf("%5d ", a[i][j]);
//    printf("\n");
//  }
    //Инициализация вершин и расстояний
    for (int i = 0; i<SIZE; i++)
    {
        d[i] = 10000;
        v[i] = 1;
    }
    cout<<"Введите вершину, расстояние от которой хотите найти"<<endl;
    cin>>begin_index;
    begin_index--;
    d[begin_index] = 0;
    // Шаг алгоритма
    do
    {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i<SIZE; i++)
        {
            // Если вершину ещё не обошли и вес меньше min
            if ((v[i] == 1) && (d[i]<min))
            {
                // Переприсваиваем значения
                min = d[i];
                minindex = i;
            }
        }
        // Добавляем найденный минимальный вес
        // к текущему весу вершины
        // и сравниваем с текущим минимальным весом вершины
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
    // Вывод кратчайших расстояний до вершин
    cout<<" Кратчайшие расстояния до вершин: "<<endl;
    for (int i = 0; i<SIZE; i++)
        cout<<"     "<<d[i];

    cout<<"\n";
    // Восстановление пути
    // массив посещенных вершин
    //int end; // индекс конечной вершины
    // cout<<"Введите вершину, расстояние до которой хотите найти"<<endl;
    // cin>>end;
    // end--;
    //ver[0] = end + 1; // начальный элемент - конечная вершина
    int ver[SIZE];
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm,"");            //открытие графического режима
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
        int k = 1; // индекс предыдущей вершины
        int weight = d[end]; // вес конечной вершины

        while (end != begin_index) // пока не дошли до начальной вершины
        {
            for (int i = 0; i<SIZE; i++) // просматриваем все вершины
                if (a[i][end] != 0)   // если связь есть
                {
                    int temp = weight - a[i][end]; // определяем вес пути из предыдущей вершины
                    if (temp == d[i]) // если вес совпал с рассчитанным
                    {
                        // значит из этой вершины и был переход
                        weight = temp; // сохраняем новый вес
                        end = i;       // сохраняем предыдущую вершину
                        ver[k] = i + 1; // и записываем ее в массив
                        k++;
                    }
                }
        }

        int otvet[k];
        cout<<endl<<" Вывод кратчайшего пути"<<endl;
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

    // Вывод пути (начальная вершина оказалась в конце массива из k элементов)




    getchar();
    getchar();
    getch();
    closegraph();

    return 0;
}
