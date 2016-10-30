#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
	public:
		int info;
		class Node *left;
		class Node *right;
};

class BinTree {
		public:
			Node *ROOT;
		BinTree() {
			ROOT = NULL;
		}

		Node *createTree() {
			Node *TMP, *CUR, *PRE;
			cout<<"Enter elements of the Binary Tree\n-1 to stop\n";
			while(1) {
				if((TMP = new Node()) == NULL) {
					cout<<"\nInsufficient Memory!\n";
				}else {
					cout<<"Enter an Element : ";
					cin>>(TMP->info);
					if(TMP->info == -1) {
						break;
					}
					if(ROOT == NULL) {
						ROOT = TMP;
					}else {
						CUR = ROOT;
						while(CUR != NULL) {
							PRE = CUR;
							if(TMP->info < CUR->info) {
								CUR = CUR->left;
							}else {
								CUR = CUR->right;
							}
						}
						if(PRE->info > TMP->info) {
							PRE->left = TMP;
						}else {
							PRE->right = TMP;
						}
						CUR = TMP;
					}
				}
			}
			return ROOT;
		}

		void intrav(Node *n) {
			if(n->left != NULL) {
				intrav(n->left);
			}

			cout<<n->info<<"\t";

			if(n->right != NULL) {
				intrav(n->right);
			}
		}

		void pretrav(Node *n) {
			cout<<n->info<<"\t";

			if(n->left != NULL) {
				pretrav(n->left);
			}

			if(n->right != NULL) {
				pretrav(n->right);
			}
		}

		void posttrav(Node *n) {
			if(n->left != NULL) {
				posttrav(n->left);
			}

			if(n->right != NULL) {
				posttrav(n->right);
			}

			cout<<n->info<<"\t";
		}
};

int main() {
	BinTree bt;
	bt.ROOT = bt.createTree();
	cout<<"\nIn Traversal Mode :\n";
	bt.intrav(bt.ROOT);

	cout<<"\nPre Traversal Mode :\n";
	bt.pretrav(bt.ROOT);

	cout<<"\nPost Traversal Mode :\n";
	bt.posttrav(bt.ROOT);
	return 0;
}
