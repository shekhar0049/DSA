class Solution {
public:
    struct Node {
        unordered_map<string, Node*> children;
        string name;
        bool deleted = false;

        Node(string name = "") : name(name) {}
    };

    unordered_map<string, int> serialCount;
    unordered_map<string, vector<Node*>> nodesWithSerial;

    string serialize(Node* node) {
        if (node->children.empty()) return "";

        vector<pair<string, string>> subs;
        for (auto& [name, child] : node->children) {
            string subSerial = serialize(child);
            subs.emplace_back(name, subSerial);
        }

        sort(subs.begin(), subs.end());

        string serial;
        for (auto& [name, subSerial] : subs) {
            serial += "(" + name + subSerial + ")";
        }

        serialCount[serial]++;
        nodesWithSerial[serial].push_back(node);
        return serial;
    }

    void markDeleted(Node* node) {
        node->deleted = true;
        for (auto& [name, child] : node->children) {
            markDeleted(child);
        }
    }

    void collectPaths(Node* node, vector<string>& path, vector<vector<string>>& res) {
        if (node->deleted) return;

        if (!path.empty()) res.push_back(path);

        for (auto& [name, child] : node->children) {
            path.push_back(name);
            collectPaths(child, path, res);
            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node();

        for (auto& path : paths) {
            Node* curr = root;
            for (string& dir : path) {
                if (!curr->children.count(dir)) {
                    curr->children[dir] = new Node(dir);
                }
                curr = curr->children[dir];
            }
        }

        serialize(root);

        for (auto& [serial, nodeList] : nodesWithSerial) {
            if (serialCount[serial] > 1) {
                for (Node* node : nodeList) {
                    markDeleted(node); 
                }
            }
        }

        vector<vector<string>> result;
        vector<string> currentPath;
        collectPaths(root, currentPath, result);
        return result;
    }
};
