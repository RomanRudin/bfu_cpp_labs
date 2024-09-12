#pragma once
const int N = 100;
const int M = 100;

namespace fnc
{

	bool have_35(int x);

	void print(int matrix[N][M], int n, int m);

	int task_check(int matrix[N][M], int n);

	int summ_kv_stolb(int matrix[N][M], int n, int x);

	int stolb_min_num(int matrix[N][M], int n, int j);

	void input(int matrix[N][M], int& n, int& m);

	int error_check(int n, int m);

	void fin_fun(int matrix[N][M], int n);

}
