//
//  main.cpp
//  quicksort_ver_3.0
//
//  Created by David Nurdinov on 16/02/2018.
//  Copyright © 2018 David Nurdinov. All rights reserved.
//

#include <iostream>
using namespace std;
static int counter=0;//Глобальная переменная подсчета кол-ва шагов
void showme(int *mass, int first, int last){//функция вывода массива
    int i;
    for(i=first;i<last;i++){
        cout << mass[i] << " ";
        
    }
    cout<<endl;
}
void quick(int *mass,int first/*левая изменяемая граница */,int last/*правая изменяемая граница */, int n){ // То ради чего все и делается, функция quicksort
    int   left=first; //левая неизменяемая граница
    int  right=last;//правая неизменяемая граница
    int check=mass[((left+right)/2+1)];//проверяющий элемент, благодаря которому остальные элементы массива сортируются
    int a;// посредник, для рокировки двух элементов находящихся не на своем месте
    
    while(first<=last){//проверка, что границы не пошли дальше, после того как сомкнулись
        while(mass[first]<check){ //пока элементы слева меньше проверяющего элемента, граница слева будет двигаться направо
            first++;
        }
        while(mass[last]>check){//пока элементы справа больше проверяющего элемента, граница справа будет двигаться налево
            last--;
        }
        if(first<=last){//проверка границ, на целесообразность обмена индексами двух элементов массива
            if((mass[first]!=mass[last])&&(last!=first))  { //условия при которых не будет бессмысленных перестановок равных элементов массива или попыток поменять местами один и тот же элемент
               cout<<"CHECKER--"<<check<<endl;
            a=mass[first];
            mass[first]=mass[last];
            mass[last]=a;
                counter++;//прибавляет единицу, если какие-то 2 элемента поменялись местами
                showme(mass, 0, n);//показывает новый порядок элементов массива, если какие-то 2 элемента поменялись местами
                
                
            }
            last--;//сдвиг границы слева
            first++;//сдвиг границ справа
            
           
        };
        
        
    if(right>first)//рекурсивный вызов функции quicksort от левой именяемой границы до правой неизменяемой границы
        quick(mass, first, right, n);
        
    if(left<last)//рекурсивный вызов функции quicksort от левой неизменяемой границы до правой изменяемой границы
        quick(mass, left, last, n);
        
    }
    
    
}

int main() {
    cout<<"Input size: ";
    int n;//кол-во элементов массива
    scanf("%d", &n);
    int a[n];// сам массив, который придется потрошить и сортировать
    
    
    
    for (int i = 0; i<n; i++){
        cout <<"Vvedite mas["<<(i+1)<<"]=    \b\b\b\b";
        scanf("%d", &a[i]);//ввод элементов массива
        
    }
    cout<<"START:"<<endl;
    showme(a, 0, n);//показ массива до сортировки
    printf("\n");
    quick(a, 0, n-1, n);//сортировка массива
    printf("\n");
    cout<<"FINISH:"<<endl;
    showme(a, 0, n);// ну а теперь показ массива после сортировки
    cout<<"TOTAL: "<<counter<<endl;//а так же счет, во сколько перестановок нам обошлась эта сортировка 
    
    printf("\n");
    return 0;
}
