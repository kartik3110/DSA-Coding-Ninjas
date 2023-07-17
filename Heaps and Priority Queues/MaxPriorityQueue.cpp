#include <iostream>
using namespace std;
#include <vector>
#include <climits>

class PriorityQueue
{
    // Declare the data members here
    vector<int> pq;

public:
    PriorityQueue()
    {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element)
    {
        // Implement the insert() function here
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        int parentIndex = (childIndex - 1) / 2;
        while (childIndex > 0)
        {
            parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] > pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp; // swapped
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int getMax()
    {
        // Implement the getMax() function here
        if (isEmpty())
        {
            return INT_MIN;
        }
        return pq[0];
    }

    int removeMax()
    {
        // Implement the removeMax() function here
        if (isEmpty())
        {
            return INT_MIN;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        // logic
        int parentIndex = 0;
        int maxIndex;
        int lci = 2 * parentIndex + 1;
        int rci = 2 * parentIndex + 2;
        while (lci < pq.size())
        {
            maxIndex = parentIndex;
            if (pq[lci] > pq[maxIndex])
            {
                maxIndex = lci;
            }
            if (rci < pq.size() && pq[rci] > pq[maxIndex])
            {
                maxIndex = rci;
            }
            if (maxIndex == parentIndex)
                break;

            int temp = pq[parentIndex];
            pq[parentIndex] = pq[maxIndex];
            pq[maxIndex] = temp;
            parentIndex = maxIndex;
            lci = 2 * parentIndex + 1;
            int rci = 2 * parentIndex + 2;
        }
        return ans;
    }

    int getSize()
    {
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here
        return pq.size() == 0;
    }
};

int main()
{
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1)
    {
        switch (choice)
        {
        case 1: // insert
            int element;
            cin >> element;
            cout << "added " << element << endl;
            pq.insert(element);
            break;
        case 2: // getMax
            cout << "max is " << pq.getMax() << "\n";
            break;
        case 3: // removeMax
            cout << "removed " << pq.removeMax() << "\n";
            break;
        case 4: // size
            cout << "size is " << pq.getSize() << "\n";
            break;
        case 5: // isEmpty
            cout << (pq.isEmpty() ? "true\n" : "false\n");

        default:
            return 0;
        }

        cin >> choice;
    }
}