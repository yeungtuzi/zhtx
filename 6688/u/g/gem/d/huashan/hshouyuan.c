//hshouyuan.c  华山后院
//by emote
inherit ROOM;

void create()
{
	set("short","华山后院");
	set("long",
@LONG
这里是后院，华山派的二弟子劳德诺和三弟子梁发正在这里相互切磋功
夫。他们正练至酣处，连你的到来都没注意到。你看到这里有条小路似乎通
往一座庙宇。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"southeast"  : __DIR__"xiaolu4",
		"north" : __DIR__"zhengqitang",
		
]));
        set("objects", ([
                 __DIR__"npc/liang":1,
				 __DIR__"npc/lao":1,
				 
]));
		set("outdoors","huashan");
		setup();
		replace_program(ROOM);
}

