#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#define MAXN 10005
using namespace std;

//#===================================================================================
//# ● Bignum Class
//#===================================================================================
    class Bignum
    {
        public:
            Bignum()
            {
                sa = "0";
                sb = "0";
            }
            void setValue(string s1, string s2)
            {
                sa = s1;
                sb = s2;
            }
            string get_sa()
            {
                return sa;
            }
            string get_sb()
            {
                return sb;
            }
            int sa_len()
            {
                return sa.size();
            }
            int sb_len()
            {
                return sb.size();
            }
            bool is_bigger(string ta, string tb)
            {
                int lena,lenb;
                lena = ta.size();
                lenb = tb.size();
                if(lena > lenb)
                    return true;
                else
                {
                    if(lena==lenb && ta>=tb)
                        return true;
                    else
                        return false;
                }
            }
            string add(string ta, string tb)
            {
                string ans;
                int lena,lenb,i,temp,flag=0;
                int na,nb;
                lena = ta.size();
                lenb = tb.size();
                while(lena != lenb)
                {
                    if(lena < lenb)
                    {
                        ta = "0"+ta;
                        lena++;
                    }
                    else
                    {
                        tb = "0"+tb;
                        lenb++;
                    }
                }
                for(i=lena-1;i>=0;i--)
                {
                    na = ta[i]-'0';
                    nb = tb[i]-'0';
                    temp = na+nb+flag;
                    ans = (char)(temp%10 + '0') + ans;
                    flag = temp/10;
                }
                if(flag != 0)
                    ans = "1"+ans;
                return ans;
            }
            string sub(string ta, string tb)
            {
                string ans;
                int i,tmp;
                if(ta.size()<tb.size() || (ta.size()==tb.size()&&ta<tb))
                {
                    swap(ta,tb);
                    ans = "-"+ans;
                }
                for(i=1;i<=tb.size();++i)
                {
                    ta[ta.size()-i] = ta[ta.size()-i]-tb[tb.size()-i]+'0';
                }
                for(i=1;i<=ta.size();++i)
                {
                    if(ta[ta.size()-i] < '0')
                    {
                        ta[ta.size()-i-1] -= 1;
                        ta[ta.size()-i] += 10;
                    }
                }
                for(tmp=0;tmp<ta.size();++tmp)
                {
                    if(ta[tmp] != '0')
                        break;
                }
                for(i=tmp;i<ta.size();i++)
                {
                    if(ta[i]>='0' && ta[i]<='9')
                        ans = ans + ta[i];
                }
                return ans;
            }
            string multi(string ta, string tb)
            {
                if(ta=="0" || tb=="0")
                    return "0";
                int len_a,len_b,len,i,j,flag=0;
                string ans;
                len_a = ta.size();
                len_b = tb.size();
                len = len_a + len_b;
                int tmp[len]={0};
                for(i=0;i<len_b;i++)
                {
                    for(j=0;j<len_a;j++)
                    {
                        tmp[i+j] += (tb[len_b-i-1]-'0')*(ta[len_a-j-1]-'0');
                    }
                }
                for(i=0;i<len;i++)
                {
                    tmp[i] += flag;
                    flag = tmp[i]/10;
                    tmp[i] %= 10;
                    ans = (char)(tmp[i]+'0')+ans;
                }
                if(flag != 0)
                    ans = (char)(flag+'0') + ans;
                for(i=0;ans[i]=='0';)
                    ans.erase(i,1);
                return ans;
            }
            string devide(string ta, string tb)
            {
                if(ta.size()<tb.size() || (ta.size()==tb.size()&&ta<tb))
                    return "0..."+ta;
                if(ta == "0")
                    return "0";
                else if(tb == "1")
                    return ta;
                else
                {
                    string ans,mod;
                    char tans[MAXN];
                    memset(tans,0,sizeof(tans));
                    int tmp,i,cnt,key=0;
                    tmp = ta.size()-tb.size();
                    if(ta[0] < tb[0])
                        tmp--;
                    for(i=0;i<tmp;++i)
                        tb = tb + "0";
                    while(tmp >= 0)
                    {
                        cnt = 0;
                        while(is_bigger(ta,tb))
                        {
                            ta = sub(ta,tb);
                            cnt++;
                        }
                        tans[tmp] = cnt+'0';
                        int pos=tb.size();
                        tb.erase(pos-1,1);
                        tmp--;
                    }
                    for(i=MAXN-1;i>=0;i--)
                    {
                        if(isdigit(tans[i]))
                            ans = ans + tans[i];
                    }
                    if(ta.empty())
                        ta = "0";
                    for(i=0;i<ans.size();++i)
                    {
                        if(ans[i] != '0')
                        {
                            if(i > 0)
                            {
                                key = i;
                                break;
                            }
                        }
                    }
                    if(key != 0)
                        ans.erase(0,key);
                    ans = ans + "..." + ta;
                    return ans;
                }
            }
            void output()
            {
                cout<<sa<<" + "<<sb<<" = "<<add(sa,sb)<<endl;
                cout<<sa<<" - "<<sb<<" = "<<sub(sa,sb)<<endl;
                cout<<sa<<" * "<<sb<<" = "<<multi(sa,sb)<<endl;
                if(sb == "0")
                    cout<<sa<<" / "<<sb<<" = "<<"NaN"<<endl;
                else
                    cout<<sa<<" / "<<sb<<" = "<<devide(sa,sb)<<endl;
                cout<<endl;
            }
        private:
            string sa;
            string sb;
    };

//#===================================================================================
//# ● Initialize
//#===================================================================================
    void initialize()
    {
        printf("#============================================================\n");
        printf("# ● Bignum Calculator\n");
        printf("#    Version 1.0.0\n");
        printf("#                                           Caronell\n");
        printf("#============================================================\n");
        printf("# 可以完成**非负数**的四则高精度计算\n");
        printf("#============================================================");
        cout<<endl;
        printf("#---------------------------------------\n");
        printf("# 请选择：\n");
        printf("# 1————开始计算\n");
        printf("# 2————退出\n");
        printf("#---------------------------------------\n");
        cout<<endl;
    }

//#===================================================================================
//# ● Update_Message
//#===================================================================================
    void update_message()
    {
        printf("#---------------------------------------\n");
        printf("# 是否继续？\n");
        printf("# 1————继续\n");
        printf("# 2————退出\n");
        printf("#---------------------------------------\n");
        cout<<endl;
    }

//#===================================================================================
//# ● Main
//#===================================================================================
    int main()
    {
        int n;
        Bignum bnum;
        initialize();
        while(cin>>n)
        {
            if(n == 2)
                exit(0);
            else if(n == 1)
            {
                string a,b;
                cout<<"请输入数字a： ";
                cin>>a;
                cout<<"请输入数字b： ";
                cin>>b;
                bnum.setValue(a,b);
                cout<<endl;
                bnum.output();
            }
            else
                cout<<"无效输入！请重新输入。"<<endl;
            cout<<endl;
            update_message();
        }
        return 0;
    }
