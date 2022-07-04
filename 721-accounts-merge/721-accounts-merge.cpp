class UnionFind {
    vector<int> parent;
    vector<int> rank;
    int groups;
    
public:
    UnionFind(int groups) {
        this -> groups = groups;
        parent = vector<int>(groups);
        rank = vector<int>(groups);
    }
    
    void initialize(int x) {
        parent[x] = x;
    }
    
    int find(int x) {
        if (parent[x] != x) {
            return find(parent[x]);
        }
        return parent[x];
    }
    
    void unify(int x, int y) {
        int xGroup = find(x);
        int yGroup = find(y);
        
        if (xGroup == yGroup) return;
        
        groups--;
        
        if (rank[xGroup] < rank[yGroup]) {
            parent[xGroup] = yGroup;
        } else if (rank[yGroup] < rank[xGroup]) {
            parent[yGroup] = xGroup;
        } else {
            parent[yGroup] = xGroup;
            rank[xGroup] = rank[yGroup] + 1;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind unions(accounts.size());
        
        map<string, int> emailToAccountIndex;
        for (int i = 0; i < accounts.size(); i++) {
            unions.initialize(i);
            vector<string>& account = accounts[i];
            for (int j = 1; j < account.size(); j++) {
                string& email = account[j];
                if (!emailToAccountIndex.count(email)) {
                    emailToAccountIndex[email] = i;
                } else {
                    unions.unify(emailToAccountIndex[email], i);
                }
            }
        }
        
        map<int, vector<string>> unionToEmails;
        for (auto& entry : emailToAccountIndex) {
            unionToEmails[unions.find(entry.second)].push_back(entry.first);
        }
        
        vector<vector<string>> mergedAccounts;
        for (auto& entry : unionToEmails) {
            vector<string>& emails = entry.second;
            emails.insert(emails.begin(), accounts[entry.first].front());
            mergedAccounts.push_back(emails);
        }
        
        return mergedAccounts;
    }
};