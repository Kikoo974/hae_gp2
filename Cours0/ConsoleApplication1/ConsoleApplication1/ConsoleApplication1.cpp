// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream> //librairie système chevron
#include <string>
#include <cstdlib>
#include <chrono>

#include "IntArray.h"
#include "Vec2.hpp"
#include "Vec3.hpp"
#include "Vec2T.h"
#include "Vec3T.h"
#include "Arr.h"
#include "DynArr.h"
#include "Node.h"
#include <functional>
using namespace std;
using namespace std::chrono;

/*void SubFunction1()
{
   rr<int> foo(4);
    
    cout << foo.Get(0) << endl;
    foo.Get(0) = 33;
    cout << foo.Get(0) << endl;
    foo.Set(0, 1);
    cout << foo.Get(0) << endl;
    int stop0 = 4;

    Arr<Vec2> vecList(4);

    Vec2 fooVec(1.2f, 3.6f);
    vecList.Set(0, fooVec);  
    cout << vecList.Get(0).x << ","<< vecList.Get(0).y << endl;
    int stop1 = 5;
    //delete foo;
}*/
void SubFunction2()
{
    DynArr<int> foo(4);

    cout << foo.Get(0) << endl;
    foo.Get(0) = 33;
    cout << foo.Get(0) << endl;
    //foo.resize(16);
    foo.Set(6, 2);
    foo.Set(0, 1);
    foo.Set(1, 3);
    foo.Set(2, 8);
    foo.Set(3, 7);
    foo.Set(4, 5);
    foo.Set(5, 9);
    
    int idx = 6;
  
    foo.Reverse();
    foo.push_back(25);
  

    DynArr<int> folichon(8);
    folichon.Set(3, 2);
    folichon.Set(0, 1);
    folichon.Set(1, 3);

    //foo.append(folichon);

    std::function<void(float)> affiche = [](float elem)
    {
        printf("%f", elem);
    };
    foo.iter(affiche);
    printf("/n");
    auto stop = 6;

   
}

int StringLenght(const char* str)
{
    //renvoyer la longueur
    int lenght = 0;
    while (*str !=0)
    {
        str++;
        lenght++;
    }
    return lenght;
}

void StringCopy(char* dst, const char* src)
{
   
    while (*src != 0)
    {     
        *dst = *src;
        src++;
        dst++;
    }
   

}
DynArr<float>* doHeapSort(float* tab, int tabSize)
{
    DynArr<float>* newTab = new DynArr<float>(tabSize);
    Node* tas = Node::fromTabRec(tab, tabSize);
    
    for (int i= 0; i < tabSize; i++)
    {
        float value = tas->getMin();
        cout << value << " ";
        newTab ->Set(i, value);
        tas = tas->deleteMin();       
    }
    int idx = 0;
    while (tas)
    {
        float val = tas->getMin();
        newTab->Set(idx, val);
        idx++;
        tas = tas->deleteMin();
    }
    return newTab;
}
void heapSort()
{
    float tf[4] = { 1.0, 15.0, -1.0, 25.0 };
    DynArr<float>* tab = doHeapSort(tf, 4);
    for (int i= 0; i < 4; i++)
    {
        cout << tab->Get(i) << " ";
    }
    cout << endl;
}

void SubFunction3()
{
    std::string toto = "toto";
    cout << toto << endl;
    cout << StringLenght("tabarnak") << endl;

    //char* thorus = new char[120];
    char thorus[120] = {};
    StringCopy(thorus, "tabarnak");
    cout << thorus << endl;
    auto k = 0;
}

