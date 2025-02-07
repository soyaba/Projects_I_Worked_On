#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <string>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

/// -----------------------------------------
///
///  Declaration of class BINARY TREE
///
/// -----------------------------------------

template <typename T>
class BinaryTree {

private:
  // In order to represent that we are an empty tree, both left and right are NULL and the
  // contents of info is irrelevant. Otherwise, or non-empty binary trees both left and right must not be NULL.
  // Similarly, if parent is not NULL, then it means that the tree is subtree of another tree pointed at by parent.
  BinaryTree *left,*right,*parent;
  T root;

  /* Pre: true */
  /* Post: the contents initially pointed to by left and right is deeply deleted, and both left and right
           are made null pointers */
  void deleteChildren() {
    if (left != NULL) delete left;
    if (right != NULL) delete right;
    left = right = NULL;
  }

  // Fields and auxiliary functions for managing input/output format.
  
  int inputformat, outputformat;
  static void checkFormat(int format) {
    if (format == POSTORDERFORMAT or
	format == LEFTVISUALFORMAT or
	format == VISUALFORMAT or
	format == INLINEFORMAT)
      return;
    std::cerr << "ERROR: wrong tree format" << std::endl;
    exit(1);
  }
  static void dieInputOutputBinaryTree(string s);
  static void dieWrongFormatTree();
  static void checkFormatCondition(bool condition);
  static int firstNonBlankPosInString(const string &s);
  static int lastNonBlankPosInString(const string &s);
  static string value2string(const T &value);
  static void string2value(const string &s, T &value);
  static void insertPrefixVectorString(string prefix, vector<string> &v);
  static void insertSpaceVectorString(int space, vector<string> &v);
  static int obtainRootPositionInString(const string &s);
  static int countNumberNodes(const BinaryTree<T> &t);
  static void readBinaryTreePostOrder(std::istream &is, BinaryTree<T> &t);
  static void writeBinaryTreePostOrderRec(std::ostream &os, const BinaryTree<T> &t);
  static void writeBinaryTreePostOrder(std::ostream &os, const BinaryTree<T> &t);
  static void readStringTree(int &itoken,const std::vector<std::pair<std::string,std::string> > &vtoken,BinaryTree<T> &t);
  static void readStringTree(const std::string &s,BinaryTree<T> &t);
  static void writeStringTreeRec(std::ostream &os,const BinaryTree<T> &t);
  static void writeStringTree(std::ostream &os,const BinaryTree<T> &t);
  static void readLeftVisualFormatRec(istream &is, int j, BinaryTree<T> &t);
  static void readLeftVisualFormat(istream &is, BinaryTree<T> &t);
  static vector<string> generateLeftVisualFormatRec(const BinaryTree<T> &t);
  static void readVisualFormatRec(const vector<string> &v, int i, int j, BinaryTree<T> &t);
  static void readVisualFormat(const vector<string> &v, BinaryTree<T> &t);
  static vector<string> generateVisualFormatRec(const BinaryTree<T> &t);
  static vector<string> generateVisualFormat(const BinaryTree<T> &t);

 void parseStringTree(const std::string &input, BinaryTree<T> &tree) {
        int start = 0;
        tree = parseStringTreeHelper(input, start);
    }

