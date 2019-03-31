class Solution {
public:
    
    void populateMap(map<char, int> &m, const string p) {
       for (int i = 0; i < p.length(); i++) {
           if (m.find(p[i]) != m.end()) {
                m[p[i]]++;
           } else {
                m.insert(std::pair<char, int>(p[i],0));
           }
       } 
    }
    
    void copyMap(map<char, int> &pm, map<char, int> &wm) {
        for (map<char, int>::iterator it = pm.begin(); it != pm.end(); it++) {
            wm.insert(pair<char, int>((*it).first,(*it).second));
        }
    }
    
    bool contains(map<char, int> &m, char c) {
        for (map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (c == (*it).first) {
                return true;
            }
        }
        return false;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        if (s.length() < p.length()) {
            return v;
        }
        map<char, int> populated_map;
        populateMap(populated_map, p);
        map<char, int> working_map;
        bool last_set_pass = false;
        bool skip_expensive_op = false;
        for (int i = 0; i < s.length() - p.length() + 1; i++) {
                
            // We don't need to check all the whole string if the last window passed.
            // We're good if the newest element is the same as the one we stopped looking at.
            if (last_set_pass) {
                skip_expensive_op = true;
                if (s[p.length() + i - 1] == s[i - 1]) {
                    v.push_back(i);
                } else {
                    last_set_pass = false;
                }
            }
            
            if (!skip_expensive_op) {
                
                // O(p.length()), which is expensive if <p> is long.
                copyMap(populated_map, working_map);
                
                for (int j = i; j < p.length() + i; j++) {
                    
                    // If the element isn't part of <p>, then jump so that element is
                    // no longer scanned.
                    if (!contains(populated_map, s[j])) {
                        last_set_pass = false;
                        i = j; 
                        break;
                    }
                    
                    if (working_map.find(s[j]) != working_map.end()) {
                        if (working_map[s[j]] > 0) {
                            working_map[s[j]]--;  
                        } else {
                            working_map.erase(s[j]);
                        }        
                    }
                }

                if (working_map.size() == 0) {
                    v.push_back(i);
                    last_set_pass = true;
                } else {
                    last_set_pass = false;
                }
            }
            
            skip_expensive_op = false;
            working_map.clear();
        }
        return v;
    }

};