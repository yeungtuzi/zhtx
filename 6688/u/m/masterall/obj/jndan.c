//stone.c
//by masterall

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"大内密宝之"+HIW"－"+HIB"九转"+HIG"凝香"+HIW"丹"NOR , ({ "jiuzhuan ningxiang dan", "dan" }) );
        set_weight(600);
        set("no_get",1);
        set("no_drop",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_paimai",1);
        set("value",0);
        set("long", "难道这就是传说中的回春极品，大内珍藏的——九转凝香丹？
前些年江湖中盛行的驻颜丹因对智商有害，已渐渐被人们遗忘，\n而九转凝香丹却在武林中为大家津津乐道，传为美谈，\n然而它却如一位深闺倩女，让人难一睹其芳容。\n");
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
                return notify_fail("九转凝香丹散发出的灵气对你发出强烈的排斥，想把它搁在嘴边都势必登天！\n");

       message_vision( HIG"$N服下一枚九转凝香丹，顿时身轻如燕，顾盼生辉，日月之光华也皆为$N的神韵而失色！\n"NOR,me);

       me->add("mud_age", -86400);
       if (me->query("mud_age") < 86400 * 2) me->set("mud_age", 2*86400);
       if (me->query("per")<50)me->add("per",random(2));
       if (me->query("dex")<50)me->add("dex",random(2));
 
       destruct(this_object());
        return 1;
}



