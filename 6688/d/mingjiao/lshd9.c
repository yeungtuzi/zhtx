// This is a room made by roommaker.

inherit ROOM;

void create()
{
        set("short", "平地");
        set("long", @LONG
	这是灵蛇岛西面海边的一大块空地，数十艘巨大的海船停泊在岸边，海船之间
有跳板相连。每艘船的白帆上都以黑边包裹，上面绣着血红的火焰之形。岸边数人金发
碧眼，看起来不似中土人士。
LONG
	);
	set("exits", ([
	"enter" : __DIR__"tiaoban0",
	"east": __DIR__"lshd8",
	]) );

	set("objects", ([ /* sizeof() == 1 */
		 "/d/mingjiao/npc/liuyun" : 1,
		 "/d/mingjiao/npc/huiyue" : 1,
		 "/d/mingjiao/npc/miaofeng" : 1,
	]));

        setup();
}       

int valid_leave(object me, string dir)
{
        // 2026-04-30: unused variable commented out
        // mapping fam;

        if (dir == "enter")
        {
                if( me->query("guild") != "明教")
                {
		 	if( present("liuyun shi",this_object()) || present("miaofeng shi",this_object()) || present("huiyue shi",this_object()) )
				return notify_fail("波斯三使挡住了你的去路。\n");
                }
        }

        return ::valid_leave(me, dir);
}