void SubFunction4()
{
    Node* root = new Node(10);
    root = root->Heapify(9);
    root = root->Heapify(14);
    root = root->Heapify(12);
    root = root->Heapify(11);
    root = root->Heapify(5);

    if (!root->isoCs()) throw "root is not a Valid Heap";
    root = Node::merge(root, new Node(12));
   // Node* tasfoireux = new Node(12, new node(8), new Node(7));
    root = Node::merge(root, new Node(12, new Node(8), new Node(7)));

    if (!root->isoCs()) throw "root is not a Valid Heap";

    Node* n = new Node(2, new Node(4), new Node(3));
    //n = n->deleteMin();
    n = n->remove(3);
    /*float value;
    value = root->getMin();
    cout << to_string(value) << endl;
    root->deleteMin();
    value = root->getMin();
    cout << to_string(value) << endl;*/
  
}
void SubFunction5()
{
    heapSort();
}
void MemCpy(char* dest, char* src, int size)
{
    for (int i = 0; i < size; i++)
    {
        *dest = *src;
        dest++;
        src++;
    }
}
/*void SubFunction6()
{
    char data[] = { 1,2,3,4,5,6 };
    char* dest = (char*)malloc(16);
    for (int i = 0; i < 16; i++) dest[i] = 0;
    MemCpy(dest, data, sizeof(data) * sizeof(char));

    for (int i = 0; i < 16; i++)
        cout << (int)dest[i] << endl;
    free(dest);
    char test[] = "sapinsapin";
    char tarbreest[] = "pin";
    char* res = StrStr(test, tarbreest);
    if (res != nullptr)
        printf("Y'a bien dedans");
    else
        printf("Y'a pas dedans");
}*/
char* StrChr(char* grange, char chat)
{
     while (*grange != 0)
    {     
        if (*grange == chat)
            return grange;
        grange++;     
    }   
    return nullptr;
}
int strLenght(char* meule)
{
    char* oMeule = meule; //arithmétique des pointeurs
    while (*meule)
    {      
        meule++;
    }
    return oMeule - meule;
}
bool startWith(char* meule, char* aiguille)
{
    int lenght = strLenght(meule);
    int lengtAiguille = strLenght(aiguille);
    if (lengtAiguille > lenght) return false;
    for (int i = 0; i < lengtAiguille; i++)
    {
        if (aiguille[i] != meule[i])
            return false;
    }
    
    return true;

}
char* StrStr(char* meuleDeFoin, char*  aiguille)
{
    if (aiguille == nullptr && meuleDeFoin == nullptr) return nullptr;

    if (meuleDeFoin == nullptr) return nullptr;
    if (*meuleDeFoin == 0) return nullptr;
    bool isAiguilleinMeule = startWith(meuleDeFoin, aiguille);
    if (isAiguilleinMeule)
        return meuleDeFoin;
    else
        return StrStr(meuleDeFoin + 1, aiguille);

}
int StrCmp(const char* a, const char* b)
{
    if (*a == 0 && *b == 0) return 0;
    if (StringLenght(a) == 0) return 1;
    if (StringLenght(b) == 0) return -1;

    if (*a > * b)
        return -1;
    if (*a < *b)
        return 1;
    if (*a == *b)
        return StrCmp(a + 1, b + 1);
    else
        return ((*b - *a) > 0) ? -1: 1;

}


int add(int a, int b)
{
    if (b == 0)
        return a;
    else if(b>0)
    {
        return 1 + (a + 1, b - 1);
    }
    else
        return -1 + add(a, b + 1);//la même que add(a-1, b-1)
}
int sub(int a, int b)
{
    if (b == 0)
        return a;
    else if (b > 0)
        return -1 + sub(a, b - 1);  //la même que add(a-1, b-1)
    else
        return add(a, -b);
}
int mul(int a, int b)
{
    if (b == 0)
        return 0;
    else if(b>0)
        return a + mul(a, b-1);
    else
        return -a+ mul(a, b+1);
}
int divi(int a, int b)
{
   
    if (b == 0)
        return 0;
    if(b==1)
        return a;
    if(b<0)
        return -divi(a, -b);
    if(a<0)
        return -divi(-a, b);
    if (b > a) return 0;
    return 1 + divi(a - b, b);
}
int modulo(int a, int b)
{
    if (b == 0)
        return 0;
    if (b == 1)
        return 0;
    if (b < 0)
        return -modulo(a, -b);
    if (a < 0)
        return -modulo(-a, b);
    if (b > a) return a;
    return modulo(a - b, b);
}
void SubFunction7()
{
    cout << modulo(15, 7) << endl;
    cout << StrCmp("abcd", "abcd");
}
void SubFunction8()
{
   /* IntArray arrIota = IntArray::iota(6);
    IntArray arrRand = IntArray::random(6);
    int se = arrIota.search(5);
    int ar = arrRand.search(5);

    cout << se << endl;
    cout << ar << endl;

    arrRand.push_front(3);
    arrRand.insert(4, 8);
    ar = arrRand.search(8);
    cout << ar << endl;

    IntArray arr;
    for (int i = 0; i < 1000; i++)
    {
        int val = rand() % 150;
        int pos == arr.searchInsertionPosRec(val);
        insert(pos, val);
    }*/
    
   

    
}


