#include <iostream>
#include <vector>
using namespace std;

void pRINTtRIANGLE(int** triangle, int *rows) {
    int x = *rows - 1;
    for (int i = 0; i < *rows; i++) {
            for(int j = 0; j < x; j++){
                cout <<"  ";
            }
            for(int k = 0; k <= i; k++){
                cout << triangle[i][k] <<"   ";
            }
            --x;
            cout << endl;
    }
}


int fINDmAX(int * rows, int** triangle){
    int maximom;
    if(*rows % 2 == 0){
       maximom = *rows/2;
    }else maximom = (*rows-1)/2;
    return triangle[*rows-1][maximom];
}


void sETtRIANGLE(int * rows, int** triangle){
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j <= i; j++) {
                triangle[i][j] = 1;
        }
    }


    for (int i = 2; i < *rows; i++) {
        for (int j = 1; j < i; j++) {

                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }



}

int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    int** triangle = new int*[rows];
    for (int i = 0; i < rows; i++) {
        triangle[i] = new int[i + 1];
    }

    sETtRIANGLE(&rows, triangle);


    pRINTtRIANGLE(triangle, &rows);

    int maxVal = 0;
    cout << "Maximom value is : " << fINDmAX(&rows, triangle) << endl;
    cout << "This is a conflict test from main branch!" << endl

    for (int i = 0; i < rows; i++) {
        delete[] triangle[i];
    }
    delete[] triangle;

    return 0;
}
