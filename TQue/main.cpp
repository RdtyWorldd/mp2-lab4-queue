#include <iostream>
#include <random>
#include "TQueue.h"

#define P 0.5
#define Q 0.5

using namespace std;

int main()
{
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<> rdis(0, 1);
  
  TQueue<int> queue(15);

  int countFull = 0, countEmpty = 0, countPush = 0, countPop = 0;
  for (int i = 0; i < 1000; i++) 
  {
	double p = rdis(gen);
	double q = rdis(gen);
	
	if (p < P) 
	{
	  if (!queue.isFull()) 
	  {
		queue.push(i);
		countPush++;
	  }
	  else 
		countFull++;
	}

	if (q < Q) 
	{
	  if (!queue.isEmpty()) 
	  {
		queue.pop();
		countPop++;
	  }
	  else
		countEmpty++;
	}
  }
  cout << "Push: " << countPush << '\n'
	<< "Push in full queue: " << countFull << '\n'
	<< "Pop: " << countPop << '\n'
	<< "Pop from empty queue: " << countEmpty << endl;
}