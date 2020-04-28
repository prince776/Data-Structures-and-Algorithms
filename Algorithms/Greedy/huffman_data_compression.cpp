// Implements Huffman encoding and decoding algorithms for data compression.

#include <bits/stdc++.h>
using namespace std;



struct Node
{
	char data;
	int freq;
	Node* left, *right;
	Node(char data, int freq) :
		data(data),
		freq(freq),
		left(0),
		right(0)
	{
		// Nothing to do here.
	}
};

struct compare
{
	bool operator()(Node* l, Node* r)
	{
		return (l->freq > r->freq);
	}
};

map<char, string> codes;
map<char, int> freq;
priority_queue<Node*, vector<Node*>, compare> minHeap;

void printCodes(Node* root, string str) 
{ 
  
    if (!root) 
        return; 
  
    if (root->data != '$') 
        cout << root->data << ": " << str << "\n"; 
  
    printCodes(root->left, str + "0"); 
    printCodes(root->right, str + "1"); 
}

void storeCodes(Node* root, string str)
{
	if (!root)
		return;
	if (root->data != '$')
		codes[root->data] = str;
	storeCodes(root->left, str + "0");
	storeCodes(root->right, str + "1");
}

// generate prefix codes
void HuffmanCodes()
{
	Node* left, *right, *top;

	for (auto& it : freq)
		minHeap.push(new Node(it.first, it.second));

	while (minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new Node('$', left->freq + right->freq);
		top->left = left;
		top->right = right;

		minHeap.push(top);
	}
	storeCodes(minHeap.top(), "");
}

void calcFreq(string str)
{
	freq.clear();
	for (int i = 0; i < str.size(); i++)
		freq[str[i]]++;
}

string decode(Node* root, string s)
{
	string ans = "";
	Node* curr = root;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
			curr = curr->left;
		if (s[i] == '1')
			curr = curr->right;
		if (!curr->left && !curr->right)
		{
			ans += curr->data;
			curr = root;
		}
	}
	return ans + "\0";
}

int main()
{
    string input = "teststringdata";
    string encodedString, decodedString;

    calcFreq(input);
    HuffmanCodes();

    for (auto i: input)
    	encodedString += codes[i];
    cout << "Ecoded String: "<< encodedString << endl;
    cout << "Encoding size: " << encodedString.size() / 8 <<" bytes" << endl;
    decodedString = decode(minHeap.top(), encodedString);
    cout << "Decoded String: " << decodedString << endl;
	return 0;
}
