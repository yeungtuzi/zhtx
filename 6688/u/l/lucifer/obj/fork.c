#include <ansi.h>
#include <weapon.h>

inherit FORK; 

void create()
{
        set_name(  CYN"翻江搅海叉"NOR , ({ "lighting fork","fork" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long",
"这是一杆由不知名的材料打造的叉子，从外表看好像没有任何起眼之处。\n");
                set("value", 0);
                set("unpawnable",1);
                set_weight(1);
                set("owner","no_owner");
                set("marks/寒于",1);
                set("no_drop",1);
                set("material", "crimson gold");
                set("rigidity", 99);
        }

       init_fork(199);
        setup();

}
 
void init()
{
    add_action("do_pull","repull");
}


int do_pull()
{
    object me;
    object obj;
    me=this_player();
    obj=new(__DIR__"nang");
    obj->move(me);
        destruct(this_object()); 
    return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
   me->add("force",me->query("force_factor"));
}

int query_autoload()
{
    return query("weapon_prop");
}


