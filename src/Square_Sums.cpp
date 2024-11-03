#include <vector>
#include <set>
#include <math.h>
#include <iostream>

void printNeighbours(std::vector<std::set<int>> neighbours)
{
  std::vector<std::set<int>>::iterator it;
  int index = 1;
  for(auto it = neighbours.begin();it!=neighbours.end();it++)
  {
    std::set<int>::iterator it_in;
    std::cout << index << " : [";
    for(auto it_in = (*it).begin();it_in!=(*it).end();it_in++)
    {
      std::cout << *it_in << ",";
    }
    std::cout << "]\n";
    index++;
  }
}

void square_sums_row(int n)
{
  std::vector<std::set<int>> neighbours;
  for(int i = 1;i<=n;i++)
  {   
      int root = floor(sqrt(i));
      int square = pow(root+1,2);
      int first_neighbour = square-i;
      std::set<int> aux;
      for(int j = first_neighbour; j <= n; j += 2*root + 1)
      {
        if(i != j)
          aux.emplace(j);
        root++;
      }
      neighbours.push_back(aux);
  }
  printNeighbours(neighbours);
}

int main()
{
  int input = 100;
  square_sums_row(input);
  return 0;
}


