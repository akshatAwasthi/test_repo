#include<iostream>
#include<list>

using namespace std;

struct ele
{
    int d;
};

void ele_e(ele *e, int d)
{
    e->d = d;
}

class b_tree
{
        ele e;
        list<ele> l;
        list<ele> r;
    public:
        b_tree(ele e);
        void add_to_btree(ele e);
};

b_tree :: b_tree(ele e)
{
    this-> e = e;
}

void b_tree :: add_to_btree(b_tree *r, ele e, char c)
{
    if(c == 'l')
        r->l.push_back(e);
    else
        r->r.push_back(e);
}

int main()
{
    ele e1; e1.d = 1;
    b_tree root();
    return 0;
}
