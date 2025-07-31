#include <stdexcept>
template <typename T>

class Matrix
{
private:
    int rows;
    int cols;
    T** data;
public:
    Matrix(int r, int c)
    {
       rows = r;
       cols = c;
       data = new T*[rows];
       for (int i = 0; i < rows; ++i)
       {
           data[i] = new T[cols]();
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

    }
    void fill(int i, int j, T value)
    {

        if (i >= 0 && i < rows && j >= 0 && j < cols)
        {
            data[i][j] = value;
        }
        else
        {
            throw std::invalid_argument("Given position is wrong!");
        }
    }
    int Get(int i, int j)
    {
        rows = i;
        cols = j;
        return data[rows][cols];
    }
};
    
