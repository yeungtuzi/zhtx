// Room: /d/mingjiao/nushe.c
// Date: XXL 97/05/11

#include <room.h>

inherit ROOM;

//string look_dui();

void create()
{
    set("short", "地门女舍");
    set("long", @LONG
走进这间女舍，一阵脂粉淡香扑面，似有似无，似茉莉，似
丁香，似玫瑰，似夜来香，让人心神荡漾。几位姑娘斜倚阑窗，
吟诗作画，全不似武林中人，谁能想到，她们都是叱咤江湖的巾
帼女杰呢？
LONG
    );

    set("exits", ([
        "out" : __DIR__"mjdimen1",
    ]));          
    
    set("sleep_room",1);
    set("no_fight",1);
    set("no_cast",1);
    set("no_magic",1);
    set("no_poison",1);

    setup();
}

void init()
{
	object me;
	me=this_player();
	if(me->query("gender")!="女性")
	{
		message_vision("$N只觉暗香扑面，眼前一阵晕眩，恍惚间一女子云袖轻舒，你就...\n",me);
		me->move(__DIR__"hsqtan2.c");
	}
}

