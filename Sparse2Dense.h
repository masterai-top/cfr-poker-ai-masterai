#ifndef _SPARSE_2_DENSE_H_
#define _SPARSE_2_DENSE_H_

#include <unordered_map>
#include <vector>

using namespace std;

class Sparse2Dense
{
public:
  Sparse2Dense(void) { num_ = 0; }
  virtual ~Sparse2Dense(void) {}
  virtual int SparseToDense(long long int sparse) = 0;
  virtual long long int DenseToSparse(int dense) = 0;
  virtual void Clear(void) = 0;
  int Num(void) const { return num_; }

protected:
  int num_;
};

class SparseAndDenseInt : public Sparse2Dense
{
public:
  SparseAndDenseInt(void);
  ~SparseAndDenseInt(void);
  int SparseToDense(long long int sparse);

  long long int DenseToSparse(int dense);
  void Clear(void);

private:
  static const int kBlockSize = 1000000;

  unordered_map<int, int> *sparse_to_dense_;
  vector<int *> *dense_to_sparse_;
};

class Sparse2DenseL : public Sparse2Dense
{
public:
  Sparse2DenseL(void);
  ~Sparse2DenseL(void);

  int SparseToDense(long long int sparse);
  long long int DenseToSparse(int dense);
  void Clear(void);

private:
  static const int kBlockSize = 1000000;

  unordered_map<long long int, int> *sparse_to_dense_;
  vector<long long int *> *dense_to_sparse_;
};

#endif
