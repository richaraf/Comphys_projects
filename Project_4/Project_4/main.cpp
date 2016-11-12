#include <iostream>
#include "lattice.h"
#include "exact2x2.h"
#include <numerical2.h>
#include <measurements.h>
#include <time.h>
#include <iomanip>
#include <mpi.h>
#include <armadillo>

using namespace arma;
using namespace std;

int main(int nargs, char* args[])
{

<<<<<<< HEAD
    int L = 60; double Temp = 2.0;
=======

    int L = 100; double Temp = 2.0;
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2

    int numprocs, my_rank;

    MPI_Init (&nargs, &args);
    MPI_Comm_size (MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank (MPI_COMM_WORLD, &my_rank);

    if(L==2 && my_rank == 0){
        Exact2x2 exact; // bruker foreløpig J = k = T = 1.0
        double E = exact.Energy(Temp);
        double E_squared = exact.EnergySquared(Temp);
        double M = exact.MagneticMoment();
        double M_squared = exact.MagneticMomentSquared(Temp);
        double Cv_exact = exact.HeatCapacity(E_squared, E, Temp);
        double X_exact = exact.Susceptibility(M_squared, M, Temp);
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

    // Start timer
    cout << "timer start" << endl;
    clock_t start, finish;
    start = clock();

    //run_measurements(&X, &Cv, 1e8, 1./Temp, L, false, my_rank);

    //Numerical2(susceptibility, heat capacity, number of flips,
    //           beta, size of system, spin ordered randomly)

    double* T = new double[numprocs];
    T[0] = 2.0;
    T[1] = 2.1;
    T[2] = 2.15;
    T[3] = 2.20;
    for (int i = 4; i < numprocs; i++){
        T[i] = 2.205 + i*0.005;
    }
    MPI_Barrier(MPI_COMM_WORLD);
    for (int i = 0; i < numprocs; i++){
        MPI_Barrier(MPI_COMM_WORLD);
        if (my_rank == i){cout << T[my_rank] << endl;}
    }



    //array to is going to hold the expectation values
    //for calculated by the different processes:

    mat local_expectation_values = zeros<mat>(7,1);
    double beta = 1/T[my_rank];
    //double beta = 1/Temp;


    Numerical2(2e6, beta, L, true, my_rank, local_expectation_values);

    // local_expectation_values now contains the different expectation values
    // for different temperatures for the different processes


    ofstream oppgd200;
    ofstream oppgd201;
    ofstream oppgd202;
    ofstream oppgd203;
    ofstream oppgd204;
    ofstream oppgd205;
    ofstream oppgd206;
    ofstream oppgd207;
    ofstream oppgd208;
    ofstream oppgd209;
    ofstream oppgd210;
    ofstream oppgd211;
    ofstream oppgd212;
    ofstream oppgd213;
    ofstream oppgd214;
    ofstream oppgd215;
    ofstream oppgd216;
    ofstream oppgd217;
    ofstream oppgd218;
    ofstream oppgd219;
    ofstream oppgd220;
    ofstream oppgd221;
    ofstream oppgd222;
    ofstream oppgd223;
    ofstream oppgd224;

    //remember to change filename depending on L!

    if(my_rank == 0){
<<<<<<< HEAD
        oppgd200.open("../oppgdL60T2000_file.dat");
=======
        oppgd200.open("../oppgdL100T2000_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd200 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd200.close();
    }
    if(my_rank == 1){
<<<<<<< HEAD
        oppgd201.open("../oppgdL60T2100_file.dat");
=======
        oppgd201.open("../oppgdL100T2100_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd201 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd201.close();
    }
    if(my_rank == 2){
<<<<<<< HEAD
        oppgd202.open("../oppgdL60T2150_file.dat");
=======
        oppgd202.open("../oppgdL100T2150_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd202 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd202.close();
    }
    if(my_rank == 3){
<<<<<<< HEAD
        oppgd203.open("../oppgdL60T2200_file.dat");
=======
        oppgd203.open("../oppgdL100T2200_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd203 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd203.close();
    }
    if(my_rank == 4){
<<<<<<< HEAD
        oppgd204.open("../oppgdL60T2225_file.dat");
=======
        oppgd204.open("../oppgdL100T2225_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd204 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd204.close();
    }
    if(my_rank == 5){
<<<<<<< HEAD
        oppgd205.open("../oppgdL60T2230_file.dat");
=======
    oppgd205.open("../oppgdL100T2230_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd205 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd205.close();
    }
    if(my_rank == 6){
<<<<<<< HEAD
        oppgd206.open("../oppgdL60T2235_file.dat");
=======
        oppgd206.open("../oppgdL100T2235_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd206 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd206.close();
    }
    if(my_rank == 7){
<<<<<<< HEAD
        oppgd207.open("../oppgdL60T2240_file.dat");
=======
        oppgd207.open("../oppgdL100T2240_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd207 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd207.close();
    }
    if(my_rank == 8){
<<<<<<< HEAD
        oppgd208.open("../oppgdL60T2245_file.dat");
=======
        oppgd208.open("../oppgdL100T2245_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd208 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd208.close();
    }
    if(my_rank == 9){
<<<<<<< HEAD
        oppgd209.open("../oppgdL60T2250_file.dat");
=======
        oppgd209.open("../oppgdL100T2250_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd209 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd209.close();
    }
    if(my_rank == 10){
<<<<<<< HEAD
        oppgd210.open("../oppgdL60T2255_file.dat");
=======
        oppgd210.open("../oppgdL100T2255_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd210 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd210.close();
    }
    if(my_rank == 11){
<<<<<<< HEAD
        oppgd211.open("../oppgdL60T2260_file.dat");
=======
        oppgd211.open("../oppgdL100T2260_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd211 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd211.close();
    }
    if(my_rank == 12){
<<<<<<< HEAD
        oppgd212.open("../oppgdL60T2265_file.dat");
=======
        oppgd212.open("../oppgdL100T2265_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd212 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd212.close();
    }
    if(my_rank == 13){
<<<<<<< HEAD
        oppgd213.open("../oppgdL60T2270_file.dat");
=======
        oppgd213.open("../oppgdL100T2270_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd213 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd213.close();
    }
    if(my_rank == 14){
<<<<<<< HEAD
        oppgd214.open("../oppgdL60T2275_file.dat");
=======
        oppgd214.open("../oppgdL100T2275_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd214 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd214.close();
    }
    if(my_rank == 15){
<<<<<<< HEAD
        oppgd215.open("../oppgdL60T2280_file.dat");
=======
        oppgd215.open("../oppgdL100T2280_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd215 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd215.close();
    }
    if(my_rank == 16){
<<<<<<< HEAD
        oppgd216.open("../oppgdL60T2285_file.dat");
=======
        oppgd216.open("../oppgdL100T2285_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd216 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd216.close();
    }
    if(my_rank == 17){
<<<<<<< HEAD
        oppgd217.open("../oppgdL60T2290_file.dat");
=======
        oppgd217.open("../oppgdL100T2290_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd217 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd217.close();
    }
    if(my_rank == 18){
<<<<<<< HEAD
        oppgd218.open("../oppgdL60T2295_file.dat");
=======
        oppgd218.open("../oppgdL100T2295_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd218 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd218.close();
    }
    if(my_rank == 19){
<<<<<<< HEAD
        oppgd219.open("../oppgdL60T2300_file.dat");
=======
        oppgd219.open("../oppgdL100T2300_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd219 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd219.close();
    }
    if(my_rank == 20){
<<<<<<< HEAD
        oppgd220.open("../oppgdL60T2305_file.dat");
=======
        oppgd220.open("../oppgdL100T2305_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd220 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd220.close();
    }
    if(my_rank == 21){
<<<<<<< HEAD
        oppgd221.open("../oppgdL60T2310_file.dat");
=======
        oppgd221.open("../oppgdL100T2310_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd221 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd221.close();
    }
    if(my_rank == 22){
<<<<<<< HEAD
        oppgd222.open("../oppgdL60T2315_file.dat");
=======
        oppgd222.open("../oppgdL100T2315_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd222 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd222.close();
    }
    if(my_rank == 23){
<<<<<<< HEAD
        oppgd223.open("../oppgdL60T2320_file.dat");
=======
        oppgd223.open("../oppgdL100T2320_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd223 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd223.close();
    }
    if(my_rank == 24){
<<<<<<< HEAD
        oppgd224.open("../oppgdL60T2325_file.dat");
=======
        oppgd224.open("../oppgdL100T2325_file.dat");
>>>>>>> 0d38efe907762d7f259099555cf26007629371e2
        oppgd224 << local_expectation_values;
        cout << local_expectation_values << endl;
        oppgd224.close();
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

    // End timer
    finish = clock();
    ((finish-start)/CLOCKS_PER_SEC);
    double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
    cout << setiosflags(ios::showpoint | ios::uppercase);
    cout << setprecision(10) << setw(20) << "Time used = " << timeused  << endl;

    //Nar du skal kjore, kommenter inn linjene over 136

}
