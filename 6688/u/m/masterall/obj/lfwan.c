//stone.c
//by masterall

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"大内密宝之"+HIW"－"+HIC"龙髓"+HIM"凤骨"+HIW"丸"NOR , ({ "longfeng wan", "wan" }) );
        set_weight(600);
        set("no_get",1);
        set("no_drop",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_paimai",1);
        set("value",0);
        set("long", "难道这就是传说中的补药极品，大内珍藏的——龙髓凤骨丸？
多少武林人士不惜性命地为皇室打拼，难道就是为了这枚举世无双的圣药吗？\n");
        if( clonep() )
                set_default_object(__FILE__);   
                set("unit", "枚");
        
}
void init()
{
        add_action("eat_wan","eat");
}


int eat_wan(string arg)
{
       object me,ob;

       if( !this_object()->id(arg) ) return 0;

       me = this_player();
       ob = this_object();

       if( ob->query("owner") != me )
                return notify_fail("龙髓凤骨丸散发出的灵气对你发出强烈的排斥，想把它搁在嘴边都难比登天！\n");

       message_vision( HIY"$N刚想将龙髓凤骨丸放嘴里，只见它爆发出一道迫人的旋芒，刹那间已经融入了$N的躯体和灵魂！\n"NOR,me);

       if (me->query("cor")<50)me->add("cor",random(2));
       if (me->query("cps")<50)me->add("cps",random(2));
       if (me->query("int")<100)me->add("int",random(2));
       if (me->query("lea")<50)me->add("lea",random(2));

 
       destruct(this_object());
        return 1;
}



