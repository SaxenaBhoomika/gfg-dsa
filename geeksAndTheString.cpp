string ans = "";
        for(int i=0;i<s.length();i++) {
            char c = s[i];
            if(ans.length()>0 && ans[ans.length()-1]==c) {
                ans = ans.substr(0,ans.length()-1);
            } else {
                ans+=c;
            }
        }
        if(ans.length()==0) return "-1";
        return ans;
