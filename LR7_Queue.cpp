#include <iostream>
#include <ctime>

struct element
{
    element* next_e;
    int data;
};

struct Queue
{
    element* first;
    element* last;
    unsigned int size;
};

void constructor(Queue& Q)
{
    Q.first = nullptr;
    Q.last = nullptr;
    Q.size = 0;
}

void destructor(Queue& Q)
{
    while (Q.first != nullptr)
    {
        element* point = Q.first;
        Q.first = Q.first->next_e;
        point->next_e = nullptr;
        delete point;
    }
    Q.size = 0;
    Q.last = nullptr;
}

unsigned int size(const Queue& Q)
{
    return Q.size;
}

void push(Queue& Q, int N)
{
    element* E = new element;
    E->data = N;
    if (Q.first == nullptr)
    {
        Q.first = E;
    }
    else
    {
        Q.last->next_e = E;
    }
    Q.last = E;
    Q.size++;
}

int pop(Queue& Q)
{
    if (Q.size != 0)
    {
        int data = Q.first->data;
        element* point = Q.first;
        Q.first = Q.first->next_e;
        delete point;
        Q.size--;
        return data;
    }
    else
    {
        return 0;
    }
}

void print(const Queue& Q)
{
    if (Q.size != 0)
    {
        std::cout << "Elements of the queue" << std::endl;
        for(auto temp_node = Q.first; temp_node != nullptr; temp_node = temp_node->next_e)
        {
            std::cout << temp_node->data << std::endl;
        }
    }
    else
    {
        std::cout << "The queue is empty" << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    Queue A;
    constructor(A);
    int N = 0;
    std::cout << "How many elements: ";
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        push(A, rand() % 10);
        A.size++;
    }
    print(A);
    push(A, rand() % 10);
    print(A);
    pop(A);
    print(A);
    std::cout << "Size of the queue A: " << size(A) << std::endl;

}
