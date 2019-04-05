#include <iostream>
#include "dht.h"

using namespace std;


int main()
{

Node n1(12);
Node n2(10);



cout<<between(7,8,1)<<endl;


initialize(n1,n2);

n1.info();
n2.info();

n1.stabilize();
n1.info();

n2.stabilize();
n2.info();


Node n3(5);
n3.join(n1);
n3.info();

n3.stabilize();
n3.info();
n2.info();

n2.stabilize();
n2.info();
n1.info();

n1.stabilize();
n1.info();
n3.info();


n2.stabilize();
n3.stabilize();
n1.stabilize();

n1.info();
n2.info();
n3.info();

Node n4(3);
n4.join(n2);
n4.info();

n4.stabilize();
n2.stabilize();
n3.stabilize();
n4.stabilize();
n1.stabilize();
n4.stabilize();
n4.stabilize();
n2.stabilize();
n3.stabilize();
n1.stabilize();


Node n5(21);
n5.join(n4);
n5.stabilize();


n4.stabilize();
n2.stabilize();
n3.stabilize();
n4.stabilize();
n1.stabilize();
n4.stabilize();
n4.stabilize();
n5.stabilize();
n2.stabilize();
n3.stabilize();
n1.stabilize();

n1.info();
n2.info();
n3.info();
n4.info();
n5.info();




}


