//
//  toolbox.cpp
//  Draw-n-Guess
//
//  Created by Alexis Louis on 05/04/2016.
//  Copyright © 2016 Alexis Louis. All rights reserved.
//

#include "toolbox.hpp"
using namespace std;

deque<deque<int>> compress_mat(deque<deque<int>> src_mat){
    deque<deque<int>> compr_mat;
    int somme = 0;
    compr_mat.resize(8);
    for (int i=0; i<8; i++){
        compr_mat[i].resize(8);
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            for(int k=0;k<4;k++){
                for(int l=0;l<4;l++){
                    somme+=src_mat[4*i+k][4*j+l];
                }
            }
            compr_mat[i][j] = somme;
            somme = 0;
        }
    }
    return compr_mat;
}

void affiche_mat(deque<deque<int>> mat, int lignes, int colonnes){
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            cout << " ";
            cout << mat[i][j];
        }
        cout << '\n';
   
    
    }
}

deque<deque<int>> transpose_mat(deque<deque<int>> src_mat){
    deque<deque<int>> t_mat;
    t_mat.resize(src_mat.size());
    for (int i=0; i<src_mat.size(); i++){
        t_mat[i].resize(src_mat[0].size());
    }
    for(int i=0;i<src_mat.size();i++){
        for(int j=0;j<src_mat[i].size();j++){
            t_mat[i][j] = src_mat[j][i];
        }
    }
    return t_mat;
}

deque<deque<int>> center_mat(deque<deque<int>> src_mat){
    deque<deque<int>> t_mat;
    deque<int> vec_zero;
    int marge_gauche=0;
    int marge_droite=0;
    int marge_haut=0;
    int marge_bas=0;
    int delta_x = 0;
    int delta_y = 0;
    int temp_size;
    bool stop;
    stop = false;
    //Marge Gauche
    for(int i=0;i<src_mat.size();i++){
        for(int j=0;j<src_mat[i].size();j++){
            if(!stop && src_mat[j][i]){
                marge_gauche = i;
                stop = true;
            }
        }
    }
    stop = false;
    //Marge Droite
    for(int i=src_mat.size()-1;i>=0;i--){
        for(int j=0;j<src_mat[i].size();j++){
            if(!stop && src_mat[j][i]){
                marge_droite = src_mat.size()-i;
                stop = true;
            }
        }
    }
    stop = false;
    //Marge Haut
    for(int i=0;i<src_mat.size();i++){
        for(int j=0;j<src_mat[i].size();j++){
            if(!stop && src_mat[i][j]){
                marge_haut = i;
                stop = true;
            }
        }
    }
    stop = false;
    //Marge Bas
    for(int i=src_mat.size()-1;i>=0;i--){
        for(int j=0;j<src_mat[i].size();j++){
            if(!stop && src_mat[i][j]){
                marge_bas = src_mat.size()-i;
                stop = true;
            }
        }
    }
    
    delta_x = (marge_droite-marge_gauche)/2;
    delta_y = (marge_bas-marge_haut)/2;
    vec_zero.resize(src_mat.size());
    temp_size = src_mat.size();
    // Colonnes de zeros
    for(int i=0;i<delta_y;i++){
        src_mat.push_front(vec_zero);
    }
    src_mat.resize(temp_size);
    // Lignes de zeros
    for (int i=0; i<src_mat.size(); i++){
        for(int j=0;j<delta_x;j++){
            src_mat[i].push_front(0);
        }
        src_mat[i].resize(temp_size);
    }
    
    return src_mat;
}
