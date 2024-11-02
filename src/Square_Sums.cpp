#include <vector>
#include <set>
#include <math.h>
#include <iostream>

void square_sums_row(int n)
{
  std::vector<std::set<int>> neighbours;
  for(int i = 1;i<=n;i++)
  {   
      int root = floor(sqrt(i))+1;
      int square = pow(root,2);
      int first_neighbour = square-i;
      std::set<int> aux;
      for(int j = first_neighbour;j< n;j += 2*root+1)
      {
        aux.emplace(j);
        root++;
      }
      neighbours.push_back(aux);
  }
  std::vector<std::set<int>>::iterator it;
  for(auto it = neighbours.begin();it!=neighbours.end();it++)
  {
    std::set<int>::iterator it_in;
    for(auto it_in = (*it).begin();it_in!=(*it).end();it_in++)
    {
      std::cout << *it_in << ",";
    }
    std::cout << "\n";
  }
}

int main()
{
  int input = 10;
  square_sums_row(input);
  return 0;
}


