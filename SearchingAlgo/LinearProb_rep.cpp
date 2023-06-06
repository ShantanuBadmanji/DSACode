#include <iostream>
#define MAX 61
using namespace std;

class LProb_rep
{
#define CHAIN_END -1
#define EMPTY 1
#define OCCU_SYN 2
#define OCCU_ASYN 3
#define DELETED 4

private:
    int size;
    int val[MAX];
    int chain[MAX];
    int states[MAX];

public:
    LProb_rep(int _n);
    int hashFunc(int data);
    void displayPrimeArea();
    void insertData(int data);
    void resoluteCollision(int data, int homeAddr);
    int nextEmpty(int homeAddr);
    int searchData(int key);
    int deleteData(int key);
};
LProb_rep ::LProb_rep(int _size)
{
    size = _size;
    for (int i = 0; i < size; i++)
    {
        chain[i] = CHAIN_END;
        states[i] = EMPTY;
    }
}
void LProb_rep::displayPrimeArea()
{
    cout << "i  v  s  c:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i << ". " << val[i] << " " << states[i] << " " << chain[i] << endl;
    }
}
int LProb_rep::hashFunc(int data)
{
    return data % size;
}
int LProb_rep::nextEmpty(int homeAddr)
{
    int addr = (homeAddr + 1) % size;
    while (addr != homeAddr && states[addr] != EMPTY)
    {
        addr = (addr + 1) % size;
    }

    return (addr == homeAddr) ? -1 : addr;
}

void LProb_rep::resoluteCollision(int data, int homeAddr)
{
    // ARE THEY SYNONYM
    if (states[homeAddr] == OCCU_SYN)
    {
        // GO TO END OF CHAIN
        int addr = homeAddr;
        while (chain[addr] != CHAIN_END)
        {
            addr = chain[addr];
        }

        //  FIND THE NEXT EMPTY ELEMENT FOR DATA.
        int next = nextEmpty(addr);
        if (next == -1)
        {
            cout << "The Prime Area is full." << endl;
        }
        else
        {
            val[next] = data;
            states[next] = OCCU_ASYN;
            chain[next] = CHAIN_END;
            chain[addr] = next;
        }
    }
    // ARE THEY NON - SYNONYM
    else if (states[homeAddr] == OCCU_ASYN)
    {
        //  FIND THE NEXT EMPTY ELEMENT FOR THE ASYN DATA AT HOMEADDR
        int next = nextEmpty(homeAddr);
        if (next == -1)
        {
            cout << "The Prime Area is full." << endl;
            return;
        }
        val[next] = val[homeAddr];
        states[next] = OCCU_ASYN;
        chain[next] = (chain[homeAddr] != CHAIN_END) ? chain[homeAddr] : CHAIN_END;
        //  FIND THE SYN-PREDECESSOR OF THIS ENTRY
        int predecessor = val[homeAddr] % size;
        while (chain[predecessor] != homeAddr)
        {
            predecessor = chain[predecessor];
        }
        chain[predecessor] = next;

        //  ASSIGN DATA TO HOME ADDR
        val[homeAddr] = data;
        states[homeAddr] = OCCU_SYN;
        chain[homeAddr] = CHAIN_END;
    }
    else
    {
        cout << "Some fault in hash table." << endl;
    }
}
void LProb_rep::insertData(int data)
{
    int homeAddr = hashFunc(data);
    if (states[homeAddr] == EMPTY)
    {
        val[homeAddr] = data;
        states[homeAddr] = OCCU_SYN;
        chain[homeAddr] = CHAIN_END;
    }
    else if (states[homeAddr] == DELETED)
    {
        //  FIND THE HOME ADDR OF THE DELETED ENTRY
        int predecessor = hashFunc(val[homeAddr]);

        if (predecessor != homeAddr) // THIS MEANS DELETED ENTRY WAS ASYNONYM SO CHANGE  THE CHAIN OF PREDECESSOR AND SET NEW ENTRYS CHAIN AS CHAIN END.
        {
            while (chain[predecessor] != homeAddr) //&& predecessor!=CHAIN_END)
            {
                predecessor = chain[predecessor];
            }
            chain[predecessor] = chain[homeAddr];
            // ADDING NEW ENTRY
            val[homeAddr] = data;
            states[homeAddr] = OCCU_SYN;
            chain[homeAddr] = CHAIN_END;
        }
        else // THIS MEANS IT WAS A SYNONYM SO DON'T CHANGE THE CHAIN OF CURRENT NODE. BCOZ AND CHAIN MAY BE PRESENT.
        {
            val[homeAddr] = data;
            states[homeAddr] = OCCU_SYN;
        }
    }
    else
    {
        resoluteCollision(data, homeAddr);
    }
}

int LProb_rep::searchData(int key)
{
    int homeAddr = hashFunc(key);
    cout << "key: " << key << " homeaddr: " << homeAddr << " val[homaddr]: " << val[homeAddr] << endl;
    if (states[homeAddr] == OCCU_SYN || states[homeAddr] == DELETED)
    {
        if (states[homeAddr] == OCCU_SYN && key == val[homeAddr])
        {
            return homeAddr;
        }
        // FIND THE DATA IN CHAIN
        int addr = chain[homeAddr];
        while (addr != CHAIN_END)
        {
            if (key == val[addr] && states[addr]!=DELETED)
            {
                return addr;
            }
            addr = chain[addr];
        }
        cout << "element not found in chain" << endl;
        return -1;
    }
    else
        return -1;
}
int LProb_rep::deleteData(int key)
{
    int addr = searchData(key);
    if (addr != -1)
    {
        states[addr] = DELETED;
    }
    return addr;
}

int main(int argc, char const *argv[])
{
    int arr[] = {12, 15, 18, 28, 24, 23, 76, 37, 87, 98, 65};
    int n = sizeof(arr) / sizeof(arr[0]);
    LProb_rep lp(n);
    for (int i = 0; i < n; i++)
    {
        lp.insertData(arr[i]);
    }
    cout << lp.searchData(87) << endl;
    cout << lp.searchData(98) << endl;
    lp.insertData(13);

    lp.displayPrimeArea();
    return 0;
}
