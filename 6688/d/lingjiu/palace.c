// Room: /d/lingjiu/palace.c

inherit ROOM;

void create()
{
	set("short", "独尊厅");
	set("long", @LONG
这个大厅全部用巨岩砌成，一个窗户也没有。一丈宽。抬头你
发现靠近屋顶的地方，有九块岩石突了出来，似乎是九个小小的平
台，不知道有什么用？大厅的正上方太师椅上坐着一人，想必就是
传说中的天山童姥。你注意到地面铺的地毯上也绣着一只巨幅黑鹫。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  CLASS_D("lingjiu") + "/master" : 1,
  __DIR__"npc/jujian" : 1,
]));
	set("no_clean_up", 0);
	set("valid_startroom", 1);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"path1",
]));

	setup();
	replace_program(ROOM);
}
