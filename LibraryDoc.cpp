/*
Function prototype:
void HashTable::deleteMovie(string)

Function description:
This method calculates the hashcode for the input movie name, and deletes the movie from the hash table. Handles cases where movie is first, mid, or last node in the chain.

Example:
HashTable ht;
ht.deleteMovie("The Usual Suspects")

Precondition: Unused locations in hashTable vector are NULL. Movies stored using correctly calculated hash code calculated from movie title. The input string name is movie title.
Post condition: movie node deleted from chain and memory freed. Pointers updated to bypass deleted movie.
*/
void ItemTree::addItemNode(string item, int price)
{
    ItemNode *next = new ItemNode(item, price);
    ItemNode *x = root;
    ItemNode *P = NULL;

    if (x == NULL)
    {
        root = next;
        root->parent = NULL;
        root->leftChild = NULL;
        root->rightChild = NULL;
    }
    else
    {
        while (x != NULL)
        {
            P = x;
            if (item.compare(x->item) < 0)
            {
                x = x->leftChild;
            }
            else
            {
                x = x->rightChild;
            }
        }

        next->parent = P;
        next->leftChild = NULL;
        next->rightChild = NULL;
        if (item.compare(P->item) < 0)
        {
            P->leftChild = next;
        }
        else
        {
            P->rightChild = next;
        }
    }
}

/*
Function prototype:
void HashTable::deleteMovie(string)

Function description:
This method calculates the hashcode for the input movie name, and deletes the movie from the hash table. Handles cases where movie is first, mid, or last node in the chain.

Example:
HashTable ht;
ht.deleteMovie("The Usual Suspects")

Precondition: Unused locations in hashTable vector are NULL. Movies stored using correctly calculated hash code calculated from movie title. The input string name is movie title.
Post condition: movie node deleted from chain and memory freed. Pointers updated to bypass deleted movie.
*/
void ItemTree::deleteItemNode(string item)
{
    ItemNode *nodeDelete = searchItemTree(root, item);

    if (nodeDelete == NULL)
    {
        cout << "Item not found." << endl;
    }
    else
    {
        soldList.push_back(nodeDelete->item);

        if (nodeDelete->leftChild==NULL || nodeDelete->rightChild==NULL)
        {
            // No Children
            if (nodeDelete->leftChild==NULL && nodeDelete->rightChild==NULL)
            {
                if (nodeDelete == nodeDelete->parent->leftChild)
                {
                    nodeDelete->parent->leftChild = NULL;
                }
                else if (nodeDelete == nodeDelete->parent->rightChild)
                {
                    nodeDelete->parent->rightChild = NULL;
                }

                delete nodeDelete;
            }
            // One child
            else
            {
                if (nodeDelete->leftChild == NULL)
                {
                    if (nodeDelete == nodeDelete->parent->leftChild)
                    {
                        nodeDelete->parent->leftChild = nodeDelete->rightChild;
                    }
                    else if (nodeDelete == nodeDelete->parent->rightChild)
                    {
                        nodeDelete->parent->rightChild = nodeDelete->rightChild;
                    }
                }
                else if (nodeDelete->rightChild == NULL)
                {
                    if (nodeDelete == nodeDelete->parent->leftChild)
                    {
                        nodeDelete->parent->leftChild = nodeDelete->leftChild;
                    }
                    else if (nodeDelete == nodeDelete->parent->rightChild)
                    {
                        nodeDelete->parent->rightChild = nodeDelete->leftChild;
                    }
                }

                delete nodeDelete;
            }
        }
        // Two children
        else if (nodeDelete->leftChild!=NULL && nodeDelete->rightChild!=NULL)
        {
            ItemNode *replNode = minimumNode(nodeDelete->rightChild);
            nodeDelete->item = replNode->item;
            nodeDelete->price = replNode->price;

            if (replNode->rightChild != NULL)
            {
                replNode->rightChild->parent = replNode->parent;
            }
            if (replNode == replNode->parent->leftChild)
            {
                replNode->parent->leftChild = replNode->rightChild;
            }
            else if (replNode == replNode->parent->rightChild)
            {
                replNode->parent->rightChild = replNode->rightChild;
            }

            delete replNode;
        }
    }
}

/*
Function prototype:
void HashTable::deleteMovie(string)

Function description:
This method calculates the hashcode for the input movie name, and deletes the movie from the hash table. Handles cases where movie is first, mid, or last node in the chain.

Example:
HashTable ht;
ht.deleteMovie("The Usual Suspects")

Precondition: Unused locations in hashTable vector are NULL. Movies stored using correctly calculated hash code calculated from movie title. The input string name is movie title.
Post condition: movie node deleted from chain and memory freed. Pointers updated to bypass deleted movie.
*/
void ItemTree::findItem(string item)
{
    if (searchItemTree(root, item) == NULL)
    {
        cout << "Item not found" << endl;
    }
    else
    {
        cout << "Item Information:" << endl
             << "******************" << endl
             << "Item:" << searchItemTree(root, item)->item << endl
             << "Price:" << searchItemTree(root, item)->price << endl;
    }
}

