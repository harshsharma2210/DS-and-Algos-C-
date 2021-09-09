int minimumNumberOfSwaps(string S){
int ans=0,opening=0,close=0;
for(int i=0;i<s.length();i++){ if(s[i]="='['){" ans+="close;" if(close="">0)
close--;
else
opening++;
}
if(S[i]==']'){
if(opening>0)
opening--;
else
close++;
}

}
return ans;
}