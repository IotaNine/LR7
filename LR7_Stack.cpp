#include <iostream>
#include <ctime>

struct element
{
    element* e_prev;
    int data;
};

struct Stack
{
    element* last;
    unsigned int size;
};

void constructor(Stack& S)
{
    S.last = nullptr;
    S.size = 0;
}

void destructor(Stack& S)
{
    while (S.last != nullptr)
    {
        element* point = S.last;
        S.last = S.last->e_prev;
        delete point;
        S.size--;
    }
}

unsigned int size(const Stack& S)
{
    return S.size;
}

void push(Stack& S, int N)
{
    element* E = new element;
    E->data = N;
    if (S.last != nullptr)
    {
        E->e_prev = S.last;
    }
    S.last = E;
    S.size++;
}int pop(Stack& S)
{
    if (S.size != 0)
    {
        int data =  S.last->data;
        element* point = S.last;
        S.last = S.last->e_prev;
        delete point;
        S.size--;
    }
    else
    {
        return 0;
    }
}

void print(const Stack& S)
{
    element* point = S.last;
    while (point != nullptr)
    {
        std::cout << point->data << std::endl;
        point = point->e_prev;
    }
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    Stack A;
    constructor(A);
    int N = 0;
    std::cout << "How many elements: ";
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        push(A, rand() % 10);
    }
    std::cout << "Size of the stack A: " << size(A) << std::endl;
    print(A);
    push(A, rand() % 10);
    print(A);
    pop(A);
    print(A);
    std::cout << "Size of the stack A: " << size(A) << std::endl;
}
