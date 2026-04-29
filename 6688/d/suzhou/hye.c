//ROOM:/d/suzhou/hye.c
//by dwolf
//97.11.4 

#include <ansi.h>
inherit ROOM;

string* npcs = ({
        "xiaolu",
        "yetu",
        "xiaohou",
});


void create()
{
	int i = random(sizeof(npcs));

	set("short", MAG"荒野"NOR);
	set("long", @LONG
这是苏州南门外的荒野，远处是山，山峰陡峭，高耸入云。近处一些小野兽跳来跳去。
十分惹人喜欢。突然一只小鹿从你身边跳过，你禁不住想抓住它。	
LONG
	);
	set("outdoors", "suzhou");

	set("exits", ([
		"north" : __DIR__"sgate",
                "southeast" : "/d/quanzhou/qzroad1",
	]));

        set("objects", ([
	__DIR__"npc/"+npcs[i] : 1]));
                                    

	setup();
}

int valid_leave(object me, string dir)
{
        if (me->query("sender") && dir == "southeast"  
&& (present("dao zei", environment(me))))
        return notify_fail("盗贼狞笑道：乖乖地把东西留下，然后把小命留下。\n");
        return ::valid_leave(me, dir);
}