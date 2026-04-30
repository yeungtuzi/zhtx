// wizlian.c 巫师专用
// Written by Doing Lu 1998/11/1
// Updated by dongsw for zh2

#include <globals.h>
#include <ansi.h>

inherit F_CLEAN_UP;

#define CLASSDIR "/class/"

void    restore_condition(object me);
void    restore_origin(object me);

string *gifts = ({"cor","cps","int","lea","dex","bln","con","str", /* 显性天赋 */
                 "per","kar","fav","spi","elo","msc","wil","vis", /* 隐性天赋 */});

string *scores = ({"bellicosity","shen","pk_point","died_times","betrayer","MKS","PKS",
                   "family","force_type",});

string *basic_skill = ({"force","dodge","parry","move","cuff","sword","taoism","buddhism",
                        "literate","blade",});
        
mapping attrib =([
        "kee"           : "",
        "气"            : "kee",
        "eff_kee"       : "",
        "有效气"        : "eff_kee",
        "max_kee"       : "",
        "最大气"        : "max_kee",
        "gin"           : "",
        "精"            : "gin",
        "eff_gin"       : "",
        "有效精"        : "eff_gin",
        "max_gin"       : "",
        "最大精"        : "max_gin",
        "sen"           : "",
        "神"            : "sen",
        "eff_sen"       : "",
        "有效神"        : "eff_sen",
        "max_sen"       : "",
        "最大神"        : "max_sen",    
        "food"          : "",
        "食物"          : "food",
        "water"         : "",
        "饮水"          : "water",
        "force"         : "",
        "内力"          : "force",
        "max_force"     : "",
        "最大内力"      : "max_force",
        "mana"          : "",
        "法力"          : "mana",
        "max_mana"      : "",
        "最大法力"      : "max_mana",
        "atman"         : "",
        "灵力"          : "atman",
        "max_atman"     : "",
        "最大灵力"      : "max_atman",  
        "shen"          : "",
        "神"            : "shen",
        "mud_age"       : "",
        "年龄"          : "mud_age",
        "str"           : "",
        "膂力"          : "str",
        "臂力"          : "str",
        "int"           : "",
        "悟性"          : "int",
        "智力"          : "int",
        "con"           : "",
        "根骨"          : "con",
        "dex"           : "",
        "身法"          : "dex",
        "MKS"           : "",   
        "PKS"           : "",
        "potential"     : "",
        "潜力"          : "potential",
        "潜能"          : "potential",
        "combat_exp"    : "",
        "exp"           : "combat_exp",
        "经验"          : "combat_exp",
        "learned_points": "",
        "学习点数"      : "learnd_points",
]);

int main(object me, string arg)
{
        // 2026-04-30: unused variable commented out
        // object ob;
        // 2026-04-30: unused variable commented out
        // mapping learned;
        string pack, argn, argm;        // 属性/武功  参数1  参数2:暂时不用
        string *classname, *skills;
        int argnum, len, j;             // 参数的个数 (包括属性)

        int i;
        string attrs;
        
        if(!wizardp(me))
        {
                if(me->query("id") != "nut")
                {
                        return 0;
                }
        }

        // 恢复状态，精、气、内力
        if( !arg)
        {
                message_vision(HIW "$N喃喃的念了一会咒语，一股烟雾笼罩了$N。\n\n" NOR, me);
                restore_condition(me);
                return 1;
        }

        // 恢复成原始数据，放弃武功
        if (arg == "org")
        {
                message_vision(HIW "$N喃喃的念了一会咒语，一股烟雾笼罩了$N。\n\n" NOR, me);
                restore_origin(me);
                return 1;
        }

        argnum = sscanf(arg, "%s %d %d", pack, argn, argm);

        if (argnum < 2)
        {
                // 没有指定属性
                message_vision(HIW "$N喃喃的念了一会咒语，什么也没发生。\n\n" NOR, me);
                return 1;
        }
        
        classname = get_dir(CLASSDIR);
        
        if (stringp(pack) && intp(argn))
        {
                for(j=0;j<sizeof(classname);j++)
                {
                        if(classname[j] == pack)
                        {

                                skills = get_dir(CLASSDIR + pack + "/skills/");
                                for(i=0;i<sizeof(skills);i++)
                                {
                                        len = sizeof(skills[i]);
                                        if(skills[i][(len-2)..(len-1)] == ".c")
                                        {
                                                me->set_skill(skills[i][0..(len-3)],argn);
                                        }
                                }
                                
                                for(i=0;i<sizeof(basic_skill);i++)
                                {
                                        me->set_skill(basic_skill[i], argn);
                                }
                                
                                write(YEL"武功设置完毕！\n"NOR);
                                return 1;
                        }
                }
                
                        
        }
        
        //me->set("classname",classname);

        if (! undefinedp(attrs = attrib[pack]))
        {
                // 修改属性
                if (attrs == "") attrs = pack;
                message_vision(HIW "$N喃喃的念叨：天灵灵，地灵灵，各路神仙快显灵！\n\n" NOR, me);
                me->set(attrs, argn);
                message_vision(HIY "天上轰隆隆的响了一会，$N呵呵的笑了两声说道：真是灵验。\n\n" NOR, me);
                return 1;
        } else
        {
                // 修改武功
                message_vision(HIW "$N点燃一张符咒，喝道：太上老君急急如律敕令！\n\n" NOR, me);
                
                if( !find_object(SKILL_D(pack))
                        && file_size(SKILL_D(pack)+".c") < 0 )
                {
                        message_vision(HIR "天上轰隆隆的响了一会，太上老君怒喝道：你搞什么鬼！\n\n" NOR, me);
                        return 1;
                }

                if (argn >= 0)
                {
                        me->set_skill(pack, argn);
                        message_vision(HIY "一道金光从天上射下来，隐入$N的体内。\n\n" NOR, me);
                } else
                {
                        message_vision(HIR "天上轰隆隆的响了一会，太上老君怒喝道：不要乱来！\n\n" NOR, me);
                }
                return 1;
        }
}

