#include <bits/stdc++.h>
#define MAX_SIZE 100010
#define ull unsigned long long int
#define ll long long int

using namespace std;

int arr[MAX_SIZE];
struct SegmentTreeNode{
    ///Define statistics
};

class SegmentTree{
    int arrsize;
    SegmentTreeNode* tree;
    int* lazyProp;

    int getTreeSize(int n){
        int i = 1;
        for(;i<n;i<<=1);

        return i<<1;
    }

    void buildTree(int ind, int ss, int se){
        if(ss==se){
            ///Initialize tree leaves.
            return;
        }

        int mid = (ss+se)>>1;
        int leftChild = ind<<1;
        int rightChild = leftChild + 1;

        buildTree(leftChild,ss,mid);
        buildTree(rightChild,mid+1,se);
        mergeNodes(tree[leftChild],tree[rightChild],tree[ind]);
    }

    void mergeNodes(SegmentTreeNode &l, SegmentTreeNode &r, SegmentTreeNode &par){
        ///Perform required Operations.
    }

    public:
    SegmentTree(int n){
        this->arrsize = n;
        int size = getTreeSize(n)
        tree = new SegmentTreeNode[size];
        lazyProp = new int[size];
        memset(lazyProp,0,sizeof(lazyProp));
        buildTree(1,0,n-1);
    }

    ~SegmentTree(){
        delete []tree;
        delete []lazyProp;
    }

    void ptUpdate(int treeind, int ss, int se, int ind, int val){
        if(ss == se){
            tree[treeind] = ///Perform leaf update
            return;
        }

        int mid = (ss+se)>>1;
        int leftChild = ind<<1;
        int rightChild = leftChild + 1;

        if(ind>mid){
            ptUpdate(rightChild,mid+1,se,ind,val);
        }
        else{
            ptUpdate(leftChild,ss,mid,ind,val);
        }

        mergeNodes(tree[leftChild],tree[rightChild],tree[ind]);
    }

    void rangeUpdate(int treeind, int ss, int se, int lo, int hi, int val){
        if(ss>hi||se<lo||ss>se){
            return;
        }

        int mid = (ss+se)>>1;
        int leftChild = ind<<1;
        int rightChild = leftChild + 1;

        if(lazyProp[treeind]){
            tree[treeind]+=lazyProp[treeind];
            if(ss!=se){
                lazyProp[leftChild]+=lazyProp[treeind];
                lazyProp[rightChild]+=lazyProp[treeind];
            }
            lazyProp[treeind] = 0;
        }

        if(ss>=lo && se<=hi){
            tree[treeind]+=val;
            if(ss!=se){
                lazyProp[leftChild]+=val;
                lazyProp[rightChild]+=val;
            }

            return;
        }

        rangeUpdate(leftChild,ss,mid,lo,hi,val);
        rangeUpdate(rightChild,mid+1,se,lo,hi,val);
        mergeNodes(tree[leftChild],tree[rightChild],tree[ind]);
    }

    int query(int treeind, int ss, int se, int qs,int qe){
        if(ss>se||ss>qe||se<qs){
            ///Return appropriate value
            return ///value
        }

        int mid = (ss+se)>>1;
        int leftChild = ind<<1;
        int rightChild = leftChild + 1;

        if(lazyProp[treeind]){
            tree[treeind]+=lazyProp[treeind];
            if(ss!=se){
                lazyProp[leftChild]+=lazyProp[treeind];
                lazyProp[rightChild]+=lazyProp[treeind];
            }
            lazyProp[treeind] = 0;
        }

        if(ss>=qs && se<=qe){
            return tree[treeind];
        }

        int res;
        int leftVal = query(leftChild,ss,mid,qs,qe);
        int rightVal = query(rightChild,mid+1,se,qs,qe);
        ///merge the result from left and right child
        res = ///merge
    }
};

int main()
{
    ///Take Input
    return 0;
}
