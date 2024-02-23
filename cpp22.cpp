/*  QUESTIONS
    get length of string
    https://leetcode.com/problems/reverse-string/
    check pallindrome
    https://leetcode.com/problems/valid-palindrome/
    https://cplusplus.com/reference/string/string/
    https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
    https://www.codingninjas.com/codestudio/problems/replace-spaces_1172172
    https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
    https://leetcode.com/problems/permutation-in-string/

    HOMEWORK
    https://www.codingninjas.com/codestudio/problems/check-if-the-string-is-a-palindrome_1062633
    differences between char array and strings
    https://leetcode.com/problems/reverse-words-in-a-string/
    https://leetcode.com/problems/reverse-words-in-a-string-ii/
    cin.getline()
    how to apply custom delimeter
    https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

*/

#include<bits/stdc++.h>
using namespace std;

int getlength(char ca[]){      //no need to give size of an array
    int i=0;
    while(ca[i]!='\0'){
        i++;
    }
    return i;
}

void reverse(char ca[]){
    int s=0,e=getlength(ca)-1;
    while(s<e){
        swap(ca[s++],ca[e--]);
    }
}

bool ispalindromecasesensitive(char s[],int n){
    int st=0, e=n-1;
    while(st<e){
        if(s[st++]!=s[e--]){
            return false;
        }
    }
    return true;
}

char lowercase(char c){
    if(c>='a' && c<='z'){
        return c;
    }
    else{
        return c-'A'+'a';
    }
}

bool ispalindromecasenonsensitive(char s[],int n){
    int st=0, e=n-1;
    while(st<e){
        if(lowercase(s[st++])!=lowercase(s[e--])){
            return false;
        }
    }
    return true;
}

bool ispalindromecasenonsensitive2(char s[],int n){
    int st=0, e=n-1;
    while(st<e){
        if((s[st++]!=s[e--]) && (s[st++]!=s[e--]-'A'+'a')){
            return false;
        }
    }
    return true;
}

bool ispalindromecasenonsensitiveonlycharandnum(char s[],int n){    
    int st=0, e=n-1;
    while(st<e){
        if(((s[st]>='a' && s[st]<='z') || (s[st]>='A' && s[st]<='Z') || (s[st]>='0' && s[st]<='9'))  &&  ((s[e]>='a' && s[e]<='z') || (s[e]>='A' && s[e]<='Z') || (s[e]>='0' && s[e]<='9'))){
            if(lowercase(s[st++])!=lowercase(s[e--])){
                return false;
            }
        }
        else{
            if(!( (s[st]>='a' && s[st]<='z') || (s[st]>='A' && s[st]<='Z') || (s[st]>='0' && s[st]<='9') )){
                st++;
            }
            else if(!( (s[e]>='a' && s[e]<='z') || (s[e]>='A' && s[e]<='Z') || (s[e]>='0' && s[e]<='9') )){
                e--;
            }
        }
    }
    return true;
}

bool ispalindromecasenonsensitiveonlycharandnum2(char s[],int n){
    int st=0, e=n-1;
    while(st<e){
        if(lowercase(s[st++])!=lowercase(s[e--])){
            return false;
        }
        else{
            if(!( (s[st]>='a' && s[st]<='z') || (s[st]>='A' && s[st]<='Z') || (s[st]>='0' && s[st]<='9') )){
                st++;
            }
            else if(!( (s[e]>='a' && s[e]<='z') || (s[e]>='A' && s[e]<='Z') || (s[e]>='0' && s[e]<='9') )){
                e--;
            }
        }
    }
    return true;
}

string reverseword(string s, int st, int e){
    int i=st, j=e;
    for(; i<j; i++, j--){
        swap(s[i], s[j]);
    }
    for(i=st; i<=e; i++){
        cout<<s[i];
    }
}

char maxoccchar(string s){
    int a[26]={0};
    for(int i=0; i<s.length(); i++){
        if(s[i]>='a'&&s[i]<='z')
            a[s[i]-'a']++;
        else{
            a[s[i]-'A']++;
        }
    }
    char c=-1;
    int maxtimes=-1;
    for(int i=0; i<26; i++){
        if(a[i]>maxtimes){
            maxtimes=a[i];
            c=i;
        }
    }
    return c+'a';
}

string replacespaces(string s){
    string temp="";
    for(int i=0; i<s.length(); i++){
        if(s[i]==' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else{
            temp.push_back(s[i]);
        }
    }
    return temp;
}

string replacespaces2(string s){
    string temp=""; 	    //string length is immutable and temp length is 0, cant change
    int k=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]==' '){
            temp[k++]='@';
            temp[k++]='4';
            temp[k++]='0';
        }
        else{
            temp[k++]=s[i];
        }
    }
    return temp;
}

