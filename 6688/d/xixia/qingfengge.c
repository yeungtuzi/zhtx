// Room: /d/xixia/qingfengge.c

inherit ROOM;

void create()
{
	set("short", "青凤阁凝香堂");
	set("long", @LONG
阁门开处，好大一座厅堂，地下铺着厚厚的羊毛地毯，地毯上织着
五彩花朵，鲜艳夺目。一张张小茶几排列成行，几上放着几只青花盖碗，
每只盖碗旁边一只青衣碟子，里面放着四色点心。厅堂尽处是一个三四
尺高的平台，铺着淡黄地毯，中间一张锦垫圆凳，当是公主之坐位。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"neitang",
  "out" : __DIR__"yroad2",
]));
	set("objects", ([
		__DIR__"npc/wangyuyan": 1,
		__DIR__"obj/chaji": 1,
	]));

	setup();
	replace_program(ROOM);
}
