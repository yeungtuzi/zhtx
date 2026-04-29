
//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 铁罗汉

#include <armor.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit HANDS;
//inherit F_UNIQUE;

int query_autoload()
{
        return query("armor_prop");
}

void create()
{
        set_name(HIW"铁罗汉"NOR, ({ "tie luohan", "quan" }) );
        set_weight(1);
        set("owner","no_owner");
        set("marks/寒于",1);
        set("no_drop",1);
        set("no_get",1);
        set("unpawnable",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("long",   "这是当年峨嵋派开山祖师郭襄十六岁生日那天少林无色禅师请人带去的生日礼物。\n这是一对精铁铸成的罗汉。这对铁罗汉肚腹之中装有机括，\n扭紧弹簧之后，能对拆一套少林罗汉拳。\n后来郭襄转送武当派开山祖师张三丰，\n张三丰在武当形势危及的时候委托门下弟子俞岱岩保留，流传至今。\n想不到一件不起眼的东西竟然有这样大的来头!\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "iron");
                set("wear_msg",
                        HIW "$N双手一分，将$n握在手中，鼓足内力，“铛”的一碰，刹那间虎啸龙吟，不绝于耳。\n"NOR);
                set("unequip_msg", HIW "寒芒一闪，$N将$n收回腰间。\n"NOR);
                set("armor_prop/attack", this_player()->query_skill("jingang-quan",1)/8);   
                set("armor_prop/parry", this_player()->query_skill("banruo-zhang",1)/4); 
                set("armor_prop/damage", 300);  
        }
       setup();
}

int wear()
{
        if( this_player()->query_skill("cuff",1) < 250
          ||this_player()->query_skill("strike",1) <250)
        {
                return notify_fail("你使不动这件兵器。\n");
        }
        if( this_player()->query_temp("weapon") )
                return notify_fail("你只能在空手时使用铁罗汉！\n");
        return ::wear();
}

int dispersion_damage(object killer,object victim,int damage)
{
        object ob;

//killer很明显是动手打人的
//victim是被打的，
//damage是将要给的伤害值。
        if(killer->query_temp("weapon") 
        && killer->query("force")*killer->query("str")
         < victim->query("force")*victim->query_str()) {
                ob = killer->query_temp("weapon");
                ob->unequip();
                ob->move(environment(killer));
message_vision(HIW"$N猛的觉着自己的兵刃撞到了什么东西硬梆梆的，手臂一阵阵发麻……\n"+ob->query("name")+HIW"再也拿捏不住，脱手飞出！！\n"NOR,killer,victim);  
        }
        return damage-random(10);
}



