//OBJ:/d/xueshan/npc/obj/fakexiaolou.c
//By masterall for 小楼一夜听春雨

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_UNIQUE;



void create()
{
        set_name(MAG"小楼"+BLK"一夜"+HIG"听"+HIB"春雨"NOR, ({ "xiao lou", "jian" }) );
        set_weight(8000);
        set("value", 100000);
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
        }
    init_sword(200);
       setup();
}

