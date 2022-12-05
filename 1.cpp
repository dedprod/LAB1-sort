#include <iostream>
using namespace std;

template <class T> //создаём шаблон
void bubblesort(T *arr, int num) //Сортировка методом пузырька
{
    for (int i = 0; i < num; i++) //запускаем первый цикл для полного прохода по всем элементам
    {
        for (int g = 0; g < num; g++) //Запускаем второй цикл для сравнения элементов и выталкивания более тяжелых вправо
        {
            if (arr[i] < arr[g]) // если элемент оказывается тяжелее выталкиваем направо с помощью свапа
            {
                swap(arr[g], arr[i]);
            }
        }
    }
}
template <class T> //создаём шаблон
void pastesort(T *arr, int num) //Сортировка вставками
{ 
    for (int i = 1; i < num; i++) // запускаем цикл для того чтобы проходить элементы один за одним, мы вставляли элемент в данную позицию предварительно проведя поиск минимального элемента
    {
        int g = i - 1;
        while ((g >= 0) & (arr[g] > arr[g + 1])) 
        {
            swap(arr[g], arr[g + 1]);
            g = g - 1;
        }
    }
}
template <class T> //создаём шаблон
void selectionsort(T *arr, int num) //сортировка выбором, 
{
    int var, pos; // задаём позицию элемента и значение
    for (int i = 0; i < num - 1; i++) //запускаем первый цикл для полного прохода по всем элементам
    {
        var = arr[i];
        pos = i;
        for (int j = i + 1; j < num; j++)
            if (arr[j] < arr[pos]) //находим минимальный элемент и записываем его номер в переменную
            {
                pos = j; 
            }
        if (pos != i) //если номер первого элемента и номер найденного элемента не совпадают, тогда свапаем значения элементов
        {
            arr[i] = arr[pos];
            arr[pos] = var;
        }
    }
}

void printArray(int arr[], int num){
    std::cout << endl;
    for (int i = 0; i < num; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << endl;
    std::cout << "------------------------------------" << endl;
}
int main()
{
    int num;
    std::cout << "Введите длину массива" << std::endl;
    std::cin >> num;
    int *arr = new int[num];

    for (int i = 0; i < num; i++)
    {
        arr[i] = rand() % 100;
        std::cout << arr[i] << endl;
    }
    selectionsort(arr, num);
    printArray(arr,num);
    for (int i = 0; i < num; i++)
    {
        arr[i] = rand() % 100;
        std::cout << arr[i] << endl;
    }
    pastesort(arr, num);
    printArray(arr,num);
    for (int i = 0; i < num; i++)
    {
        arr[i] = rand() % 100;
        std::cout << arr[i] << endl;
    }
    bubblesort(arr, num);
    std::cout << endl;
    for (int i = 0; i < num; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << endl;
    return 0;
}