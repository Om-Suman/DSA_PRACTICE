#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    map<string,int> marksMap;
    marksMap["Om"] = 96;
    marksMap["Rohan"]=69;
    marksMap.insert({{"Arun",75},{"roshan",23}});
    map<string,int>:: iterator iter;
    for (iter=marksMap.begin();iter!=marksMap.end();iter++) {
        if (iter->second < 50) 
        iter = marksMap.erase(iter);
        cout<<(*iter).first<<" "<<(*iter).second<<endl;
    }
    return 0;
}