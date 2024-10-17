#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>

using namespace std;

// Feel free to change anything you need or you don't like
// ;) if you digged here:
// don't like the dtor? the end result seems flipped?
// naming of certain stuff is confusing..? etc.
typedef unsigned char Grayscale;
class Canvas
{
    public:
        Canvas(int _d)
        : d(_d)
        {
            int bfSize = _d * _d;
            buffer = new Grayscale[bfSize]();
            memset(buffer, 0, sizeof(Grayscale) * bfSize);
        }

        // let's assume 0 based index
        void setPixel(int x, int y, Grayscale c)
        {
            if ((x >= 0 && x < d) && (y >= 0 && y < d))
            {
                buffer[x * d + y] = c;
            }
        }

        void clear()
        {
            memset(buffer, 0, sizeof(Grayscale) * d * d);
        }
    
        void dumpToHexString()
        {
            ostringstream hexStream;
            for (size_t i = 0; i < d * d; ++i) {
                hexStream << hex << setw(2) << setfill('0') << (static_cast<unsigned>(buffer[i]));
            }
        
            cout << hexStream.str();
        }

    private:
        int d;
        Grayscale* buffer;
};

int main()
{
    constexpr int dimension = 32;
    Canvas canvas(dimension);
    for (int x = 0; x < dimension ; ++x)
        for (int y = 0; y < dimension ; ++y)
            canvas.setPixel(x, y, static_cast<Grayscale>(x * 8));
    canvas.dumpToHexString();
    return 0;
}
