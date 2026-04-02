#include <iostream>
#include <vector>
#include <climits>

class SegmentTree {
private:
    std::vector<int> tree;
    int n;

    void build(int Node , int l , int r , const std::vector<int> &arr) {
        if (l == r) {
            tree[Node] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;
        build(Node*2+1 , l , mid , arr);
        build(Node*2+2 , mid+1 , r ,arr);

        tree[Node] = std::min(tree[Node*2+1] , tree[Node*2+2]);
    }

    void update(int Node , int l , int r , int idx , int val) {
        if (l == r) {
            tree[Node] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if (idx <=11 mid) update(Node * 2 + 1 , l , mid , idx , val);
        else           update(Node * 2 + 2 , mid+1 , r , idx , val);

        tree[Node] = std::min(tree[Node*2+1] , tree[Node*2+2]);
    }

    int query(int Node , int l , int r , int start , int end) {
        if (r < start || l > end) return INT_MAX;
        else if (start <= l && r <= end) return tree[Node];

        int mid = l + (r - l) / 2;
        int val1 = query(Node*2+1 , l , mid , start , end);
        int val2 = query(Node*2+2,mid+1,r,start,end);

        return tree[Node] = std::min(val1 , val2);
    }
public:
    SegmentTree(int N , const std::vector<int>& v) {
        tree.resize(N*4);
        n = N;
        build(0,0,n-1,v);
    }

    void Update(int idx , int val) {
        update(0 , 0 , n-1 , idx , val);
    }

    int Query(int start , int end) {
        return query(0 , 0 , n-1 , start , end);
    }
};

int main() {
    std::vector<int> v = {1,0,9,6,3,1,4,5,2,12,61,72,42,91,14};
    SegmentTree sgt(v.size() , v);

    std::cout << sgt.Query(2,5) << '\n';
    sgt.Update(5,600);
    std::cout << sgt.Query(4,10);

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <climits>

// class SegmentTree {
//     std::vector<int> v;
//     int n;

//     void build(int Node , int l , int r , const std::vector<int> &arr) {
//         if (l == r) {
//             v[Node] = arr[l];
//             return;
//         }
        
//         int mid = l + (r - l) / 2;
//         build(Node*2+1 , l , mid , arr);
//         build(Node*2+2 , mid+1 , r , arr);
        
//         v[Node] = std::min(v[Node*2+1] , v[Node*2+2]);
//     }
    
//     void update(int Node , int l , int r , int idx , int val) {
//         if (l == r) {
//             v[Node] = val;
//             return;
//         }
        
//         int mid = l + (r - l) / 2;
//         if (idx <= mid) update(Node*2+1 , l , mid , idx , val);
//         else            update(Node*2+2,mid+1,r,idx,val);
        
//         v[Node] = std::min(v[Node*2+1] , v[Node*2+2]);
//     }
    
//     int query(int Node , int l , int r , int start , int end) {
//         if (l > end || r < start) return INT_MAX;
//         else if (start <= l && r <= end) return v[Node];
        
//         int mid = l + (r - l) / 2;
//         int res = INT_MAX;
//         res = std::min(res , query(Node*2+1 , l , mid , start , end));
//         res = std::min(res , query(Node*2+2 , mid+1 , r,start , end));
        
//         return res;
//     }
// public:
//     SegmentTree(int N , const std::vector<int> &arr) {
//         n = N;
//         v.resize(4*n);
//         build(0 , 0 , n-1 , arr);
//     }

//     void Update(int idx , int val) {
//         update(0,0,n-1,idx,val);
//     }

//     int Query(int l , int r) {
//         return query(0 , 0 , n-1 , l , r);
//     }
// };

// int main() {
//     std::vector<int> v = {1,0,9,6,3,1,4,5,2,12,61,72,42,91,14};
//     SegmentTree sgt(v.size() , v);

//     std::cout << sgt.Query(2,5) << '\n';
//     sgt.Update(5,600);
//     std::cout << sgt.Query(4,10);
// }