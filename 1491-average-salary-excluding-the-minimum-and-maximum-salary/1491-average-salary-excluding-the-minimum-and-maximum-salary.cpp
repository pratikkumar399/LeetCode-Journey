class Solution {
public:
    double average(vector<int>& salary) {
        int mini = *min_element(salary.begin(),salary.end());
        int maxi = *max_element(salary.begin(),salary.end());
        double sum = accumulate(salary.begin(),salary.end(),0);
        sum -=mini;
        sum -=maxi;
        
        return (sum/ (salary.size()-2));
    }
};