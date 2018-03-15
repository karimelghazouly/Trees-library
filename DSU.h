#ifndef DSU_H
#define DSU_H


class DSU
{
    int rankk[100009],par[100009];
    public:
        DSU();
        void connect(int,int);
        bool is_connected(int,int);
        int get_par(int);
        virtual ~DSU();

    protected:

    private:
};

#endif // DSU_H
