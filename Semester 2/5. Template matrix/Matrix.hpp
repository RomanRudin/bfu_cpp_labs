#include <iostream>>

namespace mtx {

    auto recursiveDet(double** matrix, int K) {
        if (K == 1) {
            return matrix[0][0];
        }
        if (K == 2) {
            return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
        }
        else {
            double sum = 0;
            for (int i = 0; i < K; i++) {
                double** tmp = new double* [K - 1];
                for (int k = 0; k < K - 1; k++) {
                    tmp[k] = new double[K - 1];
                }
                for (int k = 0; k < K - 1; k++)
                    for (int l = 0; l < K; l++) {
                        if (l == i) continue;
                        else if (l > i)
                            tmp[k][l] = matrix[k + 1][l + 1];
                        else
                            tmp[k][l] = matrix[k + 1][l];
                    }
                sum += matrix[0][i] * pow(-1, 2 + i) * recursiveDet(tmp, K - 1);
            }
            for (int i = 0; i < K; i++)
                delete matrix[i];
            return sum;
        }
    }

    template<typename T, int N, int M>
    class Matrix
    {
    private:
        T matrix[N][M];
    public:
        Matrix() {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        Matrix(T arr[N][M]) {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    this->matrix[i][j] = arr[i][j];
        }

        T& operator()(int i, int j) {
            return matrix[i][j];
        }


        Matrix<T, N, M>& operator+=(Matrix<T, N, M> other) {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    this->matrix[i][j] += other.matrix[i][j];
            return *this;
        }

        Matrix<T, N, M>& operator+(Matrix<T, N, M> other) {
            *this += other;
            return *this;
        }

        Matrix<T, N, M>& operator*(T value) {
            *this *= value;
            return *this;
        }

        Matrix<T, N, M>& operator*=(T value) {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    this->matrix[i][j] *= value;
            return *this;
        }

        template<int L>
        Matrix<T, N, L>& operator*(Matrix < T, M, L>& other) {
            Matrix<T, N, L> tmp{};
            for (int i = 0; i < N; i++)
                for (int j = 0; j < L; j++)
                    for (int k = 0; k < M; k++)
                        tmp(i, j) += this->matrix[i][k] * other(k, j);
            return tmp;
        }

        template<int L>
        Matrix<T, N, L>& operator*=(Matrix < T, M, L>& other) {
            *this = *this * other;
            return *this;
        }

        Matrix<T, N, M>& operator++() {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    this->matrix[i][j]++;
            return *this;
        }

        T det()
        {
            if (N != M)
            {
                std::cout << "The matrix isn't square!" << std::endl;
                throw std::exception("The matrix isn't square!");
            }
            double** tmp = new double* [M];
            for (int i = 0; i < M; i++)
                tmp[i] = new double[M];
            for (int i = 0; i < M; i++)
                for (int j = 0; j < M; j++)
                    tmp[i][j] = this->matrix[i][j];
            return (T)recursiveDet(tmp, M);
        }

        template <typename T, int N, int M>
        friend std::ostream& operator << (std::ostream& out, const Matrix<T, N, M>& object);

        template<typename T, int N, int M>
        friend std::istream& operator>>(std::istream& in, Matrix<T, N, M>& object);
    };
    
    template<typename T, int N, int M>
    std::ostream& operator<<(std::ostream& out, const Matrix<T, N, M>& object)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
                out << object.matrix[i][j] << ' ';
            out << '\n';
        }
        return out;
    }

    template<typename T, int N, int M>
    std::istream& operator>>(std::istream& in, Matrix<T, N, M>& object)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                in >> object.matrix[i][j];
        return in;
    }
}
