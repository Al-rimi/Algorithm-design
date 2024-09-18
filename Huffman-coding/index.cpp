#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>
using namespace std;

#define MAX 101  // Maximum number of nodes in the Huffman Tree

int n;  // Number of original characters

// Struct to represent a node in the Huffman Tree
struct HTreeNode
{
    char data;   // Character the node represents
    int weight;  // Frequency or weight of the character
    int parent;  // Index of the parent node
    int lchild;  // Index of the left child node
    int rchild;  // Index of the right child node
};

HTreeNode ht[MAX];            // Array to store nodes of the Huffman Tree
map<char, string> htcode;     // Map to store the Huffman codes for each character

// Struct to represent a node in the priority queue
struct NodeType
{
    int no;      // Index of the node in the Huffman Tree array
    char data;   // Character the node represents
    int weight;  // Frequency or weight of the character

    // Overloading the less-than operator for priority queue to order by weight
    bool operator<(const NodeType &s) const
    {
        return s.weight < weight;  // Nodes with smaller weights have higher priority
    }
};

// Function prototypes
void CreateHTree();         // Creates the Huffman Tree
void CreateHcode();         // Creates the Huffman codes for each character
void DispHCode();           // Displays the generated Huffman codes
void DispHTree();           // Displays the structure of the Huffman Tree
int WPL();                  // Calculates the Weighted Path Length (WPL) of the tree
void displaySignature();    // Function to display a signature graphic

int main()
{
    displaySignature();
    // Initialize the nodes with characters and their respective frequencies
    n = 5;
    ht[0].data = 'a'; ht[0].weight = 4;
    ht[1].data = 'b'; ht[1].weight = 2;
    ht[2].data = 'c'; ht[2].weight = 1;
    ht[3].data = 'd'; ht[3].weight = 7;
    ht[4].data = 'e'; ht[4].weight = 3;

    CreateHTree();  // Construct the Huffman Tree
    printf("The created Huffman tree is:\n");
    DispHTree();    // Display the Huffman Tree structure

    CreateHcode();  // Generate Huffman codes based on the tree
    printf("The resulting Huffman code is as follows:\n");
    DispHCode();    // Display the Huffman codes

    printf("WPL=%d\n", WPL());  // Calculate and display the Weighted Path Length

    return 0;
}

// Function to create the Huffman Tree
void CreateHTree()
{
    NodeType e, e1, e2;
    priority_queue<NodeType> qu;  // Priority queue to select nodes with smallest weights

    // Initialize all nodes' parent, left child, and right child to -1
    for (int k = 0; k < 2 * n - 1; k++)
        ht[k].lchild = ht[k].rchild = ht[k].parent = -1;
    
    // Push the original nodes into the priority queue
    for (int i = 0; i < n; i++)
    {
        e.no = i;
        e.data = ht[i].data;
        e.weight = ht[i].weight;
        qu.push(e);  // Add node to the priority queue
    }

    // Construct the Huffman Tree
    for (int j = n; j < 2 * n - 1; j++)
    {
        // Extract two nodes with the smallest weights
        e1 = qu.top();  qu.pop();
        e2 = qu.top();  qu.pop();

        // Create a new internal node with these two nodes as children
        ht[j].weight = e1.weight + e2.weight;
        ht[j].lchild = e1.no;
        ht[j].rchild = e2.no;
        ht[e1.no].parent = j;
        ht[e2.no].parent = j;

        // Push the new internal node into the priority queue
        e.no = j;
        e.weight = ht[j].weight;
        qu.push(e);
    }
}

// Function to generate Huffman codes for each character
void CreateHcode()
{
    string code;  // Temporary string to store the code
    code.reserve(MAX);

    // For each original character, traverse up the tree to generate its code
    for (int i = 0; i < n; i++)
    {
        code = "";
        int curno = i;  // Start with the current node
        int f = ht[curno].parent;  // Get its parent

        // Traverse up to the root, building the code
        while (f != -1)
        {
            if (ht[f].lchild == curno)
                code = '0' + code;  // Left child is represented by '0'
            else
                code = '1' + code;  // Right child is represented by '1'
            curno = f;  // Move up to the parent
            f = ht[curno].parent;  // Get the next parent
        }

        // Store the generated code in the map
        htcode[ht[i].data] = code;
    }
}

// Function to display the Huffman codes
void DispHCode()
{
    map<char, string>::iterator it;
    for (it = htcode.begin(); it != htcode.end(); it++)
        cout << "     " << it->first << ":" << it->second << endl;  // Display each character and its code
}

// Function to display the structure of the Huffman Tree
void DispHTree()
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        printf("    data=%c, weight=%d, lchild=%d, rchild=%d, parent=%d\n",
            ht[i].data == 0 ? '-' : ht[i].data, ht[i].weight, ht[i].lchild, ht[i].rchild, ht[i].parent);
    }
}

// Function to calculate the Weighted Path Length (WPL) of the Huffman Tree
int WPL()
{
    int wps = 0;
    for (int i = 0; i < n; i++)
        wps += ht[i].weight * htcode[ht[i].data].size();  // Multiply weight by code length
    return wps;
}

// Function to display a signature graphic
void displaySignature()
{
    const char *signature = R"(  
  _    _        __  __                          _____          _ _             
 | |  | |      / _|/ _|                        / ____|        | (_)            
 | |__| |_   _| |_| |_ _ __ ___   __ _ _ __   | |     ___   __| |_ _ __   __ _ 
 |  __  | | | |  _|  _| '_ ` _ \ / _` | '_ \  | |    / _ \ / _` | | '_ \ / _` |
 | |  | | |_| | | | | | | | | | | (_| | | | | | |___| (_) | (_| | | | | | (_| |
 |_|  |_|\__,_|_| |_| |_| |_| |_|\__,_|_| |_|  \_____\___/ \__,_|_|_| |_|\__, |
                                                                          __/ |
                                                                         |___/ 
)";

    std::cout 
				<< "\033[90mName: AL RAIMI ABDULLAH\033[0m\n"
				<< "\033[90mID:   202336020211\033[0m"
				<< "\033[31m" << signature << "\033[0m"
				<< std::endl; // Display the signature in the terminal
}