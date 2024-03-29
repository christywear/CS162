#include <iostream>

using namespace std;

    // simple class that uses memory on the heap
class Example{
    private:
        int * value;
    public:
            // basic methods
        Example() { value = new int(0); }
        Example(int v) { value = new int(v); }
        int getValue() { return *value; }
        void setValue(int v) {*value = v; }
};

void display(Example & ex)
{
    cout << "in display " << ex.getValue() << endl;
    ex.setValue(33);
}
int main()
{
        // test basic class methods
    Example ex(3);

    cout << "before call " << ex.getValue() << endl;
    display(ex);
    cout << "after call " << ex.getValue() << endl;

    return 0;
}