    BinaryTree<T> parseStringTreeHelper(const std::string &input, int &pos) {
    if (pos >= input.size()) {
        return BinaryTree<T>();
    }

    std::string value;
    while (pos < input.size() && input[pos] != '(' && input[pos] != ',' && input[pos] != ')') {
        value += input[pos];
        pos++;
    }

    // Eliminar espacios en blanco al principio y al final
    value.erase(0, value.find_first_not_of(' '));
    value.erase(value.find_last_not_of(' ') + 1);

    BinaryTree<T> left, right;
    if (pos < input.size() && input[pos] == '(') {
        pos++; // saltar '('
        left = parseStringTreeHelper(input, pos);
        if (pos < input.size() && input[pos] == ',') {
            pos++; // saltar ','
            right = parseStringTreeHelper(input, pos);
        }
        if (pos < input.size() && input[pos] == ')') {
            pos++; // saltar ')'
        }
    }

    if (value.empty()) {
        return BinaryTree<T>(); // Devolver un árbol vacío si el valor está vacío
    }

    T rootValue;
    string2value(value, rootValue);
    return BinaryTree<T>(rootValue, left, right);
}

    

public:
 void printTree(const std::string& prefix, const BinaryTree<T>* node, bool isLeft) const {
    if (node != nullptr && !node->isEmpty()) {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──");
        std::cout << node->getRoot() << std::endl;
        printTree(prefix + (isLeft ? "│   " : "    "), node->left, true);
        printTree(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void print() const {
    printTree("", this, false);
}
 
    
  //constructors
  /* Pre: true */
  /* Post: the result is a binary tree without any element */
  BinaryTree() {
    left = right = parent = NULL;
    inputformat = outputformat = INLINEFORMAT;
  }
  
  /* Pre: true */
  /* Post: the implicit parameter is a deep copy of the binary tree given as parameter */
  BinaryTree(const BinaryTree<T> &t) {
    if (t.isEmpty()) {
      left = right = parent = NULL;
    } else {
      root = t.getRoot();
      left = new BinaryTree<T> (t.getLeft());
      right = new BinaryTree<T> (t.getRight());
      parent = NULL;
      left->parent = this;
      right->parent = this;
    }
    inputformat = t.inputformat;
    outputformat = t.outputformat;
  }
  
  /* Pre: true */
  /* Post: the implicit parameter is a binary tree with a copy of x as root and
     deep copies of left and right as direct subtrees */
  BinaryTree(const T &root,const BinaryTree<T> &left,const BinaryTree<T> &right) {
    this->root = root;
    this->left = new BinaryTree<T> (left);
    this->right = new BinaryTree<T> (right);
    this->left->parent = this;
    this->right->parent = this;
    this->parent = NULL;
    inputformat = outputformat = INLINEFORMAT;
  }

  // destructor: automatically deletes the memory pointed directly
  // or indirectly by the attributes.
  ~BinaryTree() {
    deleteChildren();
  }

  // modifiers
  /* Pre: true */
  /* Post: the implicit parameter represents an empty tree */
  void makeEmpty() {
    if (!isEmpty()) {
      delete left;
      delete right;
      left = right = NULL;
    }
  }
  /* Pre: true */
  /* Post: the implicit parameter is a deep copy of t, and is returned.  */
  BinaryTree<T>& operator=(const BinaryTree<T> &t) {
    if (this != &t) {
      if (t.isEmpty()) {
	deleteChildren();
      } else {
	T newroot = t.getRoot();
	BinaryTree<T> *newleft = new BinaryTree<T> (t.getLeft());
	BinaryTree<T> *newright = new BinaryTree<T> (t.getRight());
	deleteChildren();
	root = newroot;
	left = newleft;
	right = newright;
	left->parent = this;
	right->parent = this;
      }
    }
    return (*this);
  }

  // getters
  /* Pre: the implicit parameter is not empty */
  /* Post: the result is a reference to the root of the implicit parameter */
  T& getRoot() {
    if (isEmpty()) {
      std::cout<<"ERROR - Operation 'getRoot' over an empty tree."<<std::endl;
      exit(1);
    }
    return root;
  }
  /* Pre: the implicit parameter is not empty */
  /* Post: the result is a reference to the root of the implicit parameter (constant version)*/
  const T& getRoot() const {
    if (isEmpty()) {
      std::cout<<"ERROR - Operation 'getRoot' over an empty tree."<<std::endl;
      exit(1);
    }
    return root;
  }
  /* Pre: the implicit parameter is not empty */
  /* Post: the result is a reference to the left child of the implicit parameter */
  BinaryTree<T> &getLeft() {
    if (isEmpty()) {
      std::cout<<"ERROR - Operation 'getLeft' over an empty tree."<<std::endl;
      exit(1);
    }
    return *left;
  }
  /* Pre: the implicit parameter is not empty */
  /* Post: the result is a reference to the left child of the implicit parameter (constant version)*/
  const BinaryTree<T> &getLeft() const {
    if (isEmpty()) {
      std::cout<<"ERROR - Operation 'getLeft' over an empty tree."<<std::endl;
      exit(1);
    }
    return *left;
  }
  /* Pre: the implicit parameter is not empty */
  /* Post: the result is a reference to the right child of the implicit parameter */
  BinaryTree<T> &getRight() {
    if (isEmpty()) {
      std::cout<<"ERROR - Operation 'right' over an empty tree."<<std::endl;
      exit(1);
    }
    return *right;
  }
  /* Pre: the implicit parameter is not empty */
  /* Post: the result is a reference to the right child of the implicit parameter (constant version)*/
  const BinaryTree<T> &getRight() const {
    if (isEmpty()) {
      std::cout<<"ERROR - Operation 'right' over an empty tree."<<std::endl;
      exit(1);
    }
    return *right;
  }

  /* Pre: true */
  /* Post: the result is true iff the implicit parameter represents an empty tree */
  bool isEmpty() const {
    return (left == NULL) and (right == NULL);
  }

  /* Pre: true */
  /* Post: the result is true iff the implicit parameter has a parent tree */
  bool hasParent() const {
    return parent != NULL;
  }

  /* Pre: the implicit parameter has a parent tree */
  /* Post: the result is a reference to the parent tree of the implicit parameter */
  BinaryTree<T> &getParent() {
    if (not hasParent()) {
      std::cout<<"ERROR - Operation 'getParent' over a tree without parent."<<std::endl;
      exit(1);
    }
    return *parent;
  }

  /* Pre: the implicit parameter has a parent tree */
  /* Post: the result is a reference to the parent tree of the implicit parameter (constant version) */
  const BinaryTree<T> &getParent() const {
    if (not hasParent()) {
      std::cout<<"ERROR - Operation 'getParent' over a tree without parent."<<std::endl;
      exit(1);
    }
    return *parent;
  }
  
  //********************************************************* 
  // Método de búsqueda recursiva
bool search(const T &value) const {
    if (isEmpty()) {
        return false;
    }
    if (root == value) {
        return true;
    }
    bool foundInLeft = left != NULL && left->search(value);
    if (foundInLeft) {
        return true;
    }
    return right != NULL && right->search(value);
}

 
  //*********************************************************

  // Fields for managing input/output.

  static const int POSTORDERFORMAT = 1;
  static const int LEFTVISUALFORMAT = 2;
  static const int VISUALFORMAT = 3;
  static const int INLINEFORMAT = 4;

  // Pre: true
  // Post: Sets inputformat of implicit tree and its descendants to 'format'
  void setInputFormat(int format) {
    checkFormat(format);
    inputformat = format;
    if (left != NULL) left->setInputFormat(format);
    if (right != NULL) right->setInputFormat(format);
  }

  // Pre: true
  // Post: Sets outputformat of implicit tree and its descendants to 'format'
  void setOutputFormat(int format) {
    checkFormat(format);
    outputformat = format;
    if (left != NULL) left->setOutputFormat(format);
    if (right != NULL) right->setOutputFormat(format);
  }

  // Pre: true
  // Post: Sets inputformat and outputformat of implicit tree and its descendants to 'format'
  void setInputOutputFormat(int format) {
    setInputFormat(format);
    setOutputFormat(format);
  }

  // Pre: true
  // Post: returns current inputformat
  int getInputFormat() const {
    return inputformat;
  }

  // Pre: true
  // Post: returns current outputformat
  int getOutputFormat() const {
    return outputformat;
  }

  // Create tree from input string
  // Pre: true
  // Post: creates a tree from the given input string
  void createFromInput(const std::string &input) {
    int pos = 0;
    *this = parseStringTreeHelper(input, pos);
}
  
  // writing operator <<
  /* Pre: true */
  /* Post: a representation of t is written on os deppending on current value of attribute 'outputformat' */
  template <class U> friend std::ostream& operator<<(std::ostream &os, const BinaryTree<U> &t);

  // reading operator >>
  // Pre: 'is' contains a representation of a binary tree deppending on current value of attribute 'inputformat'.
  // Post: t is assigned the tree value read from 'is'
  template <class U> friend std::istream& operator>>(std::istream &is, BinaryTree<U> &t);
};


/// ============================================== ///
///           Implementation friend operations     ///




////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
// Common auxiliary functions for generating format


const int MINNUMHYPENSDESCENDANT = 4;
const int MINSPACEBETWEENSUBTREES = 4;

template<typename T>
void BinaryTree<T>::dieInputOutputBinaryTree(string s)
{
  std::cerr << s << std::endl;
  exit(1);
}

template<typename T>
void BinaryTree<T>::dieWrongFormatTree()
{
  dieInputOutputBinaryTree("Error: Wrong format input tree");
}

template<typename T>
void BinaryTree<T>::checkFormatCondition(bool condition) {
  if (not condition) dieWrongFormatTree();
}

template<typename T>
int BinaryTree<T>::firstNonBlankPosInString(const string &s) {
  int i = 0;
  while (i < int(s.size()) and s[i] == ' ') ++i;
  return i;
}

template<typename T>
int BinaryTree<T>::lastNonBlankPosInString(const string &s) {
  int i = int(s.size())-1;
  while (i >= 0 and s[i] == ' ') --i;
  return i;
}

template<typename T>
string BinaryTree<T>::value2string(const T &value)
{
  ostringstream mycout;
  if (not (mycout << value))
    dieInputOutputBinaryTree("Error: We could not transform a value into a string");
  string s = mycout.str();
  if (int(s.size()) == 0)
    dieInputOutputBinaryTree("Error: length 0 is not allowed for strings describing values");
  for (int i = 0; i < int(s.size()); ++i)
    if (s[i] == ' ')
      dieInputOutputBinaryTree("Error: white spaces are not allowed for strings describing values");
  return s;
}

template<typename T>
void BinaryTree<T>::string2value(const string &s, T &value)
{
  istringstream mycin(s);
  if (not (mycin >> value))
    dieInputOutputBinaryTree("Error: We could not transform a string into a value");
  string rest;
  if (mycin >> rest)
    dieInputOutputBinaryTree("Error: We could not transform a string into a value");
}

template<typename T>
void BinaryTree<T>::insertPrefixVectorString(string prefix, vector<string> &v) {
  for (int i = 0; i < int(v.size()); ++i)
    v[i] = prefix + v[i];
}

template<typename T>
void BinaryTree<T>::insertSpaceVectorString(int space, vector<string> &v) {
  insertPrefixVectorString(string(space, ' '), v);
}

template<typename T>
int BinaryTree<T>::obtainRootPositionInString(const string &s) {
  return (firstNonBlankPosInString(s)+int(s.size())-1)/2;
}

template <class T>
int BinaryTree<T>::countNumberNodes(const BinaryTree<T> &t)
{
  if (t.isEmpty()) return 0;
  return 1 + countNumberNodes(t.getLeft()) + countNumberNodes(t.getRight());
}


////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
// Code reading and writing POSTORDERFORMAT

template <class T>
void BinaryTree<T>::readBinaryTreePostOrder(std::istream &is, BinaryTree<T> &t)
{  
  int size;
  std::stack<BinaryTree<T> > s;

  is >> size;  
  while (size > 0) {
    T node;
    int numchildren; // 0: zero, -1: only left, 1: only right, 2: two
    is >> node >> numchildren;
    if (numchildren == 0) {
      s.push(BinaryTree<T>(node, BinaryTree<T>(), BinaryTree<T>()));
    } else if (numchildren == -1) {
      BinaryTree<T> left = s.top();
      s.pop();
      s.push(BinaryTree<T>(node, left, BinaryTree<T>()));
    } else if (numchildren == 1) {
      BinaryTree<T> right = s.top();
      s.pop();
      s.push(BinaryTree<T>(node, BinaryTree<T>(), right));
    } else {
      BinaryTree<T> right = s.top();
      s.pop();
      BinaryTree<T> left = s.top();
      s.pop();
      s.push(BinaryTree<T>(node, left, right));
    }
    --size;
  }
  if (not s.empty()) t = s.top();
}

template <class T>
void BinaryTree<T>::writeBinaryTreePostOrderRec(std::ostream &os, const BinaryTree<T> &t)
{
  if (t.isEmpty()) return;
  writeBinaryTreePostOrderRec(os, t.getLeft());
  writeBinaryTreePostOrderRec(os, t.getRight());
  os << t.getRoot() << " ";
  if (t.getLeft().isEmpty() and t.getRight().isEmpty()) os << 0;
  else if (t.getLeft().isEmpty()) os << 1;
  else if (t.getRight().isEmpty()) os << -1;
  else os << 2;
  os << endl;
}

template <class T>
void BinaryTree<T>::writeBinaryTreePostOrder(std::ostream &os, const BinaryTree<T> &t)
{
  os << countNumberNodes(t) << endl;
  writeBinaryTreePostOrderRec(os, t);
}
  
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
// Code reading and writing INLINEFORMAT

template<typename T>
void BinaryTree<T>::readStringTree(int &itoken,const std::vector<std::pair<std::string,std::string> > &vtoken,BinaryTree<T> &t)
{
  if (itoken>=int(vtoken.size()) or vtoken[itoken].first!="value") {
    t=BinaryTree<T>();
    return;
  }
  std::istringstream mycin(vtoken[itoken].second);
  T value;
  mycin>>value;
  t=BinaryTree<T>(value, BinaryTree<T>(), BinaryTree<T>());
  itoken++;
  if (itoken>=int(vtoken.size()) or vtoken[itoken].first!="(") return;
  itoken++;
  //BinaryTree<T> left;
  readStringTree(itoken,vtoken,t.getLeft());
  if (itoken>=int(vtoken.size()) or vtoken[itoken].first!=",") {
    //t=BinaryTree<T>(value,left,BinaryTree<T>());
    t.getRight()=BinaryTree<T>();
    if (itoken<int(vtoken.size()) and vtoken[itoken].first==")")
      itoken++;
    return;
  }
  itoken++;
  //BinaryTree<T> right;
  readStringTree(itoken,vtoken,t.getRight());
  if (itoken<int(vtoken.size()) and vtoken[itoken].first==")")
    itoken++;
  //t=BinaryTree<T>(value,left,right);
}

template<typename T>
void BinaryTree<T>::readStringTree(const std::string &s,BinaryTree<T> &t)
{
  std::vector<std::pair<std::string,std::string> > vtoken;
  int iant=0;
  for (int i=0;i<int(s.size());i++) {
    if (s[i]==',' or s[i]=='(' or s[i]==')') {
      if (iant<i)
	vtoken.push_back(std::pair<std::string,std::string> ("value",s.substr(iant,i-iant)));
      iant=i+1;
      vtoken.push_back(std::pair<std::string,std::string> (std::string(1,s[i]),""));
    }
  }
  if (iant<int(s.size()))
    vtoken.push_back(std::pair<std::string,std::string> ("value",s.substr(iant)));
  int itoken=0;
  readStringTree(itoken,vtoken,t);
}

template<typename T>
void BinaryTree<T>::writeStringTreeRec(std::ostream &os,const BinaryTree<T> &t)
{
  if (t.isEmpty()) return;
  os<<t.getRoot();
  const BinaryTree<T> &left=t.getLeft();
  const BinaryTree<T> &right=t.getRight();
  if (left.isEmpty() and right.isEmpty()) return;
  os<<"(";
  writeStringTreeRec(os,left);
  os<<",";
  writeStringTreeRec(os,right);
  os<<")";
}

template<typename T>
void BinaryTree<T>::writeStringTree(std::ostream &os,const BinaryTree<T> &t)
{
  if (t.isEmpty()) {
    os<<"()";
    return;
  }
  writeStringTreeRec(os,t);
}

////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
// Code reading and writing LEFTVISUALFORMAT

template<typename T>
void BinaryTree<T>::readLeftVisualFormatRec(istream &is, int j, BinaryTree<T> &t) {
  string line;
  getline(is, line);
  string s = line.substr(j);
  if (s == ".") {
    t = BinaryTree<T> ();
    return;
  }
  if (int(s.size()) == 0 or s[0] != '[')
    dieInputOutputBinaryTree("Error: Wrong format for input tree");
  if (s[int(s.size())-1] != ']')
    dieInputOutputBinaryTree("Error: Wrong format for input tree");
  T value;
  string2value(s.substr(1,int(s.size())-2), value);
  t = BinaryTree<T> (value, BinaryTree<T> (), BinaryTree<T> ());
  readLeftVisualFormatRec(is, j+4, t.getRight());
  readLeftVisualFormatRec(is, j+4, t.getLeft());
}

template<typename T>
void BinaryTree<T>::readLeftVisualFormat(istream &is, BinaryTree<T> &t) {
  readLeftVisualFormatRec(is, 0, t);
}

template<typename T>
vector<string> BinaryTree<T>::generateLeftVisualFormatRec(const BinaryTree<T> &t) {
  vector<string> result;
  if (t.isEmpty()) {
    result.push_back(".");
    return result;
  }
  string rootstring = value2string(t.getRoot());
  vector<string> leftresult = generateLeftVisualFormatRec(t.getLeft());
  vector<string> rightresult = generateLeftVisualFormatRec(t.getRight());
  result.push_back("[" + rootstring + "]");
  for (int i = 0; i < int(rightresult.size()); ++i) {
    if (i == 0)
      result.push_back(" \\__" + rightresult[i]);
    else
      result.push_back(" |  " + rightresult[i]);
  }
  for (int i = 0; i < int(leftresult.size()); ++i) {
    if (i == 0)
      result.push_back(" \\__" + leftresult[i]);
    else
      result.push_back("    " + leftresult[i]);
  }
  return result;
}

////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
// Code reading and writing VISUALFORMAT


template<typename T>
void BinaryTree<T>::readVisualFormatRec(const vector<string> &v, int i, int j, BinaryTree<T> &t) {
  if (i < 0 or int(v.size()) <= i or j < 0 or int(v[i].size()) <= j or v[i][j] == ' ') {
    t = BinaryTree<T> ();
    return;
  }
  const string &line = v[i];
  int jini = j;
  while (jini > 0 and line[jini-1] != ' ') jini--;
  int jend = j;
  while (jend+1 <= int(line.size())-1 and line[jend+1] != ' ') jend++;
  string rootstring = line.substr(jini, jend-jini+1);
  T root;
  string2value(rootstring, root);
  t = BinaryTree<T> (root, BinaryTree<T> (), BinaryTree<T> ());
  if (int(v.size()) <= i+1) return;
  const string &linedown = v[i+1];
  int jdown = jini;
  while (jdown < int(linedown.size()) and jdown <= jend and linedown[jdown] == ' ') jdown++;
  if (int(linedown.size()) <= jdown or jend < jdown) return;
  checkFormatCondition(linedown[jdown] == '|');
  checkFormatCondition(i+3 < int(v.size()));
  const string &line2down = v[i+2];
  const string &line3down = v[i+3];
  int jleft = jdown-1;
  if (jleft >= 0 and jleft < int(line2down.size()) and line2down[jleft] == '-') {
    while (jleft >= 0 and line2down[jleft] == '-') jleft--;
    checkFormatCondition(0 <= jleft and jleft < int(line3down.size()) and line3down[jleft] == '|');
    readVisualFormatRec(v, i+4, jleft, t.getLeft());
  }
  int jright = jdown+1;
  if (jright < int(line2down.size()) and line2down[jright] == '-') {
    while (jright >= 0 and jright < int(line2down.size()) and line2down[jright] == '-') jright++;
    checkFormatCondition(0 <= jright and jright < int(line3down.size()) and line3down[jright] == '|');
    readVisualFormatRec(v, i+4, jright, t.getRight());
  }
}

template<typename T>
void BinaryTree<T>::readVisualFormat(const vector<string> &v, BinaryTree<T> &t) {
  if (int(v.size()) == 0) {
    t = BinaryTree<T> ();
    return;
  }
  readVisualFormatRec(v, 0, firstNonBlankPosInString(v[0]), t);
}

template<typename T>
vector<string> BinaryTree<T>::generateVisualFormatRec(const BinaryTree<T> &t) {
  if (t.isEmpty()) return vector<string> ();
  string rootstring = value2string(t.getRoot());
  int rootrelativepos = (int(rootstring.size())-1)/2;
  vector<string> leftresult = generateVisualFormatRec(t.getLeft());
  int leftrootpos = 0;
  if (int(leftresult.size()) > 0)
    leftrootpos = obtainRootPositionInString(leftresult[0]);
  vector<string> rightresult = generateVisualFormatRec(t.getRight());
  int rightrootpos = 0;
  if (int(rightresult.size()) > 0)
    rightrootpos = obtainRootPositionInString(rightresult[0]);
  vector<string> result;
  if (int(leftresult.size()) == 0 and int(rightresult.size()) == 0) {
    result.push_back(rootstring);
    return result;
  }
  if (int(leftresult.size()) == 0) {
    int rootpos = rightrootpos-MINNUMHYPENSDESCENDANT-1;
    if (rootpos-rootrelativepos < 0) {
      insertSpaceVectorString(-(rootpos-rootrelativepos), rightresult);
      rightrootpos += -(rootpos-rootrelativepos);
      rootpos = rootrelativepos;
    }
    result.push_back(string(rootpos-rootrelativepos, ' ') + rootstring);
    result.push_back(string(rootpos, ' ') + string(1, '|'));
    result.push_back(string(rootpos+1, ' ') + string(rightrootpos-rootpos-1, '-'));
    result.push_back(string(rightrootpos, ' ') + string(1, '|'));
    for (int i = 0; i < int(rightresult.size()); ++i)
      result.push_back(rightresult[i]);
    return result;
  }
  if (int(rightresult.size()) == 0) {
    int rootpos = leftrootpos+MINNUMHYPENSDESCENDANT+1;
    if (rootpos-rootrelativepos < 0) {
      insertSpaceVectorString(-(rootpos-rootrelativepos), leftresult);
      leftrootpos += -(rootpos-rootrelativepos);
      rootpos = rootrelativepos;
    }
    result.push_back(string(rootpos-rootrelativepos, ' ') + rootstring);
    result.push_back(string(rootpos, ' ') + string(1, '|'));
    result.push_back(string(leftrootpos+1, ' ') + string(max(0,rootpos-leftrootpos-1), '-'));
    result.push_back(string(leftrootpos, ' ') + string(1, '|'));
    for (int i = 0; i < int(leftresult.size()); ++i)
      result.push_back(leftresult[i]);
    return result;
  }
  int addspace = leftrootpos + 2 + 2*MINNUMHYPENSDESCENDANT - rightrootpos;
  for (int i = 0; i < int(leftresult.size()) and i < int(rightresult.size()); ++i)
    addspace = max(addspace, int(leftresult[i].size())-firstNonBlankPosInString(rightresult[i])+MINSPACEBETWEENSUBTREES);
  if ((rightrootpos+addspace-leftrootpos)%2 == 1) addspace++;
  if (addspace > 0) {
    insertSpaceVectorString(addspace, rightresult);
    rightrootpos += addspace;
  } else if (addspace < 0) {
    insertSpaceVectorString(-addspace, leftresult);
    leftrootpos += -addspace;
  }
  int rootpos = (leftrootpos+rightrootpos)/2;
  if (rootpos-rootrelativepos < 0) {
    insertSpaceVectorString(-(rootpos-rootrelativepos), leftresult);
    insertSpaceVectorString(-(rootpos-rootrelativepos), rightresult);
    leftrootpos += -(rootpos-rootrelativepos);
    rightrootpos += -(rootpos-rootrelativepos);
    rootpos = rootrelativepos;
  }
  result.push_back(string(rootpos-rootrelativepos, ' ') + rootstring);
  result.push_back(string(rootpos, ' ') + string(1, '|'));
  result.push_back(string(leftrootpos+1, ' ') + string(rootpos-leftrootpos-1, '-') + string(1, ' ') +
		   string(max(0,rightrootpos-rootpos-1), '-'));
  result.push_back(string(leftrootpos, ' ') + string(1, '|') + string(rightrootpos-leftrootpos-1, ' ') + string(1, '|'));
  //cout << "Adding left and right result" << endl;
  for (int i = 0; i < int(leftresult.size()) or i < int(rightresult.size()); ++i) {
    if (i < int(leftresult.size()) and i < int(rightresult.size())) {
      string &leftline = leftresult[i];
      string &rightline = rightresult[i];
      int leftsize = int(leftline.size());
      int rightsize = int(rightline.size());
      int size = max(leftsize, rightsize);
      string line(size, ' ');
      for (int j = 0; j < size; ++j) {
	if (j < leftsize and leftline[j] != ' ') line[j] = leftline[j];
	else if (j < rightsize and rightline[j] != ' ') line[j] = rightline[j];
      }
      result.push_back(line);
    } else if (i < int(leftresult.size())) {
      result.push_back(leftresult[i]);
    } else {
      result.push_back(rightresult[i]);
    }
  }
  return result;
}

template <class T>
vector<string> BinaryTree<T>::generateVisualFormat(const BinaryTree<T> &t) {
  vector<string> v = generateVisualFormatRec(t);
  v.push_back(string());
  return v;
}

////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
// Write tree on an output stream

template <class T>
std::ostream& operator<<(std::ostream &os, const BinaryTree<T> &t) {
  int format = t.getOutputFormat();
  if (format == BinaryTree<T>::INLINEFORMAT) {
    BinaryTree<T>::writeStringTree(os, t);
    return os;
  }
  if (format == BinaryTree<T>::POSTORDERFORMAT) {
    BinaryTree<T>::writeBinaryTreePostOrder(os, t);
    return os;
  }
  vector<string> result;
  if (format == BinaryTree<T>::LEFTVISUALFORMAT)
    result = BinaryTree<T>::generateLeftVisualFormatRec(t);
  else if (format == BinaryTree<T>::VISUALFORMAT)
    result = BinaryTree<T>::generateVisualFormat(t);
  for (int i = 0; i < int(result.size()); ++i) {
    os << result[i];
    if (i < int(result.size())-1) os << std::endl;
  }
  return os;
}

////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
// Read tree from an input stream

template <class T>
std::istream& operator>>(std::istream &is, BinaryTree<T> &t) {
  int format = t.getInputFormat();
  if (format == BinaryTree<T>::INLINEFORMAT) {
    string s;
    is >> s;
    BinaryTree<T>::readStringTree(s, t);
    return is;
  }
  if (format == BinaryTree<T>::POSTORDERFORMAT) {
    BinaryTree<T>::readBinaryTreePostOrder(is, t);
    return is;
  }
  //is.clear();
  //is.ignore();
  if (format == BinaryTree<T>::LEFTVISUALFORMAT) {
    BinaryTree<T>::readLeftVisualFormat(is, t);
    return is;
  }
  vector<string> v;
  string line;
  while (getline(is, line) and line != "")
    v.push_back(line);
  BinaryTree<T>::readVisualFormat(v, t);
  return is;
}
#endif

