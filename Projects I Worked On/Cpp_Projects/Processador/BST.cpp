//--------------------------
// Mètodes privats auxiliars
//--------------------------

template <typename T>
void BST<T>::clear(Item *node) 
{
	if (node != NULL) {
		clear(node->left);
		clear(node->right);
		delete node;
	}
}

template <typename T>
typename BST<T>::Item* BST<T>::insert(Item *node, const T& d) 
{
	if (node == NULL) {
		node = new Item(d, NULL, NULL);
	} else if (d < node->data) {
		node->left = insert(node->left, d);
	} else {
		node->right = insert(node->right, d);
	} 
	return node;
}

template <typename T>
typename BST<T>::Item* BST<T>::remove(Item *node, const T& d) 
{
	if (node == NULL) {
		return NULL;
	} else if (d > node->data) {
		node->right = remove(node->right, d);
	} else if (d < node->data) {
		node->left = remove(node->left, d);
	} else if (node->left != NULL and node->right != NULL) 
	{
		// Node has two children
		Item *tmp = node->right;
		while (tmp->left != NULL) 
		{
			tmp = tmp->left;
		}
		node->data = tmp->data;
		node->right = remove(node->right, node->data);
	} else {
		// Node has at most one child
		Item *tmp = node;
		if (node->left == NULL) {
			node = node->right;
		} else if (node->right == NULL) {
			node = node->left;
		}
		delete tmp;
	}
	return node;
}

template <typename T>
void BST<T>::setValue(Item *node, const T& d, const T& value) 
{
	Item *temp = find(node, d);

	if (temp != NULL) 		temp->data = value;
	else 					cerr << "Error: Node not found!" << endl;

	return;
}

template <typename T>
typename BST<T>::Item* BST<T>::find(Item *node, const T& d) const 
{
	if (node == NULL) {
		return node;
	} else if (d < node->data) {
		return find(node->left, d);
	} else if (d > node->data) {
		return find(node->right, d);
	} else {
		return node;
	}
}

template <typename T>
typename BST<T>::Item* BST<T>::copia(Item *node) {
	
	Item *nou_node = NULL;

	if (node != NULL)
	{	
		Item *fe, *fd;
		
		fe = copia(node->left);
		fd = copia(node->right);
		nou_node = new Item(node->data, fe, fd);
	}

	return nou_node;
}

//-------------
// Constructors
//-------------

template <typename T>
BST<T>::BST() {
	root = NULL;
}

template <typename T>
BST<T>::BST(const BST& bst) 
{
	root = copia(bst.root);
}

template <typename T>
BST<T>& BST<T>::operator=(const BST& bst)
{
	root = copia(bst.root);
	return *this;
}

//-------------
// Destructor
//-------------

template <typename T>
BST<T>::~BST() 
{ 
	clear(root); 
}


//-------------
// Modificadors
//-------------

template <typename T>
void BST<T>::insert(const T& d) 
{ 
	root = insert(root, d); 
}

template <typename T>
void BST<T>::remove(const T& d) 
{ 
	root = remove(root, d); 
}

template <typename T>
void BST<T>::setValue(const T& d, const T& value) 
{ 
	setValue(root, d, value); 
}

//-----------
// Consultors
//-----------

template <typename T>
pair<bool, T> BST<T>::find(const T& d) const 
{ 
	pair<bool, T> res = make_pair(false, d);
	Item* node = find(root, d);
	if (node != NULL) {
			res.first = true;
			res.second = node->data;
	}
	return res;
}

template <typename T>
void BST<T>::preOrdre(Item *node, vector<T>& R) const
{

	/*
	 * Cal que implementeu aquest mètode privat.
	 * Torna en un vector tots els elements de l'arbre

	 * en PREordre. Això vol dir que tornarà els elements
	 * de l'arbre en ordre alfabètic dels noms de variables.
	 */
	 
	 
	 
   if (node != nullptr) {
   
        //Recórrer el subarbre esquerre
        preOrdre(node->left, R);

        //Visitar el node actual entre els subarbres esquerre i dret
        R.push_back(node->data);

        //Recórrer el subarbre dret
        preOrdre(node->right, R);
        
   
    }

}

template <typename T>
void BST<T>::preOrdre(vector<T>& r) const
{
	preOrdre(root, r);
	return;
}




