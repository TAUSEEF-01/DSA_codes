#include <iostream>

using namespace std;

struct MinHeap
{
    int *harr;
    int capacity;
    int heap_size;

    MinHeap(int capacity)
    {
        this->heap_size = 0;
        this->capacity = capacity;
        this->harr = new int[capacity];
    }

    int left(int index)
    {
        return 2 * index + 1;
    }

    int right(int index)
    {
        return 2 * index + 2;
    }

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    void heapify(int index)
    {
        int l = this->left(index);
        int r = this->right(index);
        int min_index = index;

        if (l < this->heap_size && harr[l] < harr[index])
            min_index = l;
        if (r < this->heap_size && harr[r] < harr[min_index])
            min_index = r;
        if (min_index != index)
        {
            swap(harr[min_index], harr[index]);
            heapify(min_index);
        }
    }

    int extract_root()
    {
        if (this->heap_size <= 0)
        {
            return INT32_MAX;
        }

        if (this->heap_size == 1)
        {
            this->heap_size--;
            return harr[0];
        }

        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        this->heap_size--;
        this->heapify(0);

        return root;
    }

    int get_min()
    {
        return harr[0];
    }

    void decrease_node(int index, int new_val)
    {
        harr[index] = new_val;

        while (index != 0 && harr[this->parent(index)] > harr[index])
        {
            swap(harr[index], harr[this->parent(index)]);
            index = parent(index);
        }
    }

    void delete_node(int index)
    {
        this->decrease_node(index, INT32_MIN);
        this->extract_root();
    }

    void insert_node(int val)
    {
        if (this->heap_size == this->capacity)
        {
            std::cout << "Heap Overflow\n";
            return;
        }

        int index = this->heap_size;
        this->heap_size++;
        harr[index] = val;

        while (index != 0 && harr[this->parent(index)] > harr[index])
        {
            swap(harr[index], harr[this->parent(index)]);
            index = this->parent(index);
        }
    }

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;

    MinHeap *heap = new MinHeap(n);

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;

        heap->insert_node(x);
    }

    int count = 0;
    while (heap->heap_size > 1 && heap->get_min() <= k)
    {
        int l1 = heap->extract_root();
        int l2 = heap->extract_root();

        heap->insert_node(l1 + 2 * l2);

        count++;
    }

    if (heap->get_min() < k)
    {
        cout << -1 << '\n';
    }
    else if (heap->get_min() >= k)
    {
        cout << count << '\n';
    }
}