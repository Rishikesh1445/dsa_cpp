#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

void pairnotes()
{
    pair<int, int> p = {1, 2};
    cout << p.first << " " << p.second;

    pair<int, pair<int, int>> pp = {1, {2, 3}};
    cout << pp.first << " " << pp.second.second << " " << pp.second.first;

    pair<int, int> arr[] = {{1, 2}, {3, 4}};
    cout << arr[1].first;
}

void vectornotes()
{
    // vector is a container whose size is dynamic in nature. Stores similar to array.

    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);

    // {1,2}
    // emplace back is faster than push back.

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    v.emplace_back(1, 2);

    // Note the syntax different.

    vector<int> v1(5, 100);
    vector<int> v2(5);

    // tho size is mentioned, can be expanded,
    //  in first one , 5 times 100 is stored, in second some garbage value.

    vector<int> v3(v2);
    // makes a copy of v2

    vector<int>::iterator it = v.begin();
    // vector can be accessed like array, this is another method by assinging pointer.

    cout << *(it);

    vector<int>::iterator it = v.end();
    // memory location after the last element
    // it-- gives last element

    vector<int>::reverse_iterator it = v.rend();
    // reverse end - it points the memory b4 first element.
    // invert the array and find v.end

    vector<int>::reverse_iterator it = v.rbegin();
    // reverse beginning - it points the last element.
    //  when it++ it goes (last element -1) coz reversed.
    // invert the array and find v.begin

    cout << v[0] << v.at(0);
    // v[i] when i is out of range, unexpected behaviour, crashes, Bound checking not done.
    // v.at(0) does Bound checking, slower than v[0]
    cout << v.back();
    // last element

    // PRINTING VECTOR
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it);
    }

    for (auto it : v)
    {
        cout << it;
    }

    // DELETING
    v.erase(v.begin() + 1);
    v.erase(v.begin(), v.begin() + 4);
    // erases till v.begin() + 3
    v.pop_back();
    v.clear();

    // INSERT
    vector<int> vec(2, 100);
    v.insert(v.begin(), 300);
    //{300,100,100}
    v.insert(v.begin(), 2, 10);
    //{300, 10,10 , 100,100}

    vector<int> copy(2, 50);
    v.insert(v.begin(), copy.begin(), copy.end());

    cout << v.size();

    // Swapping vector elements.
    v1.swap(v2);

    cout << v.empty();
    // returns Boolean.
}

void listnotes()
{
    list<int> ls;

    ls.push_back(2);
    ls.emplace_back(3);

    ls.push_front(1);
    ls.emplace_front(0);
    // front operations only in list, not in vector.
    // insert to be used in vector which takes more time than push front.
    // reason is list is double linked list and vector is single linked list.

    // remaining all functions - begin, end .... swap, same for list too.
}

void dequenotes()
{
    deque<int> dq;

    dq.pop_back();
    dq.pop_front();
    // remaining all functions are same.
}

void stacknotes()
{
    // indexing not allowed
    // LIFO - last in first out
    // imagine a beaker and pouring elements, first occupies at bottom then above that, above that.

    stack<int> st;
    st.push(1);
    st.push(2);
    st.emplace(5);

    st.top();
    // returns last element pushed

    st.pop();
    // removes last element

    st.size();
    st.empty();

    stack<int> st1, st2;
    st1.swap(st2);

    // ALL OPERATIONS HAPPEN IN O(1)
}

void queuenotes()
{
    // FIFO - first one first out

    queue<int> q;
    q.push(1);
    q.emplace(2);
    q.back();  // prints 2
    q.front(); // prints 1
    q.pop();   // deletes 1

    // others functions similar to stack
}

