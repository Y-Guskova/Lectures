#include <iostream>
using namespace std;

class Image 
{
    int* img;
    int mx, my;
public:
    Image(int tmx, int tmy) :mx(tmx), my(tmy) 
    {
        img = new int[mx * my]();
    }
    virtual ~Image() 
    {
        delete[] img;
    }

    void set(int x, int y, int color) 
    {
        if (x >= mx || y >= my || x < 0 || y < 0)
        {
            throw 1;
        }
        img[y * my + x] = color;
    }

    void get(int x, int y) 
    {
        if (x >= mx || y >= my || x < 0 || y < 0) 
        {
            throw 1;
        }
        return img[y * my + x];
    }

    Image operator=(const Image& v) 
    {
        delete[] this->img;
        this->mx = v.mx;
        this->my = v.my;
        img = new int[mx * my];
        for (int i = 0; i < mx * my; i++) 
        {
            this->img[i] = v.img[i];
        }
    }
};
int main() 
{
    try
    {
        Image a(2, 2);
        a.set(0, 0, 1);
        a.set(1, 0, 2);
        a.set(0, 1, 3);
        a.set(1, 1, 4);

        Image b(1, 1);
        b = a;

        cout << b.get(0, 0) << endl;
        cout << b.get(1, 0) << endl;
        cout << b.get(0, 1) << endl;
        cout << b.get(1, 1) << endl;

        b.set(3, 3, 1);
    }
    catch (int)
    {
        cout << "Error :(" << endl;
    }
}
