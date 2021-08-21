#pragma once
#include "UtilityFunctions.h"
#define PROB_ARR_SIZE 10
using namespace std;

/*********************************************/
/************  ADDITIONAL FUNCTION  **********/
/*********************************************/

void MainTestLoop(int num_of_loops, int simulation_flag, int Vrt, int num_of_graphs, int choise_1, int choise_2, int choise_3,
    vector<float>* Diameter_arr, vector<float>* Conn_arr, vector<float>* Isul_arr, vector<float> Prob_arr_Threshold_1_2_3)
{
    int connectiv, diam, real_diam, isolated = 0;

    for (int j = 0; j < num_of_loops; j++) {
        connectiv = 0;
        diam = 0;
        isolated = 0;

        if (simulation_flag)
            cout << endl << " **********  Set Number " << j + 1 << " were done   ***********" << endl << endl;

        // Testing attributes following User decision
        if (choise_1 == 2) {  // According requirements of exercise
            for (int i = 0; i < num_of_graphs; i++) {

                if (j < num_of_loops / 2) {
                    Graph graph = build_random_graph(Vrt, Prob_arr_Threshold_1_2_3[j]);
                    if (connectivity(graph))
                        connectiv++;
                    if (Is_Isolated(graph))
                        isolated++;
                }
                else {
                    Graph graph = build_random_graph(Vrt, Prob_arr_Threshold_1_2_3[j]);
                    real_diam = diameter(graph);
                    if (2 == real_diam)
                        diam++;
                }
                if (!(i % 50) && i)
                    cout << i << " Graphs were done" << endl;
                if (!simulation_flag) {
                    cout << "Diameter =" << real_diam << endl
                        << "Vertex isolated = " << (isolated ? "Yes" : "No") << endl
                        << "Connected = " << (connectiv ? "Yes" : "No") << endl;
                }
            }
        }
        else {  // All attributs case
            if (choise_1) {
                for (int i = 0; i < num_of_graphs; i++) {
                    Graph graph = build_random_graph(Vrt, Prob_arr_Threshold_1_2_3[j]);
                    if (connectivity(graph))
                        connectiv++;
                    real_diam = diameter(graph);
                    if (2 == real_diam)
                        diam++;
                    if (Is_Isolated(graph))
                        isolated++;
                    if (!(i % 50) && i)
                        cout << i << " Graphs were done" << endl;
                    if (!simulation_flag) {
                        cout << "Diameter = " << real_diam << endl
                            << "Vertex isolated = " << (isolated ? "Yes" : "No") << endl
                            << "Connected = " << (connectiv ? "Yes" : "No") << endl;
                    }
                }
            }
            else { // Partial attributs test
                if (choise_2 == 1) {
                    switch (choise_3)
                    {
                    case 1: {   // Diameter check
                        for (int i = 0; i < num_of_graphs; i++) {
                            Graph graph = build_random_graph(Vrt, Prob_arr_Threshold_1_2_3[j]);
                            real_diam = diameter(graph);
                            if (2 == real_diam)
                                diam++;
                            if (!(i % 50) && i)
                                cout << i << " Graphs were done" << endl;
                            if (!simulation_flag) {
                                cout << "Diameter = " << real_diam << endl;
                            }
                        }
                    }break;
                    case 2: {   // connectivity check
                        for (int i = 0; i < num_of_graphs; i++) {
                            Graph graph = build_random_graph(Vrt, Prob_arr_Threshold_1_2_3[j]);
                            if (connectivity(graph))
                                connectiv++;
                            if (!(i % 50) && i)
                                cout << i << " Graphs were done" << endl;
                            if (!simulation_flag) {
                                cout << "Connected = " << (connectiv ? "Yes" : "No") << endl;
                            }
                        }
                    }break;
                    case 3: {   // Is_Isolated check
                        for (int i = 0; i < num_of_graphs; i++) {
                            Graph graph = build_random_graph(Vrt, Prob_arr_Threshold_1_2_3[j]);
                            if (Is_Isolated(graph))
                                isolated++;
                            if (!(i % 50) && i)
                                cout << i << " Graphs were done" << endl;
                            if (!simulation_flag) {
                                cout << "Vertex isolated = " << (isolated ? "Yes" : "No") << endl;
                            }
                        }
                    }break;
                    default:
                        break;
                    }
                }
                else {  // Checking 2 attributs
                    switch (choise_3)
                    {
                    case 1: {
                        for (int i = 0; i < num_of_graphs; i++) {
                            Graph graph = build_random_graph(Vrt, Prob_arr_Threshold_1_2_3[j]);
                            real_diam = diameter(graph);
                            if (2 == real_diam)
                                diam++;
                            if (connectivity(graph))
                                connectiv++;
                            if (!(i % 50) && i)
                                cout << i << " Graphs were done" << endl;
                            if (!simulation_flag) {
                                cout << "Diameter = " << real_diam << endl
                                    << "Connected = " << (connectiv ? "Yes" : "No") << endl;
                            }
                        }
                    }break;
                    case 2: {
                        for (int i = 0; i < num_of_graphs; i++) {
                            Graph graph = build_random_graph(Vrt, Prob_arr_Threshold_1_2_3[j]);
                            if (connectivity(graph))
                                connectiv++;
                            if (Is_Isolated(graph))
                                isolated++;
                            if (!(i % 50) && i)
                                cout << i << " Graphs were done" << endl;
                            if (!simulation_flag) {
                                cout << "Vertex isolated = " << (isolated ? "Yes" : "No")
                                    << endl << "Connected = " << (connectiv ? "Yes" : "No") << endl;
                            }
                        }
                    }break;
                    case 3: {
                        for (int i = 0; i < num_of_graphs; i++) {
                            Graph graph = build_random_graph(Vrt, Prob_arr_Threshold_1_2_3[j]);
                            if (Is_Isolated(graph))
                                isolated++;
                            real_diam = diameter(graph);
                            if (2 == real_diam)
                                diam++;
                            if (!(i % 50) && i)
                                cout << i << " Graphs were done" << endl;
                            if (!simulation_flag) {
                                cout << "Diameter = " << real_diam << endl
                                    << "Vertex isolated = " << (isolated ? "Yes" : "No") << endl;
                            }
                        }
                    }break;
                    default:
                        break;
                    }
                }
            }
        }
        // insert probability results of the simulation
        if (simulation_flag) {
            (*Diameter_arr)[j] = (float)diam / num_of_graphs;
            (*Conn_arr)[j] = (float)connectiv / num_of_graphs;
            (*Isul_arr)[j] = (float)isolated / num_of_graphs;
        }
    }
}

