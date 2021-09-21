/*
  In the name of ALLAH
  Author : Raashid Anwar
*/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int M1 =  998244353;
const int M2 =  1000000007;
mt19937 rng((uint64_t)chrono::steady_clock::now().time_since_epoch().count());

template<typename T, const int N, const int M>
struct Matrix {
	T arr[N][M];
	static T* c;
	T* operator [](int x) {
		return arr[x];
	}
    const T* operator [](int x) const {
    	return arr[x];
    }
	Matrix(){
		memset(arr, 0, sizeof(arr));
	}
	
	Matrix(const vector<vector<T>> & A){
		assert(A.size() == N && A[0].size() == M);
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j) 
				arr[i][j] = A[i][j];
	}

	Matrix(const T A[][M]){
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j) 
				arr[i][j] = A[i][j];
	}

	Matrix(const Matrix<T,N,M>& A){
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j) 
				arr[i][j] = A.arr[i][j];
	}

	inline void clear(){
		memset(arr, 0, sizeof(arr));
	}

	inline void make_identity(){
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j) 
				arr[i][j] = (i == j) ? 1 : 0;
	}

	Matrix operator + (const Matrix<T,N,M>& m) const {
		Matrix<T,N,M> ans;

		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				ans.arr[i][j] = arr[i][j] + m.arr[i][j];

		return ans;
	}

	Matrix operator - (const Matrix<T,N,M>& m) const {
		Matrix<T,N,M> ans;

		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				ans.arr[i][j] = arr[i][j] - m.arr[i][j];

		return ans;
	}

	template<const int L>
	Matrix<T,N,L> operator * (const Matrix<T,M,L>& m) const {
		Matrix<T,N,L> ans;

		for(int i = 0; i < N; ++i)
			for(int k = 0; k < M; ++k) {
				if (arr[i][k] == 0)
						continue;
				for(int j = 0; j < L; ++j)
					ans.arr[i][j] += arr[i][k] * m.arr[k][j];
			}

		return ans;
	}

	Matrix& operator += (const Matrix<T,N,M>& m) {
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				arr[i][j] += m.arr[i][j];
		return *this;
	}

	Matrix& operator -= (const Matrix<T,N,M>& m) {
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				arr[i][j] -= m.arr[i][j];
		return *this;
	}

	Matrix& operator *= (const Matrix<T,M,M>& m) {
		memset(c,0,sizeof(T)*N*M);
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j) {
				if (arr[i][j] == 0)
					continue;
				for(int k = 0; k < M; ++k)
					c[i * M + k] += arr[i][j] * m.arr[j][k];
			}

		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				arr[i][j] = c[i * M + j];
		return *this;
	}

	Matrix<T,M,N> transpose() const {
		Matrix<T,M,N> ans;

		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				ans.arr[j][i] = arr[i][j];
		return ans; 
	}

	void self_transpose(){
		static_assert( N == M );
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < i; ++j)
				swap(arr[i][j],arr[j][i]);
	}


	vector<T> operator *(const vector<T>& A) const{
		assert(A.size() == M);

		vector<T> ans(N,0);

		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)

				ans[i] += arr[i][j] * A[j];

		return ans;
	}

	template<typename P>
	Matrix operator ^ (P power) const {
		static_assert( N == M );
		Matrix<T,N,M> ans, multiplier(*this);
		if (power == 1)
			return multiplier;
		ans.make_identity();

		while( power > 0 ){
			if ( power & 1 )
				ans *= multiplier;

			power >>= 1;
			if (power > 0) 
				multiplier *= multiplier;
		}

		return ans;
	}

	template<typename P>
	Matrix& operator ^= (P power) {
		static_assert( N == M );

		if (power == 1)
			return *this;
		Matrix<T,N,M> multiplier(*this);
		make_identity();

		while( power > 0 ){
			if ( power & 1 )
				(*this) *= multiplier;

			power >>= 1;
			if (power > 0) 
				multiplier *= multiplier;
		}

		return *this;
	}



	bool operator == (const Matrix other) const{
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				if (arr[i][j] != other.arr[i][j]) 
					return false;

		return true;
	}

	bool operator != (const Matrix other) const{
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				if (arr[i][j] == other.arr[i][j]) 
					return false;

		return true;
	}


	friend vector<T> operator * (const vector<T>& A, const Matrix<T,N,M>& p) {
		assert(A.size() == N);

		vector<T> ans(M,0);

		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				ans[j] += A[i] * p.arr[i][j];

		return ans;
	}
	friend ostream& operator << (ostream& os, const Matrix<T,N,M> & p) {
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < M; ++j){
				os << p.arr[i][j] << " ";
			}
			os << '\n';
		}
		return os;
	}
	
};

template<typename T,const int N , const int M> 
T* Matrix<T,N,M>::c = new T[N*M]; // required for *= operator

template<typename T, const int N>
using Square_Matrix = Matrix<T,N,N> ;

void solve() {
  Square_Matrix <int, 3> T({{1, 1, 2}, {2, 3, 4}, {2, 3, 9}});
  cout << (T ^ 0) << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
