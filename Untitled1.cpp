#include <iostream>
using namespace std;

int main() {
    int x, y, repeat_num;
    cout << "Enter number of rows and columns: ";
    cin >> x >> y;
    cout << "enter repeat number: " << endl;
    cin >> repeat_num;


    int a[x][y];
    int b[x][y];


    cout << "Enter matrix 1 numbers:\n";
    for (int i = 0; i < x; i++) {
        cout << "Row " << i + 1 << ":\n";
        for (int j = 0; j < y; j++) {
            cout << "Column " << j + 1 << ": ";
            cin >> a[i][j];
        }
    }


    cout << "Enter matrix 2 numbers:\n";
    for (int i = 0; i < x; i++) {
        cout << "Row " << i + 1 << ":\n";
        for (int j = 0; j < y; j++) {
            cout << "Column " << j + 1 << ": ";
            cin >> b[i][j];
        }
    }


    int a_numes = 0, b_numes = 0;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            if (a[i][j] != repeat_num)
                a_numes++;

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            if (b[i][j] != repeat_num)
                b_numes++;


    if (((x * y * 2) < (a_numes * 4)) || ((x * y * 2) < (b_numes * 4))) {
        cout << "Not optimal.\n";
        return 0;
    }


    int a_spars[a_numes][3];
    int k = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (a[i][j] != repeat_num) {
                a_spars[k][0] = i + 1;
                a_spars[k][1] = j + 1;
                a_spars[k][2] = a[i][j];
                k++;
            }
        }
    }


    int b_spars[b_numes][3];
    k = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (b[i][j] != repeat_num) {
                b_spars[k][0] = i + 1;
                b_spars[k][1] = j + 1;
                b_spars[k][2] = b[i][j];
                k++;
            }
        }
    }


    int P_max = a_numes + b_numes;
    int c[P_max][3];

    int c_numes = 0;


    for (int i = 0; i < a_numes; i++) {
        c[c_numes][0] = a_spars[i][0];
        c[c_numes][1] = a_spars[i][1];
        c[c_numes][2] = a_spars[i][2];
        c_numes++;
    }


    for (int j = 0; j < b_numes; j++) {
        bool found = false;

        for (int i = 0; i < c_numes; i++) {
            if (c[i][0] == b_spars[j][0] && c[i][1] == b_spars[j][1]) {
                c[i][2] += b_spars[j][2];
                found = true;
                break;
            }
        }

        if (!found) {
            c[c_numes][0] = b_spars[j][0];
            c[c_numes][1] = b_spars[j][1];
            c[c_numes][2] = b_spars[j][2];
            c_numes++;
        }
    }


    cout << "\nResult sparse matrix (row col value):\n";
    for (int i = 0; i < c_numes; i++) {
        cout << "{" << c[i][0] << " " << c[i][1] << " " << c[i][2] << "}\n";
    }

    return 0;
}