void SimulationPreperation(int* num_of_loops,
    vector<float>* Diameter_arr,
    vector<float>* Conn_arr, vector<float>* Isul_arr,
    vector<float>* Prob_arr_Threshold_1_2_3,
    double Threshold_1_2, double Threshold_3)
{
    *num_of_loops = PROB_ARR_SIZE * 2;
    Diameter_arr->resize(PROB_ARR_SIZE * 2);
    Conn_arr->resize(PROB_ARR_SIZE * 2);
    Isul_arr->resize(PROB_ARR_SIZE * 2);
    Prob_arr_Threshold_1_2_3->resize(PROB_ARR_SIZE * 2);

    // building a Probability Array according to Threshold (half below and half above for each Threshold)
    for (int i = 0; i < (2 * PROB_ARR_SIZE); i++) {
        if (i < (2 * PROB_ARR_SIZE) / 2) {
            if (i < (2 * PROB_ARR_SIZE) / 4) {
                (*Prob_arr_Threshold_1_2_3)[i] = Random(Threshold_1_2 - Threshold_1_2 * 0.35, Threshold_1_2);
            }
            else {
                (*Prob_arr_Threshold_1_2_3)[i] = Random(Threshold_1_2, Threshold_1_2 * 1.4);
            }
        }
        else {
            if (i < ((6 * PROB_ARR_SIZE) / 4)) {
                (*Prob_arr_Threshold_1_2_3)[i] = Random(Threshold_3 - Threshold_3 * 0.18, Threshold_3);
            }
            else {
                (*Prob_arr_Threshold_1_2_3)[i] = Random(Threshold_3, Threshold_3 * 1.3);
            }
        }
    }
    // Sorting Threshold array
    sort(Prob_arr_Threshold_1_2_3->begin(), Prob_arr_Threshold_1_2_3->begin() + PROB_ARR_SIZE);
    sort(Prob_arr_Threshold_1_2_3->begin() + PROB_ARR_SIZE, Prob_arr_Threshold_1_2_3->end());
}


