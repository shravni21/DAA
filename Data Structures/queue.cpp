/**
 * Queue Applications
 * 1. Single resource and multiple consumers
 * 2. Syncronisation b/w slow and fast devices
 * 3. In OS(Semaphores, FCFS scheduling, Spooling, buffers for devices like keyboard)
 * 4. In computer networks(Router, Switch and mail queue)
 * 5. Variations: Deque, Priority queue, Doubly ended priority queue
 */
#include <bits/stdc++.h>
using namespace std;

/*

				   ___           !!!         |               ___          _   _        .      .
  `  _ ,  '       .|||.       `  _ _  '      |.===.        .'_#_`.       '\-//`     .  .:::.
 -  (o)o)  -      (o o)      -  (OXO)  -     {}o o{}       |[o o]|        (o o)        :(o o):  .
-ooO'(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-

*/

#define us unordered_set
#define mod 1000000007
#define sp ' '
#define nline "\n"
#define mp make_pair
#define us unordered_set
#define bpc __builtin_popcount

#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)

#define all(v) v.begin(), v.end()
#define lb(a, X) lower_bound(all(a), X) - a.begin()
#define ub(a, X) upper_bound(all(a), X) - a.begin()
#define rfor(i, a, b) for (ll i = a; i >= b; i--)
#define sfor(i, a, b) for (ll i = a; i < b; i++)
#define rot(a, x)          \
	for (auto &a : x)      \
	{                      \
		cout << it << " "; \
	}
#define max_ele(a) *max_element(a.begin(), a.end())
#define min_ele(a) *min_element(a.begin(), a.end())
#define take_vector(a) \
	for (auto &x : a)  \
		cin >> x;
#define take_array(a, n)        \
	for (int i = 0; i < n; i++) \
	{                           \
		cin >> a[i];            \
	}
#define ssort(v) sort(v.begin(), v.end())
#define rsort(v) sort(v.begin(), v.end(), greater<>())

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

class Queue
{
public:
	int front, rear, size;
	unsigned capacity;
	int *array;
};

Queue *createQueue(unsigned capacity)
{
	Queue *queue = new Queue();
	queue->capacity = capacity;
	queue->front = queue->size = 0;

	queue->rear = capacity - 1;
	queue->array = new int[(
		queue->capacity * sizeof(int))];
	return queue;
}

int isFull(Queue *queue)
{
	return (queue->size == queue->capacity);
}

int isEmpty(Queue *queue)
{
	return (queue->size == 0);
}

void enqueue(Queue *queue, int item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	cout << item << " enqueued to queue\n";
}

int dequeue(Queue *queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

int front(Queue *queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

int rear(Queue *queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Queue *queue = createQueue(1000);

	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);

	cout << dequeue(queue)
		 << " dequeued from queue\n";

	cout << "Front item is "
		 << front(queue) << endl;
	cout << "Rear item is "
		 << rear(queue) << endl;

	return 0;
}
