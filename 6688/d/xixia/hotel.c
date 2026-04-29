// Room: /d/xixia/hotel.c

inherit ROOM;

void create()
{
	set("short", "高升客栈");
	set("long", @LONG
这家客栈并不怎么大，但恰好坐落在南门广场旁边，得天时地利
之便，加之客栈服务又周到，导致客房经常爆满，生意好得出奇。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"southstreet4",
]));
	set("objects", ([
		__DIR__"npc/zhongling": 1,
		__DIR__"npc/waiter": 1,
	]));

	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}
