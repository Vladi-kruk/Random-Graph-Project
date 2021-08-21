
# include <fstream>
# include <sstream>
# include <algorithm>
# include <math.h>
# include <chrono>
# include <Windows.h>
# include "Graph.h"

using namespace std;


/* MAIN EXERCISE FUNCTION DECLERATION  */

Graph build_random_graph(int , float);
int connectivity(Graph &);
int diameter(Graph &);
int Is_Isolated(Graph&);

/* UTILITY FUNCTION DECLERATION  */


float Random(float, float);
void Report_to_csv(vector<float>,int, int, int, int, int, vector<float>, vector<float>, vector<float>);
int Menu_of_Project(float*, int*, int*, int*, int*, int*);
void SimulationPreperation(int*, vector<float>*, vector<float>*, vector<float>*, vector<float>*, double, double);
void MainTestLoop(int, int, int, int, int, int, int, vector<float>*, vector<float>*, vector<float>*, vector<float>);

/*****************************************************************************************************************/
/******************************************************  MAIN  ***************************************************/
/*****************************************************************************************************************/

int main(){
    // Variables decleration
    int Vrt, num_of_graphs, choise_1, choise_2, choise_3;
    int num_of_loops, simulation_flag;
    float prob;    
    vector<float>Diameter_arr;
    vector<float>Conn_arr;
    vector<float>Isul_arr;
    vector<float>Prob_arr_Threshold_1_2_3;    

    // Menu function of the project
    simulation_flag = Menu_of_Project(&prob, &Vrt, &num_of_graphs, &choise_1, &choise_2, &choise_3);

    double Threshold_1_2 = logf(Vrt) / Vrt;
    double Threshold_3 = sqrtf(2 * Threshold_1_2);

    // Prepration for Simulation test
    if (simulation_flag) {
        SimulationPreperation(
            &num_of_loops, &Diameter_arr,
            &Conn_arr, &Isul_arr,
            &Prob_arr_Threshold_1_2_3,
            Threshold_1_2,Threshold_3);
    }
    // Init for regular test for one Graph
    else {
        num_of_loops = 1;
        Prob_arr_Threshold_1_2_3.push_back(prob);
    }
    //  Start timer
    srand(static_cast<unsigned>(time(0)));
    auto start = chrono::high_resolution_clock::now();

    cout << "##################################### "
        << " The Test Started "
        << "#####################################" << endl << endl;

    // Main While for each Prorobability in Threshold Array
    MainTestLoop(num_of_loops, simulation_flag, Vrt, num_of_graphs,
        choise_1, choise_2, choise_3,
        &Diameter_arr, &Conn_arr, &Isul_arr,
        Prob_arr_Threshold_1_2_3);
    // Export to CSV 
    if (simulation_flag)
        Report_to_csv(Prob_arr_Threshold_1_2_3, 
            Vrt, num_of_graphs, 
            choise_1, choise_2, choise_3, 
            Diameter_arr, Conn_arr, Isul_arr);

    // Timer calculation
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(stop - start);
    unsigned int hour = (duration.count() / 3600);
    unsigned int min = (duration.count() / 60) % 60;
    unsigned int sec = duration.count() % 60;

    cout << endl << "###  The test was done  ---->  Runing Time     ######   ";
    (hour > 9) ? cout << hour << ":" : cout << "0" << hour << ":";
    (min > 9) ? cout << min << ":" : cout << "0" << min << ":";
    (sec > 9) ? cout << sec : cout << "0" << sec;
    cout << "   ######" << endl << endl;
}