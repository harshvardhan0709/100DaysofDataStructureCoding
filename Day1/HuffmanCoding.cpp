/*

1. Create a leaf node for each unique character and build a min heap of all leaf nodes (Min Heap is used as a priority queue. The value of frequency field is used to compare two nodes in min heap. Initially, the least frequent character is at root)

2. Extract two nodes with the minimum frequency from the min heap.

3. Create a new internal node with a frequency equal to the sum of the two nodes frequencies. Make the first extracted node as its left child and the other extracted node as its right child. Add this node to the min heap.

4. Repeat steps#2 and #3 until the heap contains only one node. The remaining node is the root node and the tree is complete.

*/


#include<iostream>
#include<queue>
using namespace std;

struct MinHeapNode{
    char data;
    unsigned freq;
    MinHeapNode *left,*right;
    MinHeapNode(char data,unsigned freq){
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare{
    bool operator()(MinHeapNode *l,MinHeapNode *r){
        return (l -> freq > r->freq);
    }
};

void printCodes(struct MinHeapNode *root,string str) {
    if(!root)
        return;
    if(root->data != '$')
        cout<<root->data<<": "<<str<<"\n";
    printCodes(root->left,str + "0");
    printCodes(root->right,str+"1");
}

void HuffmanCodes(char data[],int freq[],int size){
    struct MinHeapNode *left,*right,*top;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>,compare> minHeap;

    for(int i=0; i< size;i++){
        minHeap.push(new MinHeapNode(data[i],freq[i]));
    }

    while(minHeap.size() != 1){
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with 
        // frequency equal to the sum of the 
        // two nodes frequencies. Make the 
        // two extracted node as left and right children 
        // of this new node. Add this node 
        // to the min heap '$' is a special value 
        // for internal nodes, not used 
        top = new MinHeapNode('$', left-> freq + right -> freq);
        top -> left = left;
        top -> right = right;
        minHeap.push(top);

    }
    printCodes(minHeap.top(),"");
}

int main(){
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 5, 9, 12, 13, 16, 45 }; 
  
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    HuffmanCodes(arr, freq, size); 
  
    return 0; 
}