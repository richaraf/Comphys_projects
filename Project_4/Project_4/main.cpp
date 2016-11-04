#include <iostream>
#include "lattice.h"
#include "exact2x2.h"
#include <numerical2.h>
#include <time.h>
#include <iomanip>
#include <mpi.h>
#include <armadillo>

using namespace arma;
using namespace std;

int main(int nargs, char* args[])
{
    int L = 40;

    int numprocs, my_rank;

    MPI_Init (&nargs, &args);
    MPI_Comm_size (MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank (MPI_COMM_WORLD, &my_rank);

    if(L==2 && my_rank == 0){
        Exact2x2 exact; // bruker foreløpig J = k = T = 1.0
        double E = exact.Energy(1.0);
        double E_squared = exact.EnergySquared(1.0);
        double M = exact.MagneticMoment();
        double M_squared = exact.MagneticMomentSquared(1.0);
        double Cv_exact = exact.HeatCapacity(E_squared, E, 1.0);
        double X_exact = exact.Susceptibility(M_squared, M, 1.0);
        cout << "Exact energy for 2x2, E = " << E << endl;
        cout << "Exact energy  squared for 2x2, E*E = " << E_squared << endl;
        cout << "Exact magnetic moment for 2x2, M = " << M << endl;
        cout << "Exact magnetic moment squared for 2x2, M*M = " << M_squared << endl;
        cout << "Exact heat capacity for 2x2 Cv = " << Cv_exact << endl;
        cout << "Exact susceptibility for 2x2 X = " << X_exact << endl;
    }
//    double X = 0;
//    double Cv = 0;
//    double X_total = 0.0;
//    double Cv_total = 0.0;

//    // Start timer
//    cout << "timer start" << endl;
//    clock_t start, finish;
//    start = clock();

    //Numerical2(susceptibility, heat capacity, number of sweeps,
    //           beta, size of system, spin ordered randomly)

    double* T = new double[numprocs];
    for (int i = 0; i < numprocs; i++){
        T[i] = 2.0 + i*0.5;
    }

    //array to is going to hold the expectation values
    //for calculated by the different processes:
    mat local_expectation_values = zeros<mat>(6,1);
    double beta = 1/T[my_rank];
    //cout << T[my_rank] << " " << beta << endl;

    Numerical2(1e7, beta, L, false, my_rank, local_expectation_values);
    // local_expectation_values now contains the different expectation values
    // for different temperatures for the different processes


    MPI_Barrier(MPI_COMM_WORLD);
    //MPI_Reduce(&Cv, &Cv_total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);




    //cout << "Cv: " << Cv << endl;
    //cout << setiosflags(ios::showpoint | ios::uppercase);
    //cout << setprecision(10) << setw(20) << "Time used = " << timeused  << endl;

//    for(int i = 0; i < numprocs; i++){
//        MPI_Barrier(MPI_COMM_WORLD);
//        if (my_rank == i){
//            cout << "Local expectation values for T = " << T[i] << ":" << endl << local_expectation_values << endl;
//        }

//    }
    ofstream oppgd20;
    ofstream oppgd21;
    ofstream oppgd22;
    ofstream oppgd23;
    ofstream oppgd24;
    ofstream oppgd25;
    ofstream oppgd26;
    if(my_rank == 0){
        oppgd20.open("../oppgdL40T200_file.dat");
        oppgd20 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd20.close();
    }
    if(my_rank == 1){
        oppgd21.open("../oppgdL40T205_file.dat");
        oppgd21 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd21.close();
    }
    if(my_rank == 2){
        oppgd22.open("../oppgdL40T210_file.dat");
        oppgd22 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd22.close();
    }
    if(my_rank == 3){
        oppgd23.open("../oppgdL40T215_file.dat");
        oppgd23 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd23.close();
    }
    if(my_rank == 4){
        oppgd24.open("../oppgdL40T220_file.dat");
        oppgd24 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd24.close();
    }
    if(my_rank == 5){
        oppgd25.open("../oppgdL40T225_file.dat");
        oppgd25 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd25.close();
    }
    if(my_rank == 6){
        oppgd26.open("../oppgdL40T230_file.dat");
        oppgd26 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd26.close();
    }
//    for (int i = 0; i < numprocs-1; i++){
//        expectation_values(i, my_rank) = local_expectation_values[i];
//        //cout << i << " " << my_rank << endl;
//        //cout << expectation_values << endl;
//        }
//    cout << expectation_values << endl;


    //cout << expectation_values << endl;

    //    MPI_Barrier(MPI_COMM_WORLD);
//    if( my_rank ==0 ){
//        cout << "Cv average for all processes = " << Cv_total/numprocs << endl;
//    }
    MPI_Finalize();

//    // End timer
//    finish = clock();
//    ((finish-start)/CLOCKS_PER_SEC);
//    double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
//    cout << setiosflags(ios::showpoint | ios::uppercase);
//    cout << setprecision(10) << setw(20) << "Time used = " << timeused  << endl;

}
