//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 倚天剑

#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_SWORD;

void create()
{
        set_name(HIW"倚天剑"NOR, ({ "yitian jian", "jian" }) );
        set_weight(1);
        set("unpawnable",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",  "这是天下第一利器，有“倚天不出，谁与争锋”之说。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "crimson gold");
                set("wield_msg",
                        HIW"直如矫龙吞水，长虹冠日一般，$n已在$N手中，天地为之变色。\n"NOR);
                set("unequip_msg", HIW"$N将$n插回腰间，华光顿敛，天地间只闻龙鸣。\n"NOR);
                set("adv_props/attack", 20);  
                set("adv_props/dodge", 20);    
       }
    init_sword(320);
       setup();
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weap;
        int    wap,wdp;
        string weap_name;

        if(victim == me) return;
        if(victim->query("id") == "long xiang") return;
        if(victim->query("id") == "buzhi huowu") return;
        if( objectp(weap = victim->query_temp("weapon")) )
        {

                wap = weight() / 500
                        + query("rigidity")
                        + me->query("str")*me->query_str();

                wdp = (int)weap->weight() / 500
                        + (int)weap->query("rigidity")
                        + (int)victim->query("str")*victim->query_str();

                if(  random(wap) > wdp )
                {
                        weap_name = weap->query("name");
                        weap->unequip();
                        weap->move(environment(victim));
                        weap->set("name", "断掉的" + weap->query("name"));
                        weap->set("value", 0);
                        weap->set("weapon_prop", 0);
                        weap->set("long", weap->query("long")+"可是，现在却已经断为两截，不知道还有

什么用处。\n");
                        victim->reset_action();
                        return "只听见「擦」地一声轻响，$n手中的" + weap_name
                                + "已经被锋锐无伦的倚天剑削成两段！\n";
                }
                                
        }
}

//这个函数是用来设置兵器的特殊效果的.
//比如这把剑就是难以parry的,会被削断兵器.
//只有某些技能(taiji-jian,taiji-quan)或者
//特殊物品(tulong-blade,shenghuo-ling...)
//可以parry
int query_unparryable(object me,object victim)
{
        object weap;
        
        if( victim->query_skill_mapped("parry") == "taiji-jian" )
                return 10; //正常parry
        if( victim->query_skill_mapped("parry") == "taiji-quan" )               
                return 10; //正常parry
        if( objectp(weap = victim->query_temp("weapon")) && weap->query("rigidity") > 

query("rigidity") )
                return 10; //正常parry
        
        return 100;  //普通技能或兵器10%的可parry机率
}


int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query_skill("essence-sword",1) < 200)
        {
                return notify_fail("你的浣花淬玉剑等级太低了，用不了这件兵器。\n");
        }
        if( this_player()->query("combat_exp") < 5000000)
        {
                return notify_fail("你江湖经验太低了，不配拥有这柄剑。\n");
        }
        return ::wield();
}

