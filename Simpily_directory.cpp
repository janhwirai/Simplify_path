#include <bits/stdc++.h>
using namespace std;

/*

/a/~get into folder a
/./~stay over there
/../~come out of folder a

*/
class Solution {
public:
    string simplifyPath(string path) {
        stack <string> st;
        string res;
        for(int i=0;i<path.size();++i){
            if(path[i]=='/')
                continue;
            string temp;
            //Iterate till end
            while(i<path.size() && path[i]!='/'){
                temp+= path[i];
                ++i;
            }
            if(temp=="."){
                continue;
            }
            else if(temp==".."){
                //pop the top element
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                //push the directory file
                st.push(temp);
            }
        }
        while(!st.empty()){
                res="/"+st.top()+res;
                st.pop();
            }
        //if no directory is present
        if(res.size()==0){
                return "/";
            }
        return res;
        
    }
};

int main(){
    Solution sol;
    cout<<"Enter the path:\n";
    string str;
    getline(cin,str);
    string res = sol.simplifyPath(str);
    cout << res;
    return 0;
}