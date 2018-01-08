#ifndef MIN_HEAP_H
#define MIN_HEAP_H
class Min_Heap
{
    public:
        int arr[100000],siz;
        Min_Heap();
        void move_up(int);
        void move_down(int);
        void insrt(int);
        void rem();
        int find_parent(int);
        int get_min();
        ~Min_Heap();

    protected:

    private:
};

#endif // MIN_HEAP_H
