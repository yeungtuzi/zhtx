// Room: /open/p/pock/zoulang.c

inherit ROOM;

void create()
{
	set("short", "[35m走廊[2;37;0m");
	set("long", @LONG
沿着大厅往北走，你来到了走廊这里。走廊打扫的非常干净，虽然走廊外
面有好些苍松，但在这里看不到有一丝松针或松子什么的。青城的两位宿老青
黄袍道人正在这里闲聊，还是不要打扰人家了，尽早离开为妙。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/qingguy" : 1,
		__DIR__"npc/yeguy" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
		"west" : __DIR__"zoulang2",
		"south" : __DIR__"guan1",
		"north" : __DIR__"ge",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
