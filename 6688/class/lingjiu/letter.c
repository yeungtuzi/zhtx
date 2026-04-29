// letter.c

#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;

void create()
{
        set_name( "书信" , ({ "tianshan letter" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("value", 0);
                set("material", "paper");
                set("long", "这是一封书信，封面上写着师弟无崖子谨启几字。\n");
                set("master_id","npc");
              }

 
       setup();
}

string query_autoload() 
{
        return this_object()->query("master_id");
}  

void autoload(string arg)
{ 
 set("master_id",arg);
}
