#ifndef DHT_H_INCLUDED
#define DHT_H_INCLUDED

#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

#define BOOTSTRAP_NODE 1
#define GNULL -1


using namespace std;

class Node
{

    public:

    int guid_m;
    int known_m;
    Node* predecessor_m;
    Node* successor_m;


    public:

    /**constructor**/
    Node(int guid);

    void join(Node& bootstrap);

    void stabilize();

    void rectify(int* guid);

    void info();

    Node* lookup_successor(int guid, Node *succesor);
};

    bool between(int x, int y, int z);

    void initialize(Node& n1, Node& n2);


#endif // DHT_H_INCLUDED
