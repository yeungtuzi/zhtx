// Room: /d/waterfog/fwese.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "春秋水色斋");
        set("long", @LONG
这里是水烟阁二楼的春秋水色斋, 天邪派弟子可以在此练功, 不受外派干扰.
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/waterfog/fcenter",
]));
	set("objects", ([

//        "/class/fighter/champion.c":1,
        "/obj/gf/secret/npc/champion.c":1,
	
	]) );
        set("outdoors", "waterfog");
   
        setup();
}
void init()
{       object ob;
        string classname;

        if( interactive( ob = this_player()))
        {
        classname = ob->query("family/family_name");
        if(ob->query("bellicosity") < 300 && classname!="天邪派") {
        ob->move("/d/waterfog/fcenter");
        message_vision(HIW"\n$N被一股无形的天邪罡气挡了回来。\n\n"NOR, ob);
//        message_vision(HIW"\n$N不是天邪派弟子, 不能进入春秋水色斋。\n\n"NOR, ob);
                               }
        }
}
        
