#include "dht.h"



Node::Node(int guid)
    {
        guid_m=guid;
        known_m=GNULL;
        predecessor_m=this;//(Node*)&guid_m;
        successor_m=nullptr;
    }



void Node::info()
    {
                            cout<<"✺ Node: "<<guid_m<<endl;
        if(predecessor_m)   cout<<"  Predecessor: "<<predecessor_m->guid_m<<endl;   else cout<<"  Predecessor: null"<<endl;
                            cout<<"  Known: "<<known_m<<endl;
        if(successor_m)     cout<<"  Successor: "<<successor_m->guid_m<<endl;       else cout<<"  Successor: null"<<endl;
                            cout<<"\t"<<endl;
    }



void Node::join(Node& bootstrap)
    {
      cout<<guid_m<<" joined::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"<<endl;
      known_m=bootstrap.guid_m;

      if(between(bootstrap.guid_m, guid_m,bootstrap.successor_m->guid_m) )
      {
          successor_m=bootstrap.successor_m;
      }

      else
      {
          successor_m= bootstrap.lookup_successor(guid_m, bootstrap.successor_m);
      }
    }



Node* Node::lookup_successor(int guid, Node *successor)
    {
        if( between(successor->guid_m , guid, successor->successor_m->guid_m)  )
        {
            return lookup_successor(guid, successor->successor_m);
        }

        else{ return successor; }
    }



void Node::stabilize()
    {
        cout<<guid_m<<" stabilized::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"<<endl;

        if( between(successor_m->predecessor_m->guid_m, guid_m, successor_m->guid_m ) || successor_m->predecessor_m->guid_m==guid_m )
        {
            // no actualiza sucesor

        }

        else {successor_m=successor_m->predecessor_m;}

        //notifica al sucesor independientemente
        successor_m->rectify(&guid_m);
    }


void Node::rectify(int* guid)
    {
        //ping predecessor_m

        cout<<guid_m<<" rectified::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"<<endl;

        if( between(predecessor_m->guid_m, *guid, guid_m))
        {
            predecessor_m=(Node*)guid;
        }
    }


bool between(int n1, int n2, int n3)
    {
        if (n1<n3)   return (n1<n2 && n2<n3);
        else         return (n1<n2 || n2<n3);
    }


void initialize(Node& n1, Node& n2)
    {
        n1.successor_m=&n2;
        n1.predecessor_m=&n2;

        n2.successor_m=&n1;
        n2.predecessor_m=&n1;

        cout<<"Chord initialized  <"<<n1.guid_m<<","<<n2.guid_m<<">:::::::::::::::::::::::::::::::::::::::::::::\n"<<endl;

    }
