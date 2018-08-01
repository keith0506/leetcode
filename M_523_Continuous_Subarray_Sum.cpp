bool checkSubarraySum(vector<int>& nums, int k) {
    set <int> mod;
    vector<int>::iterator it;
    int sum = 0;
    int tmpmod = -1;

    if (k == 0) {
        vector<int>::iterator end = nums.end();
        end--;
        for(it = nums.begin(); it != end; it++) {
            if (*it == 0 && *(it+1) == 0) {
                    return true;
            }
        }
        return false;
    }
    sum = *(nums.begin());
    mod.insert(sum%k);
    it = nums.begin();
    it++;
    for(; it != nums.end(); it++)
    {
        sum += *it;
        tmpmod = sum%k;
        if (tmpmod == 0 || mod.find(tmpmod) != mod.end()) {
            return true;
        }
        else {
            mod.insert(tmpmod);
        }
    }
    return false;
}