string replacespaces3(string s){
    cout<<s.length()<<'\n';
    for(int i=0; i<s.length(); i++){
        if(s[i]==' '){
            s[i]='@';
            s.insert(i+1,1,'4');
            s.insert(i+2,1,'0');
        }
        else{
            continue;
        }
    }
    cout<<s.length()<<'\n';
    return s;
}

string removeocc(string s,string spart){
    while(s.length()!=0&&s.find(spart)<s.length()){
        s.erase(s.find(spart),spart.length());
    }
    return s;
}

string removeadjacentduplicate(string s){
    int i=0,flag=0;
    while(i<s.length()){
        if(s[i]==s[i+1]){
            s.erase(i,2);
            flag=1;
        }
        else{
            i++;
        }
        if(i==s.length()-1){
            i=0;
            if(flag==0){
                break;
            }
            flag=0;
        }
    }
    return s;
}

void stringcompression(char ca[]){
    char count[26]={0};
    for(int i=0; i<strlen(ca); i++){
        count[ca[i]-'a']++;
    }
    char ans[52];
    int j=0;
    for(int i=0; i<26; i++){
        if(count[i]>1){
            ans[j++]=i+'a';
            while(count[i]){
            ans[j++]=count[i];
            count[i]/=10;

            // how to insert a number in an arrsy
            }
        }
        else if(count[i]==1){
            ans[j++]=i+'a';
        }
    }
    cout<<ans<<'\n';
}