Graph build_random_graph(int V, float prob) {
    Graph graph(V);
    float r;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            r = Random(0, 1);  // random function between 0 to 1
            if (prob > r) {
                graph.E++;
                graph.Edge[i].push_back(j);
                graph.Edge[j].push_back(i);
            }
        }
    }
    return graph;
}

int connectivity(Graph& graph) {
    const int V = graph.get_V();
    int* dist = new int[V];
    int diam = 0;

    // connectivity check by BFS O( V+E )
    if (!(graph.BFS(V, &diam, /*pred,*/ dist, 0))) {
        delete[] dist;
        return 0;
    }
    delete[] dist;
    return 1;
}

int diameter(Graph& graph)
{
    int Graph_diam = 0, V_dist = 0, temp_diam = 0;
    const int V = graph.get_V();
    int* dist = new int[V];

    // checking if is it Tree Graph E=V-1 & connected  O( V+E )
    if (graph.get_E() == (V - 1)) {
        if (graph.BFS(V, &temp_diam, /*pred,*/ dist, 0)) {
            for (int j = 0; j < V; j++) {
                if (temp_diam == dist[j]) {
                    V_dist = j;
                    j = V;
                }
            }
            graph.BFS(V, &temp_diam, /*pred,*/ dist, V_dist);
            Graph_diam = temp_diam;
        }
        else {
            Graph_diam = (-1);
        }
    }
    // case for rest Graphs O( V(V+E) )
    else {
        if (graph.BFS(V, &temp_diam, /*pred,*/ dist, 0)) {
            for (int j = 0; j < V; j++) {
                if (Graph_diam <= dist[j])
                    Graph_diam = dist[j];
            }
            for (int i = 1; i < V; i++) {
                graph.BFS(V, &temp_diam, /*pred,*/ dist, i);
                for (int j = 0; j < V; j++) {
                    if (Graph_diam <= dist[j])
                        Graph_diam = dist[j];
                }
            }
        }
        else {
            Graph_diam = (-1);
        }
    }
    delete[]dist;
    return Graph_diam;

}

// checking if there is lonely Vertices  O( V )
int Is_Isolated(Graph& graph) {
    for (int i = 0; i < graph.get_V(); i++) {
        //cout << "Vetex " << i << " ---> ";
        if (graph.Edge[i].empty()) {
            //cout << "Empty";
            return 1;
        }
    }
    return 0;
}

