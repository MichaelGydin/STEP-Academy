#include <iostream>

using namespace std;

bool isInArray(int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    } return false;
}

int main() {
    /*// task 1
    int M, N;
    cout << "Enter size A(M): "; cin >> M;
    cout << "Enter size B(N): "; cin >> N; cout << endl;

    int* A = new int[M];
    int* B = new int[N];
    int* C = new int[M];
    int C_size = 0;

    cout << "Enter elements for a: ";
    for (int i = 0; i < M; i++)
        cin >> A[i];

    cout << "Enter elements for B: ";
    for (int i = 0; i < N; i++)
        cin >> B[i];

    for (int i = 0; i < M; i++) {
        if (!isInArray(B, N, A[i])) {
            if (!isInArray(C, C_size, A[i])) {
                C[C_size] = A[i];
                C_size++;
            }
        }
    }

    cout << endl << "Elements A not included in B, without repetition: ";
    for (int i = 0; i < C_size; i++)
        cout << C[i] << " ";

    delete[] A;
    delete[] B;
    delete[] C; */

    // task 2
    int M, N;
    cout << "Enter size A(M): "; cin >> M;
    cout << "Enter size B(N): "; cin >> N; cout << endl;

    int* A = new int[M];
    int* B = new int[N];
    int* C = new int[M + N];
    int C_size = 0;

    cout << "Enter elements for A: ";
    for (int i = 0; i < M; i++)
        cin >> A[i];

    cout << "Enter elements for B: ";
    for (int i = 0; i < N; i++)
        cin >> B[i];

    for (int i = 0; i < M; i++) {
        if (!isInArray(B, N, A[i]) && !isInArray(C, C_size, A[i])) {
            C[C_size] = A[i];
            C_size++;
        }
    }

    for (int i = 0; i < N; i++) {
        if (!isInArray(A, M, B[i]) && !isInArray(C, C_size, B[i])) {
            C[C_size] = B[i];
            C_size++;
        }
    }

    cout << endl << "Elements from A and B that are not common, without repetition: ";
    for (int i = 0; i < C_size; i++)
        cout << C[i] << " ";
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;
}