int main(){
// 5?36@6?35
    // string- 1d char type array
    char ca1[15];
    cin>>ca1;
    //Ujjwal23 -> |'U'|'j'|'j'|'w'|'a'|'l'|'2'|'3'|'\0'|gv|gv|gv|gv|gv|gv|
    // cin stops execution whenever space' ', tab'\t', enter/newline'\n', null character'\0 is encountered22
    /*
    where the input will end, its next index will contain null character
    null character
    '\0'
    ASCII value is 0
    used as a terminator
    tell us where the string is ended
    */
    cout<<"ca1->\n";
    cout<<ca1<<'\n';      //print upto null character
    // |'U'|'j'|'j'|'w'|'a'|'l'|'2'|'3'|'\0'|gv|gv|gv|gv|gv|gv| -> Ujjwal23
    cout<<ca1[8]<<'\n';
    cout<<ca1[10]<<'\n';
    cout<<'\n';

    char ca2[15];
    cin>>ca2;
    cout<<"ca2->\n";
    ca2[2]='\0';
    cout<<ca2<<'\n';
    // |'U'|'j'|'j'|'w'|'a'|'l'|'2'|'3'|'\0'|gv|gv|gv|gv|gv|gv|
    // |'U'|'j'|'\0'|'w'|'a'|'l'|'2'|'3'|'\0'|gv|gv|gv|gv|gv|gv|
    // Uj
    cout<<ca2[4]<<'\n';
    cout<<ca2[8]<<'\n';
    cout<<ca2[10]<<'\n';
    cout<<'\n';

    char ca3[15];
    cin>>ca3;
    ca3[0]='H';
    ca3[1]='i';
    ca3[2]=' ';     //executionwill not stop here, because exeution stops due to cin, not due to these characters
    cout<<ca3<<'\n';
    // |'U'|'j'|'j'|'w'|'a'|'l'|'2'|'3'|'\0'|gv|gv|gv|gv|gv|gv|
    // |'U'|'j'|' '|'w'|'a'|'l'|'2'|'3'|'\0'|gv|gv|gv|gv|gv|gv|
    // Hi wal23
    cout<<'\n';
   
    char ca4[15];
    cin>>ca4;
    ca4[0]='\t';     //will not stop here, because exeution stoprs due to cin, not due to these cgaracters
    cout<<ca4<<'\n';
    // |'U'|'j'|'j'|'w'|'a'|'l'|'2'|'3'|'\0'|gv|gv|gv|gv|gv|gv|
    // |'\t'|'j'|'j'|'w'|'a'|'l'|'2'|'3'|'\0'|gv|gv|gv|gv|gv|gv|
    //      jjwal23
    cout<<'\n';
    
    char ca5[15];
    cin>>ca5;
    ca5[0]='\n';     //will not stop here, because exeution stoprs due to cin, not due to these cgaracters
    cout<<ca5<<'\n';
    // |'U'|'j'|'j'|'w'|'a'|'l'|'2'|'3'|'\0'|gv|gv|gv|gv|gv|gv|
    // |'\n'|'j'|'j'|'w'|'a'|'l'|'2'|'3'|'\0'|gv|gv|gv|gv|gv|gv|
    // 
    // jjwal23
    cout<<getlength(ca5)<<'\n';      //space, tab and enter will also count as we apply condition only for '\0'
    cout<<'\n';

    char ca6[15];
    cin>>ca6;
    cout<<getlength(ca6)<<'\n';
    cout<<'\n';
   
    char ca7[15];
    cin>>ca7;
    reverse(ca7);
    cout<<ca7<<'\n';    //32LawjjU
    // reverse2(ca7);
    cout<<ca7<<'\n';    //Ujjwal23
    // cout<<getlength(ca5)<<'\n';

    char ca8[15];
    cin>>ca8;
    cout<<"is case sensitive palindrome-> "<<ispalindromecasesensitive(ca8,getlength(ca8))<<'\n';
    cout<<"is case non sensitive palindrome-> "<<ispalindromecasenonsensitive(ca8,getlength(ca8))<<'\n';
    cout<<"is case non sensitive palindrome-> "<<ispalindromecasenonsensitive2(ca8,getlength(ca8))<<'\n';
    cout<<"is only char and digit case non sensitive palindrome-> "<<ispalindromecasenonsensitiveonlycharandnum(ca8,getlength(ca8))<<'\n';
    cout<<"is only char and digit case non sensitive palindrome-> "<<ispalindromecasenonsensitiveonlycharandnum2(ca8,getlength(ca8))<<'\n';
    cout<<ca8<<'\n';

    char ca9[15]="Hello World";
    for(int i=0; i<15; i++){
        cout<<ca9[i]<<' ';
    }
    cout<<"\n\n";

    string s1;
    string s2="Ujjwal23";
    cout<<s2<<'\n';
    cout<<s2.length()<<'\n';
    s2.push_back('y');
    cout<<s2<<'\n';
    s2.pop_back();
    s2[1]='\0';
    cout<<s2<<'\n';     //string ignores null character'\0' but not ignores any other char
    s2[1]='\n';
    cout<<s2<<'\n';
    s2[1]='\t';
    cout<<s2<<'\n';
    s2[1]=' ';
    cout<<s2<<'\n';

    string s="My name is Ujjwal";
    string new_s="";
    int st=0,e;
    for(int i=0; i<s.length(); i++){
        if(s[i]==' '){
            e=i-1;
            reverseword(s, st, e);
            cout<<' ';
            st=i+1;
        }
        else if(i==s.length()-1){
            e=s.length()-1;
            reverseword(s, st, e);
            cout<<'\n';
        }
    }

    string s3;
    cin>>s3;
    cout<<maxoccchar(s3)<<'\n';



    string s4;
    cin.getline(s4, char(s4.length()));
    cout<<s4;



    // inbuilt functions of charecter array
    char ca9[15];
    cin>>ca9;
    cout<<"length is "<<strlen(ca9)<<'\n';
    // s.length()

    char ca10[15];
    cin>>ca10;
    // comapare
    cout<<"is same "<<strcmp(ca9,ca10)<<'\n';   //0 for same
    // compare funnction

    char ca11[15];
    strcpy(ca11,ca10);
    cout<<ca11<<'\n';
    // s1=s2

    // coding studios replace space
    string s5="my name is Ujjwal Maheshwari.";
    cout<< replacespaces3(s5)<<" 1\n";
    // s5="my name is Ujjwal Maheshwari.";
    // cout<< replacespaces2(s5)<<" 2\n";        //it is not working as string length is immutable
    s5="my name is Ujjwal Maheshwari.";
    // cout<<s5.length()<<'\n';
    cout<< replacespaces(s5)<<" 3\n";           //s in function is a copy of s in main, so
    // cout<<s5.length()<<'\n';


    // remove all occurences of a substring
    /*
    substring
    continuous sequence of characters in a string
    */
    

    cout<<"\n enter s6 and s7 to remove occ\n";
    string s6,s7;
    cin>>s6>>s7;
    cout<<removeocc(s6,s7)<<'\n';

    string s8;
    cin>>s8;
    cout<<removeadjacentduplicate(s8)<<'\n';

    int n;
    char ca12[100];
    cin>>ca12;
    cout<<ca12;
    // cout<<stringcompression(ca12)<<'\n';






    /*
    // key differences between character array and strings

    // leetcode reverse words in a string II

    // cin.getline()

    // how to apply custom delimeter

    // how to change directly into a string by passing it to a function, not by making change in its copy

    // insert char in a string      s.insert(i+1,1,'4')

    // https://www.cplusplus.com/reference/string/string/

    // leetcode permutation in string
    
    // leetcode string compression
    */

    return 0;
}