<p align="center">
  <a href="https://syalux.com" target="_blank">
    <img src="../md/favicon.ico" width="80" alt="Project Logo">
  </a>
</p>

<p align="center">
  <a href="https://github.com/Al-rimi/Algorithm-design/releases">
    <img src="https://img.shields.io/github/v/release/Al-rimi/Algorithm-design" alt="Latest Stable Version">
  </a>
  <a href="https://github.com/Al-rimi/Algorithm-design/issues">
    <img src="https://img.shields.io/github/issues/Al-rimi/Algorithm-design" alt="Open Issues">
  </a>
  <a href="https://opensource.org/licenses/MIT">
    <img src="https://img.shields.io/badge/license-MIT-blue.svg" alt="License">
  </a>
</p>

# Huffman Coding

Huffman Coding is a widely used compression algorithm that assigns variable-length codes to input characters based on their frequencies. This project demonstrates the creation of a Huffman Tree and the generation of Huffman codes for a set of characters.

## Key Features

- **Character Encoding:** Each character is assigned a binary code based on its frequency.
- **Huffman Tree:** A binary tree is built where characters with lower frequency appear higher in the tree.
- **Weighted Path Length (WPL):** The project calculates the WPL of the Huffman Tree.
- **Priority Queue:** A priority queue is used to select the nodes with the smallest weights during the tree-building process.
- **Signature Display:** The program outputs a signature graphic at the start.

## Algorithm Specification

### Input
- A set of `n` characters, each associated with a frequency or weight.

### Output
- Huffman codes for each character.
- The structure of the Huffman Tree.
- The Weighted Path Length (WPL) of the generated tree.

### Steps

1. **Initialize Nodes:**
   - Each character is stored in a node along with its frequency. These nodes are initially placed in a priority queue based on their weights.

2. **Construct Huffman Tree:**
   - The two nodes with the smallest weights are selected from the queue, combined to form a new internal node whose weight is the sum of the two selected nodes.
   - This process is repeated until only one node remains, which becomes the root of the Huffman Tree.

3. **Generate Huffman Codes:**
   - Starting from each leaf node (representing a character), trace back to the root of the tree, recording a `0` for left moves and a `1` for right moves. This forms the Huffman code for the character.

4. **Calculate WPL:**
   - The WPL is calculated by multiplying each character's weight by the length of its Huffman code, then summing the results for all characters.

### Code Walkthrough

- **CreateHTree():** Builds the Huffman Tree using a priority queue to repeatedly combine the two nodes with the smallest weights.
- **CreateHcode():** Generates the Huffman code for each character by traversing the tree from leaf to root.
- **DispHCode():** Displays the Huffman codes for all characters.
- **WPL():** Calculates and returns the Weighted Path Length of the Huffman Tree.
- **DispHTree():** Displays the structure of the Huffman Tree, including the characters, weights, and relationships between nodes.

### Example

For the input characters `a (4), b (2), c (1), d (7), e (3)`, the program outputs the following:

- **Huffman Codes:** a: 10 b: 1101 c: 1100 d: 0 e: 111

- **Huffman Tree Structure:** 
data=a, weight=4, lchild=-1, rchild=-1, parent=5 data=b, weight=2, lchild=-1, rchild=-1, parent=6 data=c, weight=1, lchild=-1, rchild=-1, parent=6 data=d, weight=7, lchild=-1, rchild=-1, parent=5 data=e, weight=3, lchild=-1, rchild=-1, parent=7


- **Weighted Path Length (WPL):** `WPL = 37`

## Screenshot

Here’s a preview of the program output:

![Program Screenshot](Screenshot.png)

## Learning Resources

- [Huffman Coding - GeeksforGeeks](https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/)  
  A detailed guide on Huffman Coding, including the algorithm's step-by-step explanation and implementation.

- [Priority Queue Data Structure - Programiz](https://www.programiz.com/dsa/priority-queue)  
  Learn about the priority queue, which is a key data structure used in Huffman Coding for selecting nodes with the smallest weights.

- [Weighted Path Length (WPL) - Educative](https://www.educative.io/answers/what-is-weighted-path-length-in-huffman-tree)  
  An explanation of Weighted Path Length (WPL) and its significance in Huffman Trees.

- [Binary Tree Basics - C++ Reference](https://cplusplus.com/doc/tutorial/trees/)  
  A good introduction to binary trees, a fundamental part of Huffman Coding.

- [Data Compression - Wikipedia](https://en.wikipedia.org/wiki/Data_compression)  
  Learn more about how Huffman Coding is applied in the broader context of data compression.


## Security Vulnerabilities

If you discover a security vulnerability, please email Abdullah Al Raimi at [abdullah@syalux.com](mailto:abdullah@syalux.com). All security vulnerabilities will be promptly addressed.

## License

This project is licensed under the [MIT license](../LICENSE).

