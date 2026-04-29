// Room: /open/p/pock/guan1.c

inherit ROOM;

void create()
{
	set("short", "[41m[35m松风观[2;37;0m");
	set("long", @LONG
这里是青城派的中心----松风观大厅。大厅的南边有一排的凳子，是用来
招待客人的。厅的中部有一个大香炉，炉中檀香飘渺，令人感到非常的舒心。
厅的西边有一条甬道，通向观的内部。厅北边有个小小的走廊，南边还有个小
门，门是关着的。
LONG
	);
	set("valid_startroom", 1);
	set("resource", ([ /* sizeof() == 1 */
		"apparition" : 3,
                ]));
	set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"shufang",
		"west" : __DIR__"huayuan",
		"north" : __DIR__"zoulang",
		"east" : __DIR__"square",
                        ]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/dizi2" : 4,
		__DIR__"npc/masteryu" : 1,
                        ]));
	setup();
	replace_program(ROOM);
}

