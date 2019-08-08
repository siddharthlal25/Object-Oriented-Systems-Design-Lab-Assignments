/*
    By:Siddharth Lal
    Date: 07/08/2019
*/

#include <bits/stdc++.h>

using namespace std;

/*
    Node Structure
    Arguments:
    1. x: x coordinate of the line
    2. y: y coordinate of the line
    3. height: height of the node (height of root = 0)
    4. bottom_left_x: x coordinate of the bottom left end of diagonal of the rectangular region covered
    5. bottom_left_y; y coordinate of the bottom left end of diagonal of the rectangular region covered
    6. top_right_x; x coordinate of the top right end of diagonal of the rectangular region covered
    7. top_right_y: y coordinate of the top right end of diagonal of the rectangular region covered
*/
typedef struct node
{
    int x,y,height;
    struct node* left;
    struct node* right;
    int bottom_left_x;
    int bottom_left_y;
    int top_right_x;
    int top_right_y;
}node;

int crtree = 0, qtree = 0;

/*
    Function: swapElements
    Arguments:
    1. a: pair<int,int> type element
    2. b: pair<int,int> type element

    Output:
    Swaps the the variables a & b.
*/

void swapElements(pair<int,int>& a, pair<int,int>& b)
{
    pair<int,int> temp;
    temp.first = a.first;
    temp.second = a.second;

    a.first = b.first;
    a.second = b.second;

    b.first = temp.first;
    b.second = temp.second;
}

/*
    Function: compare
    Arguments:
    1. a: pair<int,int> type element
    2. b: pair<int,int> type element
    3. type: It specifies the comparing parameter i.e.
             0 stands for compare on basis of first element of pair
             1 stands for compare on basis of second element of pair
    Output:
    Returns 1 if a > b (comparing based on type) else return 0
*/

int compare(pair<int,int>& a, pair< int,int>& b, int type)
{
    if(type == 0)
    {
        if(a.first > b.first)
            return 1;
        else
            return 0;
    }
    else
    {
        if(a.second > b.second)
            return 1;
        else
            return 0;
    }
}

/*
    Function: quickPartiotion
    Arguments:
    1. leftEnd:  left index of the vector
    2. rightEnd: right index of the vector
    3. points: vector of pair<int,int>
    4. type: 1/0 1 for second element of pair, 0 for second element of pair

    Output:
    This function selects a random index and then partitions the array array about
    that randomly selected element and then returns the true position of that randomly selected
    element in vector in between leftEnd and rightEnd
*/

int quickPartition(int leftEnd, int rightEnd, vector< pair < int,int > >& points, int type)
{
    //cout<<"left:"<<leftEnd<<" right:"<<rightEnd<<endl;
    if(leftEnd == rightEnd)
        return leftEnd;
    if(leftEnd < rightEnd)
    {
        int randomPartition = leftEnd + rand()%(rightEnd - leftEnd + 1);

        swapElements(points[leftEnd], points[randomPartition]);

        int i,j = leftEnd;
        for(i = leftEnd+1;i<=rightEnd;i++)
        {
            // case where pivot is greater than comparing point
            if(compare(points[leftEnd],points[i],type) == 1)
            {
                j++;
                swapElements(points[j],points[i]);
            }
        }
        swapElements(points[j],points[leftEnd]);

        return j;
    }
}

/*
    Function: medianFind
    Arguments:
    1. leftEnd:  left index of the vector
    2. rightEnd: right index of the vector
    3. points: vector of pair<int,int>
    4. type: 0/1 0 for median along x, 1 for median along y
    5. desired: middle index of the vector points
    6. desiredValue: It is the index of middle element of vector points

    Output:
    This is the order statistic algorithm which finds the median of numbers
    in expected linear time complexity
*/

void medianFind(int leftEnd, int rightEnd, vector< pair < int, int> >& points, int type, int desiredValue)
{
    if(leftEnd == rightEnd)
        return;
    if(leftEnd < rightEnd)
    {
        int partitionIndex = quickPartition(leftEnd,rightEnd,points,type);
        if(partitionIndex == desiredValue)
            return;
        else if(partitionIndex > desiredValue)
            return medianFind(leftEnd,partitionIndex-1,points,type,desiredValue);
        else
            return medianFind(partitionIndex+1,rightEnd,points,type,desiredValue);
    }
}

