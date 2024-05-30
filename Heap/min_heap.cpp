# include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int i, int end){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int small = i;
    if(left<end){
        if(v[small] > v[left]){
            small = left;
        }
    }
    if(right < end){
        if(v[small] > v[right]){
            small = right;
        }
    }
    if(small != i){
        swap(v[i], v[small]);
        heapify(v, small, end);
    }
}

void buildHeap(vector<int> &v){
    int size = v.size();
    int start=(size-2)/2;
    for(int i=start; i>=0; i--){
        heapify(v, i, size);
    }
}

int extractMin(vector<int> &v){
    int r = v[0];
    int size = v.size();
    v[0]= v[size-1];
    v.pop_back();
    heapify(v, 0, size);
    return r;
}

void increaseKey(vector<int> &v, int i, int val){
    v[i]+=val;
    heapify(v, i, v.size());
}

void DecreaseKey(vector<int> &v, int i, int val){
    v[i]-=val;
    for(int j=i; j>0; j = (j-1)/2){
        if(v[j] < v[(j-1)/2]){
            swap(v[j], v[(j-1)/2]);
        }else{
            break;
        }
    }
}

void insertElement(vector<int> &v, int key){
    v.push_back(key);
    for(int j=v.size()-1; j>0; j = (j-1)/2){
        if(v[j] < v[(j-1)/2]){
            swap(v[j], v[(j-1)/2]);
        }else{
            break;
        }
    }

}

void deleteElement(vector<int> &v, int key, int i){
    if(v[i] > key){
        return;
    }
    int size = v.size();
    if(v[i] == key){
        //cout<<"hey"<<endl;
        swap(v[i], v[size-1]);
        v.pop_back();
        heapify(v, i, v.size());
        return;
    }
    int left = 2*i+1;
    int right = 2*i+2;
    if(left < size){
        deleteElement(v, key, left);
    }
    if(right < size){
        deleteElement(v, key, right);
    }

}

void heapSort(vector<int> &v){
    int size = v.size();
    vector<int> sorted;
    for(int i=0; i<size; i++){
        int min = extractMin(v);
        sorted.push_back(min);
    }
    for(int i=0; i<size; i++){
        v.push_back(sorted[i]);
    }
}

void printheap(vector<int> &v){
    int size = v.size();
    for(int i=0; i<size; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> minheap;
    int n;
    cin>>n;
    for(int i=0; i< n; i++){
        int val;
        cin>>val;
        minheap.push_back(val);
    }

    buildHeap(minheap);

    printheap(minheap);

    return 0;
}