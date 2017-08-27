 bool wordBreak(string s, vector<string>& wordDict) {
    // Validate Input
   if (s.empty() || wordDict.empty()){
       return false;
   }
   // Preparation
   unordered_set<string> dictionary;
   for(int i=0;i<wordDict.size();i++){
       dictionary.insert(wordDict[i]);
   }
   int size = s.size();
   vector<int> memory(size,0);
   // Loop through word
   for (int i = 0; i < size; i++) {
       if (dictionary.find(s.substr(0, i + 1)) != dictionary.end()) {
           memory[i] = 1;
       }
       else if (i > 0) {
           for (int j = i; j > 0; j--) {
               if (memory[j - 1] && dictionary.find(s.substr(j, i - j+1)) != dictionary.end()) {
                   memory[i] = 1;
                   break;
               }
           }
       }
   }
   // Check vector
   if (memory[size - 1] == 1) {
       return true;
   }
   else {
       return false;
   } 
}