/*
    Function: buildTree
    Attributes:
    1. leftEnd:  left index of the vector
    2. rightEnd: right index of the vector
    3. points: vector of pair<int,int>
    4. height: height of the tree

    Output:
    It finally generates the kd tree
*/

node* buildTree(int leftEnd, int rightEnd, vector< pair < int,int> >& points, int height)
{
    //cout<<"left:"<<leftEnd<<" right:"<<rightEnd<<endl;
    crtree++;
    node* temp = NULL;
    if(leftEnd == rightEnd)
    {
        temp = (node*)malloc(sizeof(node));
        temp->right = NULL;
        temp->left = NULL;
        temp->x = points[leftEnd].first;
        temp->y = points[leftEnd].second;
        temp->height = height;
    }
    if(leftEnd < rightEnd)
    {
        int mid = leftEnd + (rightEnd - leftEnd)/2;
        if(height%2 == 0)
            medianFind(leftEnd,rightEnd,points,0,mid);
        else
            medianFind(leftEnd,rightEnd,points,1,mid);

        temp = (node*)malloc(sizeof(node));
        temp->height = height;
        if(height%2 == 0)
            temp->x = points[mid].first;
        else
            temp->y = points[mid].second;
        temp->left = buildTree(leftEnd,mid,points,height+1);
        temp->right = buildTree(mid + 1,rightEnd,points,height+1);
    }
    return temp;
}

//stores the solution
vector< pair < int,int > > solutionSet;

/*
    Function: isLeaf
    Attributes:
    1. root: address of a node

    Output:
    Returns true if that node is a leaf else returns false
*/
bool isLeaf(node* root)
{
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL)
    return true;
    return false;
}

/*
    Function: reportSubtree
    Attributes:
    1. root: address of a node

    Output:
    Pushes all the elements while traversing down the root
*/
void reportSubtree(node* root)
{
//cout<<"yahan aaya"<<endl;
    if(root == NULL)
        return;
    if(isLeaf(root))
    {
        solutionSet.push_back(make_pair(root->x,root->y));
    }
    else
    {
        reportSubtree(root->left);
        reportSubtree(root->right);
    }
}

/*
    Function: inRange
    Attributes:
    1. x: x coordinate of the point
    2. y: y coordinate of the point
    3. rangeQueryBottomLeft: bottom left end of diagonal of the rectangular range
    4. rangeQueryTopRight: top right end of the diagonal of the rectangular range

    Output:
    Returns true if the point (x,y) is in the query range else returns false
*/
bool inRange(int x, int y, pair<int,int> rangeQueryBottomLeft, pair<int,int> rangeQueryTopRight)
{
    if(x <= rangeQueryTopRight.first && rangeQueryBottomLeft.first <= x && y <= rangeQueryTopRight.second && rangeQueryBottomLeft.second <= y)
        return true;
    return false;
}

/*
    Function: leftSubTreeInRange
    Attributes:
    1. root: address of a node
    2. rangeQueryBottomLeft: bottom left end of diagonal of the rectangular range
    3. rangeQueryTopRight: top right end of the diagonal of the rectangular range

    Output:
    Returns true if the range of left child of the root is completely in the query
    range otherwise returns false
*/

