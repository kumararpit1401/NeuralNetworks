// MatrixUtils.cpp
#include "MatrixUtils.h"
#include <iostream>

namespace MatrixUtils {

    std::vector<float> mat_vec_mul(const Matrix& mat, const std::vector<float>& vec) {
        size_t rows = mat.size();
        size_t cols = mat[0].size();
        if (vec.size() != cols) {
            throw std::invalid_argument("Matrix columns must match vector size.");
        }

        std::vector<float> result(rows, 0.0f);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result[i] += mat[i][j] * vec[j];
            }
        }
        return result;
    }

    Matrix mat_mul(const Matrix& A, const Matrix& B) {
        size_t A_rows = A.size();
        size_t A_cols = A[0].size();
        size_t B_rows = B.size();
        size_t B_cols = B[0].size();

        if (A_cols != B_rows) {
            throw std::invalid_argument("A's columns must match B's rows.");
        }

        Matrix result(A_rows, std::vector<float>(B_cols, 0.0f));
        for (size_t i = 0; i < A_rows; ++i) {
            for (size_t j = 0; j < B_cols; ++j) {
                for (size_t k = 0; k < A_cols; ++k) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return result;
    }

    Matrix transpose(const Matrix& mat) {
        size_t rows = mat.size();
        size_t cols = mat[0].size();
        Matrix result(cols, std::vector<float>(rows));
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result[j][i] = mat[i][j];
            }
        }
        return result;
    }

    void print(const Matrix& mat) {
        for (const auto& row : mat) {
            for (float val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

}
