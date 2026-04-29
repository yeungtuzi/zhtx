// Room: /d/emei/shijie10.c

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这里是通往峨嵋山的石阶，一条长长的石阶向西延伸，
就向没有尽头似的，虔诚的进香客来来往往。沿途很是热
闹，不是有小贩沿路叫买，还有峨眉的女尼和俗家弟子来
来往往。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "northeast" : "/d/road/emeishan",
  "west" : __DIR__"shijie11",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