void restore_condition(object me)
{
        message_vision(HIY "$N变得神采奕奕！\n\n" NOR, me);
        // 恢复气
        me->set("kee", me->query("max_kee"));
        me->set("eff_kee", me->query("max_kee"));

        // 恢复精
        me->set("gin", me->query("max_gin"));
        me->set("eff_gin", me->query("max_gin"));

        // 恢复神
        me->set("sen", me->query("max_sen"));
        me->set("eff_sen", me->query("max_sen"));

        // 恢复内力
        me->set("force", me->query("max_force"));

        // 恢复灵力
        me->set("atman", me->query("max_atman"));

        // 恢复法力
        me->set("mana", me->query("max_mana"));

        // 恢复食物
        me->set("food", me->max_food_capacity());

        // 恢复饮水
        me->set("water",me->max_water_capacity());

        // 解毒
        me->set("noposion", 1);
}

void restore_origin(object me)
{
        int i;
        mapping pmap;
        string* sk;

        message_vision(HIY "咦，$N变得天真无邪，一脸无辜状！\n\n" NOR, me);
        

        // 恢复score
        for (i=0; i<sizeof(scores); i++)
        {
                me->set(scores[i],0);
        }
        
        //恢复属性
        for (i=0; i<sizeof(gifts); i++)
        {
                me->set(gifts[i],30);
        }
        
        // disbale并且放弃各种武功

        pmap = me->query_skill_prepare();               // 准备的技能
        if (!pmap) pmap = ([]);

        if( mapp(pmap) && sizeof(pmap) > 0 )
        {
                sk = keys(pmap);
                for (i=0; i<sizeof(sk); i++)
                {
                        me->prepare_skill(sk[i]);       // 清除准备的技能
                }
        }
        
        sk = keys(me->query_skills());                  // 所学武功的名称集合
        for(i = 0; i<sizeof(sk); i++)
        {
                me->map_skill(sk[i]);                   // 取消激发某项武功
                map_delete(me->query_skills(), sk[i]);  // 放弃所学的武功
        }


        me->reset_action();                             // 完成
}

int help(object me)
{
write(@HELP
指令格式 : wizlian <武功/属性> 值

此命令提升巫师的武功，或是修改各项属性，包括气，精，神...

wizlian          : 恢复所有属性包括气，精，精力，内力，食物，饮水。
wizlian org      : 初始化个人数据，放弃所有武功，神降到0。
wizlian [属性] n : 修改某项属性为n。
wizlian [武功] n : 修改某项武功为n级，点数为m，如果小于零就不修改。
wizlian [门派] n : 修改此门派所有武功到n级。

HELP
    );
    return 1;
}

