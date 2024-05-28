

#include <iostream>

void InitialScreen();
void Print(int array[], int end, int start,int NUM_SIZE);
void enqueue(int array[], int end);

int main()
{
	const int NUM_SIZE{ 10 };
	int processing{};
	int array[NUM_SIZE]{};
	int end{ 0 };
	int start{ 0 };

	InitialScreen();
	while (1)
	{
		std::cin >> processing;
		if (processing == 1)
		{
			if ((end + 1) % NUM_SIZE != start)
			{
				end = (end+1) % NUM_SIZE;
				enqueue(array, end);
				Print(array, end, start,NUM_SIZE);
				
			}
			else
			{
				Print(array, end, start,NUM_SIZE);
				std::cout << "배열이 꽉 찼습니다. 2 dequeue 해주세요" << std::endl;
			}
			
		}
		else if (processing == 2) //dequeue
		{
			if (start == end)
			{
				Print(array, end, start, NUM_SIZE);
				std::cout << "배열이 비어 있습니다. 1 enquque 해주세요" << std::endl;
			}
			else
			{
				start = (start + 1) % NUM_SIZE;
				Print(array, end, start, NUM_SIZE);
			}
		}
	
	}
}
	void InitialScreen()
	{
		std::cout << "--------- " << "QUEUE" << " ---------" << std::endl;
		std::cout << " 1. Enqueue, 2. Dequeue " << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	void Print(int array[], int end,int start, int size)
	{
		std::cout << "--------- " << "QUEUE" << " ---------" << std::endl;

			for (int i = start; i != end; i = (i+1)%size)
			{
				std::cout << array[(i+1)%size] << " ";
			}
			std::cout << std::endl;
		
		std::cout << "------------------------" << std::endl;
	}

	void enqueue(int array[], int end)
	{
		int input{};
		std::cout << " Input Enqueue number :";
		std::cin >> input;

		array[end] = input;
	}

