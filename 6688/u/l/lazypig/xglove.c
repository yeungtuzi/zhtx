// xglove 鬼  手

#include <weapon.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit GLOVE;

int query_autoload()
{
        return query("weapon_prop");
}

void create()
{
        set_name(HIB"鬼  手"NOR, ({ "lighting glove", "glove" }) );
        set_weight(1);
        set("owner","no_owner");
        set("marks/寒于",1);
        set("no_drop",1);
        set("unpawnable",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",  "鬼  手，杀人无数，无坚不摧！\n");
                set("value", 0);
                set("material", "crimson gold");
        }
        init_glove(199);
        setup();
}

/*void init()
{
        seteuid(geteuid());
}
*/
mixed hit_ob(object me, object victim, int damage_bonus)
{
        //victim->receive_wound("kee",damage_bonus/10);
        me->add("force",me->query("force_factor"));
}

