// MatrixUtils.h
#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#include <vector>
#include <stdexcept>

namespace MatrixUtils {
    using Matrix = std::vector<std::vector<float>>;

    std::vector<float> mat_vec_mul(const Matrix& mat, const std::vector<float>& vec);

    Matrix mat_mul(const Matrix& A, const Matrix& B);

    Matrix transpose(const Matrix& mat);

    void print(const Matrix& mat);
}

#endif // MATRIX_UTILS_H
