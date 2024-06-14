#include <stdio.h>
#include <string.h>
#include<stdbool.h>
#define MAXLEN 255//预定义最大串长为225
typedef struct 
{
    char ch[MAXLEN];
    int length;
}SString;
//求子串
bool SubString(SString *Sub,SString S,int pos,int len){//求子串，设立了一个指向新串的Sub
    //，用Sub返回串的第Pos个字符起长度为len的子串
    if (pos+len>S.length)//判断子串范围是否越界
    {   
        return false;
    }
    for ( int i=pos; i <pos+len ; i++)
        Sub->ch[i-pos+1]=S.ch[i];//遍历主串赋值子串（此处因为我们的初始化表的[0]被空出这样可以保证i和数组下标一致）
    Sub->length=len;    
}
//比较串
int StrCompare(SString S,SString T){
    for (int i = 0; i <=S.length&&i<=T.length; i++)
    {
        if (S.ch[i]!=T.ch[i])//判断是否相等
        {
            return S.ch[i]-T.ch[i];//在主函数中进行判断输出的值是否>=0来判断S与T的关系
        }    
    }
    return S.length - T.length;
}
//定位查找
int Index(SString S,SString T){
    int i, n =StrLength(S),m=StrLength(T);
    SString sub;//暂存子串
    while (i<=n-m+1)
    {
        SubString (&sub,S,i,m);//遍历寻找子串
        if (StrCompare(sub,T)!=0){
            ++i;//通常推荐使用 ++i，因为它不需要保留原始值来返回且清晰表达自己的意图
        }else return i;//返回子串在主串中的位置      
    }
   return 0; //S中不存在与T相等的子串
}
 