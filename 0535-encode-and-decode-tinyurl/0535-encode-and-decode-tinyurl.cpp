class Solution {
    int cnt = 0;
    unordered_map<string,string>mp;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string val = to_string(cnt);
        cnt++;
       string encoded_url = "https://tinyurl/val";

       mp[encoded_url] = longUrl;
       return encoded_url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));