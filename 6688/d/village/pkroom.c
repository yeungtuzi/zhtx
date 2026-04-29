
inherit ROOM;

void create()
{
        set("short", "小酒店");
        set("long", @LONG
    这是一个非常简陋的小酒店，柜台上摆着一排酒坛，柜台后面坐着自然
是这家酒店的掌柜，他看上去普普通通，实在没有什么特别。
LONG
        );
        set("exits", ([ 
	"north" : __DIR__"eroad2",
]));
        set("objects", ([
                __DIR__"npc/pkmaster": 1 ]) );

        setup();
        set("no_clean_up", 1);
        replace_program(ROOM);
}


