// biaoju.c
//modified by tlang for class guard

#include <room.h>
#include <ansi.h>

inherit C_GUILD;

string look_sign();

void create()
{
        set("short", "镖局");
        set("long", @LONG
	你现在正站在镖局里靠近门口的地方有一块乌木雕成的招牌(sign)。听说天下
所有的镖局都合并了，而且广为收徒，不知道是不是真的。东边不远处是镖局专用的驿站。
LONG
);
        set("exits", ([
                "north" : __DIR__"eroad2", 
		"east" : __DIR__"gstart",
	]));
        set("objects", ([
                "/d/suzhou/npc/b_header" : 1,
                __DIR__"npc/bfighter" : 1,
        ]) );

        set("item_desc", ([
                "sign" : (: look_sign :),
        ]) );

        setup();
}

string look_sign()
{
        return "本镖局和威远镖局已经联盟，共同为武林培养人才。欢迎加入(join)。\n";
}

