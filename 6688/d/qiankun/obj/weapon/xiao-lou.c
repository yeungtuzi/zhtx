//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 小楼一夜听春雨


#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_SWORD;


void create()
{
        set_name(MAG"小楼"+BLK"一夜"+HIG"听"+HIB"春雨"NOR, ({ "xiao lou", "jian" }) );
        set_weight(1);
        set("unpawnable",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        "这是当年魔教教主使用的一把利刃，冷冷的剑身散发出逼人的杀气。\n不知道这把剑饮了多少人的血，隐隐的有一种殷红色的光芒。\n");
                set("value", 0);
                set("rigidity",10000);
                set("material", "sapphire");
                set("wield_msg",
                        HIR"$N「刷」地一声抽出了$n，天地瞬间为之变色，四周弥漫着逼人的杀气。\n"NOR);
                set("unequip_msg",  "$N将手中的$n插入腰间的剑鞘。\n");
                set("adv_props/attack", 40);   
                set("adv_props/dodge", 75);       
        }
    init_sword(300);
       setup();
}

int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query_skill("fuliu-jian",1) < 200)
        {
                return notify_fail("你的回风拂柳剑等级太低了，用不了这件兵器。\n");
        }
        if( this_player()->query("combat_exp") < 5000000)
        {
                return notify_fail("你江湖经验太低了，不配拥有这柄剑。\n");
        }
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if (damage_bonus < 0 ) return 0;
        if(random(3) > 0)
        victim->receive_wound("kee",damage_bonus/3);
        return this_object()->name()+ HIR "刺中了$n的$l，疮口登时鲜血狂飙，$n发出的连声惨嚎连天地鬼神都为之胆寒！\n" NOR;
}

