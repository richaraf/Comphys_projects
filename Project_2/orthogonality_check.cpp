#include <armadillo>
#include <jacobian_rotation.h>
#include <iomanip>

using namespace arma;
using namespace std;

// Test to check orthogonality
void orthogonality_check_func(mat R, double eps){
    int R_cols = R.n_cols;
    int R_rows = R.n_rows;
    vec col1 = zeros<vec>(R_rows);
    vec col2 = zeros<vec>(R_rows);
    for (int c1 = 0; c1 < R_cols; c1++){
        for (int i = 0; i < R_rows; i++){
            col1(i) = R(c1,i);
            }
        for (int c2 = 0; c2 < R_cols; c2++){
            if (c1 != c2){
            for (int j = 0; j < R_rows; j++){
                col2(j) = R(c2,j);
            }
            double dotproduct = dot(col1,col2);
            if (dotproduct > eps){
                cout << "Error: dot product not conserved." << endl;
            }
            // cout << dotproduct << endl;
        }
        }
    }
}
// End of orthogonality test
