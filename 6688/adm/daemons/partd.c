// partd.c
// 派系函数接口文件
// Created by dongsw

#include <ansi.h>

mapping parts = ([
//先弄第一个，以后补充
//乾坤教派系
"乾坤教" : ({"乾坤教", "青城派", "峨嵋派", "桃花岛", "铁雪山庄", "花紫会", "封山剑派",}),
]);

//"华山派系", "日月-晚月派系", "逍遥派系", "西藏喇嘛教"

int if_same_part(string myfam, string obfam, object me)
{
        string *mp;
        int i;
        
        for(i=0;i<sizeof(parts);i++)
        {
                mp = values(parts);
                if( member_array(myfam, mp[i]) != -1
                 && member_array(obfam, mp[i]) != -1) return 1;
                else return 0;
        }
}

string check_part_name(string fam)
{
        string *mp;
        int i;
        
        for(i=0;i<sizeof(parts);i++)
        {
                mp = values(parts);

                if(member_array(fam, mp[i]) != -1)
                return keys(parts)[i];
        }
}

int re_title(object me, string myfam, string mypart)
{
        string arg;
        int T, gen;
        
        if( mypart == "乾坤教")
        {
                arg = "教众";
                if (myfam == "乾坤教") 
                {
                        T = 1;
                        gen = me->query("family/generation");

                        if( gen == 3) arg = "舵主";
                        else if( gen == 2) arg = "护法";
                }
                
                myfam = replace_string(myfam, "剑派", "");
                myfam = replace_string(myfam, (T ? "教" : "派"), "");
                myfam = replace_string(myfam, "山庄", "");
                me->set("title", HIR + mypart + WHT + "「" + myfam + 
                         (T ? "总舵」" : "分舵」") + NOR + arg);
        }
        return 1;
}

