#include<bits/stdc++.h>
using namespace std;

int numUniqueEmails(vector<string>& emails) {
        int flag = true;
        int ad = false;
        int add = false;
        unordered_set<string> domainsName;
        for(auto email : emails){
            string temp = "";
            flag = true;
            ad = false;
            add = false;
            for(auto letter : email){
                if(letter == '+') {add = 1;continue;}
                if(letter == '@') {add = 0,ad = 1;}
                if(!add || ad) {
                    if(!ad && (letter == '.')) continue;
                    temp += letter;
                }  

            }
            domainsName.insert(temp);
        }
        // for(auto x : domainsName) cout<<x<<" ";
        // cout<<"\n";
        return domainsName.size();
    }


int main(){
    vector<string> x = {"fg.r.u.uzj+o.pw@kziczvh.com","r.cyo.g+d.h+b.ja@tgsg.z.com","fg.r.u.uzj+o.f.d@kziczvh.com","r.cyo.g+ng.r.iq@tgsg.z.com","fg.r.u.uzj+lp.k@kziczvh.com","r.cyo.g+n.h.e+n.g@tgsg.z.com","fg.r.u.uzj+k+p.j@kziczvh.com","fg.r.u.uzj+w.y+b@kziczvh.com","r.cyo.g+x+d.c+f.t@tgsg.z.com","r.cyo.g+x+t.y.l.i@tgsg.z.com","r.cyo.g+brxxi@tgsg.z.com","r.cyo.g+z+dr.k.u@tgsg.z.com","r.cyo.g+d+l.c.n+g@tgsg.z.com","fg.r.u.uzj+vq.o@kziczvh.com","fg.r.u.uzj+uzq@kziczvh.com","fg.r.u.uzj+mvz@kziczvh.com","fg.r.u.uzj+taj@kziczvh.com","fg.r.u.uzj+fek@kziczvh.com"};
    cout<<numUniqueEmails(x)<<"\n";
}    