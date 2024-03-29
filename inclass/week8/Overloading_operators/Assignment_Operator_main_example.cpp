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
            // assignment operator
            // comment and comment to see
            // problem and how it is solved
//#define assign1
#ifdef assign1
        Example & operator=(Example & ex)
        {
                // this is the left side of equals
                // so set our value to be the same as its
            *value = ex.getValue();
                // return our address
            return *this;
        }
#endif // copy
};

int main()
{
        // test basic class methods
    Example ex1;
    Example ex2(5);

        // show initial values
    cout << "ex1 is " << ex1.getValue() << " ex2 is "  << ex2.getValue() << endl;
        // set ex1 to be same as ex2
    ex1 = ex2;
    cout << "ex1 is " << ex1.getValue() << " ex2 is "  << ex2.getValue() << endl;

        // change ex1 and see what happens to ex2
    ex1.setValue(3);
    cout << "ex1 is " << ex1.getValue() << " ex2 is "  << ex2.getValue() << endl;

    return 0;
}
