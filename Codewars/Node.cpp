//Can you get the loop ?

#include <vector>
using namespace std;
int getLoopSize(Node* startNode)
{
  vector<Node*> temp;
  int count = 0; 
  while(1){
    temp.push_back(startNode);
    startNode = startNode->getNext();
    for(auto i = temp.begin(); i != temp.end(); i++){
      if(*i == startNode){
        while(i != temp.end()){
          count++;
          i++;
        }
        return count;
        break;
      }
    }
  }
}
