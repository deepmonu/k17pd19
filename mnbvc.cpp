#include <iostream> 
#include <string.h> 
#include <vector> 

#define P 5 

#define R 3 
int resources[R] = { 10, 5, 7 };  

using namespace std; 
bool check_available(int process_id, int allocated[][R], 
                  int max_need[][R], int need[][R], int available[])  ;


   

void safe_sequence(vector<int> safe_seq,int max_need[][R], int allocated[][R],  
                   int need[][R], int available[],bool marked[] ) 
{ 
  
    for (int i = 0; i < P; i++) { 
  
      
        if (!marked[i] && check_available(i, allocated, max_need, need, available)) { 
  
          
            marked[i] = true; 
  
           
            for (int j = 0; j < R; j++) 
                available[j] += allocated[i][j]; 
  
            safe_seq.push_back(i); 
            
            safe_sequence( safe_seq,  max_need,allocated, need, available,marked); 
            
            safe_seq.pop_back(); 
  
        } 
    } 
  
  
    if (safe_seq.size() == P) { 
        int i=0;
		while(i<P) { 
  
            cout << "P" << safe_seq[i] + 1; 
            if (i != (P - 1)) 
                cout << "--> "; 
                i++;
        } 
  
        cout << endl; 
    } 
} 
  
 
int main() 
{ 
  
     
    int allocated[P][R] = { { 0, 1, 0 }, 
                            { 2, 0, 0 }, 
                            { 3, 0, 2 }, 
                            { 2, 1, 1 },
							{ 0, 0, 2 },
							  }; 
  
    
    int max_need[P][R] = { { 7, 5, 3 }, 
                      { 3, 2, 2 }, 
                      { 9, 0, 2 }, 
                      { 2, 2, 2 },
					  { 4, 3, 3 },
					    }; 
  
    // Initial total resources 
//    int resources[R] = { 10, 5, 7 }; 
  
    // available vector of size R 
    int available[R]; 
  
    for (int i = 0; i < R; i++) { 
  
        int sum = 0; 
        for (int j = 0; j < P; j++) 
            sum += allocated[j][i]; 
  
        available[i] = resources[i] - sum; 
    } 
  
    // safe vector for displaying a safe-sequence 
    vector<int> safe_seq; 
  
     
    bool marked[P]; 
 
    int need[P][R]; 
    for (int i = 0; i < P; i++) 
        for (int j = 0; j < R; j++) 
            need[i][j] = max_need[i][j] - allocated[i][j]; 
  
    cout << "Safe sequences are given Below: \n" << endl; 
    safe_sequence( safe_seq,  max_need,allocated, need, available,marked); 
  
   
    int k=0;
    for(int j=0;j<R;j++)
            	if(available[j]==resources[j])
            		k++;
    if(k==3)
    	cout<<"System in safe state\n";
    else
        cout<<"System is not in safe state\n";
    return 0; 
}

bool check_available(int process_id, int allocated[][R], 
                  int max_need[][R], int need[][R], int available[]) 
{ 
  
    bool flag = true; 
  
    
    for (int i = 0; i < R; i++) { 
  
        if (need[process_id][i] > available[i]) 
            flag = false; 
    } 
  
    return flag; 
} 