bool leftSubTreeInRange(node* root, pair< int,int> rangeQueryBottomLeft, pair<int,int> rangeQueryTopRight)
{
    if(root == NULL || root->left == NULL) return false;
    int height = root->height;

    //assigning the regions of the left child based on height of the root node
    if(height%2 == 1)
    {
        root->left->bottom_left_x = root->bottom_left_x;
        root->left->bottom_left_y = root->bottom_left_y;
        root->left->top_right_x = root->top_right_x;
        root->left->top_right_y = root->y;
    }
    else if(height%2 == 0)
    {
        root->left->bottom_left_x = root->bottom_left_x;
        root->left->bottom_left_y = root->bottom_left_y;
        root->left->top_right_x = root->x;
        root->left->top_right_y = root->top_right_y;
    }

    node* leftChild = root->left;
    if(inRange(leftChild->bottom_left_x,leftChild->bottom_left_y,rangeQueryBottomLeft,rangeQueryTopRight)
        && inRange(leftChild->top_right_x, leftChild->top_right_y,rangeQueryBottomLeft,rangeQueryTopRight))
        return true;
    return false;
}

/*
    Function: rightSubTreeInRange
    Attributes:
    1. root: address of a node
    2. rangeQueryBottomLeft: bottom left end of diagonal of the rectangular range
    3. rangeQueryTopRight: top right end of the diagonal of the rectangular range

    Output:
    Returns true if the range of right child of the root is completely in the query
    range otherwise returns false
*/

bool rightSubTreeInRange(node* root, pair< int,int> rangeQueryBottomLeft, pair<int,int> rangeQueryTopRight)
{
    if(root == NULL || root->right == NULL) return false;
    int height = root->height;

    //assigning the regions of the left child based on height of the root node
    if(height%2 == 1)
    {
        root->right->top_right_x = root->top_right_x;
        root->right->top_right_y = root->top_right_y;
        root->right->bottom_left_y = root->y;
        root->right->bottom_left_x = root->bottom_left_x;
    }
    else if(height%2 == 0)
    {
        root->right->top_right_x = root->top_right_x;
        root->right->top_right_y = root->top_right_y;
        root->right->bottom_left_y = root->bottom_left_y;
        root->right->bottom_left_x = root->x;
    }

    node* rightChild = root->right;
    if(inRange(rightChild->bottom_left_x,rightChild->bottom_left_y,rangeQueryBottomLeft,rangeQueryTopRight)
        && inRange(rightChild->top_right_x, rightChild->top_right_y,rangeQueryBottomLeft,rangeQueryTopRight))
    return true;
    return false;
}

/*
    Function: leftSubTreeInRange
    Attributes:
    1. root: address of a node
    2. rangeQueryBottomLeft: bottom left end of diagonal of the rectangular range
    3. rangeQueryTopRight: top right end of the diagonal of the rectangular range

    Output:
    Returns true if the range of left child of the root intersects with the query
    range otherwise returns false
*/

bool leftSubtreeIntersect(node* root, pair<int,int> rangeQueryBottomLeft, pair<int,int> rangeQueryTopRight)
{
    if(root == NULL || root->left == NULL) return false;

    int height = root->height;

    if(height%2 == 1)
    {
        root->left->bottom_left_x = root->bottom_left_x;
        root->left->bottom_left_y = root->bottom_left_y;
        root->left->top_right_x = root->top_right_x;
        root->left->top_right_y = root->y;
    }
    else if(height%2 == 0)
    {
        root->left->bottom_left_x = root->bottom_left_x;
        root->left->bottom_left_y = root->bottom_left_y;
        root->left->top_right_x = root->x;
        root->left->top_right_y = root->top_right_y;
    }

    int f = 0;
    node* leftChild = root->left;

    if(leftChild->bottom_left_y > rangeQueryTopRight.second)
        f = 1;
    if(leftChild->bottom_left_x > rangeQueryTopRight.first)
        f = 1;
    if(leftChild->top_right_x < rangeQueryBottomLeft.first)
        f =1;
    if(leftChild->top_right_y < rangeQueryBottomLeft.second)
        f = 1;

    if(f == 1)
        return false;
    return true;
}

/*
    Function: rightSubTreeInRange
    Attributes:
    1. root: address of a node
    2. rangeQueryBottomLeft: bottom left end of diagonal of the rectangular range
    3. rangeQueryTopRight: top right end of the diagonal of the rectangular range

    Output:
    Returns true if the range of right child of the root intersects with the query
    range otherwise returns false
*/

