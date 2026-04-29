// Room: /d/lingjiu/pm_foot.c

inherit ROOM;

void create()
{
	set("short", "缥缈峰山脚");
	set("long", @LONG
你来到了天山缥缈峰脚下，抬头上望，缥缈峰直上云霄，几与天接！
峰顶白雾缭绕，虚虚实实，看不甚清，正合了“缥缈”之义。整座山
峰为白雪点缀，日光映照之下，熠熠生光！北边你看到了一条崎岖小
路，通向山顶。入口处立着一块丈余高的石碑，上面郝然印着“缥缈
峰”三字，鲜红夺目！
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"pm1",
  "southeast" : __DIR__"foot0",
]));
	set("no_clean_up", 0);
	set("outdoors", "lingjiu");

        set("objects", ([
                __DIR__"npc/caiyaoren" : 3,
	 ]) );


	setup();
	replace_program(ROOM);
}
