// renshen-guo.c 人参果
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIG "人参果" NOR, ({"renshen guo", "guo"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("long", 
"这是一枚人参果，看上去就像一个白白胖胖的小娃娃");
                set("value", 100000);
        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("你要吃什么？\n");
        me->set("eff_gin", (int)me->query("max_gin"));
        me->set("gin", (int)me->query("max_gin"));
        me->set("eff_kee", (int)me->query("max_kee"));
        me->set("kee", (int)me->query("max_kee"));
        me->set("eff_sen", (int)me->query("max_sen"));
        me->set("sen", (int)me->query("max_sen"));       
        me->set("max_force", (int)me->query("max_force"));
        me->set("max_mana", (int)me->query("max_mana"));
       me->set("cor",50);
        me->set("kar",30);
       me->set("con",50);
        me->set("str",100);
       me->set("int",100);
       me->set("dex",50);
       me->set("cps",50);
       me->set("bln",50);
       me->set("per",30);
       me->set("wil",30);
       me->set("vis",30);
       me->set("elo",30);
       me->set("msc",30);
       me->set("fav",20);
       me->set("spi",30);
       me->set("armor_vs_force",9000);
       me->set("armor_vs_spells",9000);
       me->set("max_force",8000);
       me->set("max_mana",5000);
       me->set("max_atman",5000);
       me->set("combat_exp",500000);
        me->set_skill("force",400);
         me->set_skill("banruo",300);
       me->set_skill("iron-cloth",400);
       me->set_skill("dodge",200);
       me->set_skill("move",200);
       me->set_skill("parry",200);
       me->set_skill("sword",200);
       me->set_skill("unarmed",151);
         me->set_skill("wuxinglun",200);
         me->set_skill("notracesnow",200);
        me->set_skill("taoism",200);
         me->set_skill("essencemagic",200);
         me->set_skill("magic",400);
        me->set_skill("strike",200);
         me->set_skill("nutrifux",200);
         me->set_skill("hammer",200);
         me->set_skill("zang-buddhi",400);
         me->set_skill("unarmed",200);
         me->set_skill("jin-gang",200);
        me->set_skill("literate",400);
         me->set("mud_age",345600);
         me->set("faith",15600);
         me->set("ct_faith",5600);
         me->set("wlshw",532);
        me->set("max_atman", (int)me->query("max_atman"));
        message_vision(HIG
 "$N吃下一枚人参果，只觉得精神健旺，气血充盈，体内真力源源滋生，甚至不再感到饥饿干渴! \n"NOR,me);

        destruct(this_object());
        return 1;
}