bool rightSubtreeIntersect(node* root, pair<int,int> rangeQueryBottomLeft, pair<int,int> rangeQueryTopRight)
{
    if(root == NULL || root->right == NULL) return false;
    int height = root->height;

    if(height%2 == 1)
    {
        root->right->top_right_x = root->top_right_x;
        root->right->top_right_y = root->top_right_y;
        root->right->bottom_left_y = root->y;
        root->right->bottom_left_x = root->bottom_left_x;
    }
    else if(height%2 == 0)
    {
        root->right->top_right_x = root->top_right_x;
        root->right->top_right_y = root->top_right_y;
        root->right->bottom_left_y = root->bottom_left_y;
        root->right->bottom_left_x = root->x;
    }

    int f = 0;
    node* rightChild = root->right;

    if(rightChild->bottom_left_y > rangeQueryTopRight.second)
        f = 1;
    if(rightChild->bottom_left_x > rangeQueryTopRight.first)
        f = 1;
    if(rightChild->top_right_x < rangeQueryBottomLeft.first)
        f =1;
    if(rightChild->top_right_y < rangeQueryBottomLeft.second)
        f = 1;

    if(f == 1)
        return false;
    return true;
}

/*
    Function: searchTree
    Attributes:
    1. root: address of a node
    2. rangeQueryBottomLeft: bottom left end of diagonal of the rectangular range
    3. rangeQueryTopRight: top right end of the diagonal of the rectangular range

    Output:
    searches the whole tree based on the query provided by the user and stores in
    the vector of pairs solutionSet
*/

void searchTree(node* root, pair<int,int> rangeQueryBottomLeft, pair<int,int> rangeQueryTopRight)
{
    qtree++;
    if(isLeaf(root))
    {
        if(inRange(root->x,root->y,rangeQueryBottomLeft,rangeQueryTopRight))
        {
            solutionSet.push_back(make_pair(root->x,root->y));
        }
    }


    if(leftSubTreeInRange(root, rangeQueryBottomLeft, rangeQueryTopRight))
    {
        reportSubtree(root->left);
    }
    else if(leftSubtreeIntersect( root, rangeQueryBottomLeft, rangeQueryTopRight))
    {
        searchTree(root->left, rangeQueryBottomLeft, rangeQueryTopRight);
    }

    if(rightSubTreeInRange(root, rangeQueryBottomLeft, rangeQueryTopRight))
    {
        reportSubtree(root->right);
    }
    else if(rightSubtreeIntersect(root, rangeQueryBottomLeft, rangeQueryTopRight))
    {
        searchTree(root->right, rangeQueryBottomLeft, rangeQueryTopRight);
    }
}


int main()
{
    vector< pair <int,int> > a;
    int n,x,y;

    cout<<"Enter number of data points:";
    cin>>n;
    cout<<"Enter all data points in x y fashion"<<endl;
    for(int i = 1;i<=n;i++)
    {
        cin>>x>>y;
        a.push_back(make_pair(x,y));
    }

    node* root = buildTree(0,a.size()-1,a,0);
    root->bottom_left_x = INT_MIN;
    root->bottom_left_y = INT_MIN;
    root->top_right_x = INT_MAX;
    root->top_right_y = INT_MAX;

    int bottom_left_x, bottom_left_y;
    int top_right_x, top_right_y;

    cout<<"Enter the left bottom end of rectangular region:";
    cin>>bottom_left_x>>bottom_left_y;

    cout<<"Enter the left bottom end of rectangular region:";
    cin>>top_right_x>>top_right_y;

    pair<int,int> lefts = make_pair(bottom_left_x,bottom_left_y), rights = make_pair(top_right_x,top_right_y);
    searchTree(root,lefts,rights);


    cout<<"Number of Points in range:"<<solutionSet.size()<<endl;
    cout<<"qtree:"<<qtree<<endl;
    cout<<"crtree:"<<crtree<<endl;

    cout<<"The points in range are as follows:"<<endl;

    for(int i = 0;i<solutionSet.size();i++)
        cout <<solutionSet[i].first<<" "<<solutionSet[i].second<<endl;

    return 0;
}