void Report_to_csv(vector<float> prob, int vrt, int graphs, int choise_1, int choise_2, int choise_3,
    vector<float> diam_prob, vector<float> conn_prob, vector<float> isul_prob) {


    string file_name = "Graph Test CSV ";
    ofstream myFile;

    // Write to CSV by dividing for cases
    if (choise_1 == 2) {
        file_name.append("According requirements of exercise.csv");
        myFile.open(file_name, std::ios::app);

        myFile << "\n" << "," << "," << "," << "," << ","
            << "Test Results For " << graphs << " with " << vrt << " vertex"
            << "\n" << "Attributes 1 & 3 probability" << ",";
        for (int i = 0; i < PROB_ARR_SIZE; i++)
            myFile << prob[i] << ",";
        myFile << "\n" << "Connactivity Probability 1 & 3" << ",";
        for (int i = 0; i < PROB_ARR_SIZE; i++)
            myFile << conn_prob[i] << ",";
        myFile << "\n" << "Isulated Probability 1 & 3" << ",";
        for (int i = 0; i < PROB_ARR_SIZE; i++)
            myFile << isul_prob[i] << ",";
        myFile << "\n" << "\n" << "Attributes 2 probability" << ",";
        for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
            myFile << prob[i] << ",";
        myFile << "\n" << "diameter Probability 2" << ",";
        for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
            myFile << diam_prob[i] << ",";
        myFile << "\n";
    }
    else {
        if (choise_1) {
            file_name.append("For 3 attributs.csv");
            myFile.open(file_name, std::ios::app);

            myFile << "\n" << "," << "," << "," << "," << ","
                << "Test Results For " << graphs << " with " << vrt << " vertex"
                << "\n" << "Attributes 1 & 3 probability" << ",";
            for (int i = 0; i < PROB_ARR_SIZE; i++)
                myFile << prob[i] << ",";
            myFile << "\n" << "diameter Probability 1 & 3" << ",";
            for (int i = 0; i < PROB_ARR_SIZE; i++)
                myFile << diam_prob[i] << ",";
            myFile << "\n" << "Connactivity Probability 1 & 3" << ",";
            for (int i = 0; i < PROB_ARR_SIZE; i++)
                myFile << conn_prob[i] << ",";
            myFile << "\n" << "Isulated Probability 1 & 3" << ",";
            for (int i = 0; i < PROB_ARR_SIZE; i++)
                myFile << isul_prob[i] << ",";
            myFile << "\n" << "\n" << "Attributes 2 probability" << ",";
            for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                myFile << prob[i] << ",";
            myFile << "\n" << "diameter Probability 2" << ",";
            for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                myFile << diam_prob[i] << ",";
            myFile << "\n" << "Connactivity Probability 2" << ",";
            for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                myFile << conn_prob[i] << ",";
            myFile << "\n" << "Isulated Probability 2" << ",";
            for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                myFile << isul_prob[i] << ",";
            myFile << "\n";
        }
        else {
            if (choise_2 == 1) {
                switch (choise_3)
                {
                case 1: {
                    file_name.append("For Diameter Attribut.csv");
                    myFile.open(file_name, std::ios::app);

                    myFile << "\n" << "," << "," << "," << "," << ","
                        << "Test Results For " << graphs << " with " << vrt << " vertex"
                        << "\n" << "Attributes 1 & 3 probability" << ",";
                    for (int i = 0; i < PROB_ARR_SIZE; i++)
                        myFile << prob[i] << ",";
                    myFile << "\n" << "diameter Probability 1 & 3" << ",";
                    for (int i = 0; i < PROB_ARR_SIZE; i++)
                        myFile << diam_prob[i] << ",";
                    myFile << "\n" << "\n" << "Attributes 2 probability" << ",";
                    for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                        myFile << prob[i] << ",";
                    myFile << "\n" << "diameter Probability 2" << ",";
                    for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                        myFile << diam_prob[i] << ",";
                    myFile << "\n";
                }break;
                case 2: {
                    file_name.append("For Connactivity attribut.csv");
                    myFile.open(file_name, std::ios::app);

                    myFile << "\n" << "," << "," << "," << "," << ","
                        << "Test Results For " << graphs << " with " << vrt << " vertex"
                        << "\n" << "Attributes 1 & 3 probability" << ",";
                    for (int i = 0; i < PROB_ARR_SIZE; i++)
                        myFile << prob[i] << ",";
                    myFile << "\n" << "Connactivity Probability 1 & 3" << ",";
                    for (int i = 0; i < PROB_ARR_SIZE; i++)
                        myFile << conn_prob[i] << ",";
                    myFile << "\n" << "\n" << "Attributes 2 probability" << ",";
                    for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                        myFile << prob[i] << ",";
                    myFile << "\n" << "Connactivity Probability 2" << ",";
                    for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                        myFile << conn_prob[i] << ",";
                    myFile << "\n";
                }break;
                case 3: {
                    file_name.append("For Isuleted attribut.csv");
                    myFile.open(file_name, std::ios::app);

                    myFile << "\n" << "," << "," << "," << "," << ","
                        << "Test Results For " << graphs << " with " << vrt << " vertex" << "\n" << "Attributes 1 & 3 probability" << ",";
                    for (int i = 0; i < PROB_ARR_SIZE; i++)
                        myFile << prob[i] << ",";
                    myFile << "\n" << "Isulated Probability 1 & 3" << ",";
                    for (int i = 0; i < PROB_ARR_SIZE; i++)
                        myFile << isul_prob[i] << ",";
                    myFile << "\n" << "\n" << "Attributes 2 probability" << ",";
                    for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                        myFile << prob[i] << ",";
                    myFile << "\n" << "Isulated Probability 2" << ",";
                    for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                        myFile << isul_prob[i] << ",";
                    myFile << "\n";
                }break;
                default:
                    break;
                }
            }
            else {
                switch (choise_3)
                {
                case 1: {
                    file_name.append("For Connactivity & Diameter attribut.csv");
                    myFile.open(file_name, std::ios::app);

                    myFile << "\n" << "," << "," << "," << "," << ","
                        << "Test Results For " << graphs << " with " << vrt << " vertex"
                        << "\n" << "Attributes 1 & 3 probability" << ",";
                    for (int i = 0; i < PROB_ARR_SIZE; i++)
                        myFile << prob[i] << ",";
                    myFile << "\n" << "diameter Probability 1 & 3" << ",";
                    for (int i = 0; i < PROB_ARR_SIZE; i++)
                        myFile << diam_prob[i] << ",";
                    myFile << "\n" << "Connactivity Probability 1 & 3" << ",";
                    for (int i = 0; i < PROB_ARR_SIZE; i++)
                        myFile << conn_prob[i] << ",";
                    myFile << "\n" << "\n" << "Attributes 2 probability" << ",";
                    for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                        myFile << prob[i] << ",";
                    myFile << "\n" << "diameter Probability 2" << ",";
                    for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                        myFile << diam_prob[i] << ",";
                    myFile << "\n" << "Connactivity Probability 2" << ",";
                    for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                        myFile << conn_prob[i] << ",";
                    myFile << "\n";
                }break;
                case 2: {
                    file_name.append("For Connactivity & Isulation attribut.csv");
                    myFile.open(file_name, std::ios::app);

                    myFile << "\n" << "," << "," << "," << "," << ","
                        << "Test Results For " << graphs << " with " << vrt << " vertex"
                        << "\n" << "Attributes 1 & 3 probability" << ",";
                    for (int i = 0; i < PROB_ARR_SIZE; i++)
                        myFile << prob[i] << ",";
                    myFile << "\n" << "Connactivity Probability 1 & 3" << ",";
                    for (int i = 0; i < PROB_ARR_SIZE; i++)
                        myFile << conn_prob[i] << ",";
                    myFile << "\n" << "Isulated Probability 1 & 3" << ",";
                    for (int i = 0; i < PROB_ARR_SIZE; i++)
                        myFile << isul_prob[i] << ",";
                    myFile << "\n" << "\n" << "Attributes 2 probability" << ",";
                    for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                        myFile << prob[i] << ",";
                    myFile << "\n" << "Connactivity Probability 2" << ",";
                    for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                        myFile << conn_prob[i] << ",";
                    myFile << "\n" << "Isulated Probability 2" << ",";
                    for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                        myFile << isul_prob[i] << ",";
                    myFile << "\n";
                }break;
                case 3: {
                    file_name.append("For Isulated & Diameter attributs.csv");
                    myFile.open(file_name, std::ios::app);

                    myFile << "\n" << "," << "," << "," << "," << ","
                        << "Test Results For " << graphs << " with " << vrt << " vertex"
                        << "\n" << "Attributes 1 & 3 probability" << ",";
                    for (int i = 0; i < PROB_ARR_SIZE; i++)
                        myFile << prob[i] << ",";
                    myFile << "\n" << "diameter Probability 1 & 3" << ",";
                    for (int i = 0; i < PROB_ARR_SIZE; i++)
                        myFile << diam_prob[i] << ",";
                    myFile << "\n" << "Isulated Probability 1 & 3" << ",";
                    for (int i = 0; i < PROB_ARR_SIZE; i++)
                        myFile << isul_prob[i] << ",";
                    myFile << "\n" << "\n" << "Attributes 2 probability" << ",";
                    for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                        myFile << prob[i] << ",";
                    myFile << "\n" << "diameter Probability 2" << ",";
                    for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                        myFile << diam_prob[i] << ",";
                    myFile << "\n" << "Isulated Probability 2" << ",";
                    for (int i = PROB_ARR_SIZE; i < PROB_ARR_SIZE * 2; i++)
                        myFile << isul_prob[i] << ",";
                    myFile << "\n";
                }break;
                default:
                    break;
                }
            }
        }
    }
    myFile.close();
}

