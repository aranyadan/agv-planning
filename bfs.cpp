#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class nodes{
public:
    int id;
    int visit;
    nodes **ptr;
    int link_count;
    nodes()
    {
        id=0;
        visit=0;
    }
    nodes(int i, int n)
    {
        id=i;
        ptr=new nodes*[n];
        link_count=0;
        visit=0;
    }

 };
nodes *a;
int main()
{
    int num_of_node; // the total number of nodes in the level
    int no_of_links; // the number of links
    cout<<"enter no of nodes:\n";
    cin >> num_of_node; cin.ignore();
    cout<<"enter no of links:\n";
    cin >> no_of_links; cin.ignore();
    a=new nodes [num_of_node];
    cout<<"enter "<<no_of_links<<" connections one after the other with a space in between (links are named 1 to n, not 0 to n-1):\n";    
    for(int i=0;i<num_of_node;i++)
    {
        a[i]= nodes(i+1,num_of_node);
    }

    for (int i = 0; i < no_of_links; i++) {
        int connector1; // N1 and N2 defines a link between these nodes
        int connector2;
        cin >> connector1 >> connector2; cin.ignore();
        a[connector1-1].ptr[((a[connector1-1].link_count)++)]=&a[connector2-1];
        a[connector2-1].ptr[((a[connector2-1].link_count)++)]=&a[connector1-1];                  //turn on for back connectivity

    }
    /*for(int i=0;i<num_of_node;i++)                 //use for checking the graph
    { 
        cout<<a[i].id<<"\n";
        cout<<"connected to-\n";
        for(int j=0;j<a[i].link_count;j++)
        {
            cout<<(a[i].ptr[j])->id<<" ";
        }
        cout<<"\n";
    }*/
    queue<int> temp_queue_for_bfs;

    cout<<"Enter starting index:\n";
    int start_index; // The index of the node on which you start
    cin >> start_index; cin.ignore();    

    temp_queue_for_bfs.push(start_index-1);
    //bfs starts here
    cout<<"bfs-\n";
    while(!temp_queue_for_bfs.empty())
    {
        int temp=temp_queue_for_bfs.front();
        temp_queue_for_bfs.pop();
        if(a[temp].visit==0)
        {
            a[temp].visit=1;
            for(int i=0;i<a[temp].link_count; i++)
            {
                temp_queue_for_bfs.push((a[temp].ptr[i])->id-1);
            }
            cout<<temp+1<<",";
        }
        
    }
    cout<<"\n";    
}