void priorityqueue()
{
    priority_queue<int> pq; // max heap

    pq.push(5); //{5}
    pq.push(2); //{5,2}
    pq.push(8); //{8,5,2}

    pq.top(); // prints 8

    pq.pop(); // removes 8

    // INVERSE PRIORITY QUEUE - [minimum heap]

    priority_queue<int, vector<int>, greater<int>> mh;
    mh.push(5); //{5}
    mh.push(2); //{2,5}
    mh.push(8); //{2,5,8}

    mh.top(); // prints 2

    // TIME COMPLEXITY
    // push - log n
    // top - O(1)
    // pop - log n

    // Remember: Not a linear structure, Tree like structure.
}

void setnotes()
{
    // sorted
    // unique
    // everything takes lograthimic time

    set<int> st;

    st.insert(1);
    st.emplace(3);
    st.insert(3);
    // nothing added
    st.insert(2);

    // 2 added in b/w 1 and 3
    // Remember: Not a linear structure, Tree like structure.

    auto it = st.find(3);
    // returns an iterator of element '3'

    auto it = st.find(6);
    // returns an interator after last element

    st.erase(5);
    // erases element '5' ; takes lograthmnic time
    auto it1 = st.find(2);
    auto it2 = st.find(5);
    st.erase(it1);
    // takes constant time
    st.erase(it1, it2);
    // erases from it1 to it2-1

    int cnt = st.count(1);
    // as it is unique, either 0 or 1 will be the output.

    auto it = st.lower_bound(2);
    // returns iterator of value >= than value specified
    auto it = st.upper_bound(2);
    // returns iterator of value > than value specified
}

void multisetnotes()
{
    // only sorted
    // No unique

    multiset<int> ms;

    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    //{1,1,1}

    ms.erase(1);
    // erases all 1

    int cnt = ms.count(1);

    ms.erase(ms.find(1));
    // erases first occurences of 1
    // ms.erase(ms.find(1), ms.find(1)+2);
    ms.erase(ms.find(1), next(ms.find(1), 2));
}

void usetnotes()
{
    // unique
    // no sorting
    // when elements are inserted, it inserts in random order
    // all operatios is almost O(1)
    // no lower bound or upper bound
    // sometimes O(N) is the worst case it can possilbly go

    unordered_set<int> uset;
}

void mapnotes()
{
    // key - value
    // value can repeat , key should be unique
    // key can be any data structure
    // key is sorted

    map<int, int> mpp;

    mpp[1] = 2; // {{1,2}}
    mpp[3] = 2; // {{1,2} , {3,2}}
    mpp[2] = 3; // {{1,2}, {2,3}, {3,2}}

    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl;
    }

    cout << mpp[1];
    // returns value of pair having key as 1

    cout << mpp[5];
    // returns null

    auto it = mpp.find(3);
    // returns an iterator of the (key , value) pair, in this it -> second gives value
    cout << (it)->second;

    auto it = mpp.find(5);
    // if the given key not found, points to memory after the last element i.e map.end()

    auto it = mpp.lower_bound(2);
    auto it = mpp.upper_bound(2);
    // it operates on keys
}

void multimapnotes()
{
    // duplicate keys stored
}

void umapnotes()
{
    // unique keys
    // no sorting, complete random

    // map works in logarathimic of time, umap works in O(1). Worst case O(N).
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;
    if (p1.first > p2.first)
        return true;
    else
        false;
}

void algorithms()
{

    int arr[] = {1};
    vector<int> v;
    // Sorting Arrays and Vectors
    sort(arr, arr + 5);
    sort(v.begin(), v.end());
    sort(arr, arr + 5, greater<int>()); // descending order
    // most often the comparision to be done is customised like below one
    pair<int, int> ar[] = {{1, 2}, {2, 1}, {4, 1}};
    // going to sort wrt to second element, if same, then wrt to first element in descending order
    sort(ar, ar + 4, comp);

    int num = 7;
    int cnt = __builtin_popcount(num);
    // 7 -> 111 ; return number of 1 ; cnt = 3

    long long num2 = 97893697875;
    int cnt = __builtin_popcountll(num2);
    // add ll

    string s = "123";
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    // prints all permutations possible from given, final one is null and loop breaks
    // to print all permutation, sort and then pass.

    int maxi = *max_element(arr, arr + 5);
}
