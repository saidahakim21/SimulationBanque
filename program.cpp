#include "program.hpp"

using namespace std;

/*

int main() {

    int cashierNb = 3; 
    double* averageServiceTimes = new double[cashierNb];
    setCashierServiceTime(&averageServiceTimes, cashierNb);



    Simulation simulation(cashierNb,30,1000, averageServiceTimes); 
    simulation.run(); 

    simulation.displayStatistics(); 

    return 0;
}
*/
int main(int argc, char *argv[]) {
    int nombre_caissier = 0;
    double temp_moyen_service[100] = {};
    int duree_prevue = 0;
    double temp_moyen_arrive = 0;

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-nc") == 0) {
            nombre_caissier = atoi(argv[i + 1]);
        }

        if (strcmp(argv[i], "-st") == 0) {
            if (nombre_caissier == 0) {
                cout << "please set -nc option first, before -st option" << endl;
                exit(-1);
            } else {
                for (int j = 0; j < nombre_caissier; j++) {
                    sscanf(argv[i + 1 + j], "%lf", &temp_moyen_service[j]);
                }
            }
        }

        if (strcmp(argv[i], "-dp") == 0) {
            duree_prevue = atoi(argv[i + 1]);
        }

        if (strcmp(argv[i], "-tm") == 0) {
            sscanf(argv[i + 1], "%lf", &temp_moyen_arrive);
        }
    }

    cout << "nombre_caissier = " << nombre_caissier << endl;
    cout << "temp_moyen_service = " << temp_moyen_service[1] << endl;
    cout << "duree_prevue = " << duree_prevue << endl;
    cout << "temp_moyen_arrive = " << temp_moyen_arrive << endl;



    Simulation simulation(nombre_caissier,temp_moyen_arrive,duree_prevue, temp_moyen_service);
    simulation.run();

    simulation.displayStatistics();

    return 0;
}

void setCashierServiceTime(double **arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        *(*arr + i) = 15;
    }
}
