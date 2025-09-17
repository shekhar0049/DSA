class FoodRatings {
public:
    
    unordered_map<string, string> foodToCuisine;   
    unordered_map<string, int> foodToRating;         
    unordered_map<string, set<pair<int, string>>> cuisineMap; 

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisineMap[cuisines[i]].insert({-ratings[i], foods[i]}); 
            
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];

        
        cuisineMap[cuisine].erase({-oldRating, food});

        
        cuisineMap[cuisine].insert({-newRating, food});

      
        foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineMap[cuisine].begin()->second;
    }
};
