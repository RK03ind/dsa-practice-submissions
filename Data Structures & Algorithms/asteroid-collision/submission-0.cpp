class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for(const int &i: asteroids){
            if(i > 0 || res.empty()){
                res.push_back(i);
            }else if(res.back() > 0 && i < 0){
                while(!res.empty() && res.back() > 0 && (res.back() < abs(i))){
                    res.pop_back(); //DESTROYING ALL IN THE PATH WHEN SMALLER +VE ie opposite direction
                }
                if(!res.empty() && res.back() == abs(i)){
                    res.pop_back(); //DESTROYING BOTH
                }else if(res.empty() || res.back() < 0){
                    res.push_back(i); //SAME DIRECTION ie BOTH -VE ASTEROIDS CANT BE DESTROYED 
                }
            }else{
                res.push_back(i);
            }

        }

        return res;

    }
};