int main()
{
    IntArray arr == IntArray::random(14000);
    auto val0 = Lib::getTimeStamp();
    arr.isSortedRec();
    auto val1 = Lib::getTimeStamp();
    cout << val0 - val1 << endl;
    //SubFunction8();
    cout << endl;
   /*// std::cout << "Hello World!\n";
   // std::cout << "Hello World!" << std::endl;
   // printf("Hello World!\n");
    printf("0\n");
    printf("0,5\n");
    printf("0,1\n");   
    printf("toto\n");
    printf("123456789123456789\n");

    int toto = 66;
    printf("valeur:%d\n", toto); //afficher la valeur d'une variable
    int nope = 0;
    

    cout << to_string(toto) << endl;
    int sapin = 0;
   
    Vec2 alpha;
    alpha.x = 0.2f;
    alpha.y = 0.3f;
   // cout << to_string(alpha.x) << endl;
   // cout << to_string(alpha.y) << endl;
    cout << to_string(alpha.x) << "," << to_string(alpha.y)<<endl;
    printf("x=%f y=%f\n", alpha.x, alpha.y);
   

    Vec2 f1(66, 37);                 
    printf("x=%f y=%f\n", f1.x, f1.y);

    Vec2 f12 = alpha.add(f1);
    printf("x=%f y=%f\n", f12.x, f12.y);
    

    Vec2 sub12 = alpha.sub(f1);
    printf("x=%f y=%f\n", sub12.x, sub12.y);

    Vec2 mul12 = alpha.mul(f1);
    printf("x=%f y=%f\n", mul12.x, mul12.y);

    Vec2 div12 = alpha.div(f1);
    printf("x=%f y=%f\n", div12.x, div12.y);
    
    Vec3 g1;
    g1.x = 10;
    g1.y = 10;
    g1.z = 10;

    printf("x=%f y=%f z=%f\n", g1.x, g1.y, g1.z);

    Vec3 g2(10, 10, 10);

    Vec3 g12 = g1.add(g2);
    printf("x=%f y=%f z=%f\n", g12.x, g12.y, g12.z);

    Vec3 gsub12 = g1.sub(g2);
    printf("x=%f y=%f z=%f\n", gsub12.x, gsub12.y, gsub12.z);

    Vec3 gmul12 = g1.mul(g2);
    printf("x=%f y=%f z=%f\n", gmul12.x, gmul12.y, gmul12.z);

    Vec3 gdiv12 = g1.div(g2);
    printf("x=%f y=%f z=%f\n", gdiv12.x, gdiv12.y, gdiv12.z);
    

    Vec2T<float> t0(45, 4);
    Vec2T<float> t1(4, 4);
    auto tres = t1.add(t0);

    cout << to_string(tres.x) << " " << to_string(tres.y) << endl;

    Vec3T<float> s0(45, 4, 1);
    Vec3T<float> s1(4, 4, 2);
    auto sres = s1.mul(s0);
    printf("x=%f y=%f z=%f\n", sres.x, sres.y, sres.z);

    Vec3T<char> vc0('a', 'b', 'c');
    Vec3T<char> vc1('d', 'e', 'f');
    auto vres = vc1.mul(vc0);

    cout << string(1, 'a') << endl;
    cout << string(1, vres.x) << " " << string(1, vres.y) << " " << string(1, vres.z) << endl;



    int tableau[] = { 0,1,4,1,2,3 };
    int size = sizeof(tableau) / sizeof(int);    //Usefull
    for (int i = 0; i < size; i++)
    {
        cout << tableau[i] << " ";
    }
    int* c0 = tableau;
    int* c1 = &(tableau[0]); //same
    int valC = *c0++;
    cout << endl;

    Vec2 p1(3, 4);            //Alloué sur la pile
    Vec2 p2(1, 1);
    p1.incr(&p2);
    cout << to_string(p2.x) << endl;

   // Vec2* pPtr = new Vec2(66);      //Alloué sur le tas
    //p1.incr((Vec2*));

    Vec2 v66 = Vec2(66);
    p1.incr(v66);  */
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
