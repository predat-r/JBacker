#include <iostream>
#include <string>
using namespace std;
class matrix
{
    int rows;
    int cols;
    int **arr;

public:
    matrix(int a = 0, int b = 0)
    {
        rows = a;
        cols = b;
        arr = new int *[rows];
        for (size_t i = 0; i < rows; i++)
        {
            arr[i] = new int[cols];
        }
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                arr[i][j] = 0;
            }
        }
    }
    matrix(const matrix &mat)
    {
        this->rows = mat.rows;
        this->cols = mat.cols;
        this->arr = new int *[rows];
        for (size_t i = 0; i < rows; i++)
        {
            arr[i] = new int[cols];
        }
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                arr[i][j] = mat.arr[i][j];
            }
        }
    }
    void display()
    {
        cout << "\nYour matrix is :\n";
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
    ~matrix()
    {
        for (size_t i = 0; i < rows; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
};
int main()
{
    matrix mat1(2, 3);
    mat1.display();
    return 0;
}