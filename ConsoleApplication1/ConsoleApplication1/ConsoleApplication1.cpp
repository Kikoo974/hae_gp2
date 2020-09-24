// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream> //librairie système chevron
#include <string>
#include "Vec2.hpp"
#include "Vec3.hpp"
using namespace std;





int main()
{
   // std::cout << "Hello World!\n";
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
    auto endl = 0;

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
