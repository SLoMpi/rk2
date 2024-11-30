#include <iostream>

using namespace std;

double** multiplyMatrices(double** A, int m, int p, double** B, int p2, int n) {

    if(p!=p2) {
        cerr<<"Число столбцов в первой матрице должно равняться числу строк во второй."<<endl;
        abort();
    }

    double** result = new double*[m];
    for(int i = 0; i < m; ++i){
        result[i] = new double[n];
        for(int j = 0; j < n; ++j){
            result[i][j] = 0.0;
        }
    }
    
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < p; ++k){
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

int main() {
    const int m = 2; // Число строк матрицы A
    const int p = 3; // Число столбцов матрицы A и число строк матрицы B
    const int n = 2; // Число столбцов матрицы B
    double A_data[m][p] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    double B_data[p][n] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    double* A_ptr[m];

    for(int i = 0; i < m; ++i){
        A_ptr[i] = A_data[i];
    }

    double* B_ptr[p];
    for(int i = 0; i < p; ++i){
        B_ptr[i] = B_data[i];
    }
    double** result = multiplyMatrices(A_ptr, m, p, B_ptr, p, n);

    cout << "Результат умножения матриц A и B:\n";
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
