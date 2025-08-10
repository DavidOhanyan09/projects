#include <stdexcept>

template <typename T>

class Matrix
{
private:
    int rows;
    int cols;
    T** data;
public:
    Matrix(int r, int c) : rows(r), cols(c) 
    {
        data = new T*[rows]; 
        for (int i = 1; i <= rows; ++i) {
            data[i] = new T[cols]; 
            for (int j = 1; j <= cols; ++j) {
                data[i][j] = 0;
            }
        }
    }
    
    Matrix(const Matrix& other)
    {

    }
    Matrix& operator=(const Matrix& other)
    {

    }
    Matrix(Matrix&& other)
    {

    }
    Matrix& operator=(const Matrix&& other)
    {

    }

    ~Matrix()
    { 
        for(int i = 1; i<=rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    T** operator+(T** other)
    {
        
    }

    void fill(int r, int c, T value)
    {
        if (r > 0 && r <= rows && c > 0 && c <= cols)
        {
            data[r][c] = value;
            return;
        }
        else
        {
            throw std::invalid_argument("Given position is wrong!");
        }
    }
    int Get(int r, int c)
    {
        if(r > rows or r<rows or c<cols or c>cols)
        {
            throw std::invalid_argument("Given position is wrong!");
        }
        return data[r][c];
    }
    
};