#ifndef MYHEAP
#define HEAP

extern void swap(int* a, int* b);

class Heap {
private:
	int* heap;
	int cnt;
	int size;
public:
	Heap(int size);
	void push(int data);
	void pop();
	int top();
	int getSize();
	int getCount();
	bool isEmpty();
	bool isFull();
	~Heap();
};

Heap::Heap(int size) {
	this->heap = new int[size];
	this->size = size;
	this->cnt = 1;
}

void Heap::push(int data) { // bottom-up ����� push 
	int insertAt = this->cnt; // �� ���� �ε����� �����Ѵ�. 
	this->heap[insertAt] = data; // �� ���� ���Ҹ� �ִ´�. 
	while (insertAt > 1) { // �ε����� 1���� Ŭ ������ 
		if (this->heap[insertAt / 2] > this->heap[insertAt]) { // �ε����� ���� �ε����� �θ��� ������ �۴ٸ� 
			swap(&this->heap[insertAt / 2], &this->heap[insertAt]); // �ٲ۴�. 
			insertAt /= 2; // �ε����� �θ�� �̵��Ѵ�. 
		}
		else // ���� �ʴٸ� ���̻� �ݺ����� �ʴ´�. 
			break;
	}
	this->cnt++;
}

void Heap::pop() { // top-down ����� pop 
	int insertAt = 1; // ������ ���� ���� ������ �ε��� 
	this->heap[insertAt] = this->heap[this->cnt - 1]; // ���� �ؿ� �ִ� ���Ҹ� �� ���� ����ִ´�. 

	int to;

	while (insertAt * 2 < this->cnt) { // ���� ũ�⸦ �ѱ��� ���� ������ 
		to = insertAt * 2; // �ڽ� �߿��� 

		if ((insertAt * 2 + 1 < this->cnt) && (this->heap[insertAt * 2] > this->heap[insertAt * 2 + 1])) { // ���� ������ �ڽĵ� �����ϰ� �� ���� ���� �ڽĺ��� �۴ٸ� 
			to = insertAt * 2 + 1; // ������ �ڽĵ� ����. 
		}

		if (this->heap[insertAt] > this->heap[to]) { // �� �������� ������ �ڽ��� �� ���� ������ �۴ٸ� 
			swap(&this->heap[insertAt], &this->heap[to]); // �ٲ۴�. 
			insertAt = to; // �� �ڽ��� �̵��Ѵ�. 
		}
		else
			break;
	}
	this->cnt--;
}

int Heap::top() { // �ּ� ���� ���ǿ� ���� �� ���� ���Ҹ� ��ȯ�Ѵ�. 
	return this->heap[1];
}

int Heap::getSize() {
	return this->size;
}

int Heap::getCount() {
	return this->cnt;
}

bool Heap::isEmpty() {
	return this->cnt <= 1;
}

bool Heap::isFull() {
	return this->cnt > this->size;
}

Heap::~Heap() {
	delete[] this->heap;
}

#endif
