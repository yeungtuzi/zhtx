//OBJ:/d/xueshan/npc/obj/xsword.c
//By tlang for 旋芒宝剑

#include <weapon.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit SWORD;
int move();


int query_autoload()
{
        return query("weapon_prop");
}

void create()
{
        set_name(HIM"旋芒宝剑"NOR, ({ "lighting sword", "sword" }) );
        set_weight(1);
        set("owner","no_owner");
        set("marks/寒于",1);
        set("no_drop",1);
        set("unpawnable",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",  "旋芒宝剑，留赠有缘.\n");
                set("value", 0);
                set("material", "crimson gold");
        }
        init_sword(199);
        setup();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        if (damage_bonus < 0 ) return 0;
        if(random(3)>1)return 0;
        if(random(me->query("force_factor")) > 50) return 0;
        me->add("force",me->query("force_factor"));
        return this_object()->name()+ HIC "从"+HIR"$N"+HIC"手中化作"+HIW"数"+HIG"道"+HIY"旋"+HIM"芒"+HIC"，刺破了天灵万物，直飞向寰宇！\n"NOR;
}




int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query("max_force") < 2000 )
        {
                return notify_fail("你的内功修为太低了，这样的使用神兵小心遭到它的戾气反噬哦！\n"); 
        }
        ob->set("owner", me);
        return ::wield();
}


void owner_is_killed() 
{ 
        object me,ob;
        ob = this_object();
        me = ob->query("owner");
        if(!userp(me)) return 0;
        message("system",HIM"一道绚丽的光芒滑破天际，消失在无尽的虚空之中……"NOR,users() );
        destruct(this_object());
}

