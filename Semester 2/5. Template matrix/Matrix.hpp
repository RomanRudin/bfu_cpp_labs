#include <iostream>>

namespace mtx {
    template<typename T, int N, int M>
    class Matrix
    {
    private:
        T matrix[N][M];
    public:
        Matrix() = default;

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
            return this->recursiveDet();
        }

    private:
        T recursiveDet() {
            if (M == 1) {
                return this->matrix[0][0];
            }
            if (M == 2) {
                return this->matrix[0][0] * this->matrix[1][1] - this->matrix[1][0] * this->matrix[0][1];
            }
            else {
                int sum = 0;
                for (int i = 0; i < M; i++) {
                    /*Matrix<T, (M - 1), (M - 1)> tmp;
                    for (int k = 0; k < M - 1; k++)
                        for (int l = 0; l < M; l++) {
                            if (l == i) continue;
                            else if (l > i)
                                tmp(k, l) = this->matrix[k + 1][l + 1];
                            else
                                tmp(k, l) = this->matrix[k + 1][l];
                        }
                    sum += this->matrix[0][i] * pow(-1, 2 + i) * tmp.det();*/
                }
                return sum;
            }
        }

    public:

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