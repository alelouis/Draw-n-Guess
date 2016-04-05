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

deque<deque<int>> mirror_mat(deque<deque<int>> src_mat){
    deque<deque<int>> m_mat;
    m_mat.resize(src_mat.size());
    for (int i=0; i<src_mat.size(); i++){
        m_mat[i].resize(src_mat.size());
    }
    for(int i=0;i<src_mat.size();i++){
        for(int j=0;j<src_mat.size();j++){
            m_mat[i][j] = src_mat[i][src_mat.size()-1-j];
        }
    }
    return m_mat;
}

vector<float> extract_variables(deque<deque<int>> img){
    vector<float> variables;
    deque<deque<int>> m_img = mirror_mat(img);
    int sumHist = 0;
    
    //Horizontal Histogram
    for(int i=0;i<img.size();i++){
        for(int j=0;j<img.size();j++){
            sumHist+=img[i][j];
        }
        variables.push_back(sumHist);
        sumHist = 0;
    }
    //Vertical Histogram
    for(int i=0;i<img.size();i++){
        for(int j=0;j<img.size();j++){
            sumHist+=img[j][i];
        }
        variables.push_back(sumHist);
        sumHist = 0;
    }
    //+pi/4 Histogram
    for (int i = 0; i < 2 * 8 - 1; ++i) {
        int z = i < 8 ? 0 : i - 8 + 1;
        for (int j = z; j <= i - z; ++j) {
            sumHist+=img[j][i - j];
        }
        variables.push_back(sumHist);
        sumHist = 0;
    }
    //-pi/4 Histogram
    for (int i = 0; i < 2 * 8 - 1; ++i) {
        int z = i < 8 ? 0 : i - 8 + 1;
        for (int j = z; j <= i - z; ++j) {
            sumHist+=m_img[j][i - j];
        }
        variables.push_back(sumHist);
        sumHist = 0;
    }
    //quadrans
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<4;k++){
                for(int l=0;l<4;l++){
                    sumHist+=img[4*i+k][4*j+l];
                }
            }
            variables.push_back(sumHist);
            sumHist = 0;
        }
    }
    //taux de presence
    for(int i=0;i<img.size();i++){
        for(int j=0;j<img.size();j++){
            if(img[i][j]){
                sumHist+=1;
            }
        }
    }
    variables.push_back(sumHist/64.0);
    
    //Deletes useless variables (all zero)
    variables.erase(variables.begin() + 45);
    variables.erase(variables.begin() + 31);
    variables.erase(variables.begin() + 30);
    variables.erase(variables.begin() + 17);
    variables.erase(variables.begin() + 16);
    variables.erase(variables.begin() + 15);
    variables.erase(variables.begin() + 7);

    return variables;
}

vector<float> normalize(vector<float> origin_variables){
    vector<vector<float>> mu = readMatFromFile("/Users/Alexis/Documents/SFML/Draw-n-Guess/sfmlMac/mu.txt");
    vector<vector<float>> sigma = readMatFromFile("/Users/Alexis/Documents/SFML/Draw-n-Guess/sfmlMac/sigma.txt");
    vector<float> norm_variables;
    for(int i=0;i<mu[0].size();i++){
        norm_variables.push_back((origin_variables[i]-mu[0][i])/sigma[0][i]);
    }
    return norm_variables;
}

vector<float> pca(vector<float> origin_variables){
    vector<vector<float>> pca = readMatFromFile("/Users/Alexis/Documents/SFML/Draw-n-Guess/sfmlMac/coef.txt");
    vector<float> pca_variables;
    float sumProjection=0;
    for(int i=0; i<pca.size();i++){
        for(int j=0;j<pca[0].size();j++){
            sumProjection+=origin_variables[i]*pca[j][i];
        }
        pca_variables.push_back(sumProjection);
        sumProjection=0;
    }
    return pca_variables;
}

