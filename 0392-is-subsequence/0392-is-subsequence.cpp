class Solution{
public:

Solution(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool isSubsequence(string s, string t) 
{
    if(s.length()>t.length())
        return false;
    if(s==t)
        return true;
    int i,v=0;
    for(i=0;t[i];i++)
    {
        if(s[v]==t[i])
            v++;
        if(v==s.length())
            return true;
    }
    return false;
}
};