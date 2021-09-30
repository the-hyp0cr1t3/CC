/* Sort vector and remove duplicates */

vector<int> vec{1, 1, 1, 2, 3, 3};
sort(vec.begin(), vec.end());
vec.erase(unique(vec.begin(), vec.end()), vec.end());
