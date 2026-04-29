// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({

        BLU "初学乍练" NOR,
        HIB "不知所以" NOR,
        HIB "粗通皮毛" NOR,
        HIB "略识之无" NOR,
        HIB "渐有所悟" NOR,
        HIB "半生不熟" NOR,
        HIB "马马虎虎" NOR,
        RED "平淡无奇" NOR,
        RED "平平常常" NOR,
        RED "触类旁通" NOR,
        
        RED "已有小成" NOR,
        YEL "心领神会" NOR,
        YEL "深入浅出" NOR,
        YEL "挥洒自如" NOR,
        YEL "驾轻就熟" NOR,
        HIC "出类拔萃" NOR,           
        HIC "初入佳境" NOR,
        HIC "神乎其技" NOR,
        HIC "威不可当" NOR,
        HIC "出神入化" NOR,
        
        HIY "略有大成" NOR,
        HIY "已有大成" NOR,
        HIY "豁然贯通" NOR,
        HIY "超群绝伦" NOR,
        CYN "登峰造极" NOR,
        CYN "旷古绝伦" NOR,
        CYN "卓然大家" NOR,
        CYN "一代宗师" NOR,
        HIG "独步天下" NOR,
        HIG "冠绝当代" NOR,
        
        HIG "无可匹敌" NOR,
        HIG "所向披靡" NOR,
        HIM "空前绝后" NOR,
        HIM "登堂入室" NOR,
        HIM "惊世骇俗" NOR,
        HIM "超凡入圣" NOR,
        HIW "震古烁今" NOR,
        HIW "深藏不露" NOR,
        HIW "返璞归真" NOR,
        HIW "深不可测" NOR,

});
string *knowledge_level_desc = ({

        BLU "新学乍用" NOR,
        HIB "不甚了了" NOR,
        HIB "不知端倪" NOR,
        HIB "平淡无奇" NOR,
        HIB "司空见惯" NOR,
        HIB "初窥门径" NOR,
        HIB "略知一二" NOR,
        RED "茅塞顿开" NOR,
        RED "略识之无" NOR,
        RED "滚瓜烂熟" NOR,
        
        YEL "马马虎虎" NOR,
        YEL "轻车熟路" NOR,
        YEL "运用自如" NOR,
        YEL "触类旁通" NOR,
        HIC "深入浅出" NOR,
        HIC "已有小成" NOR,
        HIC "心领神会" NOR,
        HIC "豁然开朗" NOR,
        HIC "了然于胸" NOR,
        HIC "挥洒自如" NOR,
        
        HIC "独具匠心" NOR,
        HIY "见多识广" NOR,
        HIY "无所不通" NOR,
        HIY "无与伦比" NOR,
        HIY "卓尔不群" NOR,
        HIY "满腹经纶" NOR,
        CYN "学富五车" NOR,
        CYN "豁然贯通" NOR,
        CYN "包罗万象" NOR,
        CYN "博古通今" NOR,
        
        HIG "醍瑚罐顶" NOR,
        HIG "一代宗师" NOR,
        HIG "博大精深" NOR,
        HIG "超群绝伦" NOR,
        HIG "登峰造极" NOR,
        HIM "举世无双" NOR,
        HIM "独步天下" NOR,
        HIW "震古铄今" NOR,
        HIW "超凡入圣" NOR,
        HIW "深不可测" NOR,
});

string skill_level(string, int, string);

int main(object me, string arg)
{
        object ob;
        mapping skl, lrn, map;
        string *sname, *mapped;
        int i;

        seteuid(getuid());

        if(!arg) ob = me;
        else {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看谁的技能？\n");
                if( !wizardp(me)
                &&      !ob->is_apprentice_of(me)
                &&      !me->is_apprentice_of(ob)
                &&      !ob->accept_info(me, "skills") )
                        return notify_fail("只有巫师或有师徒关系的人能察看他人的技能。\n");
        }

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
                return 1;
        }
        write( (ob==me ? "你" : ob->name()) +"目前一共学过"+chinese_number(sizeof(ob->query_skills()))+"种技能：\n\n");
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        
        for(i=0; i<sizeof(skl); i++) {
                printf("%s%s%-40s" NOR " - %-10s %3d/%5d\n", 
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "□"),
                        to_chinese(sname[i]) + " (" + sname[i] + ")",
                         skill_level(SKILL_D(sname[i])->type(), skl[sname[i]],sname[i]),
                        skl[sname[i]], (int)lrn[sname[i]],
                );
        }
        write("\n");
        return 1;
}

string skill_level(string type, int level, string skill_name)
{
        string desc;
        int grade;

       if( stringp(desc = SKILL_D(skill_name)->query_lev_desc(level)) ) return desc;

        grade = level / 10;

        switch(type) {
                case "knowledge":
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}

int help(object me)
{
        write(@HELP
指令格式 : skills [<某人>]


这个指令可以让你查询所学过的技能。但你不可以查询你师父的技能。
我们将提供各个门派的拜师指南, 你也可以通过询问教你武功的 NPC
来知道可以学习什么。 

神仙可以查询任何人或 NPC 的技能状况。
深不可测对应的是195+级，相应的信息是：   
   『技能类』                                『知识类』   
 
   初学乍练  以有小成  略有大成  无可匹敌    新学乍用  马马虎虎  独具匠心  醍瑚罐顶
   不知所以  心领神会  已有大成  所向披靡    不甚了了  轻车熟路  见多识广  一代宗师          
   粗通皮毛  深入浅出  豁然贯通  空前绝后    不知端倪  运用自如  无所不通  博大精深      
   略识之无  挥洒自如  超群绝伦  登堂入室    平淡无奇  触类旁通  无与伦比  超群绝伦      
   渐有所悟  驾轻就熟  登峰造极  惊世骇俗    司空见惯  深入浅出  卓尔不群  登峰造极      
   半生不熟  出类拔萃  旷古绝伦  超凡入圣    初窥门径  已有小成  满腹经纶  举世无双      
   马马虎虎  初入佳境  卓然大家  震古烁今    略知一二  心领神会  学富五车  独步天下      
   平淡无奇  神乎其技  一代宗师  深藏不露    茅塞顿开  豁然开朗  豁然贯通  震古铄今      
   平平常常  威不可当  独步天下  返璞归真    略识之无  了然于胸  包罗万象  超凡入圣      
   触类旁通  出神入化  冠绝当代  深不可测    滚瓜烂熟  挥洒自如  博古通今  深不可测      
                   
                   
                          
HELP);
      return 1;
}