/*
Function prototype:
void HashTable::deleteMovie(string)

Function description:
This method calculates the hashcode for the input movie name, and deletes the movie from the hash table. Handles cases where movie is first, mid, or last node in the chain.

Example:
HashTable ht;
ht.deleteMovie("The Usual Suspects")

Precondition: Unused locations in hashTable vector are NULL. Movies stored using correctly calculated hash code calculated from movie title. The input string name is movie title.
Post condition: movie node deleted from chain and memory freed. Pointers updated to bypass deleted movie.
*/
ItemNode* ItemTree::searchItemTree(ItemNode *node, string item)
{
    if (node == NULL)
    {
        return node;
    }
    else if (node->item == item)
    {
        return node;
    }
    else
    {
        if (node->item.compare(item) <= 0)
        {
            return searchItemTree(node->rightChild, item);
        }
        else
        {
            return searchItemTree(node->leftChild, item);
        }
    }
}

int ItemTree::countItemNodes()
{
    cnt = 0;
    countItemNodes(root);

    return cnt;
}

/*
Function prototype:
void HashTable::deleteMovie(string)

Function description:
This method calculates the hashcode for the input movie name, and deletes the movie from the hash table. Handles cases where movie is first, mid, or last node in the chain.

Example:
HashTable ht;
ht.deleteMovie("The Usual Suspects")

Precondition: Unused locations in hashTable vector are NULL. Movies stored using correctly calculated hash code calculated from movie title. The input string name is movie title.
Post condition: movie node deleted from chain and memory freed. Pointers updated to bypass deleted movie.
*/
int ItemTree::countItemNodes(ItemNode *node)
{
    if (node->leftChild != NULL)
    {
        countItemNodes(node->leftChild);
    }

    cnt++;

    if (node->rightChild != NULL)
    {
        countItemNodes(node->rightChild);
    }
}

void ItemTree::printInOrder()
{
    if (root == NULL)
    {
        cout << "List empty" << endl;
    }
    else
    {
        cout << "<ITEM:PRICE>" << endl;
        printInOrder(root);
    }
}

/*
Function prototype:
void HashTable::deleteMovie(string)

Function description:
This method calculates the hashcode for the input movie name, and deletes the movie from the hash table. Handles cases where movie is first, mid, or last node in the chain.

Example:
HashTable ht;
ht.deleteMovie("The Usual Suspects")

Precondition: Unused locations in hashTable vector are NULL. Movies stored using correctly calculated hash code calculated from movie title. The input string name is movie title.
Post condition: movie node deleted from chain and memory freed. Pointers updated to bypass deleted movie.
*/
void ItemTree::printInOrder(ItemNode *node)
{
    if (node->leftChild != NULL)
    {
        printInOrder(node->leftChild);
    }

    cout << node->item << ":" << node->price << endl;

    if (node->rightChild != NULL)
    {
        printInOrder(node->rightChild);
    }
}

void ItemTree::printPreOrder()
{
    if (root == NULL)
    {
        cout << "List empty" << endl;
    }
    else
    {
        cout << "<ITEM:PRICE>" << endl;
        printPreOrder(root);
    }
}

/*
Function prototype:
void HashTable::deleteMovie(string)

Function description:
This method calculates the hashcode for the input movie name, and deletes the movie from the hash table. Handles cases where movie is first, mid, or last node in the chain.

Example:
HashTable ht;
ht.deleteMovie("The Usual Suspects")

Precondition: Unused locations in hashTable vector are NULL. Movies stored using correctly calculated hash code calculated from movie title. The input string name is movie title.
Post condition: movie node deleted from chain and memory freed. Pointers updated to bypass deleted movie.
*/
void ItemTree::printPreOrder(ItemNode *node)
{
    cout << node->item << ":" << node->price << endl;

    if (node->leftChild != NULL)
    {
        printPreOrder(node->leftChild);
    }

    if (node->rightChild != NULL)
    {
        printPreOrder(node->rightChild);
    }
}

void ItemTree::printPostOrder()
{
    if (root == NULL)
    {
        cout << "List empty" << endl;
    }
    else
    {
        cout << "<ITEM:PRICE>" << endl;
        printPostOrder(root);
    }
}

/*
Function prototype:
void HashTable::deleteMovie(string)

Function description:
This method calculates the hashcode for the input movie name, and deletes the movie from the hash table. Handles cases where movie is first, mid, or last node in the chain.

Example:
HashTable ht;
ht.deleteMovie("The Usual Suspects")

Precondition: Unused locations in hashTable vector are NULL. Movies stored using correctly calculated hash code calculated from movie title. The input string name is movie title.
Post condition: movie node deleted from chain and memory freed. Pointers updated to bypass deleted movie.
*/
void ItemTree::printPostOrder(ItemNode *node)
{
    if (node->leftChild != NULL)
    {
        printPostOrder(node->leftChild);
    }

    if (node->rightChild != NULL)
    {
        printPostOrder(node->rightChild);
    }

    cout << node->item << ":" << node->price << endl;
}

/*
Function prototype:
void HashTable::deleteMovie(string)

Function description:
This method calculates the hashcode for the input movie name, and deletes the movie from the hash table. Handles cases where movie is first, mid, or last node in the chain.

Example:
HashTable ht;
ht.deleteMovie("The Usual Suspects")

Precondition: Unused locations in hashTable vector are NULL. Movies stored using correctly calculated hash code calculated from movie title. The input string name is movie title.
Post condition: movie node deleted from chain and memory freed. Pointers updated to bypass deleted movie.
*/
void ItemTree::printSold()
{
    if (soldList.size() == 0)
    {
        cout << "List of sold items unavailable" << endl;
    }
    else
    {
        cout << "<ITEM>" << endl;

        for (int i=0; i<soldList.size(); i++)
        {
            cout << soldList[i] << endl;
        }
    }
}
