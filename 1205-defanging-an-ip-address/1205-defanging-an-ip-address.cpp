class Solution {
public:
    string defangIPaddr(string address) {
        for(int i=0; i<address.size(); i++){
            if(address[i] == '.'){
                address = address.substr(0, i) + "[.]" + address.substr(i+1, address.size()-i-1);
                i += 2;
            }
        }

        return address;
    }
};