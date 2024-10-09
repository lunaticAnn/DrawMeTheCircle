#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>

using namespace std;

// Feel free to change anything you need or you don't like
// ;) if you digged here:
// don't like the dtor? the end result seems flipped?
// naming of certain stuff is confusing..? etc.
class Canvas
{
    public:
        Canvas(int _d)
        : d(_d)
        {
            int bfSize = _d * _d;
            buffer = new char[bfSize]();
            memset(buffer, 0, sizeof(char) * bfSize);
        }

        // let's assume 0 based index
        void setPixel(int x, int y, unsigned char c)
        {
            if ((x >= 0 && x < d) && (y >= 0 && y < d))
            {
                buffer[x * d + y] = c;
            }
        }

        void clear()
        {
            memset(buffer, 0, sizeof(char) * d * d);
        }
    
        void dumpToHexString()
        {
            ostringstream hexStream;
            for (size_t i = 0; i < d * d; ++i) {
                hexStream << hex << setw(2) << setfill('0') << (static_cast<unsigned>(static_cast<unsigned char>(buffer[i])));
            }
        
            cout << hexStream.str();
        }

    private:
        int d;
        char* buffer;
};

int main() {
    constexpr int dimension = 32;
    Canvas canvas(dimension);
    for (int x = 0; x < dimension ; ++x)
        for (int y = 0; y < dimension ; ++y)
            canvas.draw(x, y, static_cast<unsigned char>(x * 8));
    canvas.dumpToHexString();
    return 0;
}

