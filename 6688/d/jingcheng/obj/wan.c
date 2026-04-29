inherit ITEM;

void create()
{
       set_name("碗", ({ "wan" , "碗"}) );
       set_weight(500);
       set_max_encumbrance(800);
       set("no_get", 1);
       set("no_shown", 1);
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("unit", "个");
               set("long", "放骰子的碗\n");
               set("value", 1);
       }
}

int is_container() { return 1; }


