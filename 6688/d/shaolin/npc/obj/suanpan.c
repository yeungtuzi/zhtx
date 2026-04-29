// rope.c

#include <ansi.h>
#include <weapon.h>

inherit WHIP;
int move();
void create()
{
        set_name(HIM"紫金算盘"NOR,({"zijin suanpan","suanpan","whip"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("material", "steel");
		set("no_get",1);
        }
        init_whip(120);

        set("wield_msg", "$N从腰间摸出一把$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插回在腰间。\n");

        setup();
}

//int is_container() { return 1; }

void owner_is_killed() 
{ 
        remove_call_out("dest");
        call_out("dest", 1, this_object());
}

void dest(object ob)
{
        destruct(ob);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if(random(2))
           {
            message_vision("紫金算盘上的算珠不断发出噼啪的响声,使得"+victim->name()+"心神大乱\n",me,victim);
            return damage_bonus;
            }
        else return damage_bonus/2;
}
