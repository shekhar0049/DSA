class MovieRentingSystem {
    unordered_map<int, set<pair<int, int>>> unrented;
    map<pair<int, int>, int> shopAndMovieToPrice;     
    set<tuple<int, int, int>> rented;                 

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (const auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
            unrented[movie].insert({price, shop});
            shopAndMovieToPrice[{shop, movie}] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        if (unrented.count(movie)) {
            int count = 0;
            for (auto it = unrented[movie].begin(); it != unrented[movie].end() && count < 5; ++it, ++count) {
                res.push_back(it->second);
            }
        }
        return res;
    }

    void rent(int shop, int movie) {
        int price = shopAndMovieToPrice[{shop, movie}];
        unrented[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = shopAndMovieToPrice[{shop, movie}];
        unrented[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int count = 0;
        for (auto it = rented.begin(); it != rented.end() && count < 5; ++it, ++count) {
            int shop = get<1>(*it);
            int movie = get<2>(*it);
            res.push_back({shop, movie});
        }
        return res;
    }
};