class Solution {
public:
    char kthCharacter(int k) {

        string str="a";

        while(str.size()<k){

            int n=str.size();
            // cout<<"Cureent Length: "<<n<<endl;
            for(int i=0;i<n;i++){

                // cout<<"Current String: "<<str<<endl;

                // cout<<"Current character: "<<str[i]<<endl;
                if(str[i]=='z'){

                    str.push_back('a');
                }else{
                    char ch=str[i];
                    ch++;
                    // cout<<"Pushing character: "<<ch<<endl;
                    str.push_back(ch);
                }
            }
        }
        return str[k-1];
    }
};