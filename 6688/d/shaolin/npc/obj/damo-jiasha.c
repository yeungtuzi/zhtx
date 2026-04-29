#include <armor.h>
#include <ansi.h>
inherit CLOTH;
int move();
void create()
{
        set_name(HIR"达摩袈裟"NOR, ({ "damo jiasha","jiasha" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "silk");
                set("armor_prop/armor", 100);
                set("no_get",1);
		set("value",0);
        }
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
