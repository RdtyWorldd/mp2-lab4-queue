#pragma once
#include <iostream>

template <class T>
class TQueue
{
  int memSize;
  int tail;
  int head;
  int elCount;
  T* pMem;
public:
  TQueue(int maxElcount);
  TQueue(const TQueue<T>& queue);
  TQueue<T>& operator=(const TQueue<T>& queue);
  ~TQueue();
  
  void push(T el);
  T pop();
  const T& front() const;
  const T& back() const;
  bool isFull();
  bool isEmpty();
  void clear();

  int getHead() const;
  int getTail() const;

  int getMaxElCount() const;
  int getElCount() const;

  //по содержанию
  bool operator==(const TQueue& queue) const;
  bool operator!=(const TQueue& queue) const;

  friend std::ostream& operator<<(std::ostream& out, const TQueue& queue) 
  {
	return out;
  }
  friend std::istream& operator>>(std::istream& in, TQueue& queue)
  {
	return in;
  }
};

template<class T>
inline TQueue<T>::TQueue(int maxElcount)
{
  memSize = maxElcount;
  pMem = new T[memSize];
  head = 0;
  tail = -1;
  elCount = 0;
}

template<class T>
inline TQueue<T>::TQueue(const TQueue<T>& queue)
{
  head = queue.head;
  tail = queue.tail;
  elCount = queue.elCount;
  memSize = queue.memSize;
  pMem = new T[memSize];
  
  if (elCount == 0)
	return;

  if (head <= tail)
	for (int i = head; i <= tail; i++)
	  pMem[i] = queue.pMem[i];
  else
  {
	for (int i = head; i < memSize; i++)
	  pMem[i] = queue.pMem[i];
	for (int i = 0; i <= tail; i++)
	  pMem[i] = queue.pMem[i];
  }
}

template<class T>
inline TQueue<T>& TQueue<T>::operator=(const TQueue<T>& queue)
{
  head = queue.head;
  tail = queue.tail;
  elCount = queue.elCount;
  if (memSize != queue.memSize)
  {
	memSize = queue.memSize;
	T* tmp = new T[memSize];
	delete[] pMem;
	pMem = tmp;
  }

  if (head <= tail)
	for (int i = head; i <= tail; i++)
	  pMem[i] = queue.pMem[i];
  else
  {
	for (int i = head; i < memSize; i++)
	  pMem[i] = queue.pMem[i];
	for (int i = 0; i <= tail; i++)
	  pMem[i] = queue.pMem[i];
  }
  return *this;
}

template<class T>
inline TQueue<T>::~TQueue()
{
  delete[] pMem;
}

template<class T>
inline void TQueue<T>::push(T el)
{
  if (isFull())
	throw std::exception("queue is full");

  tail++;
  tail = tail % memSize;
  pMem[tail] = el;
  elCount++;
}

template<class T>
inline T TQueue<T>::pop()
{
  if (isEmpty())
	throw std::exception("queue is empty");

  T res = pMem[head];
  head++;
  head = head % memSize;
  elCount--;
  return res;
}

template<class T>
inline const T& TQueue<T>::front() const
{
  return pMem[head];
}

template<class T>
inline const T& TQueue<T>::back() const
{
  return pMem[tail];
}

template<class T>
inline bool TQueue<T>::isFull() { return elCount == memSize; }

template<class T>
inline bool TQueue<T>::isEmpty() { return elCount == 0; }

template<class T>
inline void TQueue<T>::clear()
{
  head = 0;
  tail = -1;
  elCount = 0;
}

template<class T>
inline int TQueue<T>::getHead() const
{
  return head;
}

template<class T>
inline int TQueue<T>::getTail() const
{
  return tail;
}

template<class T>
inline int TQueue<T>::getElCount() const
{
  return elCount;
}

template<class T>
inline int TQueue<T>::getMaxElCount() const
{
  return memSize;
}

template<class T>
inline bool TQueue<T>::operator==(const TQueue& queue) const
{

  if (memSize != queue.memSize)
	return false;

  if (elCount != queue.elCount)
	return false;
  
  for (int i = 0; i < elCount; i++)
  {
	int j1 = (head + i) % memSize;
	int j2 = (queue.head + i) % memSize;
	if (pMem[j1] != queue.pMem[j2])
	  return false;
  }
  return true;
}

template<class T>
inline bool TQueue<T>::operator!=(const TQueue& queue) const
{
  return !(*this == queue);
}




