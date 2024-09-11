#include <iostream>

using namespace std;

// Fungsi untuk mengubah matriks 2D menjadi matriks 1D
void matriks2D_to_1D(int **matrix2D, int rows, int cols) {
    int total_elements = rows * cols;
    int *matrix1D = new int[total_elements];

    int index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix1D[index++] = matrix2D[i][j];
        }
    }

    cout << "Matriks 1D hasil:" << endl;
    for (int i = 0; i < total_elements; ++i) {
        cout << matrix1D[i] << " ";
    }
    cout << endl;

    delete[] matrix1D;
}

// Fungsi untuk mengubah matriks 1D menjadi matriks 2D
void matriks1D_to_2D(int *matrix1D, int rows, int cols) {
    int **matrix2D = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix2D[i] = new int[cols];
    }

    int index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix2D[i][j] = matrix1D[index++];
        }
    }

    cout << "Matriks 2D hasil:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix2D[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix2D[i];
    }
    delete[] matrix2D;
}

// Fungsi untuk menampilkan matriks 2D
void display_matrix2D(int **matrix2D, int rows, int cols) {
    cout << "Matriks 2D sebelum perubahan:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix2D[i][j] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk menampilkan matriks 1D
void display_matrix1D(int *matrix1D, int total_elements) {
    cout << "Matriks 1D sebelum perubahan:" << endl;
    for (int i = 0; i < total_elements; ++i) {
        cout << matrix1D[i] << " ";
    }
    cout << endl;
}

// Fungsi untuk menghitung jumlah elemen dalam matriks 2D
int count_elements(int **matrix, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            count++;
        }
    }
    return count;
}

// Fungsi untuk mengecek apakah jumlah elemen matriks 1D atau 2D sesuai atau tidak
bool is_valid(int rows, int cols, int count) {
    return (rows * cols == count);
}

int main() {
    int option;
    cout << "Pilih matriks 2D atau 1D (2 untuk 2D, 1 untuk 1D): ";
    cin >> option;

    if (option == 2) { // Matriks 2D ke 1D
        int rows, cols;
        cout << "Masukkan jumlah baris matriks: ";
        cin >> rows;
        cout << "Masukkan jumlah kolom matriks: ";
        cin >> cols;

        int **matrix2D = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix2D[i] = new int[cols];
        }

        cout << "Masukkan elemen-elemen matriks 2D:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> matrix2D[i][j];
            }
        }

        display_matrix2D(matrix2D, rows, cols);

        int total_elements = count_elements(matrix2D, rows, cols);
        if (is_valid(rows, cols, total_elements)) {
            matriks2D_to_1D(matrix2D, rows, cols);
        } else {
            cout << "Jumlah elemen matriks tidak sesuai!" << endl;
        }

        for (int i = 0; i < rows; ++i) {
            delete[] matrix2D[i];
        }
        delete[] matrix2D;
    } else if (option == 1) { // Matriks 1D ke 2D
        int total_elements;
        cout << "Masukkan jumlah elemen matriks 1D: ";
        cin >> total_elements;

        int rows, cols;
        cout << "Masukkan jumlah baris matriks 2D: ";
        cin >> rows;
        cout << "Masukkan jumlah kolom matriks 2D: ";
        cin >> cols;

        if (is_valid(rows, cols, total_elements)) {
            int *matrix1D = new int[total_elements];
            cout << "Masukkan elemen-elemen matriks 1D:" << endl;
            for (int i = 0; i < total_elements; ++i) {
                cin >> matrix1D[i];
            }

            display_matrix1D(matrix1D, total_elements);

            matriks1D_to_2D(matrix1D, rows, cols);
            delete[] matrix1D;
        } else {
            cout << "Jumlah elemen matriks tidak sesuai!" << endl;
        }
    } else {
        cout << "Pilihan tidak valid!" << endl;
    }

    return 0;
}
