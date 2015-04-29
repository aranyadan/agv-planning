#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class nodes{
public:
    int id;
    //int ext;
    int visit;
    nodes **ptr;
    int c;
    nodes()
    {
        id=0;
        //ext=0;
        //ptr=new nodes*[x];
        visit=0;
    }
    nodes(int i, int n)
    {
        id=i;
        //ext=w;
        ptr=new nodes*[n];
        c=0;
        visit=0;
    }

 };

int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    //int E; // the number of exit gateways
    cout<<"enter no of nodes:\n";
    cin >> N; cin.ignore();
    cout<<"enter no of links:\n";
    cin >> L; cin.ignore();
    nodes *a=new nodes [N];
    cout<<"enter "<<L<<" connections one after the other with a space in between (links are named 1 to n, not 0 to n-1):\n";    
    for(int i=0;i<N;i++)
    {
        a[i]= nodes(i+1,N);
    }

    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        a[N1-1].ptr[((a[N1-1].c)++)]=&a[N2-1];
        a[N2-1].ptr[((a[N2-1].c)++)]=&a[N1-1];                  //turn on for back connectivity

    }
    for(int i=0;i<N;i++)                 //for checking the graph
    { 
        cout<<a[i].id<<"\n";
        cout<<"connected to-\n";
        for(int j=0;j<a[i].c;j++)
        {
            cout<<(a[i].ptr[j])->id<<" ";
        }
        cout<<"\n";
        //cout<<"\n exit="<<a[i].ext<<"\n";
    }
    queue<int> q;

    cout<<"Enter starting index:\n";
    int SI; // The index of the node on which the Skynet agent is positioned this turn (starting)
    cin >> SI; cin.ignore();    

    q.push(SI-1);
    //bfs starts here
    cout<<"bfs-\n";
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        if(a[temp].visit==0)
        {
            a[temp].visit=1;
            for(int i=0;i<a[temp].c; i++)
            {
                q.push((a[temp].ptr[i])->id-1);
            }
            cout<<temp+1<<",";
        }
        
    }
    cout<<"\n";


    // game loop
    
}