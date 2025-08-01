#include <stdexcept>

template <typename T>

class Matrix
{
private:
    int rows;
    int cols;
    T** data;
public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows]; 
        for (int i = 1; i <= rows; ++i) {
            data[i] = new T[cols]; 
            for (int j = 1; j <= cols; ++j) {
                data[i][j] = T();
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

    void fill(int i, int j, T value)
    {

        if (i > 0 && i <= rows && j > 0 && j <= cols)
        {
            data[i][j] = value;
            return;
        }
        else
        {
            throw std::invalid_argument("Given position is wrong!");
        }
    }
    int Get(int i, int j)
    {
        return data[i][j];
    }
    
};
    
