// Room: /d/green/work1.c

inherit ROOM;

void create()
{
	set("short", "工作站");
	set("long", @LONG
    这里是采石场在村口的工作站　一栋小小的木屋立在东边　旁边是一
条上山的斜坡　路旁有一口井可以打水（fill）　空地上停著几辆载满石料的车　
往东南是一条铺著大石板的路　一路往山下延伸过去。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"path5",
]));
	set("no_clean_up", 0);
	set("outdoors", "snow");
	set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

	setup();
	replace_program(ROOM);
}
