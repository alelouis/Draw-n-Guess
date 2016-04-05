//
//  toolbox.hpp
//  Draw-n-Guess
//
//  Created by Alexis Louis on 05/04/2016.
//  Copyright © 2016 Alexis Louis. All rights reserved.
//

#ifndef toolbox_hpp
#define toolbox_hpp

#include "Header.h"
using namespace std;

deque<deque<int>> compress_mat(deque<deque<int>> src_mat);
void affiche_mat(deque<deque<int>> mat, int lignes, int colonnes);
deque<deque<int>> transpose_mat(deque<deque<int>> src_mat);
deque<deque<int>> center_mat(deque<deque<int>> src_mat);
deque<deque<int>> mirror_mat(deque<deque<int>> src_mat);
vector<float> extract_variables(deque<deque<int>> img);
vector<float> normalize(vector<float> origin_variables);
vector<float> pca(vector<float> origin_variables);
#endif /* toolbox_hpp */
