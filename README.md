# 📈 Sample Covariance Matrix (C Implementation)

This library provides a **fast and efficient** implementation of the **sample covariance matrix** calculation using **C** and **LAPACKE/CBLAS**. The key design is based on a **single heap allocation flat buffer** for performance and interoperability.

---

## 🚀 Why This Project?

The main motivation is to provide a **lightweight**, **language-agnostic**, and **performance-critical** sample covariance calculation routine. Here's why:

- ✅ **Low-level control** with C allows you to fine-tune performance.
- ✅ **Single memory allocation** reduces overhead and improves cache efficiency.
- ✅ **BLAS (OpenBLAS)** is used under the hood for optimized matrix multiplications (`cblas_dgemm`).
- ✅ **Easy integration** with other languages like Rust, Python (via `ctypes`/`cffi`), or even embedded environments.
- ✅ **No dependency on higher-level frameworks or interpreters**.

---

## 🧮 What This Does

This library computes the **sample covariance matrix**:

\[
\text{Cov}(X) = \frac{1}{n - 1} (X - \bar{X})^T (X - \bar{X})
\]

Where:

- `X` is a matrix of shape `[n_samples, n_features]`
- Centering is performed **in-place**
- Matrix multiplication uses **cblas_dgemm** for performance

---

## 🛠️ Compilation Instructions

To build and test the code using `gcc`:

```bash
gcc -o test_program test.c c_src/sample_covariance_lapacke.c \
    -I./c_src -L/usr/lib -lopenblas -llapacke -lm

```

### This library is tested for Linux
