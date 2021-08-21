#pragma once
# include <fstream>
# include <sstream>
# include <algorithm>
# include <math.h>
# include <chrono>
# include <Windows.h>
# include <iostream>
# include <vector>
# include <list>
# include <map>
# include "Graph.h"
using namespace std;

/*********************************************/
/************  ADDITIONAL FUNCTION  **********/
/*********************************************/

//  Menu implementation for the user
int Menu_of_Project(float* prob, int* Vrt, int* num_of_graphs, int* choice_1, int* choice_2, int* choice_3);

//  The main loop of the project
void MainTestLoop(int num_of_loops, int simulation_flag, int Vrt, int num_of_graphs, int choise_1, int choise_2, int choise_3,
    vector<float>* Diameter_arr, vector<float>* Conn_arr, vector<float>* Isul_arr, vector<float> Prob_arr_Threshold_1_2_3);

//  Prepration for the simulation test (Init all Variables
void SimulationPreperation(int* num_of_loops,
    vector<float>* Diameter_arr,
    vector<float>* Conn_arr, vector<float>* Isul_arr,
    vector<float>* Prob_arr_Threshold_1_2_3,
    double Threshold_1_2, double Threshold_3);

//  Build Randon graph (Vertex and Edges
Graph build_random_graph(int V, float prob);

//  Is graph connected
int connectivity(Graph& graph);

//  Find the diammeter
int diameter(Graph& graph);

// checking if there is lonely Vertices  O( V )
int Is_Isolated(Graph& graph);

//  Export all results to CSV
void Report_to_csv(vector<float> prob, int vrt, int graphs, int choise_1, int choise_2, int choise_3,
    vector<float> diam_prob, vector<float> conn_prob, vector<float> isul_prob);

// random function between range ( Min, Max )
float Random(float MIN, float MAX);