// random function between range ( Min, Max )
float Random(float MIN, float MAX) {
    float random;
    random = MIN + (rand() / static_cast<float>(RAND_MAX / (MAX - MIN)));
    return random;
}

//  Menu implementation for the user
int Menu_of_Project(float* prob, int* Vrt, int* num_of_graphs, int* choice_1, int* choice_2, int* choice_3) {
    *choice_2 = 1;
    *choice_3 = 1;
    bool flag = true, flag2 = true;
    int simulation_flag;

    cout << "                                    "
        << "    Random Graph Program by Vladi Kruk" << endl << endl
        << "                                  "
        << "------------------------------------------------" << endl << endl;

    flag = true, flag2 = true;
    while (flag2 && flag) {
        *num_of_graphs = -1;
        *Vrt = -1;
        *prob = -1;

        cout << "                                    "
            << "--------------------------------------------" << endl
            << "                                      "
            << "1) For Simulation  --->  PRESS - 1" << endl
            << "                                      "
            << "2) For Single test --->  PRESS - 0" << endl
            << "                                      "
            << "3) To EXIT         --->  PRESS any key" << endl
            << "                                    "
            << "--------------------------------------------" << endl
            << "Your choice is : ";
        cin >> *choice_2;
        simulation_flag = *choice_2;
        if (*choice_2 != 1 && *choice_2 != 0) {
            flag2 = 0;
        }
        else {
            if (*choice_2)
                while (*num_of_graphs <= 0) {
                    cout << "Please enter a number of Graphs for the test : ";
                    cin >> *num_of_graphs;
                    if (*num_of_graphs <= 0)
                        cout << "The mount of Graphs wasn't correct !!!" << endl;
                }
            else
                *num_of_graphs = 1;

            while (*Vrt <= 0) {
                cout << "Please enter a number of Vertecis for those Graphs : ";
                cin >> *Vrt;
                if (*Vrt <= 0)
                    cout << "The number of Vertecis wasn't correct !!!" << endl;
            }
            while ((*prob < 0 || *prob > 1) && !simulation_flag) {
                cout << "Please enter a Probability for those Graphs : ";
                cin >> *prob;
                if (*prob < 0 || *prob > 1)
                    cout << "The Probability wasn't correct !!!" << endl;
            }
            cout << endl;

            cout << "                                  "
                << "------------------------------------------------" << endl
                << "                                  "
                << "The Project can test 3 attribute for those graphs" << endl
                << "                                    "
                << "( DIAMETER / CONNOCTIVIYI / ISOLATED VERTEX )" << endl
                << "                                  "
                << "------------------------------------------------" << endl << endl;
            while (flag) {
                cout << "Do you want to test partial OR all attributes, on this Test " << endl
                    << "For Partial                        ---> Press 0 " << endl
                    << "For All                            ---> Press 1 " << endl
                    << "According requirements of exercise ---> Press 2 " << endl;
                cin >> *choice_1;
                if ((*choice_1) == 1 || (*choice_1) == 0 || (*choice_1) == 2) {
                    flag = 0;
                    break;
                }
            }
            if (*choice_1 == 0) {
                while (flag2) {
                    cout << "How many attribute are you interested ( 1 or 2 attributes ) : ";
                    cin >> *choice_2;
                    cout << endl;
                    switch (*choice_2)
                    {
                    case 1: {
                        while (flag2) {
                            cout << "                                  "
                                << "------------------------------------------------" << endl
                                << "                                      "
                                << "1) For DIAMETER        ---> Press - 1" << endl
                                << "                                      "
                                << "2) For CONNOCTIVITY    ---> Press - 2" << endl
                                << "                                      "
                                << "3) For ISOLATED VERTEX ---> Press - 3" << endl
                                << "                                  "
                                << "------------------------------------------------" << endl
                                << "Your choice is : ";
                            cin >> *choice_3;
                            if ((*choice_3) >= 1 && (*choice_3) <= 3)
                                flag2 = false;
                        }
                        break;
                    }
                    case 2: {
                        while (flag2) {
                            cout << "                                  "
                                << "------------------------------------------------" << endl
                                << "                                "
                                << "1) For DIAMETER and CONNOCTIVITY          ---> Press - 1" << endl
                                << "                                "
                                << "2) For CONNOCTIVITY and ISOLATED VERTEX   ---> Press - 2" << endl
                                << "                                "
                                << "3) For DIAMETER and ISOLATED VERTEX       ---> Press - 3" << endl
                                << "                                  "
                                << "------------------------------------------------" << endl
                                << "Your choice is : ";
                            cin >> *choice_3;
                            if ((*choice_3) >= 1 && (*choice_3) <= 3)
                                flag2 = false;
                        }
                        break;
                    }
                    default:
                        break;
                    }
                }
            }
        }
    }
    return simulation_flag;
}


