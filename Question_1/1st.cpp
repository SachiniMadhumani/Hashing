#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#define t_size 10001

using namespace std;

struct hashslot{
    int data;
    hashslot *next;
};


hashslot* hashtable[t_size]={NULL};
int k=0;
int hashfunc(int data){
    int index=data%t_size;
    return index;
}
void insert(int data){
    int index=hashfunc(data);
    // cout<<k++;
    hashslot * newdata=new hashslot();
    newdata->data=data;
    newdata->next=NULL;

    if(hashtable[index]==NULL){
        hashtable[index]=newdata;
    }else{
        hashslot * traveler=hashtable[index];
        while (traveler->next){
            
            traveler=traveler->next;
        }
        traveler->next=newdata;
        
    }

}
bool search(int data){
    
    int index=hashfunc(data);
    if(hashtable[index]==NULL){
        return false;
    }else{
        hashslot *traveler=hashtable[index];
        while (traveler){
            if(traveler->data==data){
                return true;
            }
            traveler=traveler->next;
        }
        
    }
    return false;

}

bool findTargetSum(int sum){
    int i=1;
    int sumhalf=sum/2+1;
    while(i<sumhalf){
       
        if(search(i)){
             int remainder=sum-i;
             if(search(remainder)){
                 return true;
             }
        }
        i++;
    }
    return false;
}

int main(){

    ifstream file("HashInt.txt");
    string str;
    while (getline(file, str)) {
        int val=atoi(str.c_str());
        
        insert(val);
    }
    int targetsums[9]={231552, 234756, 596873, 648219, 726312, 981237,988331, 1277361, 1283379};
    char output[9];
    for(int i=0;i<9;i++){
        if(findTargetSum(targetsums[i])){
            output[i]='1';
        }else{
            output[i]='0';
        }
    } 
    for(int i=0;i<9;i++){
        cout<<output[i];
    }

}
