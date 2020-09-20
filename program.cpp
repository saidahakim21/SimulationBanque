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
int main (int argc, char* argv[]) {
    int nombre_caissier = 0;
    int temp_moyen_service = 0;
    int duree_prevue = 0;
    int temp_moyen_arrive = 0;
    int c;

    int i = 0;
    cout << "argc = " << argc <<endl;

    while ((c = getopt(argc, argv, "n:s:d:t:")) != -1)
    {
        cout << "argv[i] = "<< argv[i] <<endl;
        cout << "c = "<< char (c)  <<endl;
        switch (c) {
            case 'n':
                nombre_caissier = atoi(argv[i+1]);
                i++;
                break;
            case 's':
                temp_moyen_service = atoi(argv[i+1]);
                break;
            case 'd':
                duree_prevue = atoi(argv[i+1]);
                break;
            case 't':
                temp_moyen_arrive = atoi(argv[i+1]);
                break;
            default:
                break;
        }
        i++;
    }
    cout<<"nombre_caissier = " << nombre_caissier << endl;
    cout<<"temp_moyen_service = " << temp_moyen_service << endl;
    cout<<"duree_prevue = " << duree_prevue << endl;
    cout<<"temp_moyen_arrive = " << temp_moyen_arrive << endl;

    return 0;
}

void setCashierServiceTime(double** arr, int arrSize) {
    for(int i=0 ; i<arrSize ; i++) {
        *(*arr+i) = 15;
    }
}
