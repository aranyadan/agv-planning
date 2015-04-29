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
void dfsimplement(int current_id)
{
    if( a[current_id].visit==0)
    {
        a[current_id].visit=1;
        cout<<a[current_id].id<<",";
        for(int i=0;i<a[current_id].link_count;i++)
        {
            dfsimplement((a[current_id].ptr[i])->id-1);
        }
    }
    return;
}
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
    /*for(int i=0;i<num_of_node;i++)                 //for checking the graph
    { 
        cout<<a[i].id<<"\n";
        cout<<"connected to-\n";
        for(int j=0;j<a[i].link_count;j++)
        {
            cout<<(a[i].ptr[j])->id<<" ";
        }
        cout<<"\n";
    }*/

    cout<<"Enter starting index:\n";
    int start_index; 
    cin >> start_index; cin.ignore();    
    cout<<"dfs-\n";
    dfsimplement(start_index-1);
    cout<<"\